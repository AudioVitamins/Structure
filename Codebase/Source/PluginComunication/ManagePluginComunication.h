#ifndef IPCCLIENT_H_INCLUDED
#define IPCCLIENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "TcpServer.h"
#include "TcpClient.h"
class ManagePluginComunication : private Timer {
	PluginServer *server;
	PluginClient *client;
public:
	ManagePluginComunication();
	~ManagePluginComunication();

private:
	void timerCallback();
	bool checkServer();
	bool turnOnServer();
};
#endif 
