#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    pid_t pid;
    char str[10] = "hellow boy";
    char *buffer[1024];
    int fd, size;
    int pipefd[2];

    if(pipe(pipefd) == -1 ) {
        perror("pipe create failed");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if(pid == 0) {
        int size_read;

        printf("im child.pid=%d.\n", getpid());
        size_read = read(pipefd[0], buffer, sizeof(buffer));
        if(size_read == -1) {
            perror("read failed");
            exit(EXIT_FAILURE);
        }

        printf("i have got something:%s", buffer);
    }

    if(pid > 0 ) {
        printf("im father.pid=%d.\n", getpid());
        size = write(pipefd[1], str, sizeof(str));
        if(size == -1) {
            perror("write failed");
            exit(EXIT_FAILURE);
        }
    } 
    
    if(pid == -1){
        perror("fork failed");
        exit(EXIT_FAILURE);
    } 

    exit(EXIT_SUCCESS);   
}