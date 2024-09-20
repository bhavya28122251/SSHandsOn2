/*
============================================================================
Name : 11.c
Author : Bhavya Joshi
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void fun_reset(int sig_num) {

        struct sigaction action_def;
    	
	action_def.sa_handler=SIG_DFL;  
    	sigemptyset(&action_def.sa_mask);
    	action_def.sa_flags = 0;

    	sigaction(SIGINT,&action_def,NULL);  

        raise(SIGINT);
}

int main() {

    	struct sigaction action_ignore, action_reset;

        action_ignore.sa_handler = SIG_IGN; 
 
	sigemptyset(&action_ignore.sa_mask);
    	action_ignore.sa_flags = 0;

    	sigaction(SIGINT,&action_ignore,NULL);  

    	printf("SIGINT is being ignored\n");
    	sleep(7);  

	action_reset.sa_handler=fun_reset;  
    	sigemptyset(&action_reset.sa_mask);
    	action_reset.sa_flags = 0;

    	sigaction(SIGINT,&action_reset,NULL); 

    	printf("SIGINT has been reset\n");

    
    	while(1){
        	pause();  
    	}

    	return 0;
}
/*
============================================================================
Output:
havya@Bhavya:~/SSHandOnList2$ ./a.out
SIGINT is being ignored
^C^C^C^C^C^C^CSIGINT has been reset
^C

============================================================================
*/
