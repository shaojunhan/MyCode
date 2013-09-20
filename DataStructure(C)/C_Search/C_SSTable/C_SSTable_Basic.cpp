#include"E:\Document\Data Structures\Study\C_Search\C_Search_Header.h"
#include<stdlib.h>

typedef int ElemType;
typedef char KeyType;
typedef struct
{
	KeyType key;
	ElemType data;
}SElemType;
#include"C_SSTable_Basic.h"
Status Create_IR(SSTable &ST)
{//ST�е�Ԫ�ذ��ؼ��ִ�С��������
	int i,j,k;
	if(ST.length<=0)
		return FALSE;
	for(i=1;i<=ST.length;i++)
	{//ѡ������
		*(ST.elem+0)=*(ST.elem+i);//0λ��Ϊ�ڱ���
		k=i;
		for(j=i+1;j<=ST.length;j++)
			if LT((*(ST.elem+j)).key,(*(ST.elem+0)).key)
			{
				k=j;
				*(ST.elem+0)=*(ST.elem+j);
			}
		if(k!=i)
		{
			*(ST.elem+k)=*(ST.elem+i);
			*(ST.elem+i)=*(ST.elem+0);
		}
	}
	return OK;
}

Status Create_OR(SSTable &ST,SElemType R[],int n)
{//R��0��ʼ,ST��0λ�ò��洢Ԫ��,nΪR���鳤��
 //����R˳����ST
	int i;
	ST.elem=(SElemType*)malloc((n+1)*sizeof(SElemType));
	if(!ST.elem)
		exit(1);
	for(i=1;i<=n;i++)
		*(ST.elem+i)=R[i-1];
	ST.length=n;
	return OK;
}
Status DestroyTable(SSTable &ST)
{//����ST
	if(ST.elem)
		free(ST.elem);
	ST.elem=NULL;
	ST.length=0;
	return OK;
}
int Search_IR(SSTable &ST,KeyType key)
{//ST��̬���ұ�,key�ؼ���
//˳�����,�ҵ�������ST�е�λ��(��1��ʼ),���򷵻ظ���
	int i;
	i=ST.length;
	(*(ST.elem+0)).key=key;//0λ��Ϊ������
	while(!EQ((*(ST.elem+i)).key,key))
		i--;
	if(i==0)
		return -1;
	else
		return i;
}

int Search_BIN(SSTable &ST,KeyType key)
{//STΪ�ؼ��ִ�С��������,keyΪ����ؼ���
//��ST������key,�ҵ���������ST��λ��(��1��ʼ),���򷵻ظ���
	int low,high,mid;
	low=1,high=ST.length;
	Create_IR(ST);
	while(low<=high)
	{
		mid=(low+high)/2;
		if(EQ((*(ST.elem+mid)).key,key))
			return mid;
		if(LT((*(ST.elem+mid)).key,key))
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}

void Traverse(SSTable &ST,void (*Visit)(SElemType))
{//Visit����ΪSElemType�ĺ���ָ��
//˳�����ST
	int i;
	for(i=1;i<=ST.length;i++)
		Visit(*(ST.elem+i));
}