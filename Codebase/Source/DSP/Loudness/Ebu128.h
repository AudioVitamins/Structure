
#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../Filter/IIRFilter.h"

#define SILENCE_DB -60
class Ebu128Loudness {
	SecondOrderFilter<float> preFilter; // Pre filter
	SecondOrderFilter<float> revisedLowFrequencyBCurveFilter; // Rlb filter
	AudioSampleBuffer bufferForMeasurement;
	int numberOfSamplesPerBin, numberOfSamplesInAllBins, numberOfSamplesInTheCurrentBin;
	int numberOfBins;// Number of bin on each channel
	int currentBin;
	std::vector<std::vector<double>> bin; // bin on all channel, each channel have numberofbin
	/*
	The average of the filtered and squared samples of the last
	3 seconds.
	A value for each channel.
	*/
	std::vector<double> averageOfTheLast3s;
	float silenceThreshold;
	std::vector<double> channelWeighting;
	std::vector<float> momentaryLoudnessForIndividualChannels;
	float shortTermLoudness;
	float maximumShortTermLoudness;
public:
	static const float minimalReturnValue;
	class Listener {
	public:
		virtual void finishAnalysis(Ebu128Loudness *) = 0;
		virtual void startAnalysis(Ebu128Loudness *) = 0;
	};
	std::vector<Listener *> listListener;
	void addListener(Listener * listenser);
	void removeListener(Listener * listenser);
	void analysisCompleted();
	void startAnalysis();
public:
	Ebu128Loudness();
	~Ebu128Loudness();
	void prepareToPlay(double sampleRate,
		int numberOfInputChannels,
		int estimatedSamplesPerBlock,
		int expectedRequestRate);
	void processBlock(AudioSampleBuffer &buffer);
	void setShortTermLoudness(float val);
	float getShortTermLoudness() const;
	float getMaximumShortTermLoudness() const;
	void reset();
};

typedef Ebu128Loudness::Listener Ebu128LoudnessListener;