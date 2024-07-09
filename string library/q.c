// @todo: Add a file documentation header as explained in the specs ...
// @todo: Add necessary C standard library headers here ...
#include <stdio.h>
#include "q.h"
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

const char* build_path(const char* parent, const char* separator, const char* const folders[], size_t count)
{
	int size = 0;
	//size = (int)strlen(parent);
	size = (int)my_strlen(parent);
	
	for(int i=0; i<(int)count; i++)
		size += (int)my_strlen(folders[i]);
		//size += (int)strlen(folders[i]);
	
	size += (int)count + 1;
	char* path = debug_malloc((size_t)size);
	
	//strcpy(path, parent);
	my_strcpy(path, parent);
	
	for(int i=0; i<(int)count; i++)
	{
		//strcat(path, folders[i]);
		//strcat(path, separator);
		my_strcat(path, folders[i]);
		my_strcat(path, separator);
	}
	
	path[size-1] = '\0';
	//printf("%s\n",path); 
	
	return (const char*)path;
}

void describe_string(const char* text)
{
	//int len = (int)strlen(text);
	int len = (int)my_strlen(text);
	printf("The length of the path \"%s\" is %d.\n", text, len);
}

void find_string(const char* string, const char* substring)
{
	printf("Searching for a string:\n\t");
	printf("Text:     %s\n\t", string);
	printf("Sub-text: %s\n\t", substring);
	
	//char *pos = strstr(string, substring);
	char *pos = my_strstr(string, substring);
	if(pos != NULL)
		printf("Result:   found %d characters at a position %td.\n",(int)my_strlen(substring) ,pos - string);
		//printf("Result:   found %d characters at a position %td.\n",(int)strlen(substring) ,pos - string);
	else
		printf("Result:   not found\n");
}

void compare_string(const char* lhs, const char* rhs)
{
	//int r = strcmp(lhs, rhs);
	int r = my_strcmp(lhs, rhs);
	if(r < 0)
		printf("Left string goes first.\n");
	else if(r > 0)
		printf("Right string goes first.\n");
	else
		printf("Both strings are equal.\n");
}


