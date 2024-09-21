/*
============================================================================
Name : 5.c
Author : Bhavya Joshi
Description :Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory. 
Date: 21st Sept, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main(){
	
	printf("Maximum length of the arguments to the exec family of functions: %ld\n",sysconf(_SC_ARG_MAX));

	printf("Maximum number of simultaneous process per user id : %ld\n",sysconf(_SC_CHILD_MAX));

	printf("Number of clock ticks (jiffy) per second : %ld\n",sysconf(_SC_CLK_TCK));

	printf("Maximum number of open files : %ld\n",sysconf(_SC_OPEN_MAX));

	printf("Size of a page : %ld bytes\n",sysconf(_SC_PAGESIZE));

	printf("Total number of pages in the physical memory : %ld\n",sysconf(_SC_PHYS_PAGES));

	printf("Number of  currently available pages in the physical memory :%ld\n",sysconf(_SC_AVPHYS_PAGES));

	return 0;

}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 5.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Maximum length of the arguments to the exec family of functions: 2097152
Maximum number of simultaneous process per user id : 30109
Number of clock ticks (jiffy) per second : 100
Maximum number of open files : 1024
Size of a page : 4096 bytes
Total number of pages in the physical memory : 1948040
Number of  currently available pages in the physical memory :374899

============================================================================
*/

