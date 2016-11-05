/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "StructureEditor.h"


//==============================================================================
StructureAudioProcessor::StructureAudioProcessor()
{
	//Log Start
#if LOG_MODE == 1
	JIMMY_LOGGER_ACTIVATE(Jimmy::DATA);
#endif
	sampleRate = 0.0f;
	currentGainEbu128 = 0.0f;
	samplesPerBlock = 0;
	optionMode = INSTRUMENTS_MODE;
	analysisState = true;
	manageCom = new ManagePluginComunication(*this, PLUGIN_PORT);
	ebu128.addListener(this);
#if TEST_VERSION
	authentication = new Authentication();
#else
	authentication = new Authentication(false);
#endif
	if(authentication->isValidDate()){
		JIMMY_LOGGER_PRINT(JIMMY_LOGGER_DATA, "Valid\n");
	} else {
		JIMMY_LOGGER_PRINT(JIMMY_LOGGER_DATA, "InValid\n");
	}
}

StructureAudioProcessor::~StructureAudioProcessor()
{
	manageCom = nullptr;
}

//==============================================================================
const String StructureAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool StructureAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool StructureAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double StructureAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int StructureAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int StructureAudioProcessor::getCurrentProgram()
{
    return 0;
}

void StructureAudioProcessor::setCurrentProgram (int )
{
}

const String StructureAudioProcessor::getProgramName (int )
{
    return String();
}

void StructureAudioProcessor::changeProgramName (int , const String& )
{
}

//==============================================================================
void StructureAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
	int expectedRequestRate = 20;
	sampleIn3Sec = 0;
	this->sampleRate = sampleRate;
	ebu128.prepareToPlay(sampleRate,
		getNumInputChannels(),
		samplesPerBlock,
		expectedRequestRate);
}

void StructureAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool StructureAudioProcessor::setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet)
{
    // Reject any bus arrangements that are not compatible with your plugin

    const int numChannels = preferredSet.size();

   #if JucePlugin_IsMidiEffect
    if (numChannels != 0)
        return false;
   #elif JucePlugin_IsSynth
    if (isInput || (numChannels != 1 && numChannels != 2))
        return false;
   #else
    if (numChannels != 1 && numChannels != 2)
        return false;

    if (! AudioProcessor::setPreferredBusArrangement (! isInput, bus, preferredSet))
        return false;
   #endif

    return AudioProcessor::setPreferredBusArrangement (isInput, bus, preferredSet);
}
#endif

void StructureAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& )
{
	int expectedRequestRate = 20;
	if (!authentication->isValidDate())  return;

	if (analysisState) {
		if (optionMode == BUS_GROUP_MODE) {
			// Use delay
			sampleIn3Sec += buffer.getNumSamples();
			if (sampleIn3Sec > sampleRate * 3) {
			ebu128.processBlock(buffer);
			}
		}
		else {
			ebu128.processBlock(buffer);
		}
	}
	else {
		sampleIn3Sec = 0;
	}
	
	if (!analysisState && Ebu128Loudness::minimalReturnValue != currentGainEbu128) {
		if (optionMode == INSTRUMENTS_MODE) {
			float gain = Decibels::decibelsToGain<float>(- 27.0  - currentGainEbu128);
			buffer.applyGain(gain);
		}
		else if (optionMode == BUS_GROUP_MODE) {
			float gain = Decibels::decibelsToGain<float>(-25.0 - currentGainEbu128);
			buffer.applyGain(gain);
		}
		else if (optionMode == VOX_LEAD_MODE) {
			float gain = Decibels::decibelsToGain<float>(-23.0 - currentGainEbu128);
			buffer.applyGain(gain);
		}
	}
}

//==============================================================================
bool StructureAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* StructureAudioProcessor::createEditor()
{
    return new StructureAudioProcessorEditor(*this);
}

//==============================================================================
void StructureAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
	XmlElement xml("AudioPluginStructure");
	xml.setAttribute("OptionMode", optionMode);
	xml.setAttribute("StateAnalysis", analysisState);
	xml.setAttribute("EBUGain", currentGainEbu128);
	copyXmlToBinary(xml, destData);
}

void StructureAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
	ScopedPointer<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

	if (xmlState != nullptr)
	{
		if (xmlState->hasTagName("AudioPluginStructure"))
		{
			optionMode = xmlState->getIntAttribute("OptionMode");
			analysisState = xmlState->getBoolAttribute("StateAnalysis");
			currentGainEbu128 = xmlState->getDoubleAttribute("EBUGain");
			ebu128.setShortTermLoudness(currentGainEbu128);
		}
	}

	xmlState = nullptr;
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new StructureAudioProcessor();
}

//==============================================================================

//==============================================================================
void StructureAudioProcessor::sendAnalysisAllMode() {
	PluginMessage data;
	data.setAnalysisMode(this->analysisState);
	manageCom->sendMessage(data);
}
void StructureAudioProcessor::pluginClientCallback(PluginClient *, PluginMessage *msg) {
	if (msg != nullptr && !msg->isError()) {
		this->analysisState = msg->getAnalysisMode();
		if (this->analysisState) {
			ResetMetter();
		}
	}
}
void StructureAudioProcessor::pluginServerCenter(PluginServerConnection *pluginConnection, PluginMessage *msg) {
	PluginServer *server = pluginConnection->getServer();
	OwnedArray<PluginServerConnection> &clients = server->getClientsConnection();
	const ScopedLock sl(server->lock);
	int connectionListSize = clients.size();
	if (connectionListSize)
	{
		for (int i = (connectionListSize - 1); i >= 0; --i)
		{

			PluginServerConnection* ipc = clients.getUnchecked(i);
			if (ipc != pluginConnection && ipc != nullptr)
			{
				if (PluginServerConnection::kConnected == ipc->GetConnectionState())
				{
					ipc->SendPluginMessage(*msg);
				}
			}
		}
	}


}
void StructureAudioProcessor::finishAnalysis(Ebu128Loudness *ebu) {
	analysisState = false;
	currentGainEbu128 = ebu->getShortTermLoudness();
}
void StructureAudioProcessor::startAnalysis(Ebu128Loudness *) {
	analysisState = true;
	currentGainEbu128 = 0.0;
}
void StructureAudioProcessor::ResetMetter() {
	suspendProcessing(true);
	ebu128.reset();
	suspendProcessing(false);
}