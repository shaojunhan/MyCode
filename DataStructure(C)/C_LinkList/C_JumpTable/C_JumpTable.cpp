#include"C_JumpTable_LinkList.h"
#include"C_JumpTable_Basic.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	double a=0,b=1;
	char *c[]={"��","��","��","��"};
	LinkList S;
	InitList(S);

	ListInsertAtHead(S,Div);
	ListInsertAtHead(S,Mult);
	ListInsertAtHead(S,Sub);
	ListInsertAtHead(S,Add);

	printf("������a,b��ֵ:");
	scanf("%lf%lf",&a,&b);

	int i=1;
	ElemType e;
	for(i=1;i<=4;i++)
	{
		GetElem(S,i,e);
		printf("%s,���:%lf\n",c[i-1],e(a,b));
	}

	DestroyList(S);
	system("pause");
	return 0;
}