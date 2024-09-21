/*
============================================================================
Name : 9.c
Author : Bhavya Joshi
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signalint_handler(int sg){
	printf("Received SIGINT Signal\n");
}

int main(){

	signal(SIGINT,SIG_IGN);	
	printf("Ignoring SIGINT\n");

	sleep(5);

	signal(SIGINT,SIG_DFL);
	printf("SIGINT is Reset\n");

	sleep(5);

	return 0;

}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 9.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Ignoring SIGINT
^C^C^C^C^CSIGINT is Reset
^C

============================================================================
*/

