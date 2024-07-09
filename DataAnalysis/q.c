// TODO: File documentation block required

#include "q.h" // we're including q.h here because we want to apply the DRY principle [see specs for additional info]
// TODO: Include all necessary C standard library headers 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// TODO: Definitions of functions declared in q.h go here ...

double* read_data(char const* file_name, int* ptr_cnt)
{
	*ptr_cnt = 0;
	FILE* fp;
	fp = fopen(file_name, "r");

	if (!fp)
	{
		fprintf(stderr, "File opening failed");
		return NULL;
	}
	char str[255];
	while (fgets(str, 255, fp) != NULL)
	{
		//printf("%s\n", str);
		int i = 0;
		while (str[i] != '\0')
		{
			if(str[i] == '.') 
				(*ptr_cnt)++;
			i++;
		}
	}
	rewind(fp);
	
	double* values = malloc((size_t)(*ptr_cnt) * sizeof(double));
	int i = 0;
	while (fscanf(fp, "%lf", &values[i]) == 1)
	{
		//printf("%d, %.2lf\n", i, values[i]);
		i++;
	}
	
	fclose(fp);

	return values;
}

double max(double const *begin, double const *end)
{
	double maxNum = -1.0;
	while(begin != end)
	{
		if(maxNum < *begin)
			maxNum = *begin;
		begin++; 
	}
	return maxNum;
}

double min(double const *begin, double const *end)
{
	double minNum = 1000.0;
	while(begin != end)
	{
		if(minNum > *begin)
			minNum = *begin;
		begin++; 
	}
	return minNum;
}

double average(double const *begin, double const *end)
{
	double avg = 0;
	double sum = 0;
	int cnt = 0;
	while(begin != end)
	{
		sum += (*begin);
		begin++;
		cnt++;
	}
	
	avg = sum / cnt;
	
	return avg;
}

double variance(double const *begin, double const *end)
{
	double const *b = begin;
	double avg = average(b, end);
	double sum = 0;
	double var = 0;
	int cnt = 0;
	
	while(begin != end)
	{
		double tmp = ((*begin) - avg);
		sum += (tmp * tmp);
		begin++;
		cnt++;
	}
	
	var = sum / (cnt-1);
	
	return var;
}

double std_dev(double const *begin, double const *end)
{
	double const *b = begin;
	double var = variance(b, end);
	
	return sqrt(var);
}
double median(double *base, int size)
{
	double *b = base;
	selection_sort(b, size);
	
	if(size % 2 == 0)
	{
		double sum = 0;
		int idx = size / 2;
		
		sum += *(base + idx);
		sum += *(base + (idx - 1));

		return sum / 2;
	}
	
	else
	{
		int idx = size / 2;
		return *(base + idx);
	}
}
void selection_sort(double *base, int size)
{
	for(int i = 0; i < size - 1; i++)
	{
		double n = *(base + i);
		int idx = i;
		for(int j = i+1; j < size; j++)
		{
			if(n > *(base+j))
			{
				n = *(base+j); 
				idx = j;
			}
		}
		
		double tmp = *(base + i);
		*(base + i) = n;
		*(base + idx) = tmp;
	}
}
void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grades)
{
	double grades[TOT_GRADE];
	int cnt = 0;
	
	for (int i = 0; i < TOT_GRADE; i++)
		grades[i] = 0;

	while(begin != end)
	{
		double num = *begin;
		if(num >= 90) grades[A_GRADE]++;
		else if(num >= 80 && num < 90) grades[B_GRADE]++;
		else if(num >= 70 && num < 80) grades[C_GRADE]++;
		else if(num >= 60 && num < 70) grades[D_GRADE]++;
		else grades[F_GRADE]++;
		
		begin++;
		cnt++;
	}
	
	for(int i = 0; i < TOT_GRADE; i++)
	{
		*(ltr_grades + i) = (grades[i] / cnt) * 100.0;
	}
}
