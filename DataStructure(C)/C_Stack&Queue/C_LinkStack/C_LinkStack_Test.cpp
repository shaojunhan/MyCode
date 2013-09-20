#include"C_LinkStack_Test.h"
#include<stdio.h>


void visit(ElemType e)
{
	printf("%3c",e);
}

void test()
{
	int c;
	LinkStack S;
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
}
