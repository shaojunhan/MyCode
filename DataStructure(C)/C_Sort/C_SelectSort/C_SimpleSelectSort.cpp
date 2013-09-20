#include"C_SelectSort_Header.h"

void SimpleSelectSort(SqList &R,int flag)
{//初始条件:顺序表R存在,0号位置未占用,flag为记录有序标记(0正序,1逆序)
//操作结果:简单选择排序使R中记录有序
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
{//初始条件:顺序表R存在,0号位置未占用
//操作结果:简单选择排序使R中记录正序有序
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