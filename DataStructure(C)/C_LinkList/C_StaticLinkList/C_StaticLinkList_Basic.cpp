#include"stdafx.h"
#include"C_StaticLinkList_Basic.h"
#include"C_StaticLinkList_Malloc.h"

Status InitList(SLinkList L)
{
	int i=0;
	for(i=0;i<MAXSIZE-1;i++)
		L[i].cur=i+1;
	L[MAXSIZE-1].cur=0;

	return OK;
}

Status ClearList(SLinkList L)
{
	int i=L[0].cur;
	int k=L[MAXSIZE-1].cur;
	int n=k;

	L[MAXSIZE-1].cur=0;//×¢Òâ²»ÄÜºöÂÔµô
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

Status ListEmpty(SLinkList L)
{
	return L[MAXSIZE-1].cur==0?TRUE:FALSE;
}

int ListLength(SLinkList L)
{
	int k=L[MAXSIZE-1].cur;
	int i=0;
	while(k)
	{
		i++;
		k=L[k].cur;
	}

	return i;
}

Status GetElem(SLinkList L,int i,ElemType &e)
{
	int k=L[MAXSIZE-1].cur;
	int j=1;
	while(k && j<i)
	{
		k=L[k].cur;
		j++;
	}

	if(!k || j>i)
		return ERROR;
	e=L[k].data;
	return OK;
}

int LocateElem(SLinkList L,ElemType e,int (*compare)(ElemType,ElemType))
{
	int k=L[MAXSIZE-1].cur;
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

Status PriorElem(SLinkList L,ElemType cur_e,ElemType &prior_e)
{
	int n=L[MAXSIZE-1].cur;
	int k;

	if(n)
	{
		k=L[n].cur;
		while(k && cur_e!=L[k].data)
		{
			n=k;
			k=L[k].cur;
		}

		if(!k)
			return ERROR;
		prior_e=L[n].data;
		return OK;
	}

	return ERROR;
}

Status NextElem(SLinkList L,ElemType cur_e,ElemType &next_e)
{
	int k=L[MAXSIZE-1].cur;
	while(k && cur_e!=L[k].data)
		k=L[k].cur;
	if(!k || !L[k].cur)
		return ERROR;
	k=L[k].cur;
	next_e=L[k].data;
	return OK;
}
Status ListInsert(SLinkList L,int i,ElemType e)
{
	int k=MAXSIZE-1;
	int j=0;
	int s;

	if(i<1 || i>ListLength(L)+1)
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
Status ListDelete(SLinkList L,int i,ElemType &e)
{
	int k=MAXSIZE-1;
	int j=0;
	int s;

	if(i<1 || i>ListLength(L))
		return ERROR;

	while(j<i-1)
	{
		k=L[k].cur;
		j++;
	}

	s=L[k].cur;
	e=L[s].data;
	L[k].cur=L[s].cur;
	Free(L,s);
	return OK;

}

Status TraverseList(SLinkList L,void (*visit)(ElemType))
{
	int k=L[MAXSIZE-1].cur;
	while(k)
	{
		visit(L[k].data);
		k=L[k].cur;
	}
	return OK;
}