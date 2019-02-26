#include<stdio.h>

void divide(int n)
{
    int i = 2;
    while (i <= n)
    {
        int k = 0;
        while (n % i == 0)
        {
            k++;
            n = n / i;
        }
        if (i < n)
        {
            if (k == 1)
                printf("%d*", i);
            if (k > 1)
                printf("%d^%d *", i, k);
        }
        else
        {
            if (k == 1)
                printf("%d", i);
            if (k > 1)
                printf("%d^%d", i, k);
        }
        i++;
    }
}

int main()
{
    printf("Enter an integer: ");
    int x, rc;
    rc = scanf("%d", &x);
    if (rc == 1)
        if (x != 1)
            divide(x);
        else
            printf(" ");
    else
        printf("Error!");
}
