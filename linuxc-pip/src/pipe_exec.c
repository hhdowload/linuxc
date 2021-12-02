#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    
    pid_t pid;
    int fd_write;
    int pipe_fp[2];
    char buffer[] = "hellow im your dd";
    char buffer_read[1024];

    if(pipe(pipe_fp) == 0) {
        perror("pipe failed");
        
    }

    pid = fork();
    if(pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if(pid == 0) {
        int   *fp_read;
        sprintf(buffer_read, "%d", pipe_fp[0]);
        printf("i would gone by wind..%d\n", getpid());
        execl("pipe_exec_client", "pipe_exec_client", buffer_read,  NULL);
        printf("im bad boy..\n");
        exit(1);
    } else {
        int size;
        printf("im dada..%d\n", getpid());
        size = write(pipe_fp[1], buffer, strlen(buffer));
        if(size > 0) printf("we put %d bytes", size);
        else  {
            perror("write failed");
            exit(EXIT_FAILURE);
        }
    }




    printf("waiting for son of process finish..\n");
    int res = wait();
    if(res > 0) printf("childe process %d is done..bye\n", res);
    else perror("recycle failed");
    exit(EXIT_SUCCESS);
}