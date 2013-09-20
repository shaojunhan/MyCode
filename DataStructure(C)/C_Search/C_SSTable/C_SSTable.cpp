#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef int ElemType;
typedef char KeyType;
typedef struct
{
	KeyType key;
	ElemType data;
}SElemType;

#include"C_SSTable_Basic.h"

void Visit(SElemType e);
//输出元素的key,data
int main(int argc,char *argv[])
{
	int flag;
	int pos;
	SElemType R[MAX]={{'C',80},{'B',90},{'D',70},{'A',100},{'E',60}};
	SSTable ST;
	KeyType key;

	Create_OR(ST,R,MAX);
	flag=0;
	while(1)
	{
		printf("输入要搜索的成绩分组(A-E),输入#结束程序:");
		scanf("%c%*c",&key);
		if(key=='#')
			break;
		else if(flag%2==0)
			pos=Search_IR(ST,key);
		else
			pos=Search_BIN(ST,key);
		if(pos>0)
			Visit(*(ST.elem+pos));
		flag++;
		printf("遍历为:\n");
		Traverse(ST,Visit);
	}
	DestroyTable(ST);
	system("pause");
	return 0;
}

void Visit(SElemType e)
{//输出元素的key,data
	printf("%c %d\n",e.key,e.data);
}