#ifndef _queue_h_
#define _queue_h_
#include"tree.h"

typedef struct QUEUE
{
	Tree *data;
	struct QUEUE *pnext;
}Queue;
typedef struct HEADER_TAIL
{
	Queue *plast;
	Queue *pnext;
	int inum;
}Head;
Queue *creatqueue(void);
int inqueue(Head *head,Tree *ptree);//尾部插入
Tree* outqueue(Head *head); //头部出队
void destroyqueue(Head * head);

Head *creatHead(void);
int showqueue(Head * head);




#endif
