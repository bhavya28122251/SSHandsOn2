/*
============================================================================
Name : 32b.c
Author : Bhavya Joshi
Description :  Write a program to implement semaphore to protect any critical section.
b. protect shared memory from concurrent write access 
Date: 21st Sept, 2024.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>

int main(){
	
	int shm_key,shm_id,sem_key,sem_id;
	char *text;

	shm_key=ftok(".",'d');
	shm_id=shmget(shm_key,1024,IPC_CREAT|0744);
	text=shmat(shm_id,0,0);
	sem_key=ftok(".",'e');
	sem_id=(sem_key,1,0);

	struct sembuf buff={0,-1,0};

	sem_id=semget(sem_key,1,0);
	semop(sem_id,&buff,1);

	printf("Entered Critical Section\n");
	printf("Enter Text:\n");
	scanf("%[^\n]",text);
	
	printf("Data in the Shared Memory: %s\n",text);

	printf("Press Enter to Exit CS\n");
	getchar();
	buff.sem_op=1;
	semop(sem_id,&buff,1);

	printf("Exited CS\n");

	return 0;

}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 32b.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Entered Critical Section
Enter Text:
This is Question 32b
Data in the Shared Memory: This is Question 32b
Press Enter to Exit CS
Exited CS

============================================================================
*/
