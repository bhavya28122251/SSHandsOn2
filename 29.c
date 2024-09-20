/*
============================================================================
Name : 29.c
Author : Bhavya Joshi
Description : Write a program to remove the message queue.
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main(){

        key_t key=ftok("file_29",12);
        if(key==-1){
                perror("Error in generating the Key\n");
                return 1;
        }

        int msg_id=msgget(key,IPC_CREAT|0744);
        if(msg_id==-1){
                perror("Error in generating the Message Queue id\n");
                return 1;
        }

	if(msgctl(msg_id,IPC_RMID,NULL)==-1){
		perror("Error in removing the message queue\n");
		return 1;
	}

	printf("Message Queue is removed\n");

	return 0;

}


/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 29.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Message Queue is removed

============================================================================
*/
