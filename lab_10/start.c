#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "struct.h"
#include "add_from_file.h"
#include "pop.h"
#include "copy.h"
#include "sort.h"

/*
 Функция перенаправляет на интересующую функцию

 p_f - pop_front
 p_b - pop_back
 copy - создать копию списка
 sort - отсортировать список
 individ - индивидуальное задание (Дан список дат рождения, необходимо отсортировать,
           вывести в файл самый райнний год рождения)

 @param f_in [in]
 @param f_out [in]
 @param param [in]
 */

void start(FILE *f_in, FILE *f_out, char *param)
{
    node_t *list = NULL;
    list = add_from_file(&list, f_in);
    if (strcmp(param, "p_f") == 0)
    {
        int *x = pop_front(&list);
        fprintf(f_out, "%d", *x);
    }
    else if (strcmp(param, "p_b") == 0)
    {
        int *x = pop_back(&list);
        fprintf(f_out, "%d", *x);
    }
    else if(strcmp(param, "copy") == 0)
    {
        node_t *new_list = NULL;
        new_list = copy(list);
        print_from_head(list, f_out);
        fprintf(f_out, "\n");
        print_from_head(new_list, f_out);
    }
    else if (strcmp(param, "sort") == 0)
    {
        node_t *new_root = NULL;
        new_root = sort(list, comparator_int);
        print_from_head(new_root, f_out);
    }
    else if (strcmp(param, "individ") == 0)
    {
        //Дан список дат рождения, необходимо отсортировать, вывести в файл самый райнний год рождения
        node_t *new_root = NULL;
        new_root = sort(list, comparator_int);
        int *x = pop_front(&new_root);
        fprintf(f_out, "%d", *x);
    }
}
