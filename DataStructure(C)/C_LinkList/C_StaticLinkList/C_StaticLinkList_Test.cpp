#include"stdafx.h"
#include"C_StaticLinkList_Test.h"
#include<stdio.h>

//Merge1
void MergeList1(SLinkList L)
{
	int n=10;
	int i=0;
	ElemType e;
	int j=0;

	InitList(L);
	printf("请输入A中数据的个数:");

	scanf("%d",&i);
	if(i>0)
		n=i;

	for(i=0;i<n;i++)
	{
loop:
		scanf("%d",&e);
		if(!LocateElem(L,e,compare))
			ListInsert(L,i+1,e);
		else
		{
			printf("已存在,请重新输入:");
			goto loop;
		}
	}
	printf("遍历链表");
	TraverseList(L,visit);
	printf("\n");

	printf("请输入B中数据的个数:");
	scanf("%d",&i);
	if(i>0)
		n=i;

	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		if(!(j=LocateElem(L,e,compare)))
		{
			ListInsert(L,ListLength(L)+1,e);
		}
		else
		{
			ListDelete(L,j,e);
		}
	}

	printf("遍历链表");
	TraverseList(L,visit);
	printf("\n");
}

void MergeList2(SLinkList L)
{
	int na,nb;
	int i;
	int n;
	ElemType e;

	InitSpace(L);

	InitList(L,na);
	InitList(L,nb);

	printf("请输入A中数据的个数:");
	scanf("%d",&i);
	if(i>0)
		n=i;

	for(i=0;i<n;i++)
	{
loop1:
		scanf("%d",&e);
		if(!LocateElem(L,na,e,compare))
			ListInsert(L,na,i+1,e);
		else
		{
			printf("已存在,请重新输入:");
			goto loop1;
		}
	}
	printf("遍历链表");
	TraverseList(L,na,visit);
	printf("\n");

	printf("请输入B中数据的个数:");
	scanf("%d",&i);
	if(i>0)
		n=i;

	for(i=0;i<n;i++)
	{
loop2:
		scanf("%d",&e);
		if(!LocateElem(L,nb,e,compare))
			ListInsert(L,nb,i+1,e);
		else
		{
			printf("已存在,请重新输入:");
			goto loop2;
		}
	}
	printf("遍历链表");
	TraverseList(L,nb,visit);
	printf("\n");

	for(int j=0;j<ListLength(L,nb);j++)
	{
		if(GetElem(L,nb,j+1,e))
		{
			if(!(i=LocateElem(L,na,e,compare)))
			{
				i=ListLength(L,na);
				ListInsert(L,na,++i,e);
			}
			else
				ListDelete(L,na,i,e);
		}
	}

	printf("遍历链表");
	TraverseList(L,na,visit);
	printf("\n");
}

//visit
void visit(ElemType e)
{
	printf("%d ",e);
}

//compare
int compare(ElemType e1,ElemType e2)
{
	return e1>e2?1:e1==e2?0:-1;
}

//Basic
void test1()
{
	SLinkList L;
	SLinkList Lk;
	ElemType e;
	int i=0;
	int N=10;

	InitList(L);
	
	printf("表是否为空(1:非空,0:空),结果:%d\n",!ListEmpty(L));
	printf("表长%d\n",ListLength(L));
	
	for(i=1;i<=5;i++)
	{
		ListInsert(L,i,2*i);
	}
	
	printf("插入5个元素(2,4,6,8,10),结果:");
	TraverseList(L,visit);
	printf("\n");
	
	i=3;
	if(PriorElem(L,3,e))
		printf("%d的前驱为%d\n",i,e);
	if(NextElem(L,3,e))
		printf("%d的后继为%d\n",i,e);
	
	for(i=1;i<=5;i++)
	{
		ListInsert(L,2*i-1,2*i-1);
	}
	
	printf("插入5个元素(1,3,5,7,9)后结果:");
	TraverseList(L,visit);
	printf("\n");
	
	printf("表是否为空(1:非空,0:空),结果:%d\n",!ListEmpty(L));
	printf("表长%d\n",ListLength(L));
	
	for(i=9;i<=10;i++)
	{
		printf("删除%d个元素为",i);
		if(ListDelete(L,i,e))
			printf("%d\n",e);
		else
			printf("删除失败\n");
	}
	
	int j=0;
	for(i=-1;i<=1;i++)
	{
		printf("查找%d所在位置",i);
		j=LocateElem(L,i,compare);
		if(j)
			printf("%d\n",j);
		else
			printf("查找失败\n");
	}

		
	for(i=-1;i<=N+5;i+=3)
	{
		if(PriorElem(L,i,j))
			printf("查找到%d的前驱%d\n",i,j);
		else
			printf("查找%d的前驱失败\n",i);

		if(NextElem(L,i,j))
			printf("查找到%d的后继%d\n",i,j);
		else
			printf("查找%d的后继失败\n",i);

	}

	j=ClearList(L);
	if(j)
		printf("清空链表成功");
	else
		printf("清空失败");
	
	printf("表是否为空(1:非空,0:空),结果:%d\n",!ListEmpty(L));
	printf("表长%d\n",ListLength(L));

	printf("链表合并:");
	MergeList1(Lk);
}

//expand
void test2()
{
	SLinkList L;
	SLinkList Lk;
	ElemType e;
	int i=0;
	int N=10;
	int n;

	InitSpace(L);
	InitList(L,n);
	
	printf("表是否为空(1:非空,0:空),结果:%d\n",!ListEmpty(L,n));
	printf("表长%d\n",ListLength(L,n));
	
	for(i=1;i<=5;i++)
	{
		ListInsert(L,n,i,2*i);
	}
	
	printf("插入5个元素(2,4,6,8,10),结果:");
	TraverseList(L,n,visit);
	printf("\n");
	
	i=3;
	if(PriorElem(L,n,3,e))
		printf("%d的前驱为%d\n",i,e);
	if(NextElem(L,n,3,e))
		printf("%d的后继为%d\n",i,e);
	
	for(i=1;i<=5;i++)
	{
		ListInsert(L,n,2*i-1,2*i-1);
	}
	
	printf("插入5个元素(1,3,5,7,9)后结果:");
	TraverseList(L,n,visit);
	printf("\n");
	
	printf("表是否为空(1:非空,0:空),结果:%d\n",!ListEmpty(L,n));
	printf("表长%d\n",ListLength(L,n));
	
	for(i=9;i<=10;i++)
	{
		printf("删除%d个元素为",i);
		if(ListDelete(L,n,i,e))
			printf("%d\n",e);
		else
			printf("删除失败\n");
	}
	
	int j=0;
	for(i=-1;i<=1;i++)
	{
		printf("查找%d所在位置",i);
		j=LocateElem(L,n,i,compare);
		if(j)
			printf("%d\n",j);
		else
			printf("查找失败\n");
	}

		
	for(i=-1;i<=N+5;i+=3)
	{
		if(PriorElem(L,n,i,j))
			printf("查找到%d的前驱%d\n",i,j);
		else
			printf("查找%d的前驱失败\n",i);

		if(NextElem(L,n,i,j))
			printf("查找到%d的后继%d\n",i,j);
		else
			printf("查找%d的后继失败\n",i);

	}

	j=ClearList(L,n);
	if(j)
		printf("清空链表成功");
	else
		printf("清空失败");
	
	printf("表是否为空(1:非空,0:空),结果:%d\n",!ListEmpty(L,n));
	printf("表长%d\n",ListLength(L,n));

	MergeList2(Lk);
	printf("\n");
}



