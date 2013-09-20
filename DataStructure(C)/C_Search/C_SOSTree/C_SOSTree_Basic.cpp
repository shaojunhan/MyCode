#include"E:\Document\Data Structures\Study\C_Search\C_Search_Header.h"
#include<stdlib.h>
#include<math.h>

typedef int KeyType;
typedef struct
{
	char Sno[11];
	char Name[9];
	char sex[3];
	unsigned int age;
	char major[21];
}ElemType;
typedef struct
{
	KeyType key;
	int weight;
	ElemType data;
}TElemType;
#include"C_SOSTree_Basic.h"
int SecondOptimal(BiTree &T,int sweight[],TElemType R[],int low,int high)
{//TΪ����������,sweightΪȨֵ�͵ļ���,sweight[0]=0,RΪ��������,low,highΪR�����±�
//����Ȩֵ�������Ų�����T,�ɹ�����0
	int i,j;
	int dw,min;
	i=low;
	dw=sweight[high]+sweight[low-1];
	min=sweight[low];
	for(j=low+1;j<=high;j++)
	{
		if(fabs((dw-sweight[j]-sweight[j-1]))<min)//j����������Ȩֵ�͵Ĳ���С
		{
			i=j;
			min=fabs(dw-sweight[j]-sweight[j-1]);
		}
	}

	T=(BiTree)malloc(sizeof(BTNode));
	if(!T)
		exit(1);
	T->data=R[i-1];
	if(i==low)
		T->lchild=NULL;
	else
		SecondOptimal(T->lchild,sweight,R,low,i-1);
	if(i==high)
		T->rchild=NULL;
	else
		SecondOptimal(T->rchild,sweight,R,i+1,high);
	return 0;
}

void FindSW(int sweight[],TElemType R[],int n)
{//sweightΪ����n+1����,RΪ����,nΪ���鳤��
//����Ȩֵ�ͷ���sweight��,sweight��0λ��ΪȨֵ��0
	int i;
	sweight[0]=0;
	for(i=1;i<=n;i++)
		sweight[i]=sweight[i-1]+R[i-1].weight;
}

int Search(BiTree T,KeyType key,BiTree &p)
{//���ݹؼ����ڴ�����������
//�ҵ�p�����������������0,����p=null����1
	while(T)
	{
		if(EQ((T->data).key,key))
		{
			p=T;
			return 0;
		}
		if(LT((T->data).key,key))
			T=T->rchild;
		else
			T=T->lchild;
	}
	p=NULL;
	return 1;
}

void Traverse(BiTree T,void (*Visit)(TElemType))
{//������
	if(T)
	{
		Traverse(T->lchild,Visit);
		Visit(T->data);
		Traverse(T->rchild,Visit);
	}
}

void DestroyTree(BiTree &T)
{//���ٴ�����T
	if(T)
	{
		if(T->lchild)
			DestroyTree(T->lchild);
		if(T->rchild)
			DestroyTree(T->rchild);
		free(T);
		T=NULL;
	}
}