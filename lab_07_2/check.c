#include<stdio.h>
#include<stdlib.h>

#include"check.h"
#include"error_decoder.h"

/*
Функция проверки количества элементов подаваемой консольной строки

 @param argc[in]

 @return возвращет 0, если нет ошибок, или отрицательное число в обратном случае
*/
int check_string(int argc)
{
    if (argc < 3)
    {
        printerr(ARG_ERROR);
        return ARG_ERROR;
    }
    else
        return NO_ERROR;
}

/*
Функция проверки существования данных в файле

 @param f_input[in]

 @return возвращет 0, если нет ошибок, или отрицательное число в обратном случае
*/

int check_file(FILE *f_input)
{
    if (f_input == NULL)
    {
        printerr(IO_ERROR);
        return IO_ERROR;
    }
    else
        return NO_ERROR;
}

/*
Функция проверяет, выделилась ли память под массив

 @param f_input[in]

 @return возвращет 0, если нет ошибок, или отрицательное число в обратном случае
*/

int check_calloc(int *a)
{
    if (a == NULL)
    {
        printerr(MALLOC_ERROR);
        return MALLOC_ERROR;
    }
    else
        return NO_ERROR;
}
