// @todo: Add a file documentation header as explained in the specs ...
#include <stdio.h>   // do not remove
// IMPORTANT NOTE: Other than functions fgetc, printf, or fprintf [which are declared in <stdio.h>],
// you must not use any other C standard library function in your submission.

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
void initialize(int latin_freq[], int size, int *ctrl_cnt, int *non_latin_cnt)
{
	for(int i=0; i<size; i++)
		latin_freq[i] = 0;
	
	*ctrl_cnt = 0;
	*non_latin_cnt = 0;
}

void wc(FILE *ifs, int latin_freq[], int *ctrl_cnt, int *non_latin_cnt)
{
	char c;
	if(ifs){
		while((c = fgetc(ifs)) != EOF)
		{
			if(c >= 'A' && c <= 'Z')
			{
				latin_freq[c-'A'] += 1;
			}
			else if(c >= 'a' && c <= 'z')
			{
				latin_freq[c-'a'] += 1;
			}
			else if(c >= 0 && c <= 31)
				*ctrl_cnt += 1;
			else if(c >= 32 && c < 'A')
				*non_latin_cnt += 1;
			else if(c < 'a' && c > 'Z')
				*non_latin_cnt += 1;
			else if(c < 'z' && c >= '~')
				*non_latin_cnt += 1;
		}
	}
}

void print_freqs(int const latin_freq[], int size, int const *ctrl_cnt, int const *non_latin_cnt)
{
	int total = 0;
	for(int i=0; i<size; i++)
	{
		printf("%-10c", 'a'+i);
		total += latin_freq[i];
	}
	printf("\n");
	
	for(int i=0; i<size; i++)
		printf("%-10d", latin_freq[i]);
	
	printf("\n\nLatin Letters     :     %d\n", total);
	printf("Non-Latin Letters :     %d\n", *non_latin_cnt);
	printf("Control Letters   :      %d\n", *ctrl_cnt);
}

// Add documentation [for yourself and not for grading] for the function ...
