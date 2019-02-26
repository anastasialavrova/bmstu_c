#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "struct.h"

void pop(node_t **list)
{
    if (list)
    {
        node_t *temp = *list;
        void *name = temp->name;
        void *age = temp->age;
        *list = temp->next;
        free(temp);
    }
}


