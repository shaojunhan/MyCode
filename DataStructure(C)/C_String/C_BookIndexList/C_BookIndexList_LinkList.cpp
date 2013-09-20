#include"C_BookIndexList_LinkList.h"

//
Status InitList(LinkList &L)
{
	L=NULL;
	return OK;
}

//
Status DestroyList(LinkList &L)
{
	Link p;
	
	if(L)
	{
		p=L;
		while(p)
			L=p->next,free(p),p=L;
		L=NULL;
		return OK;
	}
	else
		return ERROR;
}

//
Status ClearList(LinkList &L)
{
	Link p;
	if(L)
	{
		p=L;
		while(p)
			L=p->next,free(p),p=L;
		L=NULL;
		return OK;
	}
	else
		return ERROR;
}

//
bool ListEmpty(LinkList L)
{
	return L==NULL;
}

//
int ListLength(LinkList L)
{
	int i=0;
	while(L)
	{
		i++;
		L=L->next;
	}

	return i;
}

//
Status GetElem(LinkList L,int i,ElemType &e)
{
	int j;
	int len=0;
	Link p;

	if(i<1)
		return ERROR;

	p=L;
	for(j=0;j<i && p;j++)
		p=p->next;

	if(p)
	{
		e=p->data;
		return OK;
	}
	else
		return ERROR;
}

//
int LocateElem(LinkList L,ElemType e,int (*compare)(ElemType,ElemType))
{
	int i;
	Link p;

	for(i=0,p=L;p;i++)
	{
		if(!compare(p->data,e))
			return i+1;
		else
			p=p->next;
	}

	return 0;
}

//
Status PriorElem(LinkList L,ElemType cur_e,ElemType &pre_e)
{
	Link p,q;

	p=L,q=NULL;
	while(p && p->data!=cur_e)
		q=p,p=p->next;

	if(p && q)
	{
		pre_e=q->data;
		return OK;
	}
	else
		return FALSE;
}

//
Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e)
{
	Link p,q;

	p=L;
	while(p && p->data!=cur_e)
		p=p->next;
	if(p && (q=p->next))
	{
		next_e=q->data;
		return OK;
	}
	else
		return FALSE;
}

//
Status ListInsert(LinkList &L,int i,ElemType e)
{
	int j;
	Link p,q;

	p=L;
	for(j=1;j<i-1 && p;j++)
		p=p->next;

	q=(Link)malloc(sizeof(struct LNode));
	if(!q)
		exit(OVERFLOW);
	q->data=e,q->next=NULL;
		
	if(i==1)
		q->next=L,L=q;
	else if(p && j<i)
		q->next=p->next,p->next=q;
	else
		return ERROR;
	return OK;
}

//
Status ListDelete(LinkList &L,int i,ElemType &e)
{
	int j;
	Link p,q;

	p=L;
	for(j=1;j<i-1 && p;j++)
		p=p->next;

	if(i==1 && L)
		e=L->data,L=L->next;
	else if(p && (q=p->next) && j<i)
		e=q->data,p->next=q->next;
	else
		return FALSE;

	return OK;
}

Status ListTraverse(LinkList L,void (*visit)(ElemType))
{
	while(L)
		visit(L->data),L=L->next;
	return OK;
}

//
Status MakeNode(Link &p,ElemType e)
{
	if(p)
		free(p);
	p=(Link)malloc(sizeof(struct LNode));
	if(!p)
		exit(OVERFLOW);
	p->data=e,p->next=NULL;
	return OK;
}

//
Status FreeNode(Link &p)
{
	if(p)
		free(p);
	p=NULL;
	return OK;
}