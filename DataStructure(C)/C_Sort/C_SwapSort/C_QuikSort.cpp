#include"C_SwapSort_Header.h"

int compare_ps(KeyType key1,KeyType key2);
//positive sequence
int compare_ns(KeyType key1,KeyType key2);
//negative sequence
void QSort(SqList &R,int low,int high,int (*compare)(KeyType,KeyType));
//具体执行快速排序

void QuikSort(SqList &R,bool flag)
{//初始条件:顺序表R存在,0号元素未占用,flag为记录有序类型标记(0正序,1逆序)
//操作结果:快速排序使R有序
	if(!flag)
		QSort(R,1,R.n,compare_ps);
	else
		QSort(R,1,R.n,compare_ns);
}

void QuikSort(SqList &R)
{//初始条件:顺序表R存在,0号元素未占用
//操作结果:快速排序使R正序有序
	QSort(R,1,R.n,compare_ps);
}

void QSort(SqList &R,int low,int high,int (*compare)(KeyType,KeyType))
{
	int l=low,h=high;
	if(low>=high)
		return;
	R.records[0]=R.records[low];
	while(l<h)
	{
		while(l<h && !(compare(R.records[h].key,R.records[0].key)<0))
			h--;
		R.records[l]=R.records[h];
		while(l<h && !(compare(R.records[l].key,R.records[0].key)>0))
			l++;
		R.records[h]=R.records[l];
	}
	R.records[l]=R.records[0];
	QSort(R,low,l-1,compare);
	QSort(R,l+1,high,compare);
}

int compare_ps(KeyType key1,KeyType key2)
{//positive sequence
	return key1==key2?0:key1>key2?1:-1;
}

int compare_ns(KeyType key1,KeyType key2)
{//negative sequence
	return key1==key2?0:key1>key2?-1:1;
}