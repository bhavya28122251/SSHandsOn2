/*
============================================================================
Name : 18.c
Author : Bhavya Joshi
Description : Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 21st Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int pipe1[2], pipe2[2];
	pid_t p_id1, p_id2;

	if (pipe(pipe1) == -1){
		perror("Error Pipe1\n");
		exit(EXIT_FAILURE);
	}

	p_id1 = fork();
	if (p_id1 == -1){
		perror("Error Fork1");
		exit(EXIT_FAILURE);
	}

	if (p_id1 == 0) {
		dup2(pipe1[1], STDOUT_FILENO);
		close(pipe1[0]); 
		close(pipe1[1]); 
		execlp("ls", "ls", "-l", NULL);
		perror("Error in execlp ls");  
		exit(EXIT_FAILURE);
	}

	if (pipe(pipe2) == -1) {
		perror("Error in Pipe2");
		exit(EXIT_FAILURE);
	}

	p_id2 = fork();
	if (p_id2 == -1) {
		perror("Error Fork2");
   		exit(EXIT_FAILURE);
	}

	if (p_id2 == 0) {
		dup2(pipe1[0], STDIN_FILENO);
		close(pipe1[1]); 
		close(pipe1[0]); 
		dup2(pipe2[1], STDOUT_FILENO);
		close(pipe2[0]); 
		close(pipe2[1]);  

		execlp("grep", "grep", "^d", NULL);
		perror("Error execlp grep"); 
		exit(EXIT_FAILURE);
	}

	close(pipe1[0]); 
	close(pipe1[1]);
	close(pipe2[1]);  
	dup2(pipe2[0], STDIN_FILENO);
	close(pipe2[0]); 
	execlp("wc", "wc", "-l", NULL);
	perror("Error execlp wc");
	exit(EXIT_FAILURE);
}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 18.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
0

============================================================================
*/
