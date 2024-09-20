/*
============================================================================
Name : 30a.c
Author : Bhavya Joshi
Description : Write a program to create a shared memory.
a. write some data to the shared memory
Date: 20th Sept, 2024.
============================================================================
*/

#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>

int main(){

	int key,shmid;
	char *text;
	
	int key = ftok(".",'c');
shmid=shmget(key,1024,IPC_CREAT|0744);
data =shmat(shmid,0,0);
printf("enter text:");
scanf("%[^\n]",data);
printf("data from shared memory : %s\n", data);
}
/*
============================================================================
Output:
============================================================================
*/
