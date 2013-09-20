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
	printf("-----------------------����1(Sqlist�Ļ�������)--------------------------\n");
	test1();
	printf("\n-----------------------����2(Sqlist����չ����)--------------------------\n");
	//test2();
	printf("\n-----------------------����3(Sqlist��Union/Merge����)-----------------------\n");
	test3();
	system("pause");
	return 0;
}

//����
void visit(ElemType e)
{
	printf("%d",e);
}

//�Ƚ�
int compare(ElemType e1, ElemType e2)
{
	return e1>e2?1:e1==e2?0:-1;
}

//�ϲ���
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
			printf("��ȡ����:���������ʼ�%s,��������%d\n",__FILE__,__LINE__);
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

//����1
void test1()
{
	Sqlist La;
	int i;
	ElemType e;

	InitList(La);
	printf("���Կձ�(1:�ǿ�&0:��),���:%d\n",!ListEmpty(La));
	for(i=0;i<5;i++)
		ListInsert(La,i+1,i+1);
	printf("���Բ���,���:");
	ListTraverse(La,visit);
	printf("\n");
	
	printf("���Կձ�(1:�ǿ�&0:��),���:%d\n",!ListEmpty(La));
	printf("���Ա�,���:%d\n",ListLength(La));

	for(i=0;i<6;i++)
		ListInsert(La,5+i+1,i+5+1);
	printf("���ӱ�6��,���:");
	ListTraverse(La,visit);
	printf("\n");

	for(i=1;i<=2;i++)
	{
		if(PriorElem(La,i,e))
			printf("����%d��ǰ��,���:%d\n",i,e);
		else
			printf("����%d��ǰ��ʧ��\n",i);
	}
	for(i=10;i<=11;i++)
	{
		if(NextElem(La,i,e))
			printf("����%d�ĺ��,���:%d\n",i,e);
		else
			printf("����%d�ĺ��ʧ��\n",i);
	}
	
	i=11;
	printf("Ԫ��Ϊ%d��λ��Ϊ%d\n",i,LocateElem(La,i,compare));
	i=12;
	printf("Ԫ��Ϊ%d��λ��Ϊ%d\n",i,LocateElem(La,i,compare));
	i=1;
	printf("Ԫ��Ϊ%d��λ��Ϊ%d\n",i,LocateElem(La,i,compare));
	i=-1;
	printf("Ԫ��Ϊ%d��λ��Ϊ%d\n",i,LocateElem(La,i,compare));
	
	for(i=11;i<=12;i++)
		if(GetElem(La,i,e))
			printf("��%d��Ԫ����:%d\n",i,e);
		else
			printf("���Ե�%d��Ԫ��ʧ��\n",i);
	
	i=1;
	if(ListDelete(La,i,e))
		printf("ɾ����%dԪ�غ��ǽ��:",i);
	else
		printf("ɾ��ʧ��,δ���ҵ���Ԫ��\n");
	ListTraverse(La,visit);
	printf("���Ա�,���:%d\n",ListLength(La));
	
	i=10;
	ListDelete(La,i,e);
	printf("ɾ����%d��Ԫ��֮����:",i);
	ListTraverse(La,visit);
	printf("���Ա�,���:%d\n",ListLength(La));

	i=10;
	ListDelete(La,i,e);
	printf("ɾ����%d��Ԫ��֮����:",i);
	ListTraverse(La,visit);
	printf("���Ա�,���:%d\n",ListLength(La));

	i=5;
	ListDelete(La,i,e);
	printf("ɾ����%d��Ԫ��֮����:",i);
	ListTraverse(La,visit);
	printf("���Ա�,���:%d",ListLength(La));
}

//����2
void test2()
{
	Sqlist La,Lb;
	int i=5;
	int j=3;
	CreateAscend(La,i);
	printf("���Խ���,��%d,���:",i);
	ListTraverse(La,visit);
	printf("\n");

	i=6;
	CreateDescend(Lb,i);
	printf("���Խ���,��%d,���:",i);
	ListTraverse(Lb,visit);
	printf("\n");

	i=5;
	InsertAscend(La,i);
	printf("�����������%d,��%d,���:",i,ListLength(La));
	ListTraverse(La,visit);
	printf("\n");

	i=6;
	InsertDescend(Lb,i);
	printf("���Խ������%d,��%d,���:",i,ListLength(Lb));
	ListTraverse(Lb,visit);
	printf("\n");

	i=11;
	printf("����ͷ����,����%d,���:\n",i);
	HeadInsert(La,i);
	ListTraverse(La,visit);
	printf("\n");
	
	i=13;
	printf("����β����,����%d,���:\n",i);
	TailInsert(La,i);
	ListTraverse(La,visit);
	printf("\n");

	printf("����ͷɾ��,");
	if(DeleteFirst(La,i))
		printf("ɾ������Ԫ��Ϊ%d\n",i);
	ListTraverse(La,visit);
	printf("\n");

	printf("����βɾ��,");
	if(DeleteTail(La,i))
		printf("ɾ������Ԫ��Ϊ%d\n",i);
	ListTraverse(La,visit);
	printf("\n");

	printf("����ɾ�����,");
	j=3;
	i=1;
	if(DeleteElem(La,i))
		printf("ɾ������%d��Ԫ��Ϊ%d.",j,i);
	ListTraverse(La,visit);
	printf("\n");

	i=6;
	if(ReplaceElem(La,j,i))
		printf("�������%d��Ԫ��Ϊ%d\n",j,i);
	ListTraverse(La,visit);
	printf("\n");
}

//����3
void test3()
{
	Sqlist La,Lb,Lc,Ld,Le;
	int i=5;
	int j=3;
	CreateAscend(La,i);
	printf("���Խ���,��%d,���:",i);
	ListTraverse(La,visit);
	printf("\n");

	i=6;
	CreateAscend(Lb,i);
	printf("���Խ���,��%d,���:",i);
	ListTraverse(Lb,visit);
	printf("\n");

	printf("Merge1����");
	MergeList1(La,Lb,Lc);
	ListTraverse(Lc,visit);
	printf("\n");

	printf("Merge2����");
	MergeList2(La,Lb,Ld);
	ListTraverse(Ld,visit);
	printf("\n");

	printf("Merge3����");
	MergeList3(La,Lb,Le);
	ListTraverse(Le,visit);
	printf("\n");

	printf("���Ա�ϲ�");
	ListUnion(La,Lb);
	ListTraverse(La,visit);
	printf("\n");
}