/*
============================================================================
Name : 30a.c
Author : Bhavya Joshi
Description : Write a program to create a shared memory.
a. write some data to the shared memory
Date: 20th Sept, 2024.
============================================================================
*/

#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>

int main(){

	key_t key=ftok(".",30);
	int shm_id;
	char *text;

	shm_id=shmget(key,1024,IPC_CREAT|0666);

	text=shmat(shm_id,0,0);
	
	printf("Enter the text to be entered in Shared Memory\n");
	scanf("%[^\n]",text);
	
	printf("Text in the Shared memory: %s\n",text);
	
}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Enter the text to be entered in Shared Memory
This is Question 30a.
Text in the Shared memory: This is Question 30a.

============================================================================
*/
