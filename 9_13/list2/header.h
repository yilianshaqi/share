#ifndef _header_h_
#define _header_h_

typedef int _I ;
typedef unsigned int U_I;
#define LEN 3

typedef struct DATA
{
//	_I data[LEN];
	_I *data;
	_I inum;
}Data;


_I creat(Data *plist);
_I insert(Data *plist ,_I offset, _I data);
_I delete(Data *plist, _I offset, _I *data);
_I find( Data * plist ,_I data);
_I updata(Data *plist ,_I offset,_I data);
_I show(Data *plist);
void destroy(Data *plist);
void menu(void);
_I expand(Data *plist);

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