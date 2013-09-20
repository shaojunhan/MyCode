#ifndef C_BANKBUSINESS_LINKQUEUE_H_INCLUDED
#define C_BANKBUSINESS_LINKQUEUE_H_INCLUDED

#include"C_BankBusiness_Header.h"

typedef struct QLNode
{
    QElemType data;
    struct QLNode *next;
}*QLink;

typedef struct
{
    QLink front;
    QLink rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q);
Status DestroyQueue(LinkQueue &Q);
Status ClearQueue(LinkQueue &Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q,QElemType &qe);
Status EnQueue(LinkQueue &Q,QElemType qe);
Status DeQueue(LinkQueue &Q,QElemType &qe);
Status QueueTraverse(LinkQueue Q,void (*visit)(QElemType));

#endif // C_BANKBUSINESS_LINKQUEUE_H_INCLUDED
