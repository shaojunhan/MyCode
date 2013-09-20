#ifndef hanshao3
#define hanshao3

#include"stdafx.h"
#include"C_SingleLinkList_Basic.h"

Status InitList_CL(LinkList &L);
Status DestroyList_CL(LinkList &L);
Status ClearList_CL(LinkList &L);
Status ListEmpty_CL(LinkList L);
int ListLength_CL(LinkList L);
Status GetElem_CL(LinkList L,int i,ElemType &e);
Status LocateElem_CL(LinkList L,ElemType e,int (*compare)(ElemType,ElemType));
Status PriorElem_CL(LinkList L,ElemType cur_e,ElemType &prior_e);
Status NextElem_CL(LinkList L,ElemType cur_e,ElemType &next_e);
Status ListInsert_CL(LinkList &L,int i,ElemType e);
Status ListDelete_CL(LinkList &L,int i,ElemType &e);
Status ListTraverse_CL(LinkList L,void (*visit)(ElemType));

#endif