/*
============================================================================
Name : 30d.c
Author : Bhavya Joshi
Description : Write a program to create a shared memory.
d. remove the shared memory
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

        printf("Shared Memory is Attached\n");
	printf("Press Enter to remove Shared Memory\n");
	getchar();
	
	shmctl(key,IPC_RMID,NULL);
        printf("Shared Memory is removed\n");

}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Shared Memory is Attached
Press Enter to remove Shared Memory

Shared Memory is removed

============================================================================
*/
