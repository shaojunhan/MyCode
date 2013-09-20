#include"C_P2MergeSort.h"
#include<stdio.h>
#include<stdlib.h>
#define SIZE 11
bool isfirst;
void InitList(SqList &R);
void Visit(RedType data);
void TraverseList(SqList R,void (*Visit)(RedType));

int main(int argc,char *argv[])
{
	isfirst=1;
	SqList R;
	InitList(R);
	printf("-----------归并排序-----------\n");
	printf("正序:\n");
	P2MergeSort(R);
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