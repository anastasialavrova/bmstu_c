#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"replace.h"

/*
 Функция вставки символа в строку

 @param str [in]
 @param search [in]
 @param replace [in]
 @param my_str [in]
 @param max_size [in]
 @param curr_size [in]
 @param i [in]
 */

void add_symbol(char *str, char *search, char *replace, char **my_str, int *max_size, int *curr_size, int *i)
{
    int s_size = strlen(search);
    int r_size = strlen(replace);
    int flag = 1;

    for (int j = 0; j < s_size && flag; j++)
    {
        if (*(str + *i + j) != *(search + j))
            flag = 0;
    }

    if (flag == 1)
    {
        if (r_size + 1 > *max_size - *curr_size )
        {
            *my_str = (char*)realloc(*my_str, *max_size + r_size + 1);
            *max_size += r_size;
        }
        memcpy(*my_str + *curr_size, replace, r_size+1);
        *curr_size += r_size;
        *i += s_size - 1;
    }
    else
    {
        if (*max_size - *curr_size < 2)
        {
            *my_str = (char *)realloc(*my_str, *max_size + SIZE);
            *max_size += SIZE;
        }
        (*my_str)[*curr_size] = str[*i];
        (*my_str)[*curr_size+1] = 0;
        (*curr_size)++;
    }
}

/*
 Функция замены подстроки

 @param str [in]
 @param search [in]
 @param replace [in]

 @return возвращает измененную строку
 */

char *str_replace(const char *str, const char *search, const char *replace)
{
    size_t str_size = strlen(str);
    char *new_str = NULL;

    if (!strlen(search))
    {
        new_str = calloc(1, sizeof(char));
    }
    else
    {
        new_str = malloc(SIZE);
        int max_size = SIZE;
        int curr_size = 0;
        for (int i = 0; i < str_size; i++)
            add_symbol(str, search, replace, &new_str, &max_size, &curr_size, &i);
    }

    return new_str;
}
