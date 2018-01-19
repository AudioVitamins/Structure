/* Copyright (C) 2016 Andrew Shakinovsky
*/
#ifndef EDITOR_STATE_H_
#define EDITOR_STATE_H_
#include "../JuceLibraryCode/JuceHeader.h"
/**
The Editor State keeps track of current editor settings (does not keep track of any data in the 
sequencer, just current editor settings such as whether we are in velocity edit mode, how sensitive
the mouse is, etc)
This will also return needed colors for various things (in case we want to allow theming later)
*/



class EditorState {
public:
   EditorState();
   ~EditorState();

   // note the order of these need to correspond with ordering (and elements) in Colors.h
   enum coloredElements {
      background=0,
      stepDisabled,      // eg if we have less steps than 16
      stepOff,           // step is off (ie 0 prob)
      stepNeverProb,     // probability of never (only useful for chain)
      stepLowProb,       // low prob
      stepMediumProb,    // med prob
      stepHighProb,      // high prob
      stepLowVel,        // low velocity
      stepMedVel,        // medium velocity
      stepHighVel,       // high velocity
      playIndicatorOff,
      playIndicatorOn,
      noteEditable,
      noteLocked,
      toggleOff,        // for things on the main ui that have a toggle state
      toggleOn,
      button,           // other buttons
      interact,         // if we are interacting with something with the mouse
      border,           // any borders around things
      measureStart,
      beatStart,
      grooveEdit,
      ghostedNotes,     // ghosted notes from previous layer
      cellSelection,    // cursor around selected cells, and length cursor
      chainPositive,    // chain/dependency positive color
      chainNegative,    // chain/dependency negative color
      chainPositiveSel,    // chain/dependency positive color selected
      chainNegativeSel,    // chain/dependency negative color selected
      alertBackground,  // for the alert popup
      recordActive,     // record button when recording or standby
      recordPassive,    // record button when not recording
      //--- add more here^^^
      Count             // number of elements
   };

   int mUserColors[coloredElements::Count];
   
   // return the color to be used for a specific element
   juce::Colour getColorFor(coloredElements e);
   
   // color theme where 0=dark and 1=light
   int getColorTheme();
   void setColorTheme(int val);

   bool getUIDPWD(String &uid, String &pwd);
   void setUIDPWD(String uid, String pwd);
   
   // mouse sensitivity for dragging stuff. 1..SEQ_MOUSE_SENSE_MAX where 1 is highest and n is lower
   int getMouseSense();
   void setMouseSense(int val);
private:
   // read or write settings to the config file
   void configSerialization(bool read);
   // read/write individual int setting (min max ensure that values read from file are not out of range)
   // def is default value
   void configGetSetInt(juce::PropertiesFile *pf, bool read, int &val, 
      const char *key, int min, int max, int def);

   void configGetSetString(juce::PropertiesFile *pf, bool read, String &val,
      const char *key, const String &defaultVal);

   // load user colors from file into user slot
   // create the skin file if it doesn't exist
   void loadColorsFromFile();
   
   int mColorTheme; // 0=dark, 1=light
   String mUserId;
   String mPassword;
   int mMouseSense;
public:
   // stops us from keeping on showing this window
   bool mShownTrialWindow;
};


class SeqAudioProcessor;

// This holds pointers to our big objects to make it easy to pass around
// TODO not sure if it really belongs here
class SeqGlob {
public:

   // these are vestiges
   SeqGlob(EditorState *es) : mEditorState(es) {}
   
   EditorState *mEditorState;
   
};

// another shared funtion I don't know where to put
void fixColors(EditorState *e, Component * cpt);
// call this from "editorShown" when a label gets converted to a text edit box
// to fix colors and optionally limit max length
void fixDynamicTextEditBox(EditorState *e, TextEditor &te, int maxlen = 0);

void gradientFill(EditorState &e, Component *c, Graphics &g);
#endif
