#ifndef IPCSERVER_H_INCLUDED
#define IPCSERVER_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"

enum FunRemote {
	NON = 0,
	BOARDCAST,
	UPDATE_ANALYSIS_MODE,
};

class PluginServerConnection;
class PluginMessage
{
	bool hasError;
	void Parser(String txt);
	void FromMemoryBlock(MemoryBlock* mem);
public:
	PluginMessage();
	PluginMessage(MemoryBlock mem);
	bool isError();
	MemoryBlock ToMemoryBlock() const;
private:
	void InitData();
public:
	struct Data {
		FunRemote func;
		bool analysisAllMode;
	};
	Data data;
	bool getAnalysisMode();
	void setAnalysisMode(bool mode);
	FunRemote getFuncRemote();
	void setFuncRemote(FunRemote fun);
};

class PluginServer : public InterprocessConnectionServer
, public Timer
{
	friend class PluginServerConnection;
public: 
	class Listener {
	public:
		virtual void pluginServerCenter(PluginServerConnection *pluginConnection, PluginMessage *msg) = 0;
	};
	PluginServer(AudioProcessor &p);
   ~PluginServer();
   InterprocessConnection* createConnectionObject();
   OwnedArray<PluginServerConnection> &getClientsConnection();
   bool StartServer(int port);
   bool StopServer();
  
private:
	void timerCallback();
	void pluginServerCallback(PluginServerConnection *pluginConnection, PluginMessage *msg);
   OwnedArray<PluginServerConnection> fConnections;
   AudioProcessor &p;
public:
    CriticalSection lock;
};

class PluginServerConnection : public InterprocessConnection
                        //  , public ChangeListener
{
	
public:
	PluginServerConnection(PluginServer *server);

   ~PluginServerConnection();

   enum ConnectionState
   {
      kConnecting = 0,
      kConnected, 
      kDisconnected
   };

   void connectionMade() override;

   void connectionLost() override;

   void messageReceived(const MemoryBlock& message) override;

   void SendPluginMessage(const PluginMessage& msg);

   PluginServer *getServer();

   ConnectionState GetConnectionState() const { return fConnected; };
private:

   CriticalSection fLock;
   PluginServer *server;
   ConnectionState fConnected;
};

typedef PluginServer::Listener PluginServerListener;

#endif
