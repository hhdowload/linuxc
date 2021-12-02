#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid;
	char * message;
	int exit_code;	


	pid = fork();
	switch(pid) {
		case 0 : 
			  printf("nhaoa\n");
			  message = "im boy";
			  exit_code = 22;
			  sleep(2);
			  break;
		case -1 :
			  printf("im error\n");
			  perror("program failed");
			  exit(1);
		default :
			  printf("hellow\n"); 
			  message = "im baba";
			  exit_code = 0;
			  sleep(30);
			  break;
	}		

	printf("%s\n", message);
	sleep(1);
	if(pid) {
		pid_t child_pid;
		int stat_val;
		child_pid = wait(&stat_val);	
		printf("child process pid:%d----%d over\n", child_pid, pid);
		
		if(WIFEXITED(stat_val)) {
			printf("the exitcode is %d", WEXITSTATUS(stat_val));
		}	
		else printf("boy exit by accdient\n");

	}


	exit(exit_code);
}
