/* Copyright (C) 2016 Andrew Shakinovsky
*/
#ifndef AUTHDIALOG_H_
#define AUTHDIALOG_H_

#include "../JuceLibraryCode/JuceHeader.h"
#include "EditorState.h"
#include "Constants.h"
#include "CommonComponents.h"


class SeqAuthDialog : public SeqModalDialog {
   ScopedPointer<Label> mLblTitle;
   ScopedPointer<Label> mLblDescription;
   ScopedPointer<Label> mLblUser;
   ScopedPointer<Label> mLblPw;
   ScopedPointer<Label> mLblKey;
   ScopedPointer<Label> mLblStatusMsg;
   ScopedPointer<TextEditor> mTxtUser;
   ScopedPointer<TextEditor> mTxtPw;
   ScopedPointer<TextEditor> mTxtKey;
   ScopedPointer<TextButton> mBtnOffline;
   ScopedPointer<TextButton> mBtnAuth;
   ScopedPointer<TextButton> mBtnClose;
   enum State {
      trial,   // trial mode (no uid pwd present yet), grace period (when we try to reauthorize), or expired
      valid,   // everything is good 
      offline  // in offline mode where they can enter key
   };
   State mState;
   // determine what state we should be in, makes no assumption about current state
   // reads in uid, pwd, key if possible and sets descriptive text
   void determineState();
   // enable disable stuff based on state
   void enableDisable();

public:
   void endDialog(bool hitOk) override;
   void doSetup();
   void notify(int id, int val) override;
   void resizedInner(Component *inner) override;
   SeqAuthDialog(SeqGlob *glob, CptNotify *parent);
   ~SeqAuthDialog();
};

#endif
