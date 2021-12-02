#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {

    FILE *write_fp;
    char buffer[MAX_SIZE];
    
    write_fp = popen("ls", "w");
    if(write_fp == NULL) {
        perror("pipe open failed");
        exit(EXIT_FAILURE);
    }

    sprintf(buffer, "/home/git");
    if(fwrite(buffer, 1024, 1, write_fp)  < 0) {
        perror("read fault");
        exit(EXIT_FAILURE);
    }
    printf("byby im main \n%s\n", buffer);
    sleep(10);
    exit(EXIT_SUCCESS);
}
