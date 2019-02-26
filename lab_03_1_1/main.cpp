#include<stdio.h>

#define file_is_empty -1
#define one_element -2

int process(FILE *f, int *max1, int *max2)
{
	int n, cnt = 0, m;
	if (fscanf(f, "%d", max1) > 0)
	{
		while (fscanf(f, "%d", &n) == 1)
		{
			cnt++;
			if (cnt == 1)
			{
				*max2 = n;
				if (*max2 > *max1)
				{
					int a = *max1;
					*max1 = *max2;
					*max2 = a;
				}
			}
			else
			{
				if (n > *max1)
				{
					*max2 = *max1;
					*max1 = n;
				}
				if (n > *max2 && n < *max1)
				{
					*max2 = n;
				}
			}
		}
		if (cnt == 0)
		{
			return one_element;
		}
		else
		{
			return 0;
		}
	}
	return file_is_empty; 
}

int main()
{
	FILE *f = fopen("C:\\Users\\User\\Desktop\\input4.txt", "r");
	int max1, max2, n;
	n = process(f, &max1, &max2);
	if (n == 0)
		printf("\n%d %d", max1, max2);
	else
		if (n == file_is_empty)
			printf("File is empty");
		if (n == one_element)
			printf("The file contains one element");
	fclose(f);
	return 0;
}