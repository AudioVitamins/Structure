/*
  ==============================================================================

    Authentication.h
    Created: 3 Nov 2016 10:10:59pm
    Author:  hungc

  ==============================================================================
*/

#ifndef AUTHENTICATION_H_INCLUDED
#define AUTHENTICATION_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"
#ifndef DEMO_TIME 
#define DEMO_TIME 10*1000//15*24*60*60*1000
#endif
class Authentication {
	File mAuthenticationDir;
	File mAuthenticationFile;

	Array<File> mAuthenticationFiles;
	Array<String> mMachineID;
	Array<String> mPosibaleNames;

	Time mActiveTime;
	Time mWorkedTime;
	Time mModifiedTime;
	String mNameId;

	bool mActive;
private:
	void init();
	void updateToFiles();
	void updateMacAddress();
	bool isExistedAuthenticationFiles();
	bool writeToFile();
	bool loadFromFile();
public:
	Authentication(bool active = true);
	bool isValidDate();
	bool isFirstTimeInstall();
	~Authentication();
};


#endif  // AUTHENTICATION_H_INCLUDED
