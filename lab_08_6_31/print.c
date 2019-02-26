#include<stdio.h>

/*
 Функция вывода матрицы в файл

 @param f [in]
 @param mtrx [in]
 @param row [in]
 @param column [in]
 */

void print_matrix(FILE *f, float **mtrx, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            fprintf(f, "%f ", mtrx[i][j]);
        }
        fprintf(f, "\n");
    }
}

