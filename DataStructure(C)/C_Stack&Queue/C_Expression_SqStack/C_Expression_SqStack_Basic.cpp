#include"C_Expression_SqStack_Basic.h"
#include<stdlib.h>
#include<math.h>

Status InitStack(SqStack &Q)
{
	Q.base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!Q.base)
		exit(OVERFLOW);
	Q.top=Q.base;
	Q.stacksize=STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(SqStack &Q)
{
	free(Q.base);
	Q.base=Q.top=NULL;
	Q.stacksize=0;
	return OK;
}

Status ClearStack(SqStack &Q)
{
	Q.top=Q.base;
	return OK;
}

Status StackEmpty(SqStack Q)
{
	return Q.top==Q.base?TRUE:FALSE;
}

int StackLength(SqStack Q)
{
	return (Q.top-Q.base);
}

Status GetTop(SqStack Q,ElemType &e)
{
	if(Q.top>Q.base)
	{
		e=*(Q.top-1);
		return OK;
	}

	return ERROR;
}

Status Push(SqStack &Q,ElemType e)
{
	if(Q.top-Q.base>=Q.stacksize-1)
	{
		Q.base=(ElemType*)realloc(Q.base,(Q.stacksize+STACKINCREMENT)*sizeof(ElemType));
		if(!Q.base)
			return ERROR;
		Q.top=Q.base+Q.stacksize-1;
		Q.stacksize+=STACKINCREMENT;
	}

	*(Q.top++)=e;
	return OK;
}

Status Pop(SqStack &Q,ElemType &e)
{
	if(Q.top>Q.base)
	{
		e=*(--Q.top);
		return OK;
	}

	return ERROR;
}

Status StackTraverse(SqStack Q,void (*visit)(ElemType))
{
	while(Q.base<Q.top)
	{
		visit(*(Q.base++));
	}

	return OK;
}
