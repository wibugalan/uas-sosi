#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


#define OFILE "output_problem_a.txt"


void main(void) {
   int n, off, ofd;
   char text[100];
   ofd = open (OFILE, O_RDWR | O_CREAT, 0644);
   scanf("%d", &n);
   int count = 0;
   for(int i = 0; i < n; i++){
      char mod[100];
      scanf("%s %d %s", text, &off, mod);
      int textsize = strlen(text);
      int a = strcmp(mod,"A");  
      int t = strcmp(mod,"T");
      if (a == 0) {
      	 lseek(ofd, count, SEEK_SET);
         write(ofd, text, textsize);
         count += textsize;
         a = 0;
      }
      else if (t == 0) {
         lseek(ofd, off, SEEK_SET);
         write(ofd, text, textsize);
         t = 0;
      }
   }
   printf("Please see file %s\n", OFILE);
   close(ofd);
}

