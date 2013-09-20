#include"stdafx.h"
#include"C_AlgorithmTime_Header.h"
#include<stdio.h>

void fun1()
{
	timeb t1,t2;
	int n;
	double x;
	double sum1=1, sum=0;
	printf("please input x(x!=0) and n(n>0):");
	scanf("%lf%d",&x,&n);

	ftime(&t1);
	for(int i=0; i<n; i++)
	{
		sum1=1;
		for(int j=0; j<=i; j++)
			sum1*=(-1.0)/x;
		sum+=sum1;
	}
	sum+=1.0;
	ftime(&t2);
	printf("result:\nsum=%lf time=%lf",sum,	(double)(t2.time - t1.time));
}


void fun2()
{
	timeb t1,t2;
	int n;
	double x;
	double sum1=1, sum=0;
	printf("please input x(x!=0) and n(n>0):");
	scanf("%lf%d",&x,&n);

	ftime(&t1);
	for(int i=0; i<n; i++)
	{
		sum1*=(-1.0)/x;
		sum+=sum1;
	}
	sum+=1.0;
	ftime(&t2);
	printf("result:\nsum=%lf time=%lf",sum,	(double)(t2.time - t1.time));
}