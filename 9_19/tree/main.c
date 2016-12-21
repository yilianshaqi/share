#include<stdio.h>
#include"tree.h"
void main()
{
	data_t treedata[10]={2,4,6,3,8,1,5,9,0,7};
	Tree *ptree;
	ptree=creattree(treedata,10);
	if(NULL==ptree)
	{
		return ;
	}
	showtree(ptree);
	printf("\n");
	queueshow( ptree);
	printf("\n");
	destroy(ptree);
}
