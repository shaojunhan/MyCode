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
//��������data
int main(int argc,char *argv[])
{
	HashTable HT;
	HLink pt;
	KeyType key;
	int i;
	HElemType R[]={{1101,"0304110512","���Ʒ�","Ů",21,"���﹤��"},
						{1006,"0304110506","��־��","��",21,"΢���ӹ���"},
						{1005,"0304110505","���","��",21,"�������"},
						{1104,"0304110510","����","Ů",21,"�����"},
						{1003,"0304110503","������","��",21,"ͨ�Ź���"},
						{1004,"0304110504","���پ�","��",23,"�������"},
						{1106,"0304110511","�����","Ů",21,"��Ϣ��ȫ"},
						{1008,"0304110508","������","��",21,"������"},
						{1001,"0304110501","�ϴ��","��",21,"����"},
						{1007,"0304110507","������","��",21,"Ӣ��"},
						{1002,"0304110502","��ѧ��","��",21,"���Ϲ���"},
						{1009,"0304110509","�޽�ΰ","��",21,"��е����"}};	
	InitDSTable(HT);
	for(i=0;i<SIZE;i++)
	{
		if(!(SearchDSTable(HT,R[i].key)))
			InsertDSTable(HT,R[i]);
	}

	while(1)
	{
		printf("���������ؼ���,0����:");
		scanf("%d%*c",&key);
		if(key==0)
			break;
		if((pt=SearchDSTable(HT,key)))
			Visit(pt->data);
		else
			printf("����ʧ��!\n");
	}

	TraverseDSTable(HT,Visit);
	DestroyDSTable(HT);
	system("pause");
	return 0;
}

void Visit(HElemType e)
{//��������data
	printf("%s %s %s %d %s\n",e.Sno,e.Name,e.Sex,e.age,e.major);
}