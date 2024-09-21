/*
============================================================================
Name : 32c.c
Author : Bhavya Joshi
Description : Write a program to implement semaphore to protect any critical section.
c. protect multiple pseudo resources ( may be two) using counting semaphore 
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

	shm_key=ftok(".",34);
	shm_id=shmget(shm_key,1024,IPC_CREAT|0744);
	text =shmat(shm_id,0,0);
	sem_key=ftok(".",33);
	sem_id=(sem_key,1,0);
	
	struct sembuf buff={0,-1,0};
	sem_id=semget(sem_key,1,0);
	semop(sem_id,&buff,1);

	printf("Inside Critical Section\n");
	printf("Enter Text:");
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
bhavya@Bhavya:~/SSHandOnList2$ cc 32c.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Inside Critical Section
Enter Text:This is Q 32c
Data in the Shared Memory: This is Q 32c
Press Enter to Exit CS
Exited CS

============================================================================
*/
