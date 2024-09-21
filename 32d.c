/*
============================================================================
Name : 32d.c
Author : Bhavya Joshi
Description : Write a program to implement semaphore to protect any critical section.
d. remove the created semaphore
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
	key_t key = ftok(".",'a');
	
	sem_id=semget(key,1,0);
	semctl(sem_id,0,IPC_RMID);\
	printf("Semeaphore Removed\n");
	return 0;

}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 32d.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Semeaphore Removed

============================================================================
*/
