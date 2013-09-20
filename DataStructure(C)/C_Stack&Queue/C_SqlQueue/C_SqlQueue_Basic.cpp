#include"C_SqlQueue_Basic.h"
#include<math.h>
#include<stdlib.h>

Status InitQueue(SqlQueue &Q)
{
	Q.base=(ElemType*)malloc(MAXSIZE*sizeof(ElemType));
	if(!Q.base)
		exit(OVERFLOW);
	Q.front=Q.rear=0;
	return OK;
}

Status DestroyQueue(SqlQueue &Q)
{
	if(Q.base)
		free(Q.base);
	Q.base=NULL;
	Q.rear=Q.front=-1;
	return OK;
}

Status ClearQueue(SqlQueue &Q)
{
	Q.rear=Q.front;
	return OK;
}

Status QueueEmpty(SqlQueue Q)
{
	return Q.rear==Q.front?TRUE:FALSE;
}

int QueueLength(SqlQueue Q)
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

Status EnQueue(SqlQueue &Q,ElemType e)
{
	if((Q.rear+1)%MAXSIZE==Q.front)
		return ERROR;
	*(Q.base+Q.rear)=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return OK;
}

Status DeQueue(SqlQueue &Q,ElemType &e)
{
	if(Q.rear==Q.front)
		return ERROR;
	e=*(Q.base+Q.front);
	Q.front=(Q.front+1)%MAXSIZE;
	return OK;
}

Status GetHead(SqlQueue Q,ElemType &e)
{
	if(Q.front==Q.rear)
		return ERROR;
	e=*(Q.base+Q.front);
	return OK;
}
Status QueueTraverse(SqlQueue Q,void (*visit)(ElemType))
{
	while(Q.front!=Q.rear)
	{
		visit(*(Q.base+Q.front));
		Q.front=(Q.front+1)%MAXSIZE;
	}

	return OK;
}