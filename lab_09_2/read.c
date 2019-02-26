#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include"read.h"

/*
 Функция считывания строки из файла

 @param lineptr [in]
 @param stream [in]

 @return функция возвращает указатель на последний символ считанной строки
 */

int my_getline(char **lineptr, int *n, FILE *stream)
{
    char buf[BUF_SIZE];
    size_t buf_size = 0;
    *lineptr = NULL;
    *n = NULL;

    *lineptr = (char *)realloc(*lineptr, *n + buf_size + 1);
    while(fgets(buf, BUF_SIZE, stream) && ((*lineptr)[(*n) - 1] != '\n'))
    {
        buf_size = strlen(buf);
        *lineptr = (char*)realloc(*lineptr, *n + buf_size + 1);
        memcpy(*lineptr + *n, buf, buf_size);
        *n += buf_size;
        (*lineptr)[(*n)] = 0;
    }

    return *n;
}

