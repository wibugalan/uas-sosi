#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define OFILE1 "output_problem_b1.txt"
#define OFILE2 "output_problem_b2.txt"

void main(void) {
   int n, off, id, ofd1, ofd2;
   ofd1 = open(OFILE1, O_RDWR | O_CREAT, 0644);
   ofd2 = open(OFILE2, O_RDWR | O_CREAT, 0644);
   scanf("%d", &n);
	for (int i = 0; i < n; i++){
	    char str[100];
	    scanf("%s %d %d", str, &off, &id);
	    int size = strlen(str);
	    if(id==1){
	     	lseek(ofd1, off, SEEK_SET);
	        write(ofd1, str, size);
	    }
	    else if(id==2){
	     	lseek(ofd2, off, SEEK_SET);
	        write(ofd2, str, size);
	    }
	}
   close(ofd1);
   close(ofd2);
   printf("Please see file %s\n", OFILE1);
   printf("Please see file %s\n", OFILE2);

}
