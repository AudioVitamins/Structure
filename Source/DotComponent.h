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
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DotComponent  : public Component
{
public:
    //==============================================================================
    DotComponent ();
    ~DotComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	enum {
		ANALYSIS,
		APPLY
	};
	void setMode(bool analyzingMode);
	void setMode(int mode);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;

    // Binary resources:
    static const char* structureanalysegreenlight_png;
    static const int structureanalysegreenlight_pngSize;
    static const char* structureanalyseorangelight_png;
    static const int structureanalyseorangelight_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	int mode;
	bool analyzingMode;
	Image orangeImg;
	Image greenImg;
    //[/UserVariables]

    //==============================================================================
    Image cachedImage_structureanalyseorangelight_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DotComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
