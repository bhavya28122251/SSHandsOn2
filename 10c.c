/*
============================================================================
Name : 10c.c
Author : Bhavya Joshi
Description : Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE 
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


void sig_handler(int sig_num) {
        printf("Floating Point Exception is caught\n");
        exit(1);
}

int main(){

        struct sigaction sig_action;
    
        memset(&sig_action,0,sizeof(sig_action));

        sig_action.sa_handler=sig_handler;

        sigaction(SIGFPE,&sig_action,NULL);

	int a=20;
	int b=0;
	int c=a/b;

        return 0;
}


/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Floating Point Exception is caught

============================================================================
*/

