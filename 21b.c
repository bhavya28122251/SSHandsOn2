/*
============================================================================
Name : 21b.c
Author : Bhavya Joshi
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {

        char buff[50];

        mkfifo("fifo_21_1", 0666);
        mkfifo("fifo_21_2", 0666);

        int w_fd = open("fifo_21_b", O_WRONLY);
        int r_fd = open("fifo_21_a", O_RDONLY);

        while (1) {

		read(r_fd,buff,sizeof(buff));

                printf("User 1: %s ",buff);

                if (strncmp(buff, "exit", 4) == 0) {
                         break;
                }

                printf("User 2 Enter a messag: ");
		
		fgets(buff, sizeof(buff), stdin);
	        write(w_fd, buff, strlen(buff) + 1);


                if (strncmp(buff, "exit", 4) == 0) {
                        break;
                }
        }

        close(w_fd);
        close(r_fd);
        return 0;
}
/*
============================================================================
Output:
============================================================================
*/

