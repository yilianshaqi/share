#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"tree.h"
#include"queue.h"


void queueshow(Tree *ptree)
{
	if(NULL==ptree)
	{
		return ;
	}
	Head * head=creatHead();
	if(NULL==head)
	{
		return ;
	}
	inqueue(head,ptree);
	while(head->inum>0)
	{	
		ptree=outqueue(head);
		printf("%5d",ptree->data);
		if(ptree->lchild!=NULL)
		{
			inqueue(head,ptree->lchild);
		}
		if(ptree->rchild!=NULL)
		{
			inqueue(head,ptree->rchild);
		}
	}
	destroyqueue(head);
	return ;
}
