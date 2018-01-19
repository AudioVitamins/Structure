/* Copyright (C) 2016 Andrew Shakinovsky
*/
#ifndef UNLOCKCODE_H_
#define UNLOCKCODE_H_
/*
key is a hex encoded string. When decoded to raw bytes:
any values are little endian.
Our own epoch is jan 1 2016.

last two bytes (short val) is checksum against whole key

strip that off and validate rest of key

last two bytes now is date it was generated in num days since our own epoch

strip that off and call it time code

make sure timecode is still valid (up to 90 days old is still valid)

enencode the string using time code as an index into our random array where to start getting
the string to xor against the original string

the value is:
integer uid (validate the last digit as a check digit against the rest, but don't strip)
short expire day (in days since our own epoch)
char prod code
char version code
*/


// final length (Excluding null terminator) of an unlock code
#define OUTPUT_KEY_LEN 24

// max period of time of validity
// this is used to create time code and validate that date has not been
// tampered with
#define VALID_DAYS 92 

/* Generate an unlock code. no checks are done for any validity
   * note that this function will not exist on the client side *
   uid - a user id (assumes that check digit is added already but doesn't validate)
   prodid - product code
   version - version code
   valid_days - number of days valid
   output - full string (null terminated) buf must have OUTPUT_KEY_LEN+1
*/
void uc_generate(int uid, char prodid, char version, short int valid_days, char *output);

/* Validate unlock code. Checks:
   valid checksum
   valid time code (to decrypt)
   license still valid for time frame
   license valid for prod and ver supplied
   outputs validated uid and remaining days
   returns 0 on success or one of these codes:
*/
#define UC_ERR_HEXINVALID        1 // main checksum failed or code contains non-hex
#define UC_ERR_TIMECODEINVALID   2 // time code expired
#define UC_ERR_UIDINVALID        3 // uid not valid (it's checksum failed)
#define UC_ERR_EXPIRED           4 // past expiration
int uc_validate(const char *code, char *prodid, char *version, short int *remaining_days, int *uid);


// given a number, add a check digit to the end and return it
int luhncreate(int num);

// given a number, returns true if the last digit is a valid check digit for the rest
bool luhnvalid(int num);



unsigned short days_since_epoch();
#endif

