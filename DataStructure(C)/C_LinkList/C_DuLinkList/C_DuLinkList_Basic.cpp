#include"stdafx.h"
#include"C_DuLinkList_Basic.h"
#include<stdlib.h>
#include<Stdio.h>

Status InitList(DuLinkList &L)
{
	L=(DuLinkList)malloc(sizeof(DuLNode));
	if(!L)
		return ERROR;
	L->next=L->prior=L;
	return OK;
}

Status DestroyList(DuLinkList &L)
{
	DuLNode *p=L->next,*q;
	while(p!=L)
	{
		q=p->next;
		free(p);
		p=q;
	}
	free(L);
	L=NULL;
	return OK;
}

Status ClearList(DuLinkList L)
{
	DuLNode *p=L->next,*q;
	while(p!=L)
	{
		q=p->next;
		free(p);
		p=q;
	}
	L->prior=L->next=L;
	return OK;
}

Status ListEmpty(DuLinkList L)
{
	return (L->prior==L && L->next==L)?TRUE:FALSE;
}

int ListLength(DuLinkList L)
{
	int i=0;
	DuLNode *p=L->next;
	while(p!=L)
	{
		p=p->next;
		i++;
	}

	return i;
}

Status GetElem(DuLinkList L,int i,ElemType &e)
{
	DuLNode *p=L->next;
	int j=1;
	while(p!=L && j<i)
	{
		j++;
		p=p->next;
	}

	if(p==L || j>i)
		return ERROR;
	e=p->data;
	return OK;
}

DuLNode* GetElemP(DuLinkList L,int i)
{
	DuLNode *p=L->next;
	int j=1;
	while(p!=L && j<i)
	{
		p=p->next;
		j++;
	}

	if(p==L || j>i)
		return NULL;
	return p;
}

int LocateElem(DuLinkList L,ElemType e,int (*compare)(ElemType,ElemType))
{
	DuLNode *p=L->next;
	int i=0;
	while(p!=L)
	{
		i++;
		if(!compare(p->data,e))
			return i;
		p=p->next;
	}

	return 0;
}

Status PriorElem(DuLinkList L,ElemType cur_e,ElemType &prior_e)
{
	DuLNode *p=L->next->next;
	while(p!=L)
	{
		if(cur_e==p->data)
		{
			prior_e=p->prior->data;
			return OK;
		}
		p=p->next;
	}

	return ERROR;
}

Status NextElem(DuLinkList L,ElemType cur_e,ElemType &next_e)
{
	DuLNode *p=L->next->next;
	while(p!=L)
	{
		if(cur_e==p->prior->data)
		{
			next_e=p->data;
			return OK;
		}
		p=p->next;
	}

	return ERROR;
}

Status ListInsert(DuLinkList &L,int i,ElemType e)
{
	if(i<1 || i>ListLength(L)+1)
		return ERROR;

	DuLNode *p=L;
	int j=0;
	while(j<i-1)
	{
		p=p->next;
		j++;
	}

	DuLNode *s=(DuLNode*)malloc(sizeof(DuLNode));
	if(!s)
		return ERROR;
	s->data=e;
	s->next=p->next;
	s->prior=p;
	p->next->prior=s;
	p->next=s;
	return OK;
}

Status ListDelete(DuLinkList &L,int i,ElemType &e)
{
	if(i<1 || i>ListLength(L))
		return ERROR;

	DuLNode *p=L->next;
	int j=1;
	while(j<i)
	{
		p=p->next;
		j++;
	}

	p->next->prior=p->prior;
	p->prior->next=p->next;
	e=p->data;
	free(p);
	return OK;
}

Status ListTraverse(DuLinkList &L,void (*visit)(ElemType))
{
	DuLNode *p=L->next;
	while(p!=L)
	{
		visit(p->data);
		p=p->next;
	}
	return OK;
}

Status ListTraverseBack(DuLinkList &L,void (*visit)(ElemType))
{
	DuLNode *p=L->prior;
	while(p!=L)
	{
		visit(p->data);
		p=p->prior;
	}

	return OK;
}