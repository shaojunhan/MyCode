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

	printf("�����Ƿ�Ϊ��(1-�ǿ� 0-��):%d\n"
		"���г���:%d\n",!QueueEmpty(Q),QueueLength(Q));

	for(i=0;i<N;i++)
	{
		EnQueue(Q,i+'A');
	}

	printf("��������,���:");
	QueueTraverse(Q,visit);
	printf("\n");

	printf("�����Ƿ�Ϊ��(1-�ǿ� 0-��):%d\n"
		"���г���:%d\n",!QueueEmpty(Q),QueueLength(Q));

	printf("��������βԪ��:");
	while(QueueLength(Q)>1)
	{
		DeQueue(Q,n);
		printf("%3c",n);
	}
	printf("\n");

	GetHead(Q,n);
	printf("���ͷԪ��:%c\n",n);
	
	ClearQueue(Q);
	printf("��ն��к�:");
	QueueTraverse(Q,visit);
	printf("\n");

	for(i=N-1;i>=0;i--)
	{
		EnQueue(Q,i+'A');
	}
	printf("�ٴη�����Ӻ�:");
	QueueTraverse(Q,visit);
	printf("\n");

	printf("���ٶ���(1-�ɹ� 0-ʧ��):%d",DestroyQueue(Q));
}