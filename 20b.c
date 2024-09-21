/*
============================================================================
Name : 20b.c
Author : Bhavya Joshi
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
	
	char buff[100];
    	int fifo_fd = open("file_20", O_RDONLY);
    	
	if (fifo_fd == -1) {
		perror("Error in opening Fifo");
       		return 1;
    	}

    	read(fifo_fd, buff, sizeof(buff));
        printf("Message Received: %s", buff);

    	close(fifo_fd);
    	
	return 0;
}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 20b.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Message Received: This is Question 20

============================================================================
*/
