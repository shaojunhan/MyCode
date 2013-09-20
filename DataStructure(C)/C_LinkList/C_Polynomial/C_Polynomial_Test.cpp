#include"stdafx.h"
#include"C_Polynomial_Test.h"
#include<stdio.h>

void test()
{
	Polynomial Pa,Pb;
	int m;

	printf("请输入多项式A的项数:");
loop1:
	scanf("%d%*c",&m);
	if(m<0)
	{
		printf("输入错误,请重新输入:");
		goto loop1;
	}
	CreatePolyn(Pa,m);
	
	printf("请输入多项式B的项数:");
loop2:
	scanf("%d%*c",&m);
	if(m<0)
	{
		printf("输入错误,请重新输入:");
		goto loop2;
	}
	CreatePolyn(Pb,m);

	printf("测试多项式加法:\n");
	AddPolyn(Pa,Pb);
	PrintPolyn(Pa);

	printf("测试多项式剑法:\n");
	SubPolyn(Pa,Pb);
	PrintPolyn(Pa);

	printf("测试多项式乘法:\n");
	MultiplyPolyn(Pa,Pb);
	PrintPolyn(Pa);
}