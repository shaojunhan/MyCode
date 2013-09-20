#ifndef C_SqlStack_Basic_2012_10_17_17_57
#define C_SqlStack_Basic_2012_10_17_17_57

#include"stdafx.h"

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

#define STACK_INIT_SIZE 5
#define STACKINCREMENT 2

typedef char ElemType;
typedef int Status;

typedef struct SNode
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqlStack;

Status InitStack(SqlStack &S);
Status DestroyStack(SqlStack &S);
Status ClearStack(SqlStack &S);
Status StackEmpty(SqlStack S);
int StackLength(SqlStack S);
Status Push(SqlStack &S,ElemType e);
Status Pop(SqlStack &S,ElemType &e);
Status GetTop(SqlStack S,ElemType &e);
Status StackTraverse(SqlStack S,void (*visit)(ElemType));

#endif