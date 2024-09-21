/*
============================================================================
Name : 23.c
Author : Bhavya Joshi
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 21st Sept, 2024.
============================================================================
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdio.h>

int main(){

	long max_files;  
	long size_pipe;

    	char *c = "fifo_23";
        mkfifo(c, S_IRWXU);

        max_files = sysconf(_SC_OPEN_MAX);

    	printf("Maximum number of files that can be opened: %ld\n", max_files);

    	printf("Max size of pipe: %d\n", PIPE_BUF);
    
	return 0;
}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 23.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Maximum number of files that can be opened: 1024
Max size of pipe: 4096

============================================================================
*/
