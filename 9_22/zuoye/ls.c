#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#include"ls.h"	
int  uid(unsigned int  id)
{	

	if(id==0)
	{
		printf("root ");
	}
	else
	{
		printf("farsight ");
	}
	return -1;
}
int mode(int num,char *s)
{

	 

	switch(num &S_IFMT)
	{
	 	case S_IFSOCK : 
	 					*s='s';
	 					s++;
	 					break;
	 	case S_IFLNK : 
	 					*s='l';
	 					s++;
	 					break;
	 	case  S_IFREG  : 
	 					*s='-';
	 					s++;
	 					break;
	 	case S_IFBLK  : 
	 					*s='b';
	 					s++;
	 					break;
	 	case  S_IFCHR  : 
	 					*s='c';
	 					s++;
	 					break;
	 	case  S_IFIFO  : 
	 					*s='p';
	 					s++;
	 					break;
	 	case  S_IFDIR  : 
	 					*s='d';
	 					s++;
	 					break;
	 	default :
	 					break;
	 }

	if(S_IRUSR == (num & S_IRUSR))
	     {
			*s='r';
			s++;
	   }	
	else
	    {
			*s='-';
			s++;
	   }	 
	if(S_IWUSR == (num & S_IWUSR))
	     {
			*s='w';
			s++;
	   }	
	else
	     {
			*s='-';
			s++;
	   }	

	if(S_IXUSR == (num & S_IXUSR))
	    {
			*s='x';
			s++;
	   }	
	else
	     {
			*s='-';
			s++;
	   }	

	if(S_IRGRP == (num & S_IRGRP))
	     {
			*s='r';
			s++;
	   }	 
	else
	     {
			*s='-';
			s++;
	   }	
	if(S_IWGRP == (num & S_IWGRP))
	    {
			*s='w';
			s++;
	   }	 
	else
	     {
			*s='-';
			s++;
	   }	
	if(S_IXGRP == (num & S_IXGRP))
	     {
			*s='x';
			s++;
	   }	
	else
	     {
			*s='-';
			s++;
	   }	

	if(S_IROTH == (num & S_IROTH))
	     {
			*s='r';
			s++;
	   }	
	else
	     {
			*s='-';
			s++;
	   }	
	if(S_IWOTH == (num & S_IWOTH))
	     {
			*s='w';
			s++;
	   }	
	else
	     {
			*s='-';
			s++;
	   }	
	if(S_IXOTH == (num & S_IXOTH))
	    {
			*s='x';
			s++;
	   }	
	else
	    {
			*s='-';
			s++;
	   }	

}

