#include"C_SelectSort_Header.h"

void SimpleSelectSort(SqList &R,int flag)
{//��ʼ����:˳���R����,0��λ��δռ��,flagΪ��¼������(0����,1����)
//�������:��ѡ������ʹR�м�¼����
	int i,j,temp;
	for(i=1;i<=R.n;i++)
	{
		temp=i;
		for(j=i+1;j<=R.n;j++)
		{
			if(!flag)
			{
				if(R.records[j].key<R.records[temp].key)
					temp=j;
			}
			else
			{
				if(R.records[j].key>R.records[temp].key)
					temp=j;
			}
		
		}
		if(temp!=i)
		{
			R.records[0]=R.records[i];
			R.records[i]=R.records[temp];
			R.records[temp]=R.records[0];
		}
	}
}

void SimpleSelectSort(SqList &R)
{//��ʼ����:˳���R����,0��λ��δռ��
//�������:��ѡ������ʹR�м�¼��������
	int i,j,temp;
	for(i=1;i<=R.n;i++)
	{
		temp=i;
		for(j=i+1;j<=R.n;j++)
		{
			if(R.records[j].key<R.records[temp].key)
				temp=j;
		}
		if(temp!=i)
		{
			R.records[0]=R.records[i];
			R.records[i]=R.records[temp];
			R.records[temp]=R.records[0];
		}
	}
}