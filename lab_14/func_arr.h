#ifndef LAB_14_22_FUNC_ARR_H
#define LAB_14_22_FUNC_ARR_H

#include <stdbool.h>

#define SIZE_BUF 10

typedef int item_t;
typedef struct set_type *set_t;

int set_create(set_t *a);
void set_destroy(set_t s);
void set_clear(set_t s);
bool set_is_empty(set_t s);
void set_print_int(set_t s, char *message);
int set_len(set_t a);
bool set_compare(set_t a, set_t b);
int set_union(set_t a, set_t b, set_t res);
int set_intersection(set_t a, set_t b, set_t res);
int set_difference(set_t a, set_t b, set_t res);
int set_symmetric_difference(set_t a, set_t b, set_t res);
int set_copy(set_t a, set_t res);
int array_extension(set_t s);
int set_push(set_t s, item_t elem);
int set_pop(set_t s, item_t elem);
int set_input(FILE *f, set_t s);

#endif //LAB_14_22_FUNC_ARR_H
