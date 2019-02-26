#include<stdio.h>
#include<math.h>

float s(float x, float eps)
{
    float s = 1, one = 1000;
    int i = 2;
    while (one > eps)
    {
        if (i % 2 == 0)
        {
            one = -(i * (i + 1) * x) / 2;
        }
        else
        {
            one = (i * (i + 1) * x) / 2;
        }
        s += one;
        i++;
    }
    return s;
}

float f(float x)
{
    return pow((1 + x), -3);
}

int main()
{
    float x;
    float eps, sum, y;
    printf("Enter X (int) and eps (float): ");
    int rc = scanf("%f %f", &x, &eps);
    if (rc == 2)
    {
        y = f(x);
        if (fabs(x) < 1)
            sum = s(x, eps);
        else
            printf("Error!");
    }
    else
    {
        printf("Error!");
    }
    printf("s(x) = %f \nf(x) = %f", sum, y);
    return 0;
}
