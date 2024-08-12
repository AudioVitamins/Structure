/* Copyright (C) 2016 Andrew Shakinovsky
*/
#ifndef COMMONCOMPONENTS_H_
#define COMMONCOMPONENTS_H_
#include "../JuceLibraryCode/JuceHeader.h"
#include "EditorState.h"
#include "Constants.h"


enum SeqMouseAxis {
   unknown,
   vertical,
   horizontal
};

/*=============================================================================
  Component helper - Allows a class to listen for a value change
  Implement cptValueChange and optionally cptValueChanging
===============================================================================*/
class CptNotify {
public:
   /* receive notification when item has changed value.
   cptId - is the ID of the component
   value - The new value. For different components this means:
      ToggleCpt - the id associated with the item selected. If this is a single item
                  toggle, then it will be the ID if it's on, and 0 if it's off
      NumberCpt - the value of the number   
   */
   virtual void cptValueChange(int cptId, int value) = 0;

   // toggle cpt calls this when an item is clicked while modifier key is held 
   // (in this case index doesn't change)
   // mod - the modifier flags
   virtual void cptItemClickWithModifier(int /*cptId*/, int /*idx*/, juce::ModifierKeys /*mod*/) {}
   /* called if the value is busy changing (cptValueChanged will be called when it's done)
      applies to NumberCpt
   */
   virtual void cptValueChanging(int /*cptId*/, int /*value*/) {}
   virtual ~CptNotify(){}
};

/*=============================================================================
This is a set of toggle buttons where one button is active at a time.
Can also be used when there is a single item that is either on or off.
===============================================================================*/
class ToggleCpt : public Component {   
   int mId;
   
   bool mAlwaysNotify;
   CptNotify *mNotify;
   struct Item {
      int id;
      String text;
      bool selected;
   };
   void recalcGrid();
   int mItemsPerRow;       // max columns as set by setMaxItemsPerRow
   int mNumRows;       // number of rows in the toggle (calculated)
   int mNumItemsOnEachRow; // number of items on each row (possibly excluding the last row) (calculated)
   int mNumItemsOnLastRow; // number of items on the last row (calculated)


protected:
   SeqGlob *mGlob;
   Array<Item> mItems;
   virtual void paintText(Graphics &g, Rectangle<float> r, const String &txt);
public:
   ToggleCpt(SeqGlob *glob, int id, CptNotify *notify, String name = "toggle");   

   // a value of 0 means unlimited (ie one row which is default)
   void setMaxItemsPerRow(int max);
   /* Add an item to the toggle collection. id can be used to reference it */
   void addItem(int id, String text, bool selected=false);
   // clear all items
   void clearItems();
   int getNumItems() { return mItems.size(); }
   /* Set the current item. does not trigger valueChange unless 3nd param is set.
   val parameter - only applicable if single item and determines whether to toggle on or off   
   */
   void setCurrentItem(int id, bool val, bool triggerNotify);
   // return true if the item specified is current
   bool isCurrent(int id);

   // by default notify will not be called if an item was clicked but it's the same item that
   // was already clicked. this turns that off (by setting to false)
   void setAlwaysNotify(bool val);
   virtual void paint(Graphics &g) override;
   void mouseDown(const MouseEvent &event) override;

};
/*==Same but with little label as used by layers with mute ==================*/
class ToggleCptWithLabel : public ToggleCpt {
   juce::HashMap<int, String> mLabels;
public:
   void setLabel(int id, const String &txt);
   void clearLabels();
   void clearLabel(int id);
   bool hasLabel(int id) { return mLabels.contains(id); }
   void paint(Graphics &g) override;
   void paintText(Graphics &g, Rectangle<float> r, const String &txt) override;
   ToggleCptWithLabel(SeqGlob *glob, int id, CptNotify *notify, String name = "toggleLabel");
};

/*=============================================================================
Button Component - for single button with text that can be clicked
notify will receive the ID and a value of 0 when it's clicked
=============================================================================*/
class ButtonCpt : public Component {
   int mId;
   SeqGlob *mGlob;
   String mText;
   CptNotify *mNotify;
   juce::Colour mOverrideColor;
   void mouseDown(const MouseEvent &event) override;
public:
   ButtonCpt(SeqGlob *glob, int id, CptNotify *notify, String name = "button");
   void paint(Graphics &g) override;
   void setText(String txt);
   // call with no parameters to not override
   void overrideColor(juce::Colour c =Colour());
   inline int getId() { return mId; }
};


/*=============================================================================
Number component - drag up and down, or left and right to change value
double click to reset
=============================================================================*/
class NumberCpt : public Component {
   SeqGlob *mGlob;
   int mId;          // ID used to determine which number control
   int mValue;       // current value
   int mDefaultValue;// default value (double click)
   int mInterval;    // interval jump
   int mLowBound;    // lower bound
   int mHighBound;   // upper bound
   String mSuffix;   // appended onto text
   CptNotify *mNotify;
   bool mInteracting;// busy dragging
   int mDragValue;   // value while dragging
   int mIntSense;    // internal sensitivity (factor of how many items)
   
   SeqMouseAxis mAxis;       // which axis we are dragging on
   bool mEnabled;    // if enabled for dragging
   juce::HashMap<int, String> mReplacements;
   
   
   void mouseDrag(const MouseEvent &event) override;
   void mouseDown(const MouseEvent &event) override;
   void mouseUp(const MouseEvent &event) override;
   void mouseDoubleClick(const MouseEvent &event) override;
   void paint(Graphics &g) override;
   
   /* This is the text box that comes up when the user double clicks
      on the item. 
   */
   class InlineEditor : public TextEditor, public TextEditor::Listener {
      
      /** Called when the user presses the return key. Accept the edit */
      void textEditorReturnKeyPressed(TextEditor&) override;

      /** Called when the user presses the escape key. Abort the edit */
      void textEditorEscapeKeyPressed(TextEditor&) override;

      /** Called when the text editor loses focus. Accept the edit */
      void textEditorFocusLost(TextEditor&) override;

      // mouse listener added to get mouse click outside this component
      // which does the same as make it lose focus (saves the contents)
      void mouseDown(const MouseEvent& event) override;
      void mouseDoubleClick(const MouseEvent&) override {
         // do nothing. we want to throw away the double click on this text box
         // otherwise it ends up causing an extra double click which might select
         // one word (if there is a space) instead of keeping the full selection
      }
      Component *mTop;
      NumberCpt *mParent;      
   public:
      ~InlineEditor();
      InlineEditor(NumberCpt *parent);
   };

   InlineEditor *mTextEdit;

public:
   class CustomText {
   public:
      // given the value, return the custom text in repl
      // id is the id as passed into the ctor
      // return false if you don't want to change that value
      virtual bool getNumberCptCustomText(int id, int value, String &repl) = 0;
      virtual ~CustomText(){}
   };

   NumberCpt(SeqGlob *glob, int id, CptNotify *notify, String name = "number");

   // set range, etc   
   void setSpec(int lo, int hi, int interval, int defaultVal, String suffix);
   // set a string replacement for values that equal a certain value
   void setStringRep(int val, String repl);
   void setCustomText(CustomText *replacer);
   // get current value
   int getValue();
   // set current value optionally sending notification.
   void setValue(int val, bool notify);

   // try to set the value (if it's compatible and can be parsed)
   // will try to interpret textual entry too if it matches string replacements
   // (as set with setStringRep) or custom Text (as set with setCustomText)
   void trySetValue(const String &val, bool notify);

   // enable or disable
   void enable(bool);
   // get effective text that is displayed
   // if stripped is set it does not add a suffix if any
   String getTextualValue(bool stripped=false);
private:
   CustomText *mTextReplacer;
};

/*=====================================================================================
Modal Dialog Popup
=======================================================================================*/

// This is the actual box that contains everything (as opposed to SeqEditDialog which takes up the whole
// client area and is semi-opaque)

/* 
Generic Dialog helper.
To use this, you need to override it, and add an instance of the overriden class to the
main component. When you want the dialog to show, call openDialog.
*/
class SeqModalDialog : public Component,
   public ButtonListener,
   public ComboBoxListener,
   public CptNotify           // for our own controls
{

   CptNotify *mParent;
   int mId; // for parent notify
   int mWidth; // width and height of the inner panel
   int mHeight;
   void buttonClicked(Button *) override;
   void comboBoxChanged(ComboBox *) override;
   void mouseDown(const MouseEvent & event) override;
   void paint(Graphics &) override;
   void cptValueChange(int cptId, int value) override;
   void resized() override;
   class InnerPanel : public Component
   {
      SeqGlob *mGlob;
      SeqModalDialog *mParent;
      void paint(Graphics &) override;
      void resized() override;
   public:
      InnerPanel(SeqGlob *glob, SeqModalDialog *par);
   };
   // contains all the controls for the dialog
   InnerPanel mPanel;

   //void fixColors(Component *cpt);

protected:
   
   // a dirty hack
   void forceResize();
   // use this to access the Glob
   SeqGlob *mGlob;
   // this calls the cptnotify interface that was passed in passing the cptid and this value
   void notifyParent(int val);
public:
   // parent will be notified if user clicks ok on dialog (usually needing repaint)
   SeqModalDialog(SeqGlob *glob, int id, CptNotify *parent, int width, int height);
   
   // helpers for adding controls to inner panel.
   // will new them and return them. id is used to pass into the
   // notify function which you need to override
   // if parent is specified, it's added to that component instead of the inner panel
   // if cptId is specified, it's the value that's passed to notify as the cptId
   ToggleButton *addToggle(const String &txt, int grp, Component *parent=nullptr, int cptId=0);
   ComboBox *addCombo(const String &txt, Component *parent = nullptr, int cptId = 0);
   Label *addStdLabel(const String &txt, Component *parent = nullptr);
   TextButton *addStdButton(const String &txt, Component *parent = nullptr, int cptId = 0);
   TextEditor *addStdTextEditor(Component *parent = nullptr, int cptId = 0);

   // generic for other stuff. do it yourself. does not make visible
   // cptId is used for the component's id (which is set)
   void addToInner(int cptId, Component &cpt, int zOrd=-1);

   void removeFromInner(Component *cpt);

   // call this if you want the dialog to show
   void openDialog();

   // call this if you want the dialog to go away
   void closeDialog(bool OK);


   // override to provide action that happens when dialog ends
   // you do not need to close and hide it, it will be done
   virtual void endDialog(bool hitOk)=0;

   // will be called when one of your components has user interaction
   // value is only valid in some cases
   virtual void notify(int cptId, int value)=0;
   
   // override to do your sizing
   virtual void resizedInner(Component *inner) = 0;
   
   virtual ~SeqModalDialog() {};

   // called if color scheme changes, goes thru child components to fix them
   // to reflect the new color scheme
   virtual void fixButtonColors();
   

};

#endif

