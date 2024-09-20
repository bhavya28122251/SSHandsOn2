/*
============================================================================
Name : 1c.c
Author : Bhavya Joshi
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
c. ITIMER_PROF
Date: 21st Sept, 2024.
============================================================================
*/


#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void sig_handler(int sig_num){
        printf("Timer expired in 10sec and 10msec interval and signal number is %d\n",sig_num);
}

int main(){

        signal(SIGPROF,sig_handler);
        
	struct timeval inter;
        inter.tv_sec=10;
        inter.tv_usec=10;

        struct timeval val;
        val.tv_sec=10;
        val.tv_usec=10;

        struct itimerval newVal;
        newVal.it_interval=inter;
        newVal.it_value=val;

        int timer=setitimer(ITIMER_PROF,&newVal,NULL);
        sleep(7);

        while (1) {}

        return 0;
}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandOnList2$ cc 1c.c
bhavya@Bhavya:~/SSHandOnList2$ ./a.out
Timer expired in 10sec and 10msec interval and signal number is 27
Timer expired in 10sec and 10msec interval and signal number is 27
^C

============================================================================
*/
