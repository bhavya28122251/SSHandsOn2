/*
============================================================================
Name : 33_server.c
Author : Bhavya Joshi
Description : Write a program to communicate between two machines using socket.
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
	int sd,nsd,sz;
	struct sockaddr_in server,client;
	char buf[80];
	sd=socket(AF_UNIX,SOCK_STREAM,0);

	server.sin_family = AF_UNIX;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port=htons(5055);

	bind(sd,(void*)(&server),sizeof(server));
	listen(sd,5);
	sz=sizeof(client);
	nsd=accept(sd,(void*)(&client),&sz);
	read(nsd,buf,sizeof(buf));
	
	printf("Message from Client:%s\n",buf);
	write(nsd,"This is Server\n",16);

	return 0;

}

/*
============================================================================
Output:
============================================================================
*/
