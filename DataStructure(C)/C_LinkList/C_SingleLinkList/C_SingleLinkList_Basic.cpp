#include"stdafx.h"
#include"C_SingleLinkList_Basic.h"
#include<stdlib.h>
#include<math.h>

Status InitList(LinkList &L)
{
	L=(LinkList)malloc(sizeof(struct LNode));
	if(!L)
		exit(OVERFLOW);
	L->next=NULL;
	return OK;
}

Status DestroyList(LinkList &L)
{
	LNode *p;
	while(L)
	{
		p=L->next;
		free(L);
		L=p;
	}
	
	return OK;
}

Status ClearList(LinkList &L)
{
	LNode *p=L->next,*q;
	while(p)
	{
		q=p->next;
		free(p);
		p=q;
	}
	L->next=NULL;
	return OK;
}

Status ListEmpty(LinkList L)
{
	return (L->next==NULL)?TRUE:FALSE;
}

int ListLength(LinkList L)
{
	int i=0;
	LNode *p=L->next;
	while(p)
	{
		i++;
		p=p->next;
	}

	return i;
}

Status GetElem(LinkList L, int i, ElemType &e)
{
	int j=0;
	LNode *p=L;
	while(p && j<i)
	{
		p=p->next;
		j++;
	}

	if(!p || j>i)
		return ERROR;
	else
		e=p->data;
	return OK;
}

int LocateElem(LinkList L, ElemType e, int (*compare)(ElemType,ElemType))
{
	LNode *p=L->next;
	int i=1;

	while(p && compare(p->data,e))
	{
		p=p->next;
		i++;
	}

	if(!p)
		return ERROR;
	else
		return i;
}

Status PriorElem(LinkList L,ElemType cur_e,ElemType &prior_e)
{
	LNode *p=L->next;
	while(p->next && cur_e!=p->next->data)
		p=p->next;

	if(!p->next)
		return ERROR;
	else
		prior_e=p->data;
	return OK;
}

Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e)
{
	LNode *p=L->next;
	while(p->next && cur_e!=p->data)
		p=p->next;
	if(!p->next)
		return ERROR;
	else
		next_e=p->next->data;
	return OK;
}

Status ListInsert(LinkList &L,int i,ElemType e)
{
	LNode *p=L;
	int j=0;
	while(p && j<i-1)
	{
		p=p->next;
		j++;
	}

	if(!p || j>i-1)
		return ERROR;
	LNode *s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

Status ListDelete(LinkList &L,int i,ElemType &e)
{
	LNode *p=L,*q;
	int j=0;
	while(p && j<i-1)
	{
		p=p->next;
		j++;
	}

	if(!p || j>i-1)
		return ERROR;
	if(!p->next)
		return ERROR;
	else
	{
		q=p->next;
		e=q->data;
		p->next=q->next;
		free(q);
		return OK;
	}
}

Status ListTraverse(LinkList L,void (*visit)(ElemType))
{
	LNode *p=L->next;
	while(p)
	{
		visit(p->data);
		p=p->next;
	}

	return OK;
}