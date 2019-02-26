#include<stdio.h>
#include<stdlib.h>

#include "mysort_lib.h"
#include "key_lib.h"
#include "read.h"
#include "check.h"

#define FILTER_ERROR -1
#define MYSORT_ERROR -2
#define FILTER_AND_MYSORT_ERROR -3
#define NO_ERROR 0

/*
 Тестовая функция

 @param f_in [in]
 @param f_out [in]
 @param f_out2 [in]
 */

int file_input(FILE* f_in, FILE* f_out, FILE* f_out2)
{
    int flag_f = NO_ERROR, flag_s = NO_ERROR;
    int *pb, *pe, *f_pb, *f_pe, *s_pe, *s_pb;
    int cnt_in = read_cnt(f_in);
    int *mas_in = calloc(cnt_in, sizeof(int));
    int err1 = check_calloc(mas_in);
    pb = pe = f_pb = f_pe = mas_in;
    read(f_in, &pe, cnt_in);
    s_pe = pe;

    int *qb, *qe;
    int cnt_out = read_cnt(f_out);
    int *mas_out = malloc(cnt_out * sizeof(int));
    qe = qb = mas_out;
    read(f_out, &qe, cnt_in);

    key(pb, pe, &f_pb, &f_pe);
    int new_cnt = f_pe - f_pb;

    if (new_cnt == cnt_out)
    {
        for (; f_pb < f_pe; f_pb++)
        {
            if (*f_pb != *qb)
            {
                flag_f = FILTER_ERROR;
            }
            qb++;
        }
    }
    else
        flag_f = FILTER_ERROR;

    int *tb, *te;
    int cnt_out2 = read_cnt(f_out2);
    te = tb = mas_out;
    read(f_out2, &te, cnt_out2);

    s_pb = mas_in;
    mysort(s_pb, cnt_in, sizeof(int), compare);
    s_pe = s_pb + cnt_in;

    int cnt_new2 = s_pe - s_pb;


    for (; s_pb < s_pe; s_pb++)
    {
        if (*s_pb != *tb)
        {
            flag_s = MYSORT_ERROR;
        }
        tb++;
    }

    free(mas_in);
    free(mas_out);

    return flag_f + flag_s;
}

/*
 Вывод результата тестирования на экран

 @param err1 [in]
 @param err2 [in]
 @param err3 [in]
 */

void error_decoder(int err1, int err2, int err3)
{
    if (err1 == FILTER_ERROR)
        printf("Test 1: filter error\n");
    else if (err1 == MYSORT_ERROR)
        printf("Test 1: sort error\n");
    else if (err1 == FILTER_AND_MYSORT_ERROR)
        printf("Test 1: filter and sort error\n");

    if (err2 == FILTER_ERROR)
        printf("Test 2: filter error\n");
    else if (err2 == MYSORT_ERROR)
        printf("Test 2: sort error\n");
    else if (err2 == FILTER_AND_MYSORT_ERROR)
        printf("Test 2: filter and sort error\n");

    if (err3 == FILTER_ERROR)
        printf("Test 3: filter error\n");
    else if (err3 == MYSORT_ERROR)
        printf("Test 3: sort error\n");
    else if (err3 == FILTER_AND_MYSORT_ERROR)
        printf("Test 3: filter and sort error\n");

    if (err1 == NO_ERROR && err2 == NO_ERROR && err3 == NO_ERROR)
        printf("No error\n");
}

/*
 Функция открывает необходимые файлы и перенаправляет в тестирующую функцию
 */

int main()
{
    FILE *f1 = fopen("in1_t.txt", "r");
    FILE *f2 = fopen("out1_t.txt", "r");
    FILE *f3 = fopen("out2_t.txt", "r");
    FILE *f4 = fopen("in2_t.txt", "r");
    FILE *f5 = fopen("out3_t.txt", "r");
    FILE *f6 = fopen("out4_t.txt", "r");
    FILE *f7 = fopen("in3_t.txt", "r");
    FILE *f8 = fopen("out5_t.txt", "r");
    FILE *f9 = fopen("out6_t.txt", "r");


    int err1 = file_input(f1, f2, f3);

    int err2 = file_input(f4, f5, f6);

    int err3 = file_input(f7, f8, f9);

    error_decoder(err1, err2, err3);
	
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    fclose(f6);
    fclose(f7);
    fclose(f8);
    fclose(f9);
}

