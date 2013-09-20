#include"stdafx.h"
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include"C_Sqlist_Basic.h"


Status InitList(Sqlist &L)
{
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)
		exit(OVERFLOW);
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
}

Status DestroyList(Sqlist &L)
{
	free(L.elem);
	L.elem=NULL;
	L.length=L.listsize=0;
	return OK;
}

Status ClearList(Sqlist &L)
{
	L.length=0;
	return OK;
}

Status ListEmpty(Sqlist L)
{
	return (L.length<=0)?TRUE:FALSE;
}

int ListLength(Sqlist L)
{
	return L.length;
}

Status GetElem(Sqlist L, int i, ElemType &e)
{
	if(i<1 || i>L.length)
		return ERROR;
	e=*(L.elem+i-1);
	return OK;
}

int LocateElem(Sqlist L, ElemType e, int (*compare)(ElemType,ElemType))
{
	int i=0;
	ElemType *p=L.elem;
	while(i<L.length && compare(*p++,e))
		i++;
	if(i>=L.length)
		return FALSE;
	return i+1;
}

Status PriorElem(Sqlist L, ElemType cur_e, ElemType &prior_e)
{
	ElemType *p=L.elem+1;
	ElemType *q=L.elem+L.length-1;
	while(p<=q && cur_e!=*p)
		p++;
	if(p>q)
		return ERROR;
	prior_e=*--p;
	return OK;
}

Status NextElem(Sqlist L, ElemType cur_e, ElemType &next_e)
{
	ElemType *p,*q;
	p=L.elem;
	q=L.elem+L.length-1;
	while(p<q && cur_e!=*p)
		p++;
	if(p>=q)
		return ERROR;
	next_e=*++p;
	return OK;
}

Status ListInsert(Sqlist &L, int i, ElemType e)
{
	if(i<1 || i>L.length+1)
		return ERROR;

	if(L.length>=L.listsize)
	{
		L.elem=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
			if(!L.elem)
				exit(OVERFLOW);
		L.listsize+=LISTINCREMENT;
	}

	ElemType *p,*q;
	q=L.elem+i-1;
	p=L.elem+L.length-1;
	for(p;p>=q;p--)
		*(p+1)=*p;
	*q=e;
	L.length++;
	return OK;
}

Status ListDelete(Sqlist &L, int i, ElemType &e)
{
	if(i<1 || i>L.length)
		return ERROR;

	ElemType *p,*q;
	q=L.elem+L.length-1;
	p=L.elem+i-1;
	e=*p;
	for(p++;p<=q;p++)
		*(p-1)=*p;
	L.length--;
	return OK;
}

Status ListTraverse(Sqlist L, void (*visit)(ElemType))
{
	ElemType *p=L.elem;
	ElemType *q=L.elem+L.length-1;
	while(p<=q)
	{
		visit(*p);
		printf(" ");
		p++;
	}

	return OK;
}