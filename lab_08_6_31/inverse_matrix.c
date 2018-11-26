#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include"check.h"
#include"matrix.h"
#include"inverse_matrix.h"

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
            for (int i = 0; i < row1; i++)
            {
                for (int j = 0; j < column1; j++)
                {
                fprintf(f2, "%f ", result[i][j]);
                }
                fprintf(f2, "\n");
            }
        }
        else
            fprintf(f2, "Matrix determinant is zero!");
    }
    fclose(f1);
    fclose(f2);
}


int Gauss(float **matrica_a, int n, float *massiv_b, float *x)
{
    int i, j, k, r;
    float c, M, max, s, **a, *b;
    a = new_matrix(n, n);
    for (i = 0; i<n; i++)
        a[i] = (float*)calloc(n, sizeof(float));
    b = (float*)calloc(n, sizeof(float));
    for (i = 0; i<n; i++)
        for (j = 0; j<n; j++)
            a[i][j] = matrica_a[i][j];
    for (i = 0; i<n; i++)
        b[i] = massiv_b[i];
    for (k = 0; k<n; k++)
    {
        max = fabs(a[k][k]);
        r = k;
        for (i = k + 1; i<n; i++)
            if (fabs(a[i][k])>max)
            {
                max = fabs(a[i][k]);
                r = i;
            }
        for (j = 0; j<n; j++)
        {
            c = a[k][j];
            a[k][j] = a[r][j];
            a[r][j] = c;
        }
        c = b[k];
        b[k] = b[r];
        b[r] = c;
        for (i = k + 1; i<n; i++)
        {
            for (M = a[i][k] / a[k][k], j = k; j<n; j++)
                a[i][j] -= M * a[k][j];
            b[i] -= M * b[k];
        }

    }
    if (a[n - 1][n - 1] == 0)
        if (b[n - 1] == 0)
            return-1;
        else
            return-2;
    else
        {
        for (i = n - 1; i >= 0; i--){
            for (s = 0, j = i + 1; j<n; j++)
                s += a[i][j] * x[j];
            x[i] = (b[i] - s) / a[i][i];
        }
        return 0;
    }

    for (i = 0; i<n; i++)
        free(a[i]);
    free(a);
    free(b);

}

int inverse_Gauss(float **a, int n, float **y){
    int i, j, res;
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
        res = Gauss(a, n, b, x);
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
        return -1;
    else
        return 0;
}

