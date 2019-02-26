#include<stdio.h>
#include<math.h>

void new_arr(float A[10])
{
    int n = 10;
    FILE *g = fopen("C:\\Users\\User\\Desktop\\out_1.txt", "w");
    for (int i = 0; i < n; i++)
    {
        if(sqrt(A[i]) - (int)sqrt(A[i]) < 0.001)
        {
            printf("%f ", A[i]);
            for (int j = i; j < n - 1; j++)
                A[j] = A[j + 1];
            n--;
            i--;
        }
    }
    for (int i = 0; i < n; i++)
        fprintf(g, "%f ", A[i]);
    fclose(g);
}

int main(int argc, char** argv)
{
    FILE *f;
    if (argc != 2)
    {
        fprintf(stderr, "num_reader.exe <file-name>\n");
        return -1;
    }

    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        fprintf(stderr, "I/O error\n");
        return -2;
    }

    float A[10];
    int x, i = 0;
    while(1)
    {
        fscanf(f, "%f", &A[i]);
        if(feof(f))
            break;
        i++;
    }
    new_arr(A);
    fclose(f);
    return 0;
}
