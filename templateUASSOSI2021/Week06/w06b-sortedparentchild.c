#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main(void) {

  int rPID, rPID1, rPPID, id1000=getpid(), offset=1000, temp, temp2, temp3, temp4, temp5, temp6;
  
  
  if(fork()>0){//999
      rPID=getpid()-id1000+offset;
      rPPID=getppid()-id1000+offset;
      if (rPPID < 1000 || rPPID > rPID) rPPID=999;
      sleep(9);
      printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
      fflush(NULL);
      }else{
         if(fork()>0){//1000
             if(fork()>0){//1001
                 rPID=getpid()-id1000+offset;
                 rPPID=getppid()-id1000+offset;
                 sleep(8);
                 printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
             }else{
                if(fork()>0){
                    if(fork()>0){
                        rPID=getpid()-id1000+offset;
                        rPPID=getppid()-id1000+offset;
                        sleep(6);
                        printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
                      }else{
                        if(fork()>0){
                            if(fork()>0){
                                rPID=getpid()-id1000+offset;
                                rPPID=getppid()-id1000+offset;
                                sleep(4);
                                printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);   
                            }else{
                               if(fork()>0){
                                    if(fork()>0){
                                        rPID=getpid()-id1000+offset;
                                        rPPID=getppid()-id1000+offset;
                                        sleep(2);
                                        printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);    
                                    }else{
                                        if(fork()>0){
                                            if(fork()>0){
                                                rPID=getpid()-id1000+offset;
                                                rPPID=getppid()-id1000+offset;
                                                printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);   
                                            }
                                        }else{
                                              rPID=getpid()-id1000+offset;
                                             rPPID=getppid()-id1000+offset;
                                             printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
                                        }
                                    }
                               }else{
                                 rPID=getpid()-id1000+offset;
                                rPPID=getppid()-id1000+offset;
                                sleep(1);
                                printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
                               }
                            }
                         }else{
                             rPID=getpid()-id1000+offset;
                            rPPID=getppid()-id1000+offset;
                            sleep(3);
                            printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
                         } 
                      }
                 }else{
                     rPID=getpid()-id1000+offset;
                    rPPID=getppid()-id1000+offset;
                    sleep(5);
                    printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID); 
                 }
             }
         }else{
            rPID=getpid()-id1000+offset;
            rPPID=getppid()-id1000+offset;
            sleep(7);
            printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);  
         }
    }
}
              
    
       
              