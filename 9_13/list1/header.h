#ifndef _header_h_
#define _header_h_

typedef int _I ;
typedef unsigned int U_I;
#define LEN 3

typedef struct DATA
{
	_I *data;
	U_I inum;
}Data;
Data pplist;
Data *creat(void);
_I insert(Data *plist ,_I offset, _I data);
_I delete(Data *plist, _I offset, _I *data);
_I find( Data * plist ,_I data);
_I updata(Data *plist ,_I offset,_I data);
_I show(Data *plist);
void destroy(Data *plist);
void menu(void);
void expand(Data * plist);

enum table_error 
{
	list_ok,
	list_error
};

enum 
{
	insertdata,
	finddata,
	deletedata,
	updatadata,
	showdata,
	esc
};


#endif