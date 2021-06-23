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
int idmaster=1;
int rr = 0;

void* producer (void* a) {
   int id;
   sem_wait (&mutex);
   id = idmaster++;
   sem_post (&mutex);

	for(;;){
		rehat_acak(T_REHAT);
		int random= (rand()%999)+1;
		sem_wait (&(mymap->buffmutex));

		mymap->buffsize = mymap->buffsize + 1; 
      	if ((mymap->buffsize)>99){
        	mymap->buffsize = 0;
      	}
      	(mymap->buffer)[mymap->buffsize - 1] = random;
         rr = random;
		printf("PID[%4.4d] \t Thread[%4.4d] \t PRODUCE %3.3d \t BUFFERSIZE [%4.4d]\n", 
			getpid(),id,random,mymap->buffsize);

		sem_post (&(mymap->buffmutex));
	}
}


void* consumer (void* a) {
   int id;
   sem_wait (&mutex);
   id = idmaster++;
   sem_post (&mutex);

	for(;;){
		while((mymap->buffsize)<=0){
			sleep(1);
		}
		rehat_acak(T_REHAT);
		int random= (rand()%999)+1;
      rr = random;
		sem_wait (&(mymap->buffmutex));

		(mymap->buffer)[mymap->buffsize - 1] = 0;
		mymap->buffsize = mymap->buffsize - 1;
		printf("PID[%4.4d] \t Thread[%4.4d] \t CONSUME %3.3d \t BUFFERSIZE [%4.4d]\n", 
			getpid(),id, random, mymap->buffsize);

		sem_post (&(mymap->buffmutex));
	}
}

void* observer (void* a) {
   int id;
   sem_wait (&mutex);
   id = idmaster++;
   sem_post (&mutex);

	for(;;){
		while((mymap->buffsize)<=0){
			sleep(1);
		}
		rehat_acak(T_REHAT);
		int random= (rand()%999)+1;
		sem_wait (&(mymap->buffmutex));

		(mymap->buffer)[mymap->buffsize] = 0;
		mymap->buffsize = mymap->buffsize - 1;
		printf("PID[%4.4d] \t Thread[%4.4d] \t OBSERVE %3.3d \t BUFFERSIZE [%4.4d]\n", 
			getpid(),id, rr, mymap->buffsize);

		sem_post (&(mymap->buffmutex));
	}
}

int main(int argc, char * argv[])
{  

   sem_init (&mutex,  0, 1);

	int fd = open(SFILE,MYFLAGS,S_IRWXU);
   	int ssize = sizeof(myshare);
   	truncate(SFILE, ssize);
   	mymap=mmap(NULL, ssize, MYPROTECT, MYVISIBILITY, fd, 0);
   	mymap-> buffsize = 0;
   	sem_init (&(mymap->buffmutex), 0, 1);

	pid_t process = fork();
	if (process>0){
		if (process>0) {
			for (int i = 0; i < NN; ++i){
				daftar_trit(producer);
			}
		}
		else {
			for (int i = 0; i < NN-2; ++i){
				daftar_trit(observer);
			}
		}
		
	}else{
		for (int i = 0; i < NN; ++i){
			daftar_trit(consumer);
		}
	}
   
   jalankan_trit();
   beberes_trit("Selesai...");

}
