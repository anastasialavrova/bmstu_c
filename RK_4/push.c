#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "struct.h"

void push_t(node_t **list, node_t *node)
{
    node->next = *list;
    *list = node;
}


void push_m(node_m **list, int elem)
{
    node_m* node = malloc(sizeof(node_m));
    node->mrk = elem;
    node->next = *list;
    *list = node;
}
