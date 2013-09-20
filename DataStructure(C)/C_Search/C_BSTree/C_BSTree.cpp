#include<stdio.h>
#include<stdlib.h>
#define MAX 12
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
#include"C_BSTree_Basic.h"
void Visit(TElemType e);
//��������data
int main(int argc,char *argv[])
{
	BSTree BST,ptr;
	KeyType key;
	int i;
	TElemType R[MAX]={{1012,"0304110512","���Ʒ�","Ů",21,"���﹤��"},
						{1006,"0304110506","��־��","��",21,"΢���ӹ���"},
						{1005,"0304110505","���","��",21,"�������"},
						{1010,"0304110510","����","Ů",21,"�����"},
						{1003,"0304110503","������","��",21,"ͨ�Ź���"},
						{1004,"0304110504","���پ�","��",23,"�������"},
						{1011,"0304110511","�����","Ů",21,"��Ϣ��ȫ"},
						{1008,"0304110508","������","��",21,"������"},
						{1001,"0304110501","�ϴ��","��",21,"����"},
						{1007,"0304110507","������","��",21,"Ӣ��"},
						{1002,"0304110502","��ѧ��","��",21,"���Ϲ���"},
						{1009,"0304110509","�޽�ΰ","��",21,"��е����"}};
	InitDSTable(BST);
	for(i=0;i<MAX;i++)
	{
		if(!(SearchDSTable(BST,R[i].key)))
			InsertDSTable(BST,R[i]);
	}

	while(1)
	{
		printf("���������ؼ���,0����:");
		scanf("%d%*c",&key);
		if(key==0)
			break;
		if((ptr=SearchDSTable(BST,key)))
			Visit(ptr->data);
		else
			printf("����ʧ��!\n");
	}

	TraverseDSTable(BST,Visit);
	DestroyDSTable(BST);
	system("pause");
	return 0;
}

void Visit(TElemType e)
{//��������data
	printf("%s %s %s %d %s\n",e.Sno,e.Name,e.sex,e.age,e.major);
}