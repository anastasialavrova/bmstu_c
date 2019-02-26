//сортировка "Пузырек"
// выбранный тип - Int
//сортировка от большего к меньшему
#include <stdlib.h>
#include<stdio.h>

int get_number_by_pos(FILE *f, int i)
{
    int n;
    fseek(f, 0, SEEK_SET);
    fseek(f, i * sizeof(int), SEEK_CUR);
    fread(&n, sizeof(int), 1, f);
    return n;
}

int put_number_by_pos(FILE *f, int i, int a)
{
    int n;
    fseek(f, 0, SEEK_SET);
    fseek(f, i * sizeof(int), SEEK_SET);
    fwrite(&a, sizeof(int), 1, f);
}

int srt(FILE *f)
{
    int n = 1, k;
    printf("Input amount: ");
    while (n < k)
    {
        for (int i = 0; i < (k - n); i++)
        {
            if (get_number_by_pos(f, i) > get_number_by_pos(f, (i+1)))
            {
                int x = get_number_by_pos(f, i);
                int y = get_number_by_pos(f, (i+1));
                put_number_by_pos(f, (i + 1), x);
                put_number_by_pos(f, i, y);
            }
        }
    }

}

int rd (FILE *f)
{
    int n, k;
    printf("Input amount: ");
    scanf("%d", &k);
    fseek(f, 0, SEEK_SET);
    for (int i = 0; i < k; i++)
    {
        fread(&n, sizeof(int), 1, f);
        printf("%d\n", n);
    }
}

int wrt(FILE *f)
{
    int n, k;
    printf("Input amount: ");
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        n = rand() % 10;
        fwrite(&n, sizeof(int), 1, f);

    }
}

int main()
{
    FILE *f = fopen("file.dat", "w+b");
    if (f == NULL)
        printf("Error!");
    else
    {
        wrt(f);
        rd(f);
        srt(f);
    }
    fclose(f);
}
