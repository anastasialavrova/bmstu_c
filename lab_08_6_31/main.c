#include<stdio.h>

#include"check.h"
#include"addition.h"
#include"matrix.h"
#include"multiplication.h"
#include"info.h"
#include"inverse_matrix.h"

int main(int argc, char *argv[])
{
    int error = check_string(argc);
    if (!error)
    {
        char choice = argv[1][0];
        if (choice == 'a')
            addition(argv[2], argv[3], argv[4]);
        else if (choice == 'm')
            multiplicaion(argv[2], argv[3], argv[4]);
        else if (choice == 'o')
            inverse_matrix(argv[2], argv[3]);
        else if (choice == 'h')
            info();
        else
            printf("Incorrect input!");
    }
}