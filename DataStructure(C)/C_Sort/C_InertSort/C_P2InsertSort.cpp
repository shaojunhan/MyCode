#include"C_InsertSort_Header.h"

void P2InsertSort(SqList &R,bool flag)
{//��ʼ����:˳���R����,0��λ��δռ��,flag��ʾ��¼��������(0����,1����)
	//�������:2·��������ʹR�м�¼���ؼ�������
	SqList temp;//�ݴ��¼
	int i,j,low,high;

	temp.records[0]=R.records[1];
	low=high=0;
	for(i=2;i<=R.n;i++)
	{
		
		if(R.records[i].key<temp.records[0].key)
		{
			low=(low-1+MAXSIZE)%MAXSIZE;
			j=low;
			while(temp.records[(j+1)%MAXSIZE].key<R.records[i].key)
			{
				temp.records[j]=temp.records[(j+1)%MAXSIZE];
				j=(++j)%MAXSIZE;
			}
			//����û��if�жϵĻ�����Ҫ��if(j!=0)
			temp.records[j]=R.records[i];
		}
		else
		{
			high=(high+1)%MAXSIZE;
			j=high;
			while(temp.records[(j-1+MAXSIZE)%MAXSIZE].key>R.records[i].key)
			{
				temp.records[j]=temp.records[(j-1+MAXSIZE)%MAXSIZE];
				j=(--j+MAXSIZE)%MAXSIZE;
			}
			//ͬ��
			temp.records[j]=R.records[i];
		}
	}

	if(!flag)
	{
		i=1;
		j=low;
		do
		{
			R.records[i]=temp.records[j];
			i++;
			j=(j+1)%MAXSIZE;
		}while(j!=high);
		R.records[i]=temp.records[j];
	}
	else
	{
		i=1;
		j=high;
		do
		{
			R.records[i]=temp.records[j];
			i++;
			j=(j-1+MAXSIZE)%MAXSIZE;
		}while(j!=low);
		R.records[i]=temp.records[j];
	}
}

void P2InsertSort(SqList &R)
{//��ʼ����:˳���R����,0��λ��δռ��
//�������:2·��������ʹR�м�¼���ؼ�����������
	int i,j,low,high;
	SqList temp;

	temp.records[0]=R.records[1];
	low=high=0;
	for(i=2;i<=R.n;i++)
	{
		if(R.records[i].key<temp.records[0].key)
		{
			low=(low-1+MAXSIZE)%MAXSIZE;
			j=low;
			while(temp.records[(j+1)%MAXSIZE].key<R.records[i].key)
			{
				temp.records[j]=temp.records[(j+1)%MAXSIZE];
				j=(j+1)%MAXSIZE;
			}
			temp.records[j]=R.records[i];
		}else
		{
			high=(high+1)%MAXSIZE;
			j=high;
			while(temp.records[(j-1+MAXSIZE)%MAXSIZE].key>R.records[i].key)
			{
				temp.records[j]=temp.records[(j-1+MAXSIZE)%MAXSIZE];
				j=(j-1+MAXSIZE)%MAXSIZE;
			}
			temp.records[j]=R.records[i];
		}
	}

	i=1;
	j=low;
	do
	{	
		R.records[i]=temp.records[j];
		i++;
		j=(j+1)%MAXSIZE;
	}while(j!=high);
	R.records[i]=temp.records[j];
}