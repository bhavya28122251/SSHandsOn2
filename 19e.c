/*
============================================================================
Name : 19e.c
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
#include <stdio.h>

int main() {
	
	if (mkfifo("myfifo_e", 0666) == -1) {
        	perror("Error in mkfifo");
        	return 1;
    }

    printf("FIFO file is created by using mkfifo library function\n");
    return 0;
}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 19e.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
FIFO file is created by using mkfifo library function

============================================================================
*/


