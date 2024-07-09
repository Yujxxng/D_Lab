// TODO1: Add file header documentation ...

#include "q.h"			// encrypt and decrypt function declarations
// TODO2: Add necessary C standard library headers ...

int main(void) {
	const char * keyText = "key.txt";
	
#ifdef ENCRYPT
	// TODO3: read characters from input file plain.txt and write the
	// corresponding encrypted characters to output file cipher.txt
	// using the keyword in file key.txt
	const char * plainText = "plain.txt";
	
	encrypt(plainText, keyText);


#else

	// TODO4: read characters from input file cipher.txt and write the
	// corresponding decrypted characters to output file out-plain.txt
	// using the keyword in file key.txt
	const char* cipher = "cipher.txt";
	
	decrypt(cipher, keyText);
	
	// TODO5: write count of words into stderr
	int cnt = Counts("out-plain.txt");
	fprintf(stderr, "Words: %d\n", cnt);

#endif

	return 0;
}
