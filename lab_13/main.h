#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SORT_INDX 3
#define MAX_FILTER_INDX 2
#define SIZE 200
#define MAX_PRICE 80000
#define NAME "Sweden"

#include "list.h"
#include "file_funcs.h"

enum ERRORS {ERROR_TESTING_FILTER = -4, ERROR_TESTING_SORT, ERROR_COMMAND_LINE, ERROR_FILE, OK};

#endif
