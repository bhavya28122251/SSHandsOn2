/*
============================================================================
Name : 30b.c
Author : Bhavya Joshi
Description : Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite. 
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

        text=shmat(shm_id,0,SHM_RDONLY);

        printf("Enter the text to be entered in Shared Memory\n");
        scanf("%[^\n]",text);

        printf("Text in the Shared memory: %s\n",text);

}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Enter the text to be entered in Shared Memory
This is Question 30b              
Segmentation fault (core dumped)

============================================================================
*/
