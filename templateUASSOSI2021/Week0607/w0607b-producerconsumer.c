#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "99-myutils.h"

#define T_REHAT 2000

#define MYFLAGS     O_CREAT | O_RDWR
#define MYPROTECT PROT_READ | PROT_WRITE
#define MYVISIBILITY          MAP_SHARED 
#define SFILE             "demo-file.bin"

#define NN 4

typedef  struct {
   sem_t  buffmutex;
   int    buffsize;
   int    buffer[100];
} myshare;

myshare* mymap;
int idmaster=0;

void* producer (void* a) {

}


void* consumer (void* a) {

}

void* observer (void* a) {

}

int main(int argc, char * argv[])
{  

   daftar_trit(producer);
   daftar_trit(consumer);
   daftar_trit(observer);
   jalankan_trit();
   beberes_trit("Selesai...");

}
