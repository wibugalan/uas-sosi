#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "99-myutils.h"

sem_t obs_sem;
sem_t addsub_sem;

#define T_REHAT 2000

int n;
int idmaster = 0;
int sharedInt = 0;
int counter = 1;
int var_add, var_sub;

void* adder (void* a) {
	sem_post(&obs_sem);
	int id;
	id = ++idmaster;
	while(TRUE){
		if (++counter == 2*n) {
			sem_post(&obs_sem);
			counter = 0;
		}
		//printf("%d dan %d", counter, 2*n);
		fflush(NULL);
		rehat_acak(T_REHAT);
		sem_wait(&addsub_sem);
		var_add = (rand()%5) + 1;
		sharedInt += var_add;
		printf("Thread=[%3.3d] ADD [%3.3d]  CURENT VALUE  [%3.3d]\n", id, var_add, sharedInt);
		sem_post(&addsub_sem);
	}
}


void* substractor (void* a) {
	sem_post(&obs_sem);
	int id;
	id = ++idmaster;
	while(TRUE){
		if (++counter == 2*n) {
			sem_post(&obs_sem);
			counter = 0;
		}
		//printf("%d dan %d\n", counter, 2*n);
		fflush(NULL);
		rehat_acak(T_REHAT);
		sem_wait(&addsub_sem);
		var_sub = (rand()%5) + 1;
		sharedInt -= var_sub;
		printf("Thread=[%3.3d] SUB [%3.3d]  CURENT VALUE  [%3.3d]\n", id, var_sub, sharedInt);
		sem_post(&addsub_sem);
	}
}


void* observer (void* a) {
	sem_wait(&obs_sem);
	int id;
	id = ++idmaster;
	printf("Thread=[%3.3d] OBS ---  CURENT VALUE  [%3.3d]\n", id, sharedInt);
	sem_post(&addsub_sem);
	
}

int main(int argc, char * argv[])
{  


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
