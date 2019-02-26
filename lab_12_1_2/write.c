#include<stdio.h>
#include<stdlib.h>
#include"write.h"

/*
Функция записи элементов в файл

 @param f_output [in]
 @param pe [in]
*/

void write(FILE *f_output, int *pb, int *pe)
{
    for (; pb < pe; pb++)
    {
        fprintf(f_output, "%d ", *pb);
    }
}
