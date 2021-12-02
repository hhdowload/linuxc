#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void *pthread_function(void *arg);
void *function_result;

int main() {
    int res;
    int num = 6;
    pthread_t a_thread[num];
    
    for(; num > 0; num-- ) {
            res = pthread_create(&a_thread[num], NULL, pthread_function, (void *)&num);
        if(res != 0) {
            perror("pthread create failed\n");
            exit(EXIT_FAILURE);
        } else printf("thread[%d] is up..\n", num);
    
        sleep(2);
        res = pthread_join(a_thread[num], NULL);
        if(res != 0) { 
            perror("pthread join failed\n");
            exit(EXIT_FAILURE);
        } else printf("we have pick up a thread...");
    }

    

    printf("all done\n");
    exit(EXIT_SUCCESS);

}

void *pthread_function(void *arg) {
    int rand_time;

    printf("thread-%d is running..\n", *(int *)arg);
    rand_time =1 +  (int)(9.0*rand()/(RAND_MAX+1.0));
    /*sleep(rand_time);*/

    printf("thread %d is byby...\n", *(int *)arg);
    pthread_exit(0);
}