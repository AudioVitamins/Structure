/* Copyright (C) 2016 Andrew Shakinovsky
 */
#include "unlockcode.h"
#include "ucshared.h"
#include <inttypes.h>
#ifdef WIN32
#include <Windows.h>
#else
#include <time.h>
#endif


#ifdef WIN32
/* 11,644,473,600,000 milliseconds separate the Win32 Epoch from the
 UNIX Epoch. */
#define EPOCH_OFFSET 0x00000A9730B66800i64

/* FILETIME is in 100ns units */
#define MSEC_PER_FTIME   10000

int64_t currentSeconds()
{
    SYSTEMTIME stime;
    FILETIME ftime;
    __int64 msec;
    
    GetSystemTime(&stime);
    SystemTimeToFileTime(&stime, &ftime);
    msec = (((__int64)ftime.dwHighDateTime << 32)
            + (__int64)ftime.dwLowDateTime)
    / MSEC_PER_FTIME;
    msec -= EPOCH_OFFSET;
    return msec / 1000;
    
}
#else
int64_t currentSeconds() {
    time_t t;
    time(&t);
    return t;
}
#endif

// random table for encoding/decoding
#define NUMRAND 199
static const unsigned char randoms[NUMRAND] = {
    198,   17,   41,   22,   13,   133,   1,   196,   127,   255,   196,   167,   203,   135,   32,   39,   153,
    197,   99,   166,   74,   71,   98,   163,   251,   62,   42,   15,   17,   126,   34,   122,   225,   68,
    211,   220,   13,   208,   141,   83,   200,   128,   212,   34,   208,   68,   43,   175,   12,   190,   154,
    91,   18,   128,   245,   228,   188,   223,   123,   7,   233,   86,   117,   13,   82,   118,   106,   60,
    153,   98,   32,   72,   52,   128,   32,   67,   147,   67,   69,   140,   229,   39,   100,   72,   192,
    64,   43,   104,   143,   28,   25,   210,   212,   119,   217,   238,   176,   157,   5,   164,   34,   91,
    241,   68,   156,   107,   127,   186,   192,   193,   162,   41,   46,   99,   64,   178,   3,   170,   217,
    13,   245,   28,   86,   133,   176,   155,   186,   62,   197,   89,   149,   162,   228,   139,   83,   119,
    190,   47,   78,   42,   82,   233,   177,   220,   83,   32,   122,   145,   62,   28,   119,   73,   41,
    26,   231,   154,   179,   227,   239,   66,   225,   240,   23,   217,   104,   8,   113,   49,   127,   160,
    132,   214,   231,   201,   131,   178,   241,   91,   251,   205,   170,   116,   145,   91,   218,   80,
    208,   102,   190,   218,   243,   254,   17,   69,   135,   191,   174,   109
};





void encode(unsigned char *input, short gen_date, unsigned char *output)
{
    // position into rand array
    int pos = gen_date % NUMRAND;
    int i;
    for (i = 0; i < START_KEY_LEN; i++) {
        output[i] = input[i] ^ randoms[pos];
        pos++;
        if (pos == NUMRAND)
            pos = 0;
    }
    output[i] = (gen_date >> 8) & 0xff;
    output[i + 1] = gen_date & 0xff;
    
}

unsigned short days_since_epoch()
{
    // days since system epoch
    int64_t curdays = currentSeconds() / (60 * 60 * 24);
    
    // days since our own epoch (generate day)
    return (unsigned short)(curdays - EPOCH);
    
}

unsigned short getChecksum(const unsigned char *buf)
{
    unsigned short sum;
    short left = 0x0056;
    short right = 0x00AF;
    
    for (int i = 0; i < ENCODED_KEY_LEN; i++) {
        right += buf[i];
        if (right > 0xff)
            right -= 0xff;
        left += right;
        if (left > 0xff)
            left -= 0xff;
        
    }
    
    sum = (left << 8) + right;
    return sum;
}

int luhn(int num)
{
    const int m[] = { 0,2,4,6,8,1,3,5,7,9 }; // mapping for rule 3
    int odd = 1, sum = 0;
    
    while (num) {
        int digit = num % 10;
        num /= 10;
        sum += odd ? digit : m[digit];
        odd = !odd;
    }
    
    return sum % 10;
}

// check and return true if last digit is a valid check digit for rest
bool luhnvalid(int num)
{
    int cs = num % 10;
    int ccs = luhn(num / 10);
    return cs == ccs;
    
}

//generate check digit and add to end of number
int luhncreate(int num) {
    return (num * 10) + luhn(num);
}
