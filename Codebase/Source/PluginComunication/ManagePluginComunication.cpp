#include "ManagePluginComunication.h"
ManagePluginComunication::ManagePluginComunication() {
	startTimer(50);
}
ManagePluginComunication::~ManagePluginComunication() {
}

bool ManagePluginComunication::checkServer() {
	if (server != nullptr) {
		return server->StartServer(1000);
	}
	return false;
}
bool ManagePluginComunication::turnOnServer() {

}


void ManagePluginComunication::timerCallback() {

}