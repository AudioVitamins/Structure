#include "Ebu128.h"
const float Ebu128Loudness::minimalReturnValue = -300.0f;
Ebu128Loudness::Ebu128Loudness() :
// Also initialise the two filters with the coefficients for a sample
 // rate of 44100 Hz. These values are given in the ITU-R BS.1770-2.
	preFilter(1.53512485958697,  // b0
		-2.69169618940638, // b1
		1.19839281085285,  // b2
		-1.69065929318241, // a1
		0.73248077421585), // a2
	revisedLowFrequencyBCurveFilter(1.0,               // b0
		-2.0,              // b1
		1.0,               // b2
		-1.99004745483398, // a1
		0.99007225036621), // a2 
	numberOfSamplesPerBin(0), numberOfSamplesInTheCurrentBin(0)
		{

}
Ebu128Loudness::~Ebu128Loudness() {

}

void Ebu128Loudness::prepareToPlay(double sampleRate,
	int numberOfInputChannels,
	int estimatedSamplesPerBlock,
	int expectedRequestRate) {
	// Modify the expectedRequestRate if needed.
	// It needs to be at least 10 and a multiple of 10 because
	//                --------------------------------
	// exactly every 0.1 second a gating block needs to be measured
	// (for the integrated loudness measurement).
	if (expectedRequestRate < 10)
		expectedRequestRate = 10;
	else
	{
		expectedRequestRate = (((expectedRequestRate - 1) / 10) + 1) * 10;
		// examples
		//  19 -> 20
		//  20 -> 20
		//  21 -> 30
	}
	// It also needs to be a divisor of the samplerate for accurate
	// M and S values (the integrated loudness (I value) would not be
	// affected by this inaccuracy.
	while (int(sampleRate) % expectedRequestRate != 0)
	{
		expectedRequestRate += 10;

		if (expectedRequestRate > sampleRate / 2)
		{
			expectedRequestRate = 10;
			break;
		}
	}
	numberOfBins = expectedRequestRate * 3; //sec // Number of bin 3 sec for example
	currentBin = 0;// Current bin
	numberOfSamplesPerBin = int(sampleRate / expectedRequestRate);
	numberOfSamplesInAllBins = numberOfBins * numberOfSamplesPerBin;
	averageOfTheLast3s.assign(numberOfInputChannels, 0.0);
	//Init weight channel
	channelWeighting.clear();
	for (int k = 0; k != numberOfInputChannels; ++k)
	{
		if (k == 3 || k == 4)
			// The left and right surround channels have a higher weight
			// because they seem louder to the human ear.
			channelWeighting.push_back(1.41);
		else
			channelWeighting.push_back(1.0);
	}
	// Set up the two filters for the K-Filtering.
	preFilter.prepareToPlay(sampleRate, numberOfInputChannels);
	revisedLowFrequencyBCurveFilter.prepareToPlay(sampleRate, numberOfInputChannels);
	bin.assign(numberOfInputChannels, std::vector<double>(numberOfBins, 0.0));
}

void Ebu128Loudness::processBlock(AudioSampleBuffer &buffer) {
	if (currentBin >= numberOfBins) return;
	bufferForMeasurement = buffer;
	const int numberOfChannels = bufferForMeasurement.getNumChannels();
	// STEP 1: K-weighted filter.
	// -----------------------------

	// Apply the pre-filter.
	// Used to account for the acoustic effects of the head.
	// This is the first part of the so called K-weighted filtering.
	preFilter.processBlock(bufferForMeasurement);

	// Apply the RLB filter (a simple highpass filter).
	// This is the second part of the so called K-weighted filtering.
	// Its name is in accordance to ITU-R BS.1770-2
	// (In ITU-R BS.1770-3 it's called 'a simple highpass filter').
	revisedLowFrequencyBCurveFilter.processBlock(bufferForMeasurement);

	// STEP 2: Mean square.
	// --------------------
	for (int k = 0; k != bufferForMeasurement.getNumChannels(); ++k)
	{
		float* theKthChannelData = bufferForMeasurement.getWritePointer(k);

		for (int i = 0; i != bufferForMeasurement.getNumSamples(); ++i)
			theKthChannelData[i] = theKthChannelData[i] * theKthChannelData[i];
	}
	// Step 3: Put to the pin
	if (numberOfSamplesInTheCurrentBin + bufferForMeasurement.getNumSamples()
		< numberOfSamplesPerBin)
	{
		for (int k = 0; k != numberOfChannels; ++k)
		{
			float* bufferOfChannelK = bufferForMeasurement.getWritePointer(k);
			double& theBinToSumTo = bin[k][currentBin];

			for (int i = 0; i != bufferForMeasurement.getNumSamples(); ++i)
			{
				theBinToSumTo += bufferOfChannelK[i];
			}
		}

		numberOfSamplesInTheCurrentBin += bufferForMeasurement.getNumSamples();
	}
	else {
		int positionInBuffer = 0;
		bool bufferStillContainsSamples = true;

		while (bufferStillContainsSamples && currentBin < numberOfBins)
		{
			// Figure out if the remaining samples in the buffer can all be
			// accumulated to the current bin.
			const int numberOfSamplesLeftInTheBuffer = bufferForMeasurement.getNumSamples() - positionInBuffer;
			int numberOfSamplesToPutIntoTheCurrentBin;

			if (numberOfSamplesLeftInTheBuffer
				< numberOfSamplesPerBin - numberOfSamplesInTheCurrentBin)
			{
				// Case 1: Partially fill a bin (by using all the samples left in the buffer).
				// ---------------------------------------------------------------------------
				// If all the samples from the buffer can be added to the
				// current bin.
				numberOfSamplesToPutIntoTheCurrentBin = numberOfSamplesLeftInTheBuffer;
				bufferStillContainsSamples = false;
			}
			else
			{
				// Case 2: Completely fill a bin (most likely the buffer will still contain some samples for the next bin).
				// --------------------------------------------------------------------------------------------------------
				// Accumulate samples to the current bin until it is full.
				numberOfSamplesToPutIntoTheCurrentBin = numberOfSamplesPerBin - numberOfSamplesInTheCurrentBin;
			}
			// Add the samples to the bin.
			for (int k = 0; k != numberOfChannels; ++k)
			{
				float* bufferOfChannelK = bufferForMeasurement.getWritePointer(k);
				double& theBinToSumTo = bin[k][currentBin];
				for (int i = positionInBuffer;
					i != positionInBuffer + numberOfSamplesToPutIntoTheCurrentBin;
					++i)
				{
					theBinToSumTo += bufferOfChannelK[i];
				}
			}
			numberOfSamplesInTheCurrentBin += numberOfSamplesToPutIntoTheCurrentBin;

			// If there are some samples left in the buffer
			// => A bin has just been completely filled (case 2 above).
			if (bufferStillContainsSamples)
			{
				positionInBuffer = positionInBuffer
					+ numberOfSamplesToPutIntoTheCurrentBin;

				// We have completely filled a bin.
				// This is the moment the larger sums need to be updated.
				for (int k = 0; k != numberOfChannels; ++k)
				{
					double sumOfAllBins = 0.0;
					// which covers the last 3s.

					for (int b = 0; b != numberOfBins; ++b)
						sumOfAllBins += bin[k][b];

					averageOfTheLast3s[k] = sumOfAllBins / numberOfSamplesInAllBins;

					// Short term loudness
					// ===================
					{
						double weightedSum = 0.0;

						for (int k = 0; k != numberOfChannels; ++k)
							weightedSum += channelWeighting[k] * averageOfTheLast3s[k];

						if (weightedSum > 0.0)
							// This refers to equation (2) in ITU-R BS.1770-2
							shortTermLoudness = jmax(float(-0.691 + 10.* std::log10(weightedSum)), minimalReturnValue);
						else
							// Since returning a value of -nan most probably would lead to
							// a malfunction, return the minimal return value.
							shortTermLoudness = minimalReturnValue;

						// Maximum
						if (shortTermLoudness > maximumShortTermLoudness)
							maximumShortTermLoudness = shortTermLoudness;
					}
				}
				// Move on to the next bin
				currentBin = (currentBin + 1);
				// Set it to zero.
				for (int k = 0; k != numberOfChannels && currentBin < numberOfBins; ++k)
				{
					bin[k][currentBin] = 0.0;
				}
				numberOfSamplesInTheCurrentBin = 0;
				// Handle listener
				if (currentBin >= numberOfBins) {
					analysisCompleted();
				}
			}
		}
	}

}

float Ebu128Loudness::getShortTermLoudness() const
{
	return shortTermLoudness;
}

float Ebu128Loudness::getMaximumShortTermLoudness() const
{
	return maximumShortTermLoudness;
}

void Ebu128Loudness::reset() {
	startAnalysis();
	// Bin reset
	currentBin = 0;
	bin.assign(bin.size(), std::vector<double>(numberOfBins, 0.0));
	// Short term loudness
	shortTermLoudness = minimalReturnValue;
	maximumShortTermLoudness = minimalReturnValue;
}

void Ebu128Loudness::analysisCompleted() {
	Ebu128Loudness* ebu128 = this; // (must use an intermediate variable here to avoid a VS2005 compiler bug)
	for (int i = 0; i < listListener.size(); i++) {
		listListener[i]->finishAnalysis(ebu128);
	}
}

void Ebu128Loudness::startAnalysis() {
	Ebu128Loudness* ebu128 = this; // (must use an intermediate variable here to avoid a VS2005 compiler bug)
	for (int i = 0; i < listListener.size(); i++) {
		listListener[i]->startAnalysis(ebu128);
	}
}

void Ebu128Loudness::addListener(Listener * listener) {
	listListener.push_back(listener);
}

void Ebu128Loudness::removeListener(Listener * listener) {
	for (std::vector<Listener *>::iterator it = listListener.begin(); it != listListener.end(); it++) {
		if (*it == listener) {
			listListener.erase(it);
			break;
		}
	}
}