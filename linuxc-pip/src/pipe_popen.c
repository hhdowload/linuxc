#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {

    FILE *read_fp;
    char *buffer[MAX_SIZE];
    int chars_read;

    read_fp = popen("ps -aux", "r");
    if(read_fp == NULL) {
        perror("pipe open failed");
        exit(EXIT_FAILURE);
    }
    chars_read = fread(buffer, 1024, 1, read_fp);
    if(chars_read  < 0) {
        perror("read fault");
        exit(EXIT_FAILURE);
    } else {
        while(chars_read > 0) {
            printf("i caught message:\n%s\n", buffer);
            chars_read = fread(buffer, 1024, 1, read_fp);
         
        }
    }
    
    pclose(read_fp);
    exit(EXIT_SUCCESS);
}
