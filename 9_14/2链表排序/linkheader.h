#ifndef _linkhead_h_
#define _linkhead_h_
typedef int data_t;
typedef struct LINK
{
	data_t data;
	struct LINK *next;
}Link;
Link * creatlink(void);
int insertlink(Link *plink,int offset ,data_t data);
int deletelink(Link * plink ,int offset ,data_t *data);
int updatalink(Link * plink ,int offset , data_t data);
int showlink(Link * plink );
int destroy(Link * plink);
int find(Link *plink, data_t data);
void menu(void);
int lengthlink(Link * plink);
int rank(Link * plink);



enum flasecodes
{
	link_ok,
	link_error
};

enum state
{
	insertdata,
	finddata,
	deletedata,
	updatadata,
	showdata,
	ranklink,
	esc,
	DELETE_OK,
	DELETE_FALSE
};



#endif