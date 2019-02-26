#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"check.h"
#include"start.h"
#include"struct.h"
#include"add_from_file.h"
#include"pop.h"
#include"copy.h"
#include "sort.h"

int test_pop_front()
{
    FILE *f1 = fopen("in1_t.txt", "r");
    FILE *f2 = fopen("out1_t.txt", "r");
    int ans, result;
    node_t *list = NULL;
    list = add_from_file(&list, f1);
    fscanf(f2, "%d", &ans);

    int *x = pop_front(&list);
    if (*x == ans)
        result = 0;
    else
        result = -1;

    return result;
}

int test_pop_back()
{
    FILE *f1 = fopen("in2_t.txt", "r");
    FILE *f2 = fopen("out2_t.txt", "r");
    int ans, result;
    node_t *list = NULL;
    list = add_from_file(&list, f1);
    fscanf(f2, "%d", &ans);

    int *x = pop_back(&list);

    if (*x == ans)
        result = 0;
    else
        result = -2;

    return result;
}

int equal(node_t *result, node_t *output)
{
    int err = 0;
    for (node_t *cur1 = result, *cur2 = output; cur1 && cur2 && !err;
         cur1 = cur1->next, cur2 = cur2->next)
    {
        if (strcmp(cur1->data,cur2->data))
        {
            err = -3;
        }
    }

    return err;
}

void print_from_hd(const node_t *list)
{
    if (list)
    {
        print_from_hd(list->next);
        int *x = list->data;
        printf("%d ", *x);
    }
}

int test_copy()
{
    FILE *f1 = fopen("in3_t.txt", "r");
    int result;
    node_t *list = NULL;
    list = add_from_file(&list, f1);

    node_t *new_list = NULL;
    new_list = copy(list);
    result = equal(list, new_list);
    return result;
}

int test_sort()
{
    FILE *f1 = fopen("in4_t.txt", "r");
    FILE *f2 = fopen("out4_t.txt", "r");
    node_t *list = NULL;
    list = add_from_file(&list, f1);
    node_t *list2 = NULL;
    list2 = add_from_file(&list2, f2);

    node_t *new_root = NULL;
    new_root = sort(list, comparator_int);

    int result = equal(new_root, list2);
    return result;
}

void error_decoder(int err1, int err2, int err3, int err4)
{
    if (!err1 && !err2 && !err3 && !err4)
        printf("All tests passed");
    else if (err1)
        printf("Function pop_front is incorrect");
    else if (err2)
        printf("Function pop_back is incorrect");
    else if (err3)
        printf("Function copy is incorrect");
    else if (err4)
        printf("Function sort is incorrect");
}

int main()
{
    int err1 = test_pop_front();
    int err2 = test_pop_back();
    int err3 = test_copy();
    int err4 = test_sort();

    error_decoder(err1, err2, err3, err4);

    return 0;
}



