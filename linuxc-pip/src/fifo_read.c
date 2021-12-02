#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_NAME "/tmp/my_fifo"

int main(int argc, char *argv[]) {

        int i, res, read_size;
        int open_mode = 0;
        char buffer[100];

        if(argc < 2) {
            fprintf(stderr, "error type: %s <combine of  O_RDONLY O_WRONLY O_NONBLOCK\n", *argv);
            exit(EXIT_FAILURE);
        }
        for(i = 1; i < argc; i++) {
            if(strncmp(*(argv++), "O_RDONLY", 8) == 0) {
                open_mode |= O_RDONLY; 
            }
            if(strncmp(*argv, "O_WRONLY", 8) == 0) {
                open_mode |= O_WRONLY; 
            }
            if(strncmp(*argv, "O_NONBLOCK", 10) == 0) {
                open_mode |= O_NONBLOCK; 
            }
        }

        printf("open_mode====>%d\n", open_mode);
        if(access(FIFO_NAME, F_OK) == -1) {
            printf("FIFO_NAME is not exits..\n");
            res = mkfifo(FIFO_NAME, 0777);
            if(res != 0) {
                perror("make fifo failed\n");
                exit(1);
            }
        }
        printf("process===>%d open a fifo by %s\n", getpid(), *argv);
        res = open(FIFO_NAME, open_mode);
        if(res == -1) {
            perror("open fifo failed\n");
            close(res);
            exit(1);
        }     

        printf("process===>%d open  fifo finished\n", getpid());
        read_size = read(res, buffer, sizeof(buffer));
        if(read_size > 0) {
            printf("we read %d bytes\n from res==>%d\n", read_size, res);
            printf("we read buffer==>%s\n", buffer);
        } else {
            perror("read failed");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
}