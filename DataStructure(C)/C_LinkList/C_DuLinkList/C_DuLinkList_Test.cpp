#include"stdafx.h"
#include"C_DuLinkList_Test.h"
#include<stdio.h>

void visit(ElemType e)
{
	printf("%d ",e);
}

int compare(ElemType e1,ElemType e2)
{
	return e1>e2?1:e1==e2?0:-1;
}

void test()
{
	DuLinkList L;
	ElemType e;
	int i=0;
	
	InitList(L);
	
	printf("表是否为空(1:非空,0:空),结果:%d\n",!ListEmpty(L));
	printf("表长%d\n",ListLength(L));
	
	for(i=1;i<=5;i++)
	{
		ListInsert(L,i,2*i);
	}
	
	printf("插入5个元素(2,4,6,8,10),结果:");
	ListTraverse(L,visit);
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
	ListTraverse(L,visit);
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
	
	for(i=0;i<=12;i+=3)
	{
		DuLNode *p=NULL;
		printf("查找第%d位置的元素",i);

		p=GetElemP(L,i);
		if(p)
			printf("%d\n",p->data);
		else
			printf("查找失败\n");
	}
	printf("遍历链表");
	ListTraverse(L,visit);
	printf("\n");

	printf("逆序遍历链表");
	ListTraverseBack(L,visit);
	printf("\n");

	j=ClearList(L);
	if(j)
		printf("清空链表成功");
	else
		printf("清空失败");
	
	printf("表是否为空(1:非空,0:空),结果:%d\n",!ListEmpty(L));
	printf("表长%d\n",ListLength(L));
	
	j=DestroyList(L);
	if(j)
		printf("销毁链表成功");
	else
		printf("销毁失败");
}