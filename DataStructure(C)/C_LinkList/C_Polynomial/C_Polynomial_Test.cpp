#include"stdafx.h"
#include"C_Polynomial_Test.h"
#include<stdio.h>

void test()
{
	Polynomial Pa,Pb;
	int m;

	printf("���������ʽA������:");
loop1:
	scanf("%d%*c",&m);
	if(m<0)
	{
		printf("�������,����������:");
		goto loop1;
	}
	CreatePolyn(Pa,m);
	
	printf("���������ʽB������:");
loop2:
	scanf("%d%*c",&m);
	if(m<0)
	{
		printf("�������,����������:");
		goto loop2;
	}
	CreatePolyn(Pb,m);

	printf("���Զ���ʽ�ӷ�:\n");
	AddPolyn(Pa,Pb);
	PrintPolyn(Pa);

	printf("���Զ���ʽ����:\n");
	SubPolyn(Pa,Pb);
	PrintPolyn(Pa);

	printf("���Զ���ʽ�˷�:\n");
	MultiplyPolyn(Pa,Pb);
	PrintPolyn(Pa);
}