#include"C_BaseSort.h"

int h[BASENUMBER],t[BASENUMBER];
int (*group[KEYSIZE])(int);
int group_h(int a);
int group_d(int a);
int group_u(int a);
void Distribute(StaticList L,int (*group)(int));
//����
void Collect(StaticList &L);
//�ռ�
void BaseSort(StaticList &L)
{//��ʼ����:��̬����L����,L�м�¼�Ĺؼ���Ϊ��λ������
//�������:��������ʹL�м�¼���ؼ�����������
	int i,j,count,next;
	group[0]=group_u;
	group[1]=group_d;
	group[2]=group_h;
	for(i=0;i<KEYSIZE;i++)
	{
		Distribute(L,group[i]);
		Collect(L);
	}

	//��������
	i=L[0].cur;
	count=0;
	while(i!=0)
	{
		count++;
		i=L[i].cur;
	}

	i=L[0].cur;
	for(j=1;j<=count;j++)
	{
		while(i<j)
			i=L[i].cur;
		next=L[i].cur;
		if(i!=j)
		{
			L[0].data=L[i].data;
			L[i]=L[j];
			L[j].data=L[0].data;
			L[j].cur=i;
		}
		i=next;
	}
	for(j=0;j<count;j++)
		L[j].cur=j+1;
	L[j].cur=0;
}

void Distribute(StaticList L,int (*group)(int))
{
	int i,next,g;
	for(i=0;i<BASENUMBER;i++)
		h[i]=t[i]=0;
	i=L[0].cur;
	while(i!=0)
	{
		next=L[i].cur;
		g=group(L[i].data);
		if(h[g]==0)
			h[g]=t[g]=i;
		else
		{
			L[t[g]].cur=i;
			t[g]=i;
		}
		i=next;
	}
}

void Collect(StaticList &L)
{
	int i,j;
	j=0;
	for(i=0;i<BASENUMBER;i++)
	{
		if(h[i]!=0)
		{
			L[j].cur=h[i];
			j=t[i];
		}
	}
	if(j!=0)
		L[j].cur=0;
}

int group_h(int a)
{
	return (a/100)%10;
}

int group_d(int a)
{
	return (a/10)%10;
}

int group_u(int a)
{
	return a%10;
}