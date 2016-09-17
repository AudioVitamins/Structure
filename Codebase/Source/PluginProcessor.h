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


class InterprocessData
{
	bool hasError;
	void Parser(String txt);
	void FromMemoryBlock(MemoryBlock* mem);
public:
	InterprocessData();
	InterprocessData(MemoryBlock mem);
	bool isError();
	MemoryBlock ToMemoryBlock();
//Data info
private:
	void InitData();
public:
	struct Data {
		bool analysisAllMode;
	};
	Data data;
	bool getAnalysisMode();
	void setAnalysisMode(bool mode);
};

class StructureAudioProcessor  : public AudioProcessor
	, public InterprocessConnection
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

	void connectionMade() ;
	void connectionLost();
	void messageReceived(const MemoryBlock& message) ;
	//------------------------------------------------------------------------------
	void sendAnalysisAllMode();
	int optionMode;
	bool analysisState;
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StructureAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
