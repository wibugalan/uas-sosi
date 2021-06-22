#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "99-myutils.h"


#define T_REHAT 2000

int idmaster = 0;
int sharedInt = 0;


void* adder (void* a) {

}


void* substractor (void* a) {

}


void* observer (void* a) {
	
}

int main(int argc, char * argv[])
{  
   int n;


   printf("Hello... \n");
   printf("Please input a positive number (N) : ");
   scanf("%d", &n);
   printf("The input N is : %d \n", n);

   daftar_trit(adder);
   daftar_trit(substractor);
   daftar_trit(observer);


   jalankan_trit();
   beberes_trit("Selesai...");
}
