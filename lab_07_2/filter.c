#include<stdio.h>
#include<stdlib.h>

#include"filter.h"
#include"error_decoder.h"

/*
Функция-фильтр, в массиве остаются элементы от нулевого
до первого отрицательного.
 @param pe_src [in]
 @param pe_src [in]
 @param pb_dst [in]
 @param pe_dst [in]
 @param flag [out]

 @return возвращает flag = 0, если функция корректно выполнила работу, и отрицательное число в обратном случае
*/

int key(int *pb_src, int *pe_src, int **pb_dst, int **pe_dst)
{
    int flag = NO_ERROR;
    if (pe_src - pb_src == 0)
        flag = INPUT_MAS_ERROR;
    else
    {
        int h = pe_src - pb_src;
        pe_src = pb_src;
        int new_size = 0;
        while (*pe_src >= 0 && new_size < h)
        {
            pe_src++;
            new_size++;
        }
        if (new_size == 0)
            flag = NEW_SIZE_ERROR;
        else
        {
            *pe_dst = *pb_dst + new_size;
        }
    }
    return flag;
}
