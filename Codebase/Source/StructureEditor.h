/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_2498E6F5CF9CCDEE__
#define __JUCE_HEADER_2498E6F5CF9CCDEE__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class StructureAudioProcessorEditor  : public AudioProcessorEditor,
                                       public ButtonListener
{
public:
    //==============================================================================
    StructureAudioProcessorEditor (StructureAudioProcessor& p);
    ~StructureAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
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


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ImageButton> instrumentsBtn;
    ScopedPointer<ImageButton> busBtn;
    ScopedPointer<ImageButton> voxBtn;
    ScopedPointer<ImageButton> analyseBtn;
    ScopedPointer<ImageButton> analyseBtn2;
    Image cachedImage_structureuibackground_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StructureAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_2498E6F5CF9CCDEE__
