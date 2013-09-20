#include"C_SelectSort_Header.h"
void HeapSort(SqList &R,int (*compare)(KeyType,KeyType));
//具体执行排序的程序
int compare_ps(KeyType key1,KeyType key2);
//positive sequence
int compare_ns(KeyType key1,KeyType key2);
//negative sequence

void HeapSelectSort(SqList &R,int flag)
{//初始条件:顺序表R存在,0号位置未占用,flag为记录有序类型标记(0正序,1逆序)
//操作结果:堆排序使R中记录按关键字有序
	if(!flag)
		HeapSort(R,compare_ps);
	else
		HeapSort(R,compare_ns);
}

void HeapSelectSort(SqList &R)
{//初始条件:顺序表R存在,0号位置为占用
//操作结果:堆排序使R中记录按关键字正序有序
	HeapSort(R,compare_ps);
}

void HeapSort(SqList &R,int (*compare)(KeyType,KeyType))
{
	int i,j,temp;
	i=R.n/2;
	while(i>=1)//建立初始大顶堆
	{
		temp=i;
		for(j=2*temp;j<=R.n;j=j*2)
		{
			if(j+1<=R.n && compare(R.records[j].key,R.records[j+1].key)<0)
				j=j+1;
			if(compare(R.records[temp].key,R.records[j].key)<0)
			{
				R.records[0]=R.records[temp];
				R.records[temp]=R.records[j];
				R.records[j]=R.records[0];
			}
			temp=j;
		}
		i--;
	}

	for(i=R.n;i>1;i--)
	{
		R.records[0]=R.records[i];
		R.records[i]=R.records[1];
		R.records[1]=R.records[0];

		temp=1;
		for(j=2*temp;j<=i-1;j=j*2)
		{
			if(j+1<=i-1 && compare(R.records[j].key,R.records[j+1].key)<0)
				j=j+1;
			if(compare(R.records[temp].key,R.records[j].key)<0)
			{
				R.records[0]=R.records[j];
				R.records[j]=R.records[temp];
				R.records[temp]=R.records[0];
			}
			temp=j;
		}
	}
}

int compare_ps(KeyType key1,KeyType key2)
{//positive sequence
	return key1==key2?0:key1>key2?1:-1;
}

int compare_ns(KeyType key1,KeyType key2)
{//negative sequence
	return key1==key2?0:key1>key2?-1:1;
}