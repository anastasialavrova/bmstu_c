#include<stdio.h>
#include<stdlib.h>

#include"check.h"

/*
Функция проверки количества элементов подаваемой консольной строки

 @param argc[in]

 @return возвращет 0, если нет ошибок, или отрицательное число в обратном случае
*/
int check_string(int argc)
{
    if (argc < 3)
    {
        printf("Incorrect input parameters!");
        return -1;
    }
    else
        return 0;
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
        printf("File error!");
        return -2;
    }
    else
        return 0;
}


