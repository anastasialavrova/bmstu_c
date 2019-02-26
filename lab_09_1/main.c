#include<stdio.h>
#include<string.h>

#include "test.h"

/*
 Функция отправляет тестовые данные
 */

int main()
{
    test("abcdefg", 'a');
    test("hhh", 'm');
    test("9lk69", 'l');
    test("", 'f');

    return 0;
}

