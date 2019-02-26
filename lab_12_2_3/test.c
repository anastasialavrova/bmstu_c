#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"
#include "prime_numbers.h"

int main()
{
    int a1[8];
    int a2[] = {2, 3, 5, 7, 11, 13, 17, 19};

    int a3[1];
    int a4[] = {2};

    int a5[] = {1, 3, 5, 7, 9, 11};
    int a6[] = {1, 3, 5, 7, 9, 11};
    int k = 100;

    int a7[] = {2, 4, 6, 8, 10, 12, 14};
    int a8[] = {2, 100, 4, 100, 6, 100, 8, 100, 10, 100, 12, 100, 14};

    int a9[] = {1, -2, -3, 4, 5, -6, -7};
    int a10[] = {1, -2, 100, -3, 4, 100, 5, -6, 100, -7};

    int err1 = test_prime(a1, a2, 8);
    int err2 = test_prime(a3, a4, 1);
    int err3 = test_new_arr(a5, a6, k, 6);
    int err4 = test_new_arr(a7, a8, k, 7);
    int err5 = test_new_arr(a9, a10, k, 7);

    errors("Test1: ", err1);
    errors("Test2: ", err2);
    errors("Test3: ", err3);
    errors("Test4: ", err4);
    errors("Test5: ", err5);
}

int test_prime(int *a, int *b, int x)
{
    prime_arr(a, x);
    return strncmp((char *)a, (char *)b, x * sizeof(int));
}

int test_new_arr(int *a, int *b, int k, int n)
{
    int new_x;
    copy_arr(a, n, b, &new_x, k);
    return strncmp((char *)a, (char *)b, new_x * sizeof(int));
}


void errors(char *err, int x)
{
    printf("%s", err);
    if (x)
    {
        printf("Failed");
    }
    else
    {
        printf("Passed");
    }
    printf("\n");
}

