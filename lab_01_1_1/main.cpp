#include<stdio.h>
#include<math.h>

int main()
{
    int a, b, alpha;
    scanf("%d%d%d", &a, &b, &alpha);
    float S;
    S = (a * a - b * b) * tan(alpha) / 4;
    printf("%f", S);
    return 0;
}
