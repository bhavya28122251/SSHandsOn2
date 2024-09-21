/*
============================================================================
Name : 8f.c 
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

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void handle_sigvtalrm(){

    printf("Caught SIGVTALRM signal\n");
    _exit(0);
}

void main()
{
    __sighandler_t st;
    struct itimerval timer;
    
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 0;
   
    int timer_stat = setitimer(ITIMER_VIRTUAL, &timer, 0);
    if (timer_stat == -1)
        perror("There is an Error while setting an interval timer\n");
    
    st = signal(SIGVTALRM, (void *)handle_sigvtalrm);
    
    if (st == SIG_ERR){
        perror("There is an error while assigning Signal Handler!");
    }
    else{
        while (1);
    }
}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 8f.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Caught SIGVTALRM signal

============================================================================
*/

