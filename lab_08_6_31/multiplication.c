#include <stdio.h>
#include"check.h"
#include"matrix.h"
#include"multiplication.h"
#include"print.h"

/*
 Функция подготавливает данные для дальнейшей отправки в "функцию-калькулятор" умножения
 и отправляет данные в функцию для вывода информации в текстовый файл

 @param mtr_1 [in]
 @param mtr_2 [in]
 @param res [in]

 */

void multiplicaion(char *mtr_1, char *mtr_2, char *res)
{
    FILE *f1 = fopen(mtr_1, "r");
    FILE *f2 = fopen(mtr_2, "r+");
    FILE *f3 = fopen(res, "w+");
    int error = check_file(f1) + check_file(f2);
    if (!error)
    {
        int row1, row2, column1, column2, result;
        fscanf(f1, "%d", &row1);
        fscanf(f1, "%d", &column1);
        fscanf(f2, "%d", &row2);
        fscanf(f2, "%d", &column2);
        float **mtrx1 = new_matrix(row1, column1);
        float **mtrx2 = new_matrix(row2, column2);
        read_mtrx(f1, mtrx1, row1, column1);
        read_mtrx(f2, mtrx2, row2, column2);
        if (column1 == row2)
        {
            float **result = new_matrix(row1, column1);
            mult_mtrx(mtrx1, mtrx2, result, row1, column1, column2);
            print_matrix(f3, result, row1, column2);
        }
        else
            printf("Error!");
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

/*
 Функция умножает две матрицы

 @param mtrx1 [in]
 @param mtr2 [in]
 @param result [in]
 @param row1 [in]
 @param column1 [in]
 @param column2 [in]
 */

void mult_mtrx(float **mtrx1, float **mtrx2, float **result,  int row1, int column1, int column2)
{
    for (int i=0; i<row1; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            for (int x = 0; x < column1; x++)
            {
                result[i][j] += mtrx1[i][x] * mtrx2[x][j];
            }
        }
    }
}

