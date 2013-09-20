#include"C_JumpTable_LinkList.h"
#include"C_JumpTable_Basic.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	double a=0,b=1;
	char *c[]={"加","减","乘","除"};
	LinkList S;
	InitList(S);

	ListInsertAtHead(S,Div);
	ListInsertAtHead(S,Mult);
	ListInsertAtHead(S,Sub);
	ListInsertAtHead(S,Add);

	printf("请输入a,b的值:");
	scanf("%lf%lf",&a,&b);

	int i=1;
	ElemType e;
	for(i=1;i<=4;i++)
	{
		GetElem(S,i,e);
		printf("%s,结果:%lf\n",c[i-1],e(a,b));
	}

	DestroyList(S);
	system("pause");
	return 0;
}