#include <stdio.h>
#include"check.h"
#include"addition.h"
#include"matrix.h"

/*
 Функция подготавливает данные для дальнейшей отправки в "функцию-калькулятор" сложения
 и отправляет данные в функцию для вывода информации в текстовый файл

 @param mtr_1 [in]
 @param mtr_2 [in]
 @param res [in]

 */

void addition(char *mtr_1, char *mtr_2, char *res)
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
        if (row1 == row2 && column1 == column2)
        {
            float **result = new_matrix(row1, column1);
            addition_mtrx(mtrx1, mtrx2, result, row1, column1);
            for (int i = 0; i < row1; i++)
            {
                for (int j = 0; j < column1; j++)
                {
                    fprintf(f3, "%f ", result[i][j]);
                }
                fprintf(f3, "\n");
            }
        }
        else
            fprintf(f3, "Error!");
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

/*
 Функция складывает две матрицы

 @param mtrx1 [in]
 @param mtrx2 [in]
 @param result [in]
 @param row [in]
 @param column [in]
 */

void addition_mtrx(float **mtrx1, float **mtrx2, float **result,  int row, int column)
{
    float **r = new_matrix(row,column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            int x = mtrx1[i][j] + mtrx2[i][j];
            r[i][j] = x;
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            result[i][j] = r[i][j];
        }
    }
}
