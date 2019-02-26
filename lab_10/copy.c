#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "copy.h"

/*
 Функция копирует список

 @param head [in]

 @return newList вовзращает копию списка
 */

node_t* copy(node_t* head)
{
    node_t* current = head;
    if (head == NULL)
        return NULL;
    else
    {
        node_t* newList = malloc(sizeof(node_t));
        newList->data = current->data;
        newList->next = copy(current->next);
        return(newList);
    }
}
