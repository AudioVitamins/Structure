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

#ifndef __JUCE_HEADER_1A7C0314FA0C68BA__
#define __JUCE_HEADER_1A7C0314FA0C68BA__

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
class MainWindow  : public Component,
                    public ButtonListener
{
public:
    //==============================================================================
    MainWindow ();
    ~MainWindow();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* structureui_png;
    static const int structureui_pngSize;
    static const char* structureanalysegreenlight_png;
    static const int structureanalysegreenlight_pngSize;
    static const char* structureanalyseorangelight_png;
    static const int structureanalyseorangelight_pngSize;
    static const char* white_pushbutton_down_png;
    static const int white_pushbutton_down_pngSize;
    static const char* white_pushbutton_up_png;
    static const int white_pushbutton_up_pngSize;
    static const char* white_pushbutton_redled_36x36_up_png;
    static const int white_pushbutton_redled_36x36_up_pngSize;
    static const char* white_pushbutton_redled_36x36_down_png;
    static const int white_pushbutton_redled_36x36_down_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ImageButton> option1Button;
    ScopedPointer<ImageButton> option2Button;
    ScopedPointer<ImageButton> option3Button;
    ScopedPointer<ImageButton> analysisButton;
    ScopedPointer<ImageButton> allButton;
    Image cachedImage_structureui_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_1A7C0314FA0C68BA__
