#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/shm.h>
#include "ipc_shm.h"

int main() {
    int running = 1;
    void *shared_memory = (void *) 0;
    struct shared_use_st *shared_stuff;
    int shmid;

    srand((unsigned int) getpid());

    shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
    if(shmid == -1) {
        fprintf(stderr, "shmget failed\n");
        exit(EXIT_FAILURE);
    }

    shared_memory = shmat(shmid, (void *)0, 0);
    if(shared_memory == (void *)-1) {
        fprintf(stderr, "shmat failed\n");
        exit(EXIT_FAILURE);
    } 
    printf("memory attached at %x \n", shared_memory);
    shared_stuff = (struct shared_use_st *)shared_memory; 

    /*while(running) {
        if(shared_stuff->written_by_you) {
            printf("you wrote %s\n", shared_stuff->some_text);
            sleep(rand() % 4);
            shared_stuff.written_by_you = 0;
            if(strncmp(shared_stuff.written_by_you, "end", 3) == 0) {
                running = 0;
            }
        }
    } */
    while(strncmp(shared_stuff->some_text, "end", 3)) {
        
        char a[5];
        int res;
        res = scanf("%s", a);
        strcpy(shared_stuff->some_text, a);
        shared_stuff->written_by_you = 1;
        sleep(5);
    }

    if(shmdt(shared_memory) == -1) {
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);        
    }

    if(shmctl(shmid, IPC_RMID, 0) == -1) {
        fprintf(stderr, "shmCTL_RM failed\n");
        exit(EXIT_FAILURE);        
    }

    exit(EXIT_SUCCESS);
}