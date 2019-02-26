#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <inttypes.h>

#include "mysort_lib.h"
#include "key_lib.h"
#include "read.h"
#include "write.h"
#include "check.h"

/*
 Функция проверяет ошибочные ситуации и передает управление
 функции-фильтру и функции-сортировщику

 @param f_input [in]
 @param f_outpur[out]
 @param argc [in]
 @param argv [in]

 @return возвращает 0, если программа выполнилась корректно,или отрицательное число в обратном случае
*/


int main(int argc, char *argv[])
{
    FILE *f_input, *f_output;
    int err1, err2, err3, err;
    err1 = check_string(argc);
    f_input = fopen(argv[1], "r");
    f_output = fopen(argv[2], "w");
    err2 = check_file(f_input);
    err = err1 + err2;

    if (!err)
    {
        int cnt = 0;
        cnt = read_cnt(f_input);
        int *a, *pb, *pe, *f_pb, *f_pe;
        a = (int*)calloc(cnt, sizeof(int));
        err3 = check_calloc(a);
        if (!err3)
        {
            pb = pe = f_pb = f_pe = a;

            read(f_input, &pe, cnt);

            if (strcmp(argv[argc - 1], "f") == 0)
            {
                key(pb, pe, &f_pb, &f_pe);
                pe = f_pe;
                pb = f_pb;
            }

            int h = pe - pb;
            mysort(pb, h, sizeof(*a), compare_int);
            write(f_output, pb, pe);
        }

        free(a);
        fclose(f_input);
        fclose(f_output);
    }

    err += err3;
    return err;
}


