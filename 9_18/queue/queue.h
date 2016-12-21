#ifndef _queue_h_
#define _queue_h_
typedef int data_t;
typedef struct DATA
{
	data_t data;
	struct DATA *pnext;
}Data;

enum state
{
	QUEUE_ERROR,
	QUEUE_OK
};

Data * creatqueue(void);
int inqueue(Data *pque, data_t tdata);
int outqueue(Data *pque,data_t *tdata);
int destory(Data *pque);








#endif
