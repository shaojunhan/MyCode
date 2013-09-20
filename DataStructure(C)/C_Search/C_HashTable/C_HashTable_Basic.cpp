#include"E:\Document\Data Structures\Study\C_Search\C_Search_Header.h"
#include<stdlib.h>

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

void InitDSTable(HashTable &HT)
{//�������:��ʼ����ϣ��
	int i;
	for(i=0;i<MAX;i++)
		HT[i]=NULL;
}

void DestroyDSTable(HashTable &HT)
{//��ʼ����:��ϣ��HT����
//�������:����HT
	int i;
	HLink pt,pr;
	for(i=0;i<MAX;i++)
	{
		pt=HT[i];
		while(pt)
		{
			pr=pt->next;
			free(pt);
			pt=pr;
		}
	}
}

HLink SearchDSTable(HashTable HT,KeyType key)
{//��ʼ����:��ϣ��HT����,key����ؼ���������ͬ��һ����ֵ
//�������:����HT�йؼ�����key��ͬ�ļ�¼,�ҵ���������λ��(ָ��),δ�ҵ����ؿ�
	int index;
	HLink pt;

	index=key%MAX;
	pt=HT[index];
	while(pt)
	{
		if EQ(key,(pt->data).key)
			return pt;
		pt=pt->next;
	}

	return NULL;
}

int InsertDSTable(HashTable &HT,HElemType data)
{//��ʼ����:��ϣ��HT����,data����HT�м�¼������ͬ��һ����ֵ
//�������:����HT�йؼ�����data.key��ͬ�ļ�¼,�ҵ����ز���ʧ��(1),δ�ҵ���ִ�в��뷵�ز���ɹ�(0)
	int index;
	HLink pt,p;

	index=data.key%MAX;

	if(HT[index]==NULL || LT(data.key,(HT[index]->data).key))
	{
		p=(HLink)malloc(sizeof(HNode));
		if(!p)
			exit(1);
		p->data=data;
		p->next=HT[index];
		HT[index]=p;
		return 0;
	}
	else
	{
		for(pt=HT[index];pt->next && LT((pt->next->data).key,data.key);pt=pt->next)
			if(!pt->next || LT(data.key,(pt->next->data).key))
			{
				p=(HLink)malloc(sizeof(HNode));
				if(!p)
					exit(1);
				p->data=data;
				p->next=pt->next;
				pt->next=p;
				return 0;
			}
	}
	return 1;
}

int DeleteDSTable(HashTable &HT,KeyType key)
{//��ʼ����:��ϣ��HT����,key����ؼ���������ͬ��һ����ֵ
//�������:��HT���������ؼ�����key��ͬ�ļ�¼,��ִ��ɾ������ɾ���ɹ�(0),���򷵻�ɾ��ʧ��(1)
	HLink pt,pre;
	int index;

	index=key%MAX;
	
	pre=NULL;
	pt=HT[index];
	while(pt)
	{
		if EQ((pt->data).key,key)
			break;
		pre=pt;
		pt=pt->next;
	}
	if(pt)
	{
		if(pre==NULL)
		{
			HT[index]=pt->next;
			free(pt);
		}
		else
		{
			pre->next=pt->next;
			free(pt);
		}
		return 0;
	}
	return 1;
}

void TraverseDSTable(HashTable HT,void (*Visit)(HElemType))
{//��ʼ����:��ϣ��HT����,Visit�Ƕ�HElemType���ͽ��з��ʵĺ���
//�������:��HT�м�¼����һ��
	int i;
	HLink pt;

	for(i=0;i<MAX;i++)
	{
		pt=HT[i];
		while(pt)
		{
			Visit(pt->data);
			pt=pt->next;
		}
	}
}