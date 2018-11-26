#include<stdio.h>
#include<stdlib.h>
//#include "check.h"

/*
Функция проверки количества элементов подаваемой консольной строки
*/
int check_string(int argc)
{
    if (argc < 3)
    {
        fprintf(stderr, "Invalid number of arguments!");
        return -1;
    }
    else
        return 0;
}

/*
Функция проверки существования данных в файле
*/


int check_file(FILE *f_input)
{
	if (f_input == NULL)
	{
		fprintf(stderr, "I/O error\n");
		return -2;
	}
	else
		return 0;
}


/*
int check_calloc(int *a)
{
	if (a == NULL)
	{
		printf("Malloc error.\nSize: %d", size);
		return -2;
	}
	else
		return 0;
}
*/


