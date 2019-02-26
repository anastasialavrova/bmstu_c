#include <stdio.h>
#include "add_test.h"

/*
 Функция выводит на экран результат тестов
 */

int main()
{
    if(add_test())
        printf("OK");
    else
        printf("NOT OK");
}
