// @todo: Add a file documentation header as explained in the specs ...

// @todo: Add necessary C standard library headers here ...
#include "my_string.h"
// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in my_string.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...


// @todo: Provide the definition(s) of function(s) that
// match the declaration(s) in my_string.h ...

// For each function -

// Add documentation [for yourself and not for grading] for the function ...

// @todo: Provide the definition of the function(s) that
// match(es) the declaration(s) in my_string.h ...

size_t my_strlen(const char* str)
{
	size_t size = 0;
	
	int i = 0;
	while(str[i] != '\0')
	{
		size++;
		i++;
	}
	
	return size;
}

char* my_strcpy(char* dest, const char* src)
{
	if(dest == NULL)
		return NULL;
	
	while(*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	
	return dest;
}

char* my_strcat(char* dest, const char* src)
{
	if (dest == NULL) return NULL;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return dest;
}

int my_strcmp(const char* lhs, const char* rhs)
{
	while(*lhs != '\0' && *rhs != '\0')
	{
		if(*lhs < *rhs) return -1;
		else if(*lhs > *rhs) return 1;
		
		lhs++;
		rhs++;
	}
	
	if(*lhs != '\0') return 1;
	else if(*rhs != '\0') return -1;
	
	return 0;
}

char* my_strstr(const char* str, const char* substr)
{
	if(*substr == '\0') return (char*)str;
	
	while(*str != '\0')
	{
		if(*str == *substr)
		{
			const char* tmp1 = str;
			const char* tmp2 = substr;
			int flag = 1;
			
			while(*tmp2 != '\0')
			{
				if(*tmp1 != *tmp2)
				{
					flag = 0;
					break;
				}
				tmp1++;
				tmp2++;
			}
			if(flag) return (char*)str;
			
			str = tmp1;
		}
		str++;
	}
	
	return NULL;
}
