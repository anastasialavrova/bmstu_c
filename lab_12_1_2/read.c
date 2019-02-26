#include<stdio.h>
#include<stdlib.h>
#include"read.h"

/*
Функция подсчета количества элементов
 @param f [in]

 @return возвращает количество элементов в массиве
*/

int read_cnt(FILE *f)
{
    int cnt = 0, x = 0;
    while (1)
    {
        fscanf(f, "%d", &x);
        if (feof(f))
        {
            cnt++;
            break;
        }
        cnt++;
    }
    return cnt;
}

/*
Функция считывания элементов из файла

 @param f [in]
 @param pe [in]
 @param cnt [in]
*/

void read(FILE *f, int **pe, int cnt)
{
    rewind(f);
    int *p = NULL;
    p = *pe;
    while (fscanf(f, "%d", p) == 1)
        p++;
    *pe = p;
}



