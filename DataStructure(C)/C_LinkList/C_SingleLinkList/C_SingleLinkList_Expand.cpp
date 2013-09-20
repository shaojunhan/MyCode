#include"stdafx.h"
#include"C_SingleLinkList_Expand.h"
#include<stdlib.h>
#include<stdio.h>

void InsertAscend(LinkList L,ElemType e)
{
	LNode *p=L->next,*q=L;
	while(p && e>p->data)
	{
		q=p;
		p=p->next;
	}
	LNode *s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	s->next=q->next;
	q->next=s;
}
void InsertDescend(LinkList L,ElemType e)
{
	LNode *p=L->next,*q=L;
	while(p && e<p->data)
	{
		q=p;
		p=p->next;
	}
	LNode *s=(LNode*)malloc(sizeof(LNode));
	if(!s)
		exit(ERROR);
	s->data=e;
	s->next=q->next;
	q->next=s;
}

Status HeadInsert(LinkList L,ElemType e)
{
	LNode *s=(LNode*)malloc(sizeof(LNode));
	if(!s)
		return ERROR;

	s->data=e;
	s->next=L->next;
	L->next=s;
	return OK;
}

Status EndInsert(LinkList L,ElemType e)
{
	LNode *p=L;
	while(p->next)
		p=p->next;
	LNode *s=(LNode*)malloc(sizeof(LNode));
	if(!s)
		return ERROR;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

Status DeleteFirst(LinkList L,ElemType &e)
{
	LNode *p=L->next;
	if(!p)
		return ERROR;
	e=p->data;
	L->next=p->next;
	return OK;
}

Status DeleteTail(LinkList L,ElemType &e)
{
	LNode *p=L->next,*q=L;
	if(!p)
		return ERROR;
	while(p->next)
	{
		q=p;
		p=p->next;
	}

	e=p->data;
	q->next=p->next;
	return OK;
}

Status DeleteElem(LinkList L,ElemType e,int (*compare)(ElemType,ElemType))
{
	LNode *p=L->next,*q=L;
	while(p && compare(p->data,e))
	{
		q=p;
		p=p->next;
	}
	if(!p)
		return ERROR;
	else
		q->next=p->next;
	return OK;
}

Status ReplaceElem(LinkList L,int i,ElemType e)
{
	LNode *p=L;
	int j=0;
	while(p && j<i)
	{
		p=p->next;
		j++;
	}

	if(!p)
		return ERROR;
	else
		p->data=e;
	return OK;
}

Status CreateAscend(LinkList &L,int n)
{
	InitList(L);
	LNode *s;
	LNode *p=L,*q=p;
	int i=0;
	ElemType e;

	printf("请输入%d个数据:",n);
	while(i<n)
	{
		scanf("%d",&e);
		p=L->next,q=L;
		while(p && e>p->data)
		{
			q=p;
			p=p->next;
		}
		
		s=(LNode*)malloc(sizeof(LNode));
		if(!s)
			return ERROR;
		s->data = e;
		s->next=q->next;
		q->next=s;
		i++;
	}

	return OK;
}

Status CreateDescend(LinkList &L,int n)
{
	InitList(L);
	LNode *s;
	LNode *p,*q;
	int i=0;
	ElemType e;

	printf("请输入%d个数据",n);
	while(i++<n)
	{
		scanf("%d",&e);
		p=L->next,q=L;
		while(p && e<p->data)
		{
			q=p,p=p->next;
		}

		s=(LNode*)malloc(sizeof(LNode));
		if(!s)
			return ERROR;
		s->data=e;
		s->next=q->next;
		q->next=s;
	}

	return OK;
}

Status GetFirstElem(LinkList L,ElemType &e)
{
	if(L->next)
	{
		e=L->next->data;
		return OK;
	}
	else
		return ERROR;
}