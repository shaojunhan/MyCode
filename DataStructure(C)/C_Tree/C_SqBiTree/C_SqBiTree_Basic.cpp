#include"C_SqBiTree_Basic.h"
#include<string.h>
#include<stdlib.h>

char Nil='#';
Status InitBiTree(SqBiTree T)
{//初始化为空值
	int i;
	for(i=0;i<MAX_SIZE;i++)
		T[i]=Nil;
	return OK;
}

void DestroyBiTree(SqBiTree T)
{//定长数据类型不能销毁

}

Status CreateBiTree(SqBiTree T,char *chars)
{
	int l,i;

	l=strlen(chars);
	if(l>MAX_SIZE)
		l=MAX_SIZE;
	for(i=0;i<l;i++)
	{
		T[i]=*(chars+i);
		if(i!=0 && T[i]!=Nil && T[(i+1)/2-1]==Nil)//儿子不为空时，双亲也不能为空
			exit(0);
	}
	return OK;
}

Status ClearBiTree(SqBiTree T)
{
	int i;
	for(i=0;i<MAX_SIZE;i++)
		T[i]=Nil;
	return OK;
}

bool BiTreeEmpty(SqBiTree T)
{
	return T[0]==Nil;
}

int BiTreeDepth(SqBiTree T)
{
	int i,j,num;

	for(i=MAX_SIZE-1;i>=0;i--)
		if(T[i]!=Nil)
			break;

	i++;
	j=0,num=1;
	while(i>=num)
	{
		j++;
		num*=2;
	}
	return j;
}

TElemType Root(SqBiTree T)
{
	return T[0]!=Nil?T[0]:Nil;
}

TElemType Value(SqBiTree T,TElemType e)
{
	int i;
	if(Nil==T[0] || e==Nil)
		return Nil;

	for(i=0;i<MAX_SIZE;i++)
		if(T[i]==e)
			return T[i];
	return Nil;
}

Status Assign(SqBiTree T,TElemType &e,TElemType value)
{
	int i;

	for(i=0;i<MAX_SIZE;i++)
		if(T[i]==e)
		{
			if(value==Nil && T[2*i+1]!=Nil || T[2*i+2]!=Nil)
				continue;
			if(i!=0 && value!=Nil && T[(i+1)/2-1]==Nil)
				continue;
			T[i]=value;
			break;
		}

	return OK;
}

TElemType Parent(SqBiTree T,TElemType e)
{
	int i;

	if(T[0]==Nil)
		return Nil;
	for(i=1;i<MAX_SIZE;i++)
		if(e==T[i])
			return T[(i+1)/2-1];
	return Nil;
}

TElemType LeftChild(SqBiTree T,TElemType e)
{
	int i;
	if(T[0]==Nil || e==Nil)
		return Nil;

	for(i=0;i<MAX_SIZE;i++)
		if(e==T[i])
			return T[2*i+1];
	return Nil;
}

TElemType RightChild(SqBiTree T,TElemType e)
{
	int i;
	if(T[0]==Nil || e==Nil)
		return Nil;
	for(i=0;i<MAX_SIZE;i++)
		if(e==T[i])
			return T[2*i+2];
	return Nil;
}

TElemType LeftSibling(SqBiTree T,TElemType e)
{
	int i;
	if(T[0]==Nil || e==Nil)
		return Nil;
	for(i=1;i<MAX_SIZE;i++)
		if(e==T[i] && i%2==0)
			return T[i-1];
	return Nil;
}

TElemType RightSibling(SqBiTree T,TElemType e)
{
	int i;
	if(T[0]==Nil || e==Nil)
		return Nil;
	for(i=0;i<MAX_SIZE;i++)
		if(e==T[i] && i%2==1)
			return T[i+1];
	return Nil;
}

void Move(SqBiTree T,int i,SqBiTree C,int j)
{
	if(T[2*i+1]!=Nil)
		Move(T,2*i+1,C,2*j+1);
	if(T[2*i+2]!=Nil)
		Move(T,2*i+2,C,2*j+2);
	C[j]=T[i];
	T[i]=Nil;
}

Status InsertChild(SqBiTree T,position p,bool LR,SqBiTree C)
{
	int i,j;
	for(j=0,i=1;j<p.level-1;j++)
		i*=2;
	i+=p.order-2;
	j=2*i+1+LR;//左右子树
	if(T[j]!=Nil)
		Move(T,j,T,2*j+2);
	Move(C,0,T,j);
	return OK;
}

//层次遍历删除
#include"C_SqBiTree_Queue.h"

Status DeleteChild(SqBiTree T,position p,bool LR)
{
	int i,j;
	Queue Q;

	InitQueue(Q);

	for(i=1,j=0;j<p.level-1;j++)
		i*=2;
	i+=p.order-2;

	if(T[i]!=Nil)
		EnQueue(Q,2*i+1+LR);
	
	while(!QueueEmpty(Q))
	{
		if(DeQueue(Q,j))
		{
			if(T[2*j+1]!=Nil)
				EnQueue(Q,2*j+1);
			if(T[2*j+2]!=Nil)
				EnQueue(Q,2*j+2);
		}
		T[j]=Nil;
	}
	DestroyQueue(Q);
	return OK;
}

void (*visit)(TElemType);
void PreTraverse(SqBiTree T,int k)
{
	if(T[k]!=Nil)
	{
		visit(T[k]);
		if(2*k+1<MAX_SIZE)
			PreTraverse(T,2*k+1);
		if(2*k+2<MAX_SIZE)
			PreTraverse(T,2*k+2);
	}
}

Status PreOrderTraverse(SqBiTree T,void (*Visit)(TElemType))
{
	visit=Visit;
	if(T[0]!=Nil)
		PreTraverse(T,0);
	return OK;
}

void InTraverse(SqBiTree T,int k)
{
	if(T[k]!=Nil)
	{
		if(2*k+1<MAX_SIZE)
			InTraverse(T,2*k+1);
		visit(T[k]);
		if(2*k+2<MAX_SIZE)
			InTraverse(T,2*k+2);
	}
}

Status InOrderTraverse(SqBiTree T,void (*Visit)(TElemType))
{
	visit=Visit;
	if(T[0]!=Nil)
		InTraverse(T,0);
	return OK;
}

void PostTraverse(SqBiTree T,int k)
{
	if(T[k]!=Nil)
	{
		if(2*k+1<MAX_SIZE)
			PostTraverse(T,2*k+1);
		if(2*k+2<MAX_SIZE)
			PostTraverse(T,2*k+2);
		visit(T[k]);
	}
}

Status PostOrderTraverse(SqBiTree T,void (*Visit)(TElemType))
{
	visit=Visit;
	if(T[0]!=Nil)
		PostTraverse(T,0);
	return OK;
}

Status LevelOrderTraverse(SqBiTree T,void (*Visit)(TElemType))
{
	int i,j;

	for(j=MAX_SIZE-1;j>=0;j--)
		if(T[j]!=Nil)
			break;

	for(i=0;i<=j;i++)
		if(T[i]!=Nil)
			Visit(T[i]);
	return OK;
}