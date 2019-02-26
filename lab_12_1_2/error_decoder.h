
#ifndef LAB_7_ERROR_DECODER_H
#define LAB_7_ERROR_DECODER_H

#include<stdio.h>

enum error
{
    NO_ERROR = 0,
    ARG_ERROR = -1,
    IO_ERROR = -2,
    INPUT_MAS_ERROR = -3,
    NEW_SIZE_ERROR = -4,
    MALLOC_ERROR = -5
};

void printerr(enum error code);

#endif //LAB_7_ERROR_DECODER_H
