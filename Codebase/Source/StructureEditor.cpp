/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "StructureEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
StructureAudioProcessorEditor::StructureAudioProcessorEditor (StructureAudioProcessor& p)
    : AudioProcessorEditor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    this->p = &p;

    redUpImg = ImageCache::getFromMemory(white_pushbutton_redled_36x36_up_png, white_pushbutton_redled_36x36_up_pngSize);
    redDownImg = ImageCache::getFromMemory(white_pushbutton_redled_36x36_down_png, white_pushbutton_redled_36x36_down_pngSize);
    greenDownImg = ImageCache::getFromMemory(white_pushbutton_greenLed_png, white_pushbutton_greenLed_pngSize);
    orangeDownImg = ImageCache::getFromMemory(white_pushbutton_orangeLed_down_png, white_pushbutton_orangeLed_down_pngSize);
    //[/Constructor_pre]

    addAndMakeVisible (demoVersionlb = new Label ("Demo Version",
                                                  TRANS("14 DAY DEMO EXPIRED\n"
                                                  "Click here to visit audiovitamins.com\n"
                                                  "and to purchase structure")));
    demoVersionlb->setFont (Font (15.00f, Font::bold));
    demoVersionlb->setJustificationType (Justification::centred);
    demoVersionlb->setEditable (false, false, false);
    demoVersionlb->setColour (Label::backgroundColourId, Colour (0x00020000));
    demoVersionlb->setColour (Label::textColourId, Colours::red);
    demoVersionlb->setColour (Label::outlineColourId, Colour (0x00000000));
    demoVersionlb->setColour (TextEditor::textColourId, Colours::black);
    demoVersionlb->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    demoVersionlb->setColour (TextEditor::highlightColourId, Colour (0x4012ff15));

    addAndMakeVisible (instrumentsBtn = new ImageButton ("Instruments"));
    instrumentsBtn->setButtonText (TRANS("new button"));
    instrumentsBtn->setRadioGroupId (1);
    instrumentsBtn->addListener (this);

    instrumentsBtn->setImages (false, true, true,
                               ImageCache::getFromMemory (white_pushbutton_redled_36x36_up_png, white_pushbutton_redled_36x36_up_pngSize), 1.000f, Colour (0x00000000),
                               Image(), 1.000f, Colour (0x00000000),
                               ImageCache::getFromMemory (white_pushbutton_redled_36x36_down_png, white_pushbutton_redled_36x36_down_pngSize), 1.000f, Colour (0x00000000));
    addAndMakeVisible (busBtn = new ImageButton ("Bus Group"));
    busBtn->setButtonText (TRANS("new button"));
    busBtn->setRadioGroupId (1);
    busBtn->addListener (this);

    busBtn->setImages (false, true, true,
                       ImageCache::getFromMemory (white_pushbutton_redled_36x36_up_png, white_pushbutton_redled_36x36_up_pngSize), 1.000f, Colour (0x00000000),
                       Image(), 1.000f, Colour (0x00000000),
                       ImageCache::getFromMemory (white_pushbutton_redled_36x36_down_png, white_pushbutton_redled_36x36_down_pngSize), 1.000f, Colour (0x00000000));
    addAndMakeVisible (voxBtn = new ImageButton ("Vox Lead"));
    voxBtn->setButtonText (TRANS("new button"));
    voxBtn->setRadioGroupId (1);
    voxBtn->addListener (this);

    voxBtn->setImages (false, true, true,
                       ImageCache::getFromMemory (white_pushbutton_redled_36x36_up_png, white_pushbutton_redled_36x36_up_pngSize), 1.000f, Colour (0x00000000),
                       Image(), 1.000f, Colour (0x00000000),
                       ImageCache::getFromMemory (white_pushbutton_redled_36x36_down_png, white_pushbutton_redled_36x36_down_pngSize), 1.000f, Colour (0x00000000));
    addAndMakeVisible (analyseBtn = new ImageButton ("Analyse"));
    analyseBtn->setButtonText (TRANS("new button"));
    analyseBtn->addListener (this);

    analyseBtn->setImages (false, true, true,
                           ImageCache::getFromMemory (white_pushbutton_up_png, white_pushbutton_up_pngSize), 1.000f, Colour (0x00000000),
                           Image(), 1.000f, Colour (0x00000000),
                           ImageCache::getFromMemory (white_pushbutton_down_png, white_pushbutton_down_pngSize), 1.000f, Colour (0x00000000));
    addAndMakeVisible (allBtn = new ImageButton ("All"));
    allBtn->setButtonText (TRANS("new button"));
    allBtn->addListener (this);

    allBtn->setImages (false, true, true,
                       ImageCache::getFromMemory (white_pushbutton_up_png, white_pushbutton_up_pngSize), 1.000f, Colour (0x00000000),
                       Image(), 1.000f, Colour (0x00000000),
                       ImageCache::getFromMemory (white_pushbutton_down_png, white_pushbutton_down_pngSize), 1.000f, Colour (0x00000000));
    addAndMakeVisible (analyseDotCom = new DotComponent());
    addAndMakeVisible (metterLbt = new Label ("Meeter",
                                              TRANS("0.00 db")));
    metterLbt->setFont (Font (15.00f, Font::plain));
    metterLbt->setJustificationType (Justification::centred);
    metterLbt->setEditable (false, false, false);
    metterLbt->setColour (Label::textColourId, Colours::white);
    metterLbt->setColour (TextEditor::textColourId, Colours::black);
    metterLbt->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (demoLinkBtn = new ImageButton ("Demo Link"));
    demoLinkBtn->setButtonText (String());
    demoLinkBtn->addListener (this);

    demoLinkBtn->setImages (false, true, true,
                            ImageCache::getFromMemory (structuredemoexpired_png, structuredemoexpired_pngSize), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000));
    cachedImage_structureuibackground_png_1 = ImageCache::getFromMemory (structureuibackground_png, structureuibackground_pngSize);

    //[UserPreSize]
    //analyseBtn->setClickingTogglesState(true);
    //allBtn->setClickingTogglesState(true);
    //[/UserPreSize]

    setSize (260, 200);


    //[Constructor] You can add your own custom stuff here..
    synGUI();
    startTimer(50);
    demoLinkBtn->setVisible(false);
    demoVersionlb->setVisible(false);
#if TEST_VERSION
    metterLbt->setVisible(true);
    synGUI();
#else
    metterLbt->setVisible(false);
#endif
    //[/Constructor]
}

StructureAudioProcessorEditor::~StructureAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    demoVersionlb = nullptr;
    instrumentsBtn = nullptr;
    busBtn = nullptr;
    voxBtn = nullptr;
    analyseBtn = nullptr;
    allBtn = nullptr;
    analyseDotCom = nullptr;
    metterLbt = nullptr;
    demoLinkBtn = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void StructureAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.drawImage (cachedImage_structureuibackground_png_1,
                 0, 0, 260, 200,
                 0, 0, cachedImage_structureuibackground_png_1.getWidth(), cachedImage_structureuibackground_png_1.getHeight());

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void StructureAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    demoVersionlb->setBounds (-29, 48, 322, 104);
    instrumentsBtn->setBounds (29, 8, 44, 60);
    busBtn->setBounds (106, 8, 44, 60);
    voxBtn->setBounds (185, 8, 44, 60);
    analyseBtn->setBounds (25, 111, 44, 44);
    allBtn->setBounds (76, 111, 44, 44);
    analyseDotCom->setBounds (40, 103, 11, 11);
    metterLbt->setBounds (24, 176, 88, 24);
    demoLinkBtn->setBounds (0, 0, 264, 200);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void StructureAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == instrumentsBtn)
    {
        //[UserButtonCode_instrumentsBtn] -- add your button handler code here..
        JIMMY_LOGGER_PRINT(JIMMY_LOGGER_DATA, "instrumentsBtn Pressed\n");
        buttonThatWasClicked->setToggleState(true, false);
        p->optionMode = INSTRUMENTS_MODE;
        //[/UserButtonCode_instrumentsBtn]
    }
    else if (buttonThatWasClicked == busBtn)
    {
        //[UserButtonCode_busBtn] -- add your button handler code here..
        JIMMY_LOGGER_PRINT(JIMMY_LOGGER_DATA, "busBtn Pressed\n");
        buttonThatWasClicked->setToggleState(true, false);
        p->optionMode = VOX_LEAD_MODE;
        //[/UserButtonCode_busBtn]
    }
    else if (buttonThatWasClicked == voxBtn)
    {
        //[UserButtonCode_voxBtn] -- add your button handler code here..
        JIMMY_LOGGER_PRINT(JIMMY_LOGGER_DATA, "voxBtn Pressed\n");
        buttonThatWasClicked->setToggleState(true, false);
        p->optionMode = BUS_GROUP_MODE;
        //[/UserButtonCode_voxBtn]
    }
    else if (buttonThatWasClicked == analyseBtn)
    {
        //[UserButtonCode_analyseBtn] -- add your button handler code here..
        JIMMY_LOGGER_PRINT(JIMMY_LOGGER_DATA, "analyseBtn Pressed\n");
        p->analysisState = false;
        p->ResetMetter();
        updateStateAnalysis();
        //buttonThatWasClicked->setToggleState(true, false);
        //[/UserButtonCode_analyseBtn]
    }
    else if (buttonThatWasClicked == allBtn)
    {
        //[UserButtonCode_allBtn] -- add your button handler code here..
        JIMMY_LOGGER_PRINT(JIMMY_LOGGER_DATA, "allBtn Pressed\n");
        p->analysisState = false;
        p->ResetMetter();
        updateStateAnalysis();
        p->sendAnalysisAllMode();
        //buttonThatWasClicked->setToggleState(true, false);
        //[/UserButtonCode_allBtn]
    }
    else if (buttonThatWasClicked == demoLinkBtn)
    {
        //[UserButtonCode_demoLinkBtn] -- add your button handler code here..
        URL("https://www.audiovitamins.com/structure?utm_source=expireddemo&utm_medium=content&utm_campaign=demoversion").launchInDefaultBrowser();
        //[/UserButtonCode_demoLinkBtn]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void StructureAudioProcessorEditor::timerCallback() {
    synGUI();
    //p->sendAnalysisAllMode();
}
void StructureAudioProcessorEditor::synGUI() {
    updateActiveMode();
    updateStateAnalysis();
    updateMetterValue();
    updateDemoVersion();
}
void StructureAudioProcessorEditor::updateDemoVersion() {
    if(!p->authentication->isValidDate()){
        demoLinkBtn->setVisible(true);
        demoVersionlb->setVisible(true);
    }
}
void StructureAudioProcessorEditor::updateActiveMode() {
    int mode = p->optionMode;
    if (mode == INSTRUMENTS_MODE && !instrumentsBtn->getToggleState()){
        instrumentsBtn->setToggleState(true, false);
    }
    else if (mode == VOX_LEAD_MODE && !busBtn->getToggleState()) {
        busBtn->setToggleState(true, false);
    }
    else if (mode == BUS_GROUP_MODE && !voxBtn->getToggleState()) {
        voxBtn->setToggleState(true, false);
    }
}
void StructureAudioProcessorEditor::updateStateAnalysis() {
    bool state = p->analysisState;
    analyseDotCom->setMode(state);
    /*ImageButton *currImageButton = analyseBtn;
     if (optionMode == INSTRUMENTS_MODE) {
     currImageButton = instrumentsBtn;
     }
     else if (optionMode == VOX_LEAD_MODE) {
     currImageButton = busBtn;
     }
     else if (optionMode == BUS_GROUP_MODE) {
     currImageButton = voxBtn;
     }


     if (currImageButton != nullptr) {
     if (state == GREEN) {
     currImageButton->setImages(false, false, false,
     greenDownImg, 1.0f, Colours::transparentWhite,
     instrumentsBtn->getOverImage(), 1.0f, Colours::transparentWhite,
     instrumentsBtn->getDownImage(), 1.0f, Colours::transparentWhite);
     }
     else if (state == ORANGE) {
     currImageButton->setImages(false, false, false,
     instrumentsBtn->getNormalImage(), 1.0f, Colours::transparentWhite,
     instrumentsBtn->getOverImage(), 1.0f, Colours::transparentWhite,
     orangeDownImg, 1.0f, Colours::transparentWhite);
     }
     else {
     currImageButton->setImages(false, false, false,
     instrumentsBtn->getNormalImage(), 1.0f, Colours::transparentWhite,
     instrumentsBtn->getOverImage(), 1.0f, Colours::transparentWhite,
     redDownImg, 1.0f, Colours::transparentWhite);
     }

     }*/
}

void StructureAudioProcessorEditor::updateMetterValue() {
    char text[100] = { 0 };
    sprintf(text, "%2.2f Db", p->ebu128.getShortTermLoudness());
    metterLbt->setText(text, NotificationType::dontSendNotification);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="StructureAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="StructureAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="260" initialHeight="200">
  <BACKGROUND backgroundColour="ffffffff">
    <IMAGE pos="0 0 260 200" resource="structureuibackground_png" opacity="1"
           mode="0"/>
  </BACKGROUND>
  <LABEL name="Demo Version" id="212388da8e5cad8a" memberName="demoVersionlb"
         virtualName="" explicitFocusOrder="0" pos="-29 48 322 104" bkgCol="20000"
         textCol="ffff0000" outlineCol="0" edTextCol="ff000000" edBkgCol="0"
         hiliteCol="4012ff15" labelText="14 DAY DEMO EXPIRED&#10;Click here to visit audiovitamins.com&#10;and to purchase structure"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="1" italic="0" justification="36"/>
  <IMAGEBUTTON name="Instruments" id="f158cac93ece10b3" memberName="instrumentsBtn"
               virtualName="" explicitFocusOrder="0" pos="29 8 44 60" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="1" keepProportions="1"
               resourceNormal="white_pushbutton_redled_36x36_up_png" opacityNormal="1"
               colourNormal="0" resourceOver="" opacityOver="1" colourOver="0"
               resourceDown="white_pushbutton_redled_36x36_down_png" opacityDown="1"
               colourDown="0"/>
  <IMAGEBUTTON name="Bus Group" id="70afa4eea71c389b" memberName="busBtn" virtualName=""
               explicitFocusOrder="0" pos="106 8 44 60" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="1" keepProportions="1"
               resourceNormal="white_pushbutton_redled_36x36_up_png" opacityNormal="1"
               colourNormal="0" resourceOver="" opacityOver="1" colourOver="0"
               resourceDown="white_pushbutton_redled_36x36_down_png" opacityDown="1"
               colourDown="0"/>
  <IMAGEBUTTON name="Vox Lead" id="dbfc28e5c361cc88" memberName="voxBtn" virtualName=""
               explicitFocusOrder="0" pos="185 8 44 60" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="1" keepProportions="1"
               resourceNormal="white_pushbutton_redled_36x36_up_png" opacityNormal="1"
               colourNormal="0" resourceOver="" opacityOver="1" colourOver="0"
               resourceDown="white_pushbutton_redled_36x36_down_png" opacityDown="1"
               colourDown="0"/>
  <IMAGEBUTTON name="Analyse" id="f4e517fbc77ff0c4" memberName="analyseBtn"
               virtualName="" explicitFocusOrder="0" pos="25 111 44 44" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="white_pushbutton_up_png" opacityNormal="1" colourNormal="0"
               resourceOver="" opacityOver="1" colourOver="0" resourceDown="white_pushbutton_down_png"
               opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="All" id="546e589926457e73" memberName="allBtn" virtualName=""
               explicitFocusOrder="0" pos="76 111 44 44" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="white_pushbutton_up_png" opacityNormal="1" colourNormal="0"
               resourceOver="" opacityOver="1" colourOver="0" resourceDown="white_pushbutton_down_png"
               opacityDown="1" colourDown="0"/>
  <JUCERCOMP name="" id="59319dd7a237afb9" memberName="analyseDotCom" virtualName=""
             explicitFocusOrder="0" pos="40 103 11 11" sourceFile="DotComponent.cpp"
             constructorParams=""/>
  <LABEL name="Meeter" id="2996657d953a87ce" memberName="metterLbt" virtualName=""
         explicitFocusOrder="0" pos="24 176 88 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="0.00 db" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <IMAGEBUTTON name="Demo Link" id="ed1c245236e0e227" memberName="demoLinkBtn"
               virtualName="" explicitFocusOrder="0" pos="0 0 264 200" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="structuredemoexpired_png" opacityNormal="1" colourNormal="0"
               resourceOver="" opacityOver="1" colourOver="0" resourceDown=""
               opacityDown="1" colourDown="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: structureuibackground_png, 10134, "../Graphics/structure-UI-background.png"
static const unsigned char resource_StructureAudioProcessorEditor_structureuibackground_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,4,0,0,0,200,8,2,0,0,0,129,55,8,38,0,0,0,25,116,69,
88,116,83,111,102,116,119,97,114,101,0,65,100,111,98,101,32,73,109,97,103,101,82,101,97,100,121,113,201,101,60,0,0,3,107,105,84,88,116,88,77,76,58,99,111,109,46,97,100,111,98,101,46,120,109,112,0,0,0,
0,0,60,63,120,112,97,99,107,101,116,32,98,101,103,105,110,61,34,239,187,191,34,32,105,100,61,34,87,53,77,48,77,112,67,101,104,105,72,122,114,101,83,122,78,84,99,122,107,99,57,100,34,63,62,32,60,120,58,
120,109,112,109,101,116,97,32,120,109,108,110,115,58,120,61,34,97,100,111,98,101,58,110,115,58,109,101,116,97,47,34,32,120,58,120,109,112,116,107,61,34,65,100,111,98,101,32,88,77,80,32,67,111,114,101,
32,53,46,53,45,99,48,49,52,32,55,57,46,49,53,49,52,56,49,44,32,50,48,49,51,47,48,51,47,49,51,45,49,50,58,48,57,58,49,53,32,32,32,32,32,32,32,32,34,62,32,60,114,100,102,58,82,68,70,32,120,109,108,110,115,
58,114,100,102,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,49,57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,97,120,45,110,115,35,34,62,32,60,114,100,102,58,68,
101,115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,32,120,109,108,110,115,58,120,109,112,77,77,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,
47,120,97,112,47,49,46,48,47,109,109,47,34,32,120,109,108,110,115,58,115,116,82,101,102,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,115,84,121,
112,101,47,82,101,115,111,117,114,99,101,82,101,102,35,34,32,120,109,108,110,115,58,120,109,112,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,34,
32,120,109,112,77,77,58,79,114,105,103,105,110,97,108,68,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,48,55,56,48,49,49,55,52,48,55,50,48,54,56,49,49,56,67,49,52,68,69,48,68,65,
55,70,69,50,51,52,57,34,32,120,109,112,77,77,58,68,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,51,65,57,57,65,54,48,52,65,48,57,56,49,49,69,54,65,57,49,55,68,48,70,68,52,53,55,
51,51,69,68,68,34,32,120,109,112,77,77,58,73,110,115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,51,65,57,57,65,54,48,51,65,48,57,56,49,49,69,54,65,57,49,55,68,48,70,68,52,53,55,51,51,
69,68,68,34,32,120,109,112,58,67,114,101,97,116,111,114,84,111,111,108,61,34,65,100,111,98,101,32,80,104,111,116,111,115,104,111,112,32,67,67,32,40,77,97,99,105,110,116,111,115,104,41,34,62,32,60,120,
109,112,77,77,58,68,101,114,105,118,101,100,70,114,111,109,32,115,116,82,101,102,58,105,110,115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,52,51,102,55,51,52,97,102,45,97,50,56,53,45,
52,97,97,101,45,57,57,54,97,45,100,99,53,97,52,55,56,54,101,52,101,49,34,32,115,116,82,101,102,58,100,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,48,55,56,48,49,49,55,52,48,55,
50,48,54,56,49,49,56,67,49,52,68,69,48,68,65,55,70,69,50,51,52,57,34,47,62,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,32,60,47,114,100,102,58,82,68,70,62,32,60,47,120,58,120,
109,112,109,101,116,97,62,32,60,63,120,112,97,99,107,101,116,32,101,110,100,61,34,114,34,63,62,179,134,210,190,0,0,35,193,73,68,65,84,120,218,236,157,7,124,20,101,250,199,167,236,236,108,207,38,187,233,
129,80,18,186,128,244,122,210,4,164,137,93,57,219,221,217,176,156,250,71,68,145,187,179,68,1,17,65,68,207,179,220,97,57,20,21,164,41,69,154,162,20,193,83,64,136,180,144,0,233,187,41,219,119,103,103,230,
255,204,12,89,150,36,155,108,52,192,6,158,47,203,126,102,223,121,231,157,119,102,159,223,251,60,207,59,147,29,178,123,247,62,4,130,32,4,65,225,41,64,16,20,3,130,160,24,16,4,197,128,32,40,6,4,65,49,32,
8,138,1,65,80,12,8,130,98,64,16,20,3,130,160,24,16,4,197,128,32,40,6,4,65,49,32,8,138,1,65,80,12,8,130,98,64,16,20,3,130,160,24,16,4,197,128,32,40,6,4,65,49,32,8,138,1,65,80,12,8,130,98,64,16,20,3,130,
160,24,16,4,197,128,32,40,6,4,65,49,32,8,138,1,65,80,12,8,130,98,64,16,20,3,130,160,24,16,4,197,128,32,40,6,4,65,80,12,8,130,98,64,16,20,3,130,160,24,16,4,197,128,32,40,6,4,65,49,32,8,138,1,65,80,12,8,
130,98,64,16,20,3,130,160,24,16,4,197,128,32,40,6,4,65,49,32,8,138,1,65,80,12,8,130,98,64,16,20,3,130,160,24,16,4,197,128,32,40,6,4,65,49,32,8,138,1,65,80,12,8,130,98,64,16,20,3,130,160,24,16,4,197,128,
32,40,6,4,65,49,32,8,138,1,65,80,12,8,130,98,64,16,20,3,130,160,24,16,4,197,128,32,8,138,1,65,106,80,197,114,231,102,204,152,54,122,244,168,145,35,175,185,84,207,254,208,161,131,166,79,159,150,153,217,
26,150,11,10,78,222,119,223,212,146,146,178,24,252,22,166,76,185,117,207,158,189,247,220,51,53,212,237,197,139,95,131,133,30,61,250,42,37,41,41,73,27,54,124,185,102,205,218,89,179,158,11,223,112,242,228,
73,58,157,14,150,149,205,187,118,237,188,116,233,7,117,119,49,101,202,157,117,203,103,205,250,71,94,222,137,90,229,112,150,158,126,122,214,193,131,185,151,151,103,80,190,131,75,123,40,2,37,148,149,149,
129,73,141,25,51,30,62,62,245,212,244,152,237,106,223,190,125,192,226,149,229,65,131,6,214,90,123,215,93,119,216,108,182,145,35,71,132,74,38,78,28,7,95,223,75,47,205,133,163,3,91,111,219,182,205,194,133,
243,192,136,225,35,188,192,208,21,13,40,31,67,146,80,62,42,175,53,107,190,10,169,66,41,81,206,210,227,143,255,245,242,10,147,224,196,129,79,56,116,40,247,210,22,195,164,73,55,40,195,45,56,132,239,191,
223,113,197,21,221,98,179,159,96,232,30,143,103,212,168,51,182,62,120,240,32,24,161,195,43,64,201,242,229,95,192,194,131,15,222,167,148,116,233,210,25,234,40,6,13,26,216,184,113,83,255,254,253,126,103,
55,148,179,4,186,186,188,196,176,121,243,86,136,142,126,254,121,223,229,19,176,166,166,166,156,56,145,31,179,221,219,188,121,203,176,97,87,193,2,132,58,16,215,129,81,134,7,123,137,137,214,55,223,124,123,
247,238,31,134,14,29,162,20,238,216,177,19,170,125,252,241,7,57,57,146,19,152,59,119,254,192,129,87,253,206,62,192,174,65,117,231,239,44,197,168,24,66,46,242,50,225,246,219,111,29,62,124,216,251,239,127,
24,179,61,252,245,215,195,93,187,118,129,133,9,19,198,193,144,239,116,58,67,171,198,140,185,26,164,2,11,123,247,254,8,14,1,76,22,150,183,111,223,241,240,195,143,150,150,150,78,156,56,97,223,190,61,155,
55,175,131,192,169,225,93,64,122,0,53,67,175,80,121,78,206,115,74,137,146,63,44,88,176,232,114,76,160,47,19,96,100,125,232,161,169,243,230,205,7,3,138,217,78,126,244,209,39,208,73,16,45,140,205,225,110,
1,128,84,1,178,100,48,122,229,35,168,69,73,112,225,112,148,35,130,100,99,193,130,87,102,206,156,1,105,116,3,51,4,144,51,212,155,25,67,206,0,131,163,146,67,190,243,206,123,231,41,123,38,112,106,245,162,
3,65,246,203,47,207,254,240,195,255,130,181,197,120,87,15,30,60,4,145,18,4,63,16,2,133,251,52,72,39,194,178,222,181,144,236,65,121,40,64,82,98,253,156,156,217,32,24,139,197,242,155,247,14,129,214,214,
173,219,64,81,138,231,65,49,92,106,192,104,119,255,253,247,190,244,210,92,8,184,99,191,183,219,182,125,211,183,111,31,136,145,194,61,216,248,241,227,148,212,89,225,227,143,63,181,90,173,16,17,109,223,
254,29,248,10,56,192,154,209,253,105,200,194,127,231,160,62,103,206,60,226,50,156,77,186,76,152,60,121,82,120,76,28,30,40,199,32,155,54,109,1,39,16,30,35,193,32,221,166,77,230,138,21,43,195,188,71,238,
161,67,185,35,71,14,7,121,47,93,250,9,28,160,114,92,122,189,254,217,103,95,104,82,206,16,18,82,8,240,48,224,66,65,144,224,142,206,199,1,146,221,187,247,65,163,68,16,244,12,8,130,98,64,16,20,3,130,160,
24,16,4,197,128,32,40,6,4,65,49,32,8,138,1,65,80,12,8,130,98,64,16,20,3,130,160,24,16,4,197,128,32,40,6,4,65,49,32,8,138,1,65,80,12,8,130,98,64,162,103,248,176,65,131,6,244,142,229,30,118,232,208,110,
252,184,145,40,6,228,252,98,177,196,119,200,106,39,8,98,236,154,20,69,13,255,195,32,75,124,60,138,1,57,191,24,13,122,65,224,221,110,119,204,246,144,166,41,232,97,85,117,53,138,1,57,191,112,92,80,16,4,
130,36,99,182,135,162,40,74,61,196,156,1,185,0,198,6,227,46,88,92,44,119,17,122,40,117,18,197,128,156,87,92,110,15,207,11,30,175,47,102,123,24,12,242,208,67,240,96,45,238,220,226,111,173,198,40,44,203,
154,205,70,70,37,127,65,161,152,72,36,226,227,227,120,129,79,74,178,248,253,126,34,60,86,18,225,159,20,162,4,252,1,155,189,242,156,239,152,166,97,43,70,205,132,74,220,46,79,181,195,217,104,30,156,148,
104,241,7,2,149,149,245,71,255,70,163,94,171,209,168,160,135,100,237,156,1,122,168,102,153,244,180,228,250,253,151,72,148,150,149,131,96,26,238,128,201,100,208,105,181,37,165,229,44,171,142,55,199,85,
85,59,124,62,127,221,10,231,180,123,6,82,246,78,210,144,225,114,53,33,185,194,31,17,139,57,72,146,236,223,175,71,155,204,140,223,182,185,195,225,250,106,253,182,208,199,43,123,118,237,216,161,109,173,
58,121,39,78,253,176,103,95,99,106,84,95,119,237,232,202,42,199,134,141,223,158,35,45,149,170,83,199,118,217,217,109,88,181,250,55,31,227,234,181,155,61,30,111,195,117,6,14,184,50,179,117,250,178,207,
190,4,81,13,25,220,103,231,238,159,10,10,10,149,85,86,107,252,128,254,87,26,244,186,70,119,228,247,7,126,61,156,151,251,235,49,244,12,45,146,17,195,6,38,196,199,193,23,95,84,92,10,33,71,173,181,230,56,
83,151,206,89,5,39,11,11,139,74,235,110,59,104,64,47,161,102,196,101,24,213,53,163,175,2,155,46,41,46,183,87,84,74,35,49,73,128,5,103,181,207,228,131,141,7,244,224,100,160,154,223,123,206,96,156,156,100,
25,52,160,183,74,69,195,114,81,81,153,195,225,12,112,92,173,81,159,164,200,46,157,178,188,94,31,72,174,110,179,173,91,167,25,13,122,49,138,156,39,224,231,148,126,74,113,151,252,82,202,179,219,103,246,
236,209,5,10,143,30,203,135,189,200,206,144,235,220,57,75,171,97,165,48,210,229,182,87,84,65,57,120,54,112,29,41,201,137,221,186,100,183,107,147,177,253,251,189,14,167,11,197,208,146,232,144,221,38,206,
164,223,177,235,127,245,218,186,50,240,119,236,208,166,180,212,86,111,5,48,25,138,58,227,94,38,142,27,238,118,123,55,111,219,1,239,225,117,218,182,73,15,139,40,26,2,90,11,242,103,67,255,212,148,196,129,
253,123,194,182,7,126,57,124,60,239,36,23,140,152,21,116,204,110,3,97,216,161,250,198,99,173,150,213,105,217,104,38,0,120,137,160,44,75,1,22,224,93,57,63,96,220,251,14,228,30,57,154,31,170,217,42,35,69,
205,208,30,143,231,167,125,185,69,197,231,252,228,61,77,81,89,89,153,93,59,103,141,28,62,96,195,166,239,60,30,31,138,161,197,0,134,238,116,186,34,41,65,49,38,176,12,70,173,138,100,190,74,248,49,102,212,
160,170,170,234,45,223,252,80,171,130,193,160,147,135,217,40,166,122,68,169,181,208,164,144,78,171,233,215,167,27,148,124,191,243,231,90,57,73,45,104,154,134,106,36,41,70,88,75,74,150,29,205,148,148,24,
18,3,44,5,43,42,170,227,76,134,206,29,219,238,220,253,115,113,73,121,168,90,74,178,181,87,207,206,160,132,173,223,238,129,160,168,246,9,17,132,195,71,78,120,220,158,94,87,118,25,52,160,231,166,45,187,
112,54,169,197,0,65,78,248,55,93,111,244,2,195,117,164,137,124,88,229,114,123,186,116,106,79,146,84,93,37,40,38,222,192,230,231,86,20,229,121,161,51,98,232,221,171,43,124,220,189,231,64,195,74,80,54,85,
38,148,34,200,85,8,6,249,40,79,133,82,83,148,143,203,98,49,15,232,215,99,223,254,195,225,231,135,36,137,158,221,59,193,218,237,59,254,87,87,9,33,78,21,150,22,21,151,67,136,152,145,158,140,98,104,49,4,
131,16,231,80,13,142,151,96,106,65,49,194,237,24,110,183,199,28,103,104,149,145,188,121,219,174,200,38,14,106,224,163,236,140,98,211,230,56,35,196,54,101,229,246,146,82,91,212,27,242,145,130,31,88,27,
77,152,4,138,13,202,145,152,178,208,181,115,251,147,167,138,243,79,22,133,215,129,200,13,194,167,83,167,75,106,133,130,117,57,244,235,113,104,4,146,7,20,67,139,1,220,189,37,193,212,112,98,43,69,47,98,
36,207,0,214,35,66,232,28,8,112,13,108,46,70,119,133,88,201,91,229,160,60,25,22,142,28,45,136,242,40,164,30,70,16,3,88,118,180,97,146,92,147,80,174,50,242,65,167,203,149,123,56,175,86,157,180,84,43,172,
58,28,150,63,68,2,212,2,168,213,52,138,161,197,144,123,248,4,124,251,29,178,90,55,52,201,195,243,145,172,153,129,60,210,235,43,43,175,140,28,252,72,99,115,84,183,75,72,57,3,175,92,59,75,136,55,129,204,
170,29,174,168,142,65,222,48,146,243,145,77,156,143,38,131,175,169,121,198,159,28,57,122,178,86,5,146,36,141,6,157,226,61,88,86,221,240,75,173,102,156,46,79,195,201,18,38,208,177,133,205,94,125,170,176,
36,53,217,98,52,104,142,229,21,86,59,220,245,229,12,92,100,207,192,73,23,227,26,116,44,80,39,154,4,90,14,168,56,142,11,200,118,25,116,185,188,81,30,130,28,226,115,60,31,140,56,67,21,228,162,185,155,4,
180,0,53,67,61,169,171,46,86,205,40,21,250,245,238,20,117,20,202,161,24,90,18,199,142,23,130,229,181,205,76,237,210,169,141,219,237,43,56,85,18,46,137,154,4,90,140,148,64,55,60,234,139,81,39,208,74,107,
28,199,211,52,5,11,110,79,19,110,0,105,32,129,150,19,128,232,18,232,154,154,144,32,193,2,73,144,117,38,166,228,142,185,189,229,246,234,40,27,20,120,17,197,208,194,40,41,173,40,183,85,165,166,36,164,165,
88,58,102,103,84,86,57,143,229,21,41,163,169,216,96,208,223,64,176,30,26,239,229,9,211,104,115,6,48,31,136,70,66,201,67,115,228,12,242,132,169,24,101,152,20,148,143,88,62,228,58,155,40,199,226,112,186,
139,75,236,205,114,218,49,103,136,81,96,100,61,93,104,219,251,211,145,194,34,155,209,160,237,152,149,17,230,25,26,74,160,131,141,89,109,180,179,73,53,59,146,167,56,131,77,185,103,92,148,187,17,105,54,
73,106,45,154,4,154,175,153,77,82,14,89,172,115,200,224,181,160,92,165,106,54,27,70,49,196,52,16,14,21,22,219,79,20,148,170,213,116,66,188,225,172,24,34,94,103,8,54,114,171,133,188,121,116,57,3,161,204,
129,42,147,185,106,134,110,74,152,20,209,147,200,153,64,116,158,65,153,132,61,43,6,177,142,24,36,209,177,106,21,138,225,50,162,178,202,5,223,187,34,6,65,186,55,129,143,116,157,161,129,105,156,208,112,
11,85,168,40,198,121,169,33,158,87,234,121,125,126,216,66,185,37,41,58,183,198,11,17,114,6,78,190,144,71,70,209,129,51,151,252,196,154,9,180,250,244,227,112,122,64,44,76,83,132,138,98,104,241,120,220,
94,197,20,5,161,161,235,12,141,230,12,178,133,5,89,182,113,235,209,235,216,208,189,73,149,149,46,88,142,143,211,70,57,157,36,229,24,17,52,233,243,249,97,109,195,243,253,10,58,29,163,92,145,136,148,51,
16,210,228,155,3,86,37,89,141,40,134,203,41,133,8,77,186,203,195,100,164,48,67,190,185,141,111,120,54,201,237,246,145,48,154,54,56,204,195,192,157,150,98,10,181,86,89,45,205,208,155,227,180,52,21,85,234,
208,192,149,16,183,27,196,192,199,153,52,13,183,96,73,208,171,164,187,152,248,154,68,185,126,207,224,114,251,253,1,78,167,101,180,26,6,197,112,185,160,86,145,62,95,32,20,76,71,50,74,33,138,11,106,246,
74,55,84,75,178,234,27,168,211,42,53,78,80,148,32,155,32,180,106,179,187,160,4,20,210,168,26,192,118,229,30,214,191,214,231,15,6,2,156,70,77,55,96,190,70,3,107,54,178,92,128,19,106,244,47,68,16,3,80,84,
92,45,117,44,217,200,54,230,109,84,52,149,108,53,160,24,90,12,169,201,70,147,145,173,85,104,208,171,33,139,173,168,242,158,137,185,5,65,163,81,213,29,203,41,138,148,164,208,152,24,60,94,206,227,227,24,
134,74,180,232,234,134,238,16,127,103,164,154,40,154,60,93,236,8,191,86,80,89,237,117,186,253,52,77,166,165,154,88,54,98,206,10,121,54,24,173,159,131,240,6,156,79,109,235,162,100,13,151,150,187,160,159,
201,137,250,122,245,0,78,195,18,175,181,85,122,42,170,189,188,124,44,208,160,116,97,37,130,24,252,129,96,153,221,13,21,224,212,25,245,234,8,142,142,52,25,216,140,52,147,86,219,80,182,77,39,39,167,161,
9,198,14,113,6,181,78,163,130,144,90,249,234,33,84,0,37,196,155,88,24,80,43,171,125,74,206,192,168,72,120,129,37,193,119,12,6,167,97,85,113,70,53,24,144,219,195,25,116,42,48,26,135,43,208,168,30,180,44,
13,67,41,152,8,140,151,96,226,16,53,105,53,82,59,176,47,80,72,113,153,43,192,241,113,6,6,140,204,229,57,115,213,22,218,135,241,158,85,83,6,29,163,133,237,104,10,182,133,14,128,0,96,91,48,68,107,130,86,
175,99,96,239,193,160,0,237,67,53,66,190,103,27,14,7,150,19,19,180,146,78,2,188,124,209,79,128,118,244,90,149,70,218,63,9,255,149,58,214,120,45,108,8,59,130,131,149,206,3,67,85,59,3,176,11,157,134,6,1,
115,193,250,117,30,8,72,201,141,134,61,211,13,229,136,164,190,49,148,84,98,80,91,227,53,176,22,118,91,110,247,4,131,17,7,11,188,232,22,91,20,150,186,226,140,172,81,207,176,102,248,242,68,82,30,77,61,190,
160,173,226,236,221,16,182,74,175,197,172,133,111,23,108,55,60,252,8,242,162,252,59,50,209,92,207,18,139,203,220,102,19,11,182,171,211,170,116,97,227,165,215,7,170,243,131,189,74,126,134,23,106,217,159,
189,202,7,157,1,131,3,51,53,214,25,248,161,190,211,205,41,98,115,168,40,131,158,49,25,206,246,16,250,5,201,243,153,89,32,23,196,74,130,217,168,6,67,103,194,234,128,90,42,170,124,138,252,228,219,168,132,
154,57,131,72,83,6,53,201,131,135,243,5,120,147,60,148,212,58,34,217,157,10,46,55,231,116,55,50,70,224,223,64,35,8,230,12,8,130,98,64,16,20,3,130,160,24,16,4,197,128,32,40,6,4,65,49,32,8,138,1,65,80,12,
8,130,98,64,144,102,5,239,77,186,164,224,56,206,239,247,241,65,142,162,72,26,254,55,223,211,174,4,145,160,68,190,139,40,170,69,225,130,61,134,132,148,94,100,128,32,221,20,89,77,81,78,149,138,163,84,26,
154,97,40,10,197,128,212,143,219,237,226,252,190,54,109,90,247,238,221,171,75,215,46,237,219,181,183,88,173,90,157,182,246,47,85,138,53,207,61,17,107,108,173,22,98,125,133,50,60,65,44,158,59,247,170,255,
44,25,28,151,84,77,71,167,177,186,173,69,110,63,98,11,242,155,159,36,220,4,105,167,136,60,138,220,79,147,123,88,117,53,163,49,51,44,138,1,57,75,69,69,121,90,74,242,29,127,252,243,232,49,163,187,247,232,
113,94,247,149,152,152,84,20,228,42,72,194,17,253,192,30,189,78,234,93,69,158,249,68,137,132,134,16,179,130,98,79,130,184,129,32,11,2,190,157,42,255,42,53,147,175,209,38,48,26,20,195,229,78,117,117,101,
146,53,254,149,121,115,110,185,245,214,11,179,71,175,215,155,32,187,136,223,254,232,66,50,10,157,212,183,138,39,9,14,58,64,146,202,15,36,25,5,225,118,31,49,137,19,214,4,184,127,105,253,4,171,215,210,205,
96,201,152,64,183,60,68,81,44,45,62,61,245,129,123,126,216,187,231,130,41,33,70,144,179,8,194,69,146,71,105,210,33,18,119,248,249,255,58,125,87,184,170,236,92,51,60,241,17,61,67,11,35,16,240,211,36,255,
213,186,181,189,122,247,190,156,207,3,37,39,18,191,146,100,10,47,44,118,11,11,4,231,7,58,33,153,213,161,24,46,23,124,62,79,90,178,245,203,245,235,116,58,221,69,216,125,236,61,136,157,38,136,18,138,116,
137,196,12,79,208,44,186,23,17,98,50,171,71,49,92,14,62,33,144,158,154,180,101,219,86,60,21,181,244,224,38,137,227,20,249,128,47,232,37,60,255,166,104,235,111,77,169,49,103,104,57,225,178,24,216,184,233,
235,139,154,172,196,116,200,148,71,146,143,248,130,195,221,46,15,31,68,49,92,202,20,158,206,95,189,102,141,74,133,158,60,162,29,123,73,194,70,16,79,249,130,26,143,19,197,112,201,226,114,57,254,62,235,
153,172,236,44,60,21,13,155,178,141,34,173,188,248,136,159,43,247,123,80,12,151,38,102,147,238,175,143,63,134,231,33,154,252,33,159,34,199,114,66,95,175,71,16,155,28,213,161,219,141,117,170,171,43,231,
207,155,19,27,89,139,116,171,147,223,86,24,32,88,77,90,154,16,228,164,18,138,242,20,23,48,26,147,224,147,102,250,153,248,120,95,101,105,29,27,85,177,105,173,68,62,72,210,180,183,40,159,38,89,54,85,218,
156,84,49,188,195,225,119,217,53,241,201,148,70,35,242,188,220,32,237,45,206,167,8,149,54,181,149,187,248,132,180,144,214,202,93,4,11,106,77,90,186,32,63,135,138,84,169,120,167,203,239,180,105,18,82,105,
141,38,80,94,238,231,92,208,55,141,209,34,26,141,84,128,187,150,19,158,229,124,241,106,45,138,225,146,34,206,160,187,254,198,27,154,189,89,223,190,253,174,47,86,91,159,157,37,184,221,165,143,79,79,124,
238,239,170,212,148,70,242,103,94,250,69,177,196,59,255,66,30,202,117,29,61,172,210,232,32,165,230,42,43,83,174,187,153,179,219,36,173,80,148,247,68,126,250,196,241,53,217,182,72,200,119,10,6,74,74,29,
187,119,81,172,150,171,180,167,220,116,155,191,184,196,185,255,103,149,70,207,187,29,108,102,43,75,207,137,246,213,107,5,175,143,84,51,208,132,191,188,36,105,210,245,98,144,183,127,255,93,242,117,55,131,
209,87,236,217,157,114,195,45,222,188,19,174,195,185,234,184,4,233,87,136,221,46,117,106,138,117,210,248,234,157,187,221,39,243,117,169,105,173,255,244,36,239,116,22,255,103,137,232,113,23,51,108,95,94,
104,237,247,58,81,12,151,18,28,23,184,238,218,241,205,120,243,105,8,193,225,228,142,29,147,70,89,154,102,59,118,32,89,117,227,219,136,34,12,254,153,111,191,153,112,224,192,247,125,251,24,53,90,222,225,
164,212,234,110,43,150,229,222,241,231,196,91,110,20,3,129,211,139,222,232,252,254,123,181,182,3,59,254,174,125,59,141,46,129,247,186,187,126,186,212,254,213,250,61,227,175,49,106,13,254,106,123,252,136,
145,93,62,250,79,238,93,127,57,249,193,191,141,169,153,129,10,59,197,106,174,88,181,188,98,195,198,188,175,86,13,93,242,142,123,223,129,19,127,24,50,228,173,55,68,142,219,154,150,170,98,117,36,195,4,170,
109,241,35,71,116,254,104,201,174,172,206,98,144,235,245,253,54,182,85,43,41,158,188,106,232,79,147,39,17,150,212,116,146,234,207,241,107,133,160,134,106,130,133,99,206,16,219,169,179,211,49,108,196,136,
243,18,242,168,213,148,217,44,45,104,52,9,211,30,163,19,18,26,223,4,162,26,232,210,219,239,25,174,236,169,161,53,130,199,199,249,170,227,71,143,130,85,165,159,124,76,49,12,109,52,184,114,127,57,49,235,
217,195,143,61,86,189,115,23,152,239,241,39,102,228,205,252,219,137,191,61,171,54,152,57,79,181,161,243,21,80,89,215,33,155,1,101,249,3,32,241,96,85,21,148,180,125,225,89,8,247,5,167,211,235,119,181,121,
250,41,40,113,31,56,4,166,201,149,219,160,2,44,56,255,247,19,184,130,212,177,147,220,149,165,160,94,146,160,196,0,71,8,130,239,68,65,187,39,158,4,37,252,114,211,45,167,230,47,212,119,237,162,214,197,17,
188,224,39,136,174,210,143,109,114,232,25,46,29,52,172,186,71,132,123,81,197,96,144,252,29,51,173,76,235,214,68,83,83,76,81,132,253,149,126,182,162,253,35,83,77,253,7,86,237,248,54,8,81,211,117,215,114,
118,187,43,232,3,37,208,90,141,167,172,228,216,139,207,185,8,130,181,36,235,58,118,56,60,255,101,48,101,53,65,106,211,219,58,93,85,48,114,67,51,218,172,246,198,142,221,221,71,114,149,232,95,58,204,214,
173,50,238,190,247,232,146,119,18,18,211,50,159,153,33,239,74,254,253,109,158,23,229,159,91,13,86,74,79,182,206,126,125,65,105,246,106,222,229,82,58,35,4,2,32,105,240,72,182,85,107,142,124,254,105,220,
231,159,150,46,93,198,38,38,67,16,5,9,68,134,32,106,154,120,193,1,197,16,211,36,37,37,38,37,37,157,99,144,28,231,94,183,193,247,211,207,34,23,16,170,29,250,171,71,25,38,77,128,114,190,220,230,222,178,
213,116,211,13,68,216,223,48,56,150,125,166,27,58,68,149,150,42,125,224,249,242,231,115,130,167,11,9,154,86,37,37,139,66,144,212,74,87,106,33,182,113,126,177,202,112,205,88,202,100,84,140,172,252,249,
23,131,39,79,17,52,69,8,162,97,236,104,227,141,215,215,184,6,48,107,194,177,107,135,40,8,214,201,19,202,119,108,133,225,28,194,149,170,109,146,42,192,111,8,254,0,148,104,173,105,132,173,136,177,36,192,
16,174,87,27,40,173,150,98,89,65,126,158,116,210,148,91,221,7,14,170,18,226,173,215,95,91,53,123,63,84,86,153,76,16,68,129,176,59,190,243,230,225,37,239,180,125,225,57,168,230,57,114,132,77,79,15,237,
84,146,174,37,193,147,123,88,215,185,99,187,105,79,29,157,63,135,13,69,52,32,9,46,0,78,3,142,132,53,39,187,15,28,80,129,187,163,105,159,32,38,136,68,2,207,55,233,138,3,134,73,49,77,74,74,114,173,18,190,
180,212,119,224,23,237,160,129,241,15,78,53,253,241,182,138,5,139,220,27,55,73,99,103,121,185,99,233,50,226,220,135,51,64,73,176,176,80,90,91,86,126,114,212,53,188,221,30,119,247,93,9,143,253,85,59,160,
159,255,215,195,188,77,186,33,90,244,251,161,26,95,45,61,74,89,168,170,62,121,205,36,190,164,36,238,238,59,160,154,126,212,136,138,215,22,219,158,127,177,198,242,36,115,241,113,30,199,142,93,214,73,19,
32,100,50,180,206,86,39,39,217,86,173,165,100,187,108,224,64,120,135,75,107,180,154,135,14,206,127,54,199,177,107,119,202,157,127,172,153,105,162,104,131,254,200,253,15,129,139,232,61,239,213,180,251,
239,57,124,215,61,174,159,246,49,9,241,225,155,67,32,84,252,254,7,197,111,189,219,254,149,217,26,70,7,17,146,242,64,10,72,24,74,151,124,100,234,215,55,243,186,155,157,85,165,42,115,188,52,22,136,34,244,
77,47,138,102,190,105,55,155,163,24,98,26,163,177,246,211,202,84,233,105,214,103,158,210,95,61,18,198,123,237,128,254,113,119,223,233,249,246,59,37,7,128,85,196,185,169,54,148,144,90,233,150,62,219,204,
191,105,250,244,74,89,188,72,55,116,48,219,165,179,97,194,184,212,215,22,82,202,221,126,20,37,85,99,164,103,41,148,205,152,169,206,106,159,242,207,197,224,79,160,154,233,214,155,51,183,111,113,125,185,
206,43,235,45,52,82,219,86,175,129,16,8,130,138,184,33,131,160,164,114,195,198,70,179,111,206,119,38,70,42,255,226,139,202,45,219,116,157,58,106,141,22,249,25,85,162,58,41,169,98,219,215,39,103,207,203,
120,226,241,64,89,89,222,7,239,65,28,37,158,107,199,36,69,49,102,243,161,169,83,97,185,195,194,5,30,41,239,151,30,124,162,201,204,44,120,251,77,174,180,172,235,138,101,169,87,143,117,149,159,86,158,157,
46,146,210,53,7,109,19,195,64,20,67,76,83,207,44,18,121,230,43,243,238,218,237,248,244,115,215,151,95,50,237,218,52,244,5,155,76,124,85,53,188,146,206,189,88,193,21,23,67,56,17,86,205,0,65,87,176,168,
56,121,254,220,90,45,196,63,52,213,249,249,10,121,215,82,119,24,146,181,175,94,7,11,166,214,217,113,87,13,245,23,21,187,203,78,55,242,0,41,146,148,178,139,27,175,15,148,149,87,138,254,146,247,63,132,178,
132,177,99,66,233,45,107,77,203,127,105,54,44,20,189,245,142,95,190,88,113,246,70,40,229,47,63,5,65,211,182,77,21,248,191,229,43,211,30,188,207,72,208,254,194,34,146,34,33,40,226,9,113,79,255,129,144,
52,247,220,184,46,161,119,63,111,89,33,25,10,20,201,24,16,67,78,206,63,246,237,219,147,146,146,212,212,13,55,111,94,55,99,198,180,24,8,78,146,160,255,112,20,161,146,7,31,188,15,74,46,124,15,157,74,178,
120,46,238,13,95,23,223,115,191,123,211,102,222,94,33,6,56,146,162,137,80,148,82,103,18,150,210,105,131,39,242,169,56,83,221,108,56,60,176,161,180,186,64,94,30,109,181,146,108,237,63,44,86,103,103,41,
126,131,144,255,244,153,49,153,157,135,247,7,202,109,25,211,31,55,246,233,85,177,126,131,208,152,213,193,48,15,118,166,237,144,165,50,199,13,89,191,190,219,231,203,36,167,215,167,87,176,166,195,108,171,
12,191,171,242,232,163,211,202,62,93,174,147,235,215,29,15,68,81,132,196,32,247,207,247,194,114,231,69,175,251,242,79,138,4,9,201,134,150,214,59,11,242,118,247,232,5,229,221,62,89,42,64,198,29,144,230,
169,160,87,190,88,16,195,200,145,35,108,54,219,93,119,221,209,66,199,99,232,57,244,31,142,226,162,247,164,164,164,246,213,92,200,16,236,243,94,53,255,233,46,235,172,153,241,83,239,51,93,119,109,80,14,
253,165,108,65,14,163,207,249,118,13,6,193,229,82,181,206,128,81,191,145,137,34,159,143,105,149,33,56,234,169,6,238,66,154,199,36,228,95,200,144,226,49,38,72,136,229,159,175,200,120,248,1,93,167,78,229,
159,127,209,232,83,108,249,106,135,206,146,166,235,208,129,82,171,19,199,140,73,24,123,53,20,198,13,26,160,146,230,196,148,88,73,100,40,237,169,69,11,188,199,143,171,34,207,101,65,48,230,118,216,78,47,
120,61,237,145,169,214,27,38,123,243,11,192,9,4,121,183,193,154,110,63,184,47,111,230,223,33,190,138,235,216,61,88,85,77,139,162,155,34,171,40,250,34,139,225,246,219,111,45,47,183,109,220,184,105,180,
60,3,13,116,237,218,25,134,213,133,11,231,193,59,188,148,145,21,10,63,254,248,3,165,4,134,219,161,67,7,133,59,150,119,223,253,103,248,182,176,22,74,148,202,171,87,47,87,124,206,196,137,227,96,67,40,217,
185,243,27,88,110,198,67,24,60,120,208,242,229,95,40,14,225,226,138,161,172,180,12,100,121,78,78,252,241,178,132,199,30,209,14,30,84,147,152,58,97,236,151,210,131,212,148,224,169,211,130,227,236,244,73,
176,180,204,243,205,118,176,93,218,98,33,89,181,237,133,151,206,153,90,205,72,15,119,35,208,142,228,22,180,90,251,220,249,181,250,80,245,238,191,117,87,143,8,137,1,140,18,76,204,190,106,141,116,83,57,
199,85,109,251,86,205,154,26,73,24,56,87,194,184,49,140,37,225,167,65,195,118,100,180,253,54,49,233,216,99,211,227,134,12,54,168,245,193,202,170,144,91,99,19,211,104,157,174,129,56,31,86,233,180,166,163,
211,167,243,30,79,246,130,121,98,32,0,225,147,218,104,225,42,43,116,4,89,252,222,127,132,0,167,205,106,39,8,126,141,72,84,144,68,5,77,93,100,49,12,27,118,213,247,223,239,88,187,246,43,171,213,26,110,163,
201,201,201,61,122,244,93,186,244,147,41,83,110,5,107,190,247,222,63,235,245,122,40,25,51,102,188,50,24,135,106,110,216,240,117,223,190,125,20,139,159,48,97,92,65,193,201,204,204,214,80,50,101,202,157,
80,89,175,215,61,252,240,84,88,59,115,230,140,3,7,126,129,22,62,252,240,191,57,57,207,129,108,154,165,255,32,188,196,68,235,155,111,190,189,123,247,15,67,135,14,185,184,98,240,250,3,251,247,237,59,39,
104,233,210,217,185,124,165,232,243,11,94,175,103,251,119,85,255,94,194,21,228,251,247,29,128,220,64,59,176,255,169,201,55,6,142,29,19,220,30,200,122,109,179,254,33,56,157,202,160,158,56,251,5,215,202,
213,101,79,63,195,21,156,20,189,62,127,238,175,101,51,255,22,56,122,76,113,41,193,146,18,48,44,185,218,243,174,181,95,217,114,102,75,222,192,231,243,237,217,123,122,242,77,16,38,25,110,190,241,28,33,169,
141,206,61,63,194,130,107,255,1,191,183,10,252,79,195,9,3,47,37,12,55,112,21,21,165,59,191,241,21,158,244,219,202,139,222,126,7,214,88,39,76,128,140,57,188,230,89,125,70,208,4,99,142,247,243,254,99,127,
157,70,105,181,186,236,44,239,241,99,237,230,188,152,250,151,63,85,16,162,121,216,85,148,154,241,159,58,77,81,210,95,187,157,38,73,47,205,92,76,49,128,141,130,213,190,255,254,135,7,15,230,130,17,143,28,
57,60,180,10,100,0,239,32,18,120,135,58,143,61,54,125,210,164,27,228,72,160,12,108,26,132,17,170,185,125,251,14,216,246,250,235,39,43,131,52,72,75,41,7,253,100,103,103,141,28,121,205,172,89,207,141,26,
53,66,167,211,205,153,51,15,202,193,112,97,248,4,217,52,203,33,140,25,115,245,230,205,91,96,97,239,222,31,187,116,233,220,92,26,251,109,232,13,166,109,91,183,133,151,36,60,250,8,211,38,179,108,198,83,
21,115,95,9,22,151,196,63,250,48,87,88,164,76,140,90,158,126,210,48,118,180,61,103,118,233,19,211,33,163,48,63,120,127,210,43,115,148,135,147,51,173,91,183,250,122,157,224,114,219,158,123,161,244,201,
167,28,203,62,83,183,107,107,186,245,102,201,2,25,70,63,250,106,197,160,153,86,173,50,86,44,227,237,118,219,243,47,66,181,202,183,223,213,13,251,67,242,162,87,107,133,239,180,201,232,169,40,246,157,58,
229,62,240,139,148,48,80,164,40,93,10,176,192,75,172,177,100,168,163,138,139,3,165,9,30,175,154,102,173,147,198,87,126,45,157,85,54,57,93,151,152,238,243,86,67,6,156,246,208,3,148,156,141,144,52,29,122,
136,186,212,84,98,162,42,62,94,80,22,204,102,121,193,10,249,134,40,167,19,122,163,229,212,123,111,5,74,74,161,231,126,119,21,19,111,238,248,175,55,6,175,95,223,117,217,71,238,131,185,85,251,247,210,230,
56,200,46,14,73,15,252,108,154,24,154,249,162,155,50,192,111,216,240,165,242,17,134,216,6,210,104,8,135,12,6,195,21,87,116,3,31,114,232,80,110,248,42,16,64,175,94,87,194,32,13,62,225,233,167,103,129,180,
210,211,211,33,238,26,62,124,152,199,227,1,87,80,227,67,190,60,31,9,15,200,108,226,196,9,202,71,208,24,236,253,98,137,65,173,86,175,89,189,230,249,156,23,206,142,158,106,198,250,143,103,130,133,69,144,
233,210,86,11,148,152,239,190,51,180,214,242,228,52,24,227,121,155,77,149,38,63,209,248,202,179,77,209,9,241,41,175,47,20,189,94,190,162,66,21,186,164,37,223,142,17,255,192,189,103,171,37,90,147,23,188,
34,184,221,124,85,21,19,86,45,124,180,6,219,165,8,242,212,203,175,130,65,131,161,67,144,67,209,42,247,193,67,132,40,80,242,79,182,192,187,191,224,164,251,151,131,132,74,37,4,124,134,78,93,3,197,197,165,
31,253,151,129,181,16,17,81,20,196,250,133,111,188,101,153,112,141,202,146,224,61,158,7,41,47,197,156,49,69,216,214,181,111,159,47,47,95,165,44,28,203,147,23,14,64,53,165,113,26,18,33,167,253,232,163,
255,215,110,78,142,46,41,253,240,180,39,216,204,214,201,99,198,112,246,138,95,110,186,133,84,169,53,12,83,33,138,187,25,186,169,191,31,211,204,98,128,129,252,95,255,122,7,134,106,197,75,128,177,194,0,
255,205,55,219,235,214,132,132,1,188,65,94,94,222,194,133,175,95,123,237,196,112,207,0,128,111,129,109,75,74,74,192,69,40,182,56,119,238,124,120,65,155,11,22,188,114,199,29,127,124,227,141,127,130,42,
6,14,188,170,217,19,158,240,102,65,174,160,192,185,117,194,232,11,73,69,181,115,213,202,149,215,78,158,92,235,2,66,196,168,68,173,62,163,132,122,215,106,181,170,90,38,94,111,192,160,215,83,122,125,196,
137,94,81,212,36,166,75,51,164,52,205,90,146,68,66,212,88,82,126,189,231,126,88,3,11,240,174,181,164,156,126,109,241,169,133,175,171,76,144,78,24,131,78,199,158,238,125,120,159,79,107,73,133,202,176,185,
206,154,118,250,181,215,75,150,124,0,113,209,143,253,6,147,42,149,74,154,78,149,239,26,180,164,252,114,227,109,176,24,111,73,57,120,211,20,216,167,180,112,51,44,144,58,185,113,112,14,134,164,86,182,149,
107,42,55,109,1,97,4,10,11,255,55,120,184,161,123,183,64,73,153,191,172,136,77,109,149,18,224,54,171,233,124,86,27,223,196,83,221,156,97,18,100,8,16,208,43,74,80,226,159,173,91,183,69,10,187,147,146,18,
247,239,223,15,193,18,120,102,136,154,234,204,162,148,237,217,179,23,134,103,37,70,130,68,22,178,100,112,20,80,126,252,248,113,72,208,55,109,146,124,46,36,229,202,126,33,141,6,59,254,253,135,48,126,252,
56,37,117,174,81,236,167,181,50,159,11,143,217,156,48,59,231,165,152,152,101,11,143,227,165,71,153,171,96,128,23,73,37,218,167,32,199,128,76,134,148,47,131,192,59,12,246,130,199,35,167,1,52,15,238,200,
237,161,88,86,36,67,217,1,4,246,108,208,225,16,124,62,233,15,33,68,241,108,182,0,219,122,125,162,95,106,10,22,164,121,210,51,11,103,26,39,148,107,106,70,131,180,173,215,203,74,161,84,28,100,47,65,71,181,
38,37,93,197,7,161,214,106,134,50,53,253,103,1,154,83,12,144,33,108,12,187,84,41,207,202,111,133,176,187,222,202,96,115,96,235,96,196,99,199,142,1,205,180,105,147,89,171,194,81,57,189,83,114,12,16,216,
193,131,135,22,47,126,13,234,15,28,56,96,222,188,249,160,138,151,94,154,11,33,150,124,65,224,57,72,72,62,250,232,147,223,217,127,72,15,160,27,43,86,172,12,149,128,83,130,248,45,60,243,185,40,148,218,171,
222,122,243,159,177,53,253,44,8,16,178,75,183,217,201,19,65,34,4,72,58,29,165,211,158,185,193,14,62,66,20,7,121,136,116,53,67,0,203,7,219,133,81,63,116,101,3,42,192,230,180,94,15,45,72,213,64,9,161,139,
30,162,64,235,117,148,86,35,42,11,154,115,22,66,174,9,90,83,54,132,100,131,130,104,50,41,9,188,80,80,16,50,121,113,35,67,239,210,234,232,166,223,247,30,187,15,69,135,56,10,222,111,187,237,78,2,33,136,
162,194,130,189,63,238,201,204,204,188,136,125,152,249,127,211,210,23,188,250,7,107,186,131,34,99,240,20,129,80,18,4,17,178,249,219,245,106,222,152,240,27,90,136,197,219,49,148,107,11,16,71,229,228,204,
70,25,40,164,166,181,158,52,97,34,158,135,6,34,56,86,36,146,9,226,21,86,229,208,25,127,91,35,177,120,11,55,4,39,61,122,244,197,47,248,28,15,78,146,254,128,56,110,236,53,95,173,95,135,103,163,174,79,96,
68,34,75,16,223,212,170,214,235,245,137,77,156,81,141,105,207,128,212,11,203,106,142,30,47,24,59,122,108,144,11,226,217,8,87,130,86,36,178,69,113,137,70,245,186,78,151,216,196,191,123,70,49,180,84,116,
58,125,254,201,194,126,125,250,30,58,120,240,98,184,167,152,59,33,210,181,109,65,108,37,138,11,53,170,151,13,186,20,141,254,247,180,134,98,104,121,254,129,19,168,171,71,141,94,244,218,107,151,185,67,80,
139,68,71,94,244,81,212,227,58,230,61,163,225,247,252,228,48,138,161,165,66,81,148,53,41,109,254,171,139,134,12,26,178,106,229,202,11,154,165,198,64,162,44,221,174,39,138,144,33,36,16,196,103,26,122,138,
129,253,193,104,78,100,180,191,191,113,58,57,57,13,205,171,37,162,209,104,253,129,224,231,159,47,95,185,98,185,199,227,142,51,155,173,86,235,121,221,227,142,111,183,179,219,183,183,211,153,2,242,207,137,
145,242,133,50,146,184,16,47,74,158,44,50,16,98,146,72,88,68,162,138,38,191,102,232,121,58,102,149,222,96,208,26,212,205,244,188,67,252,65,128,22,12,152,164,213,154,228,112,249,95,93,176,120,254,43,11,
58,100,103,245,233,219,187,107,183,110,109,219,182,77,176,88,180,26,45,37,223,66,215,200,99,5,149,181,181,30,121,24,42,36,67,209,57,105,183,219,187,210,52,152,163,58,84,255,130,248,10,216,9,71,74,191,
59,127,146,162,242,41,242,0,77,238,98,24,59,171,137,99,88,75,179,230,49,177,123,209,13,249,13,4,2,126,191,223,39,242,65,21,173,162,104,249,209,183,210,157,14,13,90,45,89,231,41,160,225,133,53,37,60,73,
82,124,176,7,207,107,68,145,187,128,153,180,242,232,91,23,73,86,209,84,53,69,251,85,42,150,102,212,77,252,171,29,244,12,151,35,106,53,11,175,243,215,254,225,139,123,116,242,235,60,38,99,104,64,8,130,98,
64,16,20,3,130,160,24,16,4,197,128,32,40,6,4,65,49,32,8,138,1,65,80,12,8,130,98,64,16,20,3,130,160,24,16,4,197,128,32,40,6,4,65,49,32,8,138,1,65,80,12,8,130,98,64,144,139,202,255,11,48,0,34,165,119,160,
242,29,196,156,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* StructureAudioProcessorEditor::structureuibackground_png = (const char*) resource_StructureAudioProcessorEditor_structureuibackground_png;
const int StructureAudioProcessorEditor::structureuibackground_pngSize = 10134;

// JUCER_RESOURCE: white_pushbutton_44x60_down_png, 1100, "../Graphics/white_pushbutton_44x60_DOWN.png"
static const unsigned char resource_StructureAudioProcessorEditor_white_pushbutton_44x60_down_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,60,8,6,0,0,0,29,82,88,154,0,0,4,19,
73,68,65,84,120,218,237,89,59,75,107,65,16,54,55,254,6,91,155,84,22,90,137,133,133,101,138,32,8,169,98,107,42,95,24,109,2,22,233,197,252,5,177,22,252,23,17,44,44,84,240,253,170,20,193,70,140,138,221,222,
59,7,70,190,251,57,187,39,123,224,114,155,29,24,246,145,125,124,103,102,118,102,118,51,52,148,40,81,162,68,137,18,37,74,148,40,81,162,68,255,156,58,157,78,169,92,46,87,134,135,135,235,179,179,179,205,
173,173,173,150,114,183,219,53,217,250,29,219,131,172,225,91,183,86,171,53,75,165,82,93,48,9,182,31,128,103,102,102,126,77,78,78,46,29,30,30,190,126,126,126,58,225,126,191,239,222,222,222,178,50,143,223,
223,223,7,26,199,99,121,158,180,63,62,62,220,237,237,173,219,217,217,121,173,84,42,75,130,237,7,224,177,177,177,242,241,241,241,190,0,125,121,121,113,55,55,55,238,226,226,194,93,94,94,126,151,90,23,190,
186,186,250,46,165,255,252,252,60,99,30,171,227,180,95,199,224,218,186,134,150,178,247,193,193,129,219,221,221,117,155,155,155,251,130,205,4,252,248,248,216,147,175,195,5,180,126,125,125,157,177,44,38,
37,246,233,56,249,13,231,234,120,108,107,159,182,177,31,1,159,157,157,185,118,187,237,154,205,102,47,8,88,84,162,128,100,162,178,2,82,192,90,50,16,172,251,218,162,110,237,211,186,148,216,150,117,151,151,
151,93,163,209,232,229,74,24,129,90,155,98,31,50,126,148,108,140,82,198,53,20,156,2,213,54,10,67,230,174,172,172,184,249,249,249,222,64,38,129,155,99,93,249,238,238,238,47,201,32,48,46,17,144,2,196,61,
44,105,71,3,150,137,8,74,25,37,105,73,30,251,17,0,155,17,127,40,142,213,125,163,0,179,90,89,109,188,161,197,190,49,104,175,10,30,247,18,192,133,36,108,217,150,246,241,97,99,219,245,217,59,174,153,199,
209,18,14,73,199,178,103,60,48,190,113,40,93,203,91,96,61,90,194,214,161,241,245,179,170,217,237,133,108,222,210,98,20,96,11,156,229,226,208,37,89,106,231,32,193,102,101,125,96,33,192,12,48,36,65,203,
76,24,60,182,89,35,62,155,46,108,18,28,241,44,91,206,3,226,115,125,172,49,244,78,133,1,51,56,244,2,232,228,245,160,249,66,179,21,41,125,26,44,228,135,45,169,221,223,223,123,79,53,127,148,254,38,155,115,
192,64,15,97,73,95,131,199,64,128,37,189,180,108,147,221,145,79,221,152,181,89,246,141,126,220,103,66,90,143,58,116,188,96,200,107,88,7,50,148,60,89,225,222,202,216,162,0,251,108,140,253,47,219,179,229,
73,172,96,193,94,196,242,237,81,128,117,113,140,78,156,70,134,2,2,75,43,20,52,112,47,221,47,42,151,80,87,198,238,198,82,181,30,170,16,112,78,166,124,190,186,80,62,44,135,142,189,132,149,104,227,105,246,
69,67,206,194,124,25,31,107,34,250,208,241,41,15,69,50,203,198,243,210,77,245,179,92,103,59,47,100,195,161,108,13,213,135,23,72,76,194,217,222,67,174,142,239,124,209,110,205,74,192,241,86,192,26,176,110,
22,161,100,159,189,3,219,244,192,54,172,87,120,159,4,124,247,55,235,240,112,157,115,109,28,175,30,162,176,73,232,85,133,253,170,37,241,60,85,251,92,153,2,197,189,10,231,18,86,22,197,161,213,146,178,117,
242,173,80,109,105,11,215,141,190,34,89,183,95,43,202,113,34,207,87,36,95,98,207,38,84,40,210,105,242,227,83,53,130,177,18,34,54,3,223,133,212,231,242,162,174,249,79,79,79,25,96,118,248,124,189,201,243,
189,150,217,224,26,120,184,172,84,83,219,171,171,171,97,192,207,207,207,189,175,175,175,44,239,69,201,73,91,15,134,48,183,217,197,97,14,130,224,56,111,144,117,120,172,244,61,60,60,100,143,129,139,139,
139,97,192,71,71,71,251,127,164,236,78,79,79,179,103,81,5,162,11,41,80,93,84,234,82,226,71,225,56,4,133,115,180,79,218,194,250,155,130,62,57,57,113,219,219,219,110,97,97,193,213,235,117,251,185,85,30,
141,199,199,199,151,228,17,121,111,111,207,117,187,221,236,185,115,125,125,221,109,108,108,100,101,136,101,12,142,27,100,142,197,173,86,75,158,88,51,176,115,115,115,175,35,35,35,246,131,182,254,101,32,
207,244,19,19,19,205,106,181,186,54,61,61,221,154,154,154,250,31,188,54,58,58,26,254,203,32,81,162,68,137,76,250,13,29,194,4,160,40,191,111,191,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* StructureAudioProcessorEditor::white_pushbutton_44x60_down_png = (const char*) resource_StructureAudioProcessorEditor_white_pushbutton_44x60_down_png;
const int StructureAudioProcessorEditor::white_pushbutton_44x60_down_pngSize = 1100;

// JUCER_RESOURCE: white_pushbutton_44x60_up_png, 1462, "../Graphics/white_pushbutton_44x60_UP.png"
static const unsigned char resource_StructureAudioProcessorEditor_white_pushbutton_44x60_up_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,60,8,6,0,0,0,29,82,88,154,0,0,5,125,73,
68,65,84,120,218,237,89,73,76,45,69,20,253,240,222,3,30,200,188,17,48,34,145,40,159,25,69,241,75,8,107,35,134,152,152,56,96,32,249,95,23,63,186,49,138,186,99,227,130,192,91,96,88,18,150,172,16,129,72,
100,122,184,32,65,25,18,32,64,8,243,60,207,32,67,144,225,122,111,231,23,169,46,170,7,26,196,191,232,74,78,170,187,234,118,213,169,91,167,110,85,119,63,120,96,39,59,217,201,78,118,178,147,157,236,100,39,
59,217,201,78,255,121,42,41,41,241,113,56,28,241,78,167,243,163,252,252,252,47,61,30,207,183,229,229,229,223,149,149,149,21,223,55,74,75,75,139,243,242,242,158,34,151,79,145,211,195,216,216,88,39,241,
83,17,206,205,205,245,205,202,202,250,186,191,191,127,31,158,131,116,118,118,6,117,117,117,7,72,182,196,229,114,69,185,221,238,96,34,126,69,56,49,49,209,49,58,58,250,235,243,64,246,242,242,18,38,38,38,
160,186,186,26,138,138,138,58,125,125,125,223,68,79,191,18,16,16,16,170,34,188,190,190,254,167,248,240,249,249,185,50,90,202,25,232,158,47,99,215,23,23,23,170,58,49,151,65,108,231,248,248,24,182,183,183,
97,104,104,8,10,10,10,0,103,125,210,199,199,39,31,73,191,141,18,121,73,147,48,117,78,15,239,237,237,193,238,238,174,210,200,206,206,142,2,217,181,152,235,129,218,19,175,89,31,107,107,107,48,61,61,13,93,
93,93,144,147,147,3,209,209,209,11,72,248,41,226,125,244,114,226,21,97,210,7,26,255,197,8,159,158,158,42,13,172,174,174,194,202,202,138,2,186,102,96,101,60,150,151,151,85,54,116,207,158,227,219,32,82,
172,76,188,159,159,159,7,148,38,120,189,94,200,204,204,132,200,200,200,101,36,91,140,248,24,189,252,150,138,48,62,212,205,8,31,29,29,193,198,198,134,210,233,226,226,34,44,45,45,169,64,229,124,78,54,122,
182,188,61,179,147,217,206,206,206,194,240,240,48,180,182,182,66,70,70,6,132,135,135,175,32,217,31,17,159,33,225,71,186,132,55,55,55,85,157,240,228,88,46,235,148,31,128,217,58,54,8,34,60,50,50,162,16,
78,79,79,231,9,23,32,225,119,53,9,147,126,201,195,140,144,172,3,25,25,51,54,188,183,25,121,194,194,194,2,204,204,204,40,132,91,90,90,110,70,152,151,132,108,106,153,119,69,15,179,142,69,143,106,13,92,38,
9,138,16,150,61,108,198,107,180,88,204,200,65,166,101,153,36,152,134,111,236,97,12,115,215,26,230,61,170,37,19,45,123,35,240,132,111,44,9,242,48,35,44,118,202,79,175,150,39,245,22,167,56,48,222,158,247,
112,90,90,218,205,9,27,121,80,79,151,162,52,248,5,38,27,48,35,76,26,182,180,232,136,176,214,148,234,77,187,72,74,182,224,100,237,210,166,113,43,13,179,40,33,91,28,226,102,193,123,147,39,99,164,97,113,
48,44,14,223,58,172,177,109,214,140,150,101,94,165,123,10,119,90,178,18,119,186,246,246,118,107,97,77,212,155,214,66,19,7,97,180,225,136,139,144,247,48,17,110,107,107,187,155,176,166,53,229,70,158,19,
235,248,193,243,81,196,114,148,144,17,214,139,179,178,8,32,150,203,206,35,124,91,36,153,185,185,57,107,30,62,57,57,81,36,193,142,141,178,233,54,115,142,208,58,193,105,201,140,17,190,211,141,67,60,184,
152,37,44,182,37,43,167,195,143,229,56,204,159,135,101,90,230,35,135,22,17,173,56,44,211,52,217,17,97,75,146,56,60,60,188,38,9,89,167,188,151,245,166,159,127,150,15,143,226,179,150,23,29,211,176,158,238,
196,179,2,59,86,26,189,85,232,133,58,230,225,91,237,116,162,86,153,20,196,5,35,70,15,113,7,52,163,245,59,33,172,21,170,180,22,162,145,78,141,14,240,150,8,83,148,160,119,58,217,246,43,46,48,163,83,156,
172,156,151,13,123,163,38,73,89,126,167,227,55,14,35,210,178,45,86,156,17,51,39,54,38,9,75,175,72,140,176,236,101,81,239,240,35,30,114,140,222,148,249,123,230,97,70,56,53,53,21,194,194,194,204,17,62,56,
56,80,62,110,240,17,128,206,171,4,186,214,2,179,101,16,159,209,107,131,118,185,169,169,41,24,24,24,128,166,166,38,72,74,74,130,224,224,96,99,194,244,157,107,107,107,75,25,237,228,228,164,242,97,142,64,
215,132,241,241,113,85,25,187,22,203,200,78,86,79,164,88,91,124,155,99,99,99,202,130,163,207,84,181,181,181,16,31,31,15,110,183,219,152,240,254,254,190,210,232,224,224,32,244,245,245,41,232,237,237,189,
130,236,190,167,167,71,85,70,96,101,98,46,107,135,234,186,187,187,161,179,179,83,241,110,101,101,37,68,68,68,0,146,228,191,252,168,9,35,193,223,104,135,163,41,233,232,232,128,230,230,102,104,104,104,144,
162,177,177,17,234,235,235,175,114,177,158,202,88,57,203,201,150,175,23,159,33,175,214,212,212,128,199,227,81,190,171,33,45,194,20,146,253,30,241,9,125,193,84,125,189,68,145,255,80,85,85,245,119,69,69,
5,20,22,22,66,118,118,182,34,252,148,148,20,72,78,78,150,130,116,166,119,175,7,178,101,246,148,39,36,36,64,92,92,28,4,5,5,1,18,36,178,255,32,254,192,235,175,16,31,32,225,100,213,47,3,44,200,192,138,111,
162,162,162,126,142,137,137,169,69,193,55,251,251,251,183,35,188,247,1,63,63,63,175,195,225,240,34,15,47,82,250,29,241,11,226,39,228,244,33,150,189,227,116,58,95,86,253,54,8,13,13,13,192,194,24,172,124,
3,141,222,35,161,35,30,35,158,32,190,184,71,60,121,214,239,231,136,60,228,147,137,3,121,21,7,21,118,237,63,7,78,71,144,203,229,122,17,13,94,35,226,52,50,18,59,34,251,30,65,253,61,122,246,171,224,117,116,
98,52,253,46,192,153,119,73,255,38,209,2,36,111,7,6,6,190,64,163,66,132,255,15,8,163,31,49,33,33,33,110,34,74,206,180,255,245,217,73,146,254,5,167,22,80,135,99,220,211,169,0,0,0,0,73,69,78,68,174,66,96,
130,0,0};

const char* StructureAudioProcessorEditor::white_pushbutton_44x60_up_png = (const char*) resource_StructureAudioProcessorEditor_white_pushbutton_44x60_up_png;
const int StructureAudioProcessorEditor::white_pushbutton_44x60_up_pngSize = 1462;

// JUCER_RESOURCE: white_pushbutton_greenLed_png, 1738, "../Graphics/white_pushbutton_greenLED.png"
static const unsigned char resource_StructureAudioProcessorEditor_white_pushbutton_greenLed_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,60,8,6,0,0,0,29,82,88,154,0,0,6,145,73,
68,65,84,120,218,237,89,91,76,84,71,24,22,118,151,221,133,46,215,196,10,107,189,117,91,145,171,88,170,34,34,173,109,140,22,8,154,152,212,150,70,26,47,177,70,31,122,17,109,250,32,105,177,13,17,30,104,124,
84,251,210,210,54,161,20,72,105,65,118,233,3,45,45,106,162,70,9,145,155,32,10,222,65,40,106,40,232,223,255,63,113,232,236,48,231,156,101,53,116,211,236,36,95,206,57,51,255,153,249,230,159,111,254,153,
115,102,214,44,127,242,39,127,242,39,127,250,223,36,139,197,18,102,182,25,14,134,219,131,93,4,179,205,116,144,242,124,146,172,209,104,124,110,78,108,104,223,170,119,23,193,198,207,146,97,83,81,50,100,
108,115,64,244,146,176,94,42,243,57,194,179,95,8,113,174,63,176,4,222,175,127,5,62,109,205,130,162,182,28,216,231,122,29,178,63,73,132,232,216,80,167,175,121,55,38,110,221,179,176,243,251,149,112,168,
35,11,190,232,206,129,226,158,92,196,70,216,83,153,9,73,111,216,129,108,124,134,112,80,112,224,234,101,155,231,194,222,159,87,67,81,199,6,248,188,235,95,210,31,58,95,131,229,91,22,0,217,248,12,97,179,
217,28,238,200,140,154,200,255,42,21,10,91,215,77,146,46,106,207,130,237,95,167,193,226,181,179,39,200,198,167,100,17,49,207,114,44,125,199,2,216,246,205,114,40,248,237,85,216,255,251,90,216,249,93,26,
172,217,229,128,200,121,193,199,124,110,210,133,96,10,179,91,26,73,203,107,118,45,130,53,239,45,130,248,245,115,32,194,110,113,82,153,79,134,182,194,194,194,128,0,83,64,150,197,102,248,22,81,78,247,148,
231,95,161,152,119,12,6,131,3,195,207,230,220,220,220,157,165,165,165,31,149,148,148,236,59,124,248,112,193,76,163,184,184,184,32,59,59,123,55,114,121,11,57,45,153,63,127,190,113,202,72,101,102,102,6,
174,88,177,98,239,153,51,103,134,193,7,210,248,248,56,84,86,86,142,32,217,66,147,201,20,109,181,90,109,68,124,146,112,92,92,156,161,173,173,237,71,95,32,251,232,209,35,232,232,232,128,227,199,143,67,126,
126,126,83,96,96,224,75,232,233,5,110,251,18,34,124,227,198,141,63,196,151,39,38,38,148,222,210,149,129,158,249,60,118,255,240,225,67,183,50,241,42,131,88,207,253,251,247,225,206,157,59,112,254,252,121,
200,203,203,3,28,245,206,128,128,128,92,36,189,28,37,50,87,149,48,53,78,47,223,189,123,23,134,134,134,148,74,6,7,7,21,200,238,197,171,22,168,62,241,158,181,113,253,250,117,232,238,238,134,230,230,102,
200,200,200,128,152,152,152,62,36,188,27,145,133,94,142,155,36,76,250,64,227,63,25,225,177,177,49,165,130,107,215,174,193,192,192,128,2,186,103,96,121,60,250,251,251,221,108,232,153,189,199,215,65,164,
88,158,248,124,249,242,101,64,105,130,203,229,130,212,212,84,136,138,138,234,71,178,5,136,55,209,203,47,187,17,198,151,90,24,225,123,247,238,193,205,155,55,149,70,175,92,185,2,87,175,94,117,3,229,243,
87,178,209,178,229,237,153,157,204,182,167,167,7,46,92,184,0,39,78,156,128,148,148,20,136,136,136,24,64,178,31,35,222,70,194,105,154,132,111,221,186,229,214,8,79,142,93,101,141,242,29,240,180,140,117,
130,8,183,182,182,42,132,151,46,93,202,19,206,67,194,171,84,9,147,126,201,195,140,144,172,1,25,25,79,108,120,111,51,242,132,190,190,62,184,116,233,146,66,184,190,190,126,122,132,121,73,200,134,150,121,
87,244,48,107,88,244,168,90,199,101,146,160,8,225,181,135,61,241,26,77,22,79,228,32,211,178,76,18,76,195,211,246,48,134,185,41,21,243,30,85,147,137,154,189,30,120,194,211,150,4,121,152,17,22,27,229,135,
87,205,147,90,147,83,236,24,111,207,123,56,57,57,121,250,132,245,60,168,165,75,81,26,252,4,147,117,152,17,38,13,123,53,233,136,176,218,144,106,13,187,72,74,54,225,100,245,210,162,241,68,26,102,81,66,54,
57,196,197,130,247,38,79,70,79,195,98,103,88,28,126,226,176,198,150,89,79,180,44,243,42,61,83,184,83,147,149,184,210,57,157,78,239,194,154,168,55,181,137,38,118,66,111,193,17,39,33,239,97,34,220,208,208,
240,116,194,154,218,144,235,121,78,44,227,59,207,71,17,175,163,132,140,176,86,156,149,69,0,49,95,182,31,225,235,34,201,244,246,246,122,231,225,7,15,30,40,146,96,219,70,217,112,123,178,143,80,219,193,169,
201,140,17,126,170,11,135,184,113,241,148,176,88,151,44,159,54,63,94,199,97,126,63,44,211,50,31,57,212,136,168,197,97,153,166,201,142,8,123,37,137,209,209,209,41,146,144,53,202,123,89,107,248,249,119,
249,240,40,190,235,245,164,99,26,214,210,157,184,87,96,219,74,189,175,10,173,80,199,60,252,68,43,157,168,85,38,5,113,194,136,209,67,92,1,61,209,250,83,33,172,22,170,212,38,162,158,78,245,54,240,94,17,
166,40,65,223,116,178,229,87,156,96,122,187,56,89,62,47,27,246,69,77,146,242,250,155,142,95,56,244,72,203,150,88,113,68,60,217,177,49,73,120,245,137,196,8,203,62,22,181,54,63,226,38,71,239,75,153,127,
102,30,102,132,147,146,146,32,60,60,220,51,194,35,35,35,202,207,13,62,2,208,126,149,64,247,106,96,182,12,226,59,90,117,208,42,215,213,213,5,103,207,158,133,218,218,90,136,143,143,7,155,205,166,79,152,
254,115,221,190,125,91,233,109,103,103,167,242,99,142,64,247,132,246,246,118,183,60,118,47,230,145,157,172,156,72,177,186,248,58,47,94,188,168,76,56,250,77,85,81,81,1,14,135,3,172,86,171,62,225,225,225,
97,165,210,115,231,206,193,233,211,167,21,156,58,117,106,18,178,231,147,39,79,186,229,17,88,158,120,149,213,67,101,45,45,45,208,212,212,164,120,247,200,145,35,16,25,25,9,72,146,255,243,227,78,24,9,254,
68,43,28,13,73,99,99,35,212,213,213,65,117,117,181,20,53,53,53,80,85,85,53,121,21,203,41,143,229,179,43,217,242,229,226,59,228,213,242,242,114,40,45,45,85,254,171,33,45,66,23,146,221,143,216,66,127,48,
221,254,94,162,200,15,28,61,122,244,175,178,178,50,216,186,117,43,164,167,167,43,194,79,76,76,132,132,132,4,41,72,103,90,207,90,32,91,102,79,215,216,216,88,88,184,112,33,132,132,132,0,18,36,178,127,35,
126,197,251,61,136,28,36,156,224,118,100,128,25,41,88,240,65,116,116,244,151,118,187,189,2,5,95,103,54,155,157,8,215,76,32,40,40,200,101,48,24,92,200,195,133,148,126,65,252,128,56,132,156,54,97,222,74,
163,209,56,207,237,216,32,44,44,204,130,153,118,44,92,134,70,27,72,232,136,109,136,237,136,29,51,136,237,143,219,125,7,145,141,124,82,177,35,207,79,57,156,164,115,14,58,83,51,153,76,115,208,224,69,34,
78,61,35,177,35,210,103,16,212,94,218,227,163,130,197,116,78,77,199,5,56,242,38,233,105,18,77,64,242,118,112,112,240,51,212,43,68,196,127,128,112,58,136,9,13,13,181,18,81,114,166,255,172,207,159,36,233,
31,90,52,195,2,219,228,147,18,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* StructureAudioProcessorEditor::white_pushbutton_greenLed_png = (const char*) resource_StructureAudioProcessorEditor_white_pushbutton_greenLed_png;
const int StructureAudioProcessorEditor::white_pushbutton_greenLed_pngSize = 1738;

// JUCER_RESOURCE: white_pushbutton_orangeLed_png, 1742, "../Graphics/white_pushbutton_orangeLED.png"
static const unsigned char resource_StructureAudioProcessorEditor_white_pushbutton_orangeLed_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,60,8,6,0,0,0,29,82,88,154,0,0,6,149,
73,68,65,84,120,218,237,89,93,76,84,71,20,118,217,93,150,5,97,249,73,81,192,34,91,137,34,44,2,22,4,75,141,15,77,218,24,168,84,219,164,63,180,146,150,246,65,107,210,84,107,219,39,73,90,99,141,238,3,198,
38,109,130,60,210,164,161,8,180,180,8,187,180,9,137,45,74,130,68,141,1,65,229,95,69,20,65,192,88,209,211,115,110,29,50,59,204,189,119,89,13,221,52,59,201,151,123,239,204,185,51,223,156,249,230,204,220,
59,75,150,4,82,32,5,82,32,5,210,255,38,133,132,132,216,194,195,140,251,19,99,45,110,130,13,239,41,207,47,201,154,76,166,103,211,146,66,6,118,109,93,14,229,59,237,112,116,151,29,118,23,197,131,35,41,180,
143,202,252,142,240,218,68,139,235,235,146,21,208,254,173,3,70,171,115,96,172,102,3,116,126,159,9,223,148,38,65,106,82,168,203,223,188,27,191,53,207,6,205,7,87,195,196,137,108,152,250,57,7,166,27,114,
97,166,33,15,254,112,58,96,91,126,12,144,141,223,16,142,8,13,122,241,189,151,162,161,173,60,5,9,175,135,187,117,72,186,254,95,210,29,223,101,192,251,175,196,2,217,248,13,97,139,197,18,249,242,250,165,
179,181,251,159,131,209,31,51,230,72,143,163,183,27,14,164,192,150,28,219,44,217,248,149,44,236,203,204,199,63,41,122,6,126,253,106,21,116,85,164,65,119,101,58,52,29,92,3,123,94,95,14,246,56,203,113,191,
155,116,97,152,18,99,77,45,91,243,34,96,207,246,88,216,187,125,25,188,182,49,18,18,99,131,93,84,230,151,161,173,172,172,204,96,54,24,10,34,172,65,63,160,102,171,204,102,67,1,229,5,86,40,230,29,163,209,
152,140,225,231,141,162,162,162,143,156,78,231,222,35,71,142,124,118,248,240,225,125,139,141,67,135,14,237,43,44,44,220,137,92,222,70,78,107,87,174,92,105,154,55,82,155,55,111,14,202,205,205,221,221,209,
209,49,1,126,144,30,60,120,0,53,53,53,147,72,182,204,108,54,199,89,173,214,112,34,62,71,56,53,53,213,120,241,226,197,19,254,64,246,209,163,71,112,233,210,37,168,172,172,132,146,146,146,214,160,160,160,
231,209,211,73,30,251,18,34,124,227,198,141,63,197,151,103,103,103,149,222,210,149,129,158,249,60,118,255,240,225,67,143,50,241,42,131,88,207,204,204,12,220,186,117,11,206,157,59,7,197,197,197,128,163,
222,99,48,24,138,144,244,6,148,200,10,85,194,212,56,189,124,231,206,29,24,31,31,87,42,185,125,251,182,2,217,189,120,213,2,213,39,222,179,54,174,95,191,14,151,47,95,134,83,167,78,193,166,77,155,32,62,62,
126,0,9,239,68,20,160,151,83,231,8,147,62,208,248,47,70,248,254,253,251,74,5,215,174,93,131,145,145,17,5,116,207,192,242,120,12,15,15,123,216,208,51,123,143,175,131,72,177,60,241,185,191,191,31,80,154,
224,118,187,33,59,59,27,98,98,98,134,145,236,62,196,155,232,229,28,15,194,248,82,27,35,60,61,61,13,163,163,163,74,163,131,131,131,48,52,52,228,1,202,231,175,100,163,101,203,219,51,59,153,237,213,171,87,
225,252,249,243,208,212,212,4,89,89,89,16,21,21,53,130,100,191,68,188,131,132,55,106,18,190,121,243,166,71,35,60,57,118,149,53,202,119,192,219,50,214,9,34,124,225,194,5,133,112,102,102,38,79,184,24,9,
191,160,74,152,244,75,30,102,132,100,13,200,200,120,99,195,123,155,145,39,12,12,12,192,149,43,87,20,194,39,79,158,92,24,97,94,18,178,161,101,222,21,61,204,26,22,61,170,214,113,153,36,40,66,248,236,97,
111,188,70,147,197,27,57,200,180,44,147,4,211,240,130,61,140,97,110,94,197,188,71,213,100,162,102,175,7,158,240,130,37,65,30,102,132,197,70,249,225,85,243,164,214,228,20,59,198,219,243,30,206,200,200,
88,56,97,61,15,106,233,82,148,6,63,193,100,29,102,132,73,195,62,77,58,34,172,54,164,90,195,46,146,146,77,56,89,189,180,104,60,145,134,89,148,144,77,14,113,177,224,189,201,147,209,211,176,216,25,22,135,
159,56,172,177,101,214,27,45,203,188,74,207,20,238,212,100,37,174,116,46,151,203,183,176,38,234,77,109,162,137,157,208,91,112,196,73,200,123,152,8,55,55,55,63,157,176,166,54,228,122,158,19,203,248,206,
243,81,196,231,40,33,35,172,21,103,101,17,64,204,151,237,71,248,186,72,50,125,125,125,190,121,248,222,189,123,138,36,216,182,81,54,220,222,236,35,212,118,112,106,50,99,132,159,234,194,33,110,92,188,37,
44,214,37,203,167,205,143,207,113,152,223,15,203,180,204,71,14,53,34,106,113,88,166,105,178,35,194,62,73,98,106,106,106,158,36,100,141,242,94,214,26,126,254,93,62,60,138,239,250,60,233,152,134,181,116,
39,238,21,216,182,82,239,171,66,43,212,49,15,63,209,74,39,106,149,73,65,156,48,98,244,16,87,64,111,180,254,84,8,171,133,42,181,137,168,167,83,189,13,188,79,132,41,74,208,55,157,108,249,21,39,152,222,46,
78,150,207,203,134,125,81,147,164,124,254,166,227,23,14,61,210,178,37,86,28,17,111,118,108,76,18,62,125,34,49,194,178,143,69,173,205,143,184,201,209,251,82,230,159,153,135,25,225,117,235,214,65,100,100,
164,119,132,39,39,39,149,159,27,124,4,160,253,42,129,238,213,192,108,25,196,119,180,234,160,85,174,183,183,23,206,158,61,11,13,13,13,144,150,150,6,225,225,225,250,132,233,63,215,216,216,152,210,219,158,
158,30,229,199,28,129,238,9,221,221,221,30,121,236,94,204,35,59,89,57,145,98,117,241,117,118,117,117,41,19,142,126,83,85,87,87,67,114,114,50,88,173,86,125,194,19,19,19,74,165,157,157,157,208,222,222,174,
224,204,153,51,115,144,61,159,62,125,218,35,143,192,242,196,171,172,30,42,107,107,107,131,214,214,86,197,187,199,142,29,131,232,232,104,64,146,252,159,31,79,194,72,240,23,90,225,104,72,90,90,90,160,177,
177,17,234,234,234,164,168,175,175,135,218,218,218,185,171,88,78,121,44,159,93,201,150,47,23,223,33,175,86,85,85,129,211,233,84,254,171,33,45,66,47,146,253,28,241,22,253,193,244,248,123,137,34,255,162,
162,162,226,110,121,121,57,236,216,177,3,242,243,243,21,225,167,167,167,131,195,225,144,130,116,166,245,172,5,178,101,246,116,77,73,73,1,187,221,14,97,97,97,128,4,137,236,223,136,223,241,254,99,196,171,
72,216,225,113,100,128,25,89,88,240,105,92,92,220,209,132,132,132,106,20,124,163,197,98,113,33,220,139,129,224,224,96,183,209,104,116,35,15,55,82,250,13,241,19,226,0,114,218,134,121,121,38,147,41,209,
227,216,192,102,179,133,96,102,2,22,174,71,163,45,36,116,196,7,136,82,196,135,139,136,210,199,237,190,139,40,68,62,217,216,145,85,243,14,39,233,156,131,206,212,204,102,243,114,52,88,77,196,169,103,36,
118,68,254,34,130,218,219,248,248,168,96,13,157,83,211,113,1,142,188,89,122,154,68,19,144,188,29,26,26,186,148,122,133,136,250,15,16,73,7,49,17,17,17,86,34,74,206,12,156,245,5,146,36,253,3,171,106,200,
139,247,115,204,149,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* StructureAudioProcessorEditor::white_pushbutton_orangeLed_png = (const char*) resource_StructureAudioProcessorEditor_white_pushbutton_orangeLed_png;
const int StructureAudioProcessorEditor::white_pushbutton_orangeLed_pngSize = 1742;

// JUCER_RESOURCE: white_pushbutton_orangeLed_down_png, 1420, "../Graphics/white_pushbutton_orangeLED_DOWN.png"
static const unsigned char resource_StructureAudioProcessorEditor_white_pushbutton_orangeLed_down_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,60,8,6,0,0,0,29,82,88,154,0,0,5,
83,73,68,65,84,120,218,237,89,95,72,100,101,20,223,113,180,49,183,116,41,154,221,150,242,79,73,109,174,57,177,52,105,24,248,16,36,49,232,218,206,147,66,68,56,47,141,127,218,25,95,4,97,133,138,13,196,129,
13,130,130,54,241,165,32,195,254,97,15,101,209,139,130,144,132,10,254,255,23,129,34,107,144,249,15,31,22,78,115,110,28,57,157,206,119,103,238,125,105,136,251,193,225,251,115,207,253,190,223,61,231,124,
231,156,239,187,103,206,120,197,43,94,241,138,87,254,55,165,176,176,176,228,254,179,254,27,165,193,192,15,72,37,233,54,142,229,36,216,252,252,252,71,47,151,23,254,22,111,190,0,183,222,168,128,247,226,
21,208,121,245,34,84,151,23,253,138,207,114,14,240,83,165,129,241,183,95,123,4,126,126,191,26,238,124,30,134,223,71,159,131,153,15,159,129,119,219,203,161,170,188,104,60,215,164,123,177,185,174,4,190,
191,249,4,252,249,197,179,112,248,77,24,142,198,106,225,120,172,14,126,26,172,134,87,234,31,4,228,201,25,192,197,69,121,47,188,250,226,3,48,117,235,82,26,240,21,56,248,42,13,250,235,191,65,255,242,65,
8,94,111,12,2,242,228,12,224,64,32,112,238,165,43,247,221,253,242,198,99,112,231,179,208,41,232,63,210,210,30,123,231,18,188,28,46,185,139,60,57,101,22,21,231,11,110,191,121,245,33,248,246,173,199,97,
233,163,203,176,252,241,211,240,221,205,39,33,25,189,0,21,15,7,110,231,220,166,59,155,46,165,193,252,31,155,235,138,33,121,45,8,61,215,206,67,203,243,231,160,52,120,207,56,62,203,73,215,214,223,223,239,
43,240,249,34,197,247,230,125,154,182,217,79,10,10,124,17,28,243,34,20,73,199,239,247,87,166,221,79,180,169,169,41,54,48,48,144,32,74,165,82,42,105,207,121,63,155,57,76,243,70,34,145,152,207,231,139,34,
38,85,75,13,13,13,121,225,112,184,99,106,106,106,239,248,248,24,144,14,14,14,96,127,127,223,170,51,209,225,225,97,86,124,146,87,190,135,253,163,163,35,88,91,91,131,161,161,161,189,202,202,202,14,196,246,
47,192,85,85,85,254,153,153,153,81,4,186,187,187,11,171,171,171,176,184,184,8,75,75,75,167,53,181,145,150,151,151,79,107,28,95,88,88,176,72,242,18,31,141,19,15,159,155,230,160,26,215,158,156,156,132,225,
225,97,232,235,235,27,69,108,42,224,173,173,173,9,252,58,62,1,181,87,86,86,44,194,201,176,230,99,196,135,207,248,187,196,207,251,52,70,125,62,206,1,207,207,207,67,111,111,47,196,98,177,9,91,192,168,18,
2,132,47,18,17,32,2,76,181,4,194,219,166,62,170,155,198,168,141,53,239,227,188,157,157,157,208,218,218,58,145,81,194,28,168,182,40,31,227,196,63,10,23,230,82,230,115,16,56,2,74,125,46,12,124,183,171,171,
11,218,218,218,38,178,50,9,190,56,111,19,173,175,175,255,67,50,28,152,172,57,32,2,200,215,208,164,237,24,48,190,200,65,17,113,73,106,146,231,227,28,128,52,35,249,161,156,151,214,117,4,88,170,85,170,77,
46,168,145,137,135,219,43,129,231,107,33,96,87,18,214,108,139,198,228,102,147,182,107,178,119,62,103,38,114,44,97,59,233,104,246,204,55,140,137,143,75,87,243,22,188,237,88,194,218,166,49,141,75,85,75,
183,103,103,243,154,22,29,1,214,192,105,46,142,187,36,77,237,50,72,72,179,210,62,208,21,96,9,208,78,130,154,153,72,240,188,47,53,98,178,105,215,38,33,35,158,102,203,153,128,152,92,159,212,24,247,78,174,
1,75,112,220,11,112,39,79,27,205,20,154,181,72,105,210,160,43,63,172,73,109,99,99,195,184,171,229,71,209,51,92,92,6,12,238,33,52,233,83,240,200,10,48,166,151,154,109,74,119,100,82,55,207,218,52,251,230,
126,220,100,66,212,118,180,233,228,132,118,94,67,219,144,118,201,147,22,238,181,140,205,17,96,147,141,73,255,43,237,89,243,36,90,176,144,94,68,243,237,142,0,211,228,60,58,201,52,210,46,32,72,105,217,5,
13,190,22,173,231,40,151,32,87,38,221,141,166,106,218,84,118,192,101,50,101,242,213,174,242,97,220,116,210,75,104,137,54,223,205,166,104,40,179,48,83,198,39,53,225,120,211,201,93,110,23,201,52,27,207,
148,110,146,159,149,109,105,231,174,108,216,46,91,227,234,227,7,72,158,132,75,123,183,115,117,242,204,231,216,173,105,9,56,63,21,72,13,104,39,11,187,100,95,122,7,105,211,89,219,48,29,225,77,18,48,157,
223,180,205,35,219,50,215,230,252,228,33,92,155,4,29,85,164,95,213,36,158,73,213,38,87,70,64,249,90,174,115,9,45,139,146,161,85,147,178,182,243,181,80,173,105,139,207,235,248,136,164,157,126,181,40,39,
19,121,121,68,50,37,246,210,132,92,69,58,74,126,76,170,230,96,180,132,72,154,129,233,64,106,114,121,142,142,249,219,219,219,22,96,233,240,229,241,38,147,239,213,204,134,207,193,55,151,150,106,82,191,187,
187,219,30,240,206,206,206,196,201,201,137,149,247,114,201,97,159,54,6,146,236,75,23,199,115,16,14,78,230,13,56,143,228,197,177,205,205,77,235,50,48,30,143,219,3,158,158,158,30,77,75,25,230,230,230,172,
107,81,2,66,19,17,80,154,20,219,88,243,143,226,124,28,20,127,135,198,176,143,68,207,8,244,236,236,44,12,14,14,66,123,123,59,68,163,81,253,186,21,47,141,107,106,106,58,240,18,121,100,100,4,82,169,148,117,
221,153,76,38,161,167,167,199,170,237,8,121,56,95,54,239,104,148,72,36,240,138,213,2,219,210,210,178,23,12,6,245,11,109,250,101,128,215,244,161,80,40,214,216,216,120,189,190,190,62,81,91,91,251,95,208,
245,178,178,50,251,95,6,94,241,138,87,188,162,150,191,0,34,22,124,164,176,254,14,186,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* StructureAudioProcessorEditor::white_pushbutton_orangeLed_down_png = (const char*) resource_StructureAudioProcessorEditor_white_pushbutton_orangeLed_down_png;
const int StructureAudioProcessorEditor::white_pushbutton_orangeLed_down_pngSize = 1420;

// JUCER_RESOURCE: white_pushbutton_redled_36x36_down_png, 2644, "../Graphics/white_pushbutton_REDLED_36x36_DOWN.png"
static const unsigned char resource_StructureAudioProcessorEditor_white_pushbutton_redled_36x36_down_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,50,8,6,0,0,0,39,88,57,234,0,
0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,65,100,111,98,101,32,73,109,97,103,101,82,101,97,100,121,113,201,101,60,0,0,3,35,105,84,88,116,88,77,76,58,99,111,109,46,97,100,111,98,101,46,120,109,
112,0,0,0,0,0,60,63,120,112,97,99,107,101,116,32,98,101,103,105,110,61,34,239,187,191,34,32,105,100,61,34,87,53,77,48,77,112,67,101,104,105,72,122,114,101,83,122,78,84,99,122,107,99,57,100,34,63,62,32,
60,120,58,120,109,112,109,101,116,97,32,120,109,108,110,115,58,120,61,34,97,100,111,98,101,58,110,115,58,109,101,116,97,47,34,32,120,58,120,109,112,116,107,61,34,65,100,111,98,101,32,88,77,80,32,67,111,
114,101,32,53,46,53,45,99,48,49,52,32,55,57,46,49,53,49,52,56,49,44,32,50,48,49,51,47,48,51,47,49,51,45,49,50,58,48,57,58,49,53,32,32,32,32,32,32,32,32,34,62,32,60,114,100,102,58,82,68,70,32,120,109,108,
110,115,58,114,100,102,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,49,57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,97,120,45,110,115,35,34,62,32,60,114,100,102,
58,68,101,115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,32,120,109,108,110,115,58,120,109,112,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,
47,120,97,112,47,49,46,48,47,34,32,120,109,108,110,115,58,120,109,112,77,77,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,109,109,47,34,32,120,
109,108,110,115,58,115,116,82,101,102,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,115,84,121,112,101,47,82,101,115,111,117,114,99,101,82,101,
102,35,34,32,120,109,112,58,67,114,101,97,116,111,114,84,111,111,108,61,34,65,100,111,98,101,32,80,104,111,116,111,115,104,111,112,32,67,67,32,40,77,97,99,105,110,116,111,115,104,41,34,32,120,109,112,
77,77,58,73,110,115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,66,67,69,50,54,56,54,49,55,50,66,48,49,49,69,54,66,53,51,55,66,51,67,55,54,55,51,68,57,67,49,53,34,32,120,109,112,77,77,
58,68,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,66,67,69,50,54,56,54,50,55,50,66,48,49,49,69,54,66,53,51,55,66,51,67,55,54,55,51,68,57,67,49,53,34,62,32,60,120,109,112,77,77,
58,68,101,114,105,118,101,100,70,114,111,109,32,115,116,82,101,102,58,105,110,115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,57,54,69,67,68,56,53,67,55,50,66,48,49,49,69,54,66,53,51,55,
66,51,67,55,54,55,51,68,57,67,49,53,34,32,115,116,82,101,102,58,100,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,66,67,69,50,54,56,54,48,55,50,66,48,49,49,69,54,66,53,51,55,66,
51,67,55,54,55,51,68,57,67,49,53,34,47,62,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,32,60,47,114,100,102,58,82,68,70,62,32,60,47,120,58,120,109,112,109,101,116,97,62,32,60,63,
120,112,97,99,107,101,116,32,101,110,100,61,34,114,34,63,62,56,2,113,171,0,0,6,199,73,68,65,84,120,218,212,89,205,79,92,85,20,191,239,205,27,30,159,101,134,70,154,24,62,34,42,197,93,151,38,141,134,40,
70,226,191,80,163,40,139,46,26,233,134,133,177,13,29,190,92,33,137,43,119,205,108,112,97,194,194,69,221,80,147,198,196,85,91,226,194,8,1,52,38,36,76,129,20,6,152,143,204,23,207,115,38,115,232,233,225,
188,249,130,148,248,146,155,247,49,239,222,251,187,191,115,206,239,156,119,199,242,60,207,252,159,14,135,46,34,145,136,153,153,153,49,142,227,152,209,209,81,211,211,211,99,112,49,180,160,137,137,137,202,
131,57,78,187,155,203,221,14,5,2,239,227,125,188,80,248,45,19,12,126,159,207,231,15,42,245,157,154,154,122,233,126,99,99,195,44,44,44,24,232,107,186,186,186,204,200,200,136,137,70,163,47,0,159,195,209,
221,111,204,239,131,161,80,247,213,198,70,227,89,150,89,203,102,63,124,116,120,248,229,95,198,188,7,191,111,158,199,36,118,181,47,74,6,228,49,96,219,247,63,189,116,169,251,102,56,108,62,11,133,204,231,
112,190,217,209,97,110,92,190,220,251,78,32,112,255,44,99,215,5,184,194,241,250,219,13,13,67,239,2,179,87,131,65,211,10,236,182,226,34,92,215,92,111,110,54,253,77,77,67,248,206,43,101,152,152,104,62,62,
214,90,95,200,182,77,59,52,3,247,94,161,80,60,219,208,194,240,44,28,8,20,223,209,250,214,194,110,93,12,127,13,129,9,129,36,219,159,207,114,185,194,86,46,103,50,16,164,199,8,26,90,14,128,111,101,179,230,
89,38,83,192,119,100,63,28,171,110,149,168,229,184,119,239,94,241,60,57,57,73,143,226,171,185,92,244,215,84,106,180,1,220,1,220,195,88,112,254,7,34,252,97,50,105,86,51,153,168,177,237,184,236,127,38,89,
171,23,248,236,236,108,241,122,199,113,110,255,116,120,248,198,223,217,236,7,253,224,187,22,60,91,7,198,159,166,211,15,119,93,247,54,77,116,231,206,157,243,209,225,122,15,2,0,192,147,95,220,189,59,244,
237,212,212,39,77,233,244,13,120,228,165,61,239,199,111,38,38,126,153,155,155,243,206,10,244,220,0,11,224,222,228,236,236,3,56,63,208,22,117,222,128,209,138,111,66,187,6,237,10,180,198,210,51,235,130,
178,112,6,218,46,180,63,208,187,160,21,144,16,139,82,239,224,224,160,237,186,238,87,243,243,243,51,125,125,125,40,163,166,128,242,84,225,192,224,226,71,53,181,9,246,161,247,248,53,221,99,139,197,98,102,
121,121,57,5,37,195,119,235,235,235,63,64,218,79,116,118,118,166,79,24,222,221,221,181,22,23,23,63,238,237,237,109,77,66,100,199,227,241,98,30,183,65,71,81,166,8,24,14,78,131,226,115,252,221,43,73,25,
159,144,222,165,254,244,27,31,139,192,210,24,116,31,0,221,222,217,217,49,169,84,170,121,120,120,248,163,213,213,213,159,161,223,243,237,237,237,253,151,124,184,189,189,253,53,236,176,183,183,119,50,16,
13,204,175,9,32,14,76,32,240,26,27,90,133,38,199,62,28,92,81,248,75,207,8,56,39,128,51,29,130,244,14,64,17,248,21,120,222,5,143,2,64,96,222,41,103,50,14,18,129,208,125,169,50,59,169,230,52,246,37,203,
220,101,248,59,100,1,206,50,222,227,248,137,68,194,28,28,28,184,152,214,225,183,60,180,196,201,72,224,6,39,1,134,157,144,45,58,184,25,185,105,165,191,210,123,220,101,164,127,75,119,32,214,233,90,113,25,
196,136,49,213,10,215,45,182,24,208,162,78,220,239,100,112,209,130,164,217,241,25,159,152,126,227,99,208,53,45,88,250,191,18,200,120,19,40,53,199,241,139,122,2,35,93,129,22,67,172,72,31,212,44,193,159,
17,80,90,156,22,196,114,145,12,184,117,170,248,145,114,195,25,144,193,196,217,45,183,112,41,91,4,86,46,82,206,85,83,181,198,253,75,234,38,105,180,230,199,220,119,57,40,206,38,245,225,146,70,215,156,105,
13,184,93,73,220,125,87,202,76,199,7,151,11,227,38,231,129,44,165,172,220,117,77,12,115,127,34,31,148,17,79,207,8,184,12,62,58,200,42,124,113,124,97,117,23,240,210,13,248,164,82,236,249,98,228,164,50,
184,36,1,62,170,80,54,213,219,149,216,149,218,201,153,228,89,77,246,247,51,169,4,161,153,95,254,94,21,96,30,24,114,34,206,176,95,98,225,1,196,173,38,231,224,129,43,245,184,174,111,58,77,23,185,232,19,
67,200,182,76,10,124,113,50,235,105,18,72,65,89,206,205,170,250,8,165,78,56,32,23,119,58,168,240,209,82,173,150,226,201,2,154,207,115,223,215,216,86,51,157,86,192,144,207,114,9,171,52,169,244,79,153,32,
120,113,37,217,244,179,136,47,195,154,217,181,204,39,3,134,64,72,165,225,103,98,144,167,100,25,7,90,12,169,128,181,136,149,166,150,229,162,95,224,241,5,203,88,224,5,150,172,59,52,101,42,235,18,146,41,
201,44,185,134,116,11,77,226,248,23,139,84,23,89,47,115,34,252,62,207,28,63,119,224,19,200,64,227,19,242,79,32,173,94,144,224,249,98,43,177,91,181,15,107,102,145,204,72,70,100,153,41,211,46,119,43,45,
163,242,69,240,250,164,34,195,252,195,145,3,245,75,32,28,132,172,127,53,144,156,105,154,139,204,175,41,83,85,46,193,117,80,11,38,201,34,77,40,163,159,3,145,11,230,193,39,63,145,252,216,45,43,107,126,147,
201,84,75,101,35,222,243,15,83,98,80,43,37,229,153,251,111,205,213,154,12,0,205,164,36,73,82,61,52,165,145,201,195,239,195,148,182,10,202,177,235,171,195,216,137,26,1,211,34,87,110,7,104,229,167,166,20,
50,176,240,140,96,113,227,166,146,74,248,250,48,55,189,252,56,148,169,85,102,60,191,0,229,140,243,62,68,10,151,200,154,125,152,71,43,47,108,180,132,192,217,226,105,86,147,70,63,137,171,84,244,148,245,
97,110,106,249,245,203,203,72,94,137,249,85,110,154,62,107,106,193,231,210,138,42,213,37,180,47,10,25,52,84,98,202,76,168,21,243,82,178,184,239,106,187,70,149,118,70,85,192,20,169,8,150,24,148,19,144,
124,113,86,165,94,75,159,151,37,39,175,212,100,113,132,45,147,201,20,131,144,123,204,41,192,177,88,236,57,14,134,155,112,8,202,117,221,83,42,193,253,143,24,164,197,249,109,12,202,61,7,94,159,80,63,158,
241,142,142,142,204,210,210,82,17,52,92,167,209,0,165,246,98,247,178,165,165,197,187,117,235,214,163,177,177,177,235,48,72,243,230,230,38,238,25,155,108,54,91,149,168,203,5,85,155,8,52,133,66,192,120,
222,222,222,206,63,126,252,248,95,220,171,44,181,212,201,14,124,36,18,177,166,167,167,175,193,68,131,3,3,3,111,5,131,193,78,232,216,10,76,56,23,241,183,65,60,30,207,239,239,239,39,224,114,21,48,61,133,
22,3,43,108,113,151,240,218,218,218,86,146,201,228,206,202,202,10,110,34,227,255,28,29,208,220,11,248,175,195,43,254,159,97,89,89,196,14,231,103,208,246,193,242,135,252,63,142,162,107,62,121,242,164,9,
220,160,13,152,189,4,191,225,190,108,67,73,254,94,57,96,104,89,0,154,128,118,4,49,149,12,135,195,41,153,233,142,199,199,199,83,209,104,52,3,38,137,231,114,57,7,2,225,66,92,2,1,131,11,20,192,53,243,16,
95,249,254,254,254,194,218,218,218,241,127,2,12,0,201,218,221,109,193,187,245,183,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* StructureAudioProcessorEditor::white_pushbutton_redled_36x36_down_png = (const char*) resource_StructureAudioProcessorEditor_white_pushbutton_redled_36x36_down_png;
const int StructureAudioProcessorEditor::white_pushbutton_redled_36x36_down_pngSize = 2644;

// JUCER_RESOURCE: white_pushbutton_redled_36x36_up_png, 2475, "../Graphics/white_pushbutton_REDLED_36x36_UP.png"
static const unsigned char resource_StructureAudioProcessorEditor_white_pushbutton_redled_36x36_up_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,50,8,6,0,0,0,39,88,57,234,0,0,
0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,65,100,111,98,101,32,73,109,97,103,101,82,101,97,100,121,113,201,101,60,0,0,3,35,105,84,88,116,88,77,76,58,99,111,109,46,97,100,111,98,101,46,120,109,
112,0,0,0,0,0,60,63,120,112,97,99,107,101,116,32,98,101,103,105,110,61,34,239,187,191,34,32,105,100,61,34,87,53,77,48,77,112,67,101,104,105,72,122,114,101,83,122,78,84,99,122,107,99,57,100,34,63,62,32,
60,120,58,120,109,112,109,101,116,97,32,120,109,108,110,115,58,120,61,34,97,100,111,98,101,58,110,115,58,109,101,116,97,47,34,32,120,58,120,109,112,116,107,61,34,65,100,111,98,101,32,88,77,80,32,67,111,
114,101,32,53,46,53,45,99,48,49,52,32,55,57,46,49,53,49,52,56,49,44,32,50,48,49,51,47,48,51,47,49,51,45,49,50,58,48,57,58,49,53,32,32,32,32,32,32,32,32,34,62,32,60,114,100,102,58,82,68,70,32,120,109,108,
110,115,58,114,100,102,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,49,57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,97,120,45,110,115,35,34,62,32,60,114,100,102,
58,68,101,115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,32,120,109,108,110,115,58,120,109,112,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,
47,120,97,112,47,49,46,48,47,34,32,120,109,108,110,115,58,120,109,112,77,77,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,109,109,47,34,32,120,
109,108,110,115,58,115,116,82,101,102,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,115,84,121,112,101,47,82,101,115,111,117,114,99,101,82,101,
102,35,34,32,120,109,112,58,67,114,101,97,116,111,114,84,111,111,108,61,34,65,100,111,98,101,32,80,104,111,116,111,115,104,111,112,32,67,67,32,40,77,97,99,105,110,116,111,115,104,41,34,32,120,109,112,
77,77,58,73,110,115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,57,54,69,67,68,56,53,65,55,50,66,48,49,49,69,54,66,53,51,55,66,51,67,55,54,55,51,68,57,67,49,53,34,32,120,109,112,77,77,
58,68,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,57,54,69,67,68,56,53,66,55,50,66,48,49,49,69,54,66,53,51,55,66,51,67,55,54,55,51,68,57,67,49,53,34,62,32,60,120,109,112,77,77,
58,68,101,114,105,118,101,100,70,114,111,109,32,115,116,82,101,102,58,105,110,115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,57,54,69,67,68,56,53,56,55,50,66,48,49,49,69,54,66,53,51,55,
66,51,67,55,54,55,51,68,57,67,49,53,34,32,115,116,82,101,102,58,100,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,57,54,69,67,68,56,53,57,55,50,66,48,49,49,69,54,66,53,51,55,66,
51,67,55,54,55,51,68,57,67,49,53,34,47,62,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,32,60,47,114,100,102,58,82,68,70,62,32,60,47,120,58,120,109,112,109,101,116,97,62,32,60,63,
120,112,97,99,107,101,116,32,101,110,100,61,34,114,34,63,62,176,79,157,184,0,0,6,30,73,68,65,84,120,218,212,89,205,79,99,85,20,191,175,31,50,164,45,9,146,56,12,65,209,152,176,50,153,33,49,97,197,208,168,
59,18,19,255,1,194,218,72,220,176,192,16,98,99,7,194,214,165,43,88,178,33,113,201,70,22,202,18,27,221,140,6,249,136,144,12,180,36,88,74,91,40,180,125,158,243,230,157,206,225,120,238,107,139,29,208,151,
156,188,251,238,187,31,191,251,187,231,235,221,231,184,174,107,254,79,87,132,10,169,84,202,60,123,246,204,56,142,99,38,38,38,204,216,216,152,193,197,208,130,102,103,103,91,25,239,3,167,94,95,128,65,63,
129,178,91,53,230,7,19,14,127,5,99,60,111,214,113,105,105,169,81,174,215,235,102,115,115,211,172,175,175,123,243,15,14,14,154,169,169,41,179,178,178,242,10,112,7,174,199,241,122,253,167,183,140,73,196,
253,138,162,49,159,230,106,181,100,49,20,122,10,143,191,118,98,146,80,171,13,145,129,80,40,100,149,88,189,254,221,16,128,125,15,218,190,227,139,95,238,193,119,65,125,57,187,29,3,220,228,122,187,199,152,
209,62,40,32,187,97,95,176,140,117,248,14,219,220,41,195,120,45,46,46,122,250,165,200,80,20,222,71,149,62,111,248,245,216,70,235,139,99,190,54,192,164,26,209,104,84,202,243,11,48,178,75,180,52,214,22,
203,88,135,239,176,141,236,215,142,42,252,195,75,180,115,165,211,105,239,62,63,63,79,85,167,5,99,190,207,25,243,25,50,16,243,43,75,32,89,16,124,135,109,100,255,215,174,18,26,112,218,218,106,52,250,249,
159,198,236,236,64,253,158,47,88,62,48,102,27,223,81,187,127,3,246,214,12,243,107,97,97,193,187,207,205,205,29,155,7,15,62,124,81,169,124,25,114,221,167,158,63,117,156,31,187,186,186,190,53,181,218,25,
181,235,88,224,232,16,240,51,144,111,238,36,210,193,229,128,188,15,242,4,164,247,165,55,242,234,156,123,138,194,16,119,76,30,228,23,144,63,64,106,158,29,83,248,29,31,31,15,141,142,142,126,145,201,100,
206,220,255,192,117,125,125,237,174,173,173,21,134,134,134,190,6,143,242,168,187,187,59,1,229,72,195,232,78,78,78,156,229,229,229,143,70,70,70,122,238,59,193,65,2,247,247,247,77,62,159,79,36,147,201,143,
107,181,218,192,213,213,85,95,54,155,141,221,208,225,190,190,190,126,217,25,26,123,3,96,82,196,7,244,116,200,175,163,247,40,232,9,232,29,213,203,254,18,28,31,7,152,53,23,23,23,230,242,242,210,108,108,
108,128,219,217,121,4,245,131,24,60,171,112,89,141,14,39,174,84,42,6,86,230,13,132,207,18,32,47,183,2,174,97,44,126,59,185,48,156,3,1,151,74,37,115,126,126,110,14,14,14,204,225,225,97,23,52,27,128,54,
85,144,98,3,48,52,114,160,162,49,19,44,198,91,41,1,230,140,114,150,37,91,152,204,240,69,19,243,124,12,122,230,59,67,207,8,24,137,194,185,81,160,76,105,73,28,222,223,84,9,9,24,213,129,28,190,100,77,178,
74,96,177,159,92,152,182,51,92,117,228,206,226,188,36,240,236,176,124,42,18,105,101,235,56,107,60,169,215,88,226,224,176,31,111,207,251,208,59,62,151,92,132,216,69,207,197,134,154,129,149,0,249,182,146,
216,250,91,243,1,31,172,182,72,57,87,203,185,4,117,32,118,57,147,180,117,146,61,201,148,220,9,105,112,154,74,81,127,219,130,3,25,150,43,149,91,72,34,85,70,50,175,237,134,246,172,25,119,91,12,107,147,19,
123,124,96,169,123,92,63,53,253,149,101,77,5,218,86,137,32,144,146,233,160,73,249,150,203,62,242,110,243,213,109,229,195,220,40,56,131,114,23,108,236,112,117,208,218,106,192,108,227,6,166,151,210,48,180,
58,122,150,70,162,45,128,116,61,200,11,112,213,106,219,232,168,35,89,174,205,221,217,130,130,182,24,77,45,184,161,133,195,225,64,117,104,249,19,73,50,36,245,150,206,23,184,43,212,220,34,7,47,239,210,0,
9,124,203,42,161,109,137,141,209,32,107,183,185,49,13,124,43,227,68,154,185,53,109,139,52,224,60,140,219,22,195,199,145,73,146,230,113,110,229,37,52,214,249,100,26,99,182,92,89,250,110,25,234,37,235,218,
46,135,130,226,189,45,104,104,193,67,243,183,52,14,15,227,18,36,47,107,172,183,29,233,200,88,36,184,86,147,245,32,159,43,189,137,172,107,27,112,80,236,231,201,138,45,4,219,34,24,103,95,166,162,220,157,
222,42,91,227,238,76,115,105,152,100,219,162,153,13,184,204,0,109,73,151,198,180,213,75,144,31,212,116,137,27,14,79,39,241,206,89,183,37,228,154,199,209,222,181,101,116,218,215,175,198,60,191,211,34,185,
222,219,66,181,246,169,213,177,195,64,233,91,165,213,107,14,159,91,190,205,159,107,249,73,51,224,129,233,37,109,119,80,70,166,25,167,141,61,14,74,6,27,114,127,205,18,248,192,72,71,58,169,101,81,50,194,
5,165,139,178,191,92,172,84,63,155,15,110,57,31,150,95,184,218,39,13,159,140,140,81,126,242,200,197,72,215,37,119,75,243,201,86,134,233,76,130,235,41,158,57,52,251,202,160,119,216,95,234,52,29,123,217,
182,157,159,73,224,129,10,149,155,2,198,70,120,226,131,231,91,8,82,78,34,99,190,141,125,219,238,104,117,68,14,2,45,151,203,116,234,211,32,41,16,48,158,109,229,243,121,83,44,22,189,1,130,178,46,254,105,
111,251,210,176,157,187,73,125,70,65,162,10,133,130,57,62,62,54,167,167,167,30,104,246,143,231,38,224,108,54,123,146,72,36,204,222,222,158,215,24,59,179,14,234,249,3,25,165,205,139,112,160,154,193,241,
11,201,193,57,143,142,142,204,234,234,170,135,1,174,50,180,67,43,68,121,117,122,25,139,197,220,201,201,201,205,233,233,233,36,48,28,207,100,50,102,119,119,215,59,69,180,133,73,109,226,118,130,128,92,20,
170,34,18,148,203,229,60,181,192,53,188,252,175,227,253,144,42,121,224,169,83,42,149,114,210,233,244,19,120,78,246,247,247,191,11,204,13,192,214,196,97,197,145,187,250,109,64,160,125,111,115,133,0,65,
126,135,5,253,12,114,4,152,94,112,149,112,65,29,126,3,118,115,160,26,15,161,211,67,168,123,19,164,235,30,254,117,184,0,16,153,68,208,121,40,31,131,252,5,161,191,208,96,56,153,76,122,6,188,181,181,213,
13,172,38,96,133,61,240,46,238,255,125,13,221,53,96,95,174,0,104,17,228,60,18,137,148,122,123,123,203,210,75,212,103,102,102,202,43,43,43,21,240,18,121,48,130,8,108,81,196,220,207,159,36,23,84,160,22,
141,70,171,96,95,213,225,225,225,218,246,246,118,253,111,1,6,0,204,118,42,71,56,207,249,143,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* StructureAudioProcessorEditor::white_pushbutton_redled_36x36_up_png = (const char*) resource_StructureAudioProcessorEditor_white_pushbutton_redled_36x36_up_png;
const int StructureAudioProcessorEditor::white_pushbutton_redled_36x36_up_pngSize = 2475;

// JUCER_RESOURCE: white_pushbutton_down_png, 1958, "../Graphics/white_pushbutton_DOWN.png"
static const unsigned char resource_StructureAudioProcessorEditor_white_pushbutton_down_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,44,8,6,0,0,0,30,132,90,1,0,0,0,25,116,69,
88,116,83,111,102,116,119,97,114,101,0,65,100,111,98,101,32,73,109,97,103,101,82,101,97,100,121,113,201,101,60,0,0,3,35,105,84,88,116,88,77,76,58,99,111,109,46,97,100,111,98,101,46,120,109,112,0,0,0,0,
0,60,63,120,112,97,99,107,101,116,32,98,101,103,105,110,61,34,239,187,191,34,32,105,100,61,34,87,53,77,48,77,112,67,101,104,105,72,122,114,101,83,122,78,84,99,122,107,99,57,100,34,63,62,32,60,120,58,120,
109,112,109,101,116,97,32,120,109,108,110,115,58,120,61,34,97,100,111,98,101,58,110,115,58,109,101,116,97,47,34,32,120,58,120,109,112,116,107,61,34,65,100,111,98,101,32,88,77,80,32,67,111,114,101,32,53,
46,53,45,99,48,49,52,32,55,57,46,49,53,49,52,56,49,44,32,50,48,49,51,47,48,51,47,49,51,45,49,50,58,48,57,58,49,53,32,32,32,32,32,32,32,32,34,62,32,60,114,100,102,58,82,68,70,32,120,109,108,110,115,58,
114,100,102,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,49,57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,97,120,45,110,115,35,34,62,32,60,114,100,102,58,68,101,
115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,32,120,109,108,110,115,58,120,109,112,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,
112,47,49,46,48,47,34,32,120,109,108,110,115,58,120,109,112,77,77,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,109,109,47,34,32,120,109,108,110,
115,58,115,116,82,101,102,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,115,84,121,112,101,47,82,101,115,111,117,114,99,101,82,101,102,35,34,32,
120,109,112,58,67,114,101,97,116,111,114,84,111,111,108,61,34,65,100,111,98,101,32,80,104,111,116,111,115,104,111,112,32,67,67,32,40,77,97,99,105,110,116,111,115,104,41,34,32,120,109,112,77,77,58,73,110,
115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,67,67,49,49,66,52,70,68,55,50,65,68,49,49,69,54,66,53,51,55,66,51,67,55,54,55,51,68,57,67,49,53,34,32,120,109,112,77,77,58,68,111,99,117,
109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,67,67,49,49,66,52,70,69,55,50,65,68,49,49,69,54,66,53,51,55,66,51,67,55,54,55,51,68,57,67,49,53,34,62,32,60,120,109,112,77,77,58,68,101,114,105,
118,101,100,70,114,111,109,32,115,116,82,101,102,58,105,110,115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,67,67,49,49,66,52,70,66,55,50,65,68,49,49,69,54,66,53,51,55,66,51,67,55,54,55,
51,68,57,67,49,53,34,32,115,116,82,101,102,58,100,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,67,67,49,49,66,52,70,67,55,50,65,68,49,49,69,54,66,53,51,55,66,51,67,55,54,55,51,
68,57,67,49,53,34,47,62,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,32,60,47,114,100,102,58,82,68,70,62,32,60,47,120,58,120,109,112,109,101,116,97,62,32,60,63,120,112,97,99,107,
101,116,32,101,110,100,61,34,114,34,63,62,90,130,147,55,0,0,4,25,73,68,65,84,120,218,236,89,177,78,27,65,16,93,219,103,129,132,112,36,234,52,32,209,56,29,5,52,20,145,248,6,74,106,254,128,14,97,201,127,
64,199,23,208,208,166,225,15,128,58,41,0,137,96,68,129,192,72,216,8,240,25,236,220,88,154,232,241,60,187,222,35,34,36,146,79,90,249,110,239,110,239,205,204,219,55,179,235,66,191,223,119,255,211,81,24,
3,254,155,128,107,181,90,161,94,175,87,179,190,47,217,101,241,3,113,245,10,133,194,247,205,205,205,31,25,166,215,30,21,192,218,170,213,106,169,82,169,108,108,111,111,55,27,141,70,250,248,248,216,215,246,
244,244,244,174,173,211,233,244,211,52,237,159,158,158,166,91,91,91,205,169,169,169,13,193,131,248,164,37,108,218,222,222,222,210,242,242,242,140,220,188,191,191,119,207,207,207,46,179,118,208,208,200,
65,120,178,62,57,215,123,218,95,44,22,93,175,215,27,122,7,175,135,66,157,221,43,151,203,174,84,42,149,87,86,86,102,146,36,89,218,221,221,29,122,110,8,240,194,194,194,162,12,126,117,117,229,50,203,7,125,
217,32,191,1,200,61,1,196,32,16,32,27,161,207,91,70,200,61,28,87,190,121,126,126,238,38,38,38,22,45,195,134,0,103,86,78,103,225,25,188,40,64,209,107,33,143,201,179,114,45,160,208,107,10,86,163,228,139,
130,222,155,156,156,116,173,86,203,93,94,94,86,162,0,203,241,242,242,242,42,220,72,9,249,8,130,87,0,10,20,129,35,117,244,80,3,176,31,127,165,137,195,110,111,111,93,52,96,30,208,234,195,112,162,135,20,
188,222,183,100,19,163,195,198,88,253,120,20,45,64,24,62,126,17,239,75,36,20,28,2,84,42,48,13,120,44,156,11,106,40,82,42,10,176,5,14,169,161,3,242,132,241,69,5,233,132,147,139,199,181,232,23,13,152,61,
162,158,139,81,10,164,129,190,195,227,98,159,158,235,36,28,117,20,71,241,55,228,61,4,43,31,148,38,52,241,189,143,30,87,227,45,249,203,13,88,249,137,158,70,96,168,169,234,113,109,28,82,245,184,54,75,45,
216,168,80,125,147,248,40,97,77,62,12,53,246,107,98,65,207,114,120,217,16,164,87,232,185,104,89,243,129,99,138,176,231,216,211,168,199,22,229,248,119,84,245,232,165,4,107,40,2,179,36,207,162,68,104,230,
179,225,86,173,146,91,37,24,40,10,187,78,48,252,16,122,156,245,151,121,204,28,214,72,132,232,16,84,9,229,24,214,2,204,83,238,179,244,214,55,25,57,9,141,202,176,209,148,64,53,224,2,200,226,31,71,7,141,
182,170,53,75,113,114,123,216,162,1,166,96,188,230,10,205,170,234,180,137,154,132,38,53,27,156,219,195,152,223,113,162,97,197,230,43,110,216,0,212,118,171,190,8,233,114,148,135,49,101,234,71,17,36,22,
60,150,199,124,209,210,231,245,92,239,235,4,126,147,14,115,6,179,234,11,171,8,247,205,114,164,141,70,7,121,139,17,245,149,164,185,170,53,86,5,95,133,165,125,86,193,195,192,112,53,195,85,224,155,50,29,
90,139,160,117,226,176,247,125,25,203,183,80,181,202,83,54,54,151,135,149,87,92,23,132,196,159,105,227,83,11,228,61,3,252,35,74,48,32,86,5,139,18,190,89,142,245,46,110,29,96,4,222,92,94,90,19,141,87,191,
232,121,95,58,102,213,65,181,177,150,99,40,161,185,56,236,91,92,50,223,240,195,72,19,223,26,142,157,192,224,70,73,90,244,18,137,101,139,55,71,124,145,177,56,234,75,237,161,82,116,228,170,153,127,153,183,
56,105,84,53,84,166,66,43,109,124,31,199,228,61,141,144,167,189,169,217,146,44,171,2,179,182,157,120,179,132,149,197,74,203,86,138,142,226,176,188,152,36,137,153,52,56,9,96,9,202,165,167,117,110,109,23,
176,113,114,221,110,183,227,1,63,60,60,180,211,52,253,36,210,35,251,92,60,185,208,235,98,24,134,147,247,202,44,111,98,2,98,73,147,247,143,143,143,221,197,197,133,244,183,162,0,239,239,239,31,206,205,205,
125,110,52,26,2,222,117,187,93,51,244,150,114,196,108,23,248,174,229,184,187,187,115,39,39,39,131,132,117,115,115,115,24,5,120,125,125,253,96,109,109,237,235,236,236,236,116,179,217,44,95,95,95,191,255,
223,0,0,186,211,233,116,207,206,206,218,71,71,71,7,243,243,243,97,192,171,171,171,189,122,189,254,109,103,103,231,231,191,240,151,129,224,25,255,139,52,6,60,6,252,193,199,47,1,6,0,25,133,145,233,137,2,
73,187,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* StructureAudioProcessorEditor::white_pushbutton_down_png = (const char*) resource_StructureAudioProcessorEditor_white_pushbutton_down_png;
const int StructureAudioProcessorEditor::white_pushbutton_down_pngSize = 1958;

// JUCER_RESOURCE: white_pushbutton_up_png, 2311, "../Graphics/white_pushbutton_UP.png"
static const unsigned char resource_StructureAudioProcessorEditor_white_pushbutton_up_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,44,8,6,0,0,0,30,132,90,1,0,0,0,25,116,69,88,
116,83,111,102,116,119,97,114,101,0,65,100,111,98,101,32,73,109,97,103,101,82,101,97,100,121,113,201,101,60,0,0,3,35,105,84,88,116,88,77,76,58,99,111,109,46,97,100,111,98,101,46,120,109,112,0,0,0,0,0,
60,63,120,112,97,99,107,101,116,32,98,101,103,105,110,61,34,239,187,191,34,32,105,100,61,34,87,53,77,48,77,112,67,101,104,105,72,122,114,101,83,122,78,84,99,122,107,99,57,100,34,63,62,32,60,120,58,120,
109,112,109,101,116,97,32,120,109,108,110,115,58,120,61,34,97,100,111,98,101,58,110,115,58,109,101,116,97,47,34,32,120,58,120,109,112,116,107,61,34,65,100,111,98,101,32,88,77,80,32,67,111,114,101,32,53,
46,53,45,99,48,49,52,32,55,57,46,49,53,49,52,56,49,44,32,50,48,49,51,47,48,51,47,49,51,45,49,50,58,48,57,58,49,53,32,32,32,32,32,32,32,32,34,62,32,60,114,100,102,58,82,68,70,32,120,109,108,110,115,58,
114,100,102,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,49,57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,97,120,45,110,115,35,34,62,32,60,114,100,102,58,68,101,
115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,32,120,109,108,110,115,58,120,109,112,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,
112,47,49,46,48,47,34,32,120,109,108,110,115,58,120,109,112,77,77,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,109,109,47,34,32,120,109,108,110,
115,58,115,116,82,101,102,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,115,84,121,112,101,47,82,101,115,111,117,114,99,101,82,101,102,35,34,32,
120,109,112,58,67,114,101,97,116,111,114,84,111,111,108,61,34,65,100,111,98,101,32,80,104,111,116,111,115,104,111,112,32,67,67,32,40,77,97,99,105,110,116,111,115,104,41,34,32,120,109,112,77,77,58,73,110,
115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,67,67,49,49,66,52,70,57,55,50,65,68,49,49,69,54,66,53,51,55,66,51,67,55,54,55,51,68,57,67,49,53,34,32,120,109,112,77,77,58,68,111,99,117,
109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,67,67,49,49,66,52,70,65,55,50,65,68,49,49,69,54,66,53,51,55,66,51,67,55,54,55,51,68,57,67,49,53,34,62,32,60,120,109,112,77,77,58,68,101,114,105,
118,101,100,70,114,111,109,32,115,116,82,101,102,58,105,110,115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,67,67,49,49,66,52,70,55,55,50,65,68,49,49,69,54,66,53,51,55,66,51,67,55,54,55,
51,68,57,67,49,53,34,32,115,116,82,101,102,58,100,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,67,67,49,49,66,52,70,56,55,50,65,68,49,49,69,54,66,53,51,55,66,51,67,55,54,55,51,
68,57,67,49,53,34,47,62,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,32,60,47,114,100,102,58,82,68,70,62,32,60,47,120,58,120,109,112,109,101,116,97,62,32,60,63,120,112,97,99,107,
101,116,32,101,110,100,61,34,114,34,63,62,174,1,129,15,0,0,5,122,73,68,65,84,120,218,212,89,77,75,51,73,16,238,100,38,137,137,186,17,125,215,47,188,45,40,120,219,195,194,194,94,2,46,123,209,5,61,120,216,
155,136,127,194,147,130,7,127,132,254,3,207,123,93,133,21,4,69,220,195,162,224,94,84,240,131,141,49,174,154,152,143,73,178,85,195,148,212,84,186,103,38,175,239,171,56,208,116,210,233,233,126,234,233,167,
171,171,43,177,86,171,165,62,210,19,87,31,236,249,112,128,109,254,101,117,117,53,190,182,182,246,107,127,127,255,207,83,83,83,223,116,119,119,91,208,28,243,126,118,235,24,60,95,11,12,200,179,245,240,240,
208,220,222,222,126,44,22,139,127,12,13,13,253,14,205,245,241,241,241,70,46,151,67,237,182,176,211,75,153,156,156,76,46,46,46,254,121,127,127,223,122,207,231,252,252,188,53,61,61,189,159,76,38,191,131,
242,109,58,157,238,29,25,25,73,172,172,172,196,124,128,103,102,102,50,165,82,169,250,158,96,203,229,114,107,127,127,191,181,177,177,81,75,165,82,63,89,150,53,145,72,36,70,16,52,16,106,249,52,188,185,185,
249,125,38,147,73,190,135,54,145,48,0,171,10,133,130,58,57,57,81,199,199,199,137,137,137,137,31,161,125,160,217,108,102,29,199,73,231,243,121,203,167,97,219,182,51,166,1,225,165,151,129,229,68,158,182,
125,159,195,30,236,131,99,226,59,88,87,42,21,5,171,171,64,142,10,116,172,142,142,142,212,237,237,237,48,252,254,9,186,59,80,63,195,243,228,3,92,173,86,227,58,160,56,24,214,141,70,163,13,20,126,39,176,
88,226,241,184,251,29,251,82,31,110,0,245,225,4,224,103,152,91,61,62,62,186,5,1,95,94,94,98,221,15,93,6,80,41,184,31,97,76,219,7,24,26,218,0,131,85,170,86,171,41,88,18,31,187,4,148,131,149,192,184,81,
28,36,239,135,109,4,24,231,193,26,9,242,72,74,67,151,110,40,105,24,35,5,223,45,201,112,76,24,224,78,134,96,233,51,103,84,183,204,58,137,224,131,99,32,104,105,8,205,83,175,215,95,10,126,199,2,0,145,64,
203,115,191,22,244,183,36,195,109,226,243,94,124,89,186,32,237,74,121,232,140,225,125,169,63,39,131,179,238,249,126,95,137,71,217,189,52,25,151,0,177,196,141,224,64,164,97,186,13,75,140,147,238,165,65,
252,192,162,218,238,4,172,100,152,27,64,26,213,109,52,222,166,27,131,175,86,152,135,137,135,185,158,32,151,101,98,143,250,19,56,146,148,78,191,58,86,131,34,200,200,193,143,156,72,186,41,221,100,82,62,
188,150,43,192,87,236,85,209,154,4,162,155,84,74,129,179,137,198,232,192,75,50,116,99,133,70,107,65,26,14,91,42,147,87,208,25,46,199,149,254,249,85,146,224,47,211,110,150,26,229,236,69,49,138,198,48,141,
247,170,77,103,90,30,154,140,127,215,109,86,222,38,181,78,159,185,108,194,116,28,42,9,201,34,119,113,166,67,66,167,123,30,107,232,230,48,121,159,142,37,1,241,104,27,88,147,27,50,49,36,153,36,55,103,210,
247,171,188,132,116,244,124,167,243,165,212,185,52,105,68,88,144,20,37,44,181,163,248,94,174,65,25,180,232,216,52,45,175,9,80,212,13,23,249,224,32,102,228,82,74,134,131,60,2,191,138,73,89,112,50,164,198,
59,2,44,79,31,93,120,104,210,44,181,75,31,203,99,15,221,81,111,58,92,34,1,214,89,43,7,163,80,80,2,151,94,193,20,12,133,29,64,29,51,108,58,241,164,71,160,43,20,95,222,160,59,160,148,136,148,207,103,251,
97,157,223,53,69,111,82,171,186,227,57,232,84,140,226,45,236,40,81,154,156,200,180,132,65,177,109,144,59,147,140,127,246,193,33,143,222,32,198,130,220,161,52,128,198,50,165,14,130,92,157,29,118,104,144,
251,225,87,124,174,97,108,39,239,33,111,30,244,62,247,223,220,173,209,251,244,27,94,84,101,58,161,35,192,116,123,165,139,40,129,147,103,63,103,2,39,149,167,159,116,87,68,2,55,138,110,230,84,155,64,219,
65,236,98,142,128,242,5,148,151,224,27,208,20,90,234,98,15,211,70,34,144,148,143,160,57,241,186,223,145,36,40,117,132,5,7,32,203,117,27,76,38,73,100,230,71,167,107,126,223,195,190,152,176,193,140,207,
211,211,147,42,22,139,238,156,161,12,131,85,101,47,161,162,238,238,238,220,60,23,14,128,224,121,230,71,119,153,148,76,154,88,215,73,133,24,198,52,21,38,3,247,246,246,220,85,69,72,208,191,233,230,133,193,
54,172,125,128,231,230,230,254,222,221,221,173,95,95,95,39,48,131,136,217,68,28,132,24,230,218,51,29,227,97,129,144,212,62,109,104,34,105,103,103,71,157,157,157,97,191,38,252,150,247,128,226,210,54,177,
205,7,56,159,207,215,151,150,150,254,154,157,157,253,225,244,244,84,29,30,30,170,139,139,11,151,97,158,1,250,146,15,73,2,53,75,218,245,140,251,23,170,18,166,247,80,161,0,182,10,210,115,98,28,192,216,216,
88,250,234,234,234,183,84,42,245,203,224,224,224,39,96,56,3,37,141,89,67,232,247,197,255,42,208,29,211,158,182,171,80,254,1,128,187,208,118,9,96,175,161,220,116,117,117,229,125,128,71,71,71,19,160,161,
44,0,196,20,231,128,151,155,29,128,210,227,37,229,190,218,255,27,220,14,79,6,184,159,10,0,20,203,45,128,47,244,246,246,222,251,36,129,127,126,28,28,28,84,48,23,11,150,198,188,68,50,190,152,121,7,192,40,
131,7,40,255,97,109,219,246,243,240,240,176,35,221,90,51,155,205,86,193,59,196,96,147,53,48,235,141,224,161,116,189,53,96,212,44,234,23,152,125,134,123,229,115,79,79,79,101,126,126,222,191,233,114,185,
28,22,103,107,107,171,124,115,115,83,131,77,80,194,36,50,20,212,112,252,141,0,187,196,225,6,3,160,14,48,219,232,235,235,115,22,22,22,26,109,110,141,89,216,240,74,149,26,151,151,151,223,10,172,90,95,95,
55,186,162,255,5,24,0,240,219,213,177,127,113,203,120,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* StructureAudioProcessorEditor::white_pushbutton_up_png = (const char*) resource_StructureAudioProcessorEditor_white_pushbutton_up_png;
const int StructureAudioProcessorEditor::white_pushbutton_up_pngSize = 2311;

// JUCER_RESOURCE: structureanalysegreenlight_png, 1501, "../Graphics/structure-analyse-greenlight.png"
static const unsigned char resource_StructureAudioProcessorEditor_structureanalysegreenlight_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,13,0,0,0,13,8,6,0,0,0,114,235,228,124,0,0,0,25,
116,69,88,116,83,111,102,116,119,97,114,101,0,65,100,111,98,101,32,73,109,97,103,101,82,101,97,100,121,113,201,101,60,0,0,3,107,105,84,88,116,88,77,76,58,99,111,109,46,97,100,111,98,101,46,120,109,112,
0,0,0,0,0,60,63,120,112,97,99,107,101,116,32,98,101,103,105,110,61,34,239,187,191,34,32,105,100,61,34,87,53,77,48,77,112,67,101,104,105,72,122,114,101,83,122,78,84,99,122,107,99,57,100,34,63,62,32,60,
120,58,120,109,112,109,101,116,97,32,120,109,108,110,115,58,120,61,34,97,100,111,98,101,58,110,115,58,109,101,116,97,47,34,32,120,58,120,109,112,116,107,61,34,65,100,111,98,101,32,88,77,80,32,67,111,114,
101,32,53,46,53,45,99,48,49,52,32,55,57,46,49,53,49,52,56,49,44,32,50,48,49,51,47,48,51,47,49,51,45,49,50,58,48,57,58,49,53,32,32,32,32,32,32,32,32,34,62,32,60,114,100,102,58,82,68,70,32,120,109,108,110,
115,58,114,100,102,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,49,57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,97,120,45,110,115,35,34,62,32,60,114,100,102,58,
68,101,115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,32,120,109,108,110,115,58,120,109,112,77,77,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,
109,47,120,97,112,47,49,46,48,47,109,109,47,34,32,120,109,108,110,115,58,115,116,82,101,102,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,115,84,
121,112,101,47,82,101,115,111,117,114,99,101,82,101,102,35,34,32,120,109,108,110,115,58,120,109,112,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,
47,34,32,120,109,112,77,77,58,79,114,105,103,105,110,97,108,68,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,48,55,56,48,49,49,55,52,48,55,50,48,54,56,49,49,56,67,49,52,68,69,48,
68,65,55,70,69,50,51,52,57,34,32,120,109,112,77,77,58,68,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,50,52,57,51,56,69,54,68,55,50,48,50,49,49,69,54,65,65,55,55,67,56,53,57,48,
54,69,68,66,55,69,70,34,32,120,109,112,77,77,58,73,110,115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,50,52,57,51,56,69,54,67,55,50,48,50,49,49,69,54,65,65,55,55,67,56,53,57,48,54,69,
68,66,55,69,70,34,32,120,109,112,58,67,114,101,97,116,111,114,84,111,111,108,61,34,65,100,111,98,101,32,80,104,111,116,111,115,104,111,112,32,67,67,32,40,77,97,99,105,110,116,111,115,104,41,34,62,32,60,
120,109,112,77,77,58,68,101,114,105,118,101,100,70,114,111,109,32,115,116,82,101,102,58,105,110,115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,52,53,97,49,52,101,101,100,45,102,101,48,
101,45,52,97,57,48,45,98,51,52,98,45,101,51,56,98,48,98,99,56,102,57,97,55,34,32,115,116,82,101,102,58,100,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,48,55,56,48,49,49,55,52,
48,55,50,48,54,56,49,49,56,67,49,52,68,69,48,68,65,55,70,69,50,51,52,57,34,47,62,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,32,60,47,114,100,102,58,82,68,70,62,32,60,47,120,58,
120,109,112,109,101,116,97,62,32,60,63,120,112,97,99,107,101,116,32,101,110,100,61,34,114,34,63,62,122,104,55,109,0,0,2,8,73,68,65,84,120,218,108,146,65,104,19,65,20,134,255,153,217,236,38,155,96,26,173,
164,90,165,72,212,230,160,120,80,65,133,66,133,220,123,241,40,42,130,122,84,140,164,34,133,120,17,13,106,111,30,4,145,42,34,246,218,131,135,16,177,130,23,107,106,17,189,8,82,105,108,114,104,171,165,236,
38,155,236,238,236,248,54,82,180,213,55,252,151,247,222,247,230,231,205,176,98,177,136,48,246,223,4,70,115,247,112,186,114,132,63,29,126,191,215,111,170,93,90,156,45,158,153,62,250,245,89,174,26,148,42,
215,176,30,26,254,4,35,157,123,49,50,91,216,50,96,100,53,147,67,182,20,38,71,230,190,80,190,68,154,32,169,191,33,86,200,221,125,216,179,207,184,208,123,40,134,68,191,142,136,41,186,144,93,247,6,87,62,
58,143,71,115,247,143,151,42,249,75,33,40,66,91,207,39,38,47,110,29,140,22,251,79,198,145,62,22,195,182,3,81,36,247,24,72,236,214,17,235,213,186,3,60,75,29,158,26,127,211,232,59,235,206,134,55,113,61,
33,10,169,131,58,66,37,51,58,132,198,127,123,143,114,2,244,174,41,231,135,15,171,222,41,80,250,17,159,186,49,147,53,82,34,99,238,16,48,251,4,32,20,84,215,186,66,64,135,209,216,24,213,226,59,35,136,246,
104,153,39,195,51,89,238,123,126,90,24,12,194,224,96,196,40,69,205,42,216,0,242,8,205,138,134,98,144,77,164,185,153,50,230,93,219,87,158,45,225,59,212,20,4,255,128,94,91,194,109,146,108,169,200,213,60,
63,127,34,95,115,215,130,170,181,224,193,170,185,144,237,141,160,215,145,176,190,187,176,22,92,116,214,100,245,78,57,95,11,23,161,164,131,177,229,57,231,165,158,228,66,73,208,202,35,16,38,25,235,40,180,
26,18,63,63,185,88,250,208,146,52,112,44,236,95,127,167,50,21,47,47,190,106,142,59,75,82,15,33,45,206,201,110,128,86,157,160,207,109,151,242,87,25,120,121,243,143,120,208,94,241,223,53,166,91,215,35,9,
62,196,56,182,147,195,101,223,14,222,146,221,219,156,137,234,255,190,81,24,97,225,212,208,173,1,225,166,86,185,190,154,10,94,95,249,38,55,245,224,151,0,3,0,111,20,244,220,38,158,66,48,0,0,0,0,73,69,78,
68,174,66,96,130,0,0};

const char* StructureAudioProcessorEditor::structureanalysegreenlight_png = (const char*) resource_StructureAudioProcessorEditor_structureanalysegreenlight_png;
const int StructureAudioProcessorEditor::structureanalysegreenlight_pngSize = 1501;

// JUCER_RESOURCE: structureanalyseorangelight_png, 1530, "../Graphics/structure-analyse-orangelight.png"
static const unsigned char resource_StructureAudioProcessorEditor_structureanalyseorangelight_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,13,0,0,0,13,8,6,0,0,0,114,235,228,124,0,0,0,
25,116,69,88,116,83,111,102,116,119,97,114,101,0,65,100,111,98,101,32,73,109,97,103,101,82,101,97,100,121,113,201,101,60,0,0,3,107,105,84,88,116,88,77,76,58,99,111,109,46,97,100,111,98,101,46,120,109,
112,0,0,0,0,0,60,63,120,112,97,99,107,101,116,32,98,101,103,105,110,61,34,239,187,191,34,32,105,100,61,34,87,53,77,48,77,112,67,101,104,105,72,122,114,101,83,122,78,84,99,122,107,99,57,100,34,63,62,32,
60,120,58,120,109,112,109,101,116,97,32,120,109,108,110,115,58,120,61,34,97,100,111,98,101,58,110,115,58,109,101,116,97,47,34,32,120,58,120,109,112,116,107,61,34,65,100,111,98,101,32,88,77,80,32,67,111,
114,101,32,53,46,53,45,99,48,49,52,32,55,57,46,49,53,49,52,56,49,44,32,50,48,49,51,47,48,51,47,49,51,45,49,50,58,48,57,58,49,53,32,32,32,32,32,32,32,32,34,62,32,60,114,100,102,58,82,68,70,32,120,109,108,
110,115,58,114,100,102,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,49,57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,97,120,45,110,115,35,34,62,32,60,114,100,102,
58,68,101,115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,32,120,109,108,110,115,58,120,109,112,77,77,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,
111,109,47,120,97,112,47,49,46,48,47,109,109,47,34,32,120,109,108,110,115,58,115,116,82,101,102,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,115,
84,121,112,101,47,82,101,115,111,117,114,99,101,82,101,102,35,34,32,120,109,108,110,115,58,120,109,112,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,
48,47,34,32,120,109,112,77,77,58,79,114,105,103,105,110,97,108,68,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,48,55,56,48,49,49,55,52,48,55,50,48,54,56,49,49,56,67,49,52,68,69,
48,68,65,55,70,69,50,51,52,57,34,32,120,109,112,77,77,58,68,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,55,67,50,55,69,52,70,69,55,49,70,69,49,49,69,54,65,65,55,55,67,56,53,57,
48,54,69,68,66,55,69,70,34,32,120,109,112,77,77,58,73,110,115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,55,67,50,55,69,52,70,68,55,49,70,69,49,49,69,54,65,65,55,55,67,56,53,57,48,54,
69,68,66,55,69,70,34,32,120,109,112,58,67,114,101,97,116,111,114,84,111,111,108,61,34,65,100,111,98,101,32,80,104,111,116,111,115,104,111,112,32,67,67,32,40,77,97,99,105,110,116,111,115,104,41,34,62,32,
60,120,109,112,77,77,58,68,101,114,105,118,101,100,70,114,111,109,32,115,116,82,101,102,58,105,110,115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,52,53,97,49,52,101,101,100,45,102,101,
48,101,45,52,97,57,48,45,98,51,52,98,45,101,51,56,98,48,98,99,56,102,57,97,55,34,32,115,116,82,101,102,58,100,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,48,55,56,48,49,49,55,
52,48,55,50,48,54,56,49,49,56,67,49,52,68,69,48,68,65,55,70,69,50,51,52,57,34,47,62,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,32,60,47,114,100,102,58,82,68,70,62,32,60,47,120,
58,120,109,112,109,101,116,97,62,32,60,63,120,112,97,99,107,101,116,32,101,110,100,61,34,114,34,63,62,80,136,82,11,0,0,2,37,73,68,65,84,120,218,92,82,207,107,19,65,24,125,51,187,217,31,137,154,109,68,
161,132,42,98,14,5,13,205,161,138,55,81,122,16,164,87,115,137,72,5,189,107,60,40,8,41,104,205,193,224,31,80,47,150,244,98,237,165,224,69,80,123,109,52,245,87,16,34,22,236,182,105,53,133,230,71,73,118,
55,187,179,187,206,70,139,152,15,134,249,152,121,239,123,243,190,111,72,46,151,67,16,211,19,192,196,205,2,238,61,31,23,111,95,123,127,177,103,249,73,89,33,149,39,115,103,222,230,211,101,246,122,246,14,
246,67,220,79,42,199,64,219,97,60,45,76,173,102,82,170,44,133,163,20,134,237,163,112,253,163,205,207,231,249,253,141,228,6,188,0,75,254,42,209,87,75,143,191,166,162,242,232,216,136,138,120,76,66,88,18,
250,164,173,150,131,207,155,38,62,53,173,234,236,82,246,84,64,36,203,15,206,227,214,98,169,120,78,83,51,23,70,35,24,27,81,48,172,73,144,68,1,182,11,252,108,51,124,169,89,88,174,118,240,174,101,204,151,
179,227,87,69,46,43,30,165,66,58,25,151,16,172,147,71,36,136,2,229,111,0,148,16,229,138,18,124,31,216,237,48,172,239,245,210,111,146,152,18,244,181,157,203,9,85,204,156,61,161,224,116,92,230,32,10,66,
200,31,163,124,163,60,15,9,64,163,235,65,175,219,194,220,11,189,76,153,195,18,114,136,64,22,41,4,14,242,121,89,223,11,252,250,232,75,112,239,1,73,17,3,101,130,158,137,4,61,160,201,165,142,201,208,177,
92,152,142,15,143,19,6,137,22,55,215,237,185,125,76,36,42,148,232,228,165,236,74,157,121,93,189,225,96,99,215,134,53,64,236,57,46,54,27,54,116,126,87,103,110,247,217,66,118,37,152,147,215,36,152,249,160,
155,143,162,42,133,203,139,199,181,16,247,198,9,204,199,118,219,69,101,203,198,234,186,129,22,241,103,130,150,247,135,171,25,200,127,83,221,148,91,237,94,217,217,115,17,31,10,33,34,83,152,182,199,231,
196,73,219,22,214,152,187,160,153,52,255,223,143,56,100,32,253,253,32,123,89,211,141,124,172,70,135,185,16,117,4,120,13,230,253,50,4,239,238,97,67,40,130,12,124,163,32,98,29,20,9,69,113,242,225,113,73,
82,155,162,109,14,177,197,251,63,108,37,232,9,253,135,251,45,192,0,212,121,6,252,66,5,242,75,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* StructureAudioProcessorEditor::structureanalyseorangelight_png = (const char*) resource_StructureAudioProcessorEditor_structureanalyseorangelight_png;
const int StructureAudioProcessorEditor::structureanalyseorangelight_pngSize = 1530;

// JUCER_RESOURCE: structuredemoexpired_png, 12966, "../Graphics/structure-demoexpired.png"
static const unsigned char resource_StructureAudioProcessorEditor_structuredemoexpired_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,4,0,0,0,200,8,2,0,0,0,129,55,8,38,0,0,0,25,116,69,88,
116,83,111,102,116,119,97,114,101,0,65,100,111,98,101,32,73,109,97,103,101,82,101,97,100,121,113,201,101,60,0,0,3,107,105,84,88,116,88,77,76,58,99,111,109,46,97,100,111,98,101,46,120,109,112,0,0,0,0,0,
60,63,120,112,97,99,107,101,116,32,98,101,103,105,110,61,34,239,187,191,34,32,105,100,61,34,87,53,77,48,77,112,67,101,104,105,72,122,114,101,83,122,78,84,99,122,107,99,57,100,34,63,62,32,60,120,58,120,
109,112,109,101,116,97,32,120,109,108,110,115,58,120,61,34,97,100,111,98,101,58,110,115,58,109,101,116,97,47,34,32,120,58,120,109,112,116,107,61,34,65,100,111,98,101,32,88,77,80,32,67,111,114,101,32,53,
46,53,45,99,48,49,52,32,55,57,46,49,53,49,52,56,49,44,32,50,48,49,51,47,48,51,47,49,51,45,49,50,58,48,57,58,49,53,32,32,32,32,32,32,32,32,34,62,32,60,114,100,102,58,82,68,70,32,120,109,108,110,115,58,
114,100,102,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,49,57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,97,120,45,110,115,35,34,62,32,60,114,100,102,58,68,101,
115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,32,120,109,108,110,115,58,120,109,112,77,77,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,
120,97,112,47,49,46,48,47,109,109,47,34,32,120,109,108,110,115,58,115,116,82,101,102,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,115,84,121,112,
101,47,82,101,115,111,117,114,99,101,82,101,102,35,34,32,120,109,108,110,115,58,120,109,112,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,34,32,
120,109,112,77,77,58,79,114,105,103,105,110,97,108,68,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,48,55,56,48,49,49,55,52,48,55,50,48,54,56,49,49,56,67,49,52,68,69,48,68,65,55,
70,69,50,51,52,57,34,32,120,109,112,77,77,58,68,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,69,65,49,57,69,55,48,52,57,67,53,56,49,49,69,54,66,57,50,50,65,56,68,55,68,69,68,48,
48,66,50,68,34,32,120,109,112,77,77,58,73,110,115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,69,65,49,57,69,55,48,51,57,67,53,56,49,49,69,54,66,57,50,50,65,56,68,55,68,69,68,48,48,66,
50,68,34,32,120,109,112,58,67,114,101,97,116,111,114,84,111,111,108,61,34,65,100,111,98,101,32,80,104,111,116,111,115,104,111,112,32,67,67,32,40,77,97,99,105,110,116,111,115,104,41,34,62,32,60,120,109,
112,77,77,58,68,101,114,105,118,101,100,70,114,111,109,32,115,116,82,101,102,58,105,110,115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,97,48,99,49,99,102,101,101,45,56,55,57,102,45,52,
48,50,51,45,98,101,98,50,45,54,49,53,51,102,97,48,56,55,50,55,57,34,32,115,116,82,101,102,58,100,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,48,55,56,48,49,49,55,52,48,55,50,48,
54,56,49,49,56,67,49,52,68,69,48,68,65,55,70,69,50,51,52,57,34,47,62,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,32,60,47,114,100,102,58,82,68,70,62,32,60,47,120,58,120,109,112,
109,101,116,97,62,32,60,63,120,112,97,99,107,101,116,32,101,110,100,61,34,114,34,63,62,33,166,76,151,0,0,46,209,73,68,65,84,120,218,236,125,7,156,20,229,253,254,148,237,237,218,94,191,227,40,7,72,17,144,
34,69,137,5,21,11,34,74,52,74,162,230,151,72,140,70,19,252,27,67,52,152,96,36,98,137,145,88,176,160,137,45,24,187,2,42,160,40,74,164,136,137,2,2,210,142,59,224,184,182,119,183,183,125,119,118,102,254,
207,204,203,13,123,219,110,49,17,143,219,247,17,247,51,247,206,251,190,243,206,59,223,231,91,222,249,238,187,236,136,17,99,25,10,10,10,134,225,232,20,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,
80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,28,39,156,117,230,164,73,19,198,244,228,17,14,26,212,255,162,
11,167,80,25,165,100,248,118,81,80,144,55,168,186,191,36,201,61,247,193,112,220,89,223,155,84,144,151,71,101,148,146,225,219,133,221,102,149,36,209,239,247,247,216,17,242,60,135,17,186,59,58,168,140,82,
50,124,187,16,132,168,36,73,12,203,246,216,17,202,178,172,140,144,130,146,225,56,8,27,244,46,36,174,39,15,17,35,84,6,73,65,201,240,173,194,231,15,136,162,20,8,134,122,236,8,163,81,17,35,132,5,163,50,122,
220,160,235,221,183,103,52,26,115,115,237,122,157,122,155,154,79,36,51,121,121,57,162,36,22,21,21,132,195,97,38,214,87,146,241,159,226,162,68,194,17,87,107,123,151,153,226,121,180,210,27,244,90,137,223,
23,232,240,120,187,141,131,139,10,11,194,145,72,123,123,114,239,223,110,183,154,77,38,29,70,200,198,199,12,24,161,193,168,47,47,43,78,110,191,100,166,169,185,5,132,73,63,0,135,195,102,49,155,27,155,90,
140,70,67,94,110,142,187,195,19,10,133,19,43,116,233,247,8,88,213,58,41,42,195,231,243,103,3,25,216,222,186,111,18,203,178,227,79,29,217,183,170,226,155,53,247,120,124,239,174,92,171,253,121,202,168,97,
131,7,245,139,171,83,179,255,224,103,155,183,116,199,70,195,165,151,156,215,238,246,172,90,253,73,23,106,233,116,39,13,238,63,112,96,95,163,193,240,141,239,113,217,138,53,129,64,48,125,157,137,19,78,169,
234,83,254,242,171,239,128,84,167,159,54,118,195,166,47,234,234,234,201,41,167,51,111,194,248,83,108,86,75,183,23,10,135,35,95,239,170,217,249,245,94,106,25,78,72,156,125,230,196,252,188,28,60,248,195,
13,77,112,57,226,206,230,230,56,134,14,169,174,59,80,95,127,184,41,177,237,164,9,163,165,78,141,171,215,235,46,56,239,12,200,116,99,67,75,107,91,187,162,137,89,6,18,92,61,160,74,140,118,239,208,195,200,
160,90,56,216,69,25,23,23,21,76,154,48,70,167,227,113,124,248,112,179,199,227,141,8,66,156,214,103,57,118,232,73,213,193,96,8,148,75,236,182,79,159,50,187,205,42,103,16,243,68,194,2,25,167,226,119,169,
255,72,249,192,1,85,163,70,14,69,225,158,189,181,184,138,106,12,133,33,67,170,205,38,163,226,70,250,252,173,109,110,148,195,178,193,116,148,20,23,14,31,58,176,127,223,138,117,159,126,238,241,250,40,25,
78,36,12,26,216,55,199,97,93,191,241,63,73,101,157,40,254,193,131,250,54,53,185,146,86,128,200,112,220,17,243,114,241,133,103,249,253,193,53,107,215,227,51,182,78,191,190,229,49,30,69,58,160,183,168,120,
212,245,47,45,41,156,56,126,20,218,110,251,106,215,190,154,3,66,52,101,84,48,120,96,95,184,97,59,146,233,99,179,217,104,49,27,51,89,0,16,21,68,85,90,74,56,192,39,153,31,8,247,150,109,59,119,239,169,213,
106,86,86,148,24,244,124,32,16,248,98,203,206,195,13,205,93,124,54,142,171,174,174,26,54,164,122,202,89,19,86,125,240,175,64,32,68,201,112,194,0,130,238,245,250,82,49,129,8,19,36,67,111,208,165,18,95,
226,126,76,61,103,146,219,221,241,225,199,159,197,85,176,217,44,170,154,205,96,169,71,86,122,211,22,133,44,102,211,169,99,135,163,228,211,13,95,198,197,36,113,224,121,30,213,88,86,78,113,150,85,36,59,
147,37,41,89,35,3,142,162,109,109,29,57,14,219,144,193,253,54,108,250,178,161,177,69,171,86,82,236,28,61,106,8,152,240,209,39,155,225,20,197,79,136,36,237,218,189,63,224,15,140,62,101,232,164,9,163,62,
248,112,35,93,77,58,97,0,39,39,246,73,39,245,94,160,174,83,45,228,227,148,207,31,24,122,210,0,150,229,18,153,64,68,60,77,243,174,21,101,117,93,232,8,25,198,140,30,134,63,55,109,222,150,158,9,164,41,89,
80,74,65,87,41,26,21,51,156,10,82,83,86,239,171,160,32,119,194,169,35,183,108,221,21,59,63,44,203,140,26,113,18,206,174,91,255,159,68,38,104,56,88,223,116,184,161,5,46,98,69,121,49,37,195,9,131,104,20,
126,14,151,86,95,66,212,162,114,138,116,12,191,63,144,155,99,171,172,40,94,179,118,99,106,17,7,27,196,12,7,67,100,58,55,199,14,223,166,185,165,181,177,201,149,113,67,49,149,243,131,179,153,184,73,96,108,
84,245,196,200,193,176,33,3,14,28,108,168,61,112,56,182,14,60,55,184,79,7,15,53,198,185,130,137,216,241,245,62,116,130,224,129,146,225,132,1,204,125,65,190,35,125,96,171,120,47,114,42,203,0,233,145,225,
58,71,34,66,154,230,114,102,111,136,73,220,170,58,229,197,56,216,189,167,46,195,187,80,70,152,130,12,144,236,76,221,36,181,38,67,222,50,138,81,175,207,183,115,87,77,92,157,178,82,39,78,237,138,137,31,
82,1,108,1,12,6,158,146,225,132,193,206,93,251,241,244,7,85,247,73,183,200,35,138,169,164,89,143,56,50,24,106,110,105,79,237,252,40,186,57,163,116,9,37,102,16,201,187,179,252,60,7,104,214,225,201,108,
53,70,109,152,202,248,168,34,46,102,18,193,119,214,60,98,79,118,239,57,16,87,129,101,89,187,205,66,172,135,209,104,72,255,207,96,208,123,125,129,140,130,37,26,64,247,16,184,90,59,14,214,55,150,22,23,216,
109,166,189,53,245,29,30,127,178,152,65,72,109,25,4,229,101,92,90,195,130,58,153,200,132,234,80,9,130,16,81,229,50,234,243,5,51,188,5,213,197,23,68,49,154,114,133,42,42,100,146,77,2,46,160,166,54,146,
68,118,25,13,122,82,225,212,49,39,101,236,133,10,148,12,39,18,246,238,171,135,228,245,171,42,29,122,82,95,191,63,84,119,176,49,150,18,157,1,180,156,42,128,78,175,245,229,140,3,104,210,155,32,136,60,207,
225,192,127,44,139,146,105,2,104,53,0,200,44,128,238,172,137,0,9,7,44,195,38,44,76,169,3,243,7,91,90,59,50,236,80,18,101,74,134,19,12,141,77,109,45,46,119,105,73,126,89,73,193,224,129,21,237,110,239,222,
154,195,68,155,202,105,157,254,52,206,186,166,239,213,5,211,76,99,6,136,15,188,17,45,120,248,95,196,12,234,130,169,156,161,155,20,85,239,88,189,229,132,38,228,94,60,94,127,67,99,43,147,221,232,229,137,
122,208,172,135,234,93,159,127,177,187,254,176,203,110,51,15,174,174,136,177,12,233,2,232,104,119,82,155,233,106,82,231,133,212,37,206,232,177,228,140,203,234,48,82,173,38,41,189,101,162,159,197,206,213,
36,114,203,114,194,45,195,106,161,92,167,163,95,0,206,142,172,85,184,67,245,13,173,251,235,154,12,6,62,63,207,118,148,12,41,223,51,68,187,73,181,80,155,103,22,51,48,100,13,148,44,230,26,244,199,176,14,
163,94,34,154,58,18,200,204,50,144,69,216,163,100,144,19,200,160,144,206,104,208,81,50,100,145,62,104,119,251,240,220,9,25,36,37,55,65,76,245,158,33,205,50,142,166,110,81,133,203,64,207,43,29,137,34,169,
23,12,133,209,130,164,36,101,102,214,68,41,69,204,32,168,47,242,216,12,6,112,228,149,159,220,185,128,150,140,63,30,111,0,100,209,235,121,74,134,44,66,192,31,36,162,40,73,233,222,51,116,27,51,168,18,22,
53,26,187,151,30,171,197,168,229,38,181,183,251,112,156,151,99,206,112,57,73,137,49,82,112,50,20,10,227,108,38,235,253,22,139,158,188,145,72,21,51,48,202,226,155,7,167,138,156,118,74,134,44,130,168,45,
186,171,106,50,149,155,161,38,183,137,233,87,147,252,254,16,11,109,154,86,205,67,113,151,149,56,180,222,218,59,148,21,250,220,28,51,207,101,20,58,164,121,19,226,247,131,12,98,142,195,148,190,135,130,124,
171,78,201,98,18,59,3,229,228,150,193,231,15,135,35,130,197,172,55,155,244,148,12,217,2,131,142,13,133,34,154,51,157,74,40,165,12,94,168,181,182,251,81,173,200,105,77,83,167,178,52,71,34,76,80,69,16,189,
186,90,125,40,1,67,186,101,3,100,87,29,97,242,179,161,112,52,18,17,76,6,62,141,248,218,109,198,92,187,81,136,8,82,39,255,165,20,100,0,14,55,116,40,3,43,182,27,187,179,54,58,158,43,118,218,40,25,78,24,
148,22,219,29,118,99,92,161,205,106,64,20,219,230,14,30,241,185,37,201,100,210,37,234,114,142,99,21,42,116,71,134,64,80,8,132,4,189,158,43,44,176,36,186,238,240,191,43,74,29,28,207,30,106,240,196,190,
43,104,239,8,122,253,97,158,103,203,74,29,70,99,202,152,21,113,54,132,54,44,192,189,129,241,137,127,70,156,202,225,166,22,31,198,89,92,104,77,202,7,24,141,130,60,179,171,61,208,214,17,20,213,123,65,135,
202,139,149,20,100,8,71,162,205,173,126,84,192,212,217,173,134,20,134,142,117,216,140,21,101,14,179,185,119,70,219,124,113,113,89,239,187,171,28,155,193,98,210,193,165,38,143,30,174,2,152,144,231,48,66,
161,182,119,132,72,204,160,215,177,248,7,73,194,51,134,192,153,140,186,28,187,1,2,228,15,8,54,139,14,66,227,241,69,186,229,131,217,200,67,149,66,68,160,47,33,226,240,154,204,38,165,31,92,11,12,105,104,
246,69,4,49,199,166,135,144,249,2,71,222,218,162,127,232,123,163,129,179,89,244,102,180,227,57,180,197,0,64,0,180,133,32,58,243,205,86,139,30,87,143,70,37,244,143,106,140,154,179,141,219,193,113,97,190,
89,225,73,68,84,95,250,73,232,199,106,214,153,148,235,179,248,159,212,113,230,153,209,16,23,194,205,42,243,160,231,58,188,17,92,194,98,226,65,96,33,154,156,231,145,136,18,220,152,140,71,134,65,238,72,
25,155,158,83,74,108,6,103,158,9,103,113,217,150,214,64,52,218,11,119,238,232,157,20,175,111,242,229,216,141,118,171,222,152,139,135,39,179,170,54,13,132,162,174,182,163,217,16,174,246,96,65,174,25,79,
23,178,27,235,126,68,69,89,221,71,38,147,247,89,114,67,179,63,215,97,132,236,90,204,58,75,140,190,12,134,192,186,48,228,85,177,51,162,20,39,127,173,238,16,6,3,129,131,152,218,19,20,63,234,123,253,2,33,
155,71,199,217,172,122,135,237,232,8,49,46,4,207,71,86,129,124,240,149,164,92,187,1,130,174,143,169,3,182,180,185,67,132,126,106,26,149,212,185,102,144,106,201,160,51,120,8,8,161,136,232,80,85,73,220,
29,169,230,84,242,249,5,175,63,210,91,189,232,94,251,29,104,10,10,26,51,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,
50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,80,50,80,80,244,116,244,208,111,186,149,72,226,63,118,109,127,189,180,98,113,110,190,86,56,76,16,158,222,245,213,11,21,85,177,133,192,75,251,247,14,245,186,
181,63,119,216,115,23,84,84,109,215,31,253,102,240,178,61,59,241,57,125,224,16,124,46,104,110,156,210,220,112,221,224,225,90,133,69,135,15,157,220,209,246,195,193,195,26,185,35,223,133,223,178,245,243,
216,254,63,114,150,204,41,171,32,3,88,186,51,254,23,13,231,85,171,221,238,221,25,224,248,137,195,79,209,202,55,124,245,133,69,18,113,118,185,69,217,52,96,110,107,203,140,134,67,22,117,235,151,205,121,
206,121,229,149,218,229,180,97,20,135,67,87,245,171,214,74,48,12,173,57,25,249,197,141,135,166,14,63,69,107,136,241,204,59,84,71,238,221,165,55,44,170,26,160,85,214,250,60,203,213,24,91,130,201,193,37,
80,62,190,173,69,155,4,140,109,86,125,221,77,131,134,159,28,10,92,127,160,203,134,245,75,203,171,238,43,40,188,56,224,199,13,206,26,50,82,41,233,58,3,117,102,235,237,125,171,209,207,141,238,182,184,182,
192,200,17,99,73,231,177,245,151,148,247,137,27,39,37,67,74,224,25,47,172,221,235,20,226,191,94,136,7,111,73,177,143,144,38,175,96,209,83,251,118,63,188,119,231,148,33,35,200,169,201,161,144,53,42,160,
55,28,172,51,153,30,117,22,78,108,109,190,165,177,254,186,202,190,56,139,199,12,113,121,160,223,160,56,209,124,178,79,127,66,57,180,154,191,127,247,34,134,33,253,3,144,137,88,166,145,78,240,137,177,253,
200,235,121,209,238,32,173,98,135,10,57,198,69,9,141,201,221,129,234,177,244,203,4,224,48,36,254,218,246,54,72,167,54,33,68,224,136,64,67,94,107,18,198,166,205,76,44,238,45,41,253,71,71,27,153,4,12,21,
194,10,161,199,228,128,12,184,132,54,117,68,190,87,56,114,19,249,79,164,153,204,182,54,153,177,109,99,17,91,14,30,38,29,39,117,147,146,51,1,186,167,217,20,191,211,22,30,182,53,131,157,208,33,94,63,27,
48,200,34,42,114,73,74,166,122,220,27,10,138,160,17,103,182,185,72,5,104,208,113,237,46,82,97,78,221,62,136,11,145,224,164,128,136,160,62,8,83,210,221,206,170,208,121,39,5,3,218,69,241,167,118,71,208,
232,232,132,176,11,66,64,108,20,196,58,243,105,193,104,91,140,166,213,69,165,231,53,55,104,133,176,9,239,56,139,200,49,24,2,211,52,205,227,206,164,55,76,194,252,126,131,48,9,152,213,219,14,238,199,228,
104,4,139,5,25,112,127,33,146,166,159,79,243,157,253,124,158,204,111,4,204,84,172,83,123,79,220,228,184,199,145,161,149,231,96,175,137,166,137,101,8,124,140,7,42,251,101,248,164,107,173,118,77,46,161,
80,87,57,114,215,229,229,195,49,32,2,13,173,6,2,252,223,161,90,40,108,162,38,211,119,72,180,224,57,254,110,126,24,28,98,49,165,83,82,97,7,240,39,57,134,128,66,53,198,57,6,224,231,105,109,174,204,167,229,
76,119,27,58,132,146,134,137,35,134,136,184,91,191,168,219,7,93,75,74,224,164,37,149,233,84,36,95,94,82,1,155,80,24,14,193,171,76,90,7,84,193,103,141,222,144,70,115,225,46,246,219,28,199,244,136,191,116,
228,140,232,104,239,129,100,232,113,110,18,68,185,209,196,39,58,72,111,149,86,224,249,101,222,143,77,221,109,151,40,84,52,220,99,208,95,47,137,151,121,58,136,182,35,126,2,20,118,162,131,148,10,142,206,
61,128,227,156,230,145,157,59,42,172,183,218,103,73,34,188,14,28,67,100,149,63,59,235,52,155,226,127,120,220,203,243,137,134,14,154,62,46,92,209,34,40,104,113,18,102,192,224,76,113,183,19,106,65,101,204,
181,88,33,142,48,92,11,84,110,196,41,17,0,167,182,196,132,13,36,6,32,199,155,108,246,139,25,6,243,19,235,177,96,228,218,24,96,106,224,46,226,108,156,113,128,159,179,32,198,30,62,84,82,158,216,86,139,79,
146,78,166,181,71,254,220,201,9,176,85,12,113,144,50,215,121,100,174,125,86,27,81,168,85,65,191,246,132,38,183,183,17,50,64,170,136,203,145,198,65,138,149,69,124,122,120,93,170,152,129,160,141,231,33,
142,83,85,71,5,7,248,83,59,85,20,10,196,85,182,139,162,95,23,223,73,156,244,104,195,38,14,213,170,175,190,32,127,66,151,151,148,148,18,14,43,211,162,206,12,252,251,171,15,213,129,27,113,19,149,52,102,
32,55,5,23,17,162,140,249,193,12,107,173,82,249,253,137,49,3,137,140,17,13,107,179,145,73,219,84,247,78,221,164,140,48,202,211,65,4,154,8,7,66,58,60,248,244,178,139,250,95,155,45,68,161,66,118,161,188,
241,15,70,0,170,23,150,253,88,7,64,28,164,15,172,221,47,128,236,177,88,225,32,193,7,216,19,227,20,197,249,54,137,126,84,183,128,238,135,134,38,119,49,117,248,41,22,213,196,161,67,76,136,22,201,128,228,
155,242,11,75,211,255,250,86,12,126,219,216,128,200,10,241,21,108,5,100,154,24,180,99,2,248,3,166,221,81,179,251,88,167,20,243,179,53,39,143,146,225,155,0,202,146,200,1,113,72,180,117,158,84,76,120,106,
223,110,40,60,168,124,40,84,60,45,77,111,161,4,170,43,195,16,83,3,164,4,209,5,220,235,76,188,169,231,242,242,33,247,160,34,14,180,66,12,0,205,161,134,9,31,32,58,100,169,55,182,78,26,160,21,12,157,118,
203,24,6,110,10,38,14,186,25,183,131,155,37,178,136,106,8,138,118,91,44,25,134,227,112,159,30,171,26,128,222,32,211,152,174,249,251,119,127,131,71,67,194,173,91,26,235,51,111,130,8,7,150,237,165,188,2,
234,38,125,91,136,245,140,225,162,16,47,22,94,208,162,170,1,177,213,136,107,148,137,199,5,251,163,173,154,67,148,231,21,149,28,117,187,187,198,12,208,172,59,204,22,77,82,225,234,144,131,130,152,45,86,
209,124,46,207,67,137,46,232,124,207,240,80,73,117,134,177,10,34,4,12,59,182,100,77,110,30,188,118,112,224,151,213,67,16,77,105,227,193,72,18,213,68,92,204,64,220,188,95,116,93,67,187,189,111,245,211,
187,190,90,208,220,120,216,96,56,214,0,239,133,138,42,76,212,143,212,235,198,197,12,76,231,75,152,216,114,16,239,158,254,131,122,224,186,42,67,119,212,163,160,56,145,220,36,10,10,74,6,10,10,74,6,10,10,
74,6,10,10,74,6,10,10,74,6,10,10,74,6,10,10,74,6,10,10,74,6,10,10,74,6,10,10,74,6,10,10,74,6,10,10,74,6,10,10,74,6,10,10,74,6,10,10,74,6,10,10,74,6,10,10,74,6,10,10,74,134,158,143,69,139,30,216,178,101,
179,246,111,205,154,247,46,190,248,66,148,227,96,238,220,91,143,231,72,200,21,135,13,27,130,97,144,49,36,14,245,165,151,158,79,218,54,77,171,111,12,12,6,87,252,102,83,154,106,156,218,172,62,253,244,227,
55,222,248,179,94,67,6,93,175,185,147,143,62,90,59,103,206,109,218,131,156,51,231,230,229,203,223,253,174,6,179,125,251,206,145,35,199,245,132,105,41,45,45,249,102,13,181,201,76,196,148,41,23,144,131,
126,253,250,254,231,63,95,80,203,208,163,177,102,205,71,78,103,151,93,137,160,110,161,207,160,119,55,108,248,152,168,94,168,97,104,62,205,146,76,158,60,137,232,209,184,18,84,91,182,236,117,82,152,104,
100,74,74,138,180,78,98,117,100,172,142,95,176,224,15,164,66,156,134,70,125,92,5,53,227,250,156,61,251,167,113,151,131,2,38,37,154,170,70,67,114,59,56,149,102,132,248,243,172,179,206,196,63,210,48,182,
31,140,60,246,46,80,72,238,23,192,89,98,79,72,171,196,57,33,150,1,103,49,201,215,95,63,251,56,219,94,74,134,99,195,172,89,87,186,92,174,216,135,125,199,29,115,183,109,251,10,218,250,133,23,254,177,96,
193,93,16,160,217,179,127,98,181,90,81,50,117,234,69,168,115,237,181,87,163,26,26,62,249,228,18,20,238,223,95,123,219,109,202,51,158,55,239,118,124,162,206,77,55,253,106,198,140,233,113,94,1,90,245,237,
91,53,107,214,53,75,151,254,19,98,17,43,97,26,9,47,190,120,218,3,15,60,56,111,222,31,32,148,63,250,209,149,164,28,82,117,245,213,63,156,63,255,110,216,144,184,38,126,191,31,3,64,135,24,12,58,84,157,174,
161,184,58,198,128,1,107,140,242,251,3,168,118,221,117,55,164,25,225,125,247,61,8,131,137,127,87,93,117,13,26,66,145,99,168,164,31,76,130,86,173,177,177,121,243,230,207,167,78,61,151,204,213,208,161,67,
214,175,223,160,77,93,226,156,16,160,79,76,50,78,225,42,212,77,234,89,128,168,65,123,145,227,186,186,3,144,51,237,212,57,231,156,109,177,88,238,189,87,17,163,197,139,159,154,57,243,210,105,211,46,212,
220,0,136,2,120,82,92,92,220,41,166,167,227,19,66,166,73,6,68,25,117,240,111,211,166,207,70,143,62,37,246,162,167,157,54,9,133,16,104,252,75,42,19,227,199,143,131,196,188,248,226,63,113,76,220,182,177,
99,199,20,21,21,222,127,255,194,183,222,90,182,110,221,250,196,38,239,188,163,84,91,177,226,93,72,225,184,113,99,113,137,53,107,62,36,53,87,174,92,5,10,145,106,159,126,186,62,147,17,198,140,228,84,92,
145,112,239,149,87,94,133,88,163,45,154,144,179,240,118,208,243,188,121,119,129,222,24,48,46,135,89,210,218,198,206,9,13,160,79,140,152,1,218,139,252,155,62,125,102,172,156,57,28,202,110,89,171,86,189,
67,204,189,230,65,193,129,129,190,132,209,7,145,8,43,160,191,161,53,161,227,81,13,103,11,10,148,141,223,32,55,164,33,170,89,187,110,50,105,181,90,26,26,26,211,140,202,102,179,53,55,183,196,21,98,0,181,
181,117,231,157,119,78,210,38,29,29,158,184,75,192,182,144,1,96,96,150,174,123,230,117,59,66,13,104,232,245,122,99,47,65,218,18,188,241,198,91,168,0,59,54,106,212,200,13,27,54,198,26,141,184,57,233,197,
100,208,49,89,0,143,199,19,8,4,38,78,60,35,182,16,46,47,158,113,77,77,205,162,69,143,92,114,201,197,68,134,160,188,137,254,198,83,135,8,174,90,245,62,142,225,126,36,85,225,196,87,73,31,161,250,124,190,
147,79,30,30,87,184,99,199,206,91,110,249,245,155,111,190,10,151,6,150,42,253,224,113,137,213,171,255,153,202,21,105,109,109,77,63,66,13,152,1,187,221,78,142,115,114,28,90,219,88,79,9,225,74,85,85,159,
197,139,159,136,109,152,116,78,168,101,56,81,241,193,7,31,146,37,38,226,196,67,195,193,119,135,175,178,117,235,86,56,75,149,149,21,240,70,180,168,151,248,220,95,127,189,11,159,123,246,236,133,224,18,143,
2,103,97,67,226,84,35,124,21,184,31,56,133,14,99,99,80,13,155,54,41,134,8,103,81,7,177,187,22,107,66,248,224,180,196,186,34,169,128,75,192,134,144,158,65,96,196,202,177,103,209,79,250,17,18,235,164,142,
228,51,244,131,58,168,121,197,21,151,163,149,230,35,105,158,18,152,64,124,164,184,149,128,184,57,137,109,165,17,140,146,225,196,0,158,250,61,247,220,7,13,173,26,250,187,16,155,194,137,127,253,245,55,137,
251,113,254,249,83,225,98,33,14,134,63,77,226,96,20,66,188,16,26,162,225,130,5,11,137,139,181,116,233,243,112,120,224,85,199,246,252,220,115,47,192,225,193,41,212,71,219,68,245,172,170,213,21,234,217,
231,81,51,86,193,163,45,120,210,237,91,5,52,65,228,250,232,163,127,197,168,96,190,110,191,125,94,92,133,244,35,252,252,243,127,131,234,96,17,104,143,126,80,7,53,17,163,195,52,197,245,3,79,9,159,177,62,
18,89,35,78,156,19,237,44,42,35,176,233,53,171,73,116,175,85,10,138,108,178,12,20,20,148,12,20,20,148,12,20,20,148,12,20,20,223,24,124,113,113,25,157,133,255,33,214,172,121,175,180,180,196,237,118,127,
240,193,123,245,245,245,187,119,239,201,188,213,167,159,110,120,250,233,199,43,42,202,55,111,254,247,177,94,119,216,176,33,199,116,69,138,68,232,232,20,124,27,56,214,172,213,255,62,15,180,231,228,201,
82,55,233,187,196,220,185,183,146,87,81,36,251,18,202,149,81,51,225,72,122,38,121,9,69,94,138,145,21,113,45,13,147,228,213,161,237,134,13,31,147,174,112,160,229,210,145,154,40,137,205,57,141,205,242,215,
142,113,45,146,55,138,79,146,46,17,155,181,26,151,43,138,254,181,203,225,79,146,69,155,152,7,138,66,45,23,21,7,228,157,26,233,132,20,162,2,249,22,7,73,125,213,174,136,66,212,39,109,181,172,216,196,204,
211,88,36,230,213,38,230,183,162,161,118,105,244,118,227,141,63,211,134,65,201,208,131,176,126,253,134,170,170,62,120,102,231,156,115,54,81,174,248,156,52,105,98,93,221,129,47,191,220,50,98,132,242,203,
196,39,157,52,152,233,76,238,31,56,176,122,249,242,21,129,64,0,245,209,10,109,33,193,16,26,72,9,14,200,235,106,34,208,179,102,93,249,216,99,143,147,28,210,179,206,58,51,81,140,8,110,187,237,86,146,106,
186,114,229,170,184,220,161,196,92,81,146,180,71,40,71,6,172,125,239,34,54,15,116,206,156,155,183,110,221,138,62,111,186,233,87,24,225,181,215,94,77,234,144,11,125,244,209,218,59,238,152,11,143,136,164,
220,94,117,213,21,177,23,69,253,37,75,158,209,78,165,201,60,101,146,229,213,166,202,111,45,42,42,68,9,250,153,49,99,250,160,65,3,209,27,201,224,160,100,232,65,88,183,110,61,145,236,242,242,114,16,0,202,
21,143,31,18,255,233,167,235,53,158,148,148,148,224,84,255,254,253,85,41,31,186,106,213,251,219,183,239,0,67,80,13,109,33,130,167,156,50,18,252,193,211,213,222,176,18,199,131,200,238,138,21,138,188,230,
230,230,38,117,214,181,124,158,197,139,159,66,111,177,103,199,143,63,117,245,234,15,208,21,186,125,229,149,87,199,141,27,139,193,108,218,244,217,153,103,42,137,82,248,196,113,42,199,137,188,75,198,221,
197,166,163,191,253,246,114,124,146,192,0,151,67,183,205,205,45,36,225,66,195,142,29,59,65,48,146,141,59,96,192,145,223,59,157,60,249,116,168,243,235,174,187,97,250,244,153,93,71,120,36,175,22,77,200,
253,38,29,51,106,162,16,37,31,127,188,14,132,127,253,245,55,25,53,53,195,106,181,80,50,244,52,31,253,136,100,67,155,66,28,47,187,108,6,30,33,152,160,241,4,4,0,55,32,181,36,205,6,229,120,144,48,26,32,64,
75,139,11,250,18,205,79,59,109,82,92,226,13,241,58,224,51,44,93,250,124,170,75,247,239,223,15,159,109,109,237,228,207,218,218,186,216,179,73,115,69,63,255,252,223,24,143,234,219,12,197,113,170,128,24,
151,38,142,80,220,23,149,8,226,88,151,6,233,51,79,19,243,106,211,231,183,18,104,247,75,99,134,30,135,181,107,63,134,100,67,182,190,254,122,23,136,49,115,230,165,144,21,146,41,180,102,205,135,23,93,116,
33,30,240,115,207,189,128,66,156,66,5,70,77,13,2,55,70,141,26,9,254,128,3,19,39,78,192,159,218,151,90,8,19,136,135,208,216,216,8,95,37,241,162,68,31,195,152,224,51,63,63,79,243,37,226,68,54,49,87,148,
88,155,133,11,23,224,147,28,199,1,154,248,233,167,159,32,95,177,128,187,146,185,220,167,2,180,62,12,2,20,63,252,67,56,69,177,254,158,207,231,203,100,204,52,128,62,97,0,71,159,184,254,56,128,100,67,149,
106,238,7,232,49,116,232,16,248,72,80,144,160,1,78,145,229,26,252,137,66,156,66,5,112,0,229,113,9,155,149,149,21,16,139,37,75,254,246,232,163,143,107,126,54,68,167,111,223,42,18,96,128,123,76,103,222,
232,141,55,254,156,81,191,201,25,167,197,83,229,138,162,28,3,78,234,35,65,16,161,137,113,47,239,188,243,238,156,57,183,205,158,253,147,184,56,228,27,172,186,166,201,60,77,204,171,237,54,191,149,146,161,
71,131,72,54,100,151,136,38,163,102,107,106,60,193,39,60,107,77,8,72,122,38,0,155,192,168,95,139,35,28,32,9,155,36,199,27,162,128,106,240,160,72,154,39,241,190,192,28,16,131,20,206,159,127,39,177,48,234,
106,204,66,56,33,36,1,54,78,139,167,202,21,37,195,75,244,145,72,30,232,180,105,23,34,68,38,95,217,129,125,192,29,193,3,252,111,214,121,19,51,79,33,244,107,214,188,199,36,203,171,237,54,191,181,183,130,
102,173,82,80,244,46,203,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,112,188,145,184,217,232,228,201,147,200,10,76,122,124,27,91,166,102,126,245,255,121,91,74,6,138,36,72,220,244,229,68,185,250,
119,59,114,74,134,158,133,84,73,160,218,246,221,36,161,85,219,59,117,195,134,143,73,34,83,108,15,215,95,63,219,233,116,146,125,251,98,55,111,77,186,19,117,101,101,5,185,34,57,155,152,238,26,155,190,202,
36,108,24,174,245,79,122,136,189,58,25,57,57,75,210,81,181,221,99,147,110,240,154,216,54,174,62,217,73,141,220,11,147,108,107,87,74,134,94,133,84,73,160,197,197,197,177,27,155,222,116,211,13,69,69,133,
179,102,93,243,155,223,220,94,88,216,229,93,242,242,229,239,62,249,228,18,151,203,133,250,16,163,5,11,238,90,189,250,3,178,121,43,68,45,49,161,117,242,228,211,167,79,159,137,38,56,155,184,187,48,211,153,
136,65,210,87,209,28,194,250,220,115,47,104,103,103,207,254,41,217,28,150,188,47,219,188,249,115,237,234,164,194,134,13,27,113,76,50,8,19,153,31,155,136,154,147,227,136,107,155,8,139,197,130,187,158,56,
241,140,84,91,187,82,50,244,30,164,74,2,133,168,49,157,73,169,227,198,141,157,56,113,2,73,216,68,53,237,5,115,34,166,77,187,48,16,8,144,77,144,22,47,126,170,174,238,0,217,181,55,22,90,30,43,206,162,126,
210,126,214,172,249,112,236,216,49,140,178,109,240,185,137,89,15,48,77,16,77,92,5,66,156,152,16,177,105,211,230,84,195,75,76,68,237,118,126,106,107,235,200,54,172,218,214,174,184,226,202,149,171,198,143,
63,149,146,161,183,161,219,36,80,2,156,210,18,54,227,50,88,227,16,155,118,225,247,251,227,146,168,153,152,188,78,156,77,213,201,170,85,239,19,105,155,50,229,236,117,235,254,21,123,234,246,219,231,53,55,
55,195,94,37,238,32,223,45,146,110,240,154,33,210,111,237,74,201,112,194,35,243,36,80,104,113,45,97,51,253,38,170,177,82,2,119,194,231,243,197,85,208,242,88,19,119,2,214,152,3,5,220,210,226,130,127,143,
222,180,140,41,2,232,233,235,174,187,1,122,29,30,78,223,190,85,154,95,151,6,218,21,19,19,81,211,215,143,133,223,31,128,181,212,182,112,206,170,175,146,102,5,25,50,79,2,37,27,155,146,164,212,164,30,2,105,
11,183,10,7,36,222,69,116,171,230,159,198,59,45,90,30,43,206,162,126,98,186,171,118,69,104,226,216,47,21,105,241,52,241,215,63,254,120,29,62,235,235,235,227,24,72,64,146,171,225,23,225,83,219,185,53,233,
6,175,164,109,210,250,137,51,144,106,107,87,74,134,19,30,208,178,25,38,129,194,65,135,131,177,116,233,243,247,223,191,16,58,59,238,44,145,75,116,130,14,17,155,66,104,112,124,245,213,63,132,242,78,252,
201,44,112,15,146,68,206,162,126,210,116,87,70,253,206,42,163,110,250,27,215,124,209,162,71,200,230,176,104,178,105,211,103,240,251,181,171,199,86,3,133,208,63,113,108,98,99,253,184,68,84,173,109,210,
250,113,51,144,126,107,215,94,12,154,181,250,29,3,106,123,198,140,233,151,94,122,121,150,124,103,160,39,131,110,21,243,93,2,190,16,252,25,24,25,202,4,106,25,40,40,104,204,64,65,65,201,64,65,65,201,64,
65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,145,197,160,223,116,75,2,65,
16,194,225,144,24,21,56,142,229,241,63,203,254,175,122,150,100,134,147,197,161,178,108,144,165,232,241,186,29,86,249,199,70,24,214,207,177,29,28,231,213,233,4,78,103,226,245,122,142,170,66,74,134,20,240,
251,125,66,56,212,183,111,159,49,99,70,15,29,54,116,64,255,1,5,78,167,217,98,230,226,132,70,86,229,139,28,48,157,199,73,43,36,64,100,152,71,239,187,239,140,191,63,123,90,78,81,7,159,25,199,18,123,75,221,
127,202,30,212,143,48,203,248,25,182,149,99,106,56,118,43,207,110,54,26,58,244,166,92,189,145,62,122,74,134,163,104,107,107,41,43,41,190,250,135,63,57,111,234,121,35,70,142,252,86,175,85,88,88,116,56,
42,180,177,140,39,115,197,158,57,79,146,158,98,143,252,197,201,140,137,145,171,163,242,40,134,153,201,176,117,145,208,6,93,248,109,131,190,214,100,206,215,155,168,24,100,59,25,58,58,218,139,156,121,127,
126,224,222,31,92,121,229,241,185,98,48,24,204,87,77,132,248,223,248,61,221,242,36,217,41,145,101,4,12,128,101,201,15,217,218,37,233,71,33,102,186,32,45,143,8,79,154,195,140,209,106,230,179,90,30,178,
215,107,148,101,185,169,225,208,13,63,191,238,179,207,55,31,55,38,244,16,168,81,4,227,99,217,61,60,235,145,153,171,195,226,63,188,161,147,125,238,86,33,68,45,67,214,33,18,9,243,172,248,238,123,43,70,143,
25,147,229,186,16,129,196,215,44,91,34,74,143,250,165,135,36,239,243,22,169,216,104,161,100,200,22,132,66,129,178,98,231,59,43,223,251,110,118,213,101,123,220,132,240,12,211,200,177,62,153,153,27,136,
230,202,254,135,25,185,216,104,165,100,200,6,155,16,41,47,45,250,112,237,71,52,94,140,227,131,159,101,246,113,236,207,67,209,32,19,248,27,199,59,179,47,164,206,186,152,129,149,35,171,63,120,255,59,13,
86,122,180,203,84,195,178,55,135,162,103,249,125,1,49,74,201,208,155,81,127,168,118,217,242,229,58,29,93,80,78,41,13,65,150,113,49,204,111,67,81,83,192,75,201,208,107,225,243,121,126,63,239,119,213,41,
246,223,166,208,4,194,197,177,78,81,190,57,44,180,132,3,148,12,189,19,185,14,203,47,111,153,67,197,61,147,248,161,150,99,207,23,164,113,193,128,36,203,217,115,227,217,226,48,116,116,180,63,248,192,189,
61,35,106,81,82,157,194,174,250,8,99,52,149,149,73,81,65,41,225,184,64,67,157,222,228,144,66,202,74,191,62,47,47,212,222,148,32,163,58,99,89,165,44,70,89,158,15,30,174,229,89,163,177,84,105,206,234,244,
162,199,19,246,181,154,242,138,57,147,73,22,69,181,67,62,216,80,203,49,58,115,105,165,191,97,191,114,80,86,233,63,140,3,131,169,172,92,185,40,6,162,211,137,94,95,216,235,50,229,151,242,38,83,164,165,37,
44,248,48,54,147,189,64,182,219,185,136,112,137,32,205,23,66,121,6,51,37,67,175,66,142,205,114,217,247,103,254,207,187,13,109,217,234,123,115,153,115,254,60,201,239,111,186,229,182,194,187,126,175,75,
251,227,87,74,252,44,70,37,134,41,188,230,167,236,142,157,190,61,187,116,38,11,66,106,161,189,189,228,210,43,132,86,151,194,21,142,11,238,175,45,191,248,162,206,104,91,102,212,76,193,72,99,147,103,211,
70,206,104,22,218,91,75,46,191,42,220,208,232,221,250,165,206,100,21,253,30,99,85,101,193,168,139,91,151,173,144,130,33,214,160,71,23,225,150,198,162,233,151,201,81,177,245,211,127,21,95,122,5,132,190,
109,243,166,146,153,63,8,214,236,247,237,218,105,200,201,7,103,68,191,207,80,90,226,156,126,81,199,134,77,254,3,181,150,210,178,62,255,247,27,209,235,109,248,251,179,114,192,223,160,55,142,19,165,62,225,
160,151,146,161,55,65,16,34,151,94,114,209,255,48,249,84,131,228,241,10,123,149,223,65,132,182,54,14,30,196,26,13,221,183,145,101,40,255,170,167,22,231,111,219,246,233,184,177,118,147,89,244,120,57,131,
97,248,27,47,239,188,250,39,133,63,248,190,28,137,28,122,248,177,33,207,61,19,215,14,114,252,175,1,253,77,150,124,49,232,31,246,202,210,214,119,87,110,190,232,2,187,217,22,238,104,205,59,123,202,208,23,
255,190,243,218,159,30,120,254,111,246,210,170,72,91,43,103,52,157,252,246,235,109,171,86,215,188,251,246,228,103,151,248,183,108,219,255,189,211,79,127,226,49,89,16,62,42,43,213,25,45,172,94,31,233,112,
229,77,57,123,200,139,207,110,172,30,34,71,133,209,159,174,53,86,86,42,254,228,25,147,191,152,49,157,41,40,45,103,185,241,130,184,66,138,154,184,172,144,147,172,136,25,124,94,207,153,103,159,253,173,184,
60,6,3,151,155,171,28,152,76,249,183,206,225,243,243,187,111,2,175,6,67,122,234,25,219,41,163,76,188,73,10,132,132,80,71,222,121,231,224,84,211,63,95,226,244,122,222,110,243,237,252,106,255,188,249,187,
230,204,233,216,176,17,226,187,239,215,115,107,238,184,115,255,157,243,13,182,92,33,208,97,27,114,50,42,91,6,13,212,131,89,225,8,40,30,117,187,81,210,239,238,249,112,247,37,175,55,24,246,245,189,253,183,
40,241,111,219,129,7,44,180,184,80,1,7,222,255,124,1,83,80,122,254,116,127,123,19,216,203,50,156,28,17,24,73,10,237,175,235,255,235,223,128,9,95,93,254,131,131,15,46,178,14,27,106,176,228,48,162,20,102,
152,97,162,44,168,62,21,181,12,189,4,38,163,97,100,138,92,84,57,26,101,255,139,149,86,125,159,62,204,177,134,152,178,140,235,53,189,250,198,128,155,111,112,140,159,232,94,255,73,20,94,211,165,151,8,173,
173,190,104,8,76,224,205,166,64,115,227,222,63,221,229,99,24,99,65,177,101,240,160,93,15,222,15,81,54,48,172,185,188,159,215,231,134,230,70,55,230,234,1,246,193,35,252,187,119,18,239,95,185,205,62,149,
21,63,158,189,231,217,37,249,133,101,85,191,155,171,94,74,82,29,51,81,22,149,131,104,187,242,107,188,3,31,121,168,105,224,50,145,252,60,41,106,68,34,160,52,44,146,235,237,229,187,95,123,37,231,181,87,
154,150,190,108,44,44,134,19,133,0,162,66,146,77,89,243,194,33,43,200,80,84,84,88,84,212,229,119,148,161,110,253,239,173,10,125,241,165,44,68,164,14,143,245,220,115,108,211,167,161,92,108,113,249,63,252,
200,113,249,76,38,230,59,12,158,151,95,181,76,62,93,87,86,170,252,33,138,45,127,92,16,61,84,207,240,188,174,168,88,150,162,172,89,121,83,11,223,198,251,230,219,182,11,206,231,28,118,34,100,45,127,252,
83,244,192,65,134,231,24,73,182,157,127,158,253,251,151,117,154,6,136,53,227,217,184,94,150,36,231,140,105,45,235,63,130,58,135,187,226,94,171,176,2,118,67,10,71,80,98,118,150,49,174,195,250,130,124,168,
112,171,193,198,153,205,156,209,40,9,17,229,118,102,93,233,223,182,93,151,159,231,188,236,18,247,194,173,168,172,115,56,224,68,129,216,131,151,44,222,245,236,146,126,119,43,63,255,30,216,189,219,88,94,
174,93,84,161,110,65,126,96,231,46,203,144,193,253,111,253,237,158,7,239,53,106,126,1,40,33,68,96,52,112,39,198,220,98,255,182,109,58,152,59,158,15,73,114,190,204,228,139,98,150,188,113,200,146,223,129,
46,142,43,17,155,154,66,219,190,50,79,154,152,119,227,13,142,31,94,213,246,208,195,254,213,31,40,186,179,165,197,179,244,101,120,14,177,149,81,18,85,127,121,54,218,220,114,224,156,11,196,214,214,156,31,
95,155,63,231,151,230,9,167,134,191,222,37,186,148,132,104,57,28,70,53,177,163,67,9,36,220,29,7,46,152,46,54,54,230,252,248,106,84,179,158,115,118,219,95,31,117,253,241,79,157,146,167,76,122,72,8,120,
214,111,116,78,159,6,151,201,214,103,160,161,184,200,245,246,10,78,149,203,52,55,34,122,124,102,187,51,119,242,105,181,243,23,120,54,110,42,185,230,135,157,43,77,28,111,179,238,190,254,23,48,17,99,30,
248,75,217,245,215,237,186,246,58,223,23,91,244,93,127,233,25,142,80,195,115,207,55,60,241,244,128,63,47,52,233,45,240,144,148,208,156,227,16,48,52,61,251,162,227,212,113,85,151,94,225,117,55,233,114,
243,20,93,32,203,24,155,85,150,115,69,145,161,100,232,53,208,126,231,252,168,65,44,47,115,254,238,183,214,115,167,64,223,155,39,140,207,249,241,53,129,79,254,69,98,0,156,98,186,134,218,40,97,205,74,74,
159,235,142,59,77,99,71,151,60,250,176,101,242,105,198,161,67,108,211,46,44,253,235,34,142,100,251,113,156,82,77,15,55,158,105,158,123,135,161,122,64,201,227,143,194,158,160,154,227,202,43,170,214,125,
232,123,231,189,160,202,55,77,83,187,150,45,135,11,4,211,156,115,186,242,163,203,237,171,86,119,27,125,11,161,35,62,82,203,155,111,182,127,184,214,114,210,96,179,189,64,84,41,100,40,42,106,91,251,254,
129,133,15,84,252,250,150,72,115,115,205,243,207,192,143,146,187,202,49,203,113,250,220,220,29,55,220,128,227,65,139,30,10,40,113,63,167,172,165,86,85,213,61,181,88,104,106,30,246,198,203,165,231,158,
239,107,57,196,170,166,68,102,149,119,14,230,172,121,211,144,21,100,72,178,138,196,30,185,241,224,198,77,158,87,94,243,189,243,142,190,127,223,116,211,228,112,136,238,14,252,43,234,250,178,66,104,104,
128,59,17,83,205,6,167,43,122,184,161,248,193,251,226,122,200,251,197,13,222,215,222,80,47,173,12,71,207,26,91,151,189,135,3,71,159,129,57,103,76,14,31,110,240,55,31,226,187,185,13,86,137,46,190,127,89,
164,185,165,93,14,55,62,247,2,202,242,207,159,170,133,183,70,103,89,237,61,11,113,112,248,137,37,97,245,101,197,209,68,40,242,205,79,73,50,245,235,235,134,253,123,253,173,178,27,127,102,103,248,112,253,
97,150,99,225,20,137,140,188,121,252,68,4,205,163,86,191,151,63,230,212,96,115,61,171,57,138,44,37,67,47,130,151,4,139,93,225,95,245,126,195,117,215,251,63,88,35,182,182,201,17,129,229,120,70,243,82,18,
22,97,57,139,57,186,191,150,203,113,36,70,195,177,142,13,103,182,68,106,106,120,167,147,53,198,127,177,216,48,176,154,216,13,70,253,234,179,222,145,235,221,181,53,210,226,170,184,237,22,251,216,209,109,
43,87,73,221,73,29,212,60,158,150,121,80,181,46,55,231,244,149,43,135,191,246,178,98,244,198,142,142,118,14,216,88,89,17,246,181,239,249,213,173,205,175,188,110,81,235,39,234,3,89,150,17,24,236,252,201,
108,28,15,121,248,145,80,237,1,153,97,17,108,152,121,171,183,174,102,211,200,209,40,31,254,207,165,18,34,238,136,178,78,133,81,133,178,134,12,89,17,64,55,54,198,191,205,69,132,208,250,192,95,10,239,186,
211,124,154,226,162,240,22,179,208,162,126,23,82,58,226,70,119,97,130,205,38,249,124,186,62,21,208,250,221,44,20,133,66,250,202,10,201,147,164,26,204,133,178,142,201,168,59,100,40,254,152,62,202,200,45,
175,189,81,113,211,207,197,64,104,255,188,249,124,119,119,33,118,120,44,5,101,150,65,131,56,131,161,112,234,84,82,152,51,105,130,78,89,19,35,190,146,172,231,204,7,31,126,136,55,217,117,169,215,178,224,
140,249,61,174,67,15,61,82,113,203,205,222,237,219,131,181,117,48,2,81,209,111,115,150,183,110,223,82,115,199,239,251,223,243,199,156,193,35,2,123,246,24,11,242,253,28,231,230,248,44,33,67,86,88,134,230,
166,102,151,203,213,37,38,126,233,229,252,57,55,19,38,168,129,169,23,186,95,209,13,165,37,209,131,135,36,207,209,229,147,104,83,115,224,227,117,144,93,190,160,128,53,26,92,119,223,211,101,105,181,162,
60,214,140,160,31,197,44,152,205,173,247,61,24,55,6,247,211,127,179,156,123,182,70,6,8,37,68,172,245,237,229,74,82,185,32,184,215,126,98,48,58,186,9,24,4,95,254,133,83,245,5,249,95,76,58,115,125,69,191,
79,10,139,246,206,185,45,231,244,211,108,6,107,180,221,173,153,53,99,97,25,111,177,164,241,243,113,202,98,118,236,185,237,54,49,16,24,248,208,3,114,36,2,247,201,96,47,16,218,219,44,12,219,240,204,223,
165,136,96,174,238,47,73,97,147,204,180,177,76,27,207,81,50,244,30,4,195,145,173,91,182,116,113,90,134,14,241,190,254,150,28,10,75,193,96,96,221,191,220,127,123,86,168,171,13,111,217,134,216,192,60,113,
252,193,25,223,143,236,221,43,249,3,136,122,93,243,254,32,121,189,68,169,23,46,188,219,247,214,178,230,219,127,39,212,29,144,131,161,240,206,175,155,239,184,51,178,103,47,49,41,209,198,70,8,150,90,237,
143,190,21,239,186,22,44,84,172,65,40,20,218,252,249,161,25,151,195,77,178,93,241,253,46,68,50,216,189,155,255,141,3,223,214,109,225,160,27,246,39,125,192,32,42,1,195,76,161,173,173,105,195,199,161,250,
3,97,87,203,225,167,150,224,140,115,218,52,68,204,177,53,143,242,51,5,39,244,185,121,97,49,188,247,151,183,114,102,179,101,96,117,112,223,222,254,247,254,169,244,167,255,215,198,200,185,103,158,193,25,
244,225,131,135,56,78,249,182,219,33,150,13,242,122,234,38,245,30,88,109,142,181,31,173,61,123,202,20,173,36,255,87,55,183,46,188,191,121,238,111,249,188,124,16,35,239,87,55,41,193,131,186,48,90,112,251,
111,16,19,183,46,88,200,152,77,156,201,156,123,227,245,182,75,47,145,213,197,86,125,159,62,149,239,191,215,242,135,187,92,119,221,205,90,173,176,21,134,254,253,244,103,157,169,72,160,94,111,61,239,92,
34,208,250,202,202,138,55,94,118,221,115,175,178,156,106,208,129,54,150,51,191,7,67,20,231,190,243,14,123,192,117,56,116,240,160,127,219,87,74,192,192,177,178,242,42,160,0,113,174,220,41,201,168,163,203,
201,1,211,164,64,208,192,27,157,211,47,106,126,249,53,69,253,23,151,163,208,223,82,143,8,184,236,23,63,223,119,171,242,138,141,229,121,185,115,81,88,233,170,176,80,215,220,34,145,131,134,70,245,192,137,
120,67,86,195,9,171,189,224,224,51,79,244,91,48,223,80,82,28,246,187,245,121,185,131,159,124,44,247,178,233,197,83,167,250,183,239,116,111,253,220,152,175,188,118,216,193,179,58,74,134,222,4,131,193,176,
124,217,242,63,46,184,251,168,246,52,232,157,127,248,93,180,254,48,34,93,222,89,128,146,220,31,95,163,157,45,248,205,173,208,241,162,203,165,43,43,83,254,62,229,104,87,124,126,94,201,35,139,228,96,80,
108,107,211,105,175,180,212,116,140,188,159,207,62,90,173,208,89,252,208,159,37,191,95,116,187,245,49,213,98,181,53,100,151,99,216,131,247,255,5,2,13,65,135,147,195,241,58,255,246,29,32,3,167,110,217,
130,207,112,221,1,255,87,219,25,157,78,138,132,108,39,13,139,52,52,52,189,248,15,61,206,194,35,226,56,248,250,245,143,61,81,48,237,2,93,65,126,112,95,13,66,94,78,127,228,129,162,173,111,203,150,80,77,
173,142,28,236,173,81,15,182,161,26,233,156,71,32,228,109,221,243,171,255,215,255,222,5,150,162,242,93,183,254,218,88,213,7,76,16,90,219,190,186,252,7,172,206,96,210,235,219,100,121,147,158,207,158,253,
99,216,17,35,198,102,195,125,186,221,109,15,255,245,193,75,102,204,248,206,71,114,199,173,183,150,255,229,47,223,115,150,123,56,101,115,47,41,20,132,33,226,13,70,153,100,168,170,170,253,232,178,166,172,
64,253,83,230,140,38,56,117,98,40,164,179,88,229,78,74,137,136,236,97,58,88,86,10,133,226,242,74,212,174,88,197,224,72,146,98,141,56,78,61,96,25,142,237,52,81,172,224,118,243,54,43,136,17,170,175,103,
68,201,54,98,120,164,177,57,220,124,216,80,90,89,21,17,214,24,248,223,231,216,179,39,133,59,91,98,163,220,220,252,133,11,238,233,17,67,137,245,227,121,14,18,12,89,151,89,226,237,115,136,49,16,201,176,
234,107,16,124,66,217,75,129,128,26,6,240,34,152,224,15,112,70,163,204,106,209,1,28,123,99,212,227,1,19,148,47,66,200,242,209,104,1,109,131,33,57,172,116,133,3,101,157,244,200,193,145,206,25,242,78,205,
110,83,218,6,131,70,184,82,185,57,136,94,162,158,14,83,73,185,78,140,162,214,50,61,231,200,166,109,1,178,232,155,110,77,173,238,39,22,63,222,179,198,4,85,173,215,43,26,93,93,8,146,225,32,89,44,156,197,
124,36,193,14,127,194,139,67,28,162,188,205,144,32,249,144,93,56,87,218,155,13,84,64,115,222,106,69,15,74,53,48,65,123,233,33,75,188,213,194,153,77,50,57,48,117,57,208,204,14,122,35,13,97,52,56,120,147,
69,69,58,135,35,42,73,85,162,188,90,207,111,52,91,120,150,165,100,232,133,112,56,114,238,252,253,31,234,234,234,24,138,52,244,68,200,36,201,237,60,251,168,81,87,152,101,187,137,101,215,238,24,165,101,
125,166,79,187,152,74,124,26,15,14,177,75,49,195,252,217,168,243,88,236,217,118,251,217,69,6,150,101,195,130,124,225,249,23,80,185,79,106,19,116,50,83,45,201,79,152,116,43,173,86,107,214,172,168,102,41,
25,0,163,209,180,103,95,221,249,231,157,31,21,162,148,0,177,76,48,203,204,64,89,126,214,164,123,196,98,41,204,154,21,164,172,38,3,96,177,88,107,15,212,159,58,118,220,142,237,219,191,11,243,212,227,38,
68,121,183,45,201,149,178,188,200,164,187,223,102,41,49,89,179,83,35,100,233,150,244,176,15,130,196,157,123,206,121,15,255,245,175,89,110,16,12,50,51,88,148,67,28,119,139,69,255,140,221,150,157,91,14,
103,53,25,148,59,231,56,103,81,217,131,127,121,248,244,73,167,191,253,214,91,199,53,74,237,1,129,178,146,174,39,203,136,16,242,25,230,85,19,63,203,102,252,204,158,91,168,55,103,179,106,224,139,139,203,
178,249,254,77,38,115,56,18,125,237,181,215,223,122,227,245,64,192,159,147,155,235,116,58,191,213,43,174,255,100,157,113,221,186,254,22,71,68,221,78,140,85,95,148,177,204,241,248,199,169,139,69,54,70,
46,146,153,2,153,113,243,236,251,122,254,1,139,254,109,171,205,102,182,25,178,254,247,14,179,37,29,35,19,120,189,30,89,20,6,13,172,30,59,110,204,176,225,195,251,245,235,151,95,80,96,54,153,57,53,133,174,
155,159,21,36,103,227,126,242,80,43,100,53,239,156,93,244,167,63,125,239,233,37,147,115,75,220,220,113,141,30,48,10,65,249,129,67,166,149,99,107,57,118,27,207,110,212,235,91,141,166,28,189,145,101,88,
250,244,41,25,146,35,18,9,135,195,33,89,140,234,120,29,199,171,63,125,171,100,58,164,245,112,216,132,95,1,141,45,236,44,17,89,150,19,163,35,69,209,36,203,194,113,148,64,242,211,183,62,150,117,243,92,7,
199,135,117,58,35,175,55,100,205,183,118,40,25,40,40,104,0,77,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,64,65,65,201,
64,65,65,201,64,65,65,201,64,65,209,211,240,255,5,24,0,152,149,191,51,147,97,77,39,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* StructureAudioProcessorEditor::structuredemoexpired_png = (const char*) resource_StructureAudioProcessorEditor_structuredemoexpired_png;
const int StructureAudioProcessorEditor::structuredemoexpired_pngSize = 12966;


//[EndFile] You can add extra defines here...
//[/EndFile]
