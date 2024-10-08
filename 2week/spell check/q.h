// @todo: Add a file-level documentation header as explained in Lab 2 specs ...
#include <stdio.h>

typedef int WordCount;
typedef unsigned char WordLength;
typedef int ErrorCode;

struct DictionaryInfo
{
	WordLength shortest;
	WordLength longest;
	WordCount count;
};
typedef struct DictionaryInfo DictionaryInfo;

enum ErrorCode
{
	FILE_OK = -1,
	FILE_ERR_OPEN = -2,
	WORD_OK = -3,
	WORD_BAD = -4
};
enum 
{
	LONGEST_WORD = 50
};

// @todo: Copy type aliases and macros from the current specs

// @todo: Provide function-level documentation header for each function 
// as explained in Assignment 2 specs ...
// It is important that you provide a function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users ...

// @todo: Now, provide the declaration or prototype of the functions 
// str_to_upper, words_starting_with, spell_check, word_lengths, and info
char* str_to_upper(char* string);
WordCount words_starting_with(const char* dictionary, char letter);
ErrorCode spell_check(const char* dictionary, const char* word);
ErrorCode word_lengths(const char* dictionary, WordCount length[], WordLength count);
ErrorCode info(const char* dictionary, DictionaryInfo* info);

