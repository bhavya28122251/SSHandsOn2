/*
============================================================================
Name : 7.c
Author : Bhavya Joshi
Description : Write a simple program to print the created thread ids. 
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_func(void* t){

	int n= *((int*)t);

	pthread_t th_id=pthread_self();
	printf("The created thread id is %lu\n",th_id);

	return NULL;
}

int main(){

	pthread_t th[3];
	int arr[3];

	for(int k=0;k<3;k++){
		arr[k]=k+1;
		pthread_create(&th[k],NULL,thread_func,&arr[k]);
	}

	for(int k=0;k<3;k++){
		pthread_join(th[k],NULL);
	}

	return 0;

}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 7.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
The created thread id is 140205587691200
The created thread id is 140205579298496
The created thread id is 140205570905792

============================================================================
*/
