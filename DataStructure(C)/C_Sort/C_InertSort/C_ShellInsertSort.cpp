#include"C_InsertSort_Header.h"
#define INCREMENT 5
int b[INCREMENT]={1,2,3,5,7};//��������
void ShellInsertSort(SqList &R,int flag)
{//��ʼ����:˳���R����,0��λ��Ϊռ��,flagΪ��¼�������ͱ��(0Ϊ����,1Ϊ����)
//�������:л������ʹR�м�¼����
	int i,j,n;
	n=INCREMENT-1;
	if(!flag)
	{while(n>=0)
	{
		for(i=b[n]+1;i<=R.n;i++)
		{
			R.records[0]=R.records[i];
			j=i;
			while(j-b[n]>0 && R.records[j-b[n]].key>R.records[0].key)
			{
				R.records[j]=R.records[j-b[n]];
				j=j-b[n];
			}

			if(j!=i)
				R.records[j]=R.records[0];
		}
		n--;
	}
	}
	else
	{
		while(n>=0)
		{
			for(i=b[n]+1;i<=R.n;i++)
			{
				R.records[0]=R.records[i];
				j=i;
				while(j-b[n]>0 && R.records[j-b[n]].key<R.records[0].key)
				{
					R.records[j]=R.records[j-b[n]];
					j=j-b[n];
				}
				if(j!=i)
					R.records[j]=R.records[0];
			}
			n--;
		}
	}
}

void ShellInsertSort(SqList &R)
{//��ʼ����:˳���R����,0��λ��Ϊռ��
//�������:л������ʹR�м�¼��������
	int i,j,n;
	n=INCREMENT-1;
	while(n>=0)
	{
		for(i=b[n]+1;i<=R.n;i++)
		{
			R.records[0]=R.records[i];
			j=i;
			while(j-b[n]>0 && R.records[j-b[n]].key>R.records[0].key)
			{
				R.records[j]=R.records[j-b[n]];
				j=j-b[n];
			}
			if(j!=i)
				R.records[j]=R.records[0];
		}
		n--;
	}
}