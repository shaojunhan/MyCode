#include"C_InsertSort_Header.h"

void BinInsertSort(SqList &R,bool flag)
{//初始条件:顺序表R存在,0号位置为占用,flag表示有序类型(0正序,1逆序)
	//操作结果:二分插入排序使R中记录按关键字有序
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
{//初始条件:顺序表R存在,0号位置为占用
//操作结果:二分插入排序使R中记录按关键字正序有序
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