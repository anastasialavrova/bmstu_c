#include <stdio.h>
#include <stdlib.h>

#include "test.h"

/*
 Начало программы, перенаправляет на функции-тесты

 @return возвращает 0 в случае успешного завершения программы
 */

int main()
{
    test_snprintf_dec();
    test_snprintf_hex();
    test_snprintf_percent();
    test_snprintf_no_args();
    test_snprintf_empty();
    test_snprintf_small();
    test_snprintf_more_args();

    return 0;
}