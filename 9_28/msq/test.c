/*************************************************************************
    > File Name: test.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Wed 28 Sep 2016 12:39:45 AM PDT
 ************************************************************************/

       #define _GUN_SOURCE
       #include <stdio.h>
       #include <stdlib.h>
int main()
{

			 FILE *fp;
			 char *line = NULL;
			 size_t len = 0;
			  ssize_t read;
			  int num=0;
			 fp = fopen("/home/farsight/lianxi/7.c", "r");
																						if (fp == NULL)
																					       exit(EXIT_FAILURE);
																				 
																				          while ((read = getline(&line, &len, fp)) != -1) 
																						  {
						num++;
					 printf("Retrieved line of length %zu :\n", read);
																								  printf("%s", line);
																							}
				printf("%d\n",num);																			free(line);
				return 0;												
}
