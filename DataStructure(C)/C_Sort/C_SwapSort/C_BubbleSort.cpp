#include"C_SwapSort_Header.h"

void BubbleSort(SqList &R,bool flag)
{//初始条件:顺序表R存在,0号位置未占用,flag为记录有序类型(0正序,1逆序)
	//操作结果:冒泡排序使R有序
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
				{//正序
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
{//初始条件:顺序表R存在,0号位置未占用
	//操作结果:冒泡排序使R正序有序
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