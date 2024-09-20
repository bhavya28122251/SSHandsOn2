/*
============================================================================
Name : 12.c
Author : Bhavya Joshi
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main(){
    
	pid_t p_id = fork();  

    	if(p_id==0){
        
		printf("Child process with PID: %d\n",getpid());
        	printf("Parent process with PID: %d\n",getppid());
        	
		printf("Sending SIGKILL signal to Parent Process\n");
		kill(getppid(),SIGKILL);

		sleep(7);

        	printf("Child process with PID %d is now Orphan\n",getpid());
		printf("New Parent PID id %d\n",getppid());
           
    	}

	else{
     
        	printf("Parent Process with PID %d is alive\n",getpid());
		printf("Parent Process is waiting for signal from Child Process\n");
        	
		sleep(13); 
    	}

    	return 0;
}

/*
============================================================================
Output:
\bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Parent Process with PID 15641 is alive
Parent Process is waiting for signal from Child Process
Child process with PID: 15642
Parent process with PID: 15641
Sending SIGKILL signal to Parent Process
Killed
bhavya@Bhavya:~/SSHandOnList2$ Child process with PID 15642 is now Orphan
New Parent PID id 1600

============================================================================
*/
