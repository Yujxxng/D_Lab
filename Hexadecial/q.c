// @todo: Add a file documentation header as explained in the specs ...

// @todo: Add necessary C standard library headers here ...
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

void print_data(const void* ptr, size_t size, size_t span)
{
	for (int j = 0; j < (int)size;)
	{
		for (int i = 0; i < (int)span; i++)
		{
			printf("%x ", *((char*)ptr + i + j));
			if ((i + 1) % 4 == 0) printf("  ");
			if ((i + 1) % (int)span == 0) printf("|  ");
		}

		for (int i = 0; i < (int)span; i++)
		{
			printf(" %c", *((char*)ptr + i + j));
			if ((i + 1) % (int)span == 0) printf("\n");
			else if ((i + 1) % 4 == 0) printf("  ");
		}
		j = j + (int)span;
	}
}