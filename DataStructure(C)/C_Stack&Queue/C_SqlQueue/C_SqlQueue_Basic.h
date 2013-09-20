#ifndef C_SqlQueue_Basic_2012_10_19_19_13
#define C_SqlQueue_Basic_2012_10_19_19_13

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

#define MAXSIZE 1000

typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType *base;
	int front;
	int rear;
}SqlQueue;

Status InitQueue(SqlQueue &Q);
Status DestroyQueue(SqlQueue &Q);
Status ClearQueue(SqlQueue &Q);
Status QueueEmpty(SqlQueue Q);
int QueueLength(SqlQueue Q);
Status EnQueue(SqlQueue &Q,ElemType e);
Status DeQueue(SqlQueue &Q,ElemType &e);
Status GetHead(SqlQueue Q,ElemType &e);
Status QueueTraverse(SqlQueue Q,void (*visit)(ElemType));

#endif