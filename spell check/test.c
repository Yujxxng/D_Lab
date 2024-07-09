#include <stdio.h>		// printf()
#include <string.h>     // strcpy


int main(void)
{
	int diff = 'a' - 'A';
	char c = 'c';
	
	if(c >= 'a' && c <= 'z'){
		c = c - diff;
	}
	printf("%c\n", c);
	return 0;
}