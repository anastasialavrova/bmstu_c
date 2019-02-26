#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "pop.h"

/*
 Функция возвращает элемент из конца списка

 @param list [in]

 @return data возвращает элемент из конца списка
 */

void* pop_back(node_t **list)
{
    node_t *temp = *list;
    void *data = temp->data;
    *list = temp->next;
    free(temp);
    return data;
}

/*
 Функция возвращает элемент из начала списка

 @param list [in]

 @return data возвращает элемент из начала списка
 */

void* pop_front(node_t **list)
{
    node_t *current = *list;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    void *data = current->next->data;
    current->next = NULL;
    return data;
}

