
#ifndef LAB_11_TEST_H
#define LAB_11_TEST_H

#define SIZE 50
#define ARGS_DEC  -30, 255, 0, -30, 255, 0
#define ARGS_HEX 255, 255, 0x100, 0x100, 0, 0 , 33, 33
#define ARGS_MORE_ARGS 1, 10, 100

void print_results(int returned1, int returned2, char *res1, char *res2);
void test_snprintf_dec();
void test_snprintf_hex();
void test_snprintf_percent();
void test_snprintf_no_args();
void test_snprintf_empty();
void test_snprintf_small();
void test_snprintf_more_args();
void free_res(char *res1, char *res2);

#endif
