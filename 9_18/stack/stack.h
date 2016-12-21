#ifndef _stack_h
#define _stack_h
typedef int data_t;
#define DATA_LEN 20
typedef struct DATA
{
	data_t data[DATA_LEN];
	int    itop;
}Data;

enum state
{
	STACK_ERROR,
	STACK_OK
};
Data *creatstack(void);
int instack(Data * pstack, data_t tdata);
int outstack(Data *pstack, data_t *tdata);
int destory(Data *pstack);















#endif
