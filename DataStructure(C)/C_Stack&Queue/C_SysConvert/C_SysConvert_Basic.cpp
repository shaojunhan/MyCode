#include"C_SysConvert_Basic.h"
#include"C_SysConvert_LinkStack.h"
#include"C_SysConvert_SqStack.h"
#include<stdio.h>

void Convert(long dec,int n)
{
	char *b="0123456789ABCDEF";
	bool flag=0;
	char c;
	int k;
	SqStack QS;
	LinkStack LS;

	InitStack(QS);
	InitStack(LS);

	if(dec<=0)
	{
		flag=1;
		dec=-dec;
	}

	while(dec)
	{
		k=dec%n;
		Push(QS,b[k]);
		Push(LS,b[k]);
		dec/=n;
	}

	if(flag)
	{
		Push(QS,'-');
		Push(LS,'-');
	}

	while(!StackEmpty(QS))
	{
		Pop(QS,c);
		printf("%c",c);
	}
	printf("\n");

	while(!StackEmpty(LS))
	{
		Pop(LS,c);
		printf("%c",c);
	}
}
