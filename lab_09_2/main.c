#include<stdio.h>
#include<stdlib.h>

#include"check.h"
#include"start.h"


/*
 Функция проверяет ошибочные ситуации и передает управление
 функции-процессу

 @param f_input [in]
 @param f_outpur[out]
 @param argc [in]
 @param argv [in]

 @return возвращает 0, если программа выполнилась корректно,или отрицательное число в обратном случае
*/


int main(int argc, char *argv[])
{
    FILE *f_input, *f_output;
    int err1, err2, err;
    err1 = check_string(argc);
    f_input = fopen(argv[1], "r");
    f_output = fopen(argv[2], "w");
    err2 = check_file(f_input);
    err = err1 + err2;

    if (!err)
    {
        start(f_input, f_output, argv[3], argv[4]);
    }

    fclose(f_input);
    fclose(f_output);

    return err;
}
