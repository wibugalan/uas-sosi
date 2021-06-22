#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "99-myutils.h"



void* T1 (void* a) {

}


void* T2 (void* a) {

}


void* T3 (void* a) {

}

void* T4 (void* a) {

}

int main(int argc, char * argv[])
{

   daftar_trit(T1);
   daftar_trit(T2);
   daftar_trit(T3);
   daftar_trit(T4);

   jalankan_trit();
   beberes_trit("Selesai...");
}
