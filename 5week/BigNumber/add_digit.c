// TODO
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "add_digit.h"

struct BigNumber
{
	BigDigit* digits;
	size_t length;
};

BigNumber* create_BigNumber(const char* text)
{
	BigNumber* BN = malloc(sizeof(BigNumber));
	BN->length = strlen(text);
	BN->digits = malloc(BN->length * sizeof(BigDigit));
	
	for(size_t i=0; i< BN->length; i++)
	{
		BN->digits[i] = (BigDigit)(*text - '0');
		text++;
	}
	
	return BN;
}

void destroy_BigNumber(BigNumber* number)
{
	free(number->digits);
	free(number);

}

BigNumber* add_BigNumber(const BigNumber* number1, const BigNumber* number2)
{
	BigNumber* res = malloc(sizeof(BigNumber));
	const BigNumber* longNum = number1->length > number2->length ? number1 : number2;
	const BigNumber* shortNum = number1->length > number2->length ? number2 : number1;

	res->length = longNum->length + 1;
	res->digits = malloc(sizeof(BigDigit) * res->length);

	for (size_t i = 0; i < res->length; i++) res->digits[i] = 0;

	int longidx = (int)longNum->length;
	int shortidx = (int)shortNum->length;
	BigDigit carry = 0;
	
	for (int i = (int)(shortidx-1); i >= 0; i--)
	{
		
		res->digits[longidx] = add_BigDigit(longNum->digits[longidx - 1], shortNum->digits[i], &carry);
		longidx--;
		shortidx--;
	}

	while (longidx > 0)
	{
		res->digits[longidx] = add_BigDigit(longNum->digits[longidx - 1], 0, &carry);
		longidx--;
	}

	if (res->digits[0] == 0)
	{
		res->length = res->length - 1;
		BigDigit* tmp = malloc(sizeof(BigDigit)*(res->length));
		for (size_t i = 0; i < res->length; i++)
			tmp[i] = res->digits[i + 1];

		res->digits = tmp;
	}
	
	return res;
}

void print_BigNumber_sum(const BigNumber* number1, const BigNumber* number2, const BigNumber* sum)
{
	const BigNumber* big = number1->length > number2->length ? number1 : number2;
	big = big->length > sum->length ? big : sum;

	size_t bigNum = big->length + 2;

	size_t s = bigNum - number1->length;
	for(int i=0; i < (int)s; i++)
		printf(" ");
	
	for(int i=0; i < (int)number1->length; i++)
		printf("%d", number1->digits[i]);
	printf("\n+");
	
	s = bigNum - number2->length - 1;
	for(int i=0; i < (int)s; i++)
		printf(" ");
	
	for(int i=0; i < (int)number2->length; i++)
		printf("%d", number2->digits[i]);
	printf("\n");
	
	for(int i=0; i < (int)bigNum; i++)
		printf("-");
	printf("\n");
	
	s = bigNum - sum->length;
	for(int i=0; i < (int)s; i++)
		printf(" ");
	for(int i=0; i < (int)sum->length; i++)
		printf("%d", sum->digits[i]);
	printf("\n");
}