#include"C_InsertSort_Header.h"

void BinInsertSort(SqList &R,bool flag)
{//��ʼ����:˳���R����,0��λ��Ϊռ��,flag��ʾ��������(0����,1����)
	//�������:���ֲ�������ʹR�м�¼���ؼ�������
	int i,j,low,high,mid;
	
	if(!flag)
	{
		for(i=2;i<=R.n;i++)
		{
			R.records[0]=R.records[i];
			low=1;
			high=i;
			while(low<=high)
			{
				mid=(low+high)/2;
				if(R.records[mid].key>R.records[0].key)
					high=mid-1;
				else
					low=mid+1;
			}
			
			if(low<i)
			{
				for(j=i;j>low;j--)
					R.records[j]=R.records[j-1];
				R.records[low]=R.records[0];
			}	
		}
	}else
	{
		for(i=2;i<=R.n;i++)
		{
			R.records[0]=R.records[i];
			low=1;
			high=i;
			while(low<=high)
			{
				mid=(low+high)/2;
				if(R.records[mid].key<R.records[0].key)
					high=mid-1;
				else
					low=mid+1;
			}
			
			if(low<i)
			{
				for(j=i;j>low;j--)
					R.records[j]=R.records[j-1];
				R.records[low]=R.records[0];
			}
		}
	}
}

void BinInsertSort(SqList &R)
{//��ʼ����:˳���R����,0��λ��Ϊռ��
//�������:���ֲ�������ʹR�м�¼���ؼ�����������
	int i,j;
	int low,high,mid;

	for(i=2;i<=R.n;i++)
	{
		R.records[0]=R.records[i];
		low=1;
		high=i;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(R.records[mid].key>R.records[0].key)
				high=mid-1;
			else
				low=mid+1;
		}

		if(low<i)
		{
			for(j=i;j>low;j--)
				R.records[j]=R.records[j-1];
			R.records[low]=R.records[0];
		}
	}
}