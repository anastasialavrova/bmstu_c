#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "prime_numbers.h"

/*
 Функция заполняет массив простыми числами

 @param a [in]
 @param x [in]
 */

void prime_arr(int *a, int x)
{
    int num = 2;
    for (int i = 0; i < x; i++)
    {
        a[i] = num;
        num = prime_num(num);
    }
}

/*
 Функция подбирает следующее просточе число

 @param num [in]
 @param i [out]

 @return возвращает простое число
 */

int prime_num(int num)
{
    char flag = 0;
    int i = num;
    while(!flag)
    {
        i++;
        if(is_prime(i))
            flag = 1;
    }
    return i;
}

/*
 Функция выясняет, является ли число простым

 @param num [in]
 @param flag [out]

 @return возвращает 1, если число является простым, и 0 в ином случае
 */

int is_prime(int num)
{
    int flag = 1;
    int i = 2;
    double limit = powf(num, 0.5);
    for(; num != 2 && i <= limit; i++)
    {
        if(num % i == 0)
            flag = 0;
    }
    return flag;
}

/*
 Функция подсчитывает количество чётных чисел

 @param a [in]
 @param x [in]
 @param cnt [out]

 @return возвращает количество четных чисел
 */

int count_even(int *a, int x)
{
    int cnt = 0;
    for (int i = 0; i < x; i++)
    {
        if (a[i] % 2 == 0)
        {
            cnt++;
        }
    }
    return cnt;
}

/**
 Функция создает копию массива и вставляет после четных элементов необходимое значение
 @param a [in]
 @param x [in]
 @param new_a [in]
 @param new_x [in]
 @param z [in]
 */

void copy_arr(int *a, int x, int *new_a, int *new_x, int z)
{
    int i = 0;
    int flag = 0;

    *new_x = x + count_even(a, x);

    for(int j = 0; j < *new_x && i < x + 1; j++)
    {
        if(!flag && j > 0 && a[i - 1] % 2 == 0)
        {
            flag = 1;
            new_a[j] = z;
        }
        else
        {
            new_a[j] = a[i];
            i++;
            flag = 0;
        }
    }
}
