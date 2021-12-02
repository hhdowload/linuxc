#include <stdio.h>
#include <stdlib.h>
#define  EXIT_SUCESS 0
#define  EXIT_FAILURE 1

extern void function3();
extern void function2();


int  main() {
    function2();
    function3();
    printf("just make Makefile\n");

    return EXIT_SUCESS;
}
