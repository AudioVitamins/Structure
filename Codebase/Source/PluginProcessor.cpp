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
	JIMMY_LOGGER_ACTIVATE(JIMMY_LOGGER_DATA, true);
	optionMode = INSTRUMENTS_MODE;
	analysisState = true;
	manageCom = new ManagePluginComunication(*this, 1000);
}

StructureAudioProcessor::~StructureAudioProcessor()
{
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

void StructureAudioProcessor::setCurrentProgram (int index)
{
}

const String StructureAudioProcessor::getProgramName (int index)
{
    return String();
}

void StructureAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void StructureAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
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

void StructureAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
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
	//for (int i = 0; i < ((TOTAL_SLOT_PARAMS * 8) + 1); i++)
	//{
	//	int slot = i / TOTAL_SLOT_PARAMS + 1;
	//	int param = i %TOTAL_SLOT_PARAMS;
	//	String att;
	//	if (i < TOTAL_SLOT_PARAMS * 8) {
	//		if (param == SLOT_LOADED) {
	//			att = "SLOT_" + String(slot) + "_SLOT_LOADED_" + String(param);
	//		}
	//		else  if (param == SLOT_PLUGINREF) {
	//			att = "SLOT_" + String(slot) + "_SLOT_PLUGINREF_" + String(param);
	//		}
	//		else  if (param == SLOT_ACTIVE) {
	//			att = "SLOT_" + String(slot) + "_SLOT_ACTIVE_" + String(param);
	//		}
	//		else  if (param == SLOT_OUTPUTGAIN) {
	//			att = "SLOT_" + String(slot) + "_SLOT_OUTPUTGAIN_" + String(param);
	//		}
	//		else {
	//			att = "SLOT_" + String(slot) + "SLOT_PARAM_" + String(param - SLOT_OUTPUTGAIN);
	//		}
	//	}
	//	else {
	//		att = "BarLength";
	//	}
	//	//float lastValue = AudioProcessor::getParameter(i);
	//	float lastValue = getParameter(i);
	//	xml.setAttribute(att, lastValue);
	//}
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
			/*for (int i = 0; i < ((TOTAL_SLOT_PARAMS * 8) + 1); i++)
			{
				int slot = i / TOTAL_SLOT_PARAMS + 1;
				int param = i %TOTAL_SLOT_PARAMS;
				String att;
				if (i < TOTAL_SLOT_PARAMS * 8) {
					if (param == SLOT_LOADED) {
						att = "SLOT_" + String(slot) + "_SLOT_LOADED_" + String(param);
					}
					else  if (param == SLOT_PLUGINREF) {
						att = "SLOT_" + String(slot) + "_SLOT_PLUGINREF_" + String(param);
					}
					else  if (param == SLOT_ACTIVE) {
						att = "SLOT_" + String(slot) + "_SLOT_ACTIVE_" + String(param);
					}
					else  if (param == SLOT_OUTPUTGAIN) {
						att = "SLOT_" + String(slot) + "_SLOT_OUTPUTGAIN_" + String(param);
					}
					else {
						att = "SLOT_" + String(slot) + "SLOT_PARAM_" + String(param - SLOT_OUTPUTGAIN);
					}
				}
				else {
					att = "BarLength";
				}
				float newValue = (float)xmlState->getDoubleAttribute(att);
				this->setParameter(i, newValue);
			}*/
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
void StructureAudioProcessor::pluginClientCallback(PluginClient *pluginConnection, PluginMessage *msg) {
	if (msg != nullptr && !msg->isError()) {
		this->analysisState = msg->getAnalysisMode();
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
				if (PluginServerConnection::kDisconnected == ipc->GetConnectionState())
				{
					ipc->SendPluginMessage(*msg);
				}
			}
		}
	}


}