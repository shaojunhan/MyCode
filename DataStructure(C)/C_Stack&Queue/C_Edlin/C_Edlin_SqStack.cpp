#include"C_Edlin_SqStack.h"
#include<stdlib.h>
#include<math.h>


Status InitStack(SqStack &S)
{
	S.base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!S.base)
		exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(SqStack &S)
{
	if(!S.base)
		free(S.base);
	S.top=S.base=NULL;
	S.stacksize=0;
	return OK;
}

Status ClearStack(SqStack &S)
{
	S.top=S.base;
	return OK;
}

Status StackEmpty(SqStack S)
{
	return S.top==S.base?TRUE:FALSE;
}

int StackLength(SqStack S)
{
	return S.top-S.base;	
}

Status GetTop(SqStack S,ElemType &e)
{
	if(S.top==S.base)
		return ERROR;
	e=*(S.top-1);
	return OK;
}

Status Push(SqStack &S,ElemType e)
{
	if(S.top-S.base>=S.stacksize-1)
	{
		S.base=(ElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(ElemType));
		if(!S.base)
			exit(OVERFLOW);
		S.top=S.base+S.stacksize-1;
		S.stacksize+=STACKINCREMENT;
	}

	*(S.top++)=e;
	return OK;
}

Status Pop(SqStack &S,ElemType &e)
{
	if(S.top==S.base)
		return ERROR;
	e=*(--S.top);
	return OK;
}

Status StackTraverse(SqStack S,void (*visit)(ElemType))
{
	while(S.base<S.top)
	{
		visit(*(S.base++));
	}

	return OK;
}