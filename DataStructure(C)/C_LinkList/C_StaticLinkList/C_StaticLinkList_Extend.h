#ifndef C_StaticLinkList_Expand_2012_10_11_14_27
#define C_StaticLinkList_Expand_2012_10_11_14_27

#include"stdafx.h"
#include"C_StaticLinkList_Basic.h"

int InitSpace(SLinkList space);
Status InitList(SLinkList L,int &n);
Status ClearList(SLinkList L,int n);
Status ListEmpty(SLinkList L,int n);
int ListLength(SLinkList L,int n);
Status GetElem(SLinkList L,int n,int i,ElemType &e);
int LocateElem(SLinkList L,int n,ElemType e,int (*compare)(ElemType,ElemType));
Status PriorElem(SLinkList L,int n,ElemType cur_e,ElemType &prior_e);
Status NextElem(SLinkList L,int n,ElemType cur_e,ElemType &next_e);
Status ListInsert(SLinkList L,int n,int i,ElemType e);
Status ListDelete(SLinkList L,int n,int i,ElemType &e);
Status TraverseList(SLinkList L,int n,void (*visit)(ElemType));

#endif