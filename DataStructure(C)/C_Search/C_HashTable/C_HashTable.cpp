#include<stdio.h>
#include<stdlib.h>
#define SIZE 12
typedef int KeyType;
typedef struct
{
	KeyType key;
	char Sno[11];
	char Name[9];
	char Sex[3];
	unsigned int age;
	char major[31];
}HElemType;
#include"C_HashTable_Basic.h"
void Visit(HElemType e);
//访问数据data
int main(int argc,char *argv[])
{
	HashTable HT;
	HLink pt;
	KeyType key;
	int i;
	HElemType R[]={{1101,"0304110512","胡菲菲","女",21,"生物工程"},
						{1006,"0304110506","李志昌","男",21,"微电子工程"},
						{1005,"0304110505","李经国","男",21,"工程设计"},
						{1104,"0304110510","刘京","女",21,"计算机"},
						{1003,"0304110503","单加猛","男",21,"通信工程"},
						{1004,"0304110504","韩少军","男",23,"软件工程"},
						{1106,"0304110511","朱紫婧","女",21,"信息安全"},
						{1008,"0304110508","刘高鑫","男",21,"物联网"},
						{1001,"0304110501","毕大成","男",21,"动画"},
						{1007,"0304110507","刘春功","男",21,"英语"},
						{1002,"0304110502","程学涵","男",21,"材料工程"},
						{1009,"0304110509","罗金伟","男",21,"机械工程"}};	
	InitDSTable(HT);
	for(i=0;i<SIZE;i++)
	{
		if(!(SearchDSTable(HT,R[i].key)))
			InsertDSTable(HT,R[i]);
	}

	while(1)
	{
		printf("输入搜索关键字,0结束:");
		scanf("%d%*c",&key);
		if(key==0)
			break;
		if((pt=SearchDSTable(HT,key)))
			Visit(pt->data);
		else
			printf("搜索失败!\n");
	}

	TraverseDSTable(HT,Visit);
	DestroyDSTable(HT);
	system("pause");
	return 0;
}

void Visit(HElemType e)
{//访问数据data
	printf("%s %s %s %d %s\n",e.Sno,e.Name,e.Sex,e.age,e.major);
}