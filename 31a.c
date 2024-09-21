/*
============================================================================
Name : 31a.c
Author : Bhavya Joshi
Description : Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore 
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/sem.h>
#include <unistd.h>

union semun {
	
	int value;
	struct semid_ds *buffer;
	unsigned short int *arr;
};

int main(){
	union semun s;
	int sem_id;
	
	key_t key = ftok(".",'a');
	
	sem_id=semget(key,1,IPC_CREAT|0666);
	
	s.value=1;
	semctl(sem_id,0,SETVAL,s);
	
	printf("Semaphore is created and value is initialized to the semaphore\n");
	
	getchar();

	return 0;


}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 31a.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Semaphore is created and value is initialized to the semaphore
^C

============================================================================
*/
