/*
============================================================================
Name : 34b_client.c
Author : Bhavya Joshi
Description : Write a program to create a concurrent server.
b. use pthread_create
Date: 21st Sept, 2024.
============================================================================
*/

#include<stdio.h>
#include <errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<sys/types.h>
int main(){
	struct sockaddr_in server;
	int sd;
	char buff[80];

	sd = socket (AF_UNIX, SOCK_STREAM, 0);

	server.sin_family = AF_UNIX;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons (8080);
	
	connect (sd,(void*)( &server),sizeof (server));
	int a = write(sd,"This is Client\n",14);
	printf("%d",a);
	
	if (a < 0) {
		perror("There is an ERROR in writing to the Socket");
	}        
	
	read(sd,buf,sizeof (buf));
	printf("Message from Server: %s\n",buf);
	
	return 0;
}
/*
============================================================================
Output:
============================================================================
*/

