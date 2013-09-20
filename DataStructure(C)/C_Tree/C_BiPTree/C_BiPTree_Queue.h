#ifndef C_BiPTree_Queue_2013_2_3_11_27
#define C_BiPTree_Queue_2013_2_3_11_27
//#pragma once

#include"C_BiPTree_Header.h"
#include"C_BiPTree_Basic.h"

typedef BiPTree QElemType;
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
Status EnQueue(Queue &Q,QElemType e);
Status DeQueue(Queue &Q,QElemType &e);
int QueueLength(Queue Q);
bool QueueEmpty(Queue Q);
Status GetHead(Queue Q,QElemType &e);

#endif