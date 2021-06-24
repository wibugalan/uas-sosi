#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main(void) {

   int rPID, rPPID, id1000=getpid(), offset=1000;

   rPID=getpid()-id1000+offset;
   rPPID=getppid()-id1000+offset;
   if (rPPID < 1000 || rPPID > rPID) rPPID=999;
   if(fork() == 0){
//      1001
                rPID=getpid()-id1000+offset;
                rPPID=getppid()-id1000+offset;
                printf("PID[%d] \t PPID[%4d]\n",rPID,rPPID);
                if(fork() == 0){
//      1002
                        rPID=getpid()-id1000+offset;
                        rPPID=getppid()-id1000+offset;
                        printf("PID[%d] \t PPID[%4d]\n",rPID,rPPID);
                        if(fork() == 0){
//      1002                    
                                if(fork() == 0){
                                        rPID=getpid()-id1000+offset;
                                        rPPID=getppid()-id1000+offset;
                                        printf("PID[%d] \t PPID[%4d]\n",rPID,rPPID);
                                }
                                
                        }

                }
                else{
                        if(fork() == 0){
        //      1003
                        rPID=getpid()-id1000+offset;
                        rPPID=getppid()-id1000+offset;

                        printf("PID[%d] \t PPID[%4d]\n",rPID,rPPID);
                                

                        }
                }
   }
   else{
        wait(NULL);
//1000

        if(fork()==0){
                if(fork()==0){
//1005
                        rPID=getpid()-id1000+offset;
                        rPPID=getppid()-id1000+offset;
                        printf("PID[%d] \t PPID[%4d]\n",rPID,rPPID);
                }
                else{
//1004
                        wait(NULL);
                        rPID=getpid()-id1000+offset;
                        rPPID=getppid()-id1000+offset;
                        printf("PID[%d] \t PPID[%4d]\n",rPID,rPPID);
                        if(fork()==0){
//1006
                                rPID=getpid()-id1000+offset;
                                rPPID=getppid()-id1000+offset;
                                printf("PID[%d] \t PPID[%4d]\n",rPID
,rPPID);

}
                }
        }
        else{
                wait(NULL);
//1000
        printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
        if(fork()==0){
                if(fork()==0){
//1005
                        rPID=getpid()-id1000+offset;
                        rPPID=getppid()-id1000+offset;
                        printf("PID[%d] \t PPID[%4d]\n",rPID,rPPID);
                }
                else{
//1004
                        wait(NULL);
                        rPID=getpid()-id1000+offset;
                        rPPID=getppid()-id1000+offset;
                        printf("PID[%d] \t PPID[%4d]\n",rPID,rPPID);
                        if(fork()==0){
//1006
                                rPID=getpid()-id1000+offset;
                                rPPID=getppid()-id1000+offset;
                                printf("PID[%d] \t PPID[%4d]\n",rPID
,rPPID);

}
                }
        }
        
}
   }
   fflush(NULL);
   return;
}
