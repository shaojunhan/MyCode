#include"stdafx.h"
#include"C_SqlStack_Basic.h"
#include<stdlib.h>

Status InitStack(SqlStack &S)
{
	S.base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!S.base)
		return ERROR;
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(SqlStack &S)
{
	free(S.base);
	S.base=S.top=NULL;
	S.stacksize=0;
	return OK;
}

Status ClearStack(SqlStack &S)
{
	S.top=S.base;
	return OK;
}

Status StackEmpty(SqlStack S)
{
	return S.top==S.base?TRUE:FALSE;
}

int StackLength(SqlStack S)
{
	return S.top-S.base;
}

Status Push(SqlStack &S,ElemType e)
{
	if(S.top-S.base>=S.stacksize-1)
	{
		S.base=(ElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(ElemType));
		if(!S.base)
			return ERROR;
		S.top=S.base+S.stacksize-1;
		S.stacksize+=STACKINCREMENT;
	}

	*(S.top++)=e;
	return OK;
}

Status Pop(SqlStack &S,ElemType &e)
{
	if(S.top>S.base)
	{
		e=*(--S.top);
		return OK;
	}

	return ERROR;
}

Status GetTop(SqlStack S,ElemType &e)
{
	if(S.top>S.base)
	{
		e=*(S.top-1);
		return OK;
	}

	return ERROR;
}

Status StackTraverse(SqlStack S,void (*visit)(ElemType))
{
	while(S.base<S.top)
	{
		visit(*(S.base++));
	}

	return OK;
}