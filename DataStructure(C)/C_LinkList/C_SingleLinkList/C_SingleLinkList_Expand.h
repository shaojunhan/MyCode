#ifndef hanshaao2
#define hanshao2

#include"stdafx.h"
#include"C_SingleLinkList_Basic.h"

void InsertAscend(LinkList L,ElemType e);
void InsertDescend(LinkList L,ElemType e);
Status HeadInsert(LinkList L,ElemType e);
Status EndInsert(LinkList L,ElemType e);
Status DeleteFirst(LinkList L,ElemType &e);
Status DeleteTail(LinkList L,ElemType &e);
Status DeleteElem(LinkList L,ElemType e,int (*compare)(ElemType,ElemType));
Status ReplaceElem(LinkList L,int i,ElemType e);
Status CreateAscend(LinkList &L,int n);
Status CreateDescend(LinkList &L,int n);
Status GetFirstElem(LinkList L,ElemType &e);

#endif