#include<stdio.h>
#include<string.h>

#include "my_func.h"

/*
 Функция отправляет данные в две функции (написанную вручную и встроенную) и сравнивает результаты тестирования

 @param str [in]
 @param ch [in]
 */

void test(char str[], int ch)
{
    char *org_res = strrchr(str, ch);
    char *my_res = my_strrchr(str, ch);

    if (org_res == my_res)
        printf("Test: OK\n");
    else
        printf("Test: NO\n");
}

