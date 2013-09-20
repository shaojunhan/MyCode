#include"C_SelectSort_Header.h"
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
bool isfirst;
void InitList(SqList &R);
void Visit(RedType data);
void TraverseList(SqList R,void (*Visit)(RedType));

int main(int argc,char *argv[])
{
	isfirst=1;
	SqList R;
	InitList(R);
	printf("-----------简单选择排序-----------\n");
	printf("逆序:\n");
	SimpleSelectSort(R,1);
	TraverseList(R,Visit);
	printf("正序:\n");
	SimpleSelectSort(R);
	TraverseList(R,Visit);

	InitList(R);
	printf("-----------堆选择排序-------------\n");
	printf("逆序:\n");
	HeapSelectSort(R,1);
	TraverseList(R,Visit);
	printf("正序:\n");
	HeapSelectSort(R);
	TraverseList(R,Visit);
	system("pause");
	return 0;
}

void InitList(SqList &R)
{
	int i;
	FILE *fp;
	fp=fopen("test.txt","r");
	if(!fp)
	{
		printf("读入数据失败,请手动输入%d个数据:",SIZE);
		for(i=1;i<=SIZE;i++)
			scanf("%d%s%*c",&R.records[i].key,&R.records[i].others);
	}
	else
	{
		for(i=1;i<=SIZE;i++)
		{
			fscanf(fp,"%d%s%*c",&R.records[i].key,&R.records[i].others);
			if(isfirst)
				printf("%d %s\n",R.records[i].key,R.records[i].others);
		}
		isfirst=0;
		fclose(fp);
	}
	R.n=i-1;
}

void Visit(RedType data)
{
	printf("%d %s\n",data.key,data.others);
}

void TraverseList(SqList R,void (*Visit)(RedType))
{
	int i;
	for(i=1;i<=R.n;i++)
		Visit(R.records[i]);
}