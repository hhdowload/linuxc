#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    pid_t pid;
    char str[] = "hellow boy";
    int  size;
    int pipefd[2];

    if(pipe(pipefd) == -1 ) {
        perror("pipe create failed");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if(pid == 0) {

	int res;
	close(0);
	res = dup(pipefd[0]);
	if(res == 0) {
		printf("wwe remake 0 stdin..\n");
	}

	if(res != 0) {
		perror("dup failed");
		exit(EXIT_FAILURE);
	}
	close(pipefd[1]);
	close(pipefd[0]);
        printf("im child.pid=%d.\n", getpid());
     	execlp("od", "od", "-c", NULL);
	exit(1);
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
