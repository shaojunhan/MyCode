#include<stdio.h>
#include<stdlib.h>
#include"C_InsertSort_Header.h"
#define SIZE 10

bool isfirst;
void InsertList(SqList &R);
void InsertList(StaticList &R);
void Visit(RedType red);
void TraverseList(SqList &R,void (*Visit)(RedType));
void TraverseList(StaticList L);

int main(int argc,char *argv[])
{
	SqList R;
	StaticList L;

	printf("输入数据\n");
	isfirst=1;
	InsertList(R);
	printf("---------二路插入排序---------\n");
	P2InsertSort(R,1);
	printf("逆序:\n");
	TraverseList(R,Visit);
	P2InsertSort(R);
	printf("正序:\n");
	TraverseList(R,Visit);

	InsertList(R);
	printf("---------简单插入排序---------\n");
	SimpleInsertSort(R,1);
	printf("逆序:\n");
	TraverseList(R,Visit);
	printf("正序:\n");
	SimpleInsertSort(R);
	TraverseList(R,Visit);

	InsertList(R);
	printf("---------折半插入排序---------\n");
	BinInsertSort(R,1);
	printf("逆序:\n");
	TraverseList(R,Visit);
	BinInsertSort(R);
	printf("正序:\n");
	TraverseList(R,Visit);

	InsertList(R);
	printf("---------谢尔排序-------------\n");
	printf("逆序:\n");
	ShellInsertSort(R,1);
	TraverseList(R,Visit);
	printf("正序:\n");
	ShellInsertSort(R);
	TraverseList(R,Visit);

	InsertList(L);
	printf("---------表插入排序-----------\n");
	printf("逆序:\n");
	TableInsertSort(L,1);
	TraverseList(L);
	printf("正序:\n");
	TableInsertSort(L);
	TraverseList(L);
	system("pause");
	return 0;
}

void InsertList(SqList &R)
{
	int i;
	FILE *fp;

	fp=fopen("test.txt","r");
	if(!fp)
	{
		printf("从文件读入数据出错,请手动输入%d个数据:",SIZE);
		for(i=0;i<=SIZE;i++)
			scanf("%d%s%*c",&R.records[i].key,R.records[i].others);
	}
	else
	{
		for(i=1;i<=SIZE;i++)
		{
			fscanf(fp,"%d%*c%s%*c",&R.records[i].key,R.records[i].others);
			if(isfirst)
				printf("%d %s\n",R.records[i].key,R.records[i].others);
		}
		fclose(fp);
		isfirst=0;
	}
	R.n=i-1;
}

void InsertList(StaticList &R)
{
	int i;
	InitList(R);
	FILE *fp;
	fp=fopen("test.txt","r");
	if(!fp)
	{
		printf("打开文件错误,请手动输入%d个数据:",SIZE);
		for(i=1;i<=SIZE;i++)
			scanf("%d%s%*c",&(R[i].data).key,&(R[i].data).others);
	}
	else
	{
		for(i=1;i<=SIZE;i++)
		{
			fscanf(fp,"%d%s%*c",&(R[i].data).key,&(R[i].data).others);
			if(isfirst)
				printf("%d %s",(R[i].data).key,(R[i].data).others);
		}
		fclose(fp);
		isfirst=0;
	}
	R[i-1].cur=0;
}

void Visit(RedType red)
{
	printf("%d %s\n",red.key,red.others);
}

void TraverseList(SqList &R,void (*Visit)(RedType))
{
	int i;
	for(i=1;i<=R.n;i++)
		Visit(R.records[i]);
}

void TraverseList(StaticList L)
{
	int i;
	i=1;
	while(i<=SIZE)
	{
		printf("%d %s\n",(L[i].data).key,(L[i].data).others);
		i++;
	}
}