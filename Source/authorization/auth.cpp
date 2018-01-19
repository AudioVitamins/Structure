#include "auth.h"
#include "unlockcode.h"
#include "Constants.h"
int
seqAuthorize(const String & key, const String &uid, String & errMsg, bool trial)
{
    short int days;
    int inuid=0;
    int valuid;
    char prod, ver;
    int res;
    
    if (!trial)
        inuid = uid.getIntValue();
    
    res=uc_validate(key.getCharPointer(),&prod, &ver, &days, &valuid);
    if (res == 0) {
        if (trial) {
            // in trial mode we don't care about user id
            if (prod == SEQ_LICENSE_TRIAL_ID && ver == SEQ_LICENSE_TRIAL_VER) {
                if (days > SEQ_TRIAL_MAX_DAYS) {
                    errMsg = "Trial code '" + key + "'is not allowed. ";
                } else
                    return days;
            }
        }
        else {
            if (prod == SEQ_LICENSE_PROD_ID && ver == SEQ_LICENSE_VER && valuid == inuid) {
                return days;
            }
        }
        
        errMsg = "Unlock code '" + key + "'is invalid. ";
        return 0;
        
    }
    else {
        errMsg = "Unlock code '" + key + "' is invalid or has expired.";
        if(!trial)
            errMsg += " Please reauthorize.";
        return 0;
    }
    
}

String seqGetNewAuthKey(const String & uid, const String & pwd, String & errMsg)
{
    juce::PluginHostType p;
    String tmp;
    errMsg.clear();
    URL url(SEQ_LICENSE_URL);
    url = url.withParameter("UID", uid);
    url = url.withParameter("PWD", pwd);
    tmp << SEQ_LICENSE_PROD_ID;
    url = url.withParameter("PROD", tmp );
    tmp.clear();
    tmp << SEQ_LICENSE_VER;
    url = url.withParameter("VER", tmp);
    url = url.withParameter("DAW", p.getHostDescription());
    url = url.withParameter("OS", juce::SystemStats::getOperatingSystemName());
    
    String resultKey = url.readEntireTextStream();
    if (!resultKey.length()) {
        errMsg = "Failed to communicate with server ";
        return String();
    }
    resultKey=resultKey.trim();
    if (resultKey.startsWith("ERROR ")) {
        errMsg = resultKey;
        return String();
    }
    
    if (resultKey.length() != OUTPUT_KEY_LEN){
        if (resultKey.length() > 50)
            resultKey = resultKey.dropLastCharacters(resultKey.length() - 50);
        errMsg = "Invalid result received from server (" + resultKey + ")";
        return String();
    }
    return resultKey;
}

static void setOptions(PropertiesFile::Options &options)
{
    options.applicationName = SEQ_LICENSE_NAME;
    options.commonToAllUsers = false;
    options.doNotSave = false;
    options.filenameSuffix = ".cfg";
    options.folderName = SEQ_CO_NAME;
    options.ignoreCaseOfKeyNames = true;
    options.osxLibrarySubFolder = "Application Support";
}

void saveToFile(const String & key, String &filename, bool trial)
{
    ApplicationProperties appProperties;
    PropertiesFile::Options options;
    setOptions(options);
    appProperties.setStorageParameters(options);
    juce::PropertiesFile *pf = appProperties.getUserSettings();
    if(trial)
        pf->setValue("TRIALKEY", key);
    else
        pf->setValue("KEY", key);
    filename = pf->getFile().getFullPathName();
    appProperties.saveIfNeeded();
}

bool seqSaveKeyToFile(const String & key, String & errMsg, bool trial)
{
    String outkey, filename;
    if (!key.length()) {
        errMsg = "Key is blank";
        return false;
    }
    saveToFile(key, filename, trial);
    
    // try to read it back out to be sure
    if (seqReadKeyFromFile(outkey, trial)) {
        if (outkey.compare(key) == 0)
            return true;
    }
    errMsg = "Failed to write key '" + key + "' to " + filename + ".";
    return false;
}

bool seqReadKeyFromFile(String & key, bool trial)
{
    ApplicationProperties appProperties;
    PropertiesFile::Options options;
    setOptions(options);
    appProperties.setStorageParameters(options);
    juce::PropertiesFile *pf = appProperties.getUserSettings();
    String val;
    if(trial)
        val = pf->getValue("TRIALKEY", "");
    else
        val = pf->getValue("KEY", "");
    val = val.trim();
    if (val.length() == OUTPUT_KEY_LEN) {
        key = val;
        return true;
    }
    return false;
}

bool seqDoReauthorize(const String & uid, const String & pwd, String & errMsg)
{
    bool ret = false;
    String authErr;
    
    // 1. Contact server passing in uid/pwd, and getting key back
    String resultKey = seqGetNewAuthKey(uid, pwd, errMsg);
    if (!resultKey.length())
        goto done;
    
    // 2. Make sure this key works
    if (seqAuthorize(resultKey, uid, errMsg) < 1) {
        goto done;
    }
    
    // 3. Save the key to the file if it worked
    if (!seqSaveKeyToFile(resultKey, errMsg)) {
        goto done; // above will produce correct error
    }
    // 4. If it didn't work, keep existing state of unlock and existing key
    // otherwise, we should be authorized and the new key saved
    ret = true;
    
done:
    return ret;
    
}

bool seqPostEmailForTrial(const String & email, String & errMsg)
{
    juce::PluginHostType p;
    
    String tmp, trimmed;
    errMsg.clear();
    trimmed = email.trim();
    if (trimmed.length() < 1 || !trimmed.containsAnyOf("@") || !trimmed.containsAnyOf(".")) {
        errMsg = "Invalid email address entered";
        return false;
    }
    
    URL url(SEQ_TRIAL_URL);
    url = url.withParameter("EMAIL", trimmed);
    url = url.withParameter("DAW", p.getHostDescription());
    url = url.withParameter("OS", juce::SystemStats::getOperatingSystemName());
    tmp.clear();
    tmp << SEQ_LICENSE_TRIAL_ID;
    url = url.withParameter("PROD", tmp);
    tmp.clear();
    tmp << SEQ_LICENSE_TRIAL_VER;
    url = url.withParameter("VER", tmp);
    String result = url.readEntireTextStream();
    if (!result.length()) {
        errMsg = "Failed to communicate with server ";
        return false;
    }
    else if (result.compare("SUCCESS") == 0) {
        return true;
    } else {
        errMsg = result;
        return false;
    }
}
