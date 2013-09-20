#include"C_BiTree_Stack.h"

Status InitStack(Stack &S)
{
	S.top=S.base=NULL;
	return OK;
}

Status DestroyStack(Stack &S)
{
	while(S.top)
	{
		S.base=S.top->next;
		free(S.top);
		S.top=S.base;
	}
	S.top=S.base=NULL;
	return OK;
}

Status ClearStack(Stack &S)
{
	while(S.top)
	{
		S.base=S.top->next;
		free(S.top);
		S.top=S.base;
	}
	S.top=S.base=NULL;
	return OK;
}

bool StackEmpty(Stack S)
{
	return S.top==NULL;
}

int StackLength(Stack S)
{
	int i;

	i=0;
	while(S.top)
	{
		i++;
		S.top=S.top->next;
	}

	return i;
}

Status Push(Stack &S,SElemType e)
{
	SLink p;

	if(!(p=(SLink)malloc(sizeof(struct SLNode))))
		exit(OVERFLOW);
	p->e=e;

	if(S.top)
	{
		p->next=S.top;
		S.top=p;
	}
	else
	{
		p->next=NULL;
		S.top=S.base=p;
	}

	return OK;
}

Status Pop(Stack &S,SElemType &e)
{
	SLink p;

	if(S.top)
	{
		e=S.top->e;
		p=S.top->next;
		free(S.top);
		S.top=p;

		if(!S.top)
			S.base=S.top=NULL;
		return OK;
	}
	else
		return FALSE;
}

Status GetTop(Stack S,SElemType &e)
{
	if(!S.top)
		return FALSE;
	else
		e=S.top->e;
	return OK;
}