#include"C_MergeSort_Header.h"
void MergeSort(SqList &R1,SqList &R2,int n,int (*compare)(KeyType,KeyType));
//初始条件:顺序表R1存在,n为归并步长,compare为比较函数指针
//操作结果:由归并步长把R1中数据归并到R2中
int compare_ps(KeyType key1,KeyType key2);
//psitive sequence
int compare_ns(KeyType key1,KeyType key2);
//negative sequence
void P2MergeSort(SqList &R,bool flag)
{//初始条件:顺序表R存在,0号位置未占用,flag为记录有序类型标记(0正序,1逆序)
	//操作结果:2路归并排序使R中记录按关键字有序
	int step;
	SqList R1;
	if(!flag)
	{
		for(step=1;step<=(R.n+1)/2;step*=4)
		{
			MergeSort(R,R1,step,compare_ps);
			MergeSort(R1,R,2*step,compare_ps);
		}
	}else
	{
		for(step=1;step<=(R.n+1)/2;step*=4)
		{	
			MergeSort(R,R1,step,compare_ns);
			MergeSort(R1,R,2*step,compare_ns);
		}
	}
}

void P2MergeSort(SqList &R)
{//初始条件:顺序表R存在,0号位置未占用
	//操作结果:2路归并排序使R中记录按关键字正序有序
	int step;
	SqList R1;
	for(step=1;step<=(R.n+1)/2;step*=4)
	{
		MergeSort(R,R1,step,compare_ps);
		MergeSort(R1,R,2*step,compare_ps);
	}
}

void MergeSort(SqList &R1,SqList &R2,int n,int (*compare)(KeyType,KeyType))
{//初始条件:顺序表R1存在,n为归并步长,compare为比较函数指针
	//操作结果:由归并步长把R1中数据归并到R2中
	int i,j,l;
	int count;
	
	count=1;
	R2.n=R1.n;
	for(l=1;l+2*n-1<=R1.n;l+=2*n)
	{
		i=0;
		j=n;
		while(i<n && j<2*n)
		{
			if(compare(R1.records[i+l].key,R1.records[j+l].key)<0)
			{
				R2.records[count++]=R1.records[i+l];
				i++;
			}else if(compare(R1.records[i+l].key,R1.records[j+l].key)>0)
			{
				R2.records[count++]=R1.records[j+l];
				j++;
			}else
			{
				R2.records[count++]=R1.records[i+l];
				i++;
				R2.records[count++]=R1.records[j+l];
				j++;
			}
		}
		
		while(i<n)
		{
			R2.records[count++]=R1.records[i+l];
			i++;
		}
		while(j<2*n)
		{
			R2.records[count++]=R1.records[j+l];
			j++;
		}
	}
	
	//分成n和小于n的两部分
	if(l+n-1<R1.n)
	{
		i=0;
		j=n;
		while(i<n && j<R1.n+1-l)
		{
			if(compare(R1.records[i+l].key,R1.records[j+l].key)<0)
			{
				R2.records[count++]=R1.records[i+l];
				i++;
			}
			else if(compare(R1.records[i+l].key,R1.records[j+l].key)>0)
			{
				R2.records[count++]=R1.records[j+l];
				j++;
			}else
			{
				R2.records[count++]=R1.records[i+l];
				i++;
				R2.records[count++]=R1.records[j+l];
				j++;
			}
		}
		
		while(i<n)
		{
			R2.records[count++]=R1.records[i+l];
			i++;
		}
		while(j<R1.n+1-l)
		{
			R2.records[count++]=R1.records[j+l];
			j++;
		}
	}else
	{
		for(l;l<=R1.n;l++)//最后不足n个数据直接复制到R2中
			R2.records[count++]=R1.records[l];
	}
}

int compare_ps(KeyType key1,KeyType key2)
{//psitive sequence
	return key1==key2?0:key1>key2?1:-1;
}

int compare_ns(KeyType key1,KeyType key2)
{//negative sequence
	return key1==key2?0:key1>key2?-1:1;
}