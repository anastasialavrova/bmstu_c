#include <stdio.h>
#include <stdlib.h>

#include "test_arr.h"

/*
 Функция запускает тестовую функция для каждого случая
 */

int main()
{
    printf("Tests union: ");
    test_func(INP_FILE_NAME_UNION, OUT_FILE_NAME_UNION,
              POS, set_union);

    printf("Tests intersection: ");
    test_func(INP_FILE_NAME_INTER, OUT_FILE_NAME_INTER,
              POS, set_intersection);

    printf("Tests difference: ");
    test_func(INP_FILE_NAME_DIF, OUT_FILE_NAME_DIF,
              POS, set_difference);

    printf("Tests symmetric difference: ");
    test_func(INP_FILE_NAME_SYM_DIF, OUT_FILE_NAME_SYM_DIF,
              POS, set_symmetric_difference);

    return 0;
}

/*
 Функция для тестирования функций объединения, пересечения, нахождения
 симетрической и обычной разности множеств

 @param inp_name [in]
 @param out_name [in]
 @param pos [in]
 @param func [in]
 */

void test_func(char *inp_name, char *out_name, int pos, int (*func)(set_t, set_t, set_t))
{
    int error;
    set_t a, b, res, answer;
    int success_tests = 0;
    char str[] = "0123456789";

    set_create(&a);
    set_create(&b);
    set_create(&res);
    set_create(&answer);

    char inp_file_name[100];
    for (int i = 0; i < strlen(inp_name); i++)
        inp_file_name[i] = inp_name[i];
    inp_file_name[strlen(inp_name)] = '\0';

    char out_file_name[100];
    for (int i = 0; i < strlen(out_name); i++)
        out_file_name[i] = out_name[i];
    out_file_name[strlen(out_name)] = '\0';

    FILE *inp_a, *inp_b, *out;
    inp_file_name[pos + 1] = 'a';
    inp_a = fopen(inp_file_name, "r");
    inp_file_name[pos + 1] = 'b';

    inp_b = fopen(inp_file_name, "r");
    out = fopen(out_file_name, "r");

    set_input(inp_a, a);
    set_input(inp_b, b);
    set_input(out, answer);

    error = func(a, b, res);

    if (!error && set_compare(res, answer))
        success_tests++;

    fclose(inp_a);
    fclose(inp_b);
    fclose(out);

    set_destroy(a);
    set_destroy(res);
    set_destroy(answer);


    if (success_tests)
        printf("OK\n");
    else
        printf("NOT OK\n");

}
