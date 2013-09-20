#include"C_Bracket_LinkStack.h"
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
	Link p=S.top->next;
	int i=0;

	while(p)
	{
		i++;
		p=p->next;
	}

	return i;
}

Status GetTop(LinkStack S,ElemType &e)
{
	if(S.top!=S.base)
	{
		S.base=S.top->next;
		e=S.base->data;
		return OK;
	}

	return FALSE;
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
	else
	{
		Link p=S.top->next;
		e=p->data;
		S.top->next=p->next;
		if(S.base==p)
			S.base=S.top;
		free(p);
		return OK;
	}
}

Status StackTraverse(LinkStack S, void (*visit)(ElemType))
{
	while(S.top!=S.base)
	{
		Link p=S.top->next;
		Link q=S.top;
		while(p!=S.base)
		{
			q=p;
			p=p->next;
		}
		visit(p->data);
		S.base=q;
	}

	return OK;
}
