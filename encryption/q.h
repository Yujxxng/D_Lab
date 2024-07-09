// TODO1: provide file header documentation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef Q_H
#define Q_H

// Don't remove!!!
// We're limiting ASCII set to the basic character set
// with encoding from 0 to 127
#define ASCII_COUNT 128

// TODO2: your clients will be given this header file since they
// will have no access to the definitions of functions
// encrypt and decrypt - therefore, provide header documentation
// for function encrypt

// TODO3: declaration for function encrypt
void encrypt(const char* str, const char* key);

// TODO4: your clients will be given this header file since they
// will have no access to the definitions of functions
// encrypt and decrypt - therefore, provide header documentation
// for function decrypt

// TODO5: declaration for function decrypt
void decrypt(const char* str, const char* key);


#endif // Q_H
int Counts(const char* fileName);