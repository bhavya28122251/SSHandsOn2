/*
============================================================================
Name : 34a_server.c
Author : Bhavya Joshi
Description: Write a program to create a concurrent server.
a. use fork
Date: 21st Sept, 2024.
============================================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<sys/types.h>

int main(){

	int sd,nsd,sz;
	struct sockaddr_in server,client;
	char buf[80];
	sd=socket(AF_UNIX,SOCK_STREAM,0);

	server.sin_family=AF_UNIX;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(5080);

	bind(sd,(void*)(&server),sizeof(server));
	listen(sd,5);
	sz=sizeof(client);
	
	while(1){
		nsd=accept(sd,(void*)(&client),&sz);
		if(!(fork())){
			close(sd);
			read(nsd,buf,sizeof (buf));
			printf("Message from Client: %s\n",buf);
			write(nsd,"This is Server\n",14);
			exit(0);
		}
		else 
			close(nsd);
	}

	return 0;
}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 34a_server.c -o 34a_s_o
bhavya@Bhavya:~/SSHandOnList2$ ./34a_s_o
Message from Client: This is Client
Message from Client: This is Client


============================================================================
*/
