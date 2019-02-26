#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "struct.h"
#include"push.h"


void add(node_t **list)
{
    node_m *list_m = NULL;
    node_t *node = malloc(sizeof(node_t));
    char name[100];
    int age, num, x;
    int *mrk = (int*)malloc(num * sizeof(int));
    printf("\nInput name: ");
    scanf("%s", name);
    strcpy(node->name, name);

    printf("Input age: ");
    scanf("%d", &age);
    node->age = age;

    printf("Input number of marks: ");
    scanf("%d", &num);

    printf("Input marks: ");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &x);
        push_m(&list_m, x);
    }
    node->list_m = list_m;
    push_t(list, node);
}

