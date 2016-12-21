/*************************************************************************
    > File Name: litte_big.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Wed 28 Sep 2016 05:04:03 AM PDT
 ************************************************************************/

#include<stdio.h>
int main()
{
	union sp
	{
		char ch;
		int in;
	};
	union sp t;
	t.in=0x8910;
	printf("%x\n",t.ch);
	return 0;
}
