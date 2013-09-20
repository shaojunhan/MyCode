#include"stdafx.h"
#include"C_SingleLinkList_Test.h"
#include"C_SingleLinkList_Tail.h"
#include"C_SingleLinkList_Expand.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<process.h>


//����
void visit(ElemType e)
{
	printf("%d ",e);
}

//�Ƚ�
int compare(ElemType e1,ElemType e2)
{
	return e1>e2?1:e1==e2?0:-1;
}

//�ϲ�
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

//�ϲ�
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

//��β���ĵ�����ϲ�
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

//��������������Ĳ���
void test1()
{
	LinkList L;
	ElemType e;
	int i=0;
	
	InitList(L);
	
	printf("���Ƿ�Ϊ��(1:�ǿ�,0:��),���:%d\n",!ListEmpty(L));
	printf("��%d\n",ListLength(L));
	
	for(i=1;i<=5;i++)
	{
		ListInsert(L,i,2*i);
	}
	
	printf("����5��Ԫ��(2,4,6,8,10),���:");
	ListTraverse(L,visit);
	printf("\n");
	
	i=3;
	if(PriorElem(L,3,e))
		printf("%d��ǰ��Ϊ%d\n",i,e);
	if(NextElem(L,3,e))
		printf("%d�ĺ��Ϊ%d\n",i,e);
	
	for(i=1;i<=5;i++)
	{
		ListInsert(L,2*i-1,2*i-1);
	}
	
	printf("����5��Ԫ��(1,3,5,7,9)����:");
	ListTraverse(L,visit);
	printf("\n");
	
	printf("���Ƿ�Ϊ��(1:�ǿ�,0:��),���:%d\n",!ListEmpty(L));
	printf("��%d\n",ListLength(L));
	
	for(i=9;i<=10;i++)
	{
		printf("ɾ��%d��Ԫ��Ϊ",i);
		if(ListDelete(L,i,e))
			printf("%d\n",e);
		else
			printf("ɾ��ʧ��\n");
	}
	
	int j=0;
	for(i=-1;i<=1;i++)
	{
		printf("����%d����λ��",i);
		j=LocateElem(L,i,compare);
		if(j)
			printf("%d\n",j);
		else
			printf("����ʧ��\n");
	}
	
	printf("��������");
	ListTraverse(L,visit);
	printf("\n");
	
	j=ClearList(L);
	if(j)
		printf("�������ɹ�");
	else
		printf("���ʧ��");
	
	printf("���Ƿ�Ϊ��(1:�ǿ�,0:��),���:%d\n",!ListEmpty(L));
	printf("��%d\n",ListLength(L));
	
	j=DestroyList(L);
	if(j)
		printf("��������ɹ�");
	else
		printf("����ʧ��");
}

//�������Union/Merge����
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
	
	printf("*****�ϲ�ǰ*****\n");
	printf("La��:");
	ListTraverse(La,visit);
	printf("\n");
	
	printf("Lb��:");
	ListTraverse(Lb,visit);
	printf("\n");
	
	printf("Lc��:");
	ListTraverse(Lc,visit);
	printf("\n");
	
	printf("****�ϲ�(Union)****");
	ListUnion(Lc,Lb);
	printf("Lc��:");
	ListTraverse(Lc,visit);
	printf("\n");
	
	printf("****�ϲ�(Merge1)****");
	MergeList1(La,Lb,Ld);
	printf("Ld��:");
	ListTraverse(Ld,visit);
	printf("\n");
	
	printf("****�ϲ�(Merge1)****");
	MergeList1(La,Lb,Le);
	printf("Le��:");
	ListTraverse(Le,visit);
	printf("\n");
}

//test-expand����
void test3()
{
	LinkList La,Lb;
	int n=0;
	int i=0,j=0;
	
	n=3;
	CreateAscend(La,n);
	printf("��������Ϊ:");
	ListTraverse(La,visit);
	printf("\n");
	
	n=4;
	CreateDescend(Lb,n);
	printf("��������Ϊ:");
	ListTraverse(Lb,visit);
	printf("\n");
	
	for(i=3,j=2;i<=11;i=2*j,j++)
	{
		InsertAscend(La,i);
		printf("�������%d����:",i);
		ListTraverse(La,visit);
		printf("\n");
	}
	
	for(i=3,j=2;i<=11;i=2*j,j++)
	{
		InsertDescend(Lb,i);
		printf("�������%d����:",i);
		ListTraverse(Lb,visit);
		printf("\n");
	}
	
	i=1;
	HeadInsert(La,i);
	printf("ͷ����%d����:",i);
	ListTraverse(La,visit);
	printf("\n");
	
	i=13;
	EndInsert(La,i);
	printf("β����%d����:",i);
	ListTraverse(La,visit);
	printf("\n");
	
	for(n=-1,i=7;n<=2;n++,i+=2)
	{
		ReplaceElem(La,n,i);
		printf("�ڵ�%dλ����%d�������:",n,i);
		ListTraverse(La,visit);
		printf("\n");
	}
	
	for(n=3;n<6;n++)
	{
		DeleteElem(La,n,compare);
		printf("ɾ��%d����:",n);
		ListTraverse(La,visit);
		printf("\n");
	}
	
	DeleteFirst(La,i);
	printf("ͷɾ��%d����:",i);
	ListTraverse(La,visit);
	printf("\n");
	
	DeleteTail(La,i);
	printf("βɾ��%d����:",i);
	ListTraverse(La,visit);
}

//����βָ��ĵ�ѭ������Ĳ���
void test4()
{
	LinkList L;
	ElemType e;
	int i=0;
	
	InitList_CL(L);
	
	printf("���Ƿ�Ϊ��(1:�ǿ�,0:��),���:%d\n",!ListEmpty_CL(L));
	printf("��%d\n",ListLength_CL(L));
	
	for(i=1;i<=5;i++)
	{
		ListInsert_CL(L,i,2*i);
	}
	
	printf("����5��Ԫ��(2,4,6,8,10),���:");
	ListTraverse_CL(L,visit);
	printf("\n");
	
	i=3;
	if(PriorElem_CL(L,3,e))
		printf("%d��ǰ��Ϊ%d\n",i,e);
	if(NextElem_CL(L,3,e))
		printf("%d�ĺ��Ϊ%d\n",i,e);
	
	for(i=1;i<=5;i++)
	{
		ListInsert_CL(L,2*i-1,2*i-1);
	}
	
	printf("����5��Ԫ��(1,3,5,7,9)����:");
	ListTraverse_CL(L,visit);
	printf("\n");
	
	printf("���Ƿ�Ϊ��(1:�ǿ�,0:��),���:%d\n",!ListEmpty_CL(L));
	printf("��%d\n",ListLength_CL(L));
	
	for(i=9;i<=10;i++)
	{
		printf("ɾ��%d��Ԫ��Ϊ",i);
		if(ListDelete_CL(L,i,e))
			printf("%d\n",e);
		else
			printf("ɾ��ʧ��\n");
	}
	
	int j=0;
	for(i=-1;i<=1;i++)
	{
		printf("����%d����λ��",i);
		j=LocateElem_CL(L,i,compare);
		if(j)
			printf("%d\n",j);
		else
			printf("����ʧ��\n");
	}
	
	printf("��������");
	ListTraverse_CL(L,visit);
	printf("\n");
	
	j=ClearList_CL(L);
	if(j)
		printf("�������ɹ�");
	else
		printf("���ʧ��");
	
	printf("���Ƿ�Ϊ��(1:�ǿ�,0:��),���:%d\n",!ListEmpty_CL(L));
	printf("��%d\n",ListLength_CL(L));
	
	j=DestroyList_CL(L);
	if(j)
		printf("��������ɹ�");
	else
		printf("����ʧ��");
}