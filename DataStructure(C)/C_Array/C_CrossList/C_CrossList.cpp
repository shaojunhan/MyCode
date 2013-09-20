#include"C_CrossList_Basic.h"
#include<stdio.h>
#include<stdlib.h>

bool flag=0;
CLSMatrix M,N,Q;
int **Mm[3];//���Ծ���
int m[2],n[2];
int i,j;


int DestroyInt(int **Mm,int mu);//���ٲ��Ծ���
int Print(int **Mm,int mu,int nu);//������Ծ���
int Create(CLSMatrix &M);//��������
int TestAdd();//���Լӷ�
int TestMult();//���Գ˷�
int TestTrans();//����ת�ò���

int main(int argc,char *argv[])
{
	InitSMatrix(M);
	InitSMatrix(N);
	InitSMatrix(Q);
	Create(M);
	Create(N);

	Mm[2]=(int**)malloc(m[0]*sizeof(int*));
	if(!Mm[2])
		exit(0);
	for(i=0;i<m[0];i++)
	{
		*(Mm[2]+i)=(int*)malloc(n[1]*sizeof(int));
		if(!*(Mm[2]+i))
			exit(0);
	}
	//TestAdd();
	TestMult();
	TestTrans();
	DestroyInt(Mm[0],m[0]),DestroyInt(Mm[1],m[1]),DestroyInt(Mm[2],m[0]);
	DestroySMatrix(M),DestroySMatrix(N),DestroySMatrix(Q);
	system("pause");
	return 0;
}

int Create(CLSMatrix &M)
{
	int k=flag;

	printf("...��������%s...\n������������:",k==0?"һ":"��");
	flag=!flag;
loop1:
	scanf("%d%d%*c",&m[k],&n[k]);
	if(m[k]<0 || n[k]<0)
		goto loop1;

	printf("����:\n");
	Mm[k]=(int**)malloc(m[k]*sizeof(int*));
	if(!Mm[k])
		exit(0);
	for(i=0;i<m[k];i++)
	{
		*(Mm[k]+i)=(int*)malloc(n[k]*sizeof(int));
		if(!*(Mm[k]+i))
			exit(0);
		for(j=0;j<n[k];j++)
			scanf("%d%*c",(*(Mm[k]+i)+j));
	}
	CreateSMatrix(M,m[k],n[k],Mm[k]);
	return 0;
}

int DestroyInt(int **Mm,int mu)
{
	int i;

	for(i=0;i<mu;i++)
		free(*(Mm+i));
	free(Mm);
	Mm=NULL;

	return 0;
}

int Print(int **Mm,int mu,int nu)
{
	int i,j;
	for(i=0;i<mu;i++)
	{
		for(j=0;j<nu;j++)
			printf("%5d",*(*(Mm+i)+j));
		putchar('\n');
	}
	return 0;
}

int TestAdd()
{
	if(m[0]!=m[1] || n[0]!=n[1])
		return -1;
	printf("�����������:\n");//����m[0]=m[1],n[0]=n[1]
	for(i=0;i<m[0];i++)
		for(j=0;j<n[0];j++)
			*(*(Mm[2]+i)+j)=*(*(Mm[0]+i)+j)+*(*(Mm[1]+i)+j);
	AddSMatrix(M,N,Q);
	printf("...�������Ա�...\n��ͳ�㷨:\n");
	Print(Mm[2],m[0],n[0]);
	printf("ϡ�����洢�㷨:\n");
	PrintSMatrix(Q);
	return 0;
}

int TestMult()
{
	int k;
	if(n[0]!=m[1])
		return -1;

	printf("...����ĳ˻�����...\n��ͳ�㷨\n");
			
	for(i=0;i<m[0];i++)
		for(j=0;j<n[1];j++)
		{
			*(*(Mm[2]+i)+j)=0;
			for(k=0;k<m[1];k++)
				*(*(Mm[2]+i)+j)+=*(*(Mm[0]+i)+k)**(*(Mm[1]+k)+j);
		}
	Print(Mm[2],m[0],n[1]);

	printf("ϡ������㷨:\n");
	MultSMatrix(M,N,Q);
	PrintSMatrix(Q);
	return 0;
}

int TestTrans()
{
	CLSMatrix Q2;
	InitSMatrix(Q2);
	printf("����ת�ò���:\n");
	TransposeSMatrix(Q,Q2);
	PrintSMatrix(Q2);
	DestroySMatrix(Q2);
	return 0;
}