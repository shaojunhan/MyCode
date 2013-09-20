#include"E:\Document\Data Structures\Study\C_Search\C_Search_Header.h"
#include<stdlib.h>

typedef int ElemType;
typedef char KeyType;
typedef struct
{
	KeyType key;
	ElemType data;
}SElemType;
#include"C_SSTable_Basic.h"
Status Create_IR(SSTable &ST)
{//ST中的元素按关键字从小到大排序
	int i,j,k;
	if(ST.length<=0)
		return FALSE;
	for(i=1;i<=ST.length;i++)
	{//选择排序
		*(ST.elem+0)=*(ST.elem+i);//0位置为哨兵岗
		k=i;
		for(j=i+1;j<=ST.length;j++)
			if LT((*(ST.elem+j)).key,(*(ST.elem+0)).key)
			{
				k=j;
				*(ST.elem+0)=*(ST.elem+j);
			}
		if(k!=i)
		{
			*(ST.elem+k)=*(ST.elem+i);
			*(ST.elem+i)=*(ST.elem+0);
		}
	}
	return OK;
}

Status Create_OR(SSTable &ST,SElemType R[],int n)
{//R从0开始,ST的0位置不存储元素,n为R数组长度
 //根据R顺序建立ST
	int i;
	ST.elem=(SElemType*)malloc((n+1)*sizeof(SElemType));
	if(!ST.elem)
		exit(1);
	for(i=1;i<=n;i++)
		*(ST.elem+i)=R[i-1];
	ST.length=n;
	return OK;
}
Status DestroyTable(SSTable &ST)
{//销毁ST
	if(ST.elem)
		free(ST.elem);
	ST.elem=NULL;
	ST.length=0;
	return OK;
}
int Search_IR(SSTable &ST,KeyType key)
{//ST静态查找表,key关键字
//顺序查找,找到返回在ST中的位置(从1开始),否则返回负数
	int i;
	i=ST.length;
	(*(ST.elem+0)).key=key;//0位置为监视哨
	while(!EQ((*(ST.elem+i)).key,key))
		i--;
	if(i==0)
		return -1;
	else
		return i;
}

int Search_BIN(SSTable &ST,KeyType key)
{//ST为关键字从小到大有序,key为待查关键字
//在ST中搜索key,找到返回所在ST中位置(从1开始),否则返回负数
	int low,high,mid;
	low=1,high=ST.length;
	Create_IR(ST);
	while(low<=high)
	{
		mid=(low+high)/2;
		if(EQ((*(ST.elem+mid)).key,key))
			return mid;
		if(LT((*(ST.elem+mid)).key,key))
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}

void Traverse(SSTable &ST,void (*Visit)(SElemType))
{//Visit参数为SElemType的函数指针
//顺序遍历ST
	int i;
	for(i=1;i<=ST.length;i++)
		Visit(*(ST.elem+i));
}