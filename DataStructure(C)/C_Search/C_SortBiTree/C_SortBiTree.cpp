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
//��������data
int main(int argc,char *argv[])
{
	BiTree DT,ptr;
	KeyType key;
	int i;
	TElemType R[MAX]={{1006,"0304110506","��־��","��",21,"΢���ӹ���"},
						{1004,"0304110504","���پ�","��",23,"�������"},
						{1001,"0304110501","�ϴ��","��",21,"�����"},
						{1003,"0304110503","������","��",21,"ͨ�Ź���"},
						{1002,"0304110502","��ѧ��","��",21,"������"},
						{1005,"0304110505","���","��",21,"��Ϣ��ȫ"}};
	InitDSTable(DT);
	for(i=0;i<MAX;i++)
	{
		if(!(SearchDSTable(DT,R[i].key)))
			InsertDSTable(DT,R[i]);
	}

	while(1)
	{
		printf("1.���� 2.ɾ�� 0.����:");
		scanf("%d%*c",&key);
		if(key==0)
			break;
		if(key==1)
		{
			printf("�����ؼ���:");
			scanf("%d%*c",&key);
			if((ptr=SearchDSTable(DT,key)))
				Visit(ptr->data);
			else
				printf("����ʧ��!\n");
		}
		else if(key==2)
		{
			printf("ɾ���ؼ���:");
			scanf("%d%*c",&key);
			if(DeleteDSTable(DT,key)==0)
				printf("ɾ���ؼ���Ϊ%d�ļ�¼�ɹ�.\n",key);
			else
				printf("ɾ���ؼ���Ϊ%d�ļ�¼ʧ��.\n",key);
		}
	}

	TraverseDSTable(DT,Visit);
	DestroyDSTable(DT);
	system("pause");
	return 0;
}

void Visit(TElemType e)
{//��������data
	printf("%s %s %s %d %s\n",e.Sno,e.Name,e.sex,e.age,e.major);
}