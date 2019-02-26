#ifndef file_funcs_h
#define file_funcs_h

#include <stdio.h>
#include "list.h"
#include "main.h"

int check_file(FILE *file);
int num_of_strings(FILE *file);
void read_num_from_file(FILE *file, int *num);
void read_string(FILE *file, char *string);
void read_num(int *num, char message[]);


#endif
