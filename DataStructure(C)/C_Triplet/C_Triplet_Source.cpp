#include"stdafx.h"
#include"C_Triplet_Header.h"
#include<stdlib.h>

Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3)
{
	T = (Triplet)malloc(3*sizeof(ElemType));
	if(!T)
		return ERROR;
	T[0]=v1;
	T[1]=v2;
	T[2]=v3;
	return OK;
}

Status DestroyTriplet(Triplet &T)
{
	free(T);
	T=NULL;
	return OK;
}

Status Put(Triplet &T, int i, ElemType e)
{
	if(i<1 || i>3)
		return ERROR;
	T[i-1]=e;
	return OK;
}

Status Get(Triplet T, int i, ElemType &e)
{
	if(i<1 || i>3)
		return ERROR;
	e=T[i-1];
	return OK;
}

Status IsAscending(Triplet T)
{
	return (T[0]>=T[1] && T[1]>=T[2]);
}

Status IsDescending(Triplet T)
{
	return (T[0]<=T[1] && T[1]<=T[2]);
}

Status Max(Triplet T, ElemType &e)
{
	e=T[0]>T[1]?T[0]>T[2]?T[0]:T[2]:T[1]>T[2]?T[1]:T[2];
	return OK;
}

Status Min(Triplet T, ElemType &e)
{
	e=T[0]<T[1]?T[0]<T[2]?T[0]:T[2]:T[1]<T[2]?T[1]:T[2];
	return OK;
}