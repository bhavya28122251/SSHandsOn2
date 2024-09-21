/*
============================================================================
Name : 17a.c
Author : Bhavya Joshi
Description :Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl 
Date: 21st Sept, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>

int main(){
	int pipe_fd[2];
	pid_t c_id;

	if(pipe(pipe_fd)==-1){
		perror("ERROR in creating pipe\n");
	}

	else{
		c_id=fork();
		if(c_id==0){
			close(0);
			dup(pipe_fd[0]);
			close(pipe_fd[1]);
			execl("/usr/bin/wc", "wc", NULL);
		}
		
		else{
			close(1); 
			dup(pipe_fd[1]);
			close(pipe_fd[0]);

			execl("/usr/bin/ls", "ls -l", "-l", NULL);
		}
	}
}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 17a.c 
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
     64     568    3306

============================================================================
*/

