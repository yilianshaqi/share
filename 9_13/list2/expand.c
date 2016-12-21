#include<stdlib.h>
#include"header.h"

extern _I leng;
_I expand(Data *plist)
{
	if(NULL==plist || plist->data ==NULL)
	{	
		return list_error;
	}
	leng+=LEN;
	plist->data=(_I *)realloc(plist->data,sizeof(_I)*leng);
	if(NULL==plist)
	{
		return list_error;
	}
	return list_ok;
}
