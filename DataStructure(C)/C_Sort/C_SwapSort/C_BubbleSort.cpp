#include"C_SwapSort_Header.h"

void BubbleSort(SqList &R,bool flag)
{//��ʼ����:˳���R����,0��λ��δռ��,flagΪ��¼��������(0����,1����)
	//�������:ð������ʹR����
	int i,j;
	bool mark;
	
	mark=1;
	if(!flag)
	{
		for(i=1;i<R.n && mark;i++)
		{
			mark=0;
			for(j=1;j<=R.n-i;j++)
			{
				if(R.records[j].key>R.records[j+1].key)
				{//����
					R.records[0]=R.records[j+1];
					R.records[j+1]=R.records[j];
					R.records[j]=R.records[0];
					mark=1;
				}
			}
		}
	}
	else
	{
		for(i=1;i<R.n && mark;i++)
		{
			mark=0;
			for(j=R.n-1;j>=i;j--)
			{
				if(R.records[j+1].key>R.records[j].key)
				{
					R.records[0]=R.records[j+1];
					R.records[j+1]=R.records[j];
					R.records[j]=R.records[0];
					mark=1;
				}
			}
		}
	}
}

void BubbleSort(SqList &R)
{//��ʼ����:˳���R����,0��λ��δռ��
	//�������:ð������ʹR��������
	int i,j;
	bool mark;
	mark=1;
	for(i=1;i<R.n && mark;i++)
	{
		mark=0;
		for(j=1;j<=R.n-i;j++)
		{
			if(R.records[j].key>R.records[j+1].key)
			{
				R.records[0]=R.records[j+1];
				R.records[j+1]=R.records[j];
				R.records[j]=R.records[0];
				mark=1;
			}
		}
	}
}