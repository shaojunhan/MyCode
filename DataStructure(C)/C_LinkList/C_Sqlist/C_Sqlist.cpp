// C_Sqlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"C_Sqlist_Basic.h"
#include"C_Sqlist_Extend.h"

void test1();
void test2();
void test3();

int main(int argc, char* argv[])
{
	printf("-----------------------测试1(Sqlist的基本操作)--------------------------\n");
	test1();
	printf("\n-----------------------测试2(Sqlist的扩展操作)--------------------------\n");
	//test2();
	printf("\n-----------------------测试3(Sqlist的Union/Merge操作)-----------------------\n");
	test3();
	system("pause");
	return 0;
}

//访问
void visit(ElemType e)
{
	printf("%d",e);
}

//比较
int compare(ElemType e1, ElemType e2)
{
	return e1>e2?1:e1==e2?0:-1;
}

//合并表
void ListUnion(Sqlist &La, Sqlist Lb)
{
	int length_a=ListLength(La);
	int length_b=ListLength(Lb);

	ElemType eb;
	int i=0;
	
	while(i<length_b)
	{
		if(!GetElem(Lb,i+1,eb))
		{
			printf("获取错误:错误所在问价%s,错误行数%d\n",__FILE__,__LINE__);
			exit(OVERFLOW);
		}
		if(!LocateElem(La,eb,compare))
			ListInsert(La,++length_a,eb);
		i++;
	}
}

//Merge1
void MergeList1(Sqlist La, Sqlist Lb, Sqlist &Lc)
{
	if(!InitList(Lc))
		exit(ERROR);

	ElemType ea,eb;
	int i=0,j=0,k=0;
	int length_a,length_b;
	length_a=La.length;
	length_b=Lb.length;

	GetElem(La,i+1,ea);
	GetElem(Lb,j+1,eb);
	while(i<length_a && j<length_b)
	{
		if(compare(ea,eb)<=0)
		{
			ListInsert(Lc,++k,ea);
			i++;
			GetElem(La,i+1,ea);
		}
		else
		{
			ListInsert(Lc,++k,eb);
			j++;
			GetElem(Lb,j+1,eb);
		}
	}

	while(i<length_a)
	{
		ListInsert(Lc,++k,ea);
		i++;
		GetElem(La,i+1,ea);
	}

	while(j<length_b)
	{
		ListInsert(Lc,++k,eb);
		j++;
		GetElem(Lb,j+1,eb);
	}
}


//Merge2
void MergeList2(Sqlist La,Sqlist Lb,Sqlist &Lc)
{
	int length_a,length_b;
	ElemType *pc,*pa,*pb,*qa_last,*qb_last;
	
	length_a=La.length;
	length_b=Lb.length;
	pc=Lc.elem=(ElemType*)malloc((length_a+length_b)*sizeof(ElemType));
	if(!pc)
		exit(ERROR);
	Lc.listsize=length_a+length_b;

	pa=La.elem;
	pb=Lb.elem;
	qa_last=La.elem+La.length-1;
	qb_last=Lb.elem+Lb.length-1;

	while(pa<=qa_last && pb<=qb_last)
	{
		if(*pa<=*pb)
			*pc++=*pa++;
		else
			*pc++=*pb++;
	}

	while(pa<=qa_last)
		*pc++=*pa++;
	while(pb<=qb_last)
		*pc++=*pb++;

	Lc.length=Lc.listsize;
}


//Merge3
void MergeList3(Sqlist La,Sqlist Lb,Sqlist &Lc)
{
	int length_a,length_b;
	ElemType *pc,*pa,*pb,*qa_last,*qb_last;
	
	length_a=La.length;
	length_b=Lb.length;
	pc=Lc.elem=(ElemType*)malloc((length_a+length_b)*sizeof(ElemType));
	if(!pc)
		exit(ERROR);
	Lc.listsize=length_a+length_b;

	pa=La.elem;
	pb=Lb.elem;
	qa_last=La.elem+La.length-1;
	qb_last=Lb.elem+Lb.length-1;

	while(pa<=qa_last && pb<=qb_last)
	{
		switch(*pa<=*pb)
		{
		case 0:
			*pc++=*pb++;
			break;
		case 1:
			*pc++=*pa++;
			break;
		}
	}

	while(pa<=qa_last)
		*pc++=*pa++;
	while(pb<=qb_last)
		*pc++=*pb++;

	Lc.length=Lc.listsize;
}

//测试1
void test1()
{
	Sqlist La;
	int i;
	ElemType e;

	InitList(La);
	printf("测试空表(1:非空&0:空),结果:%d\n",!ListEmpty(La));
	for(i=0;i<5;i++)
		ListInsert(La,i+1,i+1);
	printf("测试插入,结果:");
	ListTraverse(La,visit);
	printf("\n");
	
	printf("测试空表(1:非空&0:空),结果:%d\n",!ListEmpty(La));
	printf("测试表长,结果:%d\n",ListLength(La));

	for(i=0;i<6;i++)
		ListInsert(La,5+i+1,i+5+1);
	printf("增加表长6后,结果:");
	ListTraverse(La,visit);
	printf("\n");

	for(i=1;i<=2;i++)
	{
		if(PriorElem(La,i,e))
			printf("测试%d的前驱,结果:%d\n",i,e);
		else
			printf("测试%d的前驱失败\n",i);
	}
	for(i=10;i<=11;i++)
	{
		if(NextElem(La,i,e))
			printf("测试%d的后继,结果:%d\n",i,e);
		else
			printf("测试%d的后继失败\n",i);
	}
	
	i=11;
	printf("元素为%d的位置为%d\n",i,LocateElem(La,i,compare));
	i=12;
	printf("元素为%d的位置为%d\n",i,LocateElem(La,i,compare));
	i=1;
	printf("元素为%d的位置为%d\n",i,LocateElem(La,i,compare));
	i=-1;
	printf("元素为%d的位置为%d\n",i,LocateElem(La,i,compare));
	
	for(i=11;i<=12;i++)
		if(GetElem(La,i,e))
			printf("第%d号元素是:%d\n",i,e);
		else
			printf("测试第%d号元素失败\n",i);
	
	i=1;
	if(ListDelete(La,i,e))
		printf("删除第%d元素后是结果:",i);
	else
		printf("删除失败,未查找到该元素\n");
	ListTraverse(La,visit);
	printf("测试表长,结果:%d\n",ListLength(La));
	
	i=10;
	ListDelete(La,i,e);
	printf("删除第%d号元素之后是:",i);
	ListTraverse(La,visit);
	printf("测试表长,结果:%d\n",ListLength(La));

	i=10;
	ListDelete(La,i,e);
	printf("删除第%d号元素之后是:",i);
	ListTraverse(La,visit);
	printf("测试表长,结果:%d\n",ListLength(La));

	i=5;
	ListDelete(La,i,e);
	printf("删除第%d号元素之后是:",i);
	ListTraverse(La,visit);
	printf("测试表长,结果:%d",ListLength(La));
}

//测试2
void test2()
{
	Sqlist La,Lb;
	int i=5;
	int j=3;
	CreateAscend(La,i);
	printf("测试建表,表长%d,结果:",i);
	ListTraverse(La,visit);
	printf("\n");

	i=6;
	CreateDescend(Lb,i);
	printf("测试建表,表长%d,结果:",i);
	ListTraverse(Lb,visit);
	printf("\n");

	i=5;
	InsertAscend(La,i);
	printf("测试升序插入%d,表长%d,结果:",i,ListLength(La));
	ListTraverse(La,visit);
	printf("\n");

	i=6;
	InsertDescend(Lb,i);
	printf("测试降序插入%d,表长%d,结果:",i,ListLength(Lb));
	ListTraverse(Lb,visit);
	printf("\n");

	i=11;
	printf("测试头插入,插入%d,结果:\n",i);
	HeadInsert(La,i);
	ListTraverse(La,visit);
	printf("\n");
	
	i=13;
	printf("测试尾插入,插入%d,结果:\n",i);
	TailInsert(La,i);
	ListTraverse(La,visit);
	printf("\n");

	printf("测试头删除,");
	if(DeleteFirst(La,i))
		printf("删除掉的元素为%d\n",i);
	ListTraverse(La,visit);
	printf("\n");

	printf("测试尾删除,");
	if(DeleteTail(La,i))
		printf("删除掉的元素为%d\n",i);
	ListTraverse(La,visit);
	printf("\n");

	printf("测试删除替代,");
	j=3;
	i=1;
	if(DeleteElem(La,i))
		printf("删除掉第%d的元素为%d.",j,i);
	ListTraverse(La,visit);
	printf("\n");

	i=6;
	if(ReplaceElem(La,j,i))
		printf("替代掉第%d的元素为%d\n",j,i);
	ListTraverse(La,visit);
	printf("\n");
}

//测试3
void test3()
{
	Sqlist La,Lb,Lc,Ld,Le;
	int i=5;
	int j=3;
	CreateAscend(La,i);
	printf("测试建表,表长%d,结果:",i);
	ListTraverse(La,visit);
	printf("\n");

	i=6;
	CreateAscend(Lb,i);
	printf("测试建表,表长%d,结果:",i);
	ListTraverse(Lb,visit);
	printf("\n");

	printf("Merge1测试");
	MergeList1(La,Lb,Lc);
	ListTraverse(Lc,visit);
	printf("\n");

	printf("Merge2测试");
	MergeList2(La,Lb,Ld);
	ListTraverse(Ld,visit);
	printf("\n");

	printf("Merge3测试");
	MergeList3(La,Lb,Le);
	ListTraverse(Le,visit);
	printf("\n");

	printf("测试表合并");
	ListUnion(La,Lb);
	ListTraverse(La,visit);
	printf("\n");
}