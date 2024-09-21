/*
============================================================================
Name : 8b.c 
Author : Bhavya Joshi
Description : Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
Date: 21st Sept, 2024.
============================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sigint(int sig){

        printf("Caught SIGINT Signal\n");
        exit(1);

}

int main(){

        __sighandler_t st;

        st = signal( SIGINT, (void*)handle_sigint );

        if( st == SIG_ERR){
                printf("There is an error while assigning Signal Handler");

        }

        else{
                raise(SIGINT);
        }

        return 0;

}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 8b.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Caught SIGINT Signal

============================================================================
*/

