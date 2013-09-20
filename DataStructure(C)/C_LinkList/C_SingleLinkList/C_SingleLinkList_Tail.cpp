#include"stdafx.h"
#include"C_SingleLinkList_Tail.h"
#include<stdio.h>
#include<stdlib.h>

Status InitList_CL(LinkList &L)
{
	L=(LinkList)malloc(sizeof(LNode));
	if(!L)
		return ERROR;
	L->next=L;
	return OK;
}

Status DestroyList_CL(LinkList &L)
{
	LNode *p=L->next,*q;
	while(p!=L)
	{
		q=p->next;
		free(p);
		p=q->next;
	}
	free(L);
	L=NULL;

	return OK;
}

Status ClearList_CL(LinkList &L)
{
	L=L->next;
	LNode *p=L->next,*q;
	while(p!=L)
	{
		q=p->next;
		free(p);
		p=q;
	}
	L->next=L;

	return OK;
}

Status ListEmpty_CL(LinkList L)
{
	return (L->next==L)?TRUE:FALSE;
}

int ListLength_CL(LinkList L)
{
	LNode *p=L->next;
	int i=0;
	while(p!=L)
	{
		p=p->next;
		i++;
	}

	return i;
}

Status GetElem_CL(LinkList L,int i,ElemType &e)
{
	LNode *p=L->next->next;
	int j=1;
	if(i<1 || i>ListLength_CL(L))
		return ERROR;
	
	while(j<i)
		p=p->next;
	e=p->data;
	return OK;
}

int  LocateElem_CL(LinkList L,ElemType e,int (*compare)(ElemType,ElemType))
{
	LNode *p=L->next->next;
	int i=1;
	while(p!=L->next && compare(p->data,e))
	{
		p=p->next;
		i++;
	}

	if(p==L->next)
		i=0;
	return i;
}

Status PriorElem_CL(LinkList L,ElemType cur_e,ElemType &prior_e)
{
	LNode *p=L->next,*q;
	q=p->next;

	while(q!=L->next && cur_e!=q->data)
	{
		p=q;
		q=q->next;
	}

	if(q==L->next || p==L->next)
		return ERROR;
	else
		prior_e=q->data;
	return OK;
}

Status NextElem_CL(LinkList L,ElemType cur_e,ElemType &next_e)
{
	LNode *p=L->next->next;
	while(p!=L->next && cur_e!=p->data)
		p=p->next;

	if(p->next==L->next || p==L->next)
		return ERROR;
	else
		next_e=p->next->data;
	return OK;
}

Status ListInsert_CL(LinkList &L,int i,ElemType e)
{
	LNode *p=L->next;
	int j=0;

	if(i<1 || i>ListLength_CL(L)+1)
		return ERROR;
	while(j<i-1)
	{
		p=p->next;
		j++;
	}
	LNode *s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	if(p==L)
		L=s;
	return OK;
}

Status ListDelete_CL(LinkList &L,int i,ElemType &e)
{
	LNode *p=L->next,*q=L;
	int j=0;

	if(i<1 || i>ListLength_CL(L))
		return ERROR;
	while(j<i)
	{
		q=p;
		p=p->next;
		j++;
	}

	if(p!=L->next)
	{
		e=p->data;
		q->next=p->next;
		if(p==L)
			L=q;
		free(p);
		return OK;
	}
	else
		return ERROR;
}
Status ListTraverse_CL(LinkList L,void (*visit)(ElemType))
{
	LNode *p=L->next->next;
	while(p!=L->next)
	{
		visit(p->data);
		p=p->next;
	}

	return OK;
}