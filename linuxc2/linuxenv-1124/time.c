#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t timeval;
    
    while(1) {
        time(&timeval);
        printf("Now is===>%s", ctime(&timeval));
        sleep(1);
    }
    exit(0);
}