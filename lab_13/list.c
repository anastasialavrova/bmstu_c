#include <stdio.h>
#include "list.h"

/*
 Добавление в односвязный список нового элемента

 @param head [in]
 @param new_elem [in]
 @return указатель на голову
 */
tourist *add_to_list(tourist *head, tourist *new_elem)
{
    if (head)
    {
        tourist *cur = NULL;
        for (cur = head; cur->next; cur = cur->next)
            ;
        cur->next = new_elem;
    }
    else
        head = new_elem;

    return head;
}

/*
 Функция сравнения цен

 @param p [in]
 @param q [in]
 @return разница двух чисел
 */
int comporator_price(const void *p, const void *q)
{
    const tourist *a = p;
    const tourist *b = q;
    return  a->price - b->price;
}

/*
 Функция сравнения двух названий театра

 @param p [in]
 @param q [in]
 @return сравнение двух слов
 */
int comporator_name_tourist(const void *p, const void * q)
{
    const tourist *a = p;
    const tourist *b = q;
    return strcmp(a->name_tourist, b->name_tourist);
}

/*
 Функция сравнения двух названий спектакля

 @param p [in]
 @param q [in]
 @return сравнение двух слов
 */
int comporator_town(const void *p, const void * q)
{
    const tourist *a = p;
    const tourist *b = q;
    return strcmp(a->town, b->town);
}

/*
 Добавление нового элемента в список отсортированных элементов

 @param data [in]
 @param head [in]
 @param comporator [in]
 */
void list_add_sort(tourist *data, struct list_head *head, int (*comporator)
        (const void *, const void *), int type_of_sort)
{
    struct list_head *iter;
    tourist *cur = NULL;
    struct list_head *new = &data->sort[type_of_sort];

    list_for_each(iter, head)
    {
        cur = list_entry(iter, tourist, sort[type_of_sort]);
        if (comporator(cur, data) > 0)
        {
            new->prev = iter->prev;
            iter->prev->next = new;
            new->next = iter;
            iter->prev = new;
            break;
        }
        else if (iter->next == head)
        {
            list_add_tail(new, head);
            break;
        }
    }
    if (!cur)
        list_add_tail(new, head);
}

/*
 Поиск целого слова в строке

 @param str1 [in]
 @param str2 [in]
 @return 0, если вхождение найдено, в другом случае ненулевое значение
 */
int strsearch(char str1[], char str2[])
{
    int k = 0;
    for (int i = 0; str1[i] && str2[k] && (int)strlen(str2) - k; i++)
        if (str1[i] == str2[k])
            k++;
        else
            k = 0;

    return (int)strlen(str2) - k;
}

/*
 Добавление нового элемента в списки сортировок и фильтров

 @param new_elem [in]
 @param mas_sort [in]
 @param mas_filter [in]
 */
void add_elem_to_sort_and_filter(tourist *new_elem, struct list_head
**mas_sort, struct list_head **mas_filter)
{
    list_add_sort(new_elem, mas_sort[0], comporator_price, 0);
    list_add_sort(new_elem, mas_sort[1], comporator_name_tourist, 1);
    list_add_sort(new_elem, mas_sort[2], comporator_town, 2);
    if (new_elem->price <= MAX_PRICE)
        list_add_tail(&new_elem->filter[0], mas_filter[0]);
    if (!strsearch(new_elem->name_tourist, NAME))
        list_add_tail(&new_elem->filter[1], mas_filter[1]);
}

/*
 Вывод отсортированного списка по 1 из 3 возможных вариантов

 @param mas_sort [in]
 @param type_of_sort [in]
 */
void sort_tourist(struct list_head **mas_sort, int type_of_sort)
{
    struct list_head *iter;
    tourist *cur = NULL;
    printf("    %25s\t%30s\t%6s\n"
           "\n",
           "Country", "Town", "Price");
    int i = 0;
    list_for_each(iter, mas_sort[type_of_sort])
    {
        cur = list_entry(iter, tourist, sort[type_of_sort]);
        printf("%2d %25s\t%30s\t%6d\n", ++i, cur->name_tourist,
               cur->town, cur->price);
    }
    if (!cur)
        printf("Error! List is empty\n");
}

/*
 Вывод отфильтрованного списка по 1 из 2 возможных вариантов

 @param mas_filter [in]
 @param type_of_filter [in]
 */
void filter_tourist(struct list_head **mas_filter, int type_of_filter)
{
    struct list_head *iter;
    tourist *cur = NULL;
    printf("    %25s\t%30s\t%6s\n"
           "\n",
           "Country", "Town", "Price");
    int i = 0;
    list_for_each(iter, mas_filter[type_of_filter])
    {
        cur = list_entry(iter, tourist, filter[type_of_filter]);
        printf("%2d %25s\t%30s\t%6d\n", ++i, cur->name_tourist,
               cur->town, cur->price);
    }
    if (!cur)
        printf("Error! List is empty\n");
}

/*
 Загрузка данных из файла в список

 @param name_file [in]
 @param head [in]
 @param mas_sort [in]
 @param mas_filter [in]
 @return указатель на голову списка
 */
tourist *load_data_from_file(const char name_file[], tourist *head, struct list_head
**mas_sort, struct list_head **mas_filter)
{
    tourist *new_elem = NULL;
    FILE *file = fopen(name_file, "r");
    if (!check_file(file))
    {
        for (int i = 0, n = num_of_strings(file); i < n; i++)
        {
            new_elem = malloc(sizeof(tourist));
            new_elem->next = NULL;
            read_string(file, new_elem->name_tourist);
            read_string(file, new_elem->town);
            read_num_from_file(file, &new_elem->price);
            head = add_to_list(head, new_elem);

            add_elem_to_sort_and_filter(new_elem, mas_sort, mas_filter);
        }
    }
    fclose(file);

    return head;
}


/*
 Добавление нового элемента в список

 @param head [in]
 @param mas_sort [in]
 @param mas_filter [in]
 @return указатель на голову списка
 */
tourist *add_record(tourist *head, struct list_head **mas_sort,
                    struct list_head **mas_filter)
{
    tourist *new_elem = malloc(sizeof(tourist));
    new_elem->next = NULL;
    printf("Enter name of country: ");
    read_string(stdin, new_elem->name_tourist);

    printf("Enter name of town: ");
    read_string(stdin, new_elem->town);

    read_num(&new_elem->price, "Enter price: ");

    head = add_to_list(head, new_elem);
    add_elem_to_sort_and_filter(new_elem, mas_sort, mas_filter);

    return head;
}

/*
 Вывод списка на экран

 @param head [in]
 */
void print_table(tourist *head)
{
    if (head)
    {
        printf("    %25s\t%30s\t%6s\n"
               "\n",
               "Country", "Town", "Price");
        int i = 0;
        printf("\n");
        for (tourist *cur = head; cur; cur = cur->next, i++)
            printf("%2d %25s\t%30s\t%6d\n", i + 1, cur->name_tourist,
                   cur->town, cur->price);
    }
    else
        printf("List is empty\n");
}

/*
 Поиск элемента в списке по индексу

 @param head [in]
 @param index [in]
 @return указатель на найденный элемент
 */
tourist *search_elem_by_index(tourist *head, int index)
{
    int i = 0;
    tourist *cur = NULL;
    for (cur = head; cur->next && i < index; cur = cur->next, i++)
        ;

    return cur;
}

/*
 Удаление элемента из списка сортировки

 @param cur [in]
 */
void del_elem_from_sort(tourist *cur)
{
    for (int i = 0; i < MAX_SORT_INDX; i++)
        list_del(&cur->sort[i]);
}

/*
 Удаление элемента из списка фильтра

 @param cur [in]
 */
void del_elem_from_filter(tourist *cur)
{
    for (int i = 0; i < MAX_FILTER_INDX; i++)
    {
        if (cur->filter[i].next)
            list_del(&cur->filter[i]);
    }
}

/*
 Удаление элемента из списка

 @param head [in]
 @return указатель на голову списка
 */
tourist *del_elem(tourist *head)
{
    if (head)
    {
        int index_to_delete, i = 0;
        tourist *cur = NULL, *prev = NULL;
        read_num(&index_to_delete, "Enter index to delete from list: ");
        for (cur = head; cur->next && i < index_to_delete; cur = cur->next, i++)
            prev = cur;
        if (i == index_to_delete)
        {
            del_elem_from_sort(cur);
            del_elem_from_filter(cur);

            if (prev)
                prev->next = cur->next;
            else
                head = cur->next;
            free(cur);
        }
        else
            printf("Index not found\n");
    }
    else
        printf("List is empty\n");

    return head;
}

/*
 Изменение элемента списка

 @param head [in]
 @param mas_sort [in]
 @param mas_filter [in]
 */
void edit_elem(tourist *head, struct list_head **mas_sort, struct list_head **mas_filter)
{
    if (head)
    {
        int choice, index;
        read_num(&index, "Enter index to edit element from list: ");
        tourist *cur = search_elem_by_index(head, index);

        do
            read_num(&choice, "What do you want to edit? Country(1),\nname of"
                              " town(2) or price(3): ");
        while (choice < 1 || choice > 3);

        del_elem_from_sort(cur);
        del_elem_from_filter(cur);

        if (choice == 1)
        {
            printf("Enter name of country: ");
            read_string(stdin, cur->name_tourist);
        }
        else if (choice == 2)
        {
            printf("Enter name of town: ");
            read_string(stdin, cur->town);
        }
        else
            read_num(&cur->price, "Enter price: ");

        add_elem_to_sort_and_filter(cur, mas_sort, mas_filter);
    }
    else
        printf("List is empty\n");
}

/*
 Освобождение списка из памяти

 @param head [in]
 */
void free_list(tourist *head)
{
    if (head)
        for (tourist *cur = head, *next = NULL; cur; cur = next)
        {
            next = cur->next;
            free(cur);
        }
}

/*
 Сохранить данные в файле

 @param name_of_file [in]
 @param head [in]
 */
void save_data(const char name_of_file[], tourist *head)
{
    FILE *file = fopen(name_of_file, "w");
    for (tourist *cur = head; cur; cur = cur->next)
        fprintf(file, "%s; %s; %d\n", cur->name_tourist, cur->town, cur->price);
    fclose(file);
}
