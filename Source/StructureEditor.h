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
#include "./authorization/TrialDialog.h"
#include "./authorization/AuthDialog.h"


//[/Headers]

#include "DotComponent.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class StructureGUI  : public AudioProcessorEditor,
                                       public MultiTimer,
                                       public CptNotify,
                                       public Button::Listener
{
public:
    //==============================================================================
    StructureGUI (StructureAudioProcessor& p);
    ~StructureGUI();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void synGUI();
//	void updateActiveMode();
	void updateStateAnalysis();
	void updateMetterValue();
	void timerCallback(int timerID);
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
    static const char* authorization_png;
    static const int authorization_pngSize;
    static const char* lock2small_png;
    static const int lock2small_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	StructureAudioProcessor *p;

	Image redUpImg;
	Image redDownImg;
	Image greenDownImg;
	Image orangeDownImg;
    //@AS
    SeqGlob mGlob;
    bool mUnlocked;// will be set true when we are unlocked
    // if set to true then the authorize function will try to reauthorize if
    // expired or within reauth period
    bool mTryReauth;
    // For trial dialog
    SeqTrialDialog mTrialDialog;
    SeqAuthDialog mAuthDlg;
    // Inherited via CptNotify
    virtual void cptValueChange(int cptId, int value) override;
    void authorize();
    void prepareAuthorization(bool allowRenew);
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ImageButton> instrumentsBtn;
    ScopedPointer<ImageButton> busBtn;
    ScopedPointer<ImageButton> voxBtn;
    ScopedPointer<ImageButton> analyseBtn;
    ScopedPointer<ImageButton> allBtn;
    ScopedPointer<DotComponent> analyseDotCom;
    ScopedPointer<ImageButton> mBtnUnlock;
    Image cachedImage_structureuibackground_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StructureGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
