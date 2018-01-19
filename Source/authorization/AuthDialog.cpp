/* Copyright (C) 2016 Andrew Shakinovsky
*/
#include "AuthDialog.h"
#include "auth.h"
#include "unlockcode.h" // for constant only
void SeqAuthDialog::endDialog(bool hitOk)
{
   bool b;
   b = hitOk;
   notifyParent(0);
}

void SeqAuthDialog::doSetup()
{
   determineState();
   enableDisable();
}

void SeqAuthDialog::determineState()
{
   /* States:
   determine state as follows:
   initial mode: do the following:
   uid and pwd are present-
   offline mode?
     yes:
       key entered?
         go to key validate
     no:
       offline mode
   no:
     try to get key
     key is present?
key validate:
       key validates > 5 days    - valid key mode
       key validates <=5 days    - allow auth mode
       key not valid or expired  - allow auth mode
       key not present?             - allow auth mode
       uid and pwd not present       - trial mode

   trial mode:
   only uid/pwd are enabled, once they are entered we enter allow auth mode

   valid key mode:
   auth and offline and key are all disabled. cant move from this state

   allow auth mode:
   auth and offline are enabled, key disabled
   if offline is clicked enter offline mode

   offline mode:
   offline is disabled, auth is enabled, key is enabled
   text asks to enter key
   */
   String uid, pwd, key, err, txt;
   int days;

   bool gota = false;
   bool gotb = false;
   if (mGlob->mEditorState->getUIDPWD(uid, pwd)) {
      mTxtUser->setText(uid, juce::dontSendNotification);
      mTxtPw->setText(pwd, juce::dontSendNotification);
      gota = true;
   }
   if (seqReadKeyFromFile(key)) {
      gotb = true;
      mTxtKey->setText(key, juce::dontSendNotification);
   }
   if (gota && gotb) {
      // try auth. returns number of remaining valid days on the code,
      // or 0 if not valid anymore
      days = seqAuthorize(key, uid, err);
      if (!days) { // not valid anymore
         mState = trial;
         txt << err <<
            "Please make sure you are online as we need to re-authorize "
            "your copy of Life as part of our anti-piracy policy. "
            "If this is not possible, please click 'Offline Authorization'";
            
      }
      else { // valid code, see how many days remain         
         if (days < 5) { // less than 5 days... 
            mState = trial;
            txt << "Your copy of Life needs to be re-authorized within the next " << days <<" days. ";
            txt << "Please make sure you are online. If this is not possible, "
               "please click 'Offline Authorization'";
         }
         else { // more than 5 days remaining
            mState = valid;
            txt << "Your copy of Life is licensed, and your authorization key is current.";
         }
      }
   }
   else { // not authorized
      mState = trial;
      txt = 
         "Please enter your purchase id and code below and click 'Authorize Now'\n"
         "If you are not online, click 'Offline Authorization'";
   }
   mLblDescription->setText(txt, juce::dontSendNotification);
}

void SeqAuthDialog::enableDisable()
{
   mTxtKey->setEnabled(false);
   mBtnAuth->setEnabled(false);
   mBtnOffline->setEnabled(false);
   mTxtUser->setEnabled(true);
   mTxtPw->setEnabled(true);

   switch (mState) {
   case offline: // they can enter a key manually and click auth
      mBtnAuth->setEnabled(true);
      mTxtKey->setEnabled(true);
      break;
   case trial: // they can enter uid/pwd and click auth
      mBtnAuth->setEnabled(true);
      mBtnOffline->setEnabled(true);
      break;
   case valid: // they can't do anything
      mTxtUser->setEnabled(false);
      mTxtPw->setEnabled(false);
      break;
   default:
      jassertfalse;
   }
}

void SeqAuthDialog::notify(int id, int /*val*/) {
   String err, key, uid, pwd;
   int days = 0;
   switch (id) {
   case SEQCTL_AUTH_AUTHORIZE:
      uid = mTxtUser->getText();
      pwd = mTxtPw->getText();
      // save them to file regardless
      mGlob->mEditorState->setUIDPWD(uid, pwd);
      if (mState == offline) {
         key = mTxtKey->getText();         
         if (key.length() && uid.length()) {
            // see if key is valid
            days = seqAuthorize(key, uid, err);
            if (!days || !seqSaveKeyToFile(key, err)) {
               mLblDescription->setText(err, juce::dontSendNotification);
               return; // stay in this state
            }            
         }
         else
            return; // stay in state         
      }
      else {
         // try contact server to auth with uid pwd then save them and key to file         
         // todo use the async version of this so that we can update the ui while it's working
         if (!seqDoReauthorize(uid, pwd, err)) {            
            mLblDescription->setText(err, juce::dontSendNotification);
            return;
         }         
         
      }
      determineState();
      enableDisable();
      break;
   case SEQCTL_AUTH_OFFLINE:
      mState = offline;
      mLblDescription->setText("Please visit " SEQ_LICENSE_URL_FRIENDLY          
         " from a computer connected to the internet. Enter your "
         "key below and click 'Authorize Now'", juce::dontSendNotification);
      mTxtKey->grabKeyboardFocus();
      enableDisable();
      break;
   case SEQCTL_AUTH_CLOSE:
      closeDialog(true);
      break;
   default:
      jassertfalse;
   }
}

void SeqAuthDialog::resizedInner(Component * inner) {
   Rectangle<int> r = inner->getLocalBounds();
   Rectangle<int> left;
   Rectangle<int> tmp;
   r.reduce(8, 8);
   
   tmp= r.removeFromTop(20);   
   mLblTitle->setBounds(tmp);
   r.removeFromTop(4);

   tmp = r.removeFromTop(35);
   mLblDescription->setBounds(tmp);
   r.removeFromTop(4);

   tmp = r.removeFromTop(20);
   left = tmp.removeFromLeft(100);
   mLblUser->setBounds(left);
   tmp.removeFromLeft(4);
   left = tmp.removeFromLeft(120);
   mTxtUser->setBounds(left);
   tmp.removeFromLeft(20);
    
   left = tmp.removeFromLeft(130);
   mBtnOffline->setBounds(left);
   r.removeFromTop(4);

   tmp = r.removeFromTop(20);
   left = tmp.removeFromLeft(100);
   mLblPw->setBounds(left);
   tmp.removeFromLeft(4);
   left = tmp.removeFromLeft(120);
    mTxtPw->setBounds(left);
    tmp.removeFromLeft(20);
    
   left = tmp.removeFromLeft(130);
   mBtnAuth->setBounds(left);
    
    tmp.removeFromLeft(15);
    left = tmp.removeFromLeft(100);
    mBtnClose->setBounds(left);
    
   r.removeFromTop(4);

   tmp = r.removeFromTop(20);
   left = tmp.removeFromLeft(100);
   mLblKey->setBounds(left);
   tmp.removeFromLeft(4);
   left = tmp.removeFromLeft(220);
   mTxtKey->setBounds(left);
   
   
}

SeqAuthDialog::SeqAuthDialog(SeqGlob * glob, CptNotify * parent) : 
   SeqModalDialog(glob, SEQCTL_AUTHDIALOG, parent, 500, 150) {
   mLblTitle = addStdLabel("Registration Information");
   mLblTitle->setJustificationType(juce::Justification::centred);
   mLblDescription = addStdLabel("Registration");
   mLblDescription->setJustificationType(juce::Justification::topLeft);
   //mLblDescription->setColour(juce::Label::ColourIds::outlineColourId, 
   //   mGlob->mEditorState->getColorFor(EditorState::background));

   mLblKey = addStdLabel("Key");
   mLblUser = addStdLabel("Purchase ID");
   mLblPw = addStdLabel("Purchase Code");

   mTxtUser = addStdTextEditor();
   mTxtPw = addStdTextEditor();
   mTxtKey = addStdTextEditor();
   //mTxtKey->setEnabled(false);
   
   mBtnAuth = addStdButton("Authorize Now", 0, SEQCTL_AUTH_AUTHORIZE);
   mBtnClose = addStdButton("Close", 0, SEQCTL_AUTH_CLOSE);
   mBtnOffline = addStdButton("Offline Authorization", 0, SEQCTL_AUTH_OFFLINE);

}

SeqAuthDialog::~SeqAuthDialog() {
   
}
