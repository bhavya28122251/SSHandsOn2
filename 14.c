/*
============================================================================
Name : 14.c
Author : Bhavya Joshi
Description :  Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    
	int file_desc[2];
    	char write_msg[]="This is Question 14";
    	char read_msg[50];
    
 	printf("Creating the pipe\n");   
	pipe(file_desc);
    	
	printf("Writing to the pipe\n");
	write(file_desc[1],write_msg,strlen(write_msg));

    	printf("Reading from the pipe\n");
	read(file_desc[0],read_msg,sizeof(read_msg));
    	printf(" %s\n",read_msg);

    	close(file_desc[0]);
    	close(file_desc[1]);

    return 0;
}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Creating the pipe
Writing to the pipe
Reading from the pipe
 This is Question 14

============================================================================
*/

