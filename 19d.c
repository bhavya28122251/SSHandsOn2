/*
============================================================================
Name : 19d.c
Author : Bhavya Joshi
Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 21st Sept, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	
	if (mknod("myfifo_d", S_IFIFO | 0666, 0) == -1) {
        	perror("Error in mknod");
        	return 1;
    	}

    	printf("FIFO file created by using mknod system call.\n");
    
	return 0;
}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 19d.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
FIFO file created by using mknod system call.

============================================================================
*/


