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
{//操作结果:构造一个空的动态查找表DT
	DT=NULL;
	return 0;
}

int DestroyDSTable(BiTree &DT)
{//初始条件:动态查找表DT存在
//操作结果:销毁动态查找表DT
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
{//初始条件:动态查找表DT存在,key为和关键字类型相同的给定值
//操作结果:若DT中存在关键字与key相同的记录,则返回该元素的值或在表中的位置,否则返回空
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
{//初始条件:动态查找表DT存在,e为待插入数据元素
//操作结果:若DT中不存在关键字等于e.key的记录,则插入e到DT
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
{//初始条件:动态查找表DT存在,key为和关键字类型相同的给定值
//操作结果:若DT中存在关键字等于key的记录,则删除该记录
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
	if(ptr->lchild)//左子树不空
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
	else//左子树空
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
{//初始条件:动态查找表DT存在,Visit是对结点操作的应用函数
//操作结果:以某种次序对DT中的每个结点调用Visit一次且最多一次.Visit失败,则访问失败.
	if(DT)
	{
		TraverseDSTable(DT->lchild,Visit);
		Visit(DT->data);
		TraverseDSTable(DT->rchild,Visit);
	}
}