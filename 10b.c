/*
============================================================================
Name : 10b.c
Author : Bhavya Joshi
Description : Write a separate program using sigaction system call to catch the following signals.
b. SIGINT 
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


void sig_handler(int sig_num) {
	printf("Signal SIGINT is Caught\n");
    	exit(1);
}

int main(){
	
	struct sigaction sig_action;
    
	memset(&sig_action,0,sizeof(sig_action));

    	sig_action.sa_handler=sig_handler;

	sigaction(SIGINT,&sig_action,NULL);

	while(1);
    	
  	return 0;
}


/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ ./a.out

^CSignal SIGINT is Caught

============================================================================
*/
