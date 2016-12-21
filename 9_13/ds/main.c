#include<stdio.h>
#include"header.h"
void main()
{
	data data1;
	int set;
	char addword[LEN];
	printf("input inum:\n");
	scanf("%d",&data1.inum);
	getchar();
	printf("input a string include %d char:\n",data1.inum);
	gets(data1.str);
	printf("input insert size:\n");
	scanf("%d",&set);
	printf("input insert word:\n");
	scanf("%s",addword);
	add(&data1,set,addword);
	puts(data1.str);
}
