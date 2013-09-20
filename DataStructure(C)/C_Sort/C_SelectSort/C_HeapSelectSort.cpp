#include"C_SelectSort_Header.h"
void HeapSort(SqList &R,int (*compare)(KeyType,KeyType));
//����ִ������ĳ���
int compare_ps(KeyType key1,KeyType key2);
//positive sequence
int compare_ns(KeyType key1,KeyType key2);
//negative sequence

void HeapSelectSort(SqList &R,int flag)
{//��ʼ����:˳���R����,0��λ��δռ��,flagΪ��¼�������ͱ��(0����,1����)
//�������:������ʹR�м�¼���ؼ�������
	if(!flag)
		HeapSort(R,compare_ps);
	else
		HeapSort(R,compare_ns);
}

void HeapSelectSort(SqList &R)
{//��ʼ����:˳���R����,0��λ��Ϊռ��
//�������:������ʹR�м�¼���ؼ�����������
	HeapSort(R,compare_ps);
}

void HeapSort(SqList &R,int (*compare)(KeyType,KeyType))
{
	int i,j,temp;
	i=R.n/2;
	while(i>=1)//������ʼ�󶥶�
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