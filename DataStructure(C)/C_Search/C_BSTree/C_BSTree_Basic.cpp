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
{//操作结果:对平衡二叉树进行初始化
	BST=NULL;
}

void DestroyDSTable(BSTree &BST)
{//初始条件:平衡二叉树BST存在
//操作结果:销毁BST
	if(BST)
	{
		DestroyDSTable(BST->lchild);
		DestroyDSTable(BST->rchild);
		free(BST);
		BST=NULL;
	}
}

BSTree SearchDSTable(BSTree BST,KeyType key)
{//初始条件:平衡二叉树BST存在,key是和关键字类型相同的给定值
//操作结果:搜索BST中关键字与key相同的记录,若找到则返回在BST中位置,否则返回空
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
{//操作结果:若BST中不存在关键字为data.key的记录,则插入data,flag返回子树是否增长
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
{//初始条件:平衡二叉树BST存在,data是与BST中数据域类型相同的一给定值
//操作结果:若在BST中未找到关键字与data.key相同的记录,则执行插入,否则不执行任何操作
	int flag;
	flag=0;
	InsertBST(BST,data,flag);
	return 0;
}

int DeleteDSTable(BSTree &BST,KeyType key)
{//初始条件:平衡二叉树BST存在,key是和关键字类型相同的一给定值
//操作结果:若在BST中找到关键字与key相同的记录,则执行删除,否则不执行任何操作
	return 0;	//算法有待补充
}

void TraverseDSTable(BSTree BST,void (*Visit)(TElemType))
{//初始条件:平衡二叉树BST存在,Visit是对TElemType数据类型执行访问的函数
//操作结果:以中序遍历对BST中的每个结点访问一次
	if(BST)
	{
		TraverseDSTable(BST->lchild,Visit);
		Visit(BST->data);
		TraverseDSTable(BST->rchild,Visit);
	}
}