#include"C_InsertSort_Header.h"

void P2InsertSort(SqList &R,bool flag)
{//初始条件:顺序表R存在,0号位置未占用,flag表示记录有序类型(0正序,1逆序)
	//操作结果:2路插入排序使R中记录按关键字有序
	SqList temp;//暂存记录
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
			//上面没有if判断的话这里要加if(j!=0)
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
			//同上
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
{//初始条件:顺序表R存在,0号位置未占用
//操作结果:2路插入排序使R中记录按关键字正序有序
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