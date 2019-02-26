#include<stdio.h>

void sred_arifm(int A[10])
{
    int sum = 0, cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        if (A[i] < 0)
        {
            sum += A[i];
            cnt++;
        }
    }
    FILE *f = fopen("C:\\Users\\User\\Desktop\\out_2.txt", "w");
    if (cnt > 0)
    {
        float ans = sum / cnt;
        fprintf(f, "%f", ans);
    }
    else
        fprintf(f, "there are no negative elements in the array");
    fclose(f);
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

    int A[10], i = 0;
    while(1)
    {
        fscanf(f, "%d", &A[i]);
        if(feof(f))
            break;
        i++;
    }
    sred_arifm(A);
    fclose(f);
    return 0;
}
