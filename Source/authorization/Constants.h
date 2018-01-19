#ifndef CONSTANTS_H_
#define CONSTANTS_H_

//
// Uncomment this to disable all authorization/locking
//
//#define SEQ_ALWAYS_UNLOCKED 1




#define SEQ_APP_NAME "structure"
// name of file that stores license key
#define SEQ_LICENSE_NAME "structurekey"  
#define SEQ_CO_NAME  "AudioVitamins"
// used on the Trial dialog
#define SEQ_PURCHASE_URL  "http://www.audiovitamins.com"
// this is where it will try to reauthorize
//#define SEQ_LICENSE_URL "http://installers.audiovitamins.com/validation/unlock.php"
#define SEQ_LICENSE_URL "http://v64-d10b733-01/structure/unlock.php"
// this is the URL of the user-friendly form for manually requesting an unlock code
#define SEQ_LICENSE_URL_FRIENDLY "https://www.audiovitamins.com/my-account/offline-activation/"
// this is the URL of the user-friendly form for manually requesting a trial code
#define SEQ_TRIAL_URL_FRIENDLY "https://www.audiovitamins.com/trial-activation"
// when they enter an email, it auto posts to this
//#define SEQ_TRIAL_URL "http://installers.audiovitamins.com/validation/request_trial.php"
#define SEQ_TRIAL_URL "http://v64-d10b733-01/structure/request_trial.php"


// for licensing, these are passed to the license server (and validated against key)
// distinct product id for the purpose of licensing
#define SEQ_LICENSE_PROD_ID 127
// product version for the purpose of licensing
#define SEQ_LICENSE_VER     1
// trial version product id
#define SEQ_LICENSE_TRIAL_ID     94
// trial version for the purpose of licensing
#define SEQ_LICENSE_TRIAL_VER    1
// trial license codes can't be valid for more than this number of days
#define SEQ_TRIAL_MAX_DAYS       30

#define SEQCTL_AUTHDIALOG           19 //* auth dialog will notify when done
#define SEQCTL_TRIALDIALOG          26 //* trial dialog will notify when done

#define SEQ_SIZE_MAIN_W       750
#define SEQ_SIZE_MAIN_H       150
// mouse sensitivity default. higher value means less sensitive
#define SEQ_MOUSE_SENSE_DEFAULT 4   
// max mouse sensitivity (ie least sensitive value)
#define SEQ_MOUSE_SENSE_MAX   10

#define SEQ_MOUSE_AXIS_SENSE  8     // how much the user must drag the mouse before an axis is guessed


///////////////////////
// Auth dialog ids
///////////////////////
#define SEQCTL_AUTH_AUTHORIZE       1 //* auth btn
#define SEQCTL_AUTH_CLOSE           2 //* close dlg
#define SEQCTL_AUTH_OFFLINE         3 //*offline auth

////////////////////////
// trial dialog ids
////////////////////////
#define SEQCTL_TRIAL_SENDMAIL       1
#define SEQCTL_TRIAL_USETRIAL       2
#define SEQCTL_TRIAL_REGISTRATION   3
#define SEQCTL_TRIAL_CONTINUE       4

#endif
