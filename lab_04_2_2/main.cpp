#include<stdio.h>

void new_arr(int A[10])
{
    FILE *g = fopen("C:\\Users\\User\\Desktop\\out_1.txt", "w");
    int sum = 0, cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        int x = A[i];
        int y = A[i];
        int f, e = x, j = 0;
        while (x != 0)
        {
            if (j == 0)
                f = x % 10;
            else
                e = x % 10;
            j++;
            x = x / 10;
        }
        if (i > 1 && f == e)
            fprintf(g, "%d ", y);
    }
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
    new_arr(A);
    fclose(f);
    return 0;
}
