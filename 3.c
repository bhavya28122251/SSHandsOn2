/*
============================================================================
Name : 3.c
Author : Bhavya Joshi
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 21st Sept, 2024.
============================================================================
*/
#include <err.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>

int main(){

	struct rlimit r_limit;
	
	if(getrlimit(RLIMIT_CPU,&r_limit)==-1)
		err(EXIT_FAILURE,"prlimit-1");

	printf("Current limits: soft=%jd; hard=%jd\n",(intmax_t)r_limit.rlim_cur,(intmax_t)r_limit.rlim_max);

	r_limit.rlim_cur = 8 * 1024 * 1024;
	r_limit.rlim_max = 16 * 1024 * 1024;

	if(setrlimit(RLIMIT_CPU,&r_limit)==-1)
		err(EXIT_FAILURE,"prlimit-2");

	printf("New limits: soft=%jd; hard=%jd\n",(intmax_t)r_limit.rlim_cur,(intmax_t)r_limit.rlim_max);

}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 3.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Current limits: soft=-1; hard=-1
New limits: soft=8388608; hard=16777216

============================================================================
*/
