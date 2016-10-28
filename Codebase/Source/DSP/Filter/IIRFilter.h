#ifndef IIR_FILTER_H
#define IIR_FILTER_H
#include "../../../JuceLibraryCode/JuceHeader.h"
	template <typename Type>
	class IIRFilterBase {
	public:
		IIRFilterBase()
		{
		};

		virtual ~IIRFilterBase() {
		};

		virtual void prepareToPlay(double sampleRate, int numberOfChannels) = 0;

		virtual void releaseResources() {
		};

		virtual void processBlock(AudioBuffer<Type>& buffer) {
		};

		virtual void processBlock(Type *buffer) {
		};
	};
	template <typename Type>
	class SecondOrderFilter : public IIRFilterBase<Type> {
		Type b0_at48k, b1_at48k, b2_at48k, a1_at48k, a2_at48k
			, b0, b1, b2, a1, a2;

		Type Q, VH, VB, VL, arctanK;
		HeapBlock<Type> z1, z2;

		int mumChannels;
		int sampleRate;
	public:
		SecondOrderFilter(
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
		~SecondOrderFilter() {

		}

		void prepareToPlay(double sampleRate, int numberOfChannels) {
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

		void releaseResources() {

		}

		void processBlock(AudioBuffer<Type>& buffer) {
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

	private:
		void requantize() {
			Type sampleRate48k = 48000;
			const Type K = tan(arctanK * sampleRate48k / sampleRate);
			const Type commonFactor = 1. / (1. + K / Q + K*K);
			b0 = (VH + VB*K / Q + VL*K*K)*commonFactor;
			b1 = 2.*(VL*K*K - VH)*commonFactor;
			b2 = (VH - VB*K / Q + VL*K*K)*commonFactor;
			a1 = 2.*(K*K - 1.)*commonFactor;
			a2 = (1. - K / Q + K*K)*commonFactor;
		}
	};

	template class SecondOrderFilter< float >;
	template class SecondOrderFilter < double >;

#endif
