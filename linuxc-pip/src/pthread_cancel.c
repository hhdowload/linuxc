#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg);
pthread_t a_thread;


int main() {
    int res;
    void *thread_result;

    res = pthread_create(&a_thread, NULL, thread_function, NULL);
    if(res != 0) {
        printf("pthread create failed!!/n");
        perror("create failed");
        exit(EXIT_FAILURE);
    }
    printf("create a thread\n");
    sleep(3);
    printf("cancel this thread....\n");
    res = pthread_cancel(a_thread);
    if(res != 0) {
        printf("pthread cancel failed!!\n");
        perror("cancel failed\n");
        exit(EXIT_FAILURE);
    }
    printf("waiting for thread finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if(res != 0) {
        printf("pthread join failed!!/n");
        perror("join failed");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
    int res;
    int i = 20;

    res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    if(res != 0) {
        printf("pthread set cancel state failed!!\n");
        perror("set failed\n");
        exit(EXIT_FAILURE);
    }
    res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    if(res != 0) {
        printf("thread set cancel type failed!!\n");
        perror("set type failed\n");
        exit(EXIT_FAILURE);
    }

    while( i-- > 1) {
        printf("thread is running....\n");
        sleep(1);
    }
    
    pthread_exit(0);

}
