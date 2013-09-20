#ifndef C_BookIndexList_LinkList_2012_1_1_15_12
#define C_BookIndexList_LinkList_2012_1_1_15_12

#include"C_BookIndexList_Header.h"

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}*Link,*LinkList;

Status InitList(LinkList &L);
Status DestroyList(LinkList &L);
Status ClearList(LinkList &L);
bool ListEmpty(LinkList L);
int ListLength(LinkList L);
Status GetElem(LinkList L,int i,ElemType &e);
int LocateElem(LinkList L,ElemType e,int (*compare)(ElemType,ElemType));
Status PriorElem(LinkList L,ElemType cur_e,ElemType &pre_e);
Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e);
Status ListInsert(LinkList &L,int i,ElemType e);
Status ListDelete(LinkList &L,int i,ElemType &e);
Status ListTraverse(LinkList L,void (*visit)(ElemType));

Status MakeNode(Link &p,ElemType e);
Status FreeNode(Link &p);

#endif