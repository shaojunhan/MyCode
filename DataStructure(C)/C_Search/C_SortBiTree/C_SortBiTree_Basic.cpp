#include"E:\Document\Data Structures\Study\C_Search\C_Search_Header.h"
#include<stdio.h>
#include<stdlib.h>

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
int InitDSTable(BiTree &DT)
{//�������:����һ���յĶ�̬���ұ�DT
	DT=NULL;
	return 0;
}

int DestroyDSTable(BiTree &DT)
{//��ʼ����:��̬���ұ�DT����
//�������:���ٶ�̬���ұ�DT
	if(DT)
	{
		DestroyDSTable(DT->lchild);
		DestroyDSTable(DT->rchild);
		free(DT);
		DT=NULL;
		return 0;
	}
	return 1;
}

BiTree SearchDSTable(BiTree &DT,KeyType key)
{//��ʼ����:��̬���ұ�DT����,keyΪ�͹ؼ���������ͬ�ĸ���ֵ
//�������:��DT�д��ڹؼ�����key��ͬ�ļ�¼,�򷵻ظ�Ԫ�ص�ֵ���ڱ��е�λ��,���򷵻ؿ�
	BiTree ptr;

	ptr=DT;
	while(ptr)
	{
		if EQ(key,(ptr->data).key)
			return ptr;
		if LT(key,(ptr->data).key)
			ptr=ptr->lchild;
		else
			ptr=ptr->rchild;
	}
	return NULL;
}

int InsertDSTable(BiTree &DT,TElemType e)
{//��ʼ����:��̬���ұ�DT����,eΪ����������Ԫ��
//�������:��DT�в����ڹؼ��ֵ���e.key�ļ�¼,�����e��DT
	BiTree ptr,pre;
	pre=NULL;
	ptr=DT;
	while(ptr)
	{
		if EQ(e.key,(ptr->data).key)
			return 0;
		pre=ptr;
		if LT(e.key,(ptr->data).key)
			ptr=ptr->lchild;
		else
			ptr=ptr->rchild;
	}

	if(pre==NULL)
	{
		DT=(BiTree)malloc(sizeof(BTNode));
		if(!DT)
			exit(1);
		DT->lchild=DT->rchild=NULL;
		DT->data=e;
		return 0;
	}

	if LT(e.key,(pre->data).key)
	{
		pre->lchild=(BiTree)malloc(sizeof(BTNode));
		if(!pre->lchild)
			exit(1);
		pre->lchild->lchild=pre->lchild->rchild=NULL;
		pre->lchild->data=e;
	}
	else
	{
		pre->rchild=(BiTree)malloc(sizeof(BTNode));
		if(!pre->rchild)
			exit(1);
		pre->rchild->lchild=pre->rchild->rchild=NULL;
		pre->rchild->data=e;
	}
	return 0;
}

int DeleteDSTable(BiTree &DT,KeyType key)
{//��ʼ����:��̬���ұ�DT����,keyΪ�͹ؼ���������ͬ�ĸ���ֵ
//�������:��DT�д��ڹؼ��ֵ���key�ļ�¼,��ɾ���ü�¼
	BiTree ptr,pre,p;

	pre=NULL;
	ptr=DT;
	while(ptr)
	{
		if EQ(key,(ptr->data).key)
			break;
		pre=ptr;
		if LT(key,(ptr->data).key)
			ptr=ptr->lchild;
		else
			ptr=ptr->rchild;
	}

	if(ptr==NULL)
		return 1;
	if(ptr->lchild)//����������
	{
		p=ptr->lchild;
		while(p->rchild)
		{
			pre=p;
			p=pre->rchild;
		}

		if(p==ptr->lchild)
		{
			ptr->data=p->data;
			ptr->lchild=p->lchild;
			free(ptr);
		}
		else
		{
			ptr->data=p->data;
			pre->rchild=p->lchild;
			free(p);
		}
	}
	else//��������
	{
		if(ptr==DT)
		{
			DT=ptr->rchild;
			free(ptr);
		}
		else
		{
			if(pre->lchild==ptr)
				pre->lchild=ptr->rchild;
			else
				pre->rchild=ptr->rchild;
			free(ptr);
		}
	}
	return 0;
}

void TraverseDSTable(BiTree DT,void (*Visit)(TElemType))
{//��ʼ����:��̬���ұ�DT����,Visit�ǶԽ�������Ӧ�ú���
//�������:��ĳ�ִ����DT�е�ÿ��������Visitһ�������һ��.Visitʧ��,�����ʧ��.
	if(DT)
	{
		TraverseDSTable(DT->lchild,Visit);
		Visit(DT->data);
		TraverseDSTable(DT->rchild,Visit);
	}
}