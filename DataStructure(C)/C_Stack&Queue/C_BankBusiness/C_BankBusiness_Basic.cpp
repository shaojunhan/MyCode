#include"C_BankBusiness_Basic.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int MAXTIME=100;
int TotalTime=0;

Status OpenForDay(LinkList &L)
{
	SElemType s;
	int i=0;

	s.OccurTime=0;
	s.NType=Qu;
	TotalTime=0;
	return ListOrderInsert(L,s,compare);
}

int compare(SElemType e1,SElemType e2)
{
	return e1.OccurTime>e2.OccurTime?1:e1.OccurTime==e2.OccurTime?0:-1;
}

void Random(int &ArriveTime,int &Duration)
{
	srand(time(NULL));
	ArriveTime=rand()%Interval+1;
	Duration=rand()%Delay+1;
}

Status ListOrderInsert(LinkList &L,SElemType e,int (*compare)(SElemType,SElemType))
{
	SLink p=L;
	SLink q;
	while(p->next && compare(p->next->data,e)<0)
		p=p->next;
	q=(SLink)malloc(sizeof(struct SLNode));
	if(!q)
		return ERROR;
	q->data=e;
	q->next=p->next;
	p->next=q;
	return OK;
}

int Minmum(LinkQueue Q[])
{
	int len[Qu];
	int i=0;
	int min;

	for(i=0;i<Qu;i++)
		len[i]=QueueLength(Q[i]);

	min=0;
	for(i=0;i<Qu;i++)
	{
		if(len[min]>len[i])
			min=i;
	}

	return min;
}

//处理客户离开事件
void CustomerDeparture(LinkList &L,LinkQueue Q[],SElemType e)
{
	int i=0;
	QElemType qe;
	SElemType le;

	i=e.NType;
	DeQueue(Q[i],qe);
	if(!QueueEmpty(Q[i]))
	{
		if(GetHead(Q[i],qe))
		{
			le.OccurTime=qe.ArrivedTime+qe.Duration;
			le.NType=i;
			ListOrderInsert(L,le,compare);
		}
	}
}

int CustomerArrived(LinkList &L,LinkQueue Q[],SElemType e)
{
	SElemType le,le2;
	QElemType qe;
	int i;
	int interval,duration;

	Random(interval,duration);

	//到达事件进队
	qe.ArrivedTime=e.OccurTime;
	qe.Duration=duration;
	i=Minmum(Q);
	EnQueue(Q[i],qe);

	//队头的离开事件
	if(QueueLength(Q[i])==1)
	{
		le2.OccurTime=qe.ArrivedTime+qe.Duration;
		le2.NType=i;
		ListOrderInsert(L,le2,compare);
	}

	//生成下一个到达事件
	le.OccurTime=e.OccurTime+interval;
	le.NType=Qu;
	ListOrderInsert(L,le,compare);
	//总的抵达时间
	TotalTime+=Interval;

	return i;
}

void Bank_Simulation()
{
	SElemType se;
	LinkList L;
	LinkQueue Q[Qu];
	int total1=0,total2=0;
	int i=0,j=0;

	InitList(L);
	for(i=0;i<Qu;i++)
		InitQueue(Q[i]);

	OpenForDay(L);
	while(!ListEmpty(L) && TotalTime<MAXTIME)
	{
		ListDelete(L,1,se);
		switch(se.NType)
		{
		case Qu:
			j=CustomerArrived(L,Q,se);
			total2++;
			printf("第%d个客户-----到达-----%d号窗口\n",total2,j);
			break;
		default:
			CustomerDeparture(L,Q,se);
			total1++;
			printf("第%d个客户-----离开-----%d号窗口\n",total1,se.NType);
			break;
		}
	}

	while(!ListEmpty(L))
	{
		ListDelete(L,1,se);
		if(se.NType!=Qu)
		{
			CustomerDeparture(L,Q,se);
			total1++;
			printf("第%d个客户----离开-----%d号窗口\n",total1,se.NType);
		}
	}
}
