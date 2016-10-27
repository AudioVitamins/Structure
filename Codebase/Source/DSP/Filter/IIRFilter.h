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
			Type b0_at48k_ = 1.0,
			Type b1_at48k_ = 0.0,
			Type b2_at48k_ = 0.0,
			Type a1_at48k_ = 0.0,
			Type a2_at48k_ = 0.0);
		~SecondOrderFilter();
		//==============================================================================
		// Call before the playback starts, to let the filter prepare itself. 
		virtual void prepareToPlay(double sampleRate, int numberOfChannels);

		// Call after the playback has stopped, to let the filter free up any 
		// resources it no longer needs. 
		virtual void releaseResources();

		// Renders the next block.
		void processBlock(AudioBuffer<Type>& buffer);

	private:
		void requantize();
	};

	template class SecondOrderFilter< float >;
	template class SecondOrderFilter < double >;

#endif
