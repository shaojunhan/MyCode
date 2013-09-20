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
	
	printf("---------------------基本操作-------------------------\n");
	printf("堆栈是否为空(1-否 0-是):%d\n",!StackEmpty(S));
	printf("堆栈的长度:%d\n",StackLength(S));

	for(c='A';c<='Z';c+=2)
	{
		Push(S,c);
	}

	printf("遍历堆栈:");
	StackTraverse(S,visit);
	printf("\n");

	printf("堆栈是否为空(1-否 0-是):%d\n",!StackEmpty(S));
	printf("堆栈的长度:%d\n",StackLength(S));
	
	GetTop(S,c);
	printf("栈顶元素:%c\n",c);

	printf("弹出除栈底的元素:");
	while(StackLength(S)>1)
	{
		Pop(S,c);
		printf("%c",c);
	}
	printf("\n");

	printf("堆栈是否为空(1-否 0-是):%d\n",!StackEmpty(S));
	printf("堆栈的长度:%d\n",StackLength(S));
	
	GetTop(S,c);
	printf("栈顶元素:%c\n",c);

	ClearStack(S);
	printf("清空栈后:");
	printf("堆栈是否为空(1-否 0-是):%d\n",!StackEmpty(S));
	printf("堆栈的长度:%d\n",StackLength(S));

	DestroyStack(S);
}
