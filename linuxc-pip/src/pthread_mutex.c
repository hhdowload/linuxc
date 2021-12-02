#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

pthread_mutex_t work_mutex;
void *thread_function(void *arg);
int res;
char message[1024];
/*int time_to_exit = 0*/

int main() {
	pthread_t a_thread;
	void *thread_result;	


	res = pthread_mutex_init(&work_mutex, NULL);  /*初始化互斥量*/
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
		pthread_mutex_lock(&work_mutex);
		fgets(message, 1024, stdin);
		pthread_mutex_unlock(&work_mutex);
		while(1) {
			if(strncmp(message, "EOF", 3) == 0)  break;
			if(message[0] == '\0') break;	
		}
	}


	pthread_mutex_destroy(&work_mutex);
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
		
		pthread_mutex_lock(&work_mutex);
		printf("IPUT is ****** %s\n", message);
		printf("iput string length is: %d\n",(int)(strlen(message) -1));
		message[0] = '\0';
		pthread_mutex_unlock(&work_mutex);
		while(1) {
			if(message[0] != '\0')	break;
		}
	}
	printf("its time for myboy..\n");
	pthread_exit(0);
					
}
