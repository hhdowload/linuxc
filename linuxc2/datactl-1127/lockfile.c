#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


int main() {
    int fp;

    fp = open("/tmp/TMP1", O_RDWR|O_CREAT|O_EXCL, 0777);
    if(fp == -1) {
        perror("fp failed");
    } 
    else printf("open fp success");

    exit(EXIT_SUCCESS);
}