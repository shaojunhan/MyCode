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
	printf("������A�����ݵĸ���:");

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
			printf("�Ѵ���,����������:");
			goto loop;
		}
	}
	printf("��������");
	TraverseList(L,visit);
	printf("\n");

	printf("������B�����ݵĸ���:");
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

	printf("��������");
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

	printf("������A�����ݵĸ���:");
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
			printf("�Ѵ���,����������:");
			goto loop1;
		}
	}
	printf("��������");
	TraverseList(L,na,visit);
	printf("\n");

	printf("������B�����ݵĸ���:");
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
			printf("�Ѵ���,����������:");
			goto loop2;
		}
	}
	printf("��������");
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

	printf("��������");
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
	
	printf("���Ƿ�Ϊ��(1:�ǿ�,0:��),���:%d\n",!ListEmpty(L));
	printf("��%d\n",ListLength(L));
	
	for(i=1;i<=5;i++)
	{
		ListInsert(L,i,2*i);
	}
	
	printf("����5��Ԫ��(2,4,6,8,10),���:");
	TraverseList(L,visit);
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
	TraverseList(L,visit);
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

		
	for(i=-1;i<=N+5;i+=3)
	{
		if(PriorElem(L,i,j))
			printf("���ҵ�%d��ǰ��%d\n",i,j);
		else
			printf("����%d��ǰ��ʧ��\n",i);

		if(NextElem(L,i,j))
			printf("���ҵ�%d�ĺ��%d\n",i,j);
		else
			printf("����%d�ĺ��ʧ��\n",i);

	}

	j=ClearList(L);
	if(j)
		printf("�������ɹ�");
	else
		printf("���ʧ��");
	
	printf("���Ƿ�Ϊ��(1:�ǿ�,0:��),���:%d\n",!ListEmpty(L));
	printf("��%d\n",ListLength(L));

	printf("����ϲ�:");
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
	
	printf("���Ƿ�Ϊ��(1:�ǿ�,0:��),���:%d\n",!ListEmpty(L,n));
	printf("��%d\n",ListLength(L,n));
	
	for(i=1;i<=5;i++)
	{
		ListInsert(L,n,i,2*i);
	}
	
	printf("����5��Ԫ��(2,4,6,8,10),���:");
	TraverseList(L,n,visit);
	printf("\n");
	
	i=3;
	if(PriorElem(L,n,3,e))
		printf("%d��ǰ��Ϊ%d\n",i,e);
	if(NextElem(L,n,3,e))
		printf("%d�ĺ��Ϊ%d\n",i,e);
	
	for(i=1;i<=5;i++)
	{
		ListInsert(L,n,2*i-1,2*i-1);
	}
	
	printf("����5��Ԫ��(1,3,5,7,9)����:");
	TraverseList(L,n,visit);
	printf("\n");
	
	printf("���Ƿ�Ϊ��(1:�ǿ�,0:��),���:%d\n",!ListEmpty(L,n));
	printf("��%d\n",ListLength(L,n));
	
	for(i=9;i<=10;i++)
	{
		printf("ɾ��%d��Ԫ��Ϊ",i);
		if(ListDelete(L,n,i,e))
			printf("%d\n",e);
		else
			printf("ɾ��ʧ��\n");
	}
	
	int j=0;
	for(i=-1;i<=1;i++)
	{
		printf("����%d����λ��",i);
		j=LocateElem(L,n,i,compare);
		if(j)
			printf("%d\n",j);
		else
			printf("����ʧ��\n");
	}

		
	for(i=-1;i<=N+5;i+=3)
	{
		if(PriorElem(L,n,i,j))
			printf("���ҵ�%d��ǰ��%d\n",i,j);
		else
			printf("����%d��ǰ��ʧ��\n",i);

		if(NextElem(L,n,i,j))
			printf("���ҵ�%d�ĺ��%d\n",i,j);
		else
			printf("����%d�ĺ��ʧ��\n",i);

	}

	j=ClearList(L,n);
	if(j)
		printf("�������ɹ�");
	else
		printf("���ʧ��");
	
	printf("���Ƿ�Ϊ��(1:�ǿ�,0:��),���:%d\n",!ListEmpty(L,n));
	printf("��%d\n",ListLength(L,n));

	MergeList2(Lk);
	printf("\n");
}



