#include"C_InsertSort_Header.h"
#define INCREMENT 5
int b[INCREMENT]={1,2,3,5,7};//增量序列
void ShellInsertSort(SqList &R,int flag)
{//初始条件:顺序表R存在,0号位置为占用,flag为记录有序类型标记(0为正序,1为逆序)
//操作结果:谢尔排序使R中记录有序
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
{//初始条件:顺序表R存在,0号位置为占用
//操作结果:谢尔排序使R中记录正序有序
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