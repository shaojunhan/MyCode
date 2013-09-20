#ifndef C_LinkQueue_Basic_2012_10_19_23_10
#define C_LinkQueue_Basic_2012_10_19_23_10

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int ElemType;
typedef int Status;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}*Link;

typedef struct
{
	Link front;
	Link rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q);
Status DestroyQueue(LinkQueue &Q);
Status ClearQueue(LinkQueue &Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q,ElemType &e);
Status EnQueue(LinkQueue &Q,ElemType e);
Status DeQueue(LinkQueue &Q,ElemType &e);
Status QueueTraverse(LinkQueue Q,void (*visit)(ElemType));

#endif