#include "test.h"

int test_func_sort(void);
int test_func_filter(void);

int main(void)
{
    enum ERRORS err = OK;
    printf("func sort:\n");
    err = test_func_sort();
    if (!err)
        printf("OK\n");
    else
        printf("NOT OK\n");
    printf("\n");

    printf("func filter:\n");
    err = test_func_filter();
    if (!err)
        printf("OK\n");
    else
        printf("NOT OK\n");
    printf("\n");

    return err;
}

/*
 Тестирование функции сортировки

 @return код ошибки
 */
int test_func_sort()
{
    enum ERRORS err = OK;
    LIST_HEAD(sort_by_price);
    LIST_HEAD(sort_by_tourist_name);
    LIST_HEAD(sort_by_town);
    struct list_head *mas_sort[MAX_SORT_INDX] = {&sort_by_price,
        &sort_by_tourist_name, &sort_by_town};

    LIST_HEAD(sort_by_price1);
    LIST_HEAD(sort_by_tourist_name1);
    LIST_HEAD(sort_by_town1);
    struct list_head *mas_sort1[MAX_SORT_INDX] = {&sort_by_price1,
        &sort_by_tourist_name1, &sort_by_town1};

    LIST_HEAD(filter_by_price);
    LIST_HEAD(filter_by_name);
    struct list_head *mas_filter[MAX_FILTER_INDX] = {&filter_by_price,
        &filter_by_name};

    tourist *head_to_sort = NULL, *head_result = NULL;
    head_to_sort = load_data_from_file("in_1.txt", head_to_sort, mas_sort,
                                       mas_filter);
    head_result = load_data_from_file("out_1.txt", head_result, mas_sort1,
                                      mas_filter);

    struct list_head *iter;
    tourist *cur_to_sort = NULL, *cur_result = head_result;
    list_for_each(iter, mas_sort[0])
    {
        cur_to_sort = list_entry(iter, tourist, sort[0]);
        if (cur_to_sort->price != cur_result->price)
            err = ERROR_TESTING_SORT;
        if (cur_result->next)
            cur_result = cur_result->next;
    }

    return err;
}

/*
 Тестирование функции фильтра

 @return код ошиюки
 */
int test_func_filter()
{
    enum ERRORS err = OK;
    LIST_HEAD(sort_by_price);
    LIST_HEAD(sort_by_tourist_name);
    LIST_HEAD(sort_by_town);
    struct list_head *mas_sort[MAX_SORT_INDX] = {&sort_by_price,
        &sort_by_tourist_name, &sort_by_town};

    LIST_HEAD(filter_by_price);
    LIST_HEAD(filter_by_name);
    struct list_head *mas_filter[MAX_FILTER_INDX] = {&filter_by_price,
        &filter_by_name};

    LIST_HEAD(filter_by_price1);
    LIST_HEAD(filter_by_name1);
    struct list_head *mas_filter1[MAX_FILTER_INDX] = {&filter_by_price1,
        &filter_by_name1};

    tourist *head_to_filter = NULL, *head_result = NULL;
    head_to_filter = load_data_from_file("in_2.txt", head_to_filter, mas_sort,
                                         mas_filter);
    head_result = load_data_from_file("out_2.txt", head_result, mas_sort,
                                      mas_filter1);

    struct list_head *iter;
    tourist *cur_to_sort = NULL, *cur_result = head_result;
    list_for_each(iter, mas_filter[0])
    {
        cur_to_sort = list_entry(iter, tourist, filter[0]);
        if (cur_to_sort->price != cur_result->price)
        {
            err = ERROR_TESTING_FILTER;
        }
        if (cur_result->next)
            cur_result = cur_result->next;
        err = 0;
    }

    return err;
}
