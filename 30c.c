/*
============================================================================
Name : 30c.c
Author : Bhavya Joshi
Description : Write a program to create a shared memory.
c. detach the shared memory 
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

        printf("Shared Memory is Atteched\n");
	printf("Press Enter\n");
	getchar();
	
	shmdt(text);
        printf("The pointer is Detatched from Shared Memory\n");

}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Shared Memory is Atteched
Press Enter

The pointer is Detatched from Shared Memory

============================================================================
*/
