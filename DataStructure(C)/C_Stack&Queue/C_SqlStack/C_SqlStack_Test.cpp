#include"stdafx.h"
#include"C_SqlStack_Test.h"
#include"C_SqlStack_Basic.h"
#include<stdio.h>
#include<math.h>

void visit(ElemType e)
{
	printf("%c ",e);
}

void test()
{
	char c;
	SqlStack S;
	InitStack(S);
	
	printf("---------------------��������-------------------------\n");
	printf("��ջ�Ƿ�Ϊ��(1-�� 0-��):%d\n",!StackEmpty(S));
	printf("��ջ�ĳ���:%d\n",StackLength(S));

	for(c='A';c<='Z';c+=2)
	{
		Push(S,c);
	}

	printf("������ջ:");
	StackTraverse(S,visit);
	printf("\n");

	printf("��ջ�Ƿ�Ϊ��(1-�� 0-��):%d\n",!StackEmpty(S));
	printf("��ջ�ĳ���:%d\n",StackLength(S));
	
	GetTop(S,c);
	printf("ջ��Ԫ��:%c\n",c);

	printf("������ջ�׵�Ԫ��:");
	while(StackLength(S)>1)
	{
		Pop(S,c);
		printf("%c",c);
	}
	printf("\n");

	printf("��ջ�Ƿ�Ϊ��(1-�� 0-��):%d\n",!StackEmpty(S));
	printf("��ջ�ĳ���:%d\n",StackLength(S));
	
	GetTop(S,c);
	printf("ջ��Ԫ��:%c\n",c);

	ClearStack(S);
	printf("���ջ��:");
	printf("��ջ�Ƿ�Ϊ��(1-�� 0-��):%d\n",!StackEmpty(S));
	printf("��ջ�ĳ���:%d\n",StackLength(S));

	DestroyStack(S);
	printf("-------------------------����ת��-------------------------\n");
	Carry();
}

void Carry()
{
	int m;
	int n;
	char c='+';
	char *Binary="0123456789ABCDEF";
	SqlStack S;

	InitStack(S);

	printf("������Ҫת���Ľ���(��ΧΪ2-16):");
loop1:
	scanf("%d",&n);
	fflush(stdin);
	if(n<2 || n>16)
	{
		printf("���벻��,����������:");
		goto loop1;
	}

	printf("��������Ҫת��������:");
	scanf("%d",&m);
	fflush(stdin);

	if(m<0)
	{
		c='-';
		m*=-1;
	}

	do
	{
		Push(S,Binary[m%n]);
		m/=n;
	}while(m);

	if(c=='-')
		Push(S,c);

	while(!StackEmpty(S))
	{
		Pop(S,c);
		printf("%c",c);
	}
}