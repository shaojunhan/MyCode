#ifndef C_Polynomail_LinkList_2012_10_13_21_33
#define C_Polynomail_LinkList_2012_10_13_21_33

#include"stdafx.h"
#include"C_Polynomial_Header.h"

Status MakeNode(Link &p,ElemType e);
void FreeNode(Link &p);
Status InitList(LinkList &L);
Status DestroyList(LinkList &L);
Status ClearList(LinkList &L);
Status ListEmpty(LinkList L);
int ListLength(LinkList L);
Status InsFirst(LinkList &L,Link h,Link s);
Status DelFirst(LinkList &L,Link h,Link &q);
Status Append(LinkList &L,Link s);
Status Remove(LinkList &L,Link &q);
Status InsBefore(LinkList &L,Link &p,Link s);
Status InsAfter(LinkList &L,Link &p,Link s);
Status SetCurElem(Link &p,ElemType e);
ElemType GetCurElem(Link p);
Position GetHead(LinkList L);
Position GetLast(LinkList L);
Position PriorPos(LinkList L,Link p);
Position NextPos(LinkList L,Link p);
Status LocatePos(LinkList L,int i,Link &p);
Position LocateElem(LinkList L,ElemType e,int (*compare)(ElemType,ElemType));
Status ListTraverse(LinkList L,void (*visit)(ElemType));

#endif