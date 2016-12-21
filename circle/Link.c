#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Link.h"


Link* CreateLink()
{
    Link *plink = (Link*)malloc(sizeof(Link));
    if ( NULL == plink )
    {
        return plink;
    }
    memset(plink,0,sizeof(Link));
    return plink;
}
void DestroyLink(Link *plink)
{
    if ( NULL == plink )
    {
        return;
    }
    Link *pTmp = NULL;
    Link *pDel = NULL;
    pDel = plink->pNext;
    while ( plink != pDel )
    {
        pTmp = pDel->pNext;
        free(pDel);
        pDel = pTmp;
    }
    free(plink);
    plink = NULL;
    pTmp = NULL;
    pDel = NULL;
    return;
}

Link* CreateLinkNode(data_t data)
{
    Link *pNode = (Link*)malloc(sizeof(Link));
    if ( NULL == pNode )
    {
        return pNode;
    }
    memset(pNode,0,sizeof(Link));
    pNode->data = data;
    return pNode;
}


int InsertLinkItem(Link *plink,data_t tdata)
{
    if ( NULL == plink )
    {
        return;
    }
    Link *pNode = CreateLinkNode(tdata);
    if ( NULL == pNode )
    {
        return LINK_ERR;
    }
    if ( NULL == plink->pNext)
    {
        plink->pNext = pNode;
        pNode->pPri = plink;
        plink->pPri = pNode;
        pNode->pNext = plink;
        return LINK_OK;
    }
    pNode->pNext = plink->pNext;
    plink->pNext->pPri = pNode;
    pNode->pPri = plink;
    plink->pNext = pNode;
    return LINK_OK;
}
int DeleteLinkItem(Link *plink,data_t *pdata)
{
    if ( (NULL == plink) || (NULL == pdata) || (NULL == plink->pNext) )
    {
        return LINK_ERR;
    }
    Link *pDel = plink->pNext;
    if ( NULL == pDel->pNext)
    {
        plink->pNext = NULL;
        *pdata = pDel->data;
        free(pDel);
        pDel = NULL;
        plink->pPri = NULL;
        return LINK_OK;
    }
    plink->pNext = pDel->pNext;
    pDel->pNext->pPri = plink;
    *pdata = pDel->data;
    free(pDel);
    pDel = NULL;
    return LINK_OK;
}
void ShowLink(Link *plink,int direction)
{
    if ( NULL == plink )
    {
        return;
    }
    Link *pNode = plink->pNext;
    if ( HEADER == direction)
    {
        while ( plink != pNode)
        {
            printf("%4d",pNode->data);
            pNode = pNode->pNext;
        }
        printf("\n");
    }
    else
    {
        pNode = plink->pPri;
        while ( plink != pNode)
        {
            printf("%4d",pNode->data);
            pNode = pNode->pPri;
        }
        printf("\n");
    }

}




