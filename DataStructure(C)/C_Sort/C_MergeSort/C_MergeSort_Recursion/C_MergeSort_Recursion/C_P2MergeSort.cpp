#include"C_P2MergeSort.h"

void MergeSort(SqList R1,SqList &R2,int low,int high);
//归并操作

void P2MergeSort(SqList &R)//重载
{//初始条件:顺序表R存在,0号位置未占用
//操作结果:2路归并排序使R中的记录按关键字正序有序
	SqList temp;
	int count;
	count=1;
	MergeSort(R,temp,1,R.n);
	for(;count<=R.n;count++)
		R.records[count]=temp.records[count];
}

void MergeSort(SqList R1,SqList &R2,int low,int high)
{//归并操作
	int mid,i,j,l;
	SqList temp;

	if(low==high)
		R2.records[low]=R1.records[low];
	else if(low<high)
	{
		mid=(low+high)/2;
		MergeSort(R1,temp,low,mid);
		MergeSort(R1,temp,mid+1,high);

		i=l=low;
		j=mid+1;
		while(i<=mid && j<=high)
		{
			if(temp.records[i].key>temp.records[j].key)
				R2.records[l++]=temp.records[j++];
			else if(temp.records[i].key<temp.records[j].key)
				R2.records[l++]=temp.records[i++];
			else
			{
				R2.records[l++]=temp.records[i++];
				R2.records[l++]=temp.records[j++];
			}
		}

		while(i<=mid)
			R2.records[l++]=temp.records[i++];
		while(j<=high)
			R2.records[l++]=temp.records[j++];
	}
}