#include "client.h"
#include <ctype.h>

int main() {

    int server_fifo_fd, client_fifo_fd;
    struct data_to_pass_st my_data;
    int read_size;
    char client_fifo[256];
    char *tmp_char_ptr;


    if(access(SERVER_FIFO_NAME, F_OK) != 0) {
        if(mkfifo(SERVER_FIFO_NAME, 0777) != 0) {
            perror("make server_fifo failed");
            exit(EXIT_FAILURE);
        }
    }

    if(access(CLIENT_FIFO_NAME, F_OK) != 0) {
        if(mkfifo(CLIENT_FIFO_NAME, 0777) != 0) {
            perror("make client_fifo failed");
            exit(EXIT_FAILURE);
        }
    }    

    server_fifo_fd = open(SERVER_FIFO_NAME, O_RDONLY);
    if(server_fifo_fd == -1) {
        perror("open res_read failed");
        exit(EXIT_FAILURE);
    }

    printf("waiting for client please...\n");
    sleep(10);
    do {
        read_size = read(server_fifo_fd, &my_data, sizeof(my_data));
        if(read_size > 0) {
            printf("we got %d bytes from clinet\n", read_size);
            tmp_char_ptr = my_data.some_data;
            while(*tmp_char_ptr) {
               *tmp_char_ptr = toupper(*tmp_char_ptr);
                tmp_char_ptr++;
            }

            strncpy(my_data.some_data, tmp_char_ptr, strlen(tmp_char_ptr));
            sprintf(client_fifo, CLIENT_FIFO_NAME, my_data.client_pid);

            client_fifo_fd = open(client_fifo, O_WRONLY);
            if(client_fifo_fd != -1) {
                write(client_fifo_fd, &my_data, sizeof(my_data));
                close(client_fifo_fd);
            }
        }
    } while(read_size > 0);

    close(server_fifo_fd);
    unlink(SERVER_FIFO_NAME);
    exit(EXIT_SUCCESS);


}