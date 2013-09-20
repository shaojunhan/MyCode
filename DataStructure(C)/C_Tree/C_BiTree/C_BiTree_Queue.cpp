#include"C_BiTree_Queue.h"

Status InitQueue(Queue &Q)
{
	Q.front=Q.rear=NULL;
	return OK;
}

Status DestroyQueue(Queue &Q)
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

Status ClearQueue(Queue &Q)
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

bool QueueEmpty(Queue Q)
{
	return Q.front==NULL;
}

int QueueLength(Queue Q)
{
	int i;

	i=0;
	while(Q.front)
	{
		i++;
		Q.front=Q.front->next;
	}

	return i;
}

Status EnQueue(Queue &Q,QElemType e)
{
	QLink p;

	if(!(p=(QLink)malloc(sizeof(struct QLNode))))
		exit(OVERFLOW);
	p->e=e;
	p->next=NULL;

	if(Q.rear)
	{
		Q.rear->next=p;
		Q.rear=p;
	}
	else
	{
		Q.rear=p;
		Q.front=Q.rear;
	}

	return OK;
}

Status DeQueue(Queue &Q,QElemType &e)
{
	QLink p;

	if(Q.front)
	{
		e=Q.front->e;
		p=Q.front->next;
		free(Q.front);
		Q.front=p;

		if(!Q.front)
			Q.rear=Q.front=NULL;
		return OK;
	}
	else
		return FALSE;
}

Status GetHead(Queue Q,QElemType &e)
{
	if(!Q.front)
		return FALSE;
	else
		e=Q.front->e;
	return OK;
}
