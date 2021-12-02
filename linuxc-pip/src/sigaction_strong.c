#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void ocur(int sig) {
	printf("i have got sinint\n");	
	sleep(1);
}

int main() {

  	struct sigaction act;
	
	act.sa_handler = ocur;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	
	sigaction(SIGINT,&act, 0);
	while(1) {
		printf("i am waiting something who wants stop me\n");
		printf("but i have to lives\n");
		sleep(3);
	}	
	exit(0);
}
