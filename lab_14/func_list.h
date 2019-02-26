#ifndef LAB_14_2_FUNC_LIST_H
#define LAB_14_2_FUNC_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef int item_t;
typedef struct set_type *set_t;

typedef struct node_type *node_t;

int set_create(set_t *s);
void set_destroy(set_t s);
void set_clear(set_t s);

void set_print_int(set_t head, char *message);
int set_len(set_t a);
bool set_compare(set_t a, set_t b);
bool set_is_empty(set_t s);

int set_push(set_t s, item_t elem);
int set_pop(set_t s, item_t elem);

int set_union(set_t a, set_t b, set_t res);
int set_intersection(set_t a, set_t b, set_t res);
int set_difference(set_t a, set_t b, set_t res);
int set_symmetric_difference(set_t a, set_t b, set_t res);
int set_copy(set_t a, set_t res);
int set_input(FILE *f, set_t s);
#endif
