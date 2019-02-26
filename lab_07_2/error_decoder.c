#include"error_decoder.h"

/*
 Функция вывода информации об ошибке

 @param code [in]
 */

void printerr(enum error code)
{
    switch(code)
    {
        case ARG_ERROR:
            printf("Invalid number of arguments!");
            break;
        case IO_ERROR:
            printf("I/O error!");
            break;
        case INPUT_MAS_ERROR:
            printf("The size of inputting array is zero!");
            break;
        case NEW_SIZE_ERROR:
            printf("After applying the filter, the array size is zero!");
            break;
        case MALLOC_ERROR:
            printf("Malloc error!");
            break;
    }
}

