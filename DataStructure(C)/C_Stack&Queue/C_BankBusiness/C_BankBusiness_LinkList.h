#ifndef C_BANKBUSINESS_LINKList_H_INCLUDED
#define C_BANKBUSINESS_LINKList_H_INCLUDED

#include"C_BankBusiness_Header.h"
typedef struct SLNode
{
    SElemType data;
    struct SLNode *next;
}*SLink;

typedef SLink LinkList;

Status InitList(LinkList &L);
Status DestroyList(LinkList &L);
Status ClearList(LinkList &L);
Status ListEmpty(LinkList L);
int ListLength(LinkList L);
Status PriorElem(LinkList L,SElemType cur_e,SElemType &prior_e,int (*compare)(SElemType,SElemType));
Status NextElem(LinkList L,SElemType cur_e,SElemType &next_e,int (*compare)(SElemType,SElemType));
Status ListDelete(LinkList &L,int i,SElemType &e);
Status ListInsert(LinkList &L,int i,SElemType e);
int LocateElem(LinkList L,SElemType e,int (*compare)(SElemType,SElemType));
Status GetElem(LinkList L,int i,SElemType &e);
Status ListTraverse(LinkList L,void (*visit)(SElemType));
#endif // C_BANKBUSINESS_LINKList_H_INCLUDED
