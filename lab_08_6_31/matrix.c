#include<stdio.h>
#include <stdlib.h>
#include"matrix.h"

/*
 Функция создает новую матрицу

 @param row [in]
 @param column [in]
 @param data [out]

 @return функция возвращает матрицу
 */

float** new_matrix(int row, int column)
{
    float **data = calloc((size_t) (row + row * column), sizeof(float*));
    if (!data)
        return NULL;

    for (int i = 0; i < row; i++)
        data[i] = (float*)((char*) data + row * sizeof(float*) + i * column * sizeof(float));
    return data;
}

/*
 Функция считывает матрицу из файла

 @param f [in]
 @param mtrx [in]
 @param row [in]
 @param column [in]
 */

void read_mtrx(FILE *f, float **mtrx, int row, int column)
{
    int x;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            fscanf(f, "%d", &x);
            mtrx[i][j] = x;
        }
    }
}

/*
 Функция нахождения максимального элемента

 @param x [in]
 @param max [in]
 @param r [in]
 @param k [in]
 @param n [in]

 @return возвращает максимальный элемент
 */

float max_elem(float *x, float max, int *r, int k, int n)
{
    for (int i = k; i < n; i++)
    {
        if (*x > max)
        {
            *r = i;
            max = *x;
        }
    }
    return max;
}

/*
 Функция перестановки элементов

 @param a [in]
 @param b [in]
 */

void swap_float (float *a, float *b)
{
    float t;
    t = *a;
    *a = *b;
    *b = t;
}

void copy_matrix(int n, float **a, float **matrica_a)
{
    int i, j;
    for (i = 0; i<n; i++)
        for (j = 0; j<n; j++)
            a[i][j] = matrica_a[i][j];
}

void copy_mass(int n, float *b, float *massiv_b)
{
    int i;
    for (i = 0; i<n; i++)
        b[i] = massiv_b[i];
}



