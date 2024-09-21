/*
============================================================================
Name : 13b.c
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

int main(){

	int p_id;

	printf("To send SIGSTOP, enter the PID of the process: ");
	scanf("%d", &p_id);

	if (kill(p_id, SIGSTOP) == 0) {
		printf("Process with PID %d has been sent SIGSTOP signal\n", p_id);
	}
	else{
		perror("Failed to send the SIGSTOP signal");
		exit(EXIT_FAILURE);
	}

	return 0;
}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 13b.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
To send SIGSTOP, enter the PID of the process: 66924
Process with PID 66924 has been sent SIGSTOP signal

============================================================================
*/

