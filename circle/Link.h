#ifndef _LINK_H_
#define _LINK_H_

typedef int data_t;
typedef struct LINK
{
    data_t data;
    struct LINK *pNext;
    struct LINK *pPri;
}Link;

typedef enum LINK_OP
{
    LINK_ERR = -1,
    LINK_OK
}LINK_OP_ENUM;

#define HEADER 0
#define TAIL -1
Link* CreateLink();
void DestroyLink(Link *plink);
Link* CreateLinkNode(data_t data);
int InsertLinkItem(Link *plink,data_t tdata);
int DeleteLinkItem(Link *plink,data_t *pdata);
void ShowLink(Link *plink,int direction);
#endif /* _LINK_H_ */
