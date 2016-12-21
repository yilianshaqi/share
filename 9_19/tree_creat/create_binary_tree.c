#include<stdio.h>
#include<string.h>
#include"tree.h"
#include"queue.h"
Tree *create_binary_tree(data_t *tdata,int size)
{
	if(NULL==tdata || size<=0)
	{
		return ;
	}
	Tree *ptree=creatnode(tdata[0]);
	if(NULL==ptree)
	{
	return ptree;
	}
	int i;
	Head *head=creatHead();
	if(NULL==head)
	{
		return ;
	}
	Tree *ptemp;
	
	for(i=1;i<size;i++)
	{
		Tree *pnode=creatnode(tdata[i]);
		if(NULL==pnode)
		{
			return pnode;
		}	
		while(head->inum>0)
		{
			ptemp=outqueue(head);
		}
		inqueue(head,ptree);
		while(1)
		{	
			
			ptemp=outqueue(head);
			if(NULL==ptemp->lchild)
			{
				ptemp->lchild=pnode;
				break;
			}
			else
			{
				inqueue(head,ptemp->lchild);
			}
			if(NULL==ptemp->rchild)
			{
				ptemp->rchild=pnode;
				break;
			}
			else
			{
				inqueue(head,ptemp->rchild);
			}
//			showqueue(head);
		}
	//	printf("\n");

	}
	return ptree;
}
