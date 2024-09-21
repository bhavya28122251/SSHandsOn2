/*
============================================================================
Name : 19c.c
Author : Bhavya Joshi
Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 21st Sept, 2024.
============================================================================
*/

/*
command: strace mknod myfifo p
output: mknodat(AT_FDCWD, "myfifo", S_IFIFO|0666)

command: strace mkfifo myfifo
outputL: mknodat(AT_FDCWD, "myfifo", S_IFIFO|0666)

Both mknod and  mkfifo ultimatelt rely on mknod() system call to create FIFO.

But mkfifo is better than mknod because it is specifically designed for creating FIFO's.

*/


