/* Copyright (C) 2016 Andrew Shakinovsky
 */
#ifndef UCSHARED_H_
#define UCSHARED_H_
// not a public API, used by ucgenerate and ucvalidate only

#define START_KEY_LEN 8    // actual key length in bytes
#define ENCODED_KEY_LEN 10 // actual key with added 2 byte time code
#define FULL_KEY_LEN 12    // encoded key with added 2 byte checksum

#define EPOCH 16801        // days between real epoch and jan 1 2016 (in juce and possibly elsewhere)

// encode/decode given timecode. input is START_KEY_LEN output is ENCODED_KEY_LEN
void encode(unsigned char *input, short gen_date, unsigned char *output);

// return checksum for ENCODED_KEY_LEN bytes
unsigned short getChecksum(const unsigned char *buf);

// return current number of days since internal epoch
unsigned short days_since_epoch();



#endif

