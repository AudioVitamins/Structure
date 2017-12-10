/*
  ==============================================================================

	Authentication.cpp
	Created: 3 Nov 2016 10:10:59pm
	Author:  hungc

  ==============================================================================
*/

#include "Authentication.h"

void Authentication::init() {
	mActiveTime = Time::getCurrentTime();
	mModifiedTime = Time::getCurrentTime();
	mWorkedTime = Time::getCurrentTime();
	updateToFiles();
	updateMacAddress();
	if(isExistedAuthenticationFiles()){
		loadFromFile();
	} else {
		writeToFile();
	}
}
void Authentication::updateToFiles() {
#if JUCE_WINDOWS
	// This file identifier stays the same for 32 and 64 bit applications.
	mAuthenticationDir = File::getSpecialLocation(File::userHomeDirectory);
#elif JUCE_MAC
	// The Music folder has been chosen because it is also available when the
	// plugin gets sandboxed - like in GarageBand.
	mAuthenticationFile = File("~");
#elif JUCE_LINUX
	mAuthenticationFile = File("~");
#endif
}
void Authentication::updateMacAddress() {
	Array<MACAddress> listMacAddress;
	MACAddress::findAllAddresses(listMacAddress);
	String identify = String::toHexString((int64)mAuthenticationDir.getFileIdentifier());
	for (int i = 0; i < listMacAddress.size(); ++i)
	{
		String name = listMacAddress[i].toString() + identify;
		mMachineID.add(name);
		MemoryBlock m;
		m.append(name.toRawUTF8(), name.getNumBytesAsUTF8()); 
		name = m.toBase64Encoding();
		mPosibaleNames.add(name);
	}
	if(mPosibaleNames.size()> 0) {
		mNameId = mPosibaleNames[0];
	}
}

bool Authentication::isExistedAuthenticationFiles() {
	String dir = mAuthenticationDir.getFullPathName();
	mAuthenticationFile = File(dir + "\\" + "USERDATA.DAT");
	return mAuthenticationFile.existsAsFile();
}
Authentication::Authentication(bool active): mActive(active) {
	if(mActive) {
		init();
	}
}

bool Authentication::writeToFile(){
	if(mAuthenticationFile.existsAsFile()){
		mAuthenticationFile.deleteFile();
	}

	FileOutputStream fstream(mAuthenticationFile);

	if(fstream.openedOk()){
		MemoryBlock m;
		Time time;
		String name = mNameId;
		int64 timeInMili = time.currentTimeMillis();
		m.append(&timeInMili, sizeof(int64));

		int64 activeTimeInMili = mActiveTime.toMilliseconds();
		m.append(&activeTimeInMili, sizeof(int64));
		m.append(name.toRawUTF8(), name.getNumBytesAsUTF8());
		String data = m.toBase64Encoding();
		fstream.writeString(data);
	}
	return true;
}

bool Authentication::loadFromFile() {
	File file = mAuthenticationFile ;
	mModifiedTime = file.getLastModificationTime();
	if(file.existsAsFile()) {
		FileInputStream fstream(file);
		if(fstream.openedOk()){
			String data = fstream.readNextLine();
			MemoryBlock m; 
			m.fromBase64Encoding(data);
			int64 timeInMili = 0;
			int count = 0;
			m.copyTo(&timeInMili, 0, sizeof(int64));
			count += sizeof(int64);
			mWorkedTime = Time(timeInMili);

			int64 activeTimeInMili = 0;
			m.copyTo(&activeTimeInMili, count, sizeof(int64));
			count += sizeof(int64);
			mActiveTime = Time(activeTimeInMili);

			size_t lenName = m.getSize() - count + 1;
			char *text = new char[lenName];
			m.copyTo(text, count, lenName);
			delete text;
		}
	}
	return true;
}


bool Authentication::isValidDate() {
	if(!mActive) return true;

	int64 modifiedFileTimeMili = mModifiedTime.toMilliseconds();
	int64 activeTimeMili = mActiveTime.toMilliseconds();
	int64 workedTimeMili = mWorkedTime.toMilliseconds();
	int64 currentTimeMili = Time::currentTimeMillis();
	if(workedTimeMili > modifiedFileTimeMili - 2000 && workedTimeMili < modifiedFileTimeMili + 2000) {
		if(activeTimeMili < currentTimeMili) {
			if(activeTimeMili + DEMO_TIME < currentTimeMili) {
				return false;
			} 
			else {
				return true;
			}
		}
		else {
			return false;
		}
	} 
	else {
		return false;
	}
}
bool Authentication::isFirstTimeInstall() {
	return false;
}
Authentication::~Authentication() {

}