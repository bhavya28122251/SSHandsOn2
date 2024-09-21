/*
============================================================================
Name : 32a.c
Author : Bhavya Joshi
Description :  Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore 
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <fcntl.h>

int main(){
	
	struct{
		int t_no;
	}db;

	int file_desc,sem_id;
	key_t key=ftok(".",'a');

	sem_id=(key,1,0);
	struct sembuf buff={0,-1,0};
	sem_id=semget(key,1,0);

	file_desc=open("db",O_RDWR);
	read(file_desc,&db,sizeof(db));

	printf("Before Entering CS\n");

	semop(sem_id,&buff,1);
	printf("Inside CS\n");
	printf("Current Tickect no.: %d\n",db.t_no);
	db.t_no ++;
	lseek(file_desc,0L,SEEK_SET);
	write(file_desc,&db,sizeof(db));
	printf("New Ticket no: %d\n",db.t_no);
	printf("Press Enter to exit CS\n");
	getchar();
	
	buff.sem_op=1;
	semop(sem_id,&buff,1);
	printf("Exited cs\n");

	return 0;
}

/*
============================================================================
Output:
havya@Bhavya:~/SSHandOnList2$ cc 32a.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Before Entering CS
Inside CS
Current Tickect no.: 0
New Tiecket no: 1
Press Enter to exit CS

Exited cs

============================================================================
*/

