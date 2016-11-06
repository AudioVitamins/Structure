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
#include "DSP\Loudness\Ebu128.h"
#include "PluginComunication\ManagePluginComunication.h"

#define DEMO_VERSION  0
#define TEST_VERSION  1
#define LOG_MODE 0
#define PLUGIN_PORT 8001
#include "Authentication\Authentication.h"
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


class StructureAudioProcessor : public AudioProcessor
	, public PluginServerListener
	, public PluginClientListener
	, public Ebu128LoudnessListener
{
public:
	int samplesPerBlock;
	double sampleRate;
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

	//void messageReceived(const MemoryBlock& message) ;

	void pluginClientCallback(PluginClient *pluginConnection, PluginMessage *msg);
	void pluginServerCenter(PluginServerConnection *pluginConnection, PluginMessage *msg);
	//------------------------------------------------------------------------------
	void sendAnalysisAllMode();
	int optionMode;
	bool analysisState;
	float currentGainEbu128;
	Ebu128Loudness ebu128;
	ScopedPointer<ManagePluginComunication> manageCom;
	double sampleIn3Sec;
	ScopedPointer<Authentication> authentication;
	void finishAnalysis(Ebu128Loudness *) override;
	void startAnalysis(Ebu128Loudness *) override;
	void ResetMetter();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StructureAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
