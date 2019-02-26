#include <stdio.h>
#include <stdlib.h>

#include "func_arr.h"

struct set_type
{
    item_t *content;
    int max_len;
    int cur_len;
};

/*
 Функция создаёт множество

 @param a [in]
 @param error [out]

 @return возвращает 0 в случае успешного создания множества (и -1 в ином случае)
 */

int set_create(set_t *a)
{
    int error = 0;
    set_t new_set = malloc(sizeof(struct set_type));
    if (new_set)
    {
        item_t *new_content = malloc(SIZE_BUF*sizeof(item_t));
        if (new_content)
        {
            new_set->content = new_content;
            new_set->max_len = SIZE_BUF;
            new_set->cur_len = 0;
            *a = new_set;
        }
        else
        {
            free(new_set);
            error = -1;
        }
    }
    else
        error = -1;
    return error;
}

/*
 Функция удаления множества

 @param s [in]
 */

void set_destroy(set_t s)
{
    if (s)
    {
        if (s->content)
            free(s->content);
        free(s);
    }
}

/*
 Функция проверки множества на пустоту

 @param s [in]
 @param result [out]

 @return возвращает true, если множество пустое (или false в ином случае)
 */

bool set_is_empty(set_t s)
{
    bool result;
    if (!s->cur_len)
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
    if (!s->cur_len)
        printf("Empty\n");
    else
    {
        for (int i = 0; i < s->cur_len; i++)
            printf("%d ", s->content[i]);

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
    return a->cur_len;
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
        int i = 0, j = 0;
        for ( ; i < a->cur_len && b->cur_len; i++, j++)
        {
            if (a->content[i] != a->content[j])
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
        for (int i = 0; i < b->cur_len; i++)
        {
            int search = false;
            for (int j = 0; j < res->cur_len; j++)
            {
                if (b->content[i] == res->content[j])
                    search = true;
            }

            if (!search)
                error = set_push(res, b->content[i]);

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
    for (int i = 0; i < a->cur_len; i++)
    {
        for (int j = 0; j < b->cur_len; j++)
        {
            if (a->content[i] == b->content[j])
                error = set_push(res, b->content[j]);
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
    if (!error)
    {
        for (int i = 0; i < b->cur_len; i++)
        {
            int search = false;
            for (int j = 0; j < res->cur_len; j++)
            {
                if (res->content[j] == b->content[i])
                    search = true;
            }

            if (search)
                error = set_pop(res, b->content[i]);

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

    if (!set_create(&s1) && !set_create(&s2))
    {
        error = set_union(a, b, s1);
        if (!error)
        {
            error = set_intersection(a, b, s2);
            if (!error)
                error = set_difference(s1, s2, res);
        }
    }
    set_destroy(s1);
    set_destroy(s2);
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
    for (int i = 0; i < a->cur_len; i++)
        error = set_push(res, a->content[i]);

    return error;
}

/*
 Функция расширения динамического массива

 @param s [in]
 @param error [out]

 @return возаращет 0 в случае успешного расширения массива (или -1 в ином случае)
 */

int array_extension(set_t s)
{
    int error = 0;
    item_t *new_content = realloc(s->content, (s->max_len + SIZE_BUF)*sizeof(item_t));

    if (new_content)
    {
        s->content = new_content;
        (s->max_len) += SIZE_BUF;
    }
    else
    {
        set_destroy(s);
        error = -1;
    }
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
    int error = 0;
    if (s->cur_len == s->max_len)
        error = array_extension(s);

    int search = false;

    for(int i = 0; i < s->cur_len; i++)
        if (s->content[i] == elem)
            search = true;

    if (!search)
    {
        s->content[s->cur_len] = elem;
        (s->cur_len)++;
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
    if (!set_is_empty(s))
    {
        int search = false;
        for(int i = 0; i < s->cur_len; i++)
            if (s->content[i] == elem)
            {
                search = true;
                for (int j = i; j < s->cur_len - 1; j++)
                    s->content[j] = s->content[j + 1];
                (s->cur_len)--;
            }

        if (!search)
            error = -1;
    }
    else
        error = -1;

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

