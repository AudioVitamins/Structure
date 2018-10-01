#ifndef IPCT_H_INCLUDED
#define IPC_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "TcpServer.h"
#include "TcpClient.h"
class ManagePluginComunication : private Timer {
	ScopedPointer<PluginServer> server;
	ScopedPointer<PluginClient> client;
	AudioProcessor &p;
	int port;
public:
	ManagePluginComunication(AudioProcessor &p, int port);
	~ManagePluginComunication();
	bool sendMessage(PluginMessage &msg);
private:
	void timerCallback();
	bool checkServer();
	bool turnOnServer();
	bool turnOnClient();
};
#endif 
