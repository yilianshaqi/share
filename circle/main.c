#include<stdio.h>
#include"Link.h"

int main()
{
    Link *phead = CreateLink();
    if ( NULL == phead)
    {
        return -1;
    }
    int i,ret;
    for ( i = 0 ; i < 3 ; i++ )
    {
        ret = InsertLinkItem(phead, i);
        if ( LINK_ERR == ret)
        {
            break;
        }
    }
    ShowLink(phead,HEADER);
    ShowLink(phead,TAIL);
    int num = 0;
    for(i=0;i<3;i++)
    {
    	ret = DeleteLinkItem(phead, &num);
    	printf("the deleted num is %d,ret=%d\n",num,ret);
    }
    ShowLink(phead,TAIL);
    DestroyLink(phead);
    phead = NULL;
    return 0;

}
