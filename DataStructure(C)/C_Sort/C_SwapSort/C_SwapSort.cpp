#include<stdio.h>
#include<stdlib.h>
#include"C_SwapSort_Header.h"
#define SIZE 10

bool isfirst;
void InsertList(SqList &R);
void Visit(RedType red);
void TraverseList(SqList &R,void (*Visit)(RedType));

int main(int argc,char *argv[])
{
	SqList R;

	printf("��������\n");
	isfirst=1;
	InsertList(R);
	printf("---------ð������---------\n");
	BubbleSort(R,1);
	printf("����:\n");
	TraverseList(R,Visit);
	BubbleSort(R);
	printf("����:\n");
	TraverseList(R,Visit);

	InsertList(R);
	printf("---------��������---------\n");
	QuikSort(R,1);
	printf("����:\n");
	TraverseList(R,Visit);
	QuikSort(R);
	printf("����:\n");
	TraverseList(R,Visit);
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
		printf("���ļ��������ݳ���,���ֶ�����%d������:",SIZE);
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
