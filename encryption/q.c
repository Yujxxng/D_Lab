// TODO1: add file header documentation!!!

#include "q.h" // included because q.c requires access to ASCII_COUNT

// TODO2: include other C standard library headers. for reasons 
// explained in previous assignments/labs, think carefully about 
// the need to add an include file before you do so ...

// TODO3: define functions encrypt and decrpyt ...

void encrypt(const char* str, const char* key)
{
	FILE *fp, *fk, *fe;
	fp = fopen(str, "r");
	fk = fopen(key, "r");
	fe = fopen("cipher.txt", "w");
	
	if(fp == NULL){
		fprintf(stderr, "Unable to open file plain.txt\n");
		return;
	}
	
	char str_key[255];
	fgets(str_key, 255, fk);
	
	char str_text[1024];
	
	int j = 0;
	while((fgets(str_text, 1024, fp)) != NULL)
	{
		//printf("%s", str_text);
		char str_enc[1024];
		
		int i = 0;
		while(str_text[i] != '\0'){
			str_enc[i] = (char)((str_text[i] + str_key[j]) % ASCII_COUNT);
			//printf("enc = %d / %c, text = %d / %c, key = %d / %c\n",
			//		str_enc[i], str_enc[i], str_text[i], str_text[i], str_key[j], str_key[j]);
			i++;
			if(str_key[j+1] == '\n') j = 0;
			else j++;
		}
		
		str_enc[i] = '\0';
		//printf("%s", str_enc);
		if(fe != NULL)
		{
			fputs(str_enc, fe);
			//for(int k=0; str_enc[k] != '\0'; k++)
			//	printf("%c", str_enc[k]);
		}
	}
	
	fclose(fp);
	fclose(fk);
	fclose(fe);
}

void decrypt(const char* str, const char* key)
{
	FILE *fp, *fk, *fo;
	fp = fopen(str, "r");
	fk = fopen(key, "r");
	fo = fopen("out-plain.txt", "w");
	
	if(fp == NULL){
		fprintf(stderr, "Unable to open file cipher.txt\n");
		return;
	}
	
	char str_key[255];
	fgets(str_key, 255, fk);
	
	char str_text[1024];
	
	int j = 0;
	while((fgets(str_text, 1024, fp)) != NULL)
	{
		//printf("%s", str_text);
		char str_dec[1024];
		
		int i = 0;
		while(str_text[i] != '\0'){
			str_dec[i] = (char)((str_text[i] - str_key[j] + ASCII_COUNT) % ASCII_COUNT);
			
			i++;
			if(str_key[j+1] == '\n') j = 0;
			else j++;
		}
		
		str_dec[i] = '\0';
		if(fo != NULL)
		{
			fputs(str_dec, fo);
		}
	}
	
	fclose(fp);
	fclose(fk);
	fclose(fo);
}

int Counts(const char* fileName)
{
	FILE* fp = fopen(fileName, "r");
	if(fp == NULL)
	{
		fprintf(stderr, "Unable to open file\n");
		return -1;
	}
	
	int cnt = 0;
	char str_text[1024];
	//char tmp[1024];
	//int l = 0;
	int flag = 0;
	while((fgets(str_text, 1024, fp)) != NULL)
	{
		int i = 0;
		while(str_text[i] != '\0')
		{
			if(str_text[i] == ' ' || str_text[i] == '\n' || str_text[i] == '\r' || str_text[i] == '\t')
			{
				flag = 1;
			}
			else
			{
				if(flag == 1)
				{
					cnt++;
					flag = 0;
					//printf("%d = ", cnt);
					//for(int j = 0; j < l; j++)
					//	printf("%c", tmp[j]);
					//printf("\n");
					
					//for(int j = 0; j < l; j++)
					//	tmp[j] = '\0';
					//l = 0;
				}
			}
			//tmp[l++] = str_text[i];
			i++;
		}
	}
	/*
	if(tmp[0] != '\0')
	{
		cnt++;
		printf("%d = ", cnt);
		for(int j = 0; j < l; j++)
			printf("%c", tmp[j]);
		printf("\n");
	}
	*/
	cnt++;
	
	fclose(fp);
	
	return cnt;
}