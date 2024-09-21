/*
============================================================================
Name : 19a.c
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

#include <stdio.h>
#include <stdlib.h>

int main(){

	int a = system("mknod myfifo_a p");
	if (a == -1) {
		perror("Error in mknod\n");
		return 1;
	}

        printf("FIFO file is created by using mknod command.\n");

	return 0;
}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 19a.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
FIFO file is created by using mknod command.

============================================================================
*/
