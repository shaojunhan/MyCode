#include"C_PTree_Basic.h"
#include<stdio.h>
#include<string.h>

char Nil='#';
Status InitTree(PTree &T)
{
	T.n=0;//��ʼΪ����
	return OK;
}

void DestroyTree(PTree &T)
{
}

Status CreateTree(PTree &T)
{
	//��ֵ
	int q[MAX_SIZE];//����
	int front,rear;
	int i,l,p,n;
	char c;//�ڵ�����
	char buf[MAX_SIZE];

	front=rear=0;
	for(i=0;i<MAX_SIZE;i++)
		q[i]=-1;

	printf("\n������ڵ�:");
	scanf("%c%*c",&c);
	if(c==Nil)
	{
		T.n=0;
		return FALSE;
	}
	else
	{
		n=0;
		T.nodes[n].data=c;
		T.nodes[n++].parent=-1;
		q[rear++]=0;
		while(front!=rear)
		{
			p=q[front++];
			printf("\n����ڵ�%c���ӽڵ�:",T.nodes[p].data);
			scanf("%s%*c",buf);
			l=strlen(buf);
			for(i=0;i<l;i++)
			{
				if(buf[i]!=Nil)
				{
					T.nodes[n].data=buf[i];
					T.nodes[n].parent=p;
					q[rear++]=n++;
				}
			}
		}
		T.n=n;
		return OK;
	}
}

Status ClearTree(PTree &T)
{
	T.n=0;
	return OK;
}

bool TreeEmpty(PTree T)
{
	return T.n==0;
}

int TreeDepth(PTree T)
{
	int i,j;
	int max,def;

	if(T.n==0)
		return 0;
	else//���ϻ���
	{
		max=0;
		for(i=0;i<T.n;i++)
		{
			j=i;
			def=0;
			while(j>=0)
			{
				j=T.nodes[j].parent;
				def++;
			}

			if(max<def)
				max=def;
		}
		return max;
	}
}

TElemType Root(PTree T)
{
	int i;
	for(i=0;i<T.n;i++)
		if(T.nodes[i].parent<0)
			return T.nodes[i].data;
	return Nil;
}

TElemType Value(PTree T,int i)
{
	if(i<T.n && i>=0)
		return T.nodes[i].data;
	else
		return Nil;
}

Status Assign(PTree &T,TElemType cur_e,TElemType value)
{
	int i;
	for(i=0;i<T.n;i++)
		if(T.nodes[i].data==cur_e)
		{
			T.nodes[i].data=value;
			return OK;
		}
	return FALSE;
}

int Parent(PTree T,TElemType cur_e)
{
	int i;
	for(i=1;i<T.n;i++)
		if(T.nodes[i].data==cur_e)
			return T.nodes[i].parent;
	return -1;
}

int LeftChild(PTree T,TElemType cur_e)
{
	int i,j;
	for(i=0;i<T.n;i++)
		if(T.nodes[i].data==cur_e)
		{
			for(j=i+1;j<T.n;j++)
				if(T.nodes[j].parent==i)
					return j;
			break;
		}
	return -1;
}

int RightSibling(PTree T,TElemType cur_e)
{
	int i,j;
	
	for(i=1;i<T.n;i++)
		if(T.nodes[i].data==cur_e)
		{
			for(j=i+1;j<T.n;j++)
				if(T.nodes[j].parent==T.nodes[i].parent)
					return j;
			break;
		}
	return -1;
}

Status InsertChild(PTree &T,TElemType p,int i,PTree C)
{
	int j,k;
	int n,l;
	PTNode temp;

	if(T.n+C.n>MAX_SIZE && T.n==0)//�������߳����洢����
		return FALSE;
	
	for(l=0;l<T.n;l++)//�ҵ�p���±�
		if(T.nodes[l].data==p)
			break;
	if(l>=T.n)//δ�ҵ�
		return FALSE;

	k=0;//����
	for(n=l+1;n<T.n;n++)//�ҵ���i������
		if(T.nodes[n].parent==l && ++k==i)
			break;
	if(n>=T.n)//δ�ҵ�
		return FALSE;

	k=C.n;
	for(j=T.n-1;j>=n;j--)//�ƶ�����������λ��
	{
		T.nodes[j+k]=T.nodes[j];
		if(T.nodes[j+k].parent>=n)
			T.nodes[j+k].parent+=k;
	}

	for(j=0;j<C.n;j++)//����
	{
		T.nodes[j+n]=C.nodes[j];
		T.nodes[j+n].parent+=n;
	}
	T.nodes[n].parent=l;

	T.n+=C.n;
	j=1;
	while(j)//�����ɰ�������
	{
		l=n;
		j=0;
		while(l<T.n-1)//���ڵ㰴��С����
		{
			if(T.nodes[l].parent>T.nodes[l+1].parent)
			{
				temp=T.nodes[l+1];//����
				T.nodes[l+1]=T.nodes[l];
				T.nodes[l]=temp;

				for(k=l+1;k<T.n;k++)
				{
					if(T.nodes[k].parent==l)
						T.nodes[k].parent+=1;
					else if(T.nodes[k].parent==l+1)
						T.nodes[k].parent-=1;
				}
				j=1;
			}
			l++;
		}
	}
	return OK;
}

Status DeleteChild(PTree &T,TElemType p,int i)
{
	int j,k;
	int n,l;
	int t;

	if(T.n==0 || i<1)
		return FALSE;

	for(l=0;l<T.n;l++)//����
		if(T.nodes[l].data==p)
			break;
	if(l>=T.n)//����ʧ��
		return FALSE;

	k=0;
	for(n=l+1;n<T.n;n++)//���ҵ�i������
		if(T.nodes[n].parent==l && (++k)==i)
			break;
	if(n>=T.n)
		return FALSE;

	l=1;
	T.nodes[n].data=Nil;
	T.nodes[n].parent=-1;
	for(j=n+1;j<T.n;j++)
	{
		if(T.nodes[j].data!=Nil && T.nodes[T.nodes[j].parent].data==Nil)
		{
			T.nodes[j].data=Nil;
			T.nodes[j].parent=-1;
			l++;
		}
	}

	j=n;
	l=T.n-l;
	t=0;
	while(j<l)
	{
		if(T.nodes[j].data==Nil)
		{
			for(k=j;k<T.n-t-1;k++)
			{
				T.nodes[k]=T.nodes[k+1];
				if(T.nodes[k].parent>=j)
					T.nodes[k].parent-=1;
			}
			t++;
		}

		if(T.nodes[j].data!=Nil)
			j++;
	}
	T.n=l;
	return OK;
}

Status TraverseTree(PTree T,void (*Visit)(TElemType))
{
	int i;
	for(i=0;i<T.n;i++)
		Visit(T.nodes[i].data);
	return OK;
}
