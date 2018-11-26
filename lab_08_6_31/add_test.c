#include<stdio.h>
#include<stdlib.h>

#include"add_test.h"
#include"matrix.h"
#include"addition.h"

int add_test()
{
    char mtr1[] = "mtr_1_test.txt";
    char mtr2[] = "mtr_2_test.txt";
    char mtr3[] = "mtr_3_test.txt";
    char mtr4[] = "mtr_4_test.txt";
    char mtr5[] = "mtr_5_test.txt";
    char mtr6[] = "mtr_6_test.txt";
    char mtr7[] = "mtr_7_test.txt";
    char mtr8[] = "mtr_8_test.txt";
    char mtr9[] = "mtr_9_test.txt";

    int f1 = pre_add_test(mtr1, mtr2, mtr3);
    return f1;
    //pre_add_test(mtr4, mtr5, mtr6);
    //pre_add_test(mtr7, mtr8, mtr9);
}

int pre_add_test(char *mtr1, char *mtr2, char *res)
{
    FILE *f1 = fopen(mtr1, "r");
    FILE *f2 = fopen(mtr2, "r");
    FILE *f3 = fopen(res, "w");
    int row1, row2, column1, column2, flag = 1;
    float x;
    fscanf(f1, "%d", &row1);
    fscanf(f1, "%d", &column1);
    fscanf(f2, "%d", &row2);
    fscanf(f2, "%d", &column2);

    printf("%d", row1);

    float **mtrx1 = new_matrix(row1, column1);
    float **mtrx2 = new_matrix(row2, column2);
    float **result = new_matrix(row1, column1);

    read_mtrx(f1, mtrx1, row1, column1);
    read_mtrx(f2, mtrx2, row2, column2);


    addition_mtrx(mtrx1, mtrx2, result, row1, column1);


    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column1; j++)
        {
            fscanf(f3, "%f", &x);
            printf("%f %f", x, result[i][j]);
            if (x != result[i][j])
            {
                printf("Mistake of addition!");
                flag = 0;
            }
        }
    }
    return flag;
}

