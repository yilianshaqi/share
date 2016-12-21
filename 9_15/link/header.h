#ifndef _header_link_
#define _header_link_
typedef int data_t;
typedef struct DATA
{
	data_t data;
	struct DATA *pnext;
}Data;

Data *creation(void);
int insert(Data *plink,int offset,  data_t data);
int delete(Data *plink,int offset ,data_t *data);
int updata(Data *plink,int offset,data_t data);
int find(Data *plink ,data_t data);
int show (Data *plink);
int destory(Data *plink);
void menu(void);
enum state
{
	LINK_OK,
	LINK_ERROR
};
enum function
{
	INSERT,
	DELETE,
	FIND,
	UPDATA,
	SHOW,
	ESC
};
enum insert_state
{
	header=0,
	tail=-1
};


#endif

