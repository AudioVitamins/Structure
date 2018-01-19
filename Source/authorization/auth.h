/* Copyright (C) 2016 Andrew Shakinovsky
*/
#ifndef AUTH_H_
#define AUTH_H_
#include "../JuceLibraryCode/JuceHeader.h"

// attempt to authorize the software given the license key
// if it fails, errMsg is set to some string
// if it succeeds, returns remaining days
// otherwise returns 0 and errMsg will be set
// input uid will be validated against key
// if trial is specified, it tries to validate a trial license code
int seqAuthorize(const String &key, const String &uid, String &errMsg, bool trial=false);

/*Contact the web server to get a new key.
The new key is returned. If empty string, errmsg will have the reason
*/
String seqGetNewAuthKey(const String &uid, const String &pwd, String &errMsg);

// Save the key to the file. Returns true on success, errMsg will be set on failure
// and will include details
bool seqSaveKeyToFile(const String &key, String &errMsg, bool trial=false);

// returns false if couldn't read file
// this could mean that it doesn't exist
// if trial is specified it reads a trial mode key
bool seqReadKeyFromFile(String &key, bool trial=false);

// used by seqDoReauthorize
struct SeqAuthServerCallback {
   // will call this when it has done getting the key and writing to the file
   // at this point if it succeeds, it will have unlocked
   virtual void doneAuth(bool success, const String &message)=0;
   virtual ~SeqAuthServerCallback(){}
};

/* Try to reauthorize the software. It will contact the server, try to get a key,
   if it gets one, try to unlock with it, if that succeeds, save it to the file, if that succeeds
   returns true. If the unlock trial fails, we revert back to a previous state (locked or unlocked)
   errMsg will be set on failure unless cbk is specified. If cbk is specified, this function returns
   true immediately and calls cbk->done when completed. If cbk is not specified, it is synchronous
*/
bool seqDoReauthorize(const String &uid, const String &pwd, String &errMsg);

/*
Post an email address to the "request trial" form. return true on success
*/
bool seqPostEmailForTrial(const String & email, String & errMsg);



#endif
