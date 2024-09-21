/*
============================================================================
Name : 32b_sem.c
Author : Bhavya Joshi
Description : Write a program to implement semaphore to protect any critical section.
b. protect shared memory from concurrent write access
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/sem.h>
#include <unistd.h>

union semun{
	int value;
	struct semid_ds *buff;
	unsigned short int *arr;
};

int main(){
	union semun s;
	int sem_id;

	key_t key=ftok(".",'e');
	
	sem_id=semget(key,1,IPC_CREAT|0644);
	s.value=1;
	semctl(sem_id,0,SETVAL,s);

	return 0;
}
/*
============================================================================
Output:
============================================================================
*/
