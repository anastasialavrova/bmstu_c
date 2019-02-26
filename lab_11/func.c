#include <string.h>
#include <stdarg.h>

#include "func.h"

/*
 Функция перемещения указателя

 @param ptr [in]
 @param ptr_len [in]
 @param step [in]
 */

void move_ptr(char **ptr, int *ptr_len, int step)
{
    *ptr += step;
    *ptr_len += step;
}

/*
 Функция обработки спецификаторов типа int

 @param format [in]
 @param s [in]
 @param s_len [in]
 @param num [in]

 @return возвращает 0 при успешной обработке и -1 в обратном случае
 */

int numbers(const char **format, char **s, int *s_len, int num)
{
    int flag_err = 0;
    switch(**format)
    {
        case 'd':
            add_num(s, s_len, num, 10);
            break;
        case 'x':
            add_num(s, s_len, num, 16);
            break;
        case 'i':
            add_num(s, s_len, num, 10);
            break;
        default:
            flag_err = -1;
            break;
    }

    return flag_err;
}

/*
 Функция обрабатыват отрицательные числа, вставляет знак 'минус' в строку
 и превращает число в положительное (если число отрицательное)

 @param s [in]
 @param s_len [in]
 @param num [in]
 */

void negative(char **s, int *s_len, int *num)
{
    if (*num < 0)
    {
        *num *= -1;
        **s = '-';
        move_ptr(s, s_len, 1);
    }
}

/*
 Функция подсчета количества знаков в выбранной системе счисления

 @param num [in]
 @param base [in]

 @return возвращает количество знаков
 */

int count_len(int num, int base)
{
    int counter = 0;
    do
    {
        num /= base;
        counter++;
    }
    while (num);

    return counter;
}

/*
 Функция добавления в строку числа

 @param s [in]
 @param s_len [in]
 @param num [in]
 @param alphabet [in]
 */

void add_num(char **s, int *s_len, int num, int base)
{
    char alph[] = "0123456789abcdef";
    char *cur;
    //int base = (int)strlen(alphabet);
    int num_len = 0;

    negative(s, s_len, &num);
    cur = *s;
    num_len = count_len(num, base);
    cur += num_len;

    do
    {
        cur -= 1;
        *cur = alph[num % base];
        num /= base;
    }
    while (num);

    move_ptr(s, s_len, num_len);
}
