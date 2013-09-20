#include"C_Stack.h"
#include<stdlib.h>

int InitStack(Stack &S)
{
	if(!(S.base=(SElemType*)malloc(INIT_STACK_SIZE*sizeof(SElemType))))
		exit(1);
	S.top=S.base;
	S.stacksize=INIT_STACK_SIZE;
	return 0;
}

int DestroyStack(Stack &S)
{
	if(S.base)
		free(S.base);
	S.base=S.top=NULL;
	S.stacksize=0;
	return 0;
}

int ClearStack(Stack &S)
{
	S.top=S.base;
	return 0;
}

bool StackEmpty(Stack S)
{
	return S.top==S.base;
}

int StackLength(Stack S)
{
	return S.top-S.base;
}

int Push(Stack &S,SElemType e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType*)realloc(S.base,(S.stacksize+INCR_STACK_SIZE)*sizeof(SElemType));
		if(!S.base)
			exit(1);
		S.top=S.base+S.stacksize;
		S.stacksize+=INCR_STACK_SIZE;
	}

	*(S.top++)=e;
	return 0;
}

int Pop(Stack &S,SElemType &e)
{
	if(S.top!=S.base)
	{
		e=*(--S.top);
		return 0;
	}
	return 1;
}

int GetTop(Stack S,SElemType &e)
{
	if(S.top!=S.base)
	{
		e=*(S.top-1);
		return 0;
	}
	return 1;
}
