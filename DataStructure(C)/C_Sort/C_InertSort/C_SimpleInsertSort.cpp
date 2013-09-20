#include"C_InsertSort_Header.h"

void SimpleInsertSort(SqList &R,bool flag)
{//��ʼ����:˳���R����,flagָʾ��������(0��С����1�Ӵ�С)
	//�������:��flagָʾ���������Ͷ�R����ֱ�Ӳ�������
	int i,j;
	
	if(!flag)
	{
		for(i=2;i<=R.n;i++)
		{
			R.records[0]=R.records[i];
			j=i;
			while(R.records[j-1].key>R.records[0].key)
			{
				R.records[j]=R.records[j-1];
				j--;
			}
			R.records[j]=R.records[0];
		}
	}
	else
	{
		for(i=2;i<=R.n;i++)
		{
			R.records[0]=R.records[i];
			j=i;
			while(R.records[j-1].key<R.records[0].key)
			{
				R.records[j]=R.records[j-1];
				j--;
			}
			R.records[j]=R.records[0];
		}
	}
}

void SimpleInsertSort(SqList &R)
{//����
//��ʼ����:˳���R����,0��λ��δռ��
//�������:�򵥲�������ʹR�м�¼���ؼ��ִ�С��������
	int i,j;

	for(i=2;i<=R.n;i++)
	{
		R.records[0]=R.records[i];
		for(j=i;R.records[j-1].key>R.records[0].key;j--)
			R.records[j]=R.records[j-1];
		if(j!=i)
			R.records[j]=R.records[0];
	}
}