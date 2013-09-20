#ifndef C_HeadLinkList_Basic_2012_10_10_23_01
#define C_HeadLinkList_Basic_2012_10_10_23_01

#include"stdafx.h"

#define ERROR 0
#define FALSE 0
#define OK 1
#define TRUE 1

typedef int Status;
typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}*Link,*Position;

struct LinkList
{
	Link head,tail;
	int len;
};

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
Position PriorPos(LinkList L,Link p);
Status Remove(LinkList L,Link &q);
Status InsBefore(LinkList &L,Link &p,Link s);
Status InsAfter(LinkList &L,Link &p,Link s);
Status SetCurElem(Link p,ElemType e);
ElemType GetElem(Link p);
Position GetHead(LinkList L);
Position GetLast(LinkList L);
Position NextPos(Link p);
int LocateElem(LinkList L,ElemType e,int (*compare)(ElemType,ElemType));
Status LocateElem(LinkList L,ElemType e,Link &q,int (*compare)(ElemType,ElemType));
Status OrderInsert(LinkList &L,ElemType e,int (*compare)(ElemType,ElemType));
Status ListTraverse(LinkList L,void (*visit)(ElemType));

#endif