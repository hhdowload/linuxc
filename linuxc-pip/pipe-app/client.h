#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

#define SERVER_FIFO_NAME "/tmp/server_fifo"
#define CLIENT_FIFO_NAME "/tmp/client_%d_fifo"

#define BUFFER_SIZE 20

struct data_to_pass_st {
    pid_t client_pid;
    char some_data[BUFFER_SIZE - 1];
}
