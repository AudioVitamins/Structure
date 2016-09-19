/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "DSP\LogUtil.h"
#include "PluginComunication\TcpClient.h"
#include "PluginComunication\TcpServer.h"


//==============================================================================
/**
*/
enum {
	INSTRUMENTS_MODE,
	BUS_GROUP_MODE,
	VOX_LEAD_MODE
};

enum {
	RED,
	ORANGE,
	GREEN
};


class StructureAudioProcessor  : public AudioProcessor
	, public PluginServerListener
	, public PluginClientListener
{
public:
    //==============================================================================
    StructureAudioProcessor();
    ~StructureAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet) override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

	//void connectionMade() ;
	//void connectionLost();
	//void messageReceived(const MemoryBlock& message) ;

	void pluginClientCallback(PluginClient *pluginConnection, PluginMessage *msg);
	void pluginServerCenter(PluginServerConnection *pluginConnection, PluginMessage *msg);
	//------------------------------------------------------------------------------
	//void sendAnalysisAllMode();
	PluginServer *server;
	PluginClient *client;
	int optionMode;
	bool analysisState;
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StructureAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
