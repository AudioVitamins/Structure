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
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class StructureAudioProcessorEditor  : public AudioProcessorEditor
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

    // Binary resources:
    static const char* structureuibackground_png;
    static const int structureuibackground_pngSize;
    static const char* white_pushbutton_down_png;
    static const int white_pushbutton_down_pngSize;
    static const char* white_pushbutton_redled_36x36_down_png;
    static const int white_pushbutton_redled_36x36_down_pngSize;
    static const char* white_pushbutton_redled_36x36_up_png;
    static const int white_pushbutton_redled_36x36_up_pngSize;
    static const char* white_pushbutton_up_png;
    static const int white_pushbutton_up_pngSize;
    static const char* structureanalysegreenlight_png;
    static const int structureanalysegreenlight_pngSize;
    static const char* structureanalyseorangelight_png;
    static const int structureanalyseorangelight_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    Image cachedImage_structureuibackground_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StructureAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_2498E6F5CF9CCDEE__
