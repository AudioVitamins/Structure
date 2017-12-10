#ifndef IPCCLIENT_H_INCLUDED
#define IPCCLIENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "TcpServer.h"

class PluginClient : public InterprocessConnection
{
public:
	class Listener{
	public:
		virtual void pluginClientCallback(PluginClient *pluginConnection, PluginMessage *msg) = 0;
	};
public:
	PluginClient(AudioProcessor &p);

   ~PluginClient();

   void connectionMade() override;

   void connectionLost() override;
   bool SendMessage(const MemoryBlock& message);
   void messageReceived(const MemoryBlock& message) override;
   bool IsConnected() const { return fIsConnected; };
   void Disconnect();
   bool Connect(const String& hostName,
	   int portNumber,
	   int timeOutMillisecs);
private:

   bool fIsConnected;
   AudioProcessor &p;

};
typedef PluginClient::Listener PluginClientListener;
#endif 
