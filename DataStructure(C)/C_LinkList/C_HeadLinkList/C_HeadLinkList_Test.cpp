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

//������������
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

	printf("�Ƿ�Ϊ�ձ�(1:�� 0:��)------%d\n",!ListEmpty(L));
	printf("����:%d\n",ListLength(L));

	for(i=0;i<5;i++)
	{
		OrderInsert(L,2*(i+1),compare);
	}

	printf("����ż��(2,4,6,8,10)��:");
	ListTraverse(L,visit);
	printf("\n");

	for(i=0;i<5;i++)
	{
		OrderInsert(L,2*i+1,compare);
	}

	printf("��������(1,3,5,7,9)��:");
	ListTraverse(L,visit);
	printf("\n");

	for(i=0;i<=N+2;i+=3)
	{
		if(LocateElem(L,i,p,compare))
		{
			printf("����%d�ɹ����ҵ���ַ%d,���%d\n",i,p,p->data);
		}
		else
			printf("����%dʧ��\n",i);
	}

	printf("�Ƿ�Ϊ�ձ�(1:�� 0:��)------%d\n",!ListEmpty(L));
	printf("����:%d\n",ListLength(L));

	for(i=0;i<=N+2;i+=3)
	{
		j=LocateElem(L,i,compare);
		if(j)
		{
			printf("����%d�ɹ����ҵ��ڵ�%d��\n",i,j);
		}
		else
			printf("����%dʧ��\n",i);
	}

	p=GetLast(L);
	i=5;
	printf("�ڽ�βǰ����%d,",i);
	MakeNode(s,i);
	if(InsBefore(L,p,s))
		printf("����ɹ�:");
	else
		printf("����ʧ��:");
	ListTraverse(L,visit);
	printf("\n");

	i=12;
	printf("�ڽ�β�����%d,",i);
	MakeNode(s,i);
	if(InsAfter(L,p,s))
		printf("����ɹ�:");
	else
		printf("����ʧ��:");
	ListTraverse(L,visit);
	printf("\n");

	printf("��β��ǰ������ַ%d,���",p);
	p=PriorPos(L,GetLast(L));
	if(p)
		printf("(%d)%d\n",p,p->data);
	else
		printf("ʧ��\n");

	i=11;
	printf("���ý�βΪ%d������:",i);
	SetCurElem(GetLast(L),i);
	ListTraverse(L,visit);
	printf("\n");

	printf("�Ƿ�Ϊ�ձ�(1:�� 0:��)------%d\n",!ListEmpty(L));
	printf("����:%d\n",ListLength(L));

	ClearList(L);
	printf("��������:");
	ListTraverse(L,visit);
	printf("\n");

	printf("���������:");
	ListTraverse(L,visit);
	printf("\n");

}

//Union/Merge����
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

	printf("La����ż��(2,4,6,8,10)��:");
	ListTraverse(La,visit);
	printf("\n");

	i=5;
	OrderInsert(La,i,compare);
	printf("La����5��:");
	ListTraverse(La,visit);
	printf("\n");

	for(i=0;i<5;i++)
	{
		OrderInsert(Lb,2*i+1,compare);
	}

	printf("Lb��������(1,3,5,7,9)��:");
	ListTraverse(Lb,visit);
	printf("\n");

	i=6;
	OrderInsert(Lb,i,compare);
	printf("Lb����5��:");
	ListTraverse(Lb,visit);
	printf("\n");

	ListUnion(La,Lb);
	printf("�ϲ���:");
	ListTraverse(La,visit);
	printf("\n");

	printf("Merge�ϲ���:");
	MergeList(La,Lb,Lc);
	ListTraverse(Lc,visit);
	printf("\n");
}