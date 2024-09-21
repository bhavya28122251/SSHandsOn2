/*
============================================================================
Name : 13a.c
Author : Bhavya Joshi
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void handle_sigstop(int sg) {
	printf("Catch SIGSTOP Signal\n");
}

int main(){

	if (signal(SIGSTOP, handle_sigstop) == SIG_ERR) {
		printf("SIGSTOP signal is not catched\n");
	}

	printf("Process with PID: %d is Running\n",getpid());

	while (1){
		printf("%d is Running\n",getpid());
		sleep(2);
	}

        return 0;
}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 13a.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
SIGSTOP signal is not catched
Process with PID: 66924 is Running
66924 is Running
66924 is Running
66924 is Running
66924 is Running
66924 is Running
66924 is Running

[1]+  Stopped                 ./a.out

============================================================================
*/

