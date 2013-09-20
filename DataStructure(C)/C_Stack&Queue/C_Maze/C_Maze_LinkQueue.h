#ifndef C_Maze_LinkQueue_2012_10_28_16_28
#define C_Maze_LinkQueue_2012_10_28_16_28

#include"C_Maze_Header.h"

typedef struct
{
	Link front;
	Link rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q);
Status DestroyQueue(LinkQueue &Q);
Status CleaerQueue(LinkQueue &Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status EnQueue(LinkQueue &Q,ElemType e);
Status DeQueue(LinkQueue &Q,ElemType &e);
Status GetHead(LinkQueue Q,ElemType &e);
Status QueueTraverse(LinkQueue Q,void (*visit)(ElemType));

#endif