#include"C_Hanoi_Basic.h"
#include<stdlib.h>
#include<stdio.h>
#include<sys/timeb.h>

#include<stdlib.h>
#include<assert.h>
#include<afx.h>

int main(int argc, char *argv[])
{
	printf("HelloWorld!\n");

	int i=0;
	for(i=0;i<10;i++)
	{
		Sleep(50);
		int j=0;for(j=0;j<i%10;j++)printf("%c",'*');printf("\n");
	}
	TRACE("%d",i);
	system("pause");

	//TODO:helloworld
	return 0;
}

/*
int main(int argc,char *argv[])
{
	char a,b,c;
	int n=0;
	a='A',b='B',c='C';
	timeb t1,t2;

	printf("输入汉诺塔等级(1--):");
loop1:
	scanf("%d%*c",&n);

	if(n<=0)
	{
		printf("输入错误,请重新输入:");
		goto loop1;
	}

	printf("把%d个从%c移动到%c:\n",n,a,c);
	
	ftime(&t1);
	Hanoi(n,a,b,c);
	ftime(&t2);

	double t=(t2.time-t1.time)*1000+t2.millitm-t1.millitm;
	t=t/1000;
	printf("程序耗时:%.5lf秒",t);



	system("pause");
	return 0;
}
*/