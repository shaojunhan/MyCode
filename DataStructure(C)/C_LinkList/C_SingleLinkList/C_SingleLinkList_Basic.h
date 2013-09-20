#ifndef hanshao1
#define hanshao1

#include"stdafx.h"

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;
typedef int ElemType;

struct LNode
{
	ElemType data;
	struct LNode *next;
};

typedef struct LNode *LinkList;

Status InitList(LinkList &L);
Status DestroyList(LinkList &L);
Status ClearList(LinkList &L);
Status ListEmpty(LinkList L);
int ListLength(LinkList L);
Status GetElem(LinkList L, int i, ElemType &e);
int LocateElem(LinkList L, ElemType e, int (*compare)(ElemType,ElemType));
Status PriorElem(LinkList L,ElemType cur_e,ElemType &prior_e);
Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e);
Status ListInsert(LinkList &L,int i,ElemType e);
Status ListDelete(LinkList &L,int i,ElemType &e);
Status ListTraverse(LinkList L,void (*visit)(ElemType));

#endif