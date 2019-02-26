#include<stdio.h>
#include<stdlib.h>
#include "func.h"

int main()
{
	int N = 8, k = 10;
	int *a = (int*)malloc(N * sizeof(int));
	int *end = a;
	for (int i = 0; i < N; i++)
	{
		a[i] = k;
		k += 10;
		end++;
	}
	int *beg = a;
	int mx1 = func(beg, end, N);
	if (mx1 == 80)
		printf("Test #1 OK");
	free(a);
}
