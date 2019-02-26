#include "func_list.h"

struct set_type
{
    struct node_type *head;
};

struct node_type
{
    item_t number;
    struct node_type *next;
};

/*
 Функция создает множество

 @param a[in]
 @param error [out]

 @return возвращает 0 в случае успешного создания множества (или -1 в ином)
 */
int set_create(set_t *a)
{
    int error = 0;
    set_t new_set = malloc(sizeof(struct set_type));
    if (new_set)
    {
        new_set->head = NULL;
        *a = new_set;
    }
    else
        error = -1;
    return error;
}

/*
 Функция удаляет множество

 @param s [in]
 */

void set_destroy(set_t s)
{
    node_t node = s->head;
    while(node)
    {
        node_t cur = node->next;
        free(node);
        node = cur;
    }
    free(s);
}

/*
 Функция очищения памяти

 @param s [in]
 */

void set_clear(set_t s)
{
    node_t node = s->head;
    while(node)
    {
        node_t cur = node->next;
        free(node);
        node = cur;
    }
}

/*
 Функция проверяет, является ли множество пустым

 @param s [in]

 @return возвращает true, если множетсов пустое (и false в обратном случае)
 */

bool set_is_empty(set_t s)
{
    bool result;
    if (!s->head)
        result = true;
    else
        result = false;
    return result;
}

/*
 Функция вывода множества на экран

 @param s [in]
 @param message [in]
 */

void set_print_int(set_t s, char *message)
{
    printf("%s", message);
    if (!s->head)
        printf("Empty\n");
    else
    {
        node_t node = s->head;
        for ( ; node; node = node->next)
            printf("%d ", node->number);

        printf("\n");
    }
}

/*
 Функция нахождения длины множества

 @param a [in]
 @param len [out]

 @return длину множества
 */

int set_len(set_t a)
{
    int len = 0;
    node_t node = a->head;
    for ( ; node; node = node->next)
        len++;
    return len;
}

/*
 Функция сравнения двух множеств

 @param a [in]
 @param b [out]
 @param comp [out]

 @return возвращает true, если множества совпали (и false в ином случае)
 */

bool set_compare(set_t a, set_t b)
{
    bool comp = true;
    if (set_len(a) == set_len(b))
    {
        node_t node_a = a->head;
        node_t node_b = b->head;
        for ( ; node_a && node_b; node_a = node_a->next, node_b = node_b->next)
        {
            if (node_a->number != node_b->number)
            {
                comp = false;
            }
        }
    }
    else
        comp = false;
    return comp;
}

/*
 Функция объединения множеств

 @param s [in]
 @param b [in]
 @param res [in]
 @param error [out]

 @return возвращает 0 в случае успешного объединения (и -1 в ином случае)
 */

int set_union(set_t a, set_t b, set_t res)
{
    int error = 0;
    error = set_copy(a, res);
    if (!error)
    {
        node_t node_res = res->head;
        node_t node_b = b->head;
        for ( ; !error && node_b; node_b = node_b->next)
        {
            int search = false;
            for (node_t cur = node_res; cur; cur = cur->next)
            {
                if (cur->number == node_b->number)
                    search = true;
            }

            if (!search)
                error = set_push(res, node_b->number);

        }
    }
    else
        error = -1;

    return error;
}

/*
 Функция пересечения множеств

 @param a [in]
 @param b [in]
 @param res [in]
 @param error [out]

 @return возвращает 0 в случае успешного пересечения (и -1 в ином случае)
 */

int set_intersection(set_t a, set_t b, set_t res)
{
    int error = 0;
    node_t node_a = a->head;
    node_t node_b = b->head;
    for ( ; !error && node_a; node_a = node_a->next)
    {
        for (node_t cur_b = node_b; !error && cur_b; cur_b = cur_b->next)
        {
            if (node_a->number == cur_b->number)
                error = set_push(res, cur_b->number);
        }
    }

    return error;
}

/*
 Функция нахождения разности множеств

 @param a [in]
 @param b [in]
 @param res [in]
 @param error [out]

 @return возвращает 0 в случае успешного нахождения разности (и -1 в ином случае)
 */

int set_difference(set_t a, set_t b, set_t res)
{
    int error = 0;
    error = set_copy(a, res);
    node_t node_b = b->head;
    node_t node_res = res->head;
    if (!error)
    {
        for ( ; !error && node_b; node_b = node_b->next)
        {
            int search = false;
            for (node_t cur = node_res; cur; cur = cur->next)
            {
                if (cur->number == node_b->number)
                    search = true;
            }

            if (search)
                error = set_pop(res, node_b->number);

        }
    }
    else
        error = -1;


    return error;
}

/*
 Функция нахождения симмеческой разности множеств

 @param a [in]
 @param b [in]
 @param res [in]
 @param error [out]

 @return возвращает 0 в случае успешного нахождения разности (и -1 в ином случае)
 */

int set_symmetric_difference(set_t a, set_t b, set_t res)
{
    int error = 0;
    set_t s1, s2;
    set_create(&s1);
    set_create(&s2);

    error = set_union(a, b, s1);
    if (!error)
    {
        error = set_intersection(a, b, s2);
        if (!error)
            error = set_difference(s1, s2, res);
    }

    return error;
}

/*
 Функция копирования множества

 @param a [in]
 @param res [in]
 @param error [out]

 @return возвращает 0 в случае успешонго копирования множества (и -1 в ином случае)
 */

int set_copy(set_t a, set_t res)
{
    int error = 0;
    node_t node = a->head;
    for ( ; !error && node; node = node->next)
        error = set_push(res, node->number);

    return error;
}

/*
 Функция создания узла списка

 @param node [in]
 @param elem [in]
 @param error [out]

 @return возаращает 0 в случае успешного создания узла (и -1 в ином случае)
 */

int create_node(node_t *node, item_t elem)
{
    int error = 0;
    node_t new_node = malloc(sizeof(struct node_type));
    if (new_node)
    {
        new_node->number = elem;
        new_node->next = NULL;
        *node = new_node;
    }
    else
        error = -1;
    return error;
}

/*
 Функция добавления элемента

 @param s [in]
 @param elem [in]
 @param error [out]

 @return возращает 0 в случае успешного добавления элемента (и -1 в ином случае)
 */

int set_push(set_t s, item_t elem)
{
    node_t node_elem;
    int error = create_node(&node_elem, elem);
    if (!error)
    {
        if (!s->head)
            s->head = node_elem;
        else
        {
            node_t node = s->head;
            int search = false;

            for( ; node && node->next; node = node->next)
                if (node->number == elem)
                    search = true;

            if (node->number == elem)
                search = true;
            if (!search)
                node->next = node_elem;
        }
    }
    return error;

}

/*
 Функция удаления элемента

 @param s [in]
 @param elem [in]
 @param error [out]

 @return возвращает 0 в случае успешного удаления элемента (и -1 в ином случае)
 */

int set_pop(set_t s, item_t elem)
{
    int error = 0;
    node_t node = s->head;
    if (node->number == elem)
    {
        s->head = node->next;
        free(node);
    }
    else
    {
        node_t prev = node;
        node_t cur = node->next;
        int search = false;
        for( ; cur; cur = cur->next)
        {
            if (cur->number == elem)
            {
                search = true;
                prev->next = cur->next;
                free(cur);
                cur = prev;
            }
            prev = cur;
        }

        if (!search)
            error = -1;
    }

    return error;
}

/*
 Функция считывания множества из файла

 @param f [in]
 @param s [in]
 @param error [out]

 @return возвращает 0 в случае успешного считывания множества (и -1 в ином случае)
 */

int set_input(FILE *f, set_t s)
{
    int error = 0;
    int rc, number;
    char symb;
    while(!error && !feof(f))
    {
        rc = fscanf(f, "%d%c", &number, &symb);
        if (((rc == 2) && ((symb == '\n') || (symb == ' '))) || (rc == 1))
            rc = set_push(s, number);
        else if (rc == -1)
            error = 0;
        else
        {
            error = -1;
            fclose(f);
        }
    }
    return error;
}

