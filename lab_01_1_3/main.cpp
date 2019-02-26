#include<stdio.h>

int main()
{
    int n, a, p, e;
    scanf("%d", &n);
    n = n - 1;
    p = n / 36 + 1;
    e = (n % 36) / 4 + 1;
    printf("Entrance: %d;  floor: %d", p, e);
    return 0;
}
