#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

char message[] ="HELLO MOTO";
void *thread_function(void *arg);
int run_time = 0;

int main() {
	int res, print_count1 = 0;
	pthread_t a_thread;
	void *thread_result;	

	printf("message=%s\n", message);
	printf("prepare create thread\n");
	res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
	if(res != 0) {
		printf("thread create failed\n");
		perror("FAILED");
		exit(EXIT_FAILURE);
	}
	while(print_count1++ < 20) {
		if(run_time == 0) {
			run_time = 1;
			printf("its main time\n");
		} else sleep(1);
	}
	printf("we have  created thread\n");
	res = pthread_join(a_thread, &thread_result);
	if(res != 0) {
		perror("thread_join fail\n");
		exit(EXIT_FAILURE);
	}
	else printf("thread join result=%s", (char *)thread_result);
	printf("message=%s\n", message);
	
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
	int print_count2 = 0;	

	while(print_count2++ < 20) {
		if(run_time == 1) {
			run_time = 0;
			printf("its thread time\n");
		} else sleep(1);
	}
	printf("thread is running message=%s\n",(char *)arg);
	strcpy(message, "bye");
	printf("its time for myboy..\n");
	pthread_exit("thank u for cpu time\n");
					
}
