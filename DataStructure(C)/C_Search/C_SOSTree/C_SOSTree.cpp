#include<stdio.h>
#include<stdlib.h>
#define MAX 6
typedef int KeyType;
typedef struct
{
	char Sno[11];
	char Name[9];
	char sex[3];
	unsigned int age;
	char major[21];
}ElemType;
typedef struct
{
	KeyType key;
	int weight;
	ElemType data;
}TElemType;
#include"C_SOSTree_Basic.h"

void Visit(TElemType e);
//��������data
int main(int argc,char *argv[])
{
	int sweight[MAX+1];
	KeyType key;
	int flag;
	BiTree T,p;
	TElemType R[MAX]={{1001,2,{"0304110501","�ϴ��","��",21,"�������ѧ�뼼��"}},
						{1002,6,{"0304110502","��ѧ��","��",21,"�������ѧ�뼼��"}},
						{1003,1,{"0304110503","������","��",21,"�������ѧ�뼼��"}},
						{1004,0,{"0304110504","���پ�","��",23,"�������ѧ�뼼��"}},
						{1005,5,{"0304110505","���","��",21,"�������ѧ�뼼��"}},
						{1006,3,{"0304110506","��־��","��",21,"�������ѧ�뼼��"}}};
	T=NULL;
	FindSW(sweight,R,MAX);
	SecondOptimal(T,sweight,R,1,MAX);
	while(1)
	{
		flag=1;
		printf("�����ѯ�ؼ���,0����:");
		scanf("%d%*c",&key);
		if(key==0)
			break;
		else
			flag=Search(T,key,p);
		if(flag==0)
			Visit(p->data);
	}
	printf("����:\n");
	Traverse(T,Visit);
	DestroyTree(T);
	system("pause");
	return 0;
}

void Visit(TElemType e)
{//��������data
	printf("%s %s %s %d %s\n",e.data.Sno,e.data.Name,e.data.sex,e.data.age,e.data.major);
}