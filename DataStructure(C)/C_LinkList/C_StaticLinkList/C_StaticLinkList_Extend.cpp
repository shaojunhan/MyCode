#include"stdafx.h"
#include"C_StaticLinkList_Extend.h"
#include"C_StaticLinkList_Malloc.h"
#include<stdio.h>

int InitSpace(SLinkList space)
{
	int i=0;
	for(i=0;i<MAXSIZE;i++)
		space[i].cur=i+1;
	space[MAXSIZE-1].cur=0;
	return OK;
}

Status InitList(SLinkList L,int &n)
{
	int i=0;
	i=Malloc(L);
	if(!i)
	{
		n=0;
		return ERROR;
	}
	else
	{
		n=i;
		L[n].cur=0;
		return OK;
	}
}

Status ClearList(SLinkList L,int n)
{
	int k=L[n].cur;
	int i=L[0].cur;
	L[n].cur=0;
	
	if(k)
	{
		L[0].cur=k;
		while(k)
		{
			n=k;
			k=L[k].cur;		
		}
		L[n].cur=i;
		return OK;
	}

	return FALSE;
}

Status ListEmpty(SLinkList L,int n)
{
	return L[n].cur==0?TRUE:FALSE;
}

int ListLength(SLinkList L,int n)
{
	int i=0;
	int k=L[n].cur;

	while(k)
	{
		i++;
		k=L[k].cur;
	}

	return i;
}

Status GetElem(SLinkList L,int n,int i,ElemType &e)
{
	int k=L[n].cur;
	int j=1;

	while(k && j<i)
	{
		k=L[k].cur;
		j++;
	}

	if(!k || j>i)
		return ERROR;
	else
	{
		e=L[k].data;
		return OK;
	}
}

int LocateElem(SLinkList L,int n,ElemType e,int (*compare)(ElemType,ElemType))
{
	int k=L[n].cur;
	int i=1;
	while(k && compare(L[k].data,e))
	{
		k=L[k].cur;
		i++;
	}

	if(!k)
		i=0;
	
	return i;
}

Status PriorElem(SLinkList L,int n,ElemType cur_e,ElemType &prior_e)
{
	int k=L[n].cur;
	int i=n;

	while(k && cur_e!=L[k].data)
	{
		i=k;
		k=L[k].cur;
	}

	if(!k)
		return ERROR;
	else
	{
		prior_e=L[i].data;
		return OK;
	}
}

Status NextElem(SLinkList L,int n,ElemType cur_e,ElemType &next_e)
{
	int k=L[n].cur;

	while(k && L[k].data!=cur_e)
		k=L[k].cur;

	if(!k || !L[k].cur)
		return ERROR;
	else
	{
		k=L[k].cur;
		next_e=L[k].data;
		return OK;
	}
}

Status ListInsert(SLinkList L,int n,int i,ElemType e)
{
	int k=n;
	int j=0;
	int s;

	if(i<1 || i>ListLength(L,n)+1)
		return ERROR;
	
	while(j<i-1)
	{
		k=L[k].cur;
		j++;
	}
	
	s=Malloc(L);
	if(!s)
		return ERROR;
	L[s].data=e;
	L[s].cur=L[k].cur;
	L[k].cur=s;

	return OK;
}

Status ListDelete(SLinkList L,int n,int i,ElemType &e)
{
	int k=n;
	int j=0;
	int s;

	if(i<1 || i>ListLength(L,n))
		return ERROR;
	while(j<i-1)
	{
		k=L[k].cur;
		j++;
	}
	s=L[k].cur;
	L[k].cur=L[s].cur;
	e=L[s].data;
	Free(L,s);
	return OK;
}

Status TraverseList(SLinkList L,int n,void (*visit)(ElemType))
{
	int k=L[n].cur;
	while(k)
	{
		visit(L[k].data);
		k=L[k].cur;
	}

	return OK;
}