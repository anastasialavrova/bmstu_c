#include<stdio.h>
#include<stdlib.h>

# define N 100

int func(int *beg, const int *end, int n)
{
	int mx = *beg + *end;
	int cnt = 0, k;
	if (n % 2 == 0)
		k = n / 2;
	else
		k = n / 2 + 1;
	while (cnt < k)
	{
		int ans = *beg + *end;
		if (ans > mx)
			mx = *beg + *end;
		beg++;
		end--;
		cnt++;
	}
	return mx;
}

