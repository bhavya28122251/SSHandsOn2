/*
============================================================================
Name : 20a.c
Author : Bhavya Joshi
Description : Write two programs so that both can communicate by FIFO -Use one way communication. 
Date: 21st Sept, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <unistd.h>

int main() {

	char buff[50];
	mkfifo("file_20", 0666);
	
	int fd = open("file_20", O_WRONLY);
	printf("%d\n", fd);
	
	fgets(buff, 50,stdin);
	
	printf("%s\n",buff); 

	write(fd,buff,50);	
	close(fd);
	
	return 0;
}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ ./20a_output
This is Question 203

This is Question 20


============================================================================
*/

