#include"C_SqBiTree_Queue.h"
#include<stdlib.h>
#include<math.h>

Status InitQueue(Queue &Q)
{
	Q.front=Q.rear=NULL;
	return OK;
}

Status DestroyQueue(Queue &Q)
{
	while(Q.front)
	{
		Q.rear=Q.front;
		free(Q.front);
		Q.front=Q.rear;
	}

	return OK;
}

bool QueueEmpty(Queue &Q)
{
	return Q.front==NULL;
}

Status EnQueue(Queue &Q,QElemType e)
{
	Link p;

	if(!(p=(Link)malloc(sizeof(struct QLNode))))
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
	Link p;

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
	if(Q.front)
	{
		e=Q.front->e;
		return OK;
	}
	else
		return FALSE;
}