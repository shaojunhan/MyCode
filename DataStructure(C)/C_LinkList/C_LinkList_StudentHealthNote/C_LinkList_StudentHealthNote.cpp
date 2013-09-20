// C_LinkList_StudentHealthNote.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"C_LinkList_StudentHealthNote_Basic.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

LinkList L;
Student e;
FILE *in,*out;

void Insert();
void ReadIn();
void DeleteNum();
void DeleteName();
void ModifyNum();
void ModifyName();
void SearchNum();
void SearchName();
void visit(Student e);
void Save();
void exit();

int main()
{
	int key=0;
	char keys[64];
	
	InitList(L);
	
loop2:
	printf("\t\t1.�������в�������(��ѧ�ŷǽ���)\n"
		"\t\t2.���ļ��е����ݲ�������(ѧ�ŷǽ���)\n"
		"\t\t3.��ѧ��ɾ��\n"
		"\t\t4.������ɾ��\n"
		"\t\t5.��ѧ���޸�\n"
		"\t\t6.�������޸�\n"
		"\t\t7.��ѧ�Ų���\n"
		"\t\t8.����������\n"
		"\t\t9.��ʾ���м�¼\n"
		"\t\t10.���浽�ļ�\n"
		"\t\t11.�˳�\n");
	
loop1:
	printf("���������:");
	scanf("%s%*c",keys);
	key=atoi(keys);
	
	switch(key)
	{
	case 1:
		Insert();
		break;
	case 2:
		ReadIn();
		break;
	case 3:
		DeleteNum();
		break;
	case 4:
		DeleteName();
		break;
	case 5:
		ModifyNum();
		break;
	case 6:
		ModifyName();
		break;
	case 7:
		SearchNum();
		break;
	case 8:
		SearchName();
		break;
	case 9:
		DisplayAll(L,visit);
		getchar();
		break;
	case 10:
		Save();
		break;
	case 11:
		exit();
		break;
	default:
		printf("�������!");
		goto loop1;
	}
	system("cls");
	goto loop2;

	system("pause");
	return 0;
}

//InsertAscend
void Insert()
{
	char sex[4];
	int i;
	Student s;
	char c='N';

	printf("�������޸ĺ������ ѧ�� �Ա� ���� �༶ ����״��(1,2,3)");
	scanf("%s%s%s%d%s%d%*c",e.name,e.num,sex,&e.age,e.stuclass,&i);
	if(!strcmp(sex,"��"))
		e.sex=1;
	else
		e.sex=0;
	switch(i)
	{
	case 1:
		e.health=GOOD;
		break;
	case 2:
		e.health=GENERAL;
		break;
	case 3:
		e.health=BAD;
		break;
	}


	if(SearchNum(L,e.num,s))
	{
		printf("�Ѵ��ڸ�ѧ�ŵ�ѧ����Ϣ!�����������...");
		getchar();
		return;
	}

	if(InsertAscend(L,e))
		printf("����ɹ�\n");
	else
		printf("����ʧ��\n");
}

//ReadIn
void ReadIn()
{
	in=fopen("student.bin","rb+");
	if(in)
	{
		ReadIn(L,in);
		printf("��ȡ�ɹ�!");
		fclose(in);
		DisplayAll(L,visit);
	}
	else
	{
		printf("���ļ�ʧ��,���μ̽�����...");
		getchar();
	}
}

//DeleteNum
void DeleteNum()
{
	char num[10];
	char c='N';
	
	printf("������ѧ��");
	scanf("%s%*c",num);
	printf("ȷ��ɾ��?Y/N");
	scanf("%c",&c);
	if(c=='Y' || c=='y')
		if(DeleteNum(L,num,e))
			printf("ɾ���ɹ�\n");
		else
			printf("ɾ��ʧ��\n");
	else
	{
		printf("ɾ���Ѿ�ȡ��,�����������\n");
		getchar();
		return;
	}		
}

//DeleteName
void DeleteName()
{
	char name[20];
	char c='N';
	
	printf("����������");
	scanf("%s%*c",name);
	printf("ȷ��ɾ��?Y/N");
	scanf("%c",&c);
	if(c=='Y' || c=='y')
		if(DeleteName(L,name,e))
			printf("ɾ���ɹ�\n");
		else
			printf("ɾ��ʧ��\n");
		else
		{
			printf("ɾ���Ѿ�ȡ��,�����������\n");
			getchar();
			return;
		}
}

//ModifyNum
void ModifyNum()
{
	char sex[4];
	int i;
	char num[10];
	char c='N';

	printf("������Ҫ�޸ĵ�ѧ��ѧ��:");
	scanf("%s",num);

	printf("�������޸ĺ������ ѧ�� �Ա� ���� �༶ ����״��(1,2,3)");
	scanf("%s%s%s%d%s%d",e.name,e.num,sex,&e.age,e.stuclass,&i);
	if(strcmp(sex,"��"))
		e.sex=1;
	else
		e.sex=0;
	switch(i)
	{
	case 1:
		e.health=GOOD;
		break;
	case 2:
		e.health=GENERAL;
		break;
	case 3:
		e.health=BAD;
		break;
	}

	printf("ȷ���޸�?Y/N");
	scanf("%c",&c);
	if(c=='Y' || c=='y')
		if(ModifyNum(L,num,e))
			printf("�޸ĳɹ�\n");
		else
			printf("�޸�ʧ��\n");
		else
		{
			printf("�޸��Ѿ�ȡ��,�����������\n");
			getchar();
			return;
		}
}

//ModifyName
void ModifyName()
{
	char sex[4];
	int i;
	char name[20];
	char c='N';

	printf("������Ҫ�޸ĵ�ѧ������:");
	scanf("%s",name);

	printf("�������޸ĺ������ ѧ�� �Ա� ���� �༶ ����״��(1,2,3)");
	scanf("%s%s%s%d%s%d",e.name,e.num,sex,&e.age,e.stuclass,&i);
	if(strcmp(sex,"��"))
		e.sex=1;
	else
		e.sex=0;
	switch(i)
	{
	case 1:
		e.health=GOOD;
		break;
	case 2:
		e.health=GENERAL;
		break;
	case 3:
		e.health=BAD;
		break;
	}

	printf("ȷ���޸�?Y/N");
	scanf("%c",&c);
	if(c=='Y' || c=='y')
		if(ModifyName(L,name,e))
			printf("�޸ĳɹ�\n");
		else
			printf("�޸�ʧ��\n");
		else
		{
			printf("�޸��Ѿ�ȡ��,�����������\n");
			getchar();
			return;
		}
		
		
}

//SearchNum
void SearchNum()
{
	char num[10];

	printf("������Ҫ�޸ĵ�ѧ��ѧ��:");
	scanf("%s",num);

	if(SearchNum(L,num,e))
		visit(e);
	else
	{
		printf("����ʧ��!��������Ƿ���ȷ,�����������...");
		getchar();
		return;
	}
}

//SearchName
void SearchName()
{
	char name[20];

	printf("������Ҫ�޸ĵ�ѧ������:");
	scanf("%s",name);

	if(SearchName(L,name,e))
		visit(e);
	else
	{
		printf("����ʧ��!��������Ƿ���ȷ,�����������...");
		getchar();
		return;
	}
	
}

//visit
void visit(Student e)
{
	char sex[4];
	char health[10];
	if(e.sex==1)
		strcpy(sex,"��");
	switch(e.health)
	{
	case GOOD:
		strcpy(health,"����");
		break;
	case GENERAL:
		strcpy(health,"һ��");
		break;
	case BAD:
		strcpy(health,"����");
		break;
	}

	printf("\n����:%s\nѧ��:%s\n����:%d\n�Ա�:%s\n�༶:%s\n����״��:%s"
		,e.name,e.num,e.age,sex,e.stuclass,health);
}

//Save
void Save()
{
	out=fopen("student.bin","wb+");
	if(out)
	{
		Save(L,out);
		fclose(out);
		printf("����ɹ�");
	}
	printf("�����������...");
	getchar();
}
//exit
void exit()
{
	char c='N';
	
	printf("ȷ���˳���Y/N");
	scanf("%c",&c);
	if(c=='Y' || c=='y')
		exit(0);
	else
		printf("�˳��Ѿ�ȡ��\n");
}