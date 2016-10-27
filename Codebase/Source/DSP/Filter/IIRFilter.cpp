#include "IIRFilter.h"

	template <typename Type> SecondOrderFilter<typename Type>::SecondOrderFilter(
		Type b0_at48k_,
		Type b1_at48k_,
		Type b2_at48k_,
		Type a1_at48k_,
		Type a2_at48k_) : IIRFilterBase<Type>(),
		b0_at48k(b0_at48k_),
		b1_at48k(b1_at48k_),
		b2_at48k(b2_at48k_),
		a1_at48k(a1_at48k_),
		a2_at48k(a2_at48k_),
		b0(b0_at48k_),
		b1(b1_at48k_),
		b2(b2_at48k_),
		a1(a1_at48k_),
		a2(a2_at48k_),
		mumChannels(0),
		sampleRate(0)
	{
		Type KoverQ = (2. - 2. * a2_at48k) / (a2_at48k - a1_at48k + 1.);
		Type K = sqrt((a1_at48k + a2_at48k + 1.) / (a2_at48k - a1_at48k + 1.));
		Q = K / KoverQ;
		arctanK = atan(K);
		VB = (b0_at48k - b2_at48k) / (1. - a2_at48k);
		VH = (b0_at48k - b1_at48k + b2_at48k) / (a2_at48k - a1_at48k + 1.);
		VL = (b0_at48k + b1_at48k + b2_at48k) / (a1_at48k + a2_at48k + 1.);
	}
	template <typename Type> SecondOrderFilter<typename Type>::~SecondOrderFilter() {

	}

	template <typename Type> void SecondOrderFilter<typename Type>::prepareToPlay(double sampleRate, int numberOfChannels) {
		this->mumChannels = numberOfChannels;
		this->sampleRate = sampleRate;

		// Initialize z1 and z2.
		z1.calloc(numberOfChannels);
		z2.calloc(numberOfChannels);

		// Determine the filter coefficients.
		const double sampleRate48k = 48000.;
		if (sampleRate == sampleRate48k)
		{
			b0 = b0_at48k;
			b1 = b1_at48k;
			b2 = b2_at48k;
			a1 = a1_at48k;
			a2 = a2_at48k;
		}
		else
		{
			requantize();
		}

	}

	template <typename Type> void SecondOrderFilter<typename Type>::releaseResources() {

	}

	template <typename Type> void SecondOrderFilter<typename Type>::processBlock(AudioBuffer<Type>& buffer) {
		int numOfChannels = jmin(mumChannels, buffer.getNumChannels());

		for (int channel = 0; channel < numOfChannels; ++channel)
		{
			Type* samples = buffer.getWritePointer(channel);

			for (int i = 0; i < buffer.getNumSamples(); ++i)
			{
				const Type in = samples[i];

				double factorForB0 = in - a1 * z1[channel] - a2 * z2[channel];
				double out = b0 * factorForB0
					+ b1 * z1[channel]
					+ b2 * z2[channel];

				if (!(out < -1.0e-8 || out > 1.0e-8))
					out = 0.0;

				z2[channel] = z1[channel];
				z1[channel] = factorForB0;

				samples[i] = Type(out);
			}

		}
	}

	template <typename Type> void SecondOrderFilter<typename Type>::requantize() {
		Type sampleRate48k = 48000;
		const Type K = tan(arctanK * sampleRate48k / sampleRate);
		const Type commonFactor = 1. / (1. + K / Q + K*K);
		b0 = (VH + VB*K / Q + VL*K*K)*commonFactor;
		b1 = 2.*(VL*K*K - VH)*commonFactor;
		b2 = (VH - VB*K / Q + VL*K*K)*commonFactor;
		a1 = 2.*(K*K - 1.)*commonFactor;
		a2 = (1. - K / Q + K*K)*commonFactor;
	}
