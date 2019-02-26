#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "copy.h"
#include "sort.h"
#include "add_from_file.h"

 /*
 Сортирует список по возрастанию

 @param head [in]
 @param comparator [in]
 @param newroot [out]

 @return newroot упорядоченный список
 */

node_t* sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *new_root = NULL;
    if (head != NULL)
    {
        void *first = pop_back(&head);
        int flag = 0;
        push(&new_root, first);
        if (head->next == NULL)
        {
            flag = 1;
        }
        while (head->next)
        {
            node_t *next = head;
            sort_insert(&new_root, next, comparator);
            head = head->next;
        }
        if (flag != 1)
        {
            node_t *next = head;
            sort_insert(&new_root, next, comparator);
        }
    }
    return new_root;
}

 /*
 Функция сравнения int

 @param p [in]
 @param q [in]
 @return возвращает разницу между значениями
 */

int comparator_int(const void *p, const void *q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b;
}

/*
Получает список, и элемент, который нужно вставить в этот список

@param head [in]
@param element [in]
@param comparator [in]
*/

void sort_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    node_t *ptr = NULL;
    node_t *tmp = NULL;
    unsigned char flag = 0;
    void *x = element->data;
    if (comparator(element->data, (*head)->data) >= 0)
    {
        ptr = malloc(sizeof(node_t));
        ptr->data = x;
        ptr->next = (*head);
        *head = ptr;
    }
    else
    {
        tmp = (*head);
        while ((flag == 0) && (tmp->next != NULL))
        {
            if (comparator(tmp->data, tmp->next->data) >= 0 &&
                comparator(element->data, tmp->next->data) > 0)
                flag = 1;
            if (flag != 1)
                tmp = tmp->next;
        }
        if (flag == 0)
        {
            ptr = malloc(sizeof(node_t));
            ptr->data = x;
            ptr->next = NULL;
            tmp->next = ptr;
        }
        else
        {
            ptr = malloc(sizeof(node_t));
            ptr->data = x;
            ptr->next = tmp->next;
            tmp->next = ptr;
        }
    }
}

