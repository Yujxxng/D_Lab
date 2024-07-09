// TODO: File documentation block required

// NOTE 2: Even if you don't need the NULL, don't remove this macro ...
#define NULL ((void*)0) 

// NOTE 3: When uploading this file for grading, make sure to remove all
// standard library includes from this file.
// The auto-grader will not accept your submission if the file contains
// include directives.

// NOTE 4: When uploading this file for grading, make sure to remove
// all references to the subscript operator or the [ or ] symbols from your code. 
// It is important that even your comments should not include these symbols.

// TODO: Definitions of functions declared in q.h go here ...
#include "q.h"

char const* find(char const *begin, char const *end, char val)
{
	while(*begin != *end)
	{
		if(*begin == val)
			return begin;
		
		begin++;
	}
	
	return NULL;
}

char const* find_any(char const *begin, char const *end, char const *vals, int len)
{
	for(int i=0; i < len; i++)
	{
		char const *b = begin;
		char const *e = end;
		
		while(*b != *e)
		{
			if(*b == *vals) return b;
			b++;			
		}
		vals++;
	}
	
	return NULL;
}


int count(char const *begin, char const *end, char val)
{
	int cnt = 0;
	while(*begin != *end)
	{
		if(*begin == val) cnt++;
		begin++;
	}
	return cnt;
}


int count_any(char const *begin, char const *end, char const *vals, int len)
{
	int cnt = 0;
	for(int i=0; i < len; i++)
	{
		char const * b = begin;
		char const * e = end;
		
		while(*b != *e)
		{
			if(*b == *vals) cnt++;
			b++;		
		}
		vals++;
	}
	
	return cnt;
}

int compare(char const *begin1, char const *begin2, int len)
{
	for(int i=0; i<len; i++)
	{
		if(*begin1 < *begin2) return -1;
		else if(*begin1 > *begin2) return 1;
		
		begin1++;
		begin2++;
	}
	
	return 0;
}

void exchange(char *begin1, char *begin2, int len)
{
	for(int i=0; i<len; i++)
	{
		char tmp = *begin1;
		
		*begin1 = *begin2;
		*begin2 = tmp;
		
		begin1++;
		begin2++;
		tmp++;
	}
}


void copy(char *dst, char *src, int len)
{
	dst = dst + len - 1;
	src = src + len - 1;
	for(int i=0; i<len; i++)
	{
		*dst = *src;
		dst--;
		src--;
	}
}
