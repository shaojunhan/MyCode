#include"C_SysConvert_LinkStack.h"
#include<stdlib.h>
#include<math.h>


Status InitStack(LinkStack &S)
{
	S.base=(Link)malloc(sizeof(struct LNode));
	if(!S.base)
		exit(OVERFLOW);
	S.base->next=NULL;
	S.top=S.base;
	return OK;
}

Status DestroyStack(LinkStack &S)
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

Status ClearStack(LinkStack &S)
{
	Link p=S.top->next;
	while(p)
	{
		S.base=p->next;
		free(p);
		p=S.base;
	}

	S.top->next=NULL;
	S.base=S.top;
	return OK;
}

Status StackEmpty(LinkStack S)
{
	return S.top==S.base?TRUE:FALSE;
}

int StackLength(LinkStack S)
{
	Link p=S.top;
	int i=0;
	while(p->next)
	{
		p=p->next;
		i++;
	}

	return i;
}

Status GetTop(LinkStack S,ElemType &e)
{
	if(S.top==S.base)
		return ERROR;
	e=(S.top->next)->data;
	return OK;
}

Status Push(LinkStack &S,ElemType e)
{
	Link s=(Link)malloc(sizeof(struct LNode));
	if(!s)
		return ERROR;
	s->data=e;
	s->next=S.top->next;
	S.top->next=s;

	if(S.base==S.top)
		S.base=s;

	return OK;
}

Status Pop(LinkStack &S,ElemType &e)
{
	if(S.top==S.base)
		return ERROR;

	Link p=S.top->next;
	S.top->next=p->next;
	if(S.base==p)
		S.base=S.top;
	e=p->data;
	free(p);

	return OK;
}

Status StackTraverse(LinkStack S,void (*visit)(ElemType))
{
	S.base=S.top->next;
	while(S.base)
	{
		visit(S.base->data);
		S.base=S.base->next;
	}

	return OK;
}