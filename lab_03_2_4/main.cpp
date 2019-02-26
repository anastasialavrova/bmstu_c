#include<stdio.h>

int maximum(FILE *f)
{
    int i, cnt = 0;
    float n, mx;
    if (fscanf(f, "%f", &mx) == 1)
    {
        while(fscanf(f, "%f", &n) == 1)
        {
            cnt++;
            if (n > mx)
            {
                mx = n;
                i = cnt;
            }
        }
    }
    return i;
}

int minimum(FILE *f)
{
    int i, cnt = 0;
    float n, mn;
    if (fscanf(f, "%f", &mn) == 1)
    {
        while(fscanf(f, "%f", &n) == 1)
        {
            cnt++;
            if (n < mn)
            {
                mn = n;
                i = cnt;
            }
        }
    }
    return i;
}

float average(FILE *f, int *min_i, int *max_i)
{
    int cnt = 0, cnt2 = 0;
    float n, sum = 0.0;
    while(1)
    {
        fscanf(f, "%f", &n);
        if (feof(f))
            break;
        if (cnt < *max_i && cnt > *min_i)
        {
            sum += n;
            cnt2++;
        }
        cnt++;
    }
    float a = sum/cnt2;
    return a;
}

int main(int argc, char* argv[])
{
    FILE *f;
    if (argc != 2)
    {
        printf("Error!");
        return -1;
    }
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Error!");
        return -2;
    }

    int min_i, max_i;
    float a;
    max_i = maximum(f);
    fseek(f, 0, SEEK_SET);
    min_i = minimum(f);
    fseek(f, 0, SEEK_SET);
    a = average(f, &min_i, &max_i);
    printf("%f", a);
    fclose(f);

}
