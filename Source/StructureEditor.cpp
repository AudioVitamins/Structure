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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "StructureEditor.h"
#include "./authorization/auth.h"

//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
StructureGUI::StructureGUI (StructureAudioProcessor& p)
    : AudioProcessorEditor(p), mGlob(&p.mEditorState), mTrialDialog(&mGlob, this),mAuthDlg(&mGlob, this)
{
    //[Constructor_pre] You can add your own custom stuff here..
    this->p = &p;

    redUpImg = ImageCache::getFromMemory(white_pushbutton_redled_36x36_up_png, white_pushbutton_redled_36x36_up_pngSize);
    redDownImg = ImageCache::getFromMemory(white_pushbutton_redled_36x36_down_png, white_pushbutton_redled_36x36_down_pngSize);
    greenDownImg = ImageCache::getFromMemory(white_pushbutton_greenLed_png, white_pushbutton_greenLed_pngSize);
    orangeDownImg = ImageCache::getFromMemory(white_pushbutton_orangeLed_down_png, white_pushbutton_orangeLed_down_pngSize);
    //[/Constructor_pre]

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
    
    addAndMakeVisible (mBtnUnlock = new ImageButton ("unlock"));
    mBtnUnlock->setButtonText (TRANS("new button"));
    mBtnUnlock->addListener (this);

    mBtnUnlock->setImages (false, true, true,
                           ImageCache::getFromMemory (lock2small_png, lock2small_pngSize), 1.000f, Colour (0x00000000),
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
    startTimer(1,50);
    startTimer(2, 3000); // licensing timer
    
       //@AS
       addChildComponent(mTrialDialog);
       addChildComponent(mAuthDlg);
       fixColors(mGlob.mEditorState, this);
       mUnlocked = false;
       mTryReauth = false;
    //[/Constructor]
}

StructureGUI::~StructureGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    instrumentsBtn = nullptr;
    busBtn = nullptr;
    voxBtn = nullptr;
    analyseBtn = nullptr;
    allBtn = nullptr;
    analyseDotCom = nullptr;
    mBtnUnlock = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void StructureGUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    {
        int x = 0, y = 0, width = 260, height = 200;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (Colours::black);
        g.drawImage (cachedImage_structureuibackground_png_1,
                     x, y, width, height,
                     0, 0, cachedImage_structureuibackground_png_1.getWidth(), cachedImage_structureuibackground_png_1.getHeight());
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void StructureGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    instrumentsBtn->setBounds (29, 8, 44, 60);
    busBtn->setBounds (106, 8, 44, 60);
    voxBtn->setBounds (185, 8, 44, 60);
    analyseBtn->setBounds (25, 111, 44, 44);
    allBtn->setBounds (76, 111, 44, 44);
    analyseDotCom->setBounds (40, 103, 11, 11);
    mBtnUnlock->setBounds (8, 8, 18, 23);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void StructureGUI::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == instrumentsBtn)
    {
        //[UserButtonCode_instrumentsBtn] -- add your button handler code here..
        buttonThatWasClicked->setToggleState(true, false);
        p->optionMode = INSTRUMENTS_MODE;
        //[/UserButtonCode_instrumentsBtn]
    }
    else if (buttonThatWasClicked == busBtn)
    {
        //[UserButtonCode_busBtn] -- add your button handler code here..
        buttonThatWasClicked->setToggleState(true, false);
        p->optionMode = VOX_LEAD_MODE;
        //[/UserButtonCode_busBtn]
    }
    else if (buttonThatWasClicked == voxBtn)
    {
        //[UserButtonCode_voxBtn] -- add your button handler code here..
        buttonThatWasClicked->setToggleState(true, false);
        p->optionMode = BUS_GROUP_MODE;
        //[/UserButtonCode_voxBtn]
    }
    else if (buttonThatWasClicked == analyseBtn)
    {
        //[UserButtonCode_analyseBtn] -- add your button handler code here..
        p->analysisState = false;
        p->ResetMetter();
        updateStateAnalysis();
        //buttonThatWasClicked->setToggleState(true, false);
        //[/UserButtonCode_analyseBtn]
    }
    else if (buttonThatWasClicked == allBtn)
    {
        //[UserButtonCode_allBtn] -- add your button handler code here..
        p->analysisState = false;
        p->ResetMetter();
        updateStateAnalysis();
        p->sendAnalysisAllMode();
        //buttonThatWasClicked->setToggleState(true, false);
        //[/UserButtonCode_allBtn]
    }
    else if (buttonThatWasClicked == mBtnUnlock)
    {
        //[UserButtonCode_mBtnUnlock] -- add your button handler code here..
        //@AS auth btn was pressed
       mAuthDlg.openDialog();
       mAuthDlg.doSetup();
        //[/UserButtonCode_mBtnUnlock]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void StructureGUI::timerCallback(int timerID) {
   if (timerID == 1) {
    synGUI();
    //p->sendAnalysisAllMode();
       timerCallback(1);
   }
   else if (timerID == 2) {
       //@AS
       stopTimer(2); // prevent firing again
//       timerCallback(2);
       authorize();
   }
}
void StructureGUI::synGUI() {
//    updateActiveMode();
    updateStateAnalysis();
}
//void StructureGUI::updateActiveMode() {
//
//}
void StructureGUI::updateStateAnalysis() {
    bool state = p->analysisState;
    analyseDotCom->setMode(state);
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


//@AS
void StructureGUI::cptValueChange(int cptId, int value)
{
    switch (cptId) {
        case SEQCTL_TRIALDIALOG:
            mGlob.mEditorState->mShownTrialWindow = true; // only show it again if necessary
            // try to unlock again in a few seconds
            //(we need to do this to force a processor unlock)
            prepareAuthorization(false); // don't contact server again
            break;
        default:
            break;
    }
}		 

void StructureGUI::authorize()
{
    
    String trialText;
    String authkey;
    String uid, pwd;
    String err;
    bool unlockEngine = false;
    mGlob.mEditorState->getUIDPWD(uid, pwd);
    
    // read main unlock code
    seqReadKeyFromFile(authkey);
    
    // clear alert
    //>>>setAlertText("");
    
    // authorize
    if (authkey.length() && uid.length() && pwd.length()) {
        int days = seqAuthorize(authkey, uid, err);
        if (days > 0) {
            // still valid, unlock the engine
            unlockEngine = true;
            mUnlocked = true;
            
            if (days < 8 && mTryReauth) {
                // approaching expiration. try to get a new key from server
                seqDoReauthorize(uid, pwd, err);
                // try to unlock again in a few seconds
                prepareAuthorization(false); // don't contact server again
            }
            else if (days < 5 && !mTryReauth) {
                // must have failed to get a key. warn the user
                /*>>>
                 setAlertText("Your authorization key is approaching expiration, and Life has "
                 "been unable to contact the server to renew the key. Your key is still valid, but will expire "
                 " in a few days. Please click unlock icon to resolve the issue.");
                 */
            }
        }
        else {
            // license expired
            if (!mTryReauth) {
                trialText = "Your authorization key has expired, and Life has "
                "been unable to contact the server to renew the key. Please click Registration "
                "to resolve the issue.";
                goto trial_mode;
            }
            else {
                // try to reauthorize then come back thru here to unlock again
                seqDoReauthorize(uid, pwd, err);
                // try to unlock again in a few seconds
                prepareAuthorization(false); // don't contact server again
            }
            
        }
    }
    else {
        int days = 0;
        // no unlock code/uid/pwd is present, see if we have trial unlock
        if (seqReadKeyFromFile(authkey, true)) { // try to read trial key
            // is it valid?
            days = seqAuthorize(authkey, uid, err, true);
            if (days > 0) {
                // still valid, unlock the engine
                unlockEngine = true;
                mUnlocked = true;
                
            }
        }
        // will still show trial mode dialog once
        if (days) { // if they have days left on the trial
            if (!mGlob.mEditorState->mShownTrialWindow) {
                // and we havent shown the trial window
                mGlob.mEditorState->mShownTrialWindow = true;
                goto trial_mode; //show it once
                // otherwise we dont show it again
            }
        }
        else
            goto trial_mode;
    }
    mUnlocked = unlockEngine;
    
    return;
trial_mode:
    
    mUnlocked = unlockEngine;
    mTrialDialog.doSetup(trialText);
    mTrialDialog.openDialog();
    return;
    
}

void StructureGUI::prepareAuthorization(bool allowRenew)
{
    mTryReauth = allowRenew;
    startTimer(2, 3000);
    // authorize will be called in 3 seconds
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="StructureGUI"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="StructureAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(p), mGlob(&amp;p.mEditorState), mTrialDialog(&amp;mGlob, this),mAuthDlg(&amp;mGlob, this)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="260" initialHeight="200">
  <BACKGROUND backgroundColour="ffffffff">
    <IMAGE pos="0 0 260 200" resource="structureuibackground_png" opacity="1"
           mode="0"/>
  </BACKGROUND>
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
 <IMAGEBUTTON name="unlock" id="38b1718aad540836" memberName="mBtnUnlock" virtualName=""
               explicitFocusOrder="0" pos="8 8 18 23" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="lock2small_png" opacityNormal="1" colourNormal="0"
               resourceOver="" opacityOver="1" colourOver="0" resourceDown=""
               opacityDown="1" colourDown="0"/>
  <JUCERCOMP name="" id="59319dd7a237afb9" memberName="analyseDotCom" virtualName=""
             explicitFocusOrder="0" pos="40 103 11 11" sourceFile="DotComponent.cpp"
             constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: structureuibackground_png, 10134, "../Graphics/structure-UI-background.png"
static const unsigned char resource_StructureGUI_structureuibackground_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,4,0,0,0,200,8,2,0,0,0,129,55,8,38,0,0,0,25,116,69,
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

const char* StructureGUI::structureuibackground_png = (const char*) resource_StructureGUI_structureuibackground_png;
const int StructureGUI::structureuibackground_pngSize = 10134;

// JUCER_RESOURCE: white_pushbutton_44x60_down_png, 1100, "../Graphics/white_pushbutton_44x60_DOWN.png"
static const unsigned char resource_StructureGUI_white_pushbutton_44x60_down_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,60,8,6,0,0,0,29,82,88,154,0,0,4,19,
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

const char* StructureGUI::white_pushbutton_44x60_down_png = (const char*) resource_StructureGUI_white_pushbutton_44x60_down_png;
const int StructureGUI::white_pushbutton_44x60_down_pngSize = 1100;

// JUCER_RESOURCE: white_pushbutton_44x60_up_png, 1462, "../Graphics/white_pushbutton_44x60_UP.png"
static const unsigned char resource_StructureGUI_white_pushbutton_44x60_up_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,60,8,6,0,0,0,29,82,88,154,0,0,5,125,73,
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

const char* StructureGUI::white_pushbutton_44x60_up_png = (const char*) resource_StructureGUI_white_pushbutton_44x60_up_png;
const int StructureGUI::white_pushbutton_44x60_up_pngSize = 1462;

// JUCER_RESOURCE: white_pushbutton_greenLed_png, 1738, "../Graphics/white_pushbutton_greenLED.png"
static const unsigned char resource_StructureGUI_white_pushbutton_greenLed_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,60,8,6,0,0,0,29,82,88,154,0,0,6,145,73,
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

const char* StructureGUI::white_pushbutton_greenLed_png = (const char*) resource_StructureGUI_white_pushbutton_greenLed_png;
const int StructureGUI::white_pushbutton_greenLed_pngSize = 1738;

// JUCER_RESOURCE: white_pushbutton_orangeLed_png, 1742, "../Graphics/white_pushbutton_orangeLED.png"
static const unsigned char resource_StructureGUI_white_pushbutton_orangeLed_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,60,8,6,0,0,0,29,82,88,154,0,0,6,149,
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

const char* StructureGUI::white_pushbutton_orangeLed_png = (const char*) resource_StructureGUI_white_pushbutton_orangeLed_png;
const int StructureGUI::white_pushbutton_orangeLed_pngSize = 1742;

// JUCER_RESOURCE: white_pushbutton_orangeLed_down_png, 1420, "../Graphics/white_pushbutton_orangeLED_DOWN.png"
static const unsigned char resource_StructureGUI_white_pushbutton_orangeLed_down_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,60,8,6,0,0,0,29,82,88,154,0,0,5,
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

const char* StructureGUI::white_pushbutton_orangeLed_down_png = (const char*) resource_StructureGUI_white_pushbutton_orangeLed_down_png;
const int StructureGUI::white_pushbutton_orangeLed_down_pngSize = 1420;

// JUCER_RESOURCE: white_pushbutton_redled_36x36_down_png, 2644, "../Graphics/white_pushbutton_REDLED_36x36_DOWN.png"
static const unsigned char resource_StructureGUI_white_pushbutton_redled_36x36_down_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,50,8,6,0,0,0,39,88,57,234,0,
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

const char* StructureGUI::white_pushbutton_redled_36x36_down_png = (const char*) resource_StructureGUI_white_pushbutton_redled_36x36_down_png;
const int StructureGUI::white_pushbutton_redled_36x36_down_pngSize = 2644;

// JUCER_RESOURCE: white_pushbutton_redled_36x36_up_png, 2475, "../Graphics/white_pushbutton_REDLED_36x36_UP.png"
static const unsigned char resource_StructureGUI_white_pushbutton_redled_36x36_up_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,50,8,6,0,0,0,39,88,57,234,0,0,
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

const char* StructureGUI::white_pushbutton_redled_36x36_up_png = (const char*) resource_StructureGUI_white_pushbutton_redled_36x36_up_png;
const int StructureGUI::white_pushbutton_redled_36x36_up_pngSize = 2475;

// JUCER_RESOURCE: white_pushbutton_down_png, 1958, "../Graphics/white_pushbutton_DOWN.png"
static const unsigned char resource_StructureGUI_white_pushbutton_down_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,44,8,6,0,0,0,30,132,90,1,0,0,0,25,116,69,
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

const char* StructureGUI::white_pushbutton_down_png = (const char*) resource_StructureGUI_white_pushbutton_down_png;
const int StructureGUI::white_pushbutton_down_pngSize = 1958;

// JUCER_RESOURCE: white_pushbutton_up_png, 2311, "../Graphics/white_pushbutton_UP.png"
static const unsigned char resource_StructureGUI_white_pushbutton_up_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,44,0,0,0,44,8,6,0,0,0,30,132,90,1,0,0,0,25,116,69,88,
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

const char* StructureGUI::white_pushbutton_up_png = (const char*) resource_StructureGUI_white_pushbutton_up_png;
const int StructureGUI::white_pushbutton_up_pngSize = 2311;

// JUCER_RESOURCE: structureanalysegreenlight_png, 1501, "../Graphics/structure-analyse-greenlight.png"
static const unsigned char resource_StructureGUI_structureanalysegreenlight_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,13,0,0,0,13,8,6,0,0,0,114,235,228,124,0,0,0,25,
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

const char* StructureGUI::structureanalysegreenlight_png = (const char*) resource_StructureGUI_structureanalysegreenlight_png;
const int StructureGUI::structureanalysegreenlight_pngSize = 1501;

// JUCER_RESOURCE: structureanalyseorangelight_png, 1530, "../Graphics/structure-analyse-orangelight.png"
static const unsigned char resource_StructureGUI_structureanalyseorangelight_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,13,0,0,0,13,8,6,0,0,0,114,235,228,124,0,0,0,
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

const char* StructureGUI::structureanalyseorangelight_png = (const char*) resource_StructureGUI_structureanalyseorangelight_png;
const int StructureGUI::structureanalyseorangelight_pngSize = 1530;

// JUCER_RESOURCE: authorization_png, 7678, "../Graphics/structure-auth-UI.png"
static const unsigned char resource_StructureGUI_authorization_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,4,0,0,0,200,8,2,0,0,0,129,55,8,38,0,0,0,25,116,69,88,116,
    83,111,102,116,119,97,114,101,0,65,100,111,98,101,32,73,109,97,103,101,82,101,97,100,121,113,201,101,60,0,0,3,107,105,84,88,116,88,77,76,58,99,111,109,46,97,100,111,98,101,46,120,109,112,0,0,0,0,0,60,
    63,120,112,97,99,107,101,116,32,98,101,103,105,110,61,34,239,187,191,34,32,105,100,61,34,87,53,77,48,77,112,67,101,104,105,72,122,114,101,83,122,78,84,99,122,107,99,57,100,34,63,62,32,60,120,58,120,109,
    112,109,101,116,97,32,120,109,108,110,115,58,120,61,34,97,100,111,98,101,58,110,115,58,109,101,116,97,47,34,32,120,58,120,109,112,116,107,61,34,65,100,111,98,101,32,88,77,80,32,67,111,114,101,32,53,46,
    54,45,99,49,51,56,32,55,57,46,49,53,57,56,50,52,44,32,50,48,49,54,47,48,57,47,49,52,45,48,49,58,48,57,58,48,49,32,32,32,32,32,32,32,32,34,62,32,60,114,100,102,58,82,68,70,32,120,109,108,110,115,58,114,
    100,102,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,49,57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,97,120,45,110,115,35,34,62,32,60,114,100,102,58,68,101,115,
    99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,32,120,109,108,110,115,58,120,109,112,77,77,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,
    97,112,47,49,46,48,47,109,109,47,34,32,120,109,108,110,115,58,115,116,82,101,102,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,115,84,121,112,101,
    47,82,101,115,111,117,114,99,101,82,101,102,35,34,32,120,109,108,110,115,58,120,109,112,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,34,32,120,
    109,112,77,77,58,79,114,105,103,105,110,97,108,68,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,48,55,56,48,49,49,55,52,48,55,50,48,54,56,49,49,56,67,49,52,68,69,48,68,65,55,70,
    69,50,51,52,57,34,32,120,109,112,77,77,58,68,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,50,53,51,67,67,56,70,65,70,53,51,50,49,49,69,55,56,67,70,56,56,51,55,52,56,48,68,53,55,
    57,52,67,34,32,120,109,112,77,77,58,73,110,115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,50,53,51,67,67,56,70,57,70,53,51,50,49,49,69,55,56,67,70,56,56,51,55,52,56,48,68,53,55,57,52,
    67,34,32,120,109,112,58,67,114,101,97,116,111,114,84,111,111,108,61,34,65,100,111,98,101,32,80,104,111,116,111,115,104,111,112,32,67,67,32,40,77,97,99,105,110,116,111,115,104,41,34,62,32,60,120,109,112,
    77,77,58,68,101,114,105,118,101,100,70,114,111,109,32,115,116,82,101,102,58,105,110,115,116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,54,48,101,52,52,98,48,52,45,101,51,52,101,45,52,54,56,
    50,45,57,54,53,52,45,99,55,50,99,55,56,50,52,101,97,98,97,34,32,115,116,82,101,102,58,100,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,48,55,56,48,49,49,55,52,48,55,50,48,54,56,
    49,49,56,67,49,52,68,69,48,68,65,55,70,69,50,51,52,57,34,47,62,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,32,60,47,114,100,102,58,82,68,70,62,32,60,47,120,58,120,109,112,109,
    101,116,97,62,32,60,63,120,112,97,99,107,101,116,32,101,110,100,61,34,114,34,63,62,136,135,179,128,0,0,26,41,73,68,65,84,120,218,236,157,7,116,92,213,153,199,95,155,121,211,171,164,81,47,182,101,73,238,
    128,99,140,48,54,134,44,197,16,194,18,66,10,27,32,193,180,16,32,54,237,144,156,147,61,108,18,202,38,132,78,88,66,73,8,156,77,88,178,57,203,98,32,28,108,192,96,154,77,179,137,109,21,27,171,119,77,209,180,
    247,222,188,247,246,123,51,150,44,201,26,121,4,146,237,141,255,191,163,99,166,220,121,243,202,247,187,247,251,238,125,18,236,162,69,75,25,0,0,195,112,56,5,0,64,6,0,32,3,0,144,1,0,200,0,0,100,0,0,50,0,
    0,25,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,100,0,0,50,0,0,25,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,100,0,0,50,0,0,25,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,100,0,0,50,0,0,25,0,128,12,0,64,6,0,
    32,3,0,144,1,0,200,0,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,100,0,0,50,0,0,25,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,100,0,0,50,0,0,25,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,100,0,0,50,0,0,25,0,
    128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,100,0,0,50,0,0,25,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,100,0,0,50,0,0,25,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,100,
    0,0,50,0,0,25,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,100,0,0,50,0,0,25,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,100,0,0,50,0,0,25,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,128,12,0,64,6,0,32,3,0,144,
    1,0,200,0,0,100,0,0,50,0,0,25,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,100,0,0,50,0,0,25,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,100,0,0,50,0,0,25,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,100,0,0,50,
    0,0,25,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,100,0,0,50,0,0,25,0,128,12,0,64,6,0,32,3,0,144,1,0,200,0,0,100,0,0,50,0,112,56,17,112,10,142,101,52,77,75,36,226,
    28,163,139,162,89,20,45,60,63,81,231,200,50,140,62,233,86,134,27,36,116,189,96,160,111,126,74,141,177,156,241,226,228,232,204,161,219,28,212,115,235,58,19,103,217,65,129,239,231,133,48,47,240,130,201,
    204,241,144,1,124,41,134,34,33,191,207,91,95,95,191,114,213,170,186,121,243,138,138,138,28,14,167,32,240,95,36,106,135,27,188,211,219,179,241,196,250,245,61,193,62,143,107,198,118,156,213,25,93,102,216,
    16,199,180,113,236,199,60,187,73,20,251,68,171,67,48,31,141,50,172,62,181,94,74,74,239,188,247,225,81,27,7,115,231,206,170,158,83,181,225,165,141,199,166,6,193,224,192,226,133,243,174,185,246,246,51,207,
    58,139,231,114,200,147,217,92,27,248,156,206,40,195,180,48,76,152,101,103,242,8,104,220,97,76,26,179,68,213,78,81,152,239,202,137,205,9,233,41,171,24,178,216,109,188,112,20,201,224,247,123,231,206,153,
    245,233,246,157,71,111,145,196,113,171,87,214,39,18,201,99,80,3,69,145,45,102,254,63,30,125,232,236,53,107,102,98,251,209,104,212,72,151,56,86,159,225,3,81,233,135,101,146,44,219,205,48,86,157,185,64,
    82,79,75,37,30,151,228,231,28,14,175,217,122,180,20,208,78,135,93,211,212,88,44,118,212,6,4,165,197,180,135,161,112,248,152,203,139,134,34,39,159,244,149,173,31,110,157,33,19,142,76,215,198,48,18,203,
    52,242,172,164,235,183,37,82,63,143,12,133,147,209,163,69,6,69,73,81,77,198,204,236,40,249,165,208,117,221,216,195,99,140,112,56,120,205,213,151,255,238,137,199,121,158,159,249,83,124,216,59,56,82,157,
    101,27,120,246,28,73,125,40,18,251,194,62,76,251,212,42,133,154,106,212,252,71,245,20,138,106,236,228,49,67,60,30,189,246,154,43,111,190,229,150,127,224,99,164,222,151,122,184,93,60,187,76,209,238,28,
    138,15,74,241,35,47,67,52,22,87,85,45,126,20,103,228,169,148,74,123,72,35,216,49,98,2,105,127,242,242,175,220,124,235,45,135,53,48,143,144,15,20,205,77,60,123,166,172,94,22,163,64,156,242,37,254,130,5,
    180,40,138,30,143,211,36,8,99,14,94,103,188,94,183,170,169,5,5,126,73,146,198,156,20,221,24,60,41,69,145,37,185,127,32,56,102,15,120,158,62,101,50,155,70,94,137,69,227,225,200,208,33,235,224,130,124,191,
    36,203,193,224,196,217,191,211,105,183,90,44,2,237,33,59,190,102,160,61,52,139,166,146,226,128,158,101,148,239,233,237,35,97,38,223,1,151,203,97,179,90,187,123,250,68,209,236,245,184,67,225,72,50,41,29,
    220,96,162,236,129,77,199,168,209,101,68,163,51,94,92,41,201,248,227,79,61,121,120,51,209,35,154,6,51,204,62,142,253,129,164,190,21,143,4,157,190,153,149,129,101,217,19,151,45,174,172,40,205,90,233,171,
    106,69,121,49,253,76,248,110,36,18,125,233,149,55,70,158,30,183,100,126,205,220,170,113,109,246,126,222,246,193,214,79,39,223,13,147,73,56,117,213,137,193,80,228,111,175,110,30,115,60,130,80,91,51,171,
    186,186,82,52,155,39,217,67,187,205,122,202,138,175,100,107,240,194,139,27,227,241,196,228,59,48,127,94,117,69,121,201,159,255,107,67,126,158,111,197,201,75,223,125,255,227,150,150,142,204,91,121,121,
    222,229,39,30,231,176,219,14,121,50,37,73,222,221,176,119,215,238,230,25,75,144,98,191,254,213,93,130,112,56,87,147,88,74,148,201,117,102,120,210,150,158,178,195,161,67,189,225,216,20,154,101,141,101,
    62,150,26,25,205,134,235,153,244,71,88,134,99,15,212,121,186,206,114,156,174,170,70,155,225,167,7,4,200,188,78,219,151,101,218,82,84,20,3,154,246,253,100,234,118,139,228,52,137,51,40,195,105,167,158,228,
    243,186,233,194,119,118,245,80,202,49,238,93,143,219,53,175,110,78,75,107,71,71,103,207,193,159,173,95,126,188,54,220,227,82,52,159,125,198,42,234,86,187,187,250,6,6,131,70,79,204,50,20,193,115,102,87,
    168,169,67,39,244,116,58,168,153,148,24,211,25,7,10,252,245,203,79,200,172,28,117,118,246,70,34,67,178,162,140,235,55,88,142,157,87,59,39,145,72,146,114,7,111,182,188,188,216,233,176,235,57,212,60,178,
    164,100,246,211,200,187,210,63,153,215,171,103,87,44,89,60,143,94,108,106,222,71,223,146,30,12,149,186,186,57,86,139,113,85,104,40,24,24,12,209,235,52,178,209,208,81,24,200,95,48,175,122,86,101,233,91,
    91,182,69,134,162,211,30,152,121,94,215,215,207,63,127,26,114,203,238,30,206,229,100,69,49,213,222,97,170,40,159,76,5,65,80,83,81,185,95,18,139,74,116,77,165,144,149,123,187,121,135,139,198,65,222,110,
    83,163,81,85,151,70,229,232,130,185,176,152,99,88,37,60,148,74,68,196,64,137,209,215,178,244,145,54,186,0,150,162,82,195,10,142,151,186,168,151,209,196,162,50,185,183,203,228,203,215,146,146,18,15,90,
    2,101,153,174,89,147,101,121,176,143,26,43,193,65,45,25,103,57,179,22,238,239,40,44,95,145,74,205,78,196,123,103,78,134,185,213,149,110,151,253,157,247,62,154,48,214,51,29,127,205,220,202,158,158,254,
    9,27,80,200,100,124,166,99,248,218,154,213,177,88,98,227,27,239,208,191,163,219,84,85,150,228,56,208,210,214,82,163,242,194,162,194,252,147,78,92,66,159,221,241,89,195,158,189,173,74,42,107,202,88,83,
    93,73,105,216,206,137,250,99,171,85,180,89,197,92,38,0,84,131,84,90,75,141,30,208,191,153,243,67,193,253,233,142,93,141,77,251,70,90,150,149,22,154,77,124,60,30,255,248,211,93,157,93,189,99,114,54,142,
    155,51,167,98,126,221,156,211,87,47,255,219,107,111,199,227,211,89,107,41,138,124,201,149,87,78,207,100,212,19,79,217,79,63,205,60,191,46,244,216,19,249,191,188,125,146,150,137,174,246,202,91,127,234,
    228,249,189,119,223,97,205,43,74,118,181,205,254,229,29,82,71,39,103,181,196,62,221,17,184,248,59,158,147,235,19,237,109,20,0,150,146,210,216,238,221,59,191,123,73,82,142,7,214,156,235,59,235,204,198,
    107,174,19,124,62,37,26,156,251,200,195,241,134,166,150,251,239,177,23,86,196,186,90,74,47,191,202,121,252,146,198,245,235,106,30,121,164,253,145,71,29,139,23,211,211,134,27,127,108,45,40,75,69,135,44,
    229,229,179,239,190,99,207,173,63,161,175,88,250,193,59,98,105,233,238,43,175,233,249,159,191,150,185,252,171,21,229,105,77,21,115,190,95,99,106,5,52,5,250,208,80,52,155,9,153,96,162,200,48,153,133,108,
    225,155,73,63,206,252,106,125,40,20,166,203,63,206,4,135,195,150,238,102,115,152,234,209,141,173,141,76,10,217,172,150,101,75,23,208,43,155,223,222,182,187,113,239,36,38,240,60,79,205,216,44,235,66,60,
    207,26,145,157,75,97,170,143,200,64,143,82,131,131,97,183,203,81,87,83,245,238,251,159,140,54,161,48,144,119,252,146,58,50,225,181,215,223,29,103,130,113,66,52,173,161,241,243,173,219,182,211,129,212,
    47,95,50,189,195,130,148,140,159,53,93,75,10,28,167,37,18,156,221,238,251,241,117,135,24,67,226,113,83,65,65,249,77,235,24,186,142,225,16,111,117,148,94,127,173,174,164,2,223,190,200,86,87,163,165,100,
    85,87,189,171,79,245,156,186,138,30,112,22,139,177,159,114,210,127,238,154,226,171,214,10,94,111,42,52,152,146,18,249,255,252,245,234,251,126,205,50,188,20,28,160,19,92,243,216,195,5,223,190,136,94,47,
    188,228,123,130,199,99,46,200,47,91,127,131,99,86,77,178,183,83,79,202,130,219,29,184,228,98,93,81,106,31,123,212,50,123,150,212,213,85,245,111,255,202,40,18,37,27,139,84,93,87,164,153,154,77,162,36,167,
    171,187,111,242,236,133,186,235,108,19,249,244,86,52,22,159,87,59,155,134,194,77,111,126,48,97,136,79,242,241,177,13,245,244,188,208,126,25,78,56,126,62,61,125,127,235,142,113,213,249,132,31,205,76,40,
    101,209,85,75,165,212,28,79,69,166,165,158,62,46,191,223,179,124,217,226,79,183,55,140,62,63,44,203,44,89,84,75,239,190,245,206,71,84,30,100,219,84,91,71,79,103,87,31,165,136,165,37,129,105,148,33,80,
    144,95,85,53,190,30,211,98,113,61,251,158,76,112,152,9,163,183,18,10,11,117,122,192,113,124,126,222,152,83,41,43,250,216,126,71,116,184,59,238,123,80,75,38,221,11,151,38,147,67,254,179,206,74,133,34,61,
    207,60,67,233,147,158,82,63,189,98,237,198,154,154,190,231,255,187,247,217,63,209,131,79,206,88,195,89,109,84,219,89,42,43,141,28,123,69,189,172,38,169,80,8,110,50,170,202,138,117,55,246,73,209,178,181,
    215,80,174,21,218,184,137,94,79,182,180,208,55,198,27,26,140,116,244,129,123,101,99,37,90,35,13,226,127,223,233,56,110,137,125,209,194,109,39,156,180,101,254,188,230,117,55,89,139,42,99,60,95,164,233,
    254,212,20,230,148,166,150,38,165,82,148,231,112,147,246,151,116,114,82,84,196,76,248,110,44,22,247,184,29,126,159,123,227,27,239,101,15,113,178,65,205,113,103,50,49,237,113,59,41,183,233,237,27,232,238,
    233,207,249,131,106,182,228,135,222,205,37,77,34,99,83,233,19,157,121,48,191,110,118,107,91,215,190,214,206,209,109,40,115,163,244,169,173,189,119,220,0,120,48,59,119,239,241,121,93,84,60,180,119,244,
    76,151,12,229,229,101,99,178,166,214,214,232,11,27,244,100,66,29,26,18,23,44,112,125,243,27,198,21,121,233,21,113,225,2,161,108,255,116,72,236,213,215,132,226,34,113,193,124,122,28,124,232,17,185,121,
    15,213,9,66,32,32,109,223,225,255,201,173,122,50,73,13,28,231,157,107,156,168,193,224,224,61,247,233,82,210,40,195,108,54,255,45,235,57,167,147,134,72,234,185,35,109,205,84,27,248,191,182,166,125,199,
    54,223,217,103,72,237,237,177,68,132,179,90,233,172,154,210,189,47,13,8,58,199,83,46,111,242,251,83,225,144,115,118,29,5,186,220,211,155,127,209,55,218,95,248,11,159,14,35,185,183,175,248,202,203,91,159,
    122,178,228,186,31,166,130,65,53,22,31,153,20,52,23,21,37,63,223,231,63,231,236,146,51,206,237,120,245,69,103,186,236,38,211,120,187,221,82,86,50,184,123,123,104,211,155,148,110,165,120,222,175,235,5,
    170,250,249,12,141,12,52,220,251,125,174,201,11,91,35,123,209,179,141,12,20,61,58,165,206,178,172,76,242,113,61,183,21,226,76,221,154,78,202,3,244,160,177,169,37,199,163,48,246,48,139,12,20,217,185,166,
    73,233,150,153,169,15,122,48,20,141,238,106,216,59,174,77,113,81,30,189,213,48,42,107,202,6,217,66,152,205,211,185,60,92,82,92,50,110,76,16,74,75,60,87,95,233,95,255,99,74,218,18,111,111,49,46,232,155,
    111,81,113,124,32,227,223,242,174,188,199,8,158,254,219,127,33,55,52,121,174,184,220,127,227,58,203,9,199,105,177,152,209,181,203,114,124,211,155,105,19,6,123,215,221,196,7,242,125,235,110,240,173,187,
    142,119,185,122,174,95,79,53,10,103,119,176,2,79,39,37,182,107,183,247,180,83,169,165,187,254,164,240,187,239,233,153,81,50,61,169,204,102,38,151,89,227,57,203,243,138,28,205,59,255,60,58,135,123,111,
    190,205,179,122,149,200,154,141,210,185,170,162,237,87,247,68,183,111,95,249,247,29,201,189,123,247,253,252,78,122,101,100,39,45,197,197,189,127,249,107,215,111,127,55,239,79,127,164,64,209,100,137,242,
    183,161,109,31,38,118,55,46,252,223,191,90,44,182,148,18,101,121,142,58,86,114,207,55,149,187,13,166,38,195,174,6,58,83,250,220,57,229,147,77,242,168,106,182,104,54,81,29,153,72,246,246,5,39,153,36,54,
    50,152,92,14,192,168,25,212,204,218,25,245,169,164,89,56,146,219,108,76,250,131,217,6,159,116,136,171,185,84,240,195,45,247,143,39,141,77,173,7,207,65,59,29,182,204,232,145,254,109,129,201,126,204,102,
    211,80,52,158,83,177,148,51,246,177,115,187,98,93,173,243,252,243,56,135,195,184,16,101,37,169,254,65,163,70,202,243,179,150,3,243,45,188,223,103,158,51,75,218,185,139,12,9,60,120,175,56,127,30,95,144,
    111,91,181,210,113,246,153,169,174,158,145,52,41,252,244,179,230,186,90,223,245,63,18,74,138,133,210,82,223,205,235,204,115,102,51,47,108,16,92,46,138,0,18,122,96,195,203,230,162,66,191,195,67,9,253,192,
    11,47,154,211,145,49,102,121,108,248,28,209,1,123,191,122,90,116,251,142,93,127,124,146,6,4,223,105,167,83,55,201,91,173,74,95,127,235,29,255,46,20,23,182,253,230,193,228,190,22,222,233,28,29,99,98,113,
    209,206,31,253,72,240,122,42,47,248,86,244,179,157,156,40,154,124,222,79,46,188,144,30,156,180,115,23,107,178,40,225,16,109,220,248,61,141,169,220,12,49,181,52,169,127,32,220,214,209,93,20,240,59,29,150,
    230,189,29,225,72,108,162,154,65,201,62,50,40,198,98,220,164,3,11,181,201,37,38,210,9,149,162,40,114,58,46,83,209,104,34,247,69,153,244,87,164,178,206,80,165,148,92,78,32,185,64,45,71,246,228,96,187,68,
    179,41,211,96,217,9,181,57,103,161,202,52,202,16,139,143,191,37,33,250,226,75,114,67,35,107,179,74,187,27,108,233,158,155,25,238,179,15,204,251,187,156,241,183,223,177,28,63,166,154,167,164,136,205,172,
    138,166,231,254,181,80,40,147,44,141,96,59,109,53,179,117,91,102,4,48,49,108,240,165,87,41,201,153,123,239,125,82,103,103,104,243,102,19,103,153,248,90,200,138,96,20,12,21,188,205,86,179,126,29,165,88,
    206,101,75,149,141,47,83,103,106,171,171,109,251,195,19,237,15,62,50,248,214,107,179,126,250,51,125,164,144,51,126,145,72,23,75,74,66,154,220,251,236,159,235,254,243,233,96,81,5,117,132,150,242,178,240,
    7,91,222,155,183,104,249,206,237,139,159,127,126,219,215,207,53,217,29,26,195,74,83,185,77,110,202,235,12,205,123,58,40,242,170,42,138,230,213,86,198,98,201,150,182,238,209,74,12,23,208,122,182,2,122,
    242,94,95,207,185,128,206,108,77,81,84,158,231,232,65,108,42,147,146,147,20,208,233,2,32,183,2,122,184,37,21,72,244,128,61,232,38,132,253,59,22,75,244,13,132,115,220,160,166,78,231,226,109,103,103,215,
    152,233,209,167,159,77,188,255,129,247,202,181,226,226,133,84,182,82,124,103,114,60,110,212,50,57,229,253,90,82,162,127,83,99,63,203,164,151,186,152,225,14,222,24,253,199,222,246,171,69,163,52,110,176,
    233,190,129,231,109,209,246,230,68,99,115,225,218,75,187,30,127,42,169,73,54,171,119,226,11,17,14,218,103,213,89,170,42,109,181,53,238,149,43,140,209,108,225,252,204,183,112,54,43,125,83,211,245,55,208,
    41,230,157,142,241,113,162,170,52,234,237,92,187,246,212,139,191,53,247,183,15,38,154,155,213,68,130,132,11,238,218,209,116,253,250,234,7,126,227,200,47,214,162,49,197,110,31,228,167,144,251,124,145,123,
    147,186,123,6,63,248,112,87,91,71,143,197,34,212,84,151,86,207,46,102,217,209,105,82,214,164,127,146,100,125,164,191,79,79,152,230,90,51,80,248,80,54,50,82,60,76,71,205,144,158,48,213,115,76,147,82,153,
    213,209,244,58,131,62,225,177,68,134,98,93,221,3,185,252,244,244,6,251,6,66,211,40,67,107,203,152,204,45,190,233,245,130,95,221,69,38,24,197,116,75,43,239,245,166,131,56,150,216,246,225,112,81,17,139,
    60,247,60,165,254,182,149,43,18,239,190,79,69,243,129,99,161,88,207,104,160,24,231,205,90,191,60,252,212,211,99,77,123,134,89,113,178,110,12,143,186,177,238,198,48,67,31,125,76,175,135,222,216,204,102,
    143,50,89,147,2,255,242,29,42,157,55,251,11,222,116,123,119,93,186,214,247,79,95,117,48,130,26,141,233,70,255,194,152,124,121,108,186,56,30,51,178,167,255,67,169,87,34,25,221,115,211,109,5,23,93,104,157,
    51,155,170,103,147,215,184,191,166,251,15,207,36,91,219,172,85,179,121,73,138,178,76,239,84,126,41,244,11,46,212,83,207,218,222,209,223,217,53,80,20,240,5,10,60,53,115,74,119,55,181,15,143,12,147,21,208,
    169,67,69,109,174,179,73,195,95,148,158,226,76,77,101,48,212,211,187,161,102,159,90,205,169,128,86,135,103,147,50,135,172,31,116,200,52,106,209,235,130,112,196,254,228,66,79,111,111,75,75,75,69,197,254,
    210,211,186,162,158,202,98,203,210,227,120,167,75,250,236,51,165,181,213,60,183,218,125,241,183,251,127,121,183,218,219,203,166,167,252,105,76,80,35,67,102,151,203,123,237,213,253,84,182,46,59,65,40,40,
    48,10,235,15,182,58,191,245,205,204,189,101,198,114,208,217,103,41,159,183,244,92,183,78,92,178,136,94,76,126,248,177,109,69,61,179,100,81,170,47,83,139,83,229,202,71,63,49,110,168,137,126,246,153,137,
    84,160,158,94,20,71,238,182,96,77,166,76,76,211,63,121,231,157,51,180,117,91,100,176,143,122,250,238,167,159,166,78,61,239,204,179,149,80,144,53,25,145,201,10,251,255,229,210,55,215,208,70,40,79,51,158,
    154,140,58,219,110,247,126,126,207,93,21,63,187,205,177,104,161,26,75,44,122,229,197,230,91,110,241,158,178,74,112,56,162,13,59,253,86,235,62,142,29,20,4,113,70,71,134,81,189,163,222,209,53,64,167,197,
    108,230,125,94,199,1,25,178,174,51,164,14,113,171,69,250,227,185,213,12,76,102,14,52,51,153,107,54,77,161,3,72,127,69,42,123,37,144,219,200,144,153,132,61,32,131,126,144,12,134,116,162,249,136,253,150,
    185,217,98,123,229,229,151,71,158,122,214,254,128,122,116,53,24,20,42,202,3,247,223,227,60,239,92,10,125,115,109,77,224,158,187,141,147,40,203,84,94,151,252,249,25,163,20,166,26,96,245,170,194,71,31,162,
    178,85,13,5,77,85,85,129,135,31,48,85,86,176,54,155,247,154,43,50,91,243,254,240,42,215,247,46,214,227,113,61,145,240,92,241,3,207,85,87,100,122,136,253,51,37,14,111,178,181,181,243,119,79,42,3,131,130,
    197,168,170,13,1,56,78,79,95,56,206,100,162,88,167,107,108,247,23,217,106,230,14,188,248,18,37,106,98,160,76,102,148,232,199,159,228,95,116,129,174,164,88,142,215,135,47,52,89,68,31,215,211,22,177,233,
    219,153,232,227,244,84,112,56,105,35,123,110,190,205,24,247,154,26,233,27,143,127,99,83,213,207,255,117,223,47,238,72,132,7,124,86,235,14,158,213,77,83,248,221,104,118,209,162,165,95,254,188,215,213,148,
    80,71,216,188,183,219,110,23,43,203,242,123,122,195,253,131,19,220,118,58,191,182,84,86,82,77,123,186,179,109,199,100,226,231,206,46,138,12,37,218,58,6,14,249,165,180,181,104,52,217,210,222,95,61,187,
    208,108,18,26,154,187,114,73,247,41,179,173,155,91,146,72,200,123,91,122,39,154,142,244,121,92,54,218,67,249,80,247,120,7,242,221,121,126,231,206,221,237,118,187,165,162,44,143,118,152,118,123,92,155,
    202,242,124,187,77,108,220,211,165,40,71,230,215,39,28,86,243,150,247,182,28,182,175,219,218,219,243,220,178,147,46,235,30,8,121,220,140,70,249,18,79,163,39,107,220,186,167,218,231,207,147,123,122,228,
    94,227,156,219,170,231,82,177,18,107,110,54,187,189,150,89,85,209,237,219,141,198,164,135,44,89,138,138,76,62,159,150,72,106,138,146,108,107,165,17,64,83,100,75,73,41,239,118,197,118,238,116,44,88,144,
    252,188,133,119,59,5,167,51,214,208,64,239,26,19,121,146,228,88,188,40,190,187,81,9,14,20,93,118,169,174,40,221,127,124,198,226,207,43,224,249,31,218,196,110,151,119,198,211,164,241,235,15,177,132,213,
    106,206,140,21,147,172,51,28,178,102,72,143,10,41,81,60,116,55,79,65,54,114,111,82,48,24,205,243,59,188,110,107,223,64,14,179,171,233,251,56,178,101,98,201,164,164,218,205,52,208,29,82,6,155,205,148,89,
    145,200,86,51,164,39,223,34,22,209,91,144,231,236,232,10,29,17,25,122,250,7,95,218,176,97,205,57,231,28,198,239,100,247,167,245,186,150,10,71,41,149,55,18,27,222,20,220,252,134,96,119,9,46,55,189,51,180,
    117,43,245,239,98,160,48,21,29,26,220,244,55,147,39,159,183,90,141,5,59,139,45,222,216,148,254,184,206,242,130,201,239,215,213,20,79,47,54,53,107,82,66,44,42,9,190,245,166,217,151,175,244,247,171,73,122,
    90,76,239,178,102,51,167,105,161,45,111,138,129,82,147,199,219,254,228,99,198,144,152,87,92,206,241,175,243,76,147,213,230,156,202,174,79,79,70,171,142,76,186,167,215,25,178,165,25,233,155,219,212,201,
    103,147,98,177,36,157,78,147,48,153,15,84,33,20,23,186,70,182,22,12,27,51,244,30,183,149,231,114,42,29,38,89,9,137,197,36,122,215,237,178,76,190,5,191,207,46,24,119,49,169,195,133,178,58,161,12,209,152,
    36,201,138,205,106,178,90,76,71,68,6,187,221,113,211,141,55,235,135,245,23,15,245,204,236,167,177,40,225,112,24,151,138,30,107,154,88,80,68,98,80,248,210,143,41,63,223,148,151,71,9,41,203,113,98,65,9,
    213,3,122,230,76,210,91,62,159,201,79,63,126,193,227,214,51,107,154,106,74,112,187,204,5,1,122,64,27,161,130,129,119,57,205,5,5,195,239,170,148,59,209,70,140,76,76,16,172,5,165,150,130,82,59,203,81,231,
    244,123,139,105,74,247,111,79,155,12,102,129,77,38,229,145,100,58,91,80,106,57,44,168,13,4,99,212,172,32,207,62,73,155,178,34,183,150,49,33,125,153,105,171,253,3,81,122,133,12,201,225,79,87,233,233,61,
    156,248,221,164,148,146,101,197,98,230,39,9,95,167,67,244,56,69,69,86,180,97,255,181,44,50,24,243,155,93,97,99,199,2,78,241,80,171,203,2,207,5,242,28,211,30,155,156,96,185,122,154,238,93,205,93,135,35,
    75,165,166,255,222,204,239,155,218,168,48,117,25,138,2,78,151,115,188,109,14,187,153,10,176,193,144,145,49,43,198,237,66,154,197,34,28,220,151,83,178,110,168,112,40,25,226,9,37,158,84,76,38,46,223,111,
    59,120,142,136,138,138,210,34,23,199,179,237,93,145,209,107,5,193,112,98,40,38,81,161,85,92,228,18,197,172,185,31,213,217,20,180,146,146,50,214,234,15,154,231,201,76,148,247,244,69,105,63,3,249,246,9,
    125,160,65,195,239,181,246,7,227,131,225,132,154,62,22,218,160,177,176,146,69,6,73,78,245,14,196,168,1,157,58,167,221,156,101,160,99,93,14,177,180,216,101,181,78,127,181,205,243,252,107,155,222,122,224,
    254,251,15,95,154,116,228,160,235,81,173,234,175,155,185,39,28,118,59,63,229,209,88,152,162,58,186,199,105,22,205,92,52,102,252,29,12,10,30,138,24,183,211,76,245,104,44,46,167,147,126,141,50,13,171,69,
    40,204,183,199,226,10,5,9,69,152,69,164,142,86,232,234,53,186,252,92,38,106,40,28,11,243,108,86,145,47,45,116,210,70,100,133,250,93,227,230,106,218,142,197,8,116,189,179,59,34,27,203,220,106,250,240,247,
    211,219,31,243,123,44,118,155,41,224,183,202,178,154,144,84,99,234,149,70,79,214,152,141,32,13,108,86,129,182,211,214,53,52,24,76,228,121,45,133,249,182,240,144,76,213,3,53,48,155,56,135,205,68,79,35,
    81,153,6,135,193,96,220,227,18,243,125,22,73,54,37,146,228,183,49,244,83,27,187,213,68,135,19,141,74,225,72,210,235,18,135,235,31,93,155,244,14,142,161,168,68,89,153,207,99,241,186,69,58,87,241,68,138,
    142,200,88,151,100,141,209,128,234,19,91,186,239,72,165,82,3,193,25,249,221,113,135,195,121,207,111,30,160,48,189,254,134,235,15,83,154,116,216,201,252,81,191,90,85,255,200,196,221,236,176,121,69,219,
    23,216,200,212,100,232,232,137,186,157,162,211,110,18,61,188,170,233,108,186,55,141,39,83,253,131,7,38,82,250,131,9,191,199,74,129,75,23,126,116,250,145,82,245,244,223,145,201,101,61,75,39,115,40,28,41,
    178,41,130,109,163,250,75,10,205,96,88,162,8,54,198,25,85,163,13,142,73,177,66,73,218,25,234,128,41,112,157,7,117,252,212,126,40,166,100,6,159,136,192,57,236,38,151,227,192,30,210,126,81,241,156,121,76,
    74,144,108,164,61,141,30,166,81,109,200,165,193,80,50,26,207,220,133,193,100,134,166,244,156,65,182,41,131,225,226,33,174,36,101,149,190,142,226,126,220,17,165,135,83,99,181,116,40,38,207,92,172,120,60,
    190,123,239,123,176,169,177,241,193,135,31,250,199,75,147,232,178,57,117,189,66,99,94,49,115,63,117,218,93,150,47,152,109,78,207,212,42,248,127,129,44,75,78,135,229,206,187,238,60,253,244,211,103,112,
    106,181,107,32,52,131,127,107,117,124,94,100,209,153,82,77,143,114,236,83,34,255,204,81,245,23,245,192,209,140,217,44,74,178,254,253,203,214,94,120,193,55,54,110,156,254,63,53,107,183,103,166,61,116,118,
    248,110,237,233,253,97,134,31,80,212,138,58,147,167,233,213,154,238,96,153,13,102,254,82,167,229,57,183,247,203,152,192,224,175,112,31,131,120,125,121,77,123,90,175,184,252,170,64,32,127,229,202,83,86,
    174,90,89,83,91,91,88,88,232,112,124,217,185,172,72,50,65,35,66,21,195,244,205,224,100,46,171,49,186,194,176,17,150,217,197,115,31,243,220,70,139,185,83,180,58,5,179,253,203,111,26,105,210,177,140,170,
    170,201,68,156,231,88,171,213,66,240,153,187,83,39,249,31,50,176,163,202,213,145,7,250,254,73,177,152,174,21,244,116,47,86,212,24,55,35,25,71,230,171,140,255,63,3,199,245,8,66,72,16,24,193,108,153,190,
    255,63,3,100,0,0,53,3,0,144,1,128,9,249,63,1,6,0,185,232,59,117,80,227,182,197,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* StructureGUI::authorization_png = (const char*) resource_StructureGUI_authorization_png;
const int StructureGUI::authorization_pngSize = 7678;

// JUCER_RESOURCE: lock2small_png, 5834, "/lock2small.png"
static const unsigned char resource_StructureGUI_lock2small_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,87,0,0,1,163,8,6,0,0,0,152,50,86,23,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,4,103,
    65,77,65,0,0,177,143,11,252,97,5,0,0,0,9,112,72,89,115,0,2,180,12,0,2,180,12,1,207,83,107,90,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,112,97,105,110,116,46,110,101,116,32,52,46,48,46,49,
    57,212,214,178,100,0,0,22,58,73,68,65,84,120,94,237,221,9,144,100,119,93,192,113,54,36,129,132,27,57,12,114,5,2,42,168,144,130,160,2,162,114,99,9,138,8,120,16,5,42,30,101,64,20,148,67,69,176,184,44,144,
    75,32,148,72,10,138,155,8,65,144,42,196,24,67,5,36,160,1,13,108,9,86,1,37,193,205,102,118,54,59,179,51,211,211,247,224,239,77,255,65,96,55,201,255,191,59,175,223,235,55,159,79,213,171,158,221,192,246,
    191,251,253,223,183,255,175,167,143,27,0,0,0,0,0,0,0,0,0,0,0,0,64,43,124,243,155,223,188,113,250,17,128,163,249,250,215,191,126,247,136,229,253,6,131,193,227,86,86,86,254,40,126,126,241,214,214,214,95,
    197,159,47,218,220,220,188,34,126,254,218,81,182,165,163,252,221,215,250,253,254,23,123,189,222,197,241,243,235,171,127,103,109,109,237,185,241,231,39,84,255,254,149,87,94,121,70,186,74,128,110,136,184,
    237,169,226,54,30,143,159,48,28,14,95,53,157,78,63,16,241,220,31,17,236,199,54,137,255,94,187,184,206,105,117,125,113,253,75,147,201,228,35,113,249,154,248,235,39,94,117,213,85,247,138,203,61,105,168,
    0,237,180,119,239,222,147,99,5,121,215,88,117,254,90,4,236,181,209,180,207,68,204,198,219,133,107,169,24,95,229,115,49,222,243,98,220,103,199,95,221,45,66,124,163,116,147,0,154,113,240,224,193,59,70,152,
    158,62,26,141,222,27,81,218,23,219,214,44,91,139,169,26,127,216,31,183,233,239,227,54,253,206,202,202,202,233,233,166,2,212,39,250,179,39,86,120,15,137,248,252,69,172,248,190,26,33,106,245,202,244,120,
    197,237,171,86,182,87,198,237,125,249,120,60,254,217,248,43,79,35,0,59,99,223,190,125,167,198,42,238,33,113,154,255,166,8,205,129,89,118,118,167,184,15,14,197,246,150,126,191,255,136,165,165,165,155,166,
    187,8,32,95,172,214,126,52,66,242,230,216,150,82,91,248,14,177,170,61,24,171,217,183,197,253,116,102,186,203,0,142,238,242,203,47,63,41,98,241,244,8,234,101,17,143,105,234,8,215,33,238,167,234,185,131,
    43,98,117,255,187,241,199,147,211,93,9,236,118,17,132,61,113,154,123,122,172,194,94,29,145,56,188,93,12,142,73,220,127,189,120,96,122,211,96,48,184,103,252,209,243,179,176,91,109,110,110,62,40,130,240,
    225,8,66,167,127,49,53,111,113,127,78,98,37,123,81,60,104,61,44,221,213,192,110,80,189,43,42,162,122,73,117,74,155,122,64,13,170,251,55,206,8,62,27,247,245,147,226,143,86,178,208,69,213,193,29,43,213,
    7,198,138,234,226,237,35,159,185,138,200,126,58,86,178,213,203,185,78,72,187,4,88,116,17,213,7,199,234,233,34,43,213,102,85,247,127,236,135,127,141,200,62,60,237,26,96,17,29,56,112,224,180,233,116,250,
    119,162,218,46,41,178,255,24,15,122,119,73,187,10,88,4,251,247,239,191,201,96,48,120,81,132,117,144,142,103,90,40,246,207,104,56,28,190,50,90,123,179,180,235,128,182,138,168,62,54,14,214,171,210,241,203,
    2,136,200,46,71,100,159,28,63,250,165,23,180,77,4,245,180,56,213,252,104,117,202,57,59,100,89,36,213,110,27,143,199,159,232,247,251,119,77,187,20,104,82,28,151,213,187,170,158,26,97,189,102,118,152,178,
    200,98,21,123,120,52,26,61,51,98,235,163,15,161,41,113,0,222,41,162,250,177,116,92,210,33,177,95,63,89,189,211,43,237,106,96,94,226,244,241,81,113,0,94,157,142,69,58,40,86,177,215,68,96,127,57,237,114,
    160,78,113,204,157,58,28,14,207,155,29,126,236,6,163,209,232,221,113,150,226,21,5,80,151,88,173,222,125,60,30,239,77,199,28,187,72,156,165,124,37,86,177,247,74,83,1,216,41,189,94,239,177,113,128,109,164,
    99,141,93,104,58,157,86,95,180,248,171,105,74,0,199,163,250,173,113,245,134,128,184,244,18,43,182,223,221,21,129,125,77,92,156,146,166,8,80,42,14,160,155,196,106,245,227,233,184,130,111,139,121,113,217,
    202,202,202,45,211,84,1,114,69,88,239,52,30,143,47,75,199,18,28,33,230,199,23,99,158,156,145,166,12,112,125,214,215,215,127,36,14,154,125,233,24,130,107,85,189,117,182,215,235,61,32,77,29,224,218,108,
    108,108,156,25,167,124,43,233,216,129,235,85,253,162,115,115,115,243,167,211,20,2,190,87,156,230,61,34,86,172,253,116,204,64,182,152,55,163,216,126,33,77,37,224,91,98,245,113,118,117,128,164,99,5,138,
    197,252,137,105,52,121,70,154,82,192,112,56,60,103,58,157,78,210,49,178,235,140,70,163,141,184,253,255,25,43,247,79,245,251,253,15,69,36,94,22,219,11,15,30,60,248,172,125,251,246,157,179,188,188,124,246,
    250,250,250,147,226,191,255,98,117,89,253,185,250,251,253,251,247,255,126,245,191,139,237,37,241,255,187,48,238,199,75,227,231,207,199,191,183,158,254,233,93,39,110,255,52,110,255,31,167,169,5,187,87,
    172,52,158,22,7,196,174,8,107,4,116,26,129,252,74,28,252,23,196,237,126,206,218,218,218,227,227,175,79,221,187,119,239,201,113,185,35,159,101,90,253,59,177,157,20,247,233,41,135,15,31,174,222,120,241,
    172,193,96,240,190,184,252,210,110,185,159,83,96,159,157,238,18,216,125,226,32,120,74,108,157,253,90,235,104,233,246,138,52,182,87,71,84,31,125,232,208,161,91,164,155,222,136,24,210,169,49,142,71,198,
    246,170,136,237,229,49,174,195,179,145,118,79,245,64,18,60,69,192,238,19,147,255,254,93,12,107,28,208,7,34,94,239,138,83,244,167,196,202,241,251,210,205,109,165,234,69,248,49,206,39,198,120,207,143,113,
    119,238,165,111,85,96,99,123,104,186,185,208,125,27,27,27,247,141,85,83,47,29,3,11,47,110,203,48,182,247,196,237,122,76,252,241,196,116,51,23,202,37,151,92,114,98,196,246,97,113,59,222,25,219,230,236,
    150,45,190,120,208,24,174,173,173,253,84,186,153,208,93,213,39,27,197,132,95,78,115,127,97,197,138,40,26,52,189,98,52,26,157,219,246,21,106,169,184,109,55,175,126,201,24,251,233,115,213,234,47,221,228,
    133,21,251,105,37,246,211,253,211,205,131,238,57,120,240,224,205,227,96,93,232,47,15,140,3,117,24,7,234,133,177,157,149,110,86,167,197,106,252,62,227,241,248,189,113,187,23,250,245,199,49,239,174,137,
    21,236,109,211,205,130,238,168,190,238,58,14,210,79,166,185,190,112,170,184,196,248,223,120,232,208,161,59,167,155,180,171,92,125,245,213,183,143,219,255,170,184,31,22,246,99,31,99,252,87,196,69,163,191,
    84,132,29,21,19,250,132,56,40,47,220,158,225,11,38,86,60,189,24,251,249,155,155,155,119,73,55,103,87,139,149,236,105,213,131,76,220,47,107,233,46,90,40,177,47,47,190,224,130,11,110,152,110,14,44,182,56,
    133,126,126,28,140,11,245,121,172,49,220,73,140,251,93,85,76,210,205,224,59,196,41,246,109,226,254,121,75,196,106,161,158,147,173,166,97,181,2,79,55,3,22,87,172,248,30,56,153,76,166,105,110,47,132,56,
    248,62,27,225,248,201,248,113,71,94,216,223,101,17,171,251,196,254,189,100,118,207,45,134,24,243,116,48,24,252,92,186,9,176,120,14,28,56,112,90,172,108,14,165,57,221,122,17,137,67,17,213,115,227,199,19,
    210,77,32,67,220,95,123,134,195,225,83,227,254,59,176,125,71,46,128,152,151,27,43,43,43,167,167,155,0,139,35,230,239,137,49,129,63,61,155,202,237,22,227,172,222,206,243,193,248,241,86,105,248,28,131,234,
    213,32,177,234,127,71,220,159,11,113,166,18,195,252,66,92,156,148,134,15,139,33,98,245,162,217,20,110,183,56,192,214,98,172,79,78,195,102,7,196,41,119,245,153,6,11,113,198,18,15,6,231,165,97,67,251,197,
    169,245,89,17,173,86,191,181,117,171,250,141,213,100,242,169,213,213,213,187,165,97,179,131,122,189,222,15,196,253,251,241,234,126,78,119,121,43,85,171,236,8,236,35,211,176,161,189,226,88,186,117,76,214,
    255,77,115,183,149,102,199,211,248,101,241,163,231,86,107,20,247,239,158,120,160,125,94,220,223,195,237,59,190,165,226,65,96,57,230,237,29,210,176,161,157,34,90,239,76,115,182,149,226,64,223,140,211,214,
    199,165,225,50,7,213,87,176,196,253,222,234,215,197,70,96,63,154,134,11,237,19,97,125,76,172,0,90,251,203,140,56,192,191,188,178,178,114,215,52,92,230,104,99,99,227,251,35,96,255,145,118,69,235,196,220,
    168,158,38,250,245,52,92,104,143,165,165,165,155,198,228,108,237,211,1,49,182,127,138,240,223,62,13,151,6,84,79,25,69,196,62,144,118,73,235,196,28,57,184,186,186,122,235,52,92,104,135,88,181,190,57,205,
    209,214,25,141,70,239,143,11,207,175,182,64,236,135,234,53,177,127,179,189,99,90,40,2,251,129,52,84,104,94,175,215,251,137,88,149,180,238,213,1,49,166,234,115,1,223,22,63,122,47,121,139,196,254,168,62,
    107,226,117,213,254,217,222,81,45,82,77,153,126,191,255,168,52,84,104,78,245,33,203,241,104,255,111,105,110,182,74,28,192,111,136,11,97,109,161,106,191,196,254,121,121,27,3,27,243,249,191,226,194,155,
    11,104,86,156,226,61,109,54,37,219,37,142,217,63,72,67,164,197,98,63,157,157,118,89,171,12,6,131,231,165,33,194,252,197,129,113,163,88,125,124,35,205,199,86,168,86,66,225,252,248,209,138,117,1,196,126,
    58,33,246,215,107,170,157,182,189,3,91,34,230,245,193,229,229,229,155,165,97,194,124,141,199,227,215,166,185,216,26,113,80,188,61,46,132,117,129,84,159,175,26,251,237,117,179,61,216,30,49,166,119,167,
    33,194,252,244,122,189,59,196,228,107,213,59,111,134,195,97,245,129,220,94,21,176,128,98,191,237,137,83,241,183,110,239,200,150,136,197,244,36,198,116,143,52,68,152,143,88,181,158,151,230,96,43,68,232,
    255,61,46,22,242,155,87,153,137,253,87,61,69,240,207,219,59,180,37,70,163,209,5,105,120,80,191,205,205,205,59,71,204,6,105,254,53,110,50,153,124,181,122,7,80,26,30,11,172,250,38,221,120,224,222,155,118,
    109,227,34,246,195,88,189,254,96,26,30,212,43,38,255,91,210,220,107,92,21,249,88,93,220,47,13,141,14,136,160,157,17,251,181,53,95,132,24,15,222,31,138,11,223,74,65,189,226,81,252,158,49,241,91,241,189,
    73,113,16,78,99,21,253,196,52,52,58,164,223,239,63,188,218,191,105,87,55,42,230,251,180,215,235,61,32,13,13,234,49,28,14,91,243,54,215,24,203,95,199,133,21,69,7,85,251,53,206,144,94,188,189,163,91,32,
    206,142,62,152,134,6,59,175,250,38,212,120,16,111,197,43,4,210,243,114,55,77,67,163,131,98,229,122,74,236,231,207,204,246,120,179,98,44,147,88,77,159,145,134,6,59,43,38,250,43,210,92,107,212,100,50,233,
    197,74,226,172,52,44,58,108,48,24,252,80,60,160,175,164,93,223,168,152,255,127,155,134,5,59,167,90,69,68,212,174,78,243,172,81,17,86,111,109,221,69,134,195,225,83,210,174,111,84,68,254,154,184,112,182,
    196,206,138,160,253,246,108,138,53,43,2,255,169,184,240,122,214,93,36,246,247,9,177,223,63,186,61,1,26,22,199,193,11,211,176,96,103,180,225,185,175,88,57,12,98,21,115,102,26,18,187,72,122,149,74,47,77,
    133,198,68,228,191,28,23,222,5,200,206,216,216,216,56,115,54,181,154,21,97,253,203,52,36,118,161,8,236,31,166,169,208,168,234,101,98,105,72,112,124,98,213,218,248,123,190,99,213,82,125,133,140,21,195,
    46,22,251,127,79,204,131,106,229,216,168,88,189,126,36,13,9,142,221,202,202,202,45,99,66,55,250,110,153,173,16,171,214,167,166,33,177,139,197,234,245,177,213,124,72,83,163,17,113,60,12,215,215,215,125,
    31,27,199,39,30,165,127,51,205,169,198,196,24,46,141,11,111,22,224,91,171,215,234,237,168,141,26,141,70,62,76,155,227,19,19,249,146,52,159,26,17,139,148,233,120,60,126,104,26,14,84,175,92,185,127,204,
    203,70,223,26,27,87,255,185,52,28,40,23,97,187,109,76,162,70,63,253,42,174,255,147,105,56,240,109,49,47,254,33,77,145,70,84,207,84,245,122,189,59,166,225,64,153,56,29,111,244,251,177,170,231,214,54,55,
    55,31,148,134,3,223,54,28,14,239,29,129,109,116,245,58,24,12,94,144,134,3,101,34,174,31,75,243,168,17,113,236,92,154,134,2,71,136,249,89,125,243,68,99,226,250,47,143,11,191,11,160,204,222,189,123,79,142,
    184,53,246,209,130,213,170,181,223,239,255,76,26,14,28,97,99,99,227,190,213,60,73,83,102,238,170,149,243,210,210,146,183,195,82,38,78,121,126,62,205,161,70,196,170,224,75,113,225,109,174,92,171,152,31,
    213,219,98,63,187,61,97,26,50,28,14,207,73,195,129,60,227,241,248,245,105,254,52,34,38,237,111,165,161,192,181,138,121,250,248,52,101,26,17,113,247,29,91,228,139,57,115,195,152,180,75,179,233,51,127,113,
    182,181,182,186,186,122,235,52,28,184,86,91,91,91,55,139,249,114,40,77,157,185,139,227,100,45,46,156,97,145,103,48,24,252,112,76,216,198,158,203,138,9,123,126,26,10,92,175,152,47,47,75,83,103,238,170,
    231,124,55,55,55,31,156,134,2,215,173,223,239,63,35,205,157,70,140,124,16,54,5,98,49,112,143,104,92,99,47,203,26,14,135,47,77,67,129,235,54,153,76,62,152,230,205,220,197,138,249,43,105,24,144,45,230,236,
    231,211,20,154,187,184,238,127,73,195,128,107,23,115,165,122,9,214,55,102,211,102,254,98,21,240,242,52,20,200,22,103,91,207,76,83,104,238,226,120,57,16,23,55,78,67,129,163,139,211,171,234,45,175,141,60,
    223,90,93,239,129,3,7,238,145,134,2,217,150,151,151,239,208,212,83,3,213,243,174,222,10,203,245,218,220,220,252,149,52,103,230,46,226,250,223,113,225,51,91,41,22,243,166,250,180,172,198,94,243,26,113,
    125,86,26,10,28,93,156,150,191,54,205,151,185,139,131,195,183,107,114,204,98,254,188,52,77,165,185,27,12,6,239,79,195,128,163,139,9,218,216,103,101,246,251,125,31,45,200,49,27,141,70,247,75,83,105,238,
    182,182,182,46,75,195,128,163,139,149,107,35,223,17,31,81,223,88,93,93,189,85,26,6,20,91,94,94,174,222,80,176,154,166,212,92,141,199,227,234,219,58,188,153,128,163,219,191,127,255,237,102,83,101,254,38,
    147,137,15,31,230,184,197,234,181,177,15,119,95,89,89,57,61,13,3,190,91,156,150,63,34,205,147,185,139,21,243,27,210,48,224,152,69,92,95,144,166,212,220,197,28,62,59,13,3,190,91,196,245,220,52,79,230,110,
    48,24,60,46,13,3,142,89,175,215,251,241,52,165,230,46,226,234,157,90,28,93,76,142,198,62,9,107,125,125,253,118,105,24,112,204,98,42,221,98,107,107,171,145,207,33,246,9,89,92,171,233,116,250,158,52,79,
    230,42,78,229,14,197,213,251,68,119,118,68,156,5,237,75,83,107,174,34,234,23,165,33,192,119,235,247,251,141,188,237,53,162,254,241,52,4,56,110,49,159,222,158,166,214,92,69,212,175,73,67,128,239,22,143,
    188,235,105,158,204,149,95,102,177,147,34,114,127,146,166,214,92,197,241,51,74,67,128,255,183,111,223,190,59,199,35,254,56,205,147,185,154,76,38,231,166,97,192,113,27,143,199,191,148,166,214,92,69,92,
    167,251,247,239,191,119,26,6,204,172,175,175,223,59,38,71,35,31,216,178,180,180,244,200,52,12,56,110,87,94,121,229,89,105,106,205,85,117,248,172,173,173,61,36,13,3,102,98,98,252,88,154,35,115,23,215,125,
    243,52,12,56,110,49,159,110,148,166,214,220,197,117,63,44,13,3,102,226,84,234,209,105,126,204,85,92,111,63,78,165,110,146,134,1,199,173,250,90,248,225,112,88,189,29,117,238,38,147,201,111,164,97,192,204,
    202,202,202,57,105,126,204,213,116,58,93,170,86,26,105,24,112,220,98,90,157,24,145,251,159,217,12,155,175,213,213,213,63,75,195,128,153,209,104,244,252,52,63,230,42,194,250,197,52,4,216,49,49,181,62,49,
    155,97,243,85,189,17,39,13,1,102,34,114,127,154,230,199,92,197,202,245,11,105,8,176,99,98,94,53,242,1,46,113,28,189,49,13,1,102,154,138,235,198,198,198,165,105,8,176,99,14,31,62,124,97,154,98,115,37,174,
    28,161,169,184,246,122,189,139,211,16,96,199,196,131,246,251,210,20,155,43,113,229,8,77,197,117,48,24,124,44,13,1,118,76,191,223,127,71,154,98,115,37,174,28,161,169,184,78,38,147,15,167,33,192,142,25,
    141,70,111,77,83,108,174,196,149,35,52,21,215,184,222,87,166,33,192,142,137,121,245,236,52,197,230,74,92,57,66,131,113,125,69,26,2,236,152,152,87,207,76,83,108,174,196,149,35,136,43,93,34,174,180,134,
    184,210,37,226,74,107,136,43,93,34,174,180,134,184,210,37,226,74,107,136,43,93,34,174,180,134,184,210,37,226,74,107,136,43,93,34,174,180,134,184,210,37,226,74,107,136,43,93,34,174,180,134,184,210,37,226,
    74,107,136,43,93,34,174,180,134,184,210,37,226,74,107,136,43,93,34,174,180,134,184,210,37,226,74,107,136,43,93,34,174,180,134,184,210,37,226,74,107,136,43,93,34,174,180,134,184,210,37,226,74,107,136,43,
    93,34,174,180,134,184,210,37,226,74,107,136,43,93,34,174,180,134,184,210,37,226,74,107,136,43,93,34,174,180,134,184,210,37,226,74,107,136,43,93,34,174,180,134,184,210,37,226,74,107,136,43,93,34,174,180,
    134,184,210,37,226,74,107,136,43,93,34,174,180,134,184,210,37,226,74,107,136,43,93,34,174,180,134,184,210,37,226,74,107,136,43,93,34,174,180,134,184,210,37,226,74,107,136,43,93,34,174,180,134,184,210,
    37,226,74,107,136,43,93,34,174,180,134,184,210,37,226,74,107,136,43,93,34,174,180,134,184,210,37,226,74,107,136,43,93,34,174,180,134,184,210,37,226,74,107,136,43,93,34,174,29,21,119,240,115,98,91,90,176,
    109,61,205,143,185,138,235,221,248,158,113,216,108,59,177,173,165,41,54,87,113,189,155,223,51,142,69,216,94,153,210,213,126,49,216,63,79,247,53,64,171,69,175,222,156,210,213,126,226,10,44,10,113,5,168,
    129,184,2,212,64,92,1,106,32,174,0,53,16,87,128,26,136,43,64,13,196,21,160,6,226,10,80,3,113,5,168,129,184,2,212,64,92,1,106,32,174,0,53,16,87,128,26,136,43,64,13,196,21,160,6,226,10,80,3,113,5,168,129,
    184,2,212,64,92,1,106,32,174,0,53,16,87,128,26,136,43,64,13,196,21,160,6,226,10,80,3,113,5,168,129,184,2,212,64,92,1,106,32,174,25,226,122,95,29,23,183,177,217,108,139,183,197,241,251,220,184,156,59,113,
    205,16,215,251,146,52,4,96,193,196,241,251,123,233,80,158,43,113,205,32,174,176,184,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,
    184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,
    53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,
    2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,
    131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,
    196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,
    184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,
    53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,
    2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,
    131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,
    196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,
    184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,
    53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,
    2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,
    131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,
    196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,
    184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,
    53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,
    2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,131,184,2,165,196,53,67,131,113,29,197,182,
    97,179,217,22,114,27,166,67,121,174,226,122,197,21,96,167,137,43,64,13,196,21,160,6,226,10,80,3,113,5,168,129,184,2,212,64,92,1,106,32,174,0,53,16,87,128,26,136,43,64,13,196,21,160,6,226,10,80,3,113,5,
    168,129,184,2,212,64,92,1,106,32,174,0,53,16,87,128,26,136,43,64,13,196,21,160,6,226,10,80,3,113,5,168,129,184,2,212,64,92,1,106,32,174,0,53,16,87,128,26,136,43,64,13,196,21,160,6,226,10,80,3,113,5,168,
    193,66,197,53,198,123,82,12,248,20,155,205,102,107,251,22,189,58,57,165,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,58,221,224,6,255,7,35,151,129,121,215,12,229,197,0,0,0,0,73,69,78,68,174,66,
    96,130,0,0};

const char* StructureGUI::lock2small_png = (const char*) resource_StructureGUI_lock2small_png;
const int StructureGUI::lock2small_pngSize = 5834;



//[EndFile] You can add extra defines here...
//[/EndFile]
