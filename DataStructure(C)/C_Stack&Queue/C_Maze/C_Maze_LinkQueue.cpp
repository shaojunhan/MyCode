#include"C_Maze_LinkQueue.h"
#include<stdlib.h>
#include<math.h>

Status InitQueue(LinkQueue &Q)
{
	Q.rear=(Link)malloc(sizeof(struct LNode));
	if(!Q.rear)
		exit(OVERFLOW);
	Q.rear->next=NULL;
	Q.front=Q.rear;
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
	Q.rear=Q.front=NULL;
	return OK;
}

Status CleaerQueue(LinkQueue &Q)
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
	while(Q.front!=Q.rear)
		Q.front=Q.front->next;

	return i;
}

Status EnQueue(LinkQueue &Q,ElemType e)
{
	Link s=(Link)malloc(sizeof(struct LNode));
	if(!s)
		return ERROR;
	s->data=e;
	s->next=Q.rear->next;
	Q.rear->next=s;
	Q.rear=s;
	return OK;
}

Status DeQueue(LinkQueue &Q,ElemType &e)
{
	if(Q.front==Q.rear)
		return ERROR;
	Link p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
		Q.rear=Q.front;
	free(p);
	return OK;
}

Status GetHead(LinkQueue Q,ElemType &e)
{
	if(Q.front==Q.rear)
		return ERROR;
	
	e=Q.front->next->data;
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