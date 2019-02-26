
#ifndef RK1_STRUCT_H
#define RK1_STRUCT_H

typedef struct mark
{
    int mrk;
    struct mark *next;
}node_m;

typedef struct student
{
    char name[300];
    int age;
    node_m *list_m;
    struct student *next;
}node_t;

void add(node_t **list);

#endif //RK1_STRUCT_H
