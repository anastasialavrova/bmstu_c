#include<stdio.h>

void sort(int A[10])
{
    int sum = 0, cnt = 0;
    for (int i = 0; i < 9; i++)
    {
       int min_i = i;
       for(int j = i + 1; j < 10; j++)
       {
           if (A[j] < A[min_i])
               min_i = j;
       }
       if (min_i != i)
       {
           int t = A[i];
           A[i] = A[min_i];
           A[min_i] = t;
       }
    }
    FILE *g = fopen("C:\\Users\\User\\Desktop\\out_1.txt", "w");
    for (int i = 0; i < 10; i++)
        fprintf(g, "%d ", A[i]);
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

    int A[10], x, i = 0;
    while(1)
    {
        fscanf(f, "%d", &A[i]);
        if(feof(f))
            break;
        i++;
    }
    sort(A);
    fclose(f);
    return 0;
}
