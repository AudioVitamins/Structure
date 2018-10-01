#include "TcpServer.h"

PluginServer::PluginServer(AudioProcessor &p):
	p(p)
{
}

bool PluginServer::StartServer(int port) {
	this->startTimer(10 * 1000);
	return beginWaitingForSocket(port);
}

bool PluginServer::StopServer() {
	stopTimer();
	int connectionListSize = fConnections.size();
	if (connectionListSize)
	{
		for (int i = (connectionListSize - 1); i >= 0; --i)
		{

			PluginServerConnection* ipc = fConnections.getUnchecked(i);
			if (ipc)
			{
				ipc->disconnect();
			}
		}
	}
	stop();
	return true;
}

PluginServer::~PluginServer()
{
}

void PluginServer::timerCallback()
{
    // iterate through the connections -- if any of them are disconnected, delete them. 
    // NOTE that we iterate from the end to the front so we can delete items without
    // needing to worry about goofing up indexes.
    int connectionListSize = fConnections.size();
    if (connectionListSize)
    {
      for (int i = (connectionListSize - 1); i >= 0; --i)
      {

		  PluginServerConnection* ipc = fConnections.getUnchecked(i);
         if (ipc)
         {
            if (PluginServerConnection::kDisconnected == ipc->GetConnectionState())
            {
               // this connection is no longer operative; delete it.
				const ScopedLock sl(lock);
               fConnections.remove(i);
            }
         }
      }
    }
}

OwnedArray<PluginServerConnection> &PluginServer::getClientsConnection() {
	const ScopedLock sl(lock);
	return fConnections;
}

void PluginServer::pluginServerCallback(PluginServerConnection *pluginConnection, PluginMessage *msg) {
	PluginMessage data(*msg);
	if (!data.isError()) {
		Listener *lis = dynamic_cast<Listener*>(&p);
		if (lis != nullptr) {
			lis->pluginServerCenter(pluginConnection, &data);
		}
	}
}

InterprocessConnection* PluginServer::createConnectionObject()
{
   // TODO: store into list, periodically delete disconnected connections.
	PluginServerConnection* ipc = new PluginServerConnection(this);
   fConnections.add(ipc);
   return ipc;
}

PluginServerConnection::PluginServerConnection(PluginServer *server)
: InterprocessConnection(false, 0xf2b49e2c)
    , server(server)
	, fConnected(PluginServerConnection::kConnecting)
{
  DBG("RpcServerConnection created." );
}

PluginServerConnection::~PluginServerConnection()
{
  DBG("RpcServerConnection destroyed." );

}

void PluginServerConnection::connectionMade()
{
   DBG("RpcServerConnection::connectionMade()");
   fConnected = PluginServerConnection::kConnected;

}

void PluginServerConnection::connectionLost()
{
   DBG("RpcServerConnection::connectionLost()");
   MessageManagerLock mmLock;
   fConnected = PluginServerConnection::kDisconnected;
}

void PluginServerConnection::SendPluginMessage(const PluginMessage& msg)
{
   const ScopedLock mutex(fLock);
   this->sendMessage(msg.ToMemoryBlock());
}

void PluginServerConnection::messageReceived(const MemoryBlock& message)
{
   // a received message from a client needs to be decoded and converted into a 
   // function call that results in us sending a message back over this connection.
	PluginMessage data(message);
	if (!data.isError()) {
		server->pluginServerCallback(this, &data);
	}
}

PluginServer *PluginServerConnection::getServer() {
	return server;
}

PluginMessage::PluginMessage() :hasError(false) {
	 InitData();
 };
PluginMessage::PluginMessage(MemoryBlock mem) : hasError(false) {
	 InitData();
	 FromMemoryBlock(&mem);
 }
 void PluginMessage::Parser(String txt) {
	 /*ScopedPointer<XmlElement> xmlState(XmlDocument::parse(txt));
	 if (xmlState->hasTagName("AudioPluginStructureInterprocessData")) {
	 if (xmlState->hasAttribute("AnalysisModeAll")) {
	 analysisAllMode = xmlState->getBoolAttribute("StateAnalysis");
	 }
	 else {
	 hasError = true;
	 }
	 }
	 else {
	 hasError = true;
	 }
	 xmlState = nullptr;*/
 }
 void PluginMessage::FromMemoryBlock(MemoryBlock* mem) {
	 if (mem->getSize() == sizeof(data)) {
		 memcpy(&data, mem->getData(), mem->getSize());
	 }
	 else {
		 hasError = true;
	 }
 }
 bool PluginMessage::isError() {
	 return hasError;
 }
 MemoryBlock PluginMessage::ToMemoryBlock() const {
	 /*XmlElement xml("AudioPluginStructureInterprocessData");
	 xml.setAttribute("AnalysisModeAll", analysisAllMode);
	 MemoryBlock mem;
	 StructureAudioProcessor::copyXmlToBinary(xml, mem);*/
	 return MemoryBlock(&data, sizeof(data));
 }
 void PluginMessage::InitData() {
	 data.analysisAllMode = false;
 }
 bool PluginMessage::getAnalysisMode() {
	 return data.analysisAllMode;
 }
 void PluginMessage::setAnalysisMode(bool mode) {
	 data.analysisAllMode = mode;
 }

 FunRemote PluginMessage::getFuncRemote() {
	 return data.func;
 }
 void PluginMessage::setFuncRemote(FunRemote func) {
	 data.func = func;
 }
