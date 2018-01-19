/* Copyright (C) 2016 Andrew Shakinovsky
*/
#include "TrialDialog.h"
#include "auth.h"
#include "unlockcode.h" // for constant only
//#include "SeqImageX.h"
#include "../LifeGUI.h" // so we can access the image resource for background

void SeqTrialDialog::endDialog(bool hitOk)
{
   bool b;
   b = hitOk;
   notifyParent(0);
}

void SeqTrialDialog::doSetup(const String &txt)
{
   String key;
   // if an existing trial code exists, show it
   if (seqReadKeyFromFile(key, true)) {
      mTxtTrialCode->setText(key, juce::dontSendNotification);
   }
   mLastError = "";
   if (txt.length()) {
      // if text is incoming, it means we were unable to renew their
      // licensed product, so we kick them into here
      mLastError = txt;
      mMainUnlockFailed = true;
   }
   else
      mMainUnlockFailed = false;
   
   mClickedSend = false;
   mEmailFailed = false;
   mSaveFailed = false;
   // if we are in this dialog, it's assumed that they either are unregistered or in
   // trial mode
   determineState();
   mMainUnlockFailed = false; // reset this
   enableDisable();
   
}

void SeqTrialDialog::determineState()
{
   String uid, pwd, key, txt;
   int days;
   mState = locked;
   if (mClickedSend) {
      if (mEmailFailed)
         mState = emailFailed;
      else
         mState = trialSent;
      return;
   }
   if (mSaveFailed) {
      mState = saveFailed;
      return;
   }
   if (mMainUnlockFailed) {
      mState = lockedWithFailure;
      return;
   }
   // see if we have a trial key
   if (seqReadKeyFromFile(key, true)) { // check for TRIAL
      // see if it's valid
      days = seqAuthorize(key, uid, mLastError, true);
      if (days > 0) {
         mDaysRem = String::formatted("%d", days);
         mState = trialModeValid;
      }
      else {
         mState = trialExpired;
         
      }
   } 
}

#ifdef LIFE_BETA
#define BETA_TRIAL "Beta"
#else
#define BETA_TRIAL "Trial"
#endif

void SeqTrialDialog::enableDisable()
{
   juce::String txt;
   mTxtEmail->setEnabled(false);
   mTxtTrialCode->setEnabled(false);
   mBtnEmail->setEnabled(false);
   mBtnAcceptTrialCode->setEnabled(false);
   mBtnContinue->setVisible(false);       // will be hidden when locked

#ifndef LIFE_BETA
   mBtnRegistration->setEnabled(true);    // always enabled
#else
   mBtnRegistration->setEnabled(false);    // always enabled
#endif

   switch (mState) {
   case saveFailed:      
   case locked:
   case trialExpired:
   case emailFailed:
   case lockedWithFailure:

      mTxtEmail->setEnabled(true);
      mTxtTrialCode->setEnabled(true);
      mBtnEmail->setEnabled(true);
      mBtnAcceptTrialCode->setEnabled(true);      
      if (mState == emailFailed) {
         txt = mLastError +". To get a trail code, please visit \n" SEQ_TRIAL_URL_FRIENDLY;
      }
      else if (mState == lockedWithFailure) {
         // just display this text. it means that we were unable to unlock their
         // purchased product, so there is a problem
         txt = mLastError;
      }
      else {
         if (mState == trialExpired || mState==saveFailed) {
            txt = mLastError;
            if (txt.length())
               txt += "\n";
         }
#ifdef LIFE_BETA
         txt += "This is a pre-release time-limited version of Life.\n"
            "To use this version, enter the email address with which you signed up for the beta. An unlock code will be "
            "delivered by email. If you already have an unlock code, enter it in "
            "the space provided. "
            "If this machine is not connected to the internet, request a code at "
            SEQ_TRIAL_URL_FRIENDLY ".";
#else

        txt += "If you have purchased Life, click Registration to enter your registration details.\n"
           "To demo Life for 30 days, enter a valid email address to have a trial code sent by email and enter it below\n"
           "If you are not online, request a trial code at "
           SEQ_TRIAL_URL_FRIENDLY ".";
#endif
      }
      mLblDescription->setText(txt,juce::dontSendNotification);
      break;
   case trialModeValid: // they can hit continue, or register retail version
      txt = "You are using the " BETA_TRIAL " version of Life with " + mDaysRem + " days remaining. "
#ifndef LIFE_BETA
         "If you have purchased Life, click Registration"
         " to enter your registration details.";
#else
         "Please click the 'REPORT!' button in the top right of the main screen if you find any problems or if you have any comments. Your help is appreciated.";
#endif
      mLblDescription->setText(txt, juce::dontSendNotification);
      mBtnContinue->setVisible(true);
      if(mTxtEmail->isShowing())
         mTxtEmail->grabKeyboardFocus();
      break;
   case trialSent:
      mLblDescription->setText("An email has been sent to you! "
         "Check your email (including your spam folder) for your " BETA_TRIAL " code "
         "and enter it below.", juce::dontSendNotification);
      mTxtTrialCode->setEnabled(true);
      mBtnAcceptTrialCode->setEnabled(true);
      if (mTxtTrialCode->isShowing())
         mTxtTrialCode->grabKeyboardFocus();
      break;
   default:
      jassertfalse;
   }
}

bool SeqTrialDialog::checkRegistration(bool trial)
{
   String uid, pwd, authkey;
   mGlob->mEditorState->getUIDPWD(uid, pwd);
   seqReadKeyFromFile(authkey);
   mDaysRem = "0";   
   mLastError = "";
   // authorize
   if (authkey.length() && uid.length() && pwd.length()) {
      int days = seqAuthorize(authkey, uid, mLastError, trial);
      if (days > 0) {
         mDaysRem = String::formatted("%d", days);
         return true;
      }
   }
   return false;
}

void SeqTrialDialog::mouseDown(const MouseEvent &)
{
   URL url(SEQ_PURCHASE_URL);
   url.launchInDefaultBrowser();
}


void SeqTrialDialog::notify(int id, int /*val*/) {
   String err;
   String trialcode;
   mEmailFailed = false;
   mClickedSend = false;
   mSaveFailed = false;
   switch (id) {
   case SEQCTL_TRIAL_SENDMAIL:      
      mClickedSend = true;
      if (!seqPostEmailForTrial(mTxtEmail->getText(), mLastError))         
         mEmailFailed = true;
      break;
   case SEQCTL_TRIAL_USETRIAL:      
      trialcode = mTxtTrialCode->getText().trim();
      if (trialcode.length() != OUTPUT_KEY_LEN) {
         mSaveFailed = true;
         mLastError = "Invalid " BETA_TRIAL " code entered";
      }
      else {
         // save the trial key entered to the file
         if (!seqSaveKeyToFile(trialcode, mLastError, true)) {
            mSaveFailed = true;
         }
         else {
            // validate the trial license code and if valid close the dialog to go
            // back to main screen
            determineState();
            if (mState == trialModeValid) {
               closeDialog(true);
            }
         }
      }
      break;
   case SEQCTL_TRIAL_REGISTRATION:
      // show the registration dialog
      mAuthDlg.openDialog();
      mAuthDlg.doSetup();
      break;
   case SEQCTL_TRIAL_CONTINUE:
      // if this button is available they can go on
      closeDialog(true);
      break;
   case SEQCTL_AUTHDIALOG:
      // auth dialog was closed, check auth again, and if valid, close the dialog
      // to go back to the main screen
      if (checkRegistration(false))
         closeDialog(true);
      break;
   default:
      jassertfalse;
   }

   determineState();
   enableDisable();

}

void SeqTrialDialog::resizedInner(Component * inner) {
   Rectangle<int> r = inner->getLocalBounds();
   Rectangle<int> left;
   Rectangle<int> tmp, tmp2;

   mBackground.setBounds(r);

   r.reduce(8, 8);
   
   // Title
   tmp= r.removeFromTop(15);
   mLblTitle->setBounds(tmp);
   r.removeFromTop(4);

   // Description
   tmp = r.removeFromTop(42);
   mLblDescription->setBounds(tmp);
   r.removeFromTop(4);

   tmp2 = r.removeFromBottom(80);
   tmp2.removeFromLeft(10);

   // email label and textbox and button
   tmp = tmp2.removeFromTop(20);
   left = tmp.removeFromLeft(110);
   mLblEmail->setBounds(left);
   tmp.removeFromLeft(4);
   left = tmp.removeFromLeft(200);
   mTxtEmail->setBounds(left);
   tmp.removeFromLeft(4);
   left = tmp.removeFromLeft(175);
   mBtnEmail->setBounds(left);
    
    // continue button
    tmp.removeFromLeft(20);
    left = tmp.removeFromLeft(100);
    mBtnContinue->setBounds(left);
    
    
    
   tmp2.removeFromTop(4);
   // trial code label and text box
   tmp = tmp2.removeFromTop(20);
   left = tmp.removeFromLeft(110);
   mLblTrialCode->setBounds(left);
   tmp.removeFromLeft(4);
   left = tmp.removeFromLeft(200);
   mTxtTrialCode->setBounds(left);
   tmp.removeFromLeft(4);
   left = tmp.removeFromLeft(175);
   mBtnAcceptTrialCode->setBounds(left);
    
    
    // registration button
    tmp.removeFromLeft(20);
    left = tmp.removeFromLeft(100);
    mBtnRegistration->setBounds(left);

   // buy now button
   tmp = tmp2.removeFromTop(20);
   tmp.removeFromLeft(154);
   left = tmp.removeFromLeft(200);
   mLblBuyNow->setBounds(left);

   
   
   
}

SeqTrialDialog::SeqTrialDialog(SeqGlob * glob, CptNotify * parent) :
   SeqModalDialog(glob, SEQCTL_TRIALDIALOG, parent, SEQ_SIZE_MAIN_W, SEQ_SIZE_MAIN_H),
   mAuthDlg(glob, this) 
{
   Image img;
   img = ImageCache::getFromMemory(LifeGUI::authorization_png,  LifeGUI::authorization_pngSize);
   mBackground.setImage(img);   
   addToInner(9999, mBackground);
   
   mBackground.setVisible(true);
#ifdef LIFE_BETA
#define SBTITLE "Beta Version of Life"
#else
#define SBTITLE "Unregistered Version of Life"
#endif
   mLblTitle = addStdLabel(SBTITLE);
   mLblTitle->setJustificationType(juce::Justification::centred);
   mLblTitle->setFont(Font(16.0f, Font::bold));
   mLblDescription = addStdLabel("");
   mLblDescription->setMinimumHorizontalScale(1.0f);
   mLblDescription->setFont(Font(14.0f, Font::plain));
   mLblDescription->setJustificationType(juce::Justification::topLeft);
   mLblEmail = addStdLabel("Email address");
   mLblTrialCode = addStdLabel(BETA_TRIAL " code");
   mLblBuyNow = addStdLabel("Click to purchase now");
   mLblBuyNow->setFont(Font(15, Font::underlined));
   mLblBuyNow->addMouseListener(this,false);
   mTxtEmail = addStdTextEditor();
   mTxtTrialCode = addStdTextEditor();
   
   mBtnEmail = addStdButton("Send me a " BETA_TRIAL " code", 0, SEQCTL_TRIAL_SENDMAIL);
   mBtnAcceptTrialCode = addStdButton("Start " BETA_TRIAL, 0, SEQCTL_TRIAL_USETRIAL);
   mBtnRegistration = addStdButton("Registration", 0, SEQCTL_TRIAL_REGISTRATION);
   mBtnContinue = addStdButton("Continue " BETA_TRIAL, 0, SEQCTL_TRIAL_CONTINUE);

   addChildComponent(mAuthDlg);
}

SeqTrialDialog::~SeqTrialDialog() {
   
}
