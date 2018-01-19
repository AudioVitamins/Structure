/* Copyright (C) 2016 Andrew Shakinovsky
*/
#ifndef TRIALDIALOG_H_
#define TRIALDIALOG_H_

#include "../JuceLibraryCode/JuceHeader.h"
#include "EditorState.h"
#include "Constants.h"
#include "AuthDialog.h"
#include "CommonComponents.h"

/*Displayed when in trial mode or not unlocked
  otherwise it will not be shown
*/
class SeqTrialDialog : public SeqModalDialog{
   ScopedPointer<Label> mLblTitle;
   ScopedPointer<Label> mLblDescription;
   ScopedPointer<Label> mLblEmail;
   ScopedPointer<Label> mLblTrialCode;
   ScopedPointer<Label> mLblBuyNow;
   ScopedPointer<TextEditor> mTxtEmail;
   ScopedPointer<TextEditor> mTxtTrialCode;
   ScopedPointer<TextButton> mBtnEmail;
   ScopedPointer<TextButton> mBtnAcceptTrialCode;
   ScopedPointer<TextButton> mBtnRegistration;
   ScopedPointer<TextButton> mBtnContinue;
   SeqAuthDialog mAuthDlg;
   ImageComponent mBackground;
   enum State {
      trialModeValid, // some days remain in trial mode
      locked,         // no codes exist, want email and/or unlock code      
      trialSent,      // after clicking send
      trialExpired,   // had trial, no longer valid
      emailFailed,    // failed to send email
      saveFailed,      // failed to save unlock code
      lockedWithFailure // they have a proper unlock code (non trial) that is failing
   };
   State mState;
   String mDaysRem;
   String mLastError;
   
   bool mClickedSend;
   bool mEmailFailed;
   bool mSaveFailed;
   bool mMainUnlockFailed;
   // determine what state we should be in
   void determineState();
   // enable disable stuff based on state
   void enableDisable();
   // check to see if we have a valid registration
   bool checkRegistration(bool trial);
   void mouseDown(const MouseEvent & event);
public:
   void endDialog(bool hitOk) override;
   void doSetup(const String &description=String());
   void notify(int id, int val) override;
   void resizedInner(Component *inner) override;
   SeqTrialDialog(SeqGlob *glob, CptNotify *parent);
   ~SeqTrialDialog();

   
};

#endif
