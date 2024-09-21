/*
============================================================================
Name : 22.c
Author : Bhavya Joshi
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main() {

    int fifo_fd;
    char buff[1024];
    fd_set read_fds;
    
    struct timeval time_out;
    int r;

    mkfifo("fifo_22", 0666);
    fifo_fd = open("fifo_22", O_RDONLY | O_NONBLOCK);

    FD_ZERO(&read_fds);
    FD_SET(fifo_fd, &read_fds);

    time_out.tv_sec = 10;
    time_out.tv_usec = 0;

    r = select(fifo_fd + 1, &read_fds, NULL, NULL, &time_out);

    if (r == -1) {
        perror("Error in select");
        close(fifo_fd);
        exit(EXIT_FAILURE);
    } 
    else if (r == 0) {
        printf("Timeout occurred!\n", 10);
    } 
    else {
        if (FD_ISSET(fifo_fd, &read_fds)) {
            ssize_t num_bytes = read(fifo_fd, buff, sizeof(buff) - 1);
            if (num_bytes > 0) {
                buff[num_bytes] = '\0'; 
                printf("Data read from FIFO: %s\n", buff);
            }  
	    else {
                printf("No data read from fifo or end of file reached\n");
            }
        }
    }

    close("fifo_22");

    return 0;
}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Data read from FIFO: This is question 22


============================================================================
*/

