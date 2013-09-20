#include"C_LinkQueue_Basic.h"
#include<stdlib.h>
#include<math.h>

Status InitQueue(LinkQueue &Q)
{
	Q.front=(Link)malloc(sizeof(struct LNode));
	if(!Q.front)
		exit(OVERFLOW);
	Q.front->next=NULL;
	Q.rear=Q.front;

	return OK;
}

Status DestroyQueue(LinkQueue &Q)
{
	while(Q.front)
	{
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}

	Q.front=Q.rear=NULL;
	return OK;
}

Status ClearQueue(LinkQueue &Q)
{
	Link p=Q.front->next;
	while(p)
	{
		Q.rear=p->next;
		free(p);
		p=Q.rear;
	}

	Q.front->next=NULL;
	Q.rear=Q.front;
	return OK;
}

Status QueueEmpty(LinkQueue Q)
{
	return Q.front==Q.rear?TRUE:FALSE;
}

int QueueLength(LinkQueue Q)
{
	int i=0;
	while(Q.front->next)
	{
		Q.front=Q.front->next;
		i++;
	}

	return i;
}

Status GetHead(LinkQueue Q,ElemType &e)
{
	if(Q.rear==Q.front)
		return ERROR;

	Q.front=Q.front->next;
	e=Q.front->data;
	return OK;
}

Status EnQueue(LinkQueue &Q,ElemType e)
{
	Link s=(Link)malloc(sizeof(struct LNode));
	if(!s)
		return ERROR;

	s->data=e;
	s->next=Q.rear->next;
	Q.rear->next=s;//×¢Òâ±ð³ö´í
	Q.rear=s;

	return OK;
}

Status DeQueue(LinkQueue &Q,ElemType &e)
{
	if(Q.front==Q.rear)
		return ERROR;

	Link p=Q.front->next;
	Q.front->next=p->next;

	if(p==Q.rear)
		Q.rear=Q.front;

	e=p->data;
	free(p);
	return OK;
}

Status QueueTraverse(LinkQueue Q,void (*visit)(ElemType))
{
	Q.front=Q.front->next;
	while(Q.front)
	{
		visit(Q.front->data);
		Q.front=Q.front->next;
	}

	return OK;
}