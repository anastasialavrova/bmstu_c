#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "test.h"
#include "func.h"
#include "my_snprintf.h"

/*
 Тестовая функция для десятичных чисел
 */

void test_snprintf_dec()
{
    char msg[] = "Decimal numbers:";
    printf("%-30s", msg);

    char format[] = "%d %i %d %ld %li %ld";

    size_t n = SIZE;
    char *res1 = malloc(SIZE *sizeof(char));
    char *res2 = malloc(SIZE *sizeof(char));
    int returned1 = my_snprintf(res1, n, format, ARGS_DEC);
    int returned2 = snprintf(res2, n, format, ARGS_DEC);

    print_results(returned1, returned2, res1, res2);
    free_res(res1, res2);
}

/*
 Тестовая функция для шестнадцатиричных чисел
 */

void test_snprintf_hex()
{
    char msg[] = "Hexadecimal numbers:";
    printf("%-30s", msg);

    char format[] = "%x %lx %lx %lx %x %lx";

    size_t n = SIZE;
    char *res1 = malloc(SIZE *sizeof(char));
    char *res2 = malloc(SIZE *sizeof(char));
    int returned1 = my_snprintf(res1, n, format, ARGS_HEX);
    int returned2 = snprintf(res2, n, format, ARGS_HEX);

    print_results(returned1, returned2, res1, res2);
    free_res(res1, res2);
}

/*
 Тестовая функция для спецификатором с двумя знаками '%'
 */

void test_snprintf_percent()
{
    char msg[] = "Specifier with %%:";
    printf("%-30s", msg);
    char format[] = "%%";

    size_t n = SIZE;
    char *res1 = malloc(SIZE *sizeof(char));
    char *res2 = malloc(SIZE *sizeof(char));
    int returned1 = my_snprintf(res1, n, format);
    int returned2 = snprintf(res2, n, format);

    print_results(returned1, returned2, res1, res2);
    free_res(res1, res2);
}

/*
 Тестовая функция для случая с отсутсвием спецификаторов
 */

void test_snprintf_no_args()
{
    char msg[] = "No arguments:";
    printf("%-30s", msg);

    char format[] = "i love bmstu";

    size_t n = SIZE;
    char *res1 = malloc(SIZE *sizeof(char));
    char *res2 = malloc(SIZE *sizeof(char));
    int returned1 = my_snprintf(res1, n, format);
    int returned2 = snprintf(res2, n, format);

    print_results(returned1, returned2, res1, res2);
    free_res(res1, res2);
}

/*
 Тестовая функция для случая пустой строки спецификатора
 */

void test_snprintf_empty()
{
    char msg[] = "Empty format:";
    printf("%-30s", msg);

    char format[] = "";

    size_t n = SIZE;
    char *res1 = malloc(SIZE *sizeof(char));
    char *res2 = malloc(SIZE *sizeof(char));
    int returned1 = my_snprintf(res1, n, format);
    int returned2 = snprintf(res2, n, format);

    print_results(returned1, returned2, res1, res2);
    free_res(res1, res2);
}

/*
 Тестовая функция для проверки случая, когда буфер меньше, чем строка
 */

void test_snprintf_small()
{
    char msg[] = "Short string:";
    printf("%-30s", msg);

    char format[] = "98765555555555";

    size_t n = 3;
    char *res1 = malloc(SIZE *sizeof(char));
    char *res2 = malloc(SIZE *sizeof(char));
    int returned1 = my_snprintf(res1, n, format);
    int returned2 = snprintf(res2, n, format);

    print_results(returned1, returned2, res1, res2);
    free_res(res1, res2);
}

/*
 Тестовая функция для проверки, когда спецификаторов меньше, чем аргументов
 */

void test_snprintf_more_args()
{
    char msg[] = "More than specifiers:";
    printf("%-30s", msg);

    char format[] = "Programm %d, %d";

    size_t n = SIZE;
    char *res1 = malloc(SIZE *sizeof(char));
    char *res2 = malloc(SIZE *sizeof(char));
    int returned1 = my_snprintf(res1, n, format, ARGS_MORE_ARGS);
    int returned2 = snprintf(res2, n, format, ARGS_MORE_ARGS);

    print_results(returned1, returned2, res1, res2);
    free_res(res1, res2);
}

/*
 Функция вывода результатов тестов на экран

 @param num1 [in]
 @param num2 [in]
 @param res1 [in]
 @param res2 [in]
 */

void print_results(int num1, int num2, char *res1, char *res2)
{
    if (!strcmp(res1, res2) && num1 == num2)
        printf("OK\n");
    else
        printf("NO %d|%d: %s|%s\n", num1, num2, res1, res2);
}

/*
 Функция освобождения памяти

 @param res1 [in]
 @param res2 [in]
 */

void free_res(char *res1, char *res2)
{
    if (res1)
        free(res1);
    if (res2)
        free(res2);
}

