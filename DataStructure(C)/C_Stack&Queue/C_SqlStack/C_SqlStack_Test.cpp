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
	printf("-------------------------进制转换-------------------------\n");
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

	printf("请输入要转换的进制(范围为2-16):");
loop1:
	scanf("%d",&n);
	fflush(stdin);
	if(n<2 || n>16)
	{
		printf("输入不符,请重新输入:");
		goto loop1;
	}

	printf("请输入需要转换的数字:");
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