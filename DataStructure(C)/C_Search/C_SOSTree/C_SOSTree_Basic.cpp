#include"E:\Document\Data Structures\Study\C_Search\C_Search_Header.h"
#include<stdlib.h>
#include<math.h>

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
int SecondOptimal(BiTree &T,int sweight[],TElemType R[],int low,int high)
{//T为待创建的树,sweight为权值和的集合,sweight[0]=0,R为数据数组,low,high为R数组下标
//根据权值创建次优查找树T,成功返回0
	int i,j;
	int dw,min;
	i=low;
	dw=sweight[high]+sweight[low-1];
	min=sweight[low];
	for(j=low+1;j<=high;j++)
	{
		if(fabs((dw-sweight[j]-sweight[j-1]))<min)//j左右两部分权值和的差最小
		{
			i=j;
			min=fabs(dw-sweight[j]-sweight[j-1]);
		}
	}

	T=(BiTree)malloc(sizeof(BTNode));
	if(!T)
		exit(1);
	T->data=R[i-1];
	if(i==low)
		T->lchild=NULL;
	else
		SecondOptimal(T->lchild,sweight,R,low,i-1);
	if(i==high)
		T->rchild=NULL;
	else
		SecondOptimal(T->rchild,sweight,R,i+1,high);
	return 0;
}

void FindSW(int sweight[],TElemType R[],int n)
{//sweight为长度n+1数组,R为数据,n为数组长度
//计算权值和放入sweight中,sweight的0位置为权值和0
	int i;
	sweight[0]=0;
	for(i=1;i<=n;i++)
		sweight[i]=sweight[i-1]+R[i-1].weight;
}

int Search(BiTree T,KeyType key,BiTree &p)
{//根据关键字在次优树中搜索
//找到p返回搜索结果并返回0,否则p=null返回1
	while(T)
	{
		if(EQ((T->data).key,key))
		{
			p=T;
			return 0;
		}
		if(LT((T->data).key,key))
			T=T->rchild;
		else
			T=T->lchild;
	}
	p=NULL;
	return 1;
}

void Traverse(BiTree T,void (*Visit)(TElemType))
{//遍历树
	if(T)
	{
		Traverse(T->lchild,Visit);
		Visit(T->data);
		Traverse(T->rchild,Visit);
	}
}

void DestroyTree(BiTree &T)
{//销毁次优树T
	if(T)
	{
		if(T->lchild)
			DestroyTree(T->lchild);
		if(T->rchild)
			DestroyTree(T->rchild);
		free(T);
		T=NULL;
	}
}