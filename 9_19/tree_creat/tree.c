#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"
Tree *creatnode(data_t tdata)
{
	Tree * ptree=(Tree*)malloc(sizeof(Tree));
	if(NULL==ptree)
	{
		return ptree;
	}
	memset(ptree,0,sizeof(Tree));
	ptree->data=tdata;
	return ptree;
}
Tree *creattree( data_t *tdata,int size)
{
	
	
	Tree *ptree=creatnode(tdata[0]);
	int i;
	for(i=1;i<size;i++)
	{	
		Tree *ptemp=ptree;
		Tree *pnode=creatnode(tdata[i]);
		if(NULL==pnode)
		{
			return pnode;
		}
		while(1)
		{
			if(pnode->data>ptemp->data)
			{
				if(ptemp->rchild==NULL)
				{
					ptemp->rchild=pnode;
					break;
				}
				else
				{
					ptemp=ptemp->rchild;
				}
			}
			else
			{
				if(ptemp->lchild==NULL)
				{
					ptemp->lchild=pnode;
					break;
				}
				else
				{
					ptemp=ptemp->lchild;
				}
			}
		}
	}
	return ptree;
}

void showtree(Tree *ptree)
{
	if(NULL==ptree)
	{
		return ;
	}
	printf("%5d",ptree->data);
	showtree(ptree->lchild);
	showtree(ptree->rchild);       

	
/*	showtree(ptree->lchild);
	printf("%5d",ptree->data);
	showtree(ptree->rchild);     
*/
	return ;
}
int destroy(Tree *ptree)
{
	if(NULL==ptree)
	{
		return ;
	}
	destroy(ptree->lchild);
	destroy(ptree->rchild);
	free(ptree);
	ptree=NULL;
	return ;
}

