#include<stdio.h>

int main()
{
    int v1, t1, v2, t2, V;
    float T;
    scanf("%d%d%d%d", &v1, &t1, &v2, &t2);
    V = v1 + v2;
    T = (t1 * v1 + t2 * v2) / V;
    printf("%f", T);
    return 0;
}
