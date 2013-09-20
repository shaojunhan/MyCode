#include"C_BankBusiness_LinkQueue.h"
#include<stdlib.h>
#include<math.h>

Status InitQueue(LinkQueue &Q)
{
    Q.front=(QLink)malloc(sizeof(struct QLNode));
    if(!Q.front)
        exit(OVERFLOW);
    Q.front->next=NULL;
    Q.rear=Q.front;
    return OK;
}

Status DestroyQueue(LinkQueue &Q)
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
Status ClearQueue(LinkQueue &Q)
{
    QLink p=Q.front->next;
    while(p)
    {
        Q.rear=p->next;
        free(p);
        p=Q.rear;
    }
    Q.front->next=NULL;
    Q.rear=Q.front;
    return OK;
}

Status QueueEmpty(LinkQueue Q)
{
    return Q.front==Q.rear?TRUE:FALSE;
}
int QueueLength(LinkQueue Q)
{
    int i=0;
    QLink p=Q.front->next;
    while(p)
    {
        i++;
        p=p->next;
    }

    return i;
}
Status GetHead(LinkQueue Q,QElemType &qe)
{
    if(Q.front==Q.rear)
        return FALSE;
    Q.front=Q.front->next;
    qe=Q.front->data;
    return OK;
}

Status EnQueue(LinkQueue &Q,QElemType qe)
{
    QLink q=(QLink)malloc(sizeof(struct QLNode));
    if(!q)
        return ERROR;
    q->data=qe;
    q->next=Q.rear->next;
    Q.rear->next=q;
    Q.rear=q;
    return OK;
}
Status DeQueue(LinkQueue &Q,QElemType &qe)
{
    if(Q.front==Q.rear)
        return FALSE;
    QLink p=Q.front->next;
    Q.front->next=p->next;
    if(Q.rear==p)
        Q.rear=Q.front;
    qe=p->data;
    free(p);
    return OK;
}
Status QueueTraverse(LinkQueue Q,void (*visit)(QElemType))
{
    if(!Q.front)
        return ERROR;
    Q.front=Q.front->next;
    while(Q.front)
    {
        visit(Q.front->data);
        Q.front=Q.front->next;
    }

    return OK;
}
