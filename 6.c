/*
============================================================================
Name : 6.c
Author : Bhavya Joshi
Description : Write a simple program to create three threads. 
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_thread(void* t){
	int n= *((int*)t);
	printf("Thread %d\n",n);
	pthread_exit(NULL);
}

int main(){
	pthread_t th[3];
	int arr[3],k;  
	
	printf("Creating 3 threads\n");
	
	for(k=0;k<3;k++){
        	arr[k]=k+1;
         	pthread_create(&th[k],NULL,print_thread,&arr[k]);  
    	}

   
    	for(k=0;k<3;k++){
        	pthread_join(th[k],NULL);
     	}


    return 0;
}


/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 6.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Creating 3 threads
Thread 1
Thread 2
Thread 3

============================================================================
*/

