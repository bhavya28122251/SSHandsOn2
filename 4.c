/*
============================================================================
Name : 4.c
Author : Bhavya Joshi
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long rdtsc(){
	
	unsigned long long dst;
        __asm__ __volatile__("rdtsc":"=A"(dst));
        return dst;

}

int main(){

	int k ,total_time;
	unsigned long long int t_start,t_end;

	t_start=rdtsc();

	for(k=0;k<=100;k++)
        	getpid();
	
	t_end=rdtsc();
	
	total_time=(t_end-t_start)/0.23;
	printf("Total time taken to execute 100 getpid() is %d nsec\n",total_time);
	return 0;

}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 4.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Total time taken to execute 100 getpid() is 286000 nsec

============================================================================
*/
