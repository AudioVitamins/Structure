/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//[/Headers]

#include "DotComponent.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class StructureAudioProcessorEditor  : public AudioProcessorEditor,
                                       public Timer,
                                       public Button::Listener
{
public:
    //==============================================================================
    StructureAudioProcessorEditor (StructureAudioProcessor& p);
    ~StructureAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void synGUI();
	void updateActiveMode();
	void updateStateAnalysis();
	void updateMetterValue();
	void timerCallback();
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* structureuibackground_png;
    static const int structureuibackground_pngSize;
    static const char* white_pushbutton_44x60_down_png;
    static const int white_pushbutton_44x60_down_pngSize;
    static const char* white_pushbutton_44x60_up_png;
    static const int white_pushbutton_44x60_up_pngSize;
    static const char* white_pushbutton_greenLed_png;
    static const int white_pushbutton_greenLed_pngSize;
    static const char* white_pushbutton_orangeLed_png;
    static const int white_pushbutton_orangeLed_pngSize;
    static const char* white_pushbutton_orangeLed_down_png;
    static const int white_pushbutton_orangeLed_down_pngSize;
    static const char* white_pushbutton_redled_36x36_down_png;
    static const int white_pushbutton_redled_36x36_down_pngSize;
    static const char* white_pushbutton_redled_36x36_up_png;
    static const int white_pushbutton_redled_36x36_up_pngSize;
    static const char* white_pushbutton_down_png;
    static const int white_pushbutton_down_pngSize;
    static const char* white_pushbutton_up_png;
    static const int white_pushbutton_up_pngSize;
    static const char* structureanalysegreenlight_png;
    static const int structureanalysegreenlight_pngSize;
    static const char* structureanalyseorangelight_png;
    static const int structureanalyseorangelight_pngSize;
    static const char* structuredemoexpired_png;
    static const int structuredemoexpired_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	StructureAudioProcessor *p;

	Image redUpImg;
	Image redDownImg;
	Image greenDownImg;
	Image orangeDownImg;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> demoVersionlb;
    ScopedPointer<ImageButton> instrumentsBtn;
    ScopedPointer<ImageButton> busBtn;
    ScopedPointer<ImageButton> voxBtn;
    ScopedPointer<ImageButton> analyseBtn;
    ScopedPointer<ImageButton> allBtn;
    ScopedPointer<DotComponent> analyseDotCom;
    ScopedPointer<Label> metterLbt;
    ScopedPointer<ImageButton> demoLinkBtn;
    Image cachedImage_structureuibackground_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StructureAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
