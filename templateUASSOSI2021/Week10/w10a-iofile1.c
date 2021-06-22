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
   ofd = open (OFILE, O_RDWR | O_CREAT | O_TRUNC, 0644);
   scanf("%d\n", &n);

   for(int i = 0; i < n; i++){
      char mod[1];
      scanf("%s %d %d", text, &off, &mod);
      int textsize = strlen(text);
      if (mod == "A") {
         lseek(ofd, off, SEEK_SET);
         write(ofd, text, textsize);
      }
      else if (mod == "T") {
         lseek(ofd, off, SEEK_SET);
         write(ofd, text, textsize);
      }
   close(ofd);
   printf("Please see file %s\n", OFILE);
}
