/*
============================================================================
Name : 15.c
Author : Bhavya Joshi
Description : Write a simple program to send some data from parent to the child process. 
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
	
	int file_desc[2];
        char write_msg[]="This is Question 15";
        char read_msg[50];
   
    	pipe(file_desc);

	pid_t p_id=fork();
   
	if(p_id>0){
        	close(file_desc[0]);
        	write(file_desc[1],write_msg,strlen(write_msg));
		printf("Parent has send data to Child process\n");
        	close(file_desc[1]);
    	}

	else{
        	close(file_desc[1]);
        	read(file_desc[0],read_msg,sizeof(read_msg));
        	printf("Child has received data from parent\n");
		printf("Data is: %s\n",read_msg);
        	close(file_desc[0]);
    	}

    	return 0;
}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Parent has send data to Child process
Child has received data from parent
Data is: This is Question 15

============================================================================
*/

