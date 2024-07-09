// @todo: Add a file documentation header as explained in the specs ...
#include "q.h"
#include <string.h>
#include <stdbool.h>
// @todo: Add necessary C standard library headers here ...

// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...


// @todo: Provide the definition(s) of function(s) that
// match the declaration(s) in q.h ...

// For each function -

// Add documentation [for yourself and not for grading] for the function ...

// @todo: Provide the definition of the function(s) that
// match(es) the declaration(s) in q.h ...
ErrorCode ec;

char* str_to_upper(char* string)
{
	for(int i=0; string[i] != '\0'; i++)
	{
		if(string[i] >= 'a' && string[i] <= 'z'){
			*(string + i) = *(string + i) - ('a' - 'A');
		}
	}
	
	return string;
}

WordCount words_starting_with(const char* dictionary, char letter)
{
	FILE *fp;
	fp = fopen(dictionary, "r");
	
	if(fp == NULL)
		return FILE_ERR_OPEN;
	
	char* up_letter = str_to_upper(&letter);
	
	char str[LONGEST_WORD + 1];
	char* ch;
	
	int cnt = 0;
	while((fgets(str, LONGEST_WORD + 1, fp)) != NULL)
	{
		ch = str_to_upper(str);
		if(ch[0] == up_letter[0]) cnt++;
	}
	
	fclose(fp);
	
	return cnt;
}

ErrorCode spell_check(const char* dictionary, const char* word)
{
	FILE *fp;
	fp = fopen(dictionary, "r");
	
	if(fp == NULL)
		return FILE_ERR_OPEN;
	
	const size_t num_word = strlen(word);
	char tmp[num_word + 1];
	memcpy(tmp, word, num_word+1);

	char* upWord = str_to_upper(tmp);

	char* ch;
	char str[LONGEST_WORD + 1];
	
	while((fgets(str, LONGEST_WORD+1, fp)) != NULL)
	{
		ch = str_to_upper(str);
		
		int i = 0;
		bool flag = true;
		while(upWord[i] != '\0')
		{
			if(ch[i] != upWord[i])
			{
				flag = false;
				break;
			}
			i++;	
		}
		if(flag && ch[i] != '\n')
			return WORD_BAD;
		
		if(flag)
			return WORD_OK;
	}
	
	fclose(fp);
	
	return WORD_BAD;
}


ErrorCode word_lengths(const char* dictionary, WordCount length[], WordLength count)
{
	FILE *fp;
	fp = fopen(dictionary, "r");
	
	if(fp == NULL)
		return FILE_ERR_OPEN;
	
	char str[LONGEST_WORD + 1];
	while((fgets(str, LONGEST_WORD + 1, fp)) != NULL)
	{
		
		int cnt = 0;
		int i = 0;
		
		while(str[i] != '\n')
		{
			cnt++;
			i++;
		}
		if(cnt > 0 && count >= cnt)
			length[cnt]++;
	
		for(int j=0; j<=LONGEST_WORD; j++)
			str[j] = '\0';
	}	
	
	fclose(fp);
	return FILE_OK;
}


ErrorCode info(const char* dictionary, DictionaryInfo* info)
{
	FILE *fp;
	fp = fopen(dictionary, "r");
	
	if(fp == NULL)
		return FILE_ERR_OPEN;
	
	WordCount len[LONGEST_WORD + 1];
	for(WordLength i = 0; i <= LONGEST_WORD; i++)
		len[i] = 0;

	ErrorCode error = word_lengths(dictionary, len, LONGEST_WORD);
	if(error == FILE_ERR_OPEN) return FILE_ERR_OPEN;
	
	
	info->shortest = LONGEST_WORD + 1;
	info->longest = 0;
	
	int total = 0;
	for(WordLength i = 1; i <= LONGEST_WORD; i++)
	{
		if((info->shortest == LONGEST_WORD + 1) && len[i] > 0) info->shortest = i;
		if(len[i] != 0) info->longest = i;
		
		total += len[i];
	}
	
	info->count = total;

	
	fclose(fp);
	return FILE_OK;
}