#ifndef C_StaticLinkList_Basic_2012_10_11_14_27
#define C_StaticLinkList_Basic_2012_10_11_14_27

#include"stdafx.h"

#define MAXSIZE 1000

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	int cur;
}component,SLinkList[MAXSIZE];


Status InitList(SLinkList L);
Status ClearList(SLinkList L);
Status ListEmpty(SLinkList L);
int ListLength(SLinkList L);
Status GetElem(SLinkList L,int i,ElemType &e);
int LocateElem(SLinkList L,ElemType e,int (*compare)(ElemType,ElemType));
Status PriorElem(SLinkList L,ElemType cur_e,ElemType &prior_e);
Status NextElem(SLinkList L,ElemType cur_e,ElemType &next_e);
Status ListInsert(SLinkList L,int i,ElemType e);
Status ListDelete(SLinkList L,int i,ElemType &e);
Status TraverseList(SLinkList L,void (*visit)(ElemType));

#endif