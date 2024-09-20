/*
============================================================================
Name : 10a.c
Author : Bhavya Joshi
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


void sig_handler(int sig_num) {
	printf("Signal Segmentation Fault is caught\n");
    	exit(1);
}

int main(){
	
	struct sigaction sig_action;
    
	memset(&sig_action,0,sizeof(sig_action));

    	sig_action.sa_handler=sig_handler;

	sigaction(SIGSEGV,&sig_action,NULL);

	int* p=NULL;
    	
	*p=10;

    	return 0;
}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Signal Segmentation Fault is caught

============================================================================
*/
