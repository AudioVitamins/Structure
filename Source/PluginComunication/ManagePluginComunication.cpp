#include "ManagePluginComunication.h"
ManagePluginComunication::ManagePluginComunication(AudioProcessor &p, int port) : p(p), port(port)
{
	startTimer(50);
	turnOnServer();
	turnOnClient();
}

ManagePluginComunication::~ManagePluginComunication() {
	server->StopServer();
	client->Disconnect();
	server = nullptr;
	client = nullptr;
}

bool ManagePluginComunication::checkServer() {
	if (server != nullptr) {
		return server->StartServer(port);
	}
	return false;
}

bool ManagePluginComunication::turnOnServer() {
	server = new PluginServer(p);
	if (!checkServer()) {
		return false;
	}
	return true;
}

bool ManagePluginComunication::turnOnClient() {
	client = new PluginClient(p);
	return client->Connect(IPAddress::local().toString(), port, 1000);
}

bool ManagePluginComunication::sendMessage(PluginMessage &msg) {
	if (client->isConnected()) {
		return client->SendMessage(msg.ToMemoryBlock());
	}
	else {
		client->disconnect();
		turnOnClient();
		if (client->isConnected()) {
			return client->SendMessage(msg.ToMemoryBlock());
		}
	}
	return false;
}

void ManagePluginComunication::timerCallback() {
	if (client != nullptr && !client->IsConnected()) {
		turnOnServer();
		turnOnClient();
	} 
	else if (client == nullptr) {
		client->Disconnect();
		turnOnClient();
	}
}