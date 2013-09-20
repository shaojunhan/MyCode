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
}TElemType;
#include"C_BSTree_Basic.h"
void InitDSTable(BSTree &BST)
{//�������:��ƽ����������г�ʼ��
	BST=NULL;
}

void DestroyDSTable(BSTree &BST)
{//��ʼ����:ƽ�������BST����
//�������:����BST
	if(BST)
	{
		DestroyDSTable(BST->lchild);
		DestroyDSTable(BST->rchild);
		free(BST);
		BST=NULL;
	}
}

BSTree SearchDSTable(BSTree BST,KeyType key)
{//��ʼ����:ƽ�������BST����,key�Ǻ͹ؼ���������ͬ�ĸ���ֵ
//�������:����BST�йؼ�����key��ͬ�ļ�¼,���ҵ��򷵻���BST��λ��,���򷵻ؿ�
	BSTree pt;

	pt=BST;
	while(pt)
	{
		if EQ(key,(pt->data).key)
			return pt;
		if LT(key,(pt->data).key)
			pt=pt->lchild;
		else
			pt=pt->rchild;
	}

	return NULL;
}

void L_Rotate(BSTree &BST)
{
	BSTree pt;
	if(BST && BST->rchild)
	{
		pt=BST->rchild;
		BST->rchild=pt->lchild;
		pt->lchild=BST;
		BST=pt;
	}
}

void R_Rotate(BSTree &BST)
{
	BSTree pt;
	if(BST && BST->lchild)
	{
		pt=BST->lchild;
		BST->lchild=pt->rchild;
		pt->rchild=BST;
		BST=pt;
	}
}

void LeftBalance(BSTree &BST)
{
	if(BST && BST->lchild)
	{
		switch(BST->lchild->bf)
		{
		case -1:
			L_Rotate(BST->lchild);
			R_Rotate(BST);
			switch(BST->bf)
			{
			case -1:
				BST->lchild->bf=1;
				BST->rchild->bf=0;
				break;
			case 0:
				BST->lchild->bf=0;
				BST->rchild->bf=0;
				break;
			case 1:
				BST->lchild->bf=0;
				BST->rchild->bf=-1;
				break;
			}
			BST->bf=0;
			break;
		case 1:
			R_Rotate(BST);
			BST->bf=0;
			BST->rchild->bf=0;
			break;
		}
	}
}

void RightBalance(BSTree &BST)
{
	if(BST && BST->rchild)
	{
		switch(BST->rchild->bf)
		{
		case -1:
			L_Rotate(BST);
			BST->bf=0;
			BST->lchild->bf=0;
			break;
		case 1:
			R_Rotate(BST->rchild);
			L_Rotate(BST);
			switch(BST->bf)
			{
			case -1:
				BST->lchild->bf=1;
				BST->rchild->bf=0;
				break;
			case 0:
				BST->lchild->bf=0;
				BST->rchild->bf=0;
				break;
			case 1:
				BST->lchild->bf=0;
				BST->rchild->bf=-1;
				break;
			}
			BST->bf=0;
			break;
		}
	}
}

void InsertBST(BSTree &BST,TElemType data,int &flag)
{//�������:��BST�в����ڹؼ���Ϊdata.key�ļ�¼,�����data,flag���������Ƿ�����
	if(BST==NULL)
	{
		BST=(BSTree)malloc(sizeof(BSTNode));
		if(!BST)
			exit(1);
		BST->lchild=BST->rchild=NULL;
		BST->bf=0;
		BST->data=data;
		flag=1;
	}
	else
	{
		if EQ(data.key,(BST->data).key)
		{
			flag=0;
			return;
		}

		if LT(data.key,(BST->data).key)
		{
			InsertBST(BST->lchild,data,flag);
			if(flag==1)
			{
				switch(BST->bf)
				{
				case -1:
					BST->bf=0;
					flag=0;
					break;
				case 0:
					BST->bf=1;
					flag=1;
					break;
				case 1:
					LeftBalance(BST);
					flag=0;
					break;
				}
			}
		}
		else
		{
			InsertBST(BST->rchild,data,flag);
			if(flag==1)
			{
				switch(BST->bf)
				{
				case -1:
					RightBalance(BST);
					flag=0;
					break;
				case 0:
					BST->bf=-1;
					flag=1;
					break;
				case 1:
					BST->bf=0;
					flag=0;
					break;
				}
			}
		}
	}
}

int InsertDSTable(BSTree &BST,TElemType data)
{//��ʼ����:ƽ�������BST����,data����BST��������������ͬ��һ����ֵ
//�������:����BST��δ�ҵ��ؼ�����data.key��ͬ�ļ�¼,��ִ�в���,����ִ���κβ���
	int flag;
	flag=0;
	InsertBST(BST,data,flag);
	return 0;
}

int DeleteDSTable(BSTree &BST,KeyType key)
{//��ʼ����:ƽ�������BST����,key�Ǻ͹ؼ���������ͬ��һ����ֵ
//�������:����BST���ҵ��ؼ�����key��ͬ�ļ�¼,��ִ��ɾ��,����ִ���κβ���
	return 0;	//�㷨�д�����
}

void TraverseDSTable(BSTree BST,void (*Visit)(TElemType))
{//��ʼ����:ƽ�������BST����,Visit�Ƕ�TElemType��������ִ�з��ʵĺ���
//�������:�����������BST�е�ÿ��������һ��
	if(BST)
	{
		TraverseDSTable(BST->lchild,Visit);
		Visit(BST->data);
		TraverseDSTable(BST->rchild,Visit);
	}
}