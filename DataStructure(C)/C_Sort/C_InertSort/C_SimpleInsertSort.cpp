#include"C_InsertSort_Header.h"

void SimpleInsertSort(SqList &R,bool flag)
{//初始条件:顺序表R存在,flag指示有序类型(0从小到大、1从大到小)
	//操作结果:按flag指示的有序类型对R进行直接插入排序
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
{//重载
//初始条件:顺序表R存在,0号位置未占用
//操作结果:简单插入排序使R中记录按关键字从小到大排序
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