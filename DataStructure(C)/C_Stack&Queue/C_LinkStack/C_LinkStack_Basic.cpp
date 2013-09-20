#include"C_LinkStack_Basic.h"
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
	int i=0;
	while(S.top->next)
	{
		S.top=S.top->next;
		i++;
	}

	return i;
}

Status Push(LinkStack &S,ElemType e)
{
	Link s=(Link)malloc(sizeof(struct LNode));
	if(!s)
		exit(OVERFLOW);

	s->data=e;
	s->next=S.top->next;
	S.top->next=s;
	if(S.top==S.base)
		S.base=s;
	return OK;
}

Status Pop(LinkStack &S,ElemType &e)
{
	if(S.base==S.top)
		return ERROR;
	S.top=S.top->next;
	e=S.top->data;
	return OK;
}

Status GetTop(LinkStack S,ElemType &e)
{
	if(S.base==S.top)
		return ERROR;
	S.top=S.top->next;
	e=S.top->data;
	return OK;
}

Status StackTraverse(LinkStack S,void (*visit)(ElemType))
{
	Link p=S.top;
	while(S.base!=S.top)
	{
		p=S.top;
		while(p->next!=S.base)
		{
			p=p->next;
		}
		visit(S.base->data);
		S.base=p;
	}
	return OK;
}