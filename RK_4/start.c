#include<stdio.h>
#include<stdlib.h>

#include"struct.h"
#include"push.h"
#include"pop.h"
#include"print.h"

void start()
{
    node_t *list = NULL;
    node_m *list_mrk = NULL;
    int choice = 0;
    while(1)
    {
        printf("\n1) Add new element\n2) Delete element from end\n3) Print elements\n0) Exit\n");
        printf("Input parameter: ");
        scanf("%d", &choice);
        if (choice == 1)
            add(&list);
        else if (choice == 2)
            pop(&list);
        else if (choice == 3)
            print(list);
        else if (choice == 0)
            break;
        else
        {
            printf("Invalid parameter!\n");
        }
    }
}
