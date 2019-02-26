#include<stdio.h>
#include<stdlib.h>

/*
Функция проверки количества элементов подаваемой консольной строки

 @param argc [in]
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
 @param f_input [in]
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




