
#ifndef LAB_10_ADD_FROM_FILE_H
#define LAB_10_ADD_FROM_FILE_H

#include <stdio.h>
#include "struct.h"

node_t* add_from_file(node_t **list, FILE *f);
void push(node_t** list, void *elem);
void print_from_head(const node_t *list, FILE *f);

#endif //LAB_10_ADD_FROM_FILE_H
