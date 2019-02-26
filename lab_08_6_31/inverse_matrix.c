#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include"check.h"
#include"matrix.h"
#include"inverse_matrix.h"
#include"print.h"

/*
 Функция подготавливает данные для дальнейшего превращения в обратную матрицу
 и отправляет данные в функцию для вывода информации в текстовый файл

 @param mtr_1 [in]
 @param res [in]
 */

void inverse_matrix(char *mtr_1, char *res)
{
    FILE *f1 = fopen(mtr_1, "r");
    FILE *f2 = fopen(res, "w+");
    int error = check_file(f1) + check_file(f2);
    if (!error)
    {
        int row1, column1;
        fscanf(f1, "%d", &row1);
        fscanf(f1, "%d", &column1);
        float **mtrx1 = new_matrix(row1, column1);
        read_mtrx(f1, mtrx1, row1, column1);
        float **result = new_matrix(row1, column1);
        int res = inverse_Gauss(mtrx1, row1, result);
        if (res == 0)
        {
            print_matrix(f2, result, row1, column1);
        }
        else
            fprintf(f2, "Matrix determinant is zero!");
    }
    fclose(f1);
    fclose(f2);
}

/*
 функция подсчитывается обратную матрицу методом Гаусса

 @param matrica_a [in]
 @param n [in]
 @param massiv_b [in]
 @param x [in]
 @param flag [out]

 @return
 */


int gauss(float **matrica_a, int n, float *massiv_b, float *x)
{
    int i, j, k, r, result = 0;
    float c, M, max, s, **a, *b;
    a = new_matrix(n, n);
    b = (float*)calloc(n, sizeof(float));
    copy_matrix(n, a, matrica_a);
    copy_mass(n, b, massiv_b);
    for (i=0, k = 0; k<n; k++)
    {
        max = fabs(a[k][k]);
        r = k;
        int i1 = 0;
        max = max_elem(a[i1], max, &r, k + 1, n);
        for (j = 0; j<n; j++)
        {
            swap_float(&a[k][j], &a[r][j]);
        }
        swap_float(&b[k], &b[r]);
        for (i = k + 1; i<n; i++)
        {
            for (M = a[i][k] / a[k][k], j = k; j<n; j++)
                a[i][j] -= M * a[k][j];
            b[i] -= M * b[k];
        }

    }

    if (a[n - 1][n - 1] == 0)
        if (b[n - 1] == 0)
            result = -1;
        else
            result = -2;
    else
    {
        for (i = n - 1; i >= 0; i--){
            for (s = 0, j = i + 1; j<n; j++)
                s += a[i][j] * x[j];
            x[i] = (b[i] - s) / a[i][i];
        }
        result = 0;
    }

    return result;

}

/*
 Функция принимает на вход матрицу, создает вспомогательные массивы, перенаправляет
 матрицу в "функцию-калькулятор"

 @param a [in]
 @param n [in]
 @param y [in]
 @param flag [out]

 @return возвращает 0, если получилось создать обратную матрицу (определитель не равен нулю), и
 возвращает -1 в ином случае
 */

int inverse_Gauss(float **a, int n, float **y)
{
    int i, j, res, flag = 0;
    float *b, *x;
    b = (float*)calloc(n, sizeof(float));
    x = (float*)calloc(n, sizeof(float));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (j == i)
                b[j] = 1;
            else
                b[j] = 0;
        res = gauss(a, n, b, x);
        if (res != 0)
            break;
        else
            for (j = 0; j < n; j++)
            {
                y[j][i] = x[j];
            }
    }
    free(x);
    free(b);

    if (res != 0)
        flag = -1;
    else
        flag = 0;

    return flag;
}



