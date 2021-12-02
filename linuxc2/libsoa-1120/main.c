#include <stdio.h>
#include <stdlib.h>

void argc(int);
void argv(char **);

void main(int argc1, char *argv2[]) {

    argc(argc1);
    argv(argv2);
    printf("main===>argv2 %s\n", argv2[0]);
}