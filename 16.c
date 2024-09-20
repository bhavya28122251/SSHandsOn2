/*
============================================================================
Name : 16.c
Author : Bhavya Joshi
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication. 
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
	int pipe1_fd[2];
    	int pipe2_fd[2];

   	char p_msg[]="This is Parent";
    	char c_msg[] ="This is child";
    	char read_msg[50];

    	pipe(pipe1_fd);
    	pipe(pipe2_fd);

    	pid_t p_id = fork();

    	if(p_id>0){
        	close(pipe1_fd[0]);
        	close(pipe2_fd[1]);

        	write(pipe1_fd[1],p_msg,strlen(p_msg));
	
		close(pipe1_fd[1]);
        	read(pipe2_fd[0],read_msg,sizeof(read_msg));
        	printf("Message received by Parent: %s\n",read_msg);
        	close(pipe2_fd[0]);

    	} 

	else{
        	close(pipe1_fd[1]);
       		close(pipe2_fd[0]);

        	read(pipe1_fd[0],read_msg,sizeof(read_msg));
       		printf("Message received by Child: %s\n",read_msg);

		close(pipe1_fd[0]);
        	write(pipe2_fd[1],c_msg,strlen(c_msg));
        	close(pipe2_fd[1]);
    	}

    	return 0;
}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Message received by Child: This is Parent
Message received by Parent: This is child

============================================================================
*/

