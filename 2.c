/*
============================================================================
Name : 2.c
Author : Bhavya Joshi
Description : Write a program to print the system resource limits. Use getrlimit system call.
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
	
	if (getrlimit(RLIMIT_CPU,&r_limit)==-1)
	       err(EXIT_FAILURE,"prlimit-1");

	printf("System Resource Limits: soft=%jd, hard=%jd\n",(intmax_t)r_limit.rlim_cur,(intmax_t) r_limit.rlim_max);

	return 0;
}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 2.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
System Resource Limits: soft=-1, hard=-1

============================================================================
*/
