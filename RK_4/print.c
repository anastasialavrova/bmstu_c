#include <stdio.h>

#include"struct.h"
#include "print.h"

void print(node_t *list)
{
    if (list)
    {
        print(list->next);
        printf("%s %d\n", list->name, list->age);
        printf("Marks: ");
        print_mark(list->list_m);
        printf("\n");
    }
    else
    {
        puts("\nEmpty structure!\n");
    }
}

void print_mark(node_m *list)
{
    if (list)
    {
        print_mark(list->next);
        printf("%d ", list->mrk);
    }
}

