#ifndef _link_h_
#define _link_h_
typedef int data_t;

typedef struct DATA
{
	data_t data;
	struct DATA *plast;
	struct DATA *pnext;
}Data;
enum state
{
	LINK_ERROR,
	LINK_OK
};
Data *creatlink(void);
int insertlink(Data * plink,data_t data);
//int deletelink(Data *plink,data_t *data);
int taildelete(Data * plink,data_t *data);

int find(Data *plink,data_t data);
int show(Data *plink);
int destory(Data *plink);



#endif
