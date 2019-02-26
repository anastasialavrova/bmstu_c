#include<stdio.h>
#include<stdlib.h>

#include "struct.h"
#include "add_from_file.h"

/*
 Считывает данные из файла

 @param list [in]
 @param f [in]

 @return сформированный список
 */

node_t* add_from_file(node_t **list, FILE *f)
{
    rewind(f);
    int *x;
    while (!feof(f))
    {
        x = malloc(sizeof(int));
        fscanf(f, "%d", x);
        push(list, (void *) x);
    }
    return *list;
}

/*
 Функция добавляет элемент в список

 @param list [in]
 @param elem [in]
 */

void push(node_t** list, void *elem)
{
    node_t* node = malloc(sizeof(node_t));
    node->data = elem;
    node->next = *list;
    *list = node;
}

/*
 Функция вывод элементов с начала

 @param list [in]
 @param f [in]
 */

void print_from_head(const node_t *list, FILE *f)
{
    if (list)
    {
        print_from_head(list->next, f);
        int *x = list->data;
        fprintf(f, "%d ", *x);
    }
}





