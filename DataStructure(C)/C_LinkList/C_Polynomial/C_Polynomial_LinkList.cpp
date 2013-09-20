#include"stdafx.h"
#include"C_Polynomial_LinkList.h"
#include<stdlib.h>

Status MakeNode(Link &p,ElemType e)
{
	p=(Link)malloc(sizeof(struct LNode));
	if(!p)
		return ERROR;
	p->next=NULL;
	p->data=e;
	return OK;
}

void FreeNode(Link &p)
{
	free(p);
	p=NULL;
}

Status InitList(LinkList &L)
{
	Link s=(Link)malloc(sizeof(struct LNode));
	if(!s)
		return ERROR;
	s->next=NULL;
	L.head=L.tail=s;
	L.len=0;
	return OK;
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
	L.head->next=NULL;
	L.tail=L.head;
	L.len=0;
	return OK;
}

Status ListEmpty(LinkList L)
{
	return L.len==0?TRUE:FALSE;
}

int ListLength(LinkList L)
{
	return L.len;
}

Status InsFirst(LinkList &L,Link h,Link s)
{
	s->next=h->next;
	h->next=s;
	L.len++;
	if(L.tail==h)
		L.tail=s;
	return OK;
}

Status DelFirst(LinkList &L,Link h,Link &q)
{
	Link p=h->next;
	if(p)
	{
		q=p;
		h->next=p->next;
		if(L.tail==p)
			L.tail=h;
		L.len--;
		return OK;
	}
	else
	{
		q=NULL;
		return ERROR;
	}
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

Status Remove(LinkList &L,Link &q)
{
	Link p,pp=L.head;
	p=pp->next;
	
	if(p)
	{
		while(p->next)
		{
			pp=p;
			p=p->next;
		}
		L.tail=pp;
		q=p;
		L.len--;
		return OK;
	}
	return ERROR;
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
	if(L.tail==p)
		L.tail=s;
	L.len++;
	return OK;
}

Status InsAfter(LinkList &L,Link &p,Link s)
{
	s->next=p->next;
	p->next=s;
	if(L.tail==p)
		L.tail=s;
	L.len++;
	return OK;
}

Status SetCurElem(Link &p,ElemType e)
{
	p->data=e;
	return OK;
}

ElemType GetCurElem(Link p)
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

Position PriorPos(LinkList L,Link p)
{
	Link q=L.head;
	while(q && q->next!=p)
	{
		q=q->next;
	}

	if(!q || q==L.head)
		return ERROR;
	return q;
}

Position NextPos(LinkList L,Link p)
{
	return p->next?p->next:NULL;
}

Status LocatePos(LinkList L,int i,Link &p)
{
	int j=1;
	Link q=L.head->next;
	while(q && j<i)
	{
		q=q->next;
		j++;
	}

	if(!q)
	{
		p=NULL;
		return ERROR;
	}
	else
	{
		p=q;
		return OK;
	}
}
Position LocateElem(LinkList L,ElemType e,int (*compare)(ElemType,ElemType))
{
	Link p=L.head->next;
	while(p && compare(p->data,e))
		p=p->next;

	if(!p)
		return NULL;
	return p;
}

Status ListTraverse(LinkList L,void (*visit)(ElemType))
{
	Link p=L.head->next;
	while(p)
	{
		visit(p->data);
		p=p->next;
	}

	return OK;
}