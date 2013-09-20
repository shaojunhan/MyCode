#include"stdafx.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"C_Sqlist_Extend.h"

void InsertAscend(Sqlist &L,ElemType e)
{
	ElemType *p;
	p=L.elem;
	int i=0;

	while(i<L.length)
	{
		if(e<*p++)
			break;
		i++;
	}
	ListInsert(L,i+1,e);
}

void InsertDescend(Sqlist &L,ElemType e)
{
	ElemType *p=L.elem;
	int i=0;
	while(i<L.length)
	{
		if(e>*p)
			break;
		p++;
		i++;
	}
	ListInsert(L,i+1,e);
}

Status HeadInsert(Sqlist &L,ElemType e)
{
	if(L.length>=L.listsize)
	{
		L.elem = (ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!L.elem)
			exit(OVERFLOW);
		L.listsize+=LISTINCREMENT;
	}

	ElemType *q=L.elem;
	ElemType *p=L.elem+L.length-1;
	for(p;p>=q;p--)
		*(p+1)=*p;
	*q=e;
	L.length++;
	return OK;
}

Status TailInsert(Sqlist &L,ElemType e)
{
	if(L.length>=L.listsize)
	{
		L.elem=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!L.elem)
			exit(OVERFLOW);
		L.listsize+=LISTINCREMENT;
	}
	*(L.elem+L.length)=e;
	L.length++;
	return OK;
}

Status DeleteFirst(Sqlist &L,ElemType &e)
{
	if(ListEmpty(L))
		return ERROR;
	ElemType *p=L.elem;
	ElemType *q=L.elem+L.length-1;
	e=*p;
	for(p;p<q;p++)
		*p=*(p+1);
	L.length--;
	return OK;
}

Status DeleteTail(Sqlist &L, ElemType &e)
{
	if(ListEmpty(L))
		return ERROR;
	e=*(L.elem+L.length-1);
	L.length--;
	return OK;
}

Status DeleteElem(Sqlist &L, ElemType e)
{
	int i=0;
	while(i<L.length && e!=*(L.elem+i))
		i++;
	if(i>=L.length)
		return ERROR;
	else
	{
		for(int j=i;j<L.length-1;j++)
			*(L.elem+j)=*(L.elem+j+1);
		L.length--;
		return OK;
	}
}

Status ReplaceElem(Sqlist &L, int i, ElemType e)
{
	if(i<1 || i>L.length)
		return ERROR;
	*(L.elem+i-1)=e;
	return OK;
}

Status CreateAscend(Sqlist &L,int n)
{
	if(!InitList(L))
		return ERROR;

	ElemType e;
	ElemType *p=L.elem;
	int j=0;
	int i=1;

	printf("请输入%d个数据:",n);
	scanf("%d",&e);
	ListInsert(L,1,e);

	while(i<n)
	{
		scanf("%d",&e);
		for(j=0,p=L.elem;j<L.length;j++)
			if(e<*p++)
				break;
		ListInsert(L,j+1,e);
		i++;
	}

	return OK;
}
Status CreateDescend(Sqlist &L, int n)
{
	if(!InitList(L))
		return ERROR;

	ElemType e,*p=L.elem;
	int i=1,j=0;
	printf("请输入%d个数值:",n);
	
	while(i<=n)
	{
		scanf("%d",&e);
		for(j=0,p=L.elem;j<L.length;j++)
			if(e>*p++)
				break;
		ListInsert(L,j+1,e);
		i++;
	}

	return OK;
}