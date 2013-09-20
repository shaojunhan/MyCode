#include"stdafx.h"
#include"C_SingleLinkList_Test.h"
#include"C_SingleLinkList_Tail.h"
#include"C_SingleLinkList_Expand.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<process.h>


//访问
void visit(ElemType e)
{
	printf("%d ",e);
}

//比较
int compare(ElemType e1,ElemType e2)
{
	return e1>e2?1:e1==e2?0:-1;
}

//合并
void MergeList1(LinkList La,LinkList Lb,LinkList &Lc)
{
	if(!InitList(Lc))
		exit(OVERFLOW);
	ElemType ea,eb;
	int i=1,j=1,k=0;
	int length_a,length_b;
	
	length_a=ListLength(La);
	length_b=ListLength(Lb);
	
	while(i<=length_a && j<=length_b)
	{
		GetElem(La,i,ea);
		GetElem(Lb,j,eb);
		
		if(compare(ea,eb)<=0)
		{
			ListInsert(Lc,++k,ea);
			i++;
		}
		else
		{
			ListInsert(Lc,++k,eb);
			j++;
		}
	}
	
	while(i<=length_a)
	{
		GetElem(La,i,ea);
		ListInsert(Lc,++k,ea);
		i++;
	}
	
	while(j<=length_b)
	{
		GetElem(Lb,j,eb);
		ListInsert(Lc,++k,eb);
		j++;
	}
}

//
void MergeList2(LinkList La,LinkList &Lb,LinkList &Lc)
{
	LNode *pa=La->next,*pb=Lb->next;
	LNode *pc=Lc=La;
	while(pa && pb)
	{
		if(compare(pa->data,pb->data)<=0)
		{
			pc->next = pa;
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	
	pc->next=(pa==NULL)?pb:pa;
	free(Lb);
}

//合并
void ListUnion(LinkList &La,LinkList Lb)
{
	int j=1;
	int length_a,length_b;
	length_a=ListLength(La);
	length_b=ListLength(Lb);
	ElemType eb;
	
	while(j<=length_b)
	{
		if(GetElem(Lb,j,eb))
		{
			if(!LocateElem(La,eb,compare))
			{
				ListInsert(La,++length_a,eb);
			}
		}
		j++;
	}
}

//带尾结点的但链表合并
void Merge(LinkList &La,LinkList Lb)
{
	if(ListLength_CL(Lb))
	{
		LNode *p=Lb->next->next;
		Lb->next=La->next;
		La->next=p;

		free(Lb);
	}
}

//单链表基本操作的测试
void test1()
{
	LinkList L;
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
	
	printf("遍历链表");
	ListTraverse(L,visit);
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

//单链表的Union/Merge测试
void test2()
{
	LinkList La,Lb,Lc,Ld,Le;
	int i;
	
	InitList(La);
	InitList(Lb);
	InitList(Lc);
	
	for(i=1;i<=5;i++)
	{
		ListInsert(La,i,2*i);
		ListInsert(Lb,i,3*i);
		ListInsert(Lc,i,4*i);
	}
	
	for(i=1;i<=5;i++)
	{
		ListInsert(La,2*i-1,2*i-1);
		ListInsert(Lb,2*i-1,3*i-1);
		ListInsert(Lc,2*i-1,3*i-2);
	}
	
	printf("*****合并前*****\n");
	printf("La表:");
	ListTraverse(La,visit);
	printf("\n");
	
	printf("Lb表:");
	ListTraverse(Lb,visit);
	printf("\n");
	
	printf("Lc表:");
	ListTraverse(Lc,visit);
	printf("\n");
	
	printf("****合并(Union)****");
	ListUnion(Lc,Lb);
	printf("Lc表:");
	ListTraverse(Lc,visit);
	printf("\n");
	
	printf("****合并(Merge1)****");
	MergeList1(La,Lb,Ld);
	printf("Ld表:");
	ListTraverse(Ld,visit);
	printf("\n");
	
	printf("****合并(Merge1)****");
	MergeList1(La,Lb,Le);
	printf("Le表:");
	ListTraverse(Le,visit);
	printf("\n");
}

//test-expand测试
void test3()
{
	LinkList La,Lb;
	int n=0;
	int i=0,j=0;
	
	n=3;
	CreateAscend(La,n);
	printf("升序链表为:");
	ListTraverse(La,visit);
	printf("\n");
	
	n=4;
	CreateDescend(Lb,n);
	printf("降序链表为:");
	ListTraverse(Lb,visit);
	printf("\n");
	
	for(i=3,j=2;i<=11;i=2*j,j++)
	{
		InsertAscend(La,i);
		printf("升序插入%d后结果:",i);
		ListTraverse(La,visit);
		printf("\n");
	}
	
	for(i=3,j=2;i<=11;i=2*j,j++)
	{
		InsertDescend(Lb,i);
		printf("降序插入%d后结果:",i);
		ListTraverse(Lb,visit);
		printf("\n");
	}
	
	i=1;
	HeadInsert(La,i);
	printf("头插入%d后结果:",i);
	ListTraverse(La,visit);
	printf("\n");
	
	i=13;
	EndInsert(La,i);
	printf("尾插入%d后结果:",i);
	ListTraverse(La,visit);
	printf("\n");
	
	for(n=-1,i=7;n<=2;n++,i+=2)
	{
		ReplaceElem(La,n,i);
		printf("在第%d位置用%d替代后结果:",n,i);
		ListTraverse(La,visit);
		printf("\n");
	}
	
	for(n=3;n<6;n++)
	{
		DeleteElem(La,n,compare);
		printf("删除%d后结果:",n);
		ListTraverse(La,visit);
		printf("\n");
	}
	
	DeleteFirst(La,i);
	printf("头删除%d后结果:",i);
	ListTraverse(La,visit);
	printf("\n");
	
	DeleteTail(La,i);
	printf("尾删除%d后结果:",i);
	ListTraverse(La,visit);
}

//设立尾指针的单循环链表的测试
void test4()
{
	LinkList L;
	ElemType e;
	int i=0;
	
	InitList_CL(L);
	
	printf("表是否为空(1:非空,0:空),结果:%d\n",!ListEmpty_CL(L));
	printf("表长%d\n",ListLength_CL(L));
	
	for(i=1;i<=5;i++)
	{
		ListInsert_CL(L,i,2*i);
	}
	
	printf("插入5个元素(2,4,6,8,10),结果:");
	ListTraverse_CL(L,visit);
	printf("\n");
	
	i=3;
	if(PriorElem_CL(L,3,e))
		printf("%d的前驱为%d\n",i,e);
	if(NextElem_CL(L,3,e))
		printf("%d的后继为%d\n",i,e);
	
	for(i=1;i<=5;i++)
	{
		ListInsert_CL(L,2*i-1,2*i-1);
	}
	
	printf("插入5个元素(1,3,5,7,9)后结果:");
	ListTraverse_CL(L,visit);
	printf("\n");
	
	printf("表是否为空(1:非空,0:空),结果:%d\n",!ListEmpty_CL(L));
	printf("表长%d\n",ListLength_CL(L));
	
	for(i=9;i<=10;i++)
	{
		printf("删除%d个元素为",i);
		if(ListDelete_CL(L,i,e))
			printf("%d\n",e);
		else
			printf("删除失败\n");
	}
	
	int j=0;
	for(i=-1;i<=1;i++)
	{
		printf("查找%d所在位置",i);
		j=LocateElem_CL(L,i,compare);
		if(j)
			printf("%d\n",j);
		else
			printf("查找失败\n");
	}
	
	printf("遍历链表");
	ListTraverse_CL(L,visit);
	printf("\n");
	
	j=ClearList_CL(L);
	if(j)
		printf("清空链表成功");
	else
		printf("清空失败");
	
	printf("表是否为空(1:非空,0:空),结果:%d\n",!ListEmpty_CL(L));
	printf("表长%d\n",ListLength_CL(L));
	
	j=DestroyList_CL(L);
	if(j)
		printf("销毁链表成功");
	else
		printf("销毁失败");
}