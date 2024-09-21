/*
============================================================================
Name : 34b_server.c
Author : Bhavya Joshi
Description : Write a program to create a concurrent server.
b. use pthread_create
Date: 21st Sept, 2024.
============================================================================
*/

#include <netinet/in.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void handle_client(void *nsd,void *sd){

	char buf[80];
	close(sd);
	
	read(nsd,buf,sizeof(buf));
	printf("Message from client: %s\n",buf);
	write(nsd,"This is server\n",14);
}

int main(){
	int sd,nsd,sz;
	struct sockaddr_in server, client;
	char buf[80];
	sd = socket (AF_UNIX, SOCK_STREAM, 0);

	server.sin_family = AF_UNIX;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons (8080);

	bind (sd, (void*)(&server), sizeof (server));
	listen (sd, 5);
	printf("Server is Listening\n");
	
	sz=sizeof(client);
	while(1){
		nsd = accept (sd,(void*)( &client), &sz);

		pthread_t threadID;
   		(pthread_create(&threadID, NULL, (void *)handle_client, (&nsd,&sd)));
	}
	close(nsd);

}


/*
============================================================================
Output:
============================================================================
*/
