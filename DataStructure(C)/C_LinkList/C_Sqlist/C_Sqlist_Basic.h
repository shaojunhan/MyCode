#include"stdafx.h"

#ifndef hanshao1
#define hanshao1 "¿ªÌÅÊÖ½Ü¿Ë"

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 2

typedef int Status;
typedef int Boolean;
typedef int ElemType;
typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;

Status InitList(Sqlist &L);
Status DestroyList(Sqlist &L);
Status ClearList(Sqlist &L);
Status ListEmpty(Sqlist L);
int ListLength(Sqlist L);
Status GetElem(Sqlist L, int i, ElemType &e);
int LocateElem(Sqlist L, ElemType e, int (*compare)(ElemType,ElemType));
Status PriorElem(Sqlist L, ElemType cur_e, ElemType &prior_e);
Status NextElem(Sqlist L, ElemType cur_e, ElemType &next_e);
Status ListInsert(Sqlist &L, int i, ElemType e);
Status ListDelete(Sqlist &L, int i, ElemType &e);
Status ListTraverse(Sqlist L, void (*visit)(ElemType));

#endif