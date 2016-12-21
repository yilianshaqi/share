#include <stdio.h>
#include <stdlib.h>

int i;
int main()
{
   int fd=fork();
   if(fd<0)
   {
       printf("fork erro\n");
       return ;

   }
   if(fd==0)
   {
       sleep(20);
       i=3;
       printf("i =3\n");
       thread_exit();

   }
   if(fd>0)
   {

       while()
   }
}
