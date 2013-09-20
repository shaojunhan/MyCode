#include"stdafx.h"
#include"C_HeadLinkList_Test.h"
#include<stdio.h>

void visit(ElemType e)
{
	printf("%d ",e);
}

int compare(ElemType e1,ElemType e2)
{
	return e1>e2?1:e1==e2?0:-1;
}

Status ListUnion(LinkList La,LinkList Lb)
{
	Link pb,hb,ta;
	Link s;
	ta=GetLast(La);
	hb=GetHead(Lb);
	pb=NextPos(hb);

	while(pb)
	{
		if(!LocateElem(La,pb->data,compare))
		{
			if(!MakeNode(s,pb->data))
				return ERROR;
			InsAfter(La,ta,s);
		}
		pb=NextPos(pb);
	}

	return OK;
}

Status MergeList(LinkList La,LinkList &Lb,LinkList &Lc)
{
	Link pa,pb;
	Link ha,hb;
	Link s,pc;

	InitList(Lc);
	pc=GetHead(Lc);
	ha=GetHead(La),hb=GetHead(Lb);
	pa=NextPos(ha),pb=NextPos(hb);

	while(pa && pb)
	{
		if(compare(pa->data,pb->data)<=0)
		{
			DelFirst(La,ha,s);
			InsAfter(Lc,pc,s);
			pa=NextPos(ha);
		}
		else
		{
			DelFirst(Lb,hb,s);
			InsAfter(Lc,pc,s);
			pb=NextPos(hb);
		}
		pc=NextPos(pc);
	}

	pc=pa!=NULL?pa:pb;
	if(pc)
		Append(Lc,pc);
	return OK;
}

//基本操作测试
void test1()
{
	LinkList L;
	Link h,p,s;
	int j;
	int i=0;
	const int N=10;

	InitList(L);
	h=GetHead(L);
	p=h;

	printf("是否为空表？(1:否 0:是)------%d\n",!ListEmpty(L));
	printf("表长是:%d\n",ListLength(L));

	for(i=0;i<5;i++)
	{
		OrderInsert(L,2*(i+1),compare);
	}

	printf("插入偶数(2,4,6,8,10)后:");
	ListTraverse(L,visit);
	printf("\n");

	for(i=0;i<5;i++)
	{
		OrderInsert(L,2*i+1,compare);
	}

	printf("差如奇数(1,3,5,7,9)后:");
	ListTraverse(L,visit);
	printf("\n");

	for(i=0;i<=N+2;i+=3)
	{
		if(LocateElem(L,i,p,compare))
		{
			printf("查找%d成功查找到地址%d,结果%d\n",i,p,p->data);
		}
		else
			printf("查找%d失败\n",i);
	}

	printf("是否为空表？(1:否 0:是)------%d\n",!ListEmpty(L));
	printf("表长是:%d\n",ListLength(L));

	for(i=0;i<=N+2;i+=3)
	{
		j=LocateElem(L,i,compare);
		if(j)
		{
			printf("查找%d成功查找到在第%d个\n",i,j);
		}
		else
			printf("查找%d失败\n",i);
	}

	p=GetLast(L);
	i=5;
	printf("在结尾前插入%d,",i);
	MakeNode(s,i);
	if(InsBefore(L,p,s))
		printf("插入成功:");
	else
		printf("插入失败:");
	ListTraverse(L,visit);
	printf("\n");

	i=12;
	printf("在结尾后插入%d,",i);
	MakeNode(s,i);
	if(InsAfter(L,p,s))
		printf("插入成功:");
	else
		printf("插入失败:");
	ListTraverse(L,visit);
	printf("\n");

	printf("结尾的前驱结点地址%d,结果",p);
	p=PriorPos(L,GetLast(L));
	if(p)
		printf("(%d)%d\n",p,p->data);
	else
		printf("失败\n");

	i=11;
	printf("设置结尾为%d后链表:",i);
	SetCurElem(GetLast(L),i);
	ListTraverse(L,visit);
	printf("\n");

	printf("是否为空表？(1:否 0:是)------%d\n",!ListEmpty(L));
	printf("表长是:%d\n",ListLength(L));

	ClearList(L);
	printf("清空链表后:");
	ListTraverse(L,visit);
	printf("\n");

	printf("销毁链表后:");
	ListTraverse(L,visit);
	printf("\n");

}

//Union/Merge测试
void test2()
{

	LinkList La,Lb,Lc;
	Link h,p,s;
	int j;
	int i=0;
	const int N=10;

	InitList(La);
	InitList(Lb);

	for(i=0;i<5;i++)
	{
		OrderInsert(La,2*(i+1),compare);
	}

	printf("La插入偶数(2,4,6,8,10)后:");
	ListTraverse(La,visit);
	printf("\n");

	i=5;
	OrderInsert(La,i,compare);
	printf("La插入5后:");
	ListTraverse(La,visit);
	printf("\n");

	for(i=0;i<5;i++)
	{
		OrderInsert(Lb,2*i+1,compare);
	}

	printf("Lb插入奇数(1,3,5,7,9)后:");
	ListTraverse(Lb,visit);
	printf("\n");

	i=6;
	OrderInsert(Lb,i,compare);
	printf("Lb插入5后:");
	ListTraverse(Lb,visit);
	printf("\n");

	ListUnion(La,Lb);
	printf("合并后:");
	ListTraverse(La,visit);
	printf("\n");

	printf("Merge合并后:");
	MergeList(La,Lb,Lc);
	ListTraverse(Lc,visit);
	printf("\n");
}