/*
============================================================================
Name : 34a_client.c
Author : Bhavya Joshi
Description : Write a program to create a concurrent server.
a. use fork
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <sys/types.h>

int main(){
	struct sockaddr_in server;
	int sd;
	char buf[80];
	sd=socket(AF_UNIX,SOCK_STREAM,0);

	server.sin_family=AF_UNIX;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(5080);
	
	connect(sd,(void*)(&server),sizeof(server));
	write(sd,"This is Client\n",14);
	read(sd,buf,sizeof(buf));
	printf("Message from Server: %s\n",buf);

	return 0;
}

/*
============================================================================
Output:
============================================================================
*/
