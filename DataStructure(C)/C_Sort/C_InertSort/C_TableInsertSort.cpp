#include"C_InsertSort_Header.h"

void TableInsertSort(StaticList &R,bool flag)
{//��ʼ����:��̬����R����,0Ϊ����ͷ���,flag��ʾ��¼��������(0����,1����)
//�������:���������ʹR����
	int i,j,prior,next,count;
	i=R[0].cur;
	if(i==0)
		return;//�ջ���ֻ��һ����¼
	prior=i;
	i=R[i].cur;
	count=1;
	while(i!=0)
	{
		next=R[i].cur;
		j=0;
		while((R[(R[j].cur)].data).key<(R[i].data).key)
			j=R[j].cur;

		if(R[j].cur!=i)
		{
			R[prior].cur=R[i].cur;
			R[i].cur=R[j].cur;
			R[j].cur=i;
		}
		else
			prior=i;
		count++;
		i=next;
	}
	
	if(!flag)
	{
		i=R[0].cur;
		for(j=1;j<=count;j++)//Ԫ���ݴ�
		{
			while(i<j)
				i=R[i].cur;
			next=R[i].cur;
			if(i!=j)
			{
				R[0].data=R[i].data;
				R[i]=R[j];
				R[j].data=R[0].data;
				R[j].cur=i;
			}
			i=next;
		}
	}
	else
	{
		i=R[0].cur;
		for(j=count;j>=1;j--)
		{
			while(i>j)
				i=R[i].cur;
			next=R[i].cur;
			if(i!=j)
			{
				R[0].data=R[i].data;//iλ��Ԫ���ݴ�
				R[i]=R[j];
				R[j].data=R[0].data;
				R[j].cur=i;
			}
			i=next;
		}
	}
	for(i=0;i<count;i++)//���µ�������
		R[i].cur=i+1;
	R[i].cur=0;
}

void TableInsertSort(StaticList &R)//����
{//��ʼ����:��̬����R����,0Ϊ����ͷ���
//�������:���������ʹR��������
	int i,j,prior,next,count;
	i=R[0].cur;
	if(i==0)
		return;
	prior=i;
	i=R[i].cur;
	count=1;
	while(i!=0)
	{
		next=R[i].cur;
		j=0;
		while((R[R[j].cur].data).key<(R[i].data).key)
			j=R[j].cur;
		if(R[j].cur!=i)
		{
			R[prior].cur=R[i].cur;
			R[i].cur=R[j].cur;
			R[j].cur=i;
		}
		else
			prior=i;
		count++;
		i=next;
	}

	i=R[0].cur;
	for(j=1;j<=count;j++)
	{
		while(i<j)
			i=R[i].cur;
		next=R[i].cur;
		if(i!=j)
		{
			R[0].data=R[i].data;
			R[i]=R[j];
			R[j].data=R[0].data;
			R[j].cur=i;
		}
		i=next;
	}
	for(i=0;i<count;i++)//���µ�������
		R[i].cur=i+1;
	R[i].cur=0;
}

void InitList(StaticList &L)
{//�������:��ʼ����̬����,��ͷΪ0�����洢���ý��
	int i;
	for(i=1;i<MAXSIZE;i++)
		L[i-1].cur=i;
	L[i].cur=0;//��β
}

bool ListEmpty(StaticList L,int head)
{//�������:�ж������Ƿ�Ϊ��
	return L[head].cur==0;
}

int ListLength(StaticList L,int head)
{//�������:��������head�ĳ���
	int count,i;
	count=0;
	i=head;
	while(i!=0)
	{
		i=L[i].cur;
		count++;
	}
	return count;
}

int ClearList(StaticList &L,int head)
{//�������:�������head,ʧ�ܷ���0,�ɹ�����1
	int i;
	if(L[head].cur==0)
		return 0;
	i=L[head].cur;
	while(L[i].cur!=0)
		i=L[i].cur;
	L[i].cur=L[0].cur;
	L[0].cur=L[head].cur;
	return 1;
}

int GetElem(StaticList &L,int head,int i,ElemType &e)
{//��ʼ����:��̬����L����,headΪ�����ͷ,0<i<=ListLength(head)
//�������:��e��������head�ĵ�i������
	int j,count;

	if(i<=0 || i>ListLength(L,head))
		return 0;
	j=L[head].cur;
	count=1;
	while(count<i)
	{
		j=L[j].cur;
		count++;
	}
	e=L[j].data;
	return 1;
}

int LocateElem(StaticList L,int head,ElemType e,int (*compare)(ElemType,ElemType))
{//��ʼ����:��̬����L����,headΪ�����ͷ
//�������:����Ԫ��e��������head�е�λ��
	int i,count;
	i=L[head].cur;
	count=1;
	while(i!=0)
	{
		if(!compare(L[i].data,e))
			return count;
		i=L[i].cur;
		count++;
	}
	return 0;
}

int PriorElem(StaticList L,int head,ElemType cur_e,ElemType &prior_e,
			  int (*compare)(ElemType,ElemType))
{//��ʼ����:��̬����L����,headΪ��ͷ,cur_eΪ����head�е�һ��Ԫ��
//�������:prior_e��������head��cur_e��ǰ��,�ɹ�����0,ʧ�ܷ���0
	int i,next;
	
	i=L[head].cur;
	if(i==0 || L[i].cur==0)
		return 0;
	while(L[i].cur)
	{
		next=L[i].cur;
		if(!compare(cur_e,L[next].data))
		{
			prior_e=L[i].data;
			return 1;
		}
		i=next;
	}
	return 0;
}

int NextElem(StaticList L,int head,ElemType cur_e,ElemType &next_e,
			 int (*compare)(ElemType,ElemType))
{//��ʼ����:L����,headΪ��ͷ,cur_eΪ����head�е�һԪ��
//�������:��next_e��������head��Ԫ��cur_e�ĺ��
	int i;
	i=L[head].cur;
	while(i!=0)
	{
		if(!compare(L[i].data,cur_e))
			break;
		i=L[i].cur;
	}

	if(i==0 || L[i].cur==0)
		return 0;
	next_e=L[i].data;
	return 1;
}

int ListInsert(StaticList &L,int head,int i,ElemType e,int (*compare)(ElemType,ElemType))
{//��ʼ����:L����,headΪ��ͷ,0<i<=ListLength(head)+1
//�������:����head�е�i��λ�ò���Ԫ��e
	int j,count,n;
	if(i<=0 || i>ListLength(L,head)+1)
		return 0;
	j=head;
	count=0;
	while(count<i-1)
		j=L[j].cur;
	n=Malloc(L);
	if(n)
	{
		L[n].cur=L[j].cur;
		L[j].cur=n;
		return 1;
	}
	return 0;
}

int ListDelete(StaticList &L,int head,int i,ElemType &e)
{//��ʼ����:L����,headΪ��ͷ,0<i<=ListLenngth(head)
//�������:ɾ������head�еĵ�i��Ԫ��,��e����ɾ��Ԫ�ص�ֵ
	int j,count,n;
	if(i<=0 || i>ListLength(L,head))
		return 0;
	j=head;
	count=0;
	while(count<i-1)
		j=L[j].cur;
	n=L[j].cur;
	L[j].cur=L[n].cur;
	Free(L,n);
	return 1;
}

void TraverseList(StaticList L,int head,void (*Visit)(ElemType))
{//�������:��������head�е�ÿ��Ԫ��һ��
	int i;
	i=L[head].cur;
	while(i!=0)
	{
		Visit(L[i].data);
		i=L[i].cur;
	}
}

int Malloc(StaticList &L)
{//�������:����һ�����ô洢��Ԫ
	int i;
	i=L[0].cur;
	if(i!=0)
	{
		L[0].cur=L[i].cur;
		L[i].cur=0;
	}
	return i;
}

void Free(StaticList &L,int n)
{//�������:����һ�����ô洢��Ԫ
	if(n>0 && n<=MAXSIZE)
	{
		L[n].cur=L[0].cur;
		L[0].cur=n;
	}
}