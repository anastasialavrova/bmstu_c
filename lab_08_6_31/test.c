#include <stdio.h>
#include "add_test.h"
//#include "invers_tests.h"
//#include "multiply_tests.h"

int main()
{
    //if (multiply_test() && invers_test && add_test)
    if(add_test())
        printf("OK");
    else
        printf("NOT OK");
}
