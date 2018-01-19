/* Copyright (C) 2016 Andrew Shakinovsky
*/
#include "EditorState.h"
#define COLORS_H_INCLUDE
#include "Colors.h"
#include "Constants.h"

EditorState::EditorState() : 
   mShownTrialWindow(false)

{
   configSerialization(true); // read settings from config
}

EditorState::~EditorState()
{
   configSerialization(false); // write settings to config
   
}


juce::Colour EditorState::getColorFor(coloredElements e)
{
   int r;
   jassert(e != Count);

   // in future we could pull this from a "current theme" sub array
   // add alpha channel
   if(mColorTheme==0)
      r = 0xFF000000 | gDarkColor[(int)e];
   else if(mColorTheme==1)
      r = 0xFF000000 | gLightColor[(int)e];
   else
      r = 0xFF000000 | mUserColors[(int)e];
   return juce::Colour(r);
}

//===================================================================================
// Below here are settings that are persisted to the config file
//===================================================================================
void EditorState::configGetSetInt(juce::PropertiesFile *pf, 
   bool read, int &val, const char *key, int min, int max, int def)
{
   if (read) {
      val = pf->getIntValue(key, def);
      if (val < min || val >max)
         val = def;      
   }
   else {
      pf->setValue(key, var(val));
   }
}
void EditorState::configGetSetString(juce::PropertiesFile * pf, bool read, 
   String & val, const char * key, const String &def)
{
   if (read) {
      val = pf->getValue(key, def);
   }
   else {
      pf->setValue(key, var(val));
   }
}

bool EditorState::getUIDPWD(String & uid, String & pwd)
{
   if (mUserId.length() && mPassword.length()) {
      uid = mUserId;
      pwd = mPassword;
      return true;
   }
   return false;
}

void EditorState::setUIDPWD(String uid, String pwd)
{
   mUserId = uid;
   mPassword = pwd;
}

void EditorState::configSerialization(bool read)
{
   juce::PluginHostType hostType;

   ApplicationProperties appProperties;
   PropertiesFile::Options options;
   options.applicationName = SEQ_APP_NAME;
   options.commonToAllUsers = false;
   options.doNotSave = false;
   options.filenameSuffix = ".cfg";
   options.folderName = SEQ_CO_NAME;
   options.ignoreCaseOfKeyNames = true;
   options.osxLibrarySubFolder = "Application Support";
   appProperties.setStorageParameters(options);
   
   
   juce::PropertiesFile *pf = appProperties.getUserSettings();
   
   configGetSetInt(pf, read, mMouseSense, "mouseSense", 1, SEQ_MOUSE_SENSE_MAX, SEQ_MOUSE_SENSE_DEFAULT);
   configGetSetString(pf, read, mUserId, "UID", "");
   configGetSetString(pf, read, mPassword, "PWD", "");
   
   configGetSetInt(pf, read, mColorTheme, "colorTheme", 0,2,0);
   if (read)
      setColorTheme(mColorTheme); // force load of custom colors if applicable

   if (!read)
      appProperties.saveIfNeeded();
}

void EditorState::loadColorsFromFile()
{
   bool newFile = false;
   ApplicationProperties appProperties;
   PropertiesFile::Options options;
   options.applicationName = SEQ_APP_NAME;
   options.commonToAllUsers = false;
   options.doNotSave = false;
   options.filenameSuffix = ".skin";
   options.folderName = SEQ_CO_NAME;
   options.ignoreCaseOfKeyNames = true;
   options.osxLibrarySubFolder = "Application Support";
   appProperties.setStorageParameters(options);

   if (!options.getDefaultFile().existsAsFile())
      newFile = true;


   juce::PropertiesFile *pf = appProperties.getUserSettings();
   for (int i = 0; i < coloredElements::Count; i++) {
      String val;
      if (newFile)
         val = String::toHexString(gDarkColor[i]);
      configGetSetString(pf, !newFile, val, gColorNames[i],String::toHexString(gDarkColor[i]));
      mUserColors[i] = val.getHexValue32();      
   }
   
}

int EditorState::getColorTheme()
{
   return mColorTheme;
}

void EditorState::setColorTheme(int val)
{
   jassert(val == 0 || val == 1 || val==2);
   mColorTheme = val;
   if (val == 2) { // user
      loadColorsFromFile(); // create if doesn't exist      
   }
}

void fixColors(EditorState *e, Component * cpt)
{
   /* Should have really tried to use the in-build color scheming stuff and would have saved
   all this trouble. but too late
   */
   int len = cpt->getNumChildComponents();
   juce::Colour bg = e->getColorFor(EditorState::background);
   juce::Colour fg = bg.contrasting(.5f);
   juce::Colour border =e->getColorFor(EditorState::border);
   juce::Colour btn = e->getColorFor(EditorState::button);



   for (int i = 0; i < len; i++) {
      Component *innercpt = cpt->getChildComponent(i);

      if (dynamic_cast<TextButton *>(innercpt) != nullptr) {
         TextButton *tb = dynamic_cast<TextButton *>(innercpt);
         tb->setColour(TextButton::ColourIds::buttonOnColourId, btn.contrasting(.5F));
         tb->setColour(TextButton::ColourIds::textColourOnId, btn);

         tb->setColour(TextButton::ColourIds::buttonColourId, btn);
         tb->setColour(TextButton::ColourIds::textColourOffId, btn.contrasting(.9F));
      }
      else if (dynamic_cast<TabbedComponent *>(innercpt) != nullptr) {
         TabbedComponent *tc = dynamic_cast<TabbedComponent *>(innercpt);
         int tl = tc->getNumTabs();
         for (int ti = 0; ti < tl; ti++) {
            tc->setTabBackgroundColour(ti, bg);
            fixColors(e,tc->getTabContentComponent(ti));
         }
      }
      else if (dynamic_cast<ListBox *>(innercpt) != nullptr) {
         ListBox *lb = dynamic_cast<ListBox *>(innercpt);
         lb->setColour(juce::TableListBox::ColourIds::backgroundColourId, bg);
         lb->setColour(ListBox::outlineColourId, border);
         lb->updateContent();
      }
      else if (dynamic_cast<ToggleButton *>(innercpt) != nullptr) {
         ToggleButton *tb = dynamic_cast<ToggleButton *>(innercpt);
         tb->setColour(ToggleButton::textColourId, fg);
         tb->setColour(ToggleButton::ColourIds::tickColourId, btn.contrasting(.5)/* Colours::black*/);

      }
      else if (dynamic_cast<ComboBox *>(innercpt) != nullptr) {
         ComboBox *cb = dynamic_cast<ComboBox *>(innercpt);
         cb->setColour(ComboBox::ColourIds::backgroundColourId, bg);
         cb->setColour(ComboBox::ColourIds::textColourId, fg);
         cb->setColour(ComboBox::ColourIds::arrowColourId, fg);
         cb->setColour(ComboBox::ColourIds::outlineColourId, border);
      }
      else if (dynamic_cast<Label *>(innercpt) != nullptr) {
         Label *lbl = dynamic_cast<Label *>(innercpt);
         lbl->setColour(Label::textColourId, fg);
         lbl->setColour(Label::ColourIds::textWhenEditingColourId, fg);
         lbl->setColour(Label::ColourIds::backgroundWhenEditingColourId, bg);
      }
      else if (dynamic_cast<TextEditor *>(innercpt) != nullptr) {
         TextEditor *te = dynamic_cast<TextEditor *>(innercpt);
         te->setColour(TextEditor::ColourIds::textColourId, fg);
         te->setColour(TextEditor::ColourIds::highlightColourId, fg);
         te->setColour(TextEditor::ColourIds::highlightedTextColourId, bg);
         te->setColour(TextEditor::ColourIds::backgroundColourId, bg);
         te->setColour(CaretComponent::caretColourId, btn);
         te->setColour(TextEditor::ColourIds::focusedOutlineColourId, btn);
         te->setColour(TextEditor::ColourIds::outlineColourId, btn.contrasting(.5));

      }
      else if (dynamic_cast<ScrollBar *>(innercpt) != nullptr) {
         ScrollBar *sb = dynamic_cast<ScrollBar *>(innercpt);
         sb->setColour(ScrollBar::ColourIds::thumbColourId, fg);
         sb->setColour(ScrollBar::ColourIds::trackColourId, bg);
      }
      else {
         fixColors(e,innercpt);
      }

   }

}

void fixDynamicTextEditBox(EditorState *e, TextEditor & te, int maxlen)
{
   juce::Colour bg = e->getColorFor(EditorState::background);
   juce::Colour fg = bg.contrasting(.5f);
   juce::Colour border = e->getColorFor(EditorState::border);
   juce::Colour btn = e->getColorFor(EditorState::button);

   te.setColour(TextEditor::ColourIds::textColourId, fg);
   te.setColour(TextEditor::ColourIds::highlightColourId, fg);
   te.setColour(TextEditor::ColourIds::highlightedTextColourId, bg);
   te.setColour(TextEditor::ColourIds::backgroundColourId, bg);
   te.setColour(CaretComponent::caretColourId, btn);
   
   te.setColour(TextEditor::ColourIds::focusedOutlineColourId, btn);
   te.setColour(TextEditor::ColourIds::outlineColourId, btn.contrasting(.5));
   te.setInputRestrictions(maxlen);
   //te.setInputFilter(new TextEditor::LengthAndCharacterRestriction(maxlen, ""), true);
}

void gradientFill(EditorState &e, Component * c, Graphics & g)
{
   Rectangle<int> me = c->getLocalBounds();
   Colour top, mid, bot;
   bot = e.getColorFor(EditorState::background);
   top = bot.brighter(.6f);
   mid = bot.brighter(.1f);
   ColourGradient grad(top, 0.f, 0.f, bot, 0.f, (float)me.getBottom(), false);
   grad.addColour(.08, mid);
   g.setGradientFill(grad);
   g.fillAll();// mGlob->mEditorState->getColorFor(EditorState::background));
}


int EditorState::getMouseSense()
{
   return mMouseSense;
}

void EditorState::setMouseSense(int val)
{
   jassert(val > 0 && val <= SEQ_MOUSE_SENSE_MAX);
   mMouseSense = val;
}
