/*
============================================================================
Name : 25.c
Author : Bhavya Joshi
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include<time.h>

int main(){

        struct msqid_ds mq_info;

	key_t key=ftok("file_25",12);
        if(key==-1){
                perror("Error in generating the Key\n");
                return 1;
        }

        int msg_id=msgget(key,IPC_CREAT|0744);
        if(msg_id==-1){
                perror("Error in generating the Message Queue id\n");
                return 1;
        }

	if(msgctl(msg_id,IPC_STAT,&mq_info)==-1){
		perror("Error in retieving Message Queue information");
		return 1;
	}

	printf("Access Permission: %o\n", mq_info.msg_perm.mode);

	printf("UID: %d, GID: %d\n", mq_info.msg_perm.uid, mq_info.msg_perm.gid); 

	printf("Time of last message sent: %s", ctime(&mq_info.msg_stime));

	printf("Time of last message received: %s", ctime(&mq_info.msg_rtime));

	printf("Time of last change in the message queue: %s", ctime(&mq_info.msg_ctime));

	printf("Size of the queue: %ld bytes\n", mq_info.__msg_cbytes);

	printf("Number of messages in the queue: %ld\n", mq_info.msg_qnum); 

	printf("Maximum number of bytes allowed in the queue: %ld\n", mq_info.msg_qbytes);

   	printf("PID of last msgsnd: %d\n", mq_info.msg_lspid);

    	printf("PID of last msgrcv: %d\n", mq_info.msg_lrpid);

        return 0;

}



/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Access Permission: 744
UID: 1000, GID: 1000
Time of last message sent: Thu Jan  1 05:30:00 1970
Time of last message received: Thu Jan  1 05:30:00 1970
Time of last change in the message queue: Fri Sep 20 01:43:14 2024
Size of the queue: 0 bytes
Number of messages in the queue: 0
Maximum number of bytes allowed in the queue: 16384
PID of last msgsnd: 0
PID of last msgrcv: 0

============================================================================
*/

