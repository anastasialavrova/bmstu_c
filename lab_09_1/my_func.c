#include<stdio.h>
#include<string.h>

/*
 Функция Функция ищет последнее вхождение символа в строку

 @param str [in]
 @param ch [in]

 @return возвращает индекс символа последнего вхождения (если символа нет, возвращает NULL)
 */

char *my_strrchr(const char *str, int ch)
{
    char *last_found = 0;
    while (*str)
    {
        if (*str == ch)
            last_found = (char *)str;

        str++;
    }
    return last_found ? last_found : NULL;
}
