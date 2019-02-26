#include "main.h"

int main(int argc, const char * argv[])
{
    enum ERRORS err = OK;

    if (argc != 2)
    {
        printf("Invalid num of args in command line ./app.exe [file.txt]\n");
        return ERROR_COMMAND_LINE;
    }
    tourist *head = NULL;
    LIST_HEAD(sort_by_price);
    LIST_HEAD(sort_by_tourist_name);
    LIST_HEAD(sort_by_performance);
    struct list_head *mas_sort[MAX_SORT_INDX] = {&sort_by_price,
                                                 &sort_by_tourist_name, &sort_by_performance};

    LIST_HEAD(filter_by_price);
    LIST_HEAD(filter_by_name);
    struct list_head *mas_filter[MAX_FILTER_INDX] = {&filter_by_price,
                                                     &filter_by_name};

    int menu, process = 1, is_loaded_from_file = 0;
    while (process)
    {
        printf("\n"
               "Menu:\n"
               " 1) Load from file\n"
               " 2) Add record\n"
               " 3) Del record by index\n"
               " 4) Edit record\n"
               " 5) Print table\n"
               " 6) Sort by price\n"
               " 7) Sort by country name\n"
               " 8) Sort by town\n"
               " 9) Filter by price less 80.000 rub\n"
               "10) Filter by word 'Sweden'\n"
               "0) Exit\n"
               "\nEnter: ");

        read_num(&menu, "");
        printf("\n");

        switch(menu)
        {
            case 0: process = 0;
                break;
            case 1:
                if (is_loaded_from_file)
                    printf("Data is already imported from file\n");
                else
                {
                    head = load_data_from_file(argv[1], head, mas_sort, mas_filter);
                    is_loaded_from_file = 1;
                }
                break;
            case 2:
                head = add_record(head, mas_sort, mas_filter);
                break;
            case 3:
                head = del_elem(head);
                break;
            case 4:
                edit_elem(head, mas_sort, mas_filter);
                break;
            case 5:
                print_table(head);
                break;
            case 6:
                sort_tourist(mas_sort, 0);
                break;
            case 7:
                sort_tourist(mas_sort, 1);
                break;
            case 8:
                sort_tourist(mas_sort, 2);
                break;
            case 9:
                filter_tourist(mas_filter, 0);
                break;
            case 10:
                filter_tourist(mas_filter, 1);
                break;

            default: puts("Enter num from 0 to 10\n");
        }
    }

    free_list(head);

    return err;
}
