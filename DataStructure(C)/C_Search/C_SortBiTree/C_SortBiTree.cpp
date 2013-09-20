#include<stdio.h>
#include<stdlib.h>
#define MAX 6
typedef int KeyType;
typedef struct
{
	KeyType key;
	char Sno[11];
	char Name[9];
	char sex[3];
	unsigned int age;
	char major[31];
}TElemType;
#include"C_SortBiTree_Basic.h"
void Visit(TElemType e);
//访问数据data
int main(int argc,char *argv[])
{
	BiTree DT,ptr;
	KeyType key;
	int i;
	TElemType R[MAX]={{1006,"0304110506","李志昌","男",21,"微电子工程"},
						{1004,"0304110504","韩少军","男",23,"软件工程"},
						{1001,"0304110501","毕大成","男",21,"计算机"},
						{1003,"0304110503","单加猛","男",21,"通信工程"},
						{1002,"0304110502","程学涵","男",21,"物联网"},
						{1005,"0304110505","李经国","男",21,"信息安全"}};
	InitDSTable(DT);
	for(i=0;i<MAX;i++)
	{
		if(!(SearchDSTable(DT,R[i].key)))
			InsertDSTable(DT,R[i]);
	}

	while(1)
	{
		printf("1.搜索 2.删除 0.结束:");
		scanf("%d%*c",&key);
		if(key==0)
			break;
		if(key==1)
		{
			printf("搜索关键字:");
			scanf("%d%*c",&key);
			if((ptr=SearchDSTable(DT,key)))
				Visit(ptr->data);
			else
				printf("搜索失败!\n");
		}
		else if(key==2)
		{
			printf("删除关键字:");
			scanf("%d%*c",&key);
			if(DeleteDSTable(DT,key)==0)
				printf("删除关键字为%d的记录成功.\n",key);
			else
				printf("删除关键字为%d的记录失败.\n",key);
		}
	}

	TraverseDSTable(DT,Visit);
	DestroyDSTable(DT);
	system("pause");
	return 0;
}

void Visit(TElemType e)
{//访问数据data
	printf("%s %s %s %d %s\n",e.Sno,e.Name,e.sex,e.age,e.major);
}