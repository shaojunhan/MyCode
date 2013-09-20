#include"C_P2MergeSort.h"

void MergeSort(SqList R1,SqList &R2,int low,int high);
//�鲢����

void P2MergeSort(SqList &R)//����
{//��ʼ����:˳���R����,0��λ��δռ��
//�������:2·�鲢����ʹR�еļ�¼���ؼ�����������
	SqList temp;
	int count;
	count=1;
	MergeSort(R,temp,1,R.n);
	for(;count<=R.n;count++)
		R.records[count]=temp.records[count];
}

void MergeSort(SqList R1,SqList &R2,int low,int high)
{//�鲢����
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