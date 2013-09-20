#include"C_LinkQueue_Test.h"
#include<stdio.h>

void visit(ElemType e)
{
	printf("%3c",e);
}

void test()
{
	int i;
	int n;
	const N=10;
	LinkQueue Q;
	InitQueue(Q);

	printf("队列是否为空(1-非空 0-空):%d\n"
		"队列长度:%d\n",!QueueEmpty(Q),QueueLength(Q));

	for(i=0;i<N;i++)
	{
		EnQueue(Q,i+'A');
	}

	printf("遍历队列,结果:");
	QueueTraverse(Q,visit);
	printf("\n");

	printf("队列是否为空(1-非空 0-空):%d\n"
		"队列长度:%d\n",!QueueEmpty(Q),QueueLength(Q));

	printf("弹出除队尾元素:");
	while(QueueLength(Q)>1)
	{
		DeQueue(Q,n);
		printf("%3c",n);
	}
	printf("\n");

	GetHead(Q,n);
	printf("获得头元素:%c\n",n);
	
	ClearQueue(Q);
	printf("清空队列后:");
	QueueTraverse(Q,visit);
	printf("\n");

	for(i=N-1;i>=0;i--)
	{
		EnQueue(Q,i+'A');
	}
	printf("再次反向入队后:");
	QueueTraverse(Q,visit);
	printf("\n");

	printf("销毁队列(1-成功 0-失败):%d",DestroyQueue(Q));
}