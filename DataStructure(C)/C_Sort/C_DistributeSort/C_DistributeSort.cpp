#include"C_BaseSort.h"
#include<stdio.h>
#include<stdlib.h>
#define SIZE 11
void InitList(StaticList &L);
void Visit(ElemType e);
void TraverseList(StaticList L,void (*Visit)(ElemType));
int main(int argc,char *argv[])
{
	StaticList L;
	InitList(L);
	printf("----------基数排序-----------\n");
	printf("正序:\n");
	BaseSort(L);
	TraverseList(L,Visit);
	system("pause");
	return 0;
}
void InitList(StaticList &L)
{
	int count,i;

	count=1;
	FILE *fp;
	fp=fopen("test.txt","r");
	if(!fp)
	{
		printf("读取数据失败,请手动输入%d个数:",SIZE);
		for(i=1;i<=SIZE;i++)
			L[i].cur=i+1;
		L[0].cur=1;
		L[i-1].cur=0;
	}else
	{
		for(i=1;i<=SIZE;i++)
		{
			fscanf(fp,"%d%*c",&L[i].data);
			L[i].cur=i+1;
			printf("%d\n",L[i].data);
		}
		L[0].cur=1;
		L[i-1].cur=0;
	}
}

void Visit(ElemType e)
{
	printf("%d\n",e);
}

void TraverseList(StaticList L,void (*Visit)(ElemType))
{
	int i;
	i=L[0].cur;
	while(i!=0)
	{
		Visit(L[i].data);
		i=L[i].cur;
	}
}