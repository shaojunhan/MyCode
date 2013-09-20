#ifndef C_BiTree_Queue_2013_1_31_21_21
#define C_BiTree_Queue_2013_1_31_21_21
//#pragma once

#include"C_BiTree_Header.h"
#include"C_BiTree_Basic.h"
typedef BiTree QElemType;
typedef struct QLNode
{
	QElemType e;
	struct QLNode *next;
}*QLink;

typedef struct
{
	QLink front,rear;
}Queue;

Status InitQueue(Queue &Q);
Status DestroyQueue(Queue &Q);
Status ClearQueue(Queue &Q);
bool QueueEmpty(Queue Q);
int QueueLength(Queue Q);
Status EnQueue(Queue &Q,QElemType e);
Status DeQueue(Queue &Q,QElemType &e);
Status GetHead(Queue Q,QElemType &e);

#endif