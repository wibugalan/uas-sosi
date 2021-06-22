#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main(void) {

   int rPID, rPPID, id1000=getpid(), offset=1000;

   rPID=getpid()-id1000+offset;
   rPPID=getppid()-id1000+offset;
   if (rPPID < 1000 || rPPID > rPID) rPPID=999;
   printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
   fflush(NULL);
}
