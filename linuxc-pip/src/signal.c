#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void oops(int sig) {
	printf("i got sigiter %d \n", sig);
	(void) signal(SIGINT, SIG_DFL);
}



int main() {
	(void) signal(SIGINT, oops);
	while(1) {
		printf("hahha.im free\n");
		sleep(2);
	}

	exit(0);
}


