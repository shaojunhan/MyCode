#include"stdafx.h"
#include"C_HeadLinkList_Basic.h"
#include<stdlib.h>
#include<stdio.h>

Status MakeNode(Link &p,ElemType e)
{
	if( !(p=(Link)malloc(sizeof(struct LNode))))
		return ERROR;
	p->data=e;
	p->next=NULL;
	return OK;
}

void FreeNode(Link &p)
{
	free(p);
	p=NULL;
}

Status InitList(LinkList &L)
{
	Link p=(Link)malloc(sizeof(struct LNode));
	if(!p)
	{
		L.head=L.tail=NULL;
		L.len=0;
		return ERROR;
	}
	else
	{
		L.head=L.tail=p;
		L.head->next=NULL;
		L.len=0;
		return OK;
	}
}

Status DestroyList(LinkList &L)
{
	Link p=L.head,q;
	while(p)
	{
		q=p->next;
		free(p);
		p=q;
	}
	L.head=L.tail=NULL;
	L.len=0;
	return OK;
}

Status ClearList(LinkList &L)
{
	Link p=L.head->next,q;
	while(p)
	{
		q=p->next;
		free(p);
		p=q;
	}
	L.tail=L.head;
	L.len=0;
	return OK;
}

Status ListEmpty(LinkList L)
{
	return (L.len==0)?TRUE:FALSE;
}

int ListLength(LinkList L)
{
	return L.len;
}

Status InsFirst(LinkList &L,Link h,Link s)
{
	h->next=s;
	if(h==L.tail)
		L.tail=s;
	L.len++;
	return OK;
}

Status DelFirst(LinkList &L,Link h,Link &q)
{
	q=h->next;
	if(q)
	{
		h->next=q->next;
		q->next=NULL;
		if(q==L.tail)
			L.tail=h;
		L.len--;
		return OK;
	}
	else
		return ERROR;
}

Status Append(LinkList &L,Link s)
{
	int i=1;
	L.tail->next=s;
	while(s->next)
	{
		i++;
		s=s->next;
	}
	L.tail=s;
	L.len+=i;
	return OK;
}

Position PriorPos(LinkList L,Link p)
{
	Link q=L.head;
	while(q && q->next!=p)
		q=q->next;
	if(!q)
		return NULL;
	return q;
}

Status Remove(LinkList L,Link &q)
{
	Link p=L.head;
	if(L.len<=0)
		return ERROR;
	while(p->next!=L.tail)
		p=p->next;
	q=L.tail;
	L.tail=p;
	L.len--;
	return OK;
}

Status InsBefore(LinkList &L,Link &p,Link s)
{
	Link q=L.head;
	while(q && q->next!=p)
		q=q->next;
	if(!q)
		return ERROR;
	s->next=q->next;
	q->next=s;
	L.len++;
	return OK;
}

Status InsAfter(LinkList &L,Link &p,Link s)
{
	s->next=p->next;
	p->next=s;
	if(p==L.tail)
		L.tail=s;
	L.len++;
	return OK;
}

Status SetCurElem(Link p,ElemType e)
{
	p->data=e;
	return OK;
}

ElemType GetElem(Link p)
{
	return p->data;
}

Position GetHead(LinkList L)
{
	return L.head;
}

Position GetLast(LinkList L)
{
	return L.tail;
}

Position NextPos(Link p)
{
	return (p->next==NULL)?NULL:p->next;
}

int LocateElem(LinkList L,ElemType e,int (*compare)(ElemType,ElemType))
{
	Link p=L.head->next;
	int i=1;
	while(p && compare(p->data,e))
	{
		p=p->next;
		i++;
	}
	if(!p)
		i=0;
	return i;
}

Status LocateElem(LinkList L,ElemType e,Link &q,int (*compare)(ElemType,ElemType))
{
	Link p,pp=L.head;
	p=pp->next;
	while(p && compare(p->data,e)<0)
	{
		pp=p;
		p=p->next;
	}
	
	if(!p || compare(p->data,e)>0)
	{
		q=pp;
		return ERROR;
	}
	else
	{
		q=p;
		return OK;
	}
}

Status OrderInsert(LinkList &L,ElemType e,int (*compare)(ElemType,ElemType))
{
	Link p,q=L.head;
	p=q->next;
	while(p && compare(p->data,e)<0)
	{
		q=p;
		p=p->next;
	}
	
	Link s=(Link)malloc(sizeof(struct LNode));
	if(!s)
		return ERROR;
	s->data=e;
	s->next=q->next;
	q->next=s;
	if(q==L.tail)
		L.tail=s;
	L.len++;
	return OK;
}

Status ListTraverse(LinkList L,void (*visit)(ElemType))
{
	if(L.len<=0)
		return ERROR;

	Link p=L.head->next;
	while(p)
	{
		visit(p->data);
		p=p->next;
	}

	return OK;
}