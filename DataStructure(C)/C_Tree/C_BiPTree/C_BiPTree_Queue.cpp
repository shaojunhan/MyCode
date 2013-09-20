#include"C_BiPTree_Queue.h"

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

	if(!Q.front)
		return ERROR;
	else
	{
		p=Q.front->next;
		e=Q.front->e;
		free(Q.front);
		if(!p)
			Q.front=Q.rear=NULL;
		else
			Q.front=p;
		return OK;
	}
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

bool QueueEmpty(Queue Q)
{
	return Q.front==NULL;
}

Status GetHead(Queue Q,QElemType &e)
{
	if(!Q.front)
		return ERROR;
	else
		e=Q.front->e;
	return OK;
}