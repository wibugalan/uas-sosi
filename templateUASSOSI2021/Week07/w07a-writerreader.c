#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "99-myutils.h"

sem_t sem_1;
sem_t sem_2;
sem_t sem_3;
sem_t sem_4;

#define W_REHAT 1000

void* T1 (void* a) {
	while(TRUE) {
		sem_wait(&sem_4);
		for(int ii = 1; ii < 2; ii = ii + 1) {
			printf("T1     Writer        [%d]\n", ii);
			rehat_acak(W_REHAT);
		}
		sem_post(&sem_1);
	}
}


void* T2 (void* a) {
	while(TRUE) {
		sem_wait(&sem_1);
		for(int ii = 1; ii < 3; ii = ii + 1) {
			printf("T2     Writer        [%d]\n", ii);
			rehat_acak(W_REHAT);
		}
		sem_post(&sem_2);
	}
}


void* T3 (void* a) {
	while(TRUE) {
		sem_wait(&sem_2);
		for(int ii = 1; ii < 4; ii = ii + 1) {
			printf("T3     Reader        [%d]\n", ii);
			rehat_acak(W_REHAT);
		}
		sem_post(&sem_3);
	}
}

void* T4 (void* a) {
	while(TRUE) {
		sem_wait(&sem_3);
		for(int ii = 1; ii < 5; ii = ii + 1) {
			printf("T4     Reader        [%d]\n", ii);
			rehat_acak(W_REHAT);
		}
		sem_post(&sem_4);
	}
}

int main(int argc, char * argv[])
{
   sem_init(&sem_1, 0, 0);
   sem_init(&sem_2, 0, 0);
   sem_init(&sem_3, 0, 0);
   sem_init(&sem_4, 0, 1);

   daftar_trit(T1);
   daftar_trit(T2);
   daftar_trit(T3);
   daftar_trit(T4);

   jalankan_trit();
   beberes_trit("Selesai...");
}
