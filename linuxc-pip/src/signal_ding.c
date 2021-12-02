#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

static int fire_alarm = 0;

void ding(int sig) {
	fire_alarm = 1;
}

int main() {
	pid_t pid;
	pid = fork();
	switch(pid) {
		case 0:
			printf("U know im boy\n");
			sleep(5);
			kill(getppid(), SIGALRM);
			break;
		case -1:
			perror("Fork failed");
			exit(1);
		default:
			printf("U know im baba----%d\n", getpid());
			
	}
	
	if(pid != 0) {
		(void) signal(SIGALRM, ding);
		printf("waiting for my boy signal..\n");
		
		pause();

		while(fire_alarm) {
			printf("i have my boy gifts hhahahah\n");
			printf("\a\a\a\a\n");
			sleep(5);
		}
	}

	exit(0);
}


