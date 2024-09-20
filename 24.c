/*
============================================================================
Name : 24.c
Author : Bhavya Joshi
Description : Write a program to create a message queue and print the key and message queue id.
Date: 19th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main(){

	key_t key=ftok("file_24",12);
	if(key==-1){
		perror("Error in generating the Key\n");
		return 1;
	}

	int msg_id=msgget(key,IPC_CREAT|0744);
	if(msg_id==-1){
                perror("Error in generating the Message Queue id\n");
                return 1;
        }

	
	printf("The Message Queue is created\n");
	
	printf("Key:%d\n",key);
	printf("Message Queue id:%d\n",msg_id);

	return 0;

}

		
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 24.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
The Message Queue is created
Key:201869349
Message Queue id:1

============================================================================
*/
