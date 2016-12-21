#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"queue.h"

Queue *creatqueue(void)
{
	Queue *pque=(Queue *)malloc(sizeof(Queue));
	if(NULL==pque)
	{
		return pque;
	}
	memset(pque,0,sizeof(Queue));
	return pque;
}
Head *creatHead(void)
{
	Head *head=(Head *)malloc(sizeof(Head));
	if(NULL==head)
	{
		return head;
	}
	memset(head,0,sizeof(Head));
	return head;
}
int inqueue(Head *head,Tree *ptree)//尾部插入
{
	if(NULL==head || NULL==ptree)
	{
		return ;
	}
	Queue* pnode=creatqueue();
	if(NULL==pnode)
	{
		return ;
	}
	pnode->data=ptree;
	if(head->plast==NULL)
	{
		head->plast=pnode;
		head->pnext=pnode;
		head->inum++;
//		printf("%4d",pnode->data->data);
		return ;
	}
	Queue * ptemp;
	ptemp=head->pnext;
	ptemp->pnext=pnode;
	head->pnext=pnode;
	head->inum++;
//	printf("%4d",pnode->data->data);
	return ;
}
Tree* outqueue(Head *head) //头部出队
{
	if(NULL==head || head->pnext==NULL)
	{
		return ;
	}
	Queue *ptemp;
	Tree * treeout;
	if(head->plast==head->pnext)
	{
		ptemp=head->plast;
		head->plast=NULL;
		head->pnext=NULL;
		treeout=ptemp->data;
		free(ptemp);
		ptemp=NULL;
		head->inum--;
		return treeout;
	}
	ptemp=head->plast;
	treeout=ptemp->data;
	head->plast=ptemp->pnext;
	free(ptemp);
	ptemp=NULL;
	head->inum--;
	return treeout;
}
void destroyqueue(Head * head)
{
	if(NULL==head)
	{
		return ;
	}
	Queue * pdel,*ptemp;
	ptemp=head->plast;
	while(ptemp!=NULL)
	{
		pdel=ptemp;
		free(pdel);
		pdel=NULL;
		ptemp=ptemp->pnext;
	}
	free(head);
	head=NULL;
	return ;
}
int showqueue(Head * head)
{
	if(NULL==head)
	{
		return ;
	}
	Queue *ptemp;
	ptemp=head->plast;
	while(ptemp!=NULL)
	{
		printf("%5d",ptemp->data->data);
		ptemp=ptemp->pnext;
	}
	return;
}

