#include<stdio.h>
#include"matrix.h"

float** new_matrix(int row, int column)
{
    float **data = calloc((size_t) (row + row * column), sizeof(float*));
    if (!data)
        return NULL;

    for (int i = 0; i < row; i++)
        data[i] = (float*)((char*) data + row * sizeof(float*) + i * column * sizeof(float));
    return data;
}

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



