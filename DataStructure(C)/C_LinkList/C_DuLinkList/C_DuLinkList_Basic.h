#ifndef C_DuLinkList_Basic_2012_10_8_22_58
#define C_DuLinkList_Basic_2012_10_8_22_58

#include"stdafx.h"

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int ElemType;
typedef int Status;
typedef struct LNode
{
	ElemType data;
	struct LNode *prior,*next;
}DuLNode,*DuLinkList;

Status InitList(DuLinkList &L);
Status DestroyList(DuLinkList &L);
Status ClearList(DuLinkList L);
Status ListEmpty(DuLinkList L);
int ListLength(DuLinkList L);
Status GetElem(DuLinkList L,int i,ElemType &e);
DuLNode* GetElemP(DuLinkList L,int i);
int LocateElem(DuLinkList L,ElemType e,int (*compare)(ElemType,ElemType));
Status PriorElem(DuLinkList L,ElemType cur_e,ElemType &prior_e);
Status NextElem(DuLinkList L,ElemType cur_e,ElemType &next_e);
Status ListInsert(DuLinkList &L,int i,ElemType e);
Status ListDelete(DuLinkList &L,int i,ElemType &e);
Status ListTraverse(DuLinkList &L,void (*visit)(ElemType));
Status ListTraverseBack(DuLinkList &L,void (*visit)(ElemType));

#endif