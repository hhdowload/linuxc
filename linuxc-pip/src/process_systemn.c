#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>



int main() {
	char *const echo_argv[] = {"echo","${NAME}", 0};
	char *const echo_envp[] = {"NAME=execve", 0};

	char *error;
	printf("we would run ps process ..\n");
	system("ps -xua");
     /*   execl("/bin/ls", "ls", "-l", 0); */
	execve("/usr/bin/echo", echo_argv, echo_envp);
	perror("error");
	printf("done..\n");
	exit(0);
}
