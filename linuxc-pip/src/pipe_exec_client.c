#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void *argc, void *argv[]) {
    printf("son is running\n");
    int fd_read;
    int size;
    char buffer[1024];
    
    sscanf(argv[1], "%d", &fd_read);
    size = read(fd_read, buffer, 1024);
    if(size > 0) {
        printf("we have got %d bytes..\n", size);
        printf("parent gift is:  **%s**  \n", buffer);
        exit(0);
    } else {
        perror("child read failed");
        exit(1);
    }

}