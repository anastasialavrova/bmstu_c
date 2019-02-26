#include<stdio.h>
#include<stdlib.h>
#include "func.h"

#define N 100

int func(int *beg, const int *end, int n);

int main()
{
	FILE *f = fopen("C:\\Users\\User\\Desktop\\in_1.txt", "r");
	if (f == NULL)
	{
		fprintf(stderr, "I/O error\n");
		return -2;
	}
	int *a = (int*)malloc(N * sizeof(int));
	int *pa = a;
	int cnt = 0;
	fscanf(f, "%d", pa);
	while (1)
	{
		pa++;
		fscanf(f, "%d", pa);
		cnt++;
		if (feof(f))
			break;
		if (cnt == 100)
			break;
	}
	int *end = pa;
	int *beg = a;
	fclose(f);
	FILE *g = fopen("C:\\Users\\User\\Desktop\\out_1.txt", "w");
	fprintf(g, "%d", func(beg, end, cnt));
	free(a);
	fclose(g);
	return 0;
}
