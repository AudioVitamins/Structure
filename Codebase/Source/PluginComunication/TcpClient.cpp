/*
  Copyright 2016 Art & Logic Software Development. 
 */




#include "TcpClient.h"

PluginClient::PluginClient(AudioProcessor &p)
:  InterprocessConnection(false, 0xf2b49e2c)
,  fIsConnected(false)
, p(p)
{

}

PluginClient::~PluginClient()
{
	
}

void PluginClient::connectionMade()
{
   DBG("RpcClient::connectionMade()");
   fIsConnected = true;
}

void PluginClient::connectionLost()
{
   DBG("RpcClient::connectionLost()");
   fIsConnected = true;
}

bool PluginClient::SendMessage(const MemoryBlock& message) {
	return sendMessage(message);
}

void PluginClient::messageReceived(const MemoryBlock& message)
{
	PluginMessage data(message);
	if (!data.isError()) {
		Listener *lis = dynamic_cast<Listener*>(&p);
		if (lis != nullptr) {
			lis->pluginClientCallback(this, &data);
		}
	}
}

void PluginClient::Disconnect() {
	disconnect();
}

bool PluginClient::Connect(const String& hostName,
	int portNumber,
	int timeOutMillisecs) {
	return (fIsConnected = connectToSocket(hostName, portNumber, timeOutMillisecs));
}