#ifndef LAB_08_MATRIX_H
#define LAB_08_MATRIX_H

#include<stdio.h>

float** new_matrix(int row, int columns);
void read_mtrx(FILE *f, float **mtrx, int row, int column);
float max_elem(float *x, float max, int *r, int k, int n);
void swap_float (float *a, float *b);
void copy_matrix(int n, float **a, float **matrica_a);
void copy_mass(int n, float *b, float *massiv_b);

#endif //LAB_08_MATRIX_H
