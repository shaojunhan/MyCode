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
	
	for(i=0;i<=12;i+=3)
	{
		DuLNode *p=NULL;
		printf("���ҵ�%dλ�õ�Ԫ��",i);

		p=GetElemP(L,i);
		if(p)
			printf("%d\n",p->data);
		else
			printf("����ʧ��\n");
	}
	printf("��������");
	ListTraverse(L,visit);
	printf("\n");

	printf("�����������");
	ListTraverseBack(L,visit);
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