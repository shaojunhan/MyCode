#include"C_BankBusiness_LinkList.h"
#include<stdlib.h>
#include<math.h>

Status InitList(LinkList &L)
{
	L=(SLink)malloc(sizeof(struct SLNode));
	if(!L)
		exit(OVERFLOW);
	L->next=NULL;
	return OK;
}

Status DestroyList(LinkList &L)
{
	SLink p;
	while(L)
	{
		p=L->next;
		free(L);
		L=p;
	}

	L=NULL;
	return OK;
}

Status ClearList(LinkList &L)
{
	SLink p=L->next;
	SLink q;
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
	return (L==NULL || L->next==NULL)?TRUE:FALSE;
}

int ListLength(LinkList L)
{
	SLink p=L->next;
	int i=0;

	while(p)
	{
		i++;
		p=p->next;
	}

	return i;
}

Status PriorElem(LinkList L,SElemType cur_e,SElemType &prior_e,int (*compare)(SElemType,SElemType))
{
	SLink p=L;
	while(p->next && compare(p->next->data,cur_e))
		p=p->next;

	if(p==L || p->next==NULL)
		return ERROR;
	prior_e=p->data;
	return OK;
}

Status NextElem(LinkList L,SElemType cur_e,SElemType &next_e,int (*compare)(SElemType,SElemType))
{
	SLink p=L->next;
	while(p && compare(p->data,cur_e))
		p=p->next;

	if(!p || !p->next)
		return ERROR;
	next_e=p->next->data;
	return OK;
}

Status ListDelete(LinkList &L,int i,SElemType &e)
{
	SLink p=L->next;
	SLink q;
	int len=0;

	while(p)
	{
		len++;
		p=p->next;
	}

	if(i<1 || i>len)
		return ERROR;

	p=L;
	while(--i)//指向前驱结点
		p=p->next;

	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	return OK;
}

Status ListInsert(LinkList &L,int i,SElemType e)
{
	SLink s;
	SLink p=L->next;
	int len=0;

	while(p)
	{
		len++;
		p=p->next;
	}

	if(i<1 || i>len+1)
		return ERROR;

	p=L;
	while(--i)
		p=p->next;

	s=(SLink)malloc(sizeof(struct SLNode));
	if(!s)
		return ERROR;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

int LocateElem(LinkList L,SElemType e,int (*compare)(SElemType,SElemType))
{
	SLink p=L->next;
	int i=0;
	while(p && compare(p->data,e))
	{
		i++;
		p=p->next;
	}

	if(!p)
		i=0;
	return i;
}

Status GetElem(LinkList L,int i,SElemType &e)
{
	SLink p=L->next;
	int len=1;

	while(p && len<i)
	{
		len++;
		p=p->next;
	}

	if(!p || i<len)
		return ERROR;
	e=p->data;
	return OK;
}

Status ListTraverse(LinkList L,void (*visit)(SElemType))
{
	SLink p=L->next;
	while(p)
	{
		visit(p->data);
		p=p->next;
	}

	return OK;
}