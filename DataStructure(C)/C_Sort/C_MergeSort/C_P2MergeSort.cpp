#include"C_MergeSort_Header.h"
void MergeSort(SqList &R1,SqList &R2,int n,int (*compare)(KeyType,KeyType));
//��ʼ����:˳���R1����,nΪ�鲢����,compareΪ�ȽϺ���ָ��
//�������:�ɹ鲢������R1�����ݹ鲢��R2��
int compare_ps(KeyType key1,KeyType key2);
//psitive sequence
int compare_ns(KeyType key1,KeyType key2);
//negative sequence
void P2MergeSort(SqList &R,bool flag)
{//��ʼ����:˳���R����,0��λ��δռ��,flagΪ��¼�������ͱ��(0����,1����)
	//�������:2·�鲢����ʹR�м�¼���ؼ�������
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
{//��ʼ����:˳���R����,0��λ��δռ��
	//�������:2·�鲢����ʹR�м�¼���ؼ�����������
	int step;
	SqList R1;
	for(step=1;step<=(R.n+1)/2;step*=4)
	{
		MergeSort(R,R1,step,compare_ps);
		MergeSort(R1,R,2*step,compare_ps);
	}
}

void MergeSort(SqList &R1,SqList &R2,int n,int (*compare)(KeyType,KeyType))
{//��ʼ����:˳���R1����,nΪ�鲢����,compareΪ�ȽϺ���ָ��
	//�������:�ɹ鲢������R1�����ݹ鲢��R2��
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
	
	//�ֳ�n��С��n��������
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
		for(l;l<=R1.n;l++)//�����n������ֱ�Ӹ��Ƶ�R2��
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