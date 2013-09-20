#include"C_TripletSMatrix_Basic.h"
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

void Visit(ElemType e)//访问函数
{
	printf("%5d",e);
}

Status CreateSMatrix(TSSMatrix &M,int mu,int nu,ElemType **data)//创建矩阵
{
	int i,j,tu;
	if(mu<0 || nu<0)
		return ERROR;
	else
		M.mu=mu,M.nu=nu;

	for(i=0,tu=0;i<mu;i++)
		for(j=0;j<nu;j++)
			if(*(data[i]+j)!=0)
				M.data[tu].i=i,M.data[tu].j=j,M.data[tu++].e=*(data[i]+j);
	M.tu=tu;
	return OK;
}

Status DestroySMatrix(TSSMatrix &M)//销毁矩阵
{
	M.mu=M.nu=M.tu=0;
	return OK;
}

Status CopySMatrix(TSSMatrix M,TSSMatrix &T)//拷贝矩阵
{
	int i;

	M.mu=T.mu,M.nu=T.nu,M.tu=T.nu;
	for(i=0;i<T.tu;i++)
		M.data[i].i=T.data[i].i,M.data[i].j=T.data[i].j,M.data[i].e=T.data[i].e;
	return OK;
}

Status PrintSMatrix(TSSMatrix M)//输出矩阵
{
	int i,j,k;

	for(i=0;i<M.mu;i++)//
	{
		for(j=0;j<M.nu;j++)
		{
			for(k=0;k<M.tu;k++)
				if(M.data[k].i==i && M.data[k].j==j)
				{
					Visit(M.data[k].e);
					break;
				}
			if(k>=M.tu)
				Visit(0);
		}
		printf("\n");
	}

	return OK;
}

Status AddSMatrix(TSSMatrix M,TSSMatrix N,TSSMatrix &Q)//矩阵加
{
	int i,j,tu,flag;

	if(M.mu!=N.mu || M.nu!=N.nu)
		return ERROR;
	Q.mu=M.mu,Q.nu=M.nu;//
	i=j=tu=0;
	while(i<M.tu && j<N.tu)
	{
		flag=0;
		//
		if(M.data[i].i<N.data[j].i)
			flag=1;
		else if(M.data[i].i>N.data[j].i)
			flag=2;
		else
			if(M.data[i].j<N.data[j].j)
				flag=1;
			else if(M.data[i].j>N.data[j].j)
				flag=2;
			else if((M.data[i].e+N.data[j].e)!=ZERO)
				flag=3;
		switch(flag)//
		{
		case 1:
			Q.data[tu].i=M.data[i].i,Q.data[tu].j=M.data[i].j,Q.data[tu++].e=M.data[i].e,i++;
			break;
		case 2:
			Q.data[tu].i=N.data[j].i,Q.data[tu].j=N.data[j].j,Q.data[tu++].e=N.data[j].e,j++;
			break;
		case 3:
			Q.data[tu].i=M.data[i].i,Q.data[tu].j=N.data[j].j,Q.data[tu++].e=(M.data[i].e+N.data[j].e),i++,j++;
			break;
		default:
			i++,j++;
			break;
		}
	}
	//
	while(i<M.tu)
		Q.data[tu].i=M.data[i].i,Q.data[tu].j=M.data[i].j,Q.data[tu++].e=M.data[i].e,i++;
	while(j<N.tu)
		Q.data[tu].i=N.data[j].i,Q.data[tu].j=N.data[j].j,Q.data[tu++].e=N.data[j].e,j++;

	Q.tu=tu;
	return OK;
}

Status SubSMatrix(TSSMatrix M,TSSMatrix N,TSSMatrix &Q)//矩阵减
{
	int i;

	if(M.mu!=N.mu || M.nu!=N.nu)//
		return ERROR;
	for(i=0;i<N.tu;i++)//
		N.data[i].e*=MINUS;
	return AddSMatrix(M,N,Q);
}

Status MultSMatrix(TSSMatrix M,TSSMatrix N,TSSMatrix &Q)//矩阵乘
{
	int *colums[2],*totals;
	int i,j,tu;
	int ml,nl;
	int p,q;

	if(M.nu!=N.mu || M.mu*N.nu==0)//
		return ERROR;
	Q.mu=M.mu,Q.nu=N.nu;
	colums[0]=(int*)malloc((M.mu+1)*sizeof(int)),//算法一初始
		colums[1]=(int*)malloc((N.mu+1)*sizeof(int)),
		totals=(int*)malloc(N.nu*sizeof(int));//
	if(!(colums[0] && colums[1]) || !totals)
		exit(OVERFLOW);

	//算法一
	for(i=0;i<=M.mu;i++)
		*(colums[0]+i)=0;
	for(i=0;i<M.tu;i++)
		(*(colums[0]+M.data[i].i+1))++;
	for(i=1;i<=M.mu;i++)
		*(colums[0]+i)=*(colums[0]+i-1)+*(colums[0]+i);

	for(i=0;i<=N.mu;i++)
		*(colums[1]+i)=0;
	for(i=0;i<N.tu;i++)
		(*(colums[1]+N.data[i].i+1))++;
	for(i=1;i<=N.mu;i++)
		*(colums[1]+i)=*(colums[1]+i-1)+*(colums[1]+i);

	for(i=0,tu=0;i<M.mu;i++)
	{
		for(j=0;j<N.nu;j++)//
			*(totals+j)=0;

		ml=i>=M.mu-1?M.tu:*(colums[0]+i+1),p=*(colums[0]+i);
		for(p;p<ml;p++)
		{
			j=M.data[p].j;
			nl=j>=N.mu-1?N.tu:*(colums[1]+j+1),q=*(colums[1]+j);
			for(q;q<nl;q++)
				*(totals+N.data[q].j)+=(M.data[p].e)*(N.data[q].e);
		}

		for(j=0;j<N.nu;j++)
			if((totals+j)!=0)
				Q.data[tu].i=i,Q.data[tu].j=j,Q.data[tu++].e=*(totals+j);
	}

	Q.tu=tu;
	free(colums[0]),free(colums[1]),free(totals);

	
	return OK;
}

Status TransposeSMatrix(TSSMatrix M,TSSMatrix &T)//转置
{
	int i,j,k;
	int *nums,*colums;
	////算法一
	//T.mu=M.mu,T.nu=M.nu,T.tu=M.tu;
	//for(i=0;i<T.nu;i++)
	//	for(j=0;j<M.tu;j++)
	//		if(M.data[j].i==i)
	//			T.data[j].i=M.data[j].j,T.data[j].j=M.data[j].i,T.data[j].e=M.data[j].e;

	//算法二
	T.mu=M.nu,T.nu=M.mu,T.tu=M.tu;
	nums=(int*)malloc(M.nu*sizeof(int)),colums=(int*)malloc(M.nu*sizeof(int));
	if(!nums || !colums)
		exit(OVERFLOW);

	for(i=0;i<M.nu;i++)
		*(nums+i)=0;
	for(i=0;i<M.tu;i++)
		(*(nums+M.data[i].j))++;

	*(colums+0)=0;
	for(i=1;i<M.nu;i++)
		*(colums+i)=*(colums+i-1)+*(nums+i-1);

	for(i=0;i<M.tu;i++)
	{
		k=*(colums+M.data[i].j);
		T.data[k].i=M.data[i].j,
		T.data[k].j=M.data[i].i,
		T.data[k].e=M.data[i].e;
		(*(colums+M.data[i].j))++;
	}
	free(nums),free(colums);
	return OK;
}
