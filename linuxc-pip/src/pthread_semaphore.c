#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

sem_t bin_sem;
void *thread_function(void *arg);
int res;
char message[1024];

int main() {
	pthread_t a_thread;
	void *thread_result;	


	res = sem_init(&bin_sem, 0, 0);  /*初始化二进制信号量，参数三表示为进程内共享，参数三表示初始值赋0*/
	/*检查函数返回值*/
	if(res != 0) {
		printf("semaphore init failed\n");
		perror("FAILED");
		exit(EXIT_FAILURE);
	}

	res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
	if(res != 0) {
		printf("thread create failed\n");
		perror("FAILED");
		exit(EXIT_FAILURE);
	}

	
	while(strncmp(message, "EOF", 3) != 0) {
		fgets(message, 1024, stdin);
		sem_post(&bin_sem);
		
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
	while(strncmp(message, "EOF", 3) != 0) {
		sem_wait(&bin_sem);
		printf("IPUT is ****** %s\n", message);
		printf("iput string length is: %d\n",(int)(strlen(message) -1));
	}
	printf("its time for myboy..\n");
	sem_destroy(&bin_sem);
	pthread_exit("thank u for cpu time\n");
					
}
