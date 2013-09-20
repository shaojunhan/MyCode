#ifndef C_SqBiTree_Queue_2013_1_30_20_53
#define C_SqBiTree_Queue_2013_1_30_20_53
//#pragma

#include"C_SqBiTree_Header.h"
typedef struct QLNode
{
	QElemType e;
	struct QLNode *next;
}*Link;

typedef struct
{
	Link front,rear;
}Queue;

Status InitQueue(Queue &Q);
Status DestroyQueue(Queue &Q);
bool QueueEmpty(Queue &Q);
Status EnQueue(Queue &Q,QElemType e);
Status DeQueue(Queue &Q,QElemType &e);
Status GetHead(Queue Q,QElemType &e);
#endif