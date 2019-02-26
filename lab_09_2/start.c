#include<stdio.h>
#include<stdlib.h>

#include"start.h"
#include"read.h"
#include"replace.h"

void start(FILE *f_in, FILE *f_out, const char *search, const char *replace)
{
    int size = 0;
    char *str = NULL;
    char *new_str = NULL;

    while (my_getline(&str, &size, f_in))
    {
        new_str = str_replace(str, search, replace);
        fprintf(f_out, "%s", new_str);
    }

    free(str);
    free(new_str);
}

