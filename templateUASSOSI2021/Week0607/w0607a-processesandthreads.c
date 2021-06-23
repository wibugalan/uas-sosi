#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "99-myutils.h"


#define T_REHAT 2000

int idmaster = 0;
int rPID, rPPID, id1000, offset=1000, n;

void* trit (void* a) {
   int id = idmaster++;
   for(;;){
    int detik = rehat_acak(T_REHAT);
    if (rPID-1000 < n){
    printf("PID[%04d] \t ThreadID[%04d] \t Delay(ms)[%04d] \n",rPID, id, detik);
    }
  }
}


int main(int argc, char * argv[])
{  
   int t, temp;
   id1000 = getpid(); 

   printf("Hello... \n");
   printf("Please input number of processes (N) : ");
   scanf("%d", &n);
   printf("Please input number of threads per process (T) : ");
   scanf("%d", &t);
   printf("The input N is : %d \n", n);
   printf("The input T is : %d \n", t);

   rPID=getpid()-id1000+offset;
   for (int i = 0; i < n-1; i++)
   {
      temp=fork();
      if(temp==0){
         rPID=getpid()-id1000+offset;
      }
      else{
         rPID=getpid()-id1000+offset;
      }
   }
   
   for (int i = 0; i < t-1; ++i)
   {
      daftar_trit(trit);
   }

   jalankan_trit();

   beberes_trit("Selesai...");
}
