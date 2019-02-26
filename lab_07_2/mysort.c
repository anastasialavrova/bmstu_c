#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mysort.h"

/*
Функция копирования массива

 @param pb_src [in]
 @param pe_src [in]
 @param pb_dst [in]
 @param pe_dst [in]
*/

void copy_array(const int *pb_src, const int *pe_src, int *pb_dst, int **pe_dst)
{
    *pe_dst = pb_dst + (pe_src - pb_src);
    for(; pb_dst < *pe_dst; pb_dst++, pb_src++)
        *pb_dst = *pb_src;
}

/*
Функция сравнения двух элементов

 @param f [in]
 @param s [in]

 @return возвращает разницу между этими двумя значениями
*/

int compare_int(const void* f, const void* s)
{
    const int *a = (const int*)f;
    const int *b = (const int*)s;
    return *a - *b;
}

/*
 Функция перестановки двух элементов

 @param p1 [in]
 @param p2 [in]
 @param size [in]
*/

void swap(void *p1, void *p2, size_t size)
{
    void *tmp = malloc(size);
    if (tmp)
    {
        memcpy(tmp, p1, size);
        memcpy(p1, p2, size);
        memcpy(p2, tmp, size);
        free(tmp);
    }
}

/*
Функция сортировки массива методом "пузырька"

 @param a [in]
 @param n [in]
 @param size [in]
 @param compare [in]
*/

void mysort(void *a, int n, size_t size, int(*compare_int)(const void*, const void*))
{
    int stop = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < stop - 1; j++)
        {
            if (compare_int(((int*)a + j), ((int*)a + j + 1)) >=0)
            {
                swap(((int*)a + j), ((int*)a + j + 1), size);
            }
        }
        stop--;

    }
}
