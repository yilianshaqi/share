#ifndef _header_list_
#define _header_list_


typedef int  data_t;
#define LEN 30

typedef struct DATA
{
	data_t data[LEN];
	int inum;
}Data;

enum state
{
	LIST_OK,
	LIST_ERROR,
	NO_DATA
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
Data *create(void);
int insert(Data * plist, int offset, data_t data);
int delete(Data * plist, int offset,data_t *data);
int updata(Data * plist ,int offset ,data_t data );
int find(Data *plist, data_t data);
int show(Data *plist);
void menu(void);





#endif
