
/*
============================================================================
Name : 27b.c
Author : Bhavya Joshi
Description :Write a program to receive messages from the message queue.
b. with IPC_NOWAIT as a flag
Date: 20th Sept, 2024.
============================================================================
*/

#include <errno.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

struct mg_info{
        long msg_type;
        char msg_text[50];
}my_msg;

int main(){

        key_t key=ftok("file_26",12);
        if(key==-1){
                perror("Error in generating the Key\n");
                return 1;
        }

        int msg_id=msgget(key,IPC_CREAT|0744);
        if(msg_id==-1){
                perror("Error in generating the Message Queue id\n");
                return 1;
        }


        if((msgrcv(msg_id,&my_msg,sizeof(my_msg.msg_text),1,IPC_NOWAIT))==-1){
		
		if (errno == ENOMSG)
			printf("There is no message of type 1\n");
       		else 
            		perror("There is an error in receiving message\n");
    		 
		return 1;
        }

        printf("The received message is: %s\n",my_msg.msg_text); 

        return 0;

}


/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 27b.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
The received message is: This is message of type 1

bhavya@Bhavya:~/SSHandOnList2$ cc 27b.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
There is no message of type 1

============================================================================
*/
