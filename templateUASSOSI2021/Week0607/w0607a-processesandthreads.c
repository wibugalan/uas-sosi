#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "99-myutils.h"


#define T_REHAT 2000

int idmaster = 0;
int rPID, rPPID, id1000, offset=1000;

void* trit (void* a) {

}


int main(int argc, char * argv[])
{  
   int n, t, temp;
   id1000=getpid(); 

   printf("Hello... \n");
   printf("Please input number of processes (N) : ");
   scanf("%d", &n);
   printf("Please input number of threads per process (T) : ");
   scanf("%d", &t);
   printf("The input N is : %d \n", n);
   printf("The input T is : %d \n", t);


   beberes_trit("Selesai...");
}
