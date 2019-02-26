#ifndef _TEST_H_
#define _TEST_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "func_list.h"

#define POS 4

#define INP_FILE_NAME_UNION "inp_1a.txt"
#define OUT_FILE_NAME_UNION "out_1.txt"

#define INP_FILE_NAME_INTER "inp_2a.txt"
#define OUT_FILE_NAME_INTER "out_2.txt"

#define INP_FILE_NAME_DIF "inp_3a.txt"
#define OUT_FILE_NAME_DIF "out_3.txt"

#define INP_FILE_NAME_SYM_DIF "inp_4a.txt"
#define OUT_FILE_NAME_SYM_DIF "out_4.txt"

void test_func(char *inp_name, char *out_name, int pos,
                        int (*func)(set_t, set_t, set_t));

#endif
