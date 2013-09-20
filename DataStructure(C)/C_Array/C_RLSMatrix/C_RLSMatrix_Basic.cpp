#include"C_RLSMatrix_Basic.h"
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

void Visit(ElemType e)
{
	printf("%5d",e);
}

Status CreateSMatrix(RLSMatrix &M,int mu,int nu,ElemType *data[])
{
	int i,j,tu;

	if(mu<0 || nu<0 || mu>MAXROW)
		return ERROR;

	M.mu=mu,M.nu=nu;
	for(i=0;i<mu;i++)
		M.rpos[i]=0;
	for(tu=0,i=0;i<mu;i++)
		for(j=0;j<nu;j++)
			if(*(data[i]+j)!=ZERO)
			{
				M.data[tu].i=i,M.data[tu].j=j,M.data[tu++].e=*(data[i]+j);
				M.rpos[i]++;
			}
	
	//初始M.rpos[]
	M.tu=tu;
	M.rpos[M.mu-1]=M.tu-M.rpos[M.mu-1];
	for(i=mu-2;i>=0;i--)
		M.rpos[i]=M.rpos[i+1]-M.rpos[i];
	return OK;
}

//
Status DestroySMatrix(RLSMatrix &M)
{
	M.mu=M.nu=M.tu=0;
	return OK;
}

Status PrintSMatrix(RLSMatrix M)
{
	int i,j;
	bool flag;
	int p,ml;

	for(i=0;i<M.mu;i++)
	{
		for(j=0;j<M.nu;j++)
		{
			flag=0;
			ml=i>=M.mu-1?M.tu:M.rpos[i+1];
			for(p=M.rpos[i];p<ml;p++)
			{
				if(M.data[p].j==j)
				{
					Visit(M.data[p].e);
					flag=1;
					break;
				}
			}
			if(!flag)
				Visit(ZERO);
		}
		putchar('\n');
	}

	return OK;
}

Status CopySMatrix(RLSMatrix M,RLSMatrix &T)
{
	int i;

	T.mu=M.mu,T.nu=M.nu,T.tu=M.tu;

	if(!M.tu)
		return ERROR;
	
	for(i=0;i<M.tu;i++)
	{
		T.data[i].i=M.data[i].i,T.data[i].j=M.data[i].j,T.data[i].e=M.data[i].e;
		T.rpos[i]=M.rpos[i];
	}
	return OK;
}

Status AddSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q)
{
	int i,j,tu;

	if(M.mu!=N.mu || M.nu!=N.nu)
		return ERROR;

	Q.mu=M.mu,Q.nu=M.nu;
	for(i=0;i<M.mu;i++)
		Q.rpos[i]=0;

	i=j=tu=0;
	while(i<M.tu && j<N.tu)
	{
		//分五种情况
		if(M.data[i].i<N.data[j].i || (M.data[i].i==N.data[j].i && M.data[i].j<N.data[j].j))
		{
			Q.data[tu].i=M.data[i].i,Q.data[tu].j=M.data[i].j,Q.data[tu++].e=M.data[i].e;
			Q.rpos[M.data[i].i]++;
			i++;
		}
		else if(M.data[i].i>N.data[j].i || M.data[i].j>N.data[j].j)
		{
			Q.data[tu].i=N.data[j].i,Q.data[tu].j=N.data[j].j,Q.data[tu++].e=N.data[j].e;
			Q.rpos[N.data[j].i]++;
			j++;
		}
		else if((M.data[i].e+N.data[j].e)!=ZERO)
		{
			Q.data[tu].i=M.data[i].i,Q.data[tu].j=M.data[i].j,Q.data[tu++].e=M.data[i].e+N.data[j].e;
			Q.rpos[M.data[i].i]++;
			i++,j++;
		}
		else
			i++,j++;
	}

	while(i<M.tu)
	{
		Q.data[tu].i=M.data[i].i,Q.data[tu].j=M.data[i].j,Q.data[tu++].e=M.data[i].e;
		Q.rpos[M.data[i].i]++;
		i++;
	}

	while(j<N.tu)
	{
		Q.data[tu].i=N.data[j].i,Q.data[tu].j=N.data[j].j,Q.data[tu++].e=N.data[j].e;
		Q.rpos[N.data[j].i]++;
		j++;
	}

	Q.tu=tu;
	Q.rpos[Q.mu-1]=Q.tu-Q.rpos[Q.mu-1];
	for(i=Q.mu-2;i>=0;i--)
		Q.rpos[i]=Q.rpos[i+1]-Q.rpos[i];
	return OK;
}

Status SubSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q)
{
	int i;

	for(i=0;i<N.tu;i++)
		N.data[i].e*=-1;
	AddSMatrix(M,N,Q);
	return OK;
}

//矩阵乘积运算
Status MultSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q)
{
	ElemType *totals;
	int i,j,tu;
	int p,ml;
	int q,nl;

	if(M.nu!=N.mu || M.mu*N.nu==0)
		return ERROR;
	Q.mu=M.mu,Q.nu=N.nu;

	totals=(ElemType*)malloc(N.nu*sizeof(ElemType));
	if(!totals)
		exit(OVERFLOW);
	
	for(i=0;i<M.mu;i++)
		Q.rpos[i]=0;

	for(tu=0,i=0;i<M.mu;i++)
	{
		for(j=0;j<N.nu;j++)
			*(totals+j)=0;
		
		ml=i==M.mu-1?M.tu:M.rpos[i+1];
		for(p=M.rpos[i];p<ml;p++)
		{
			j=M.data[p].j;
			nl=j==N.mu-1?N.tu:N.rpos[j+1];
			for(q=N.rpos[j];q<nl;q++)
				*(totals+N.data[q].j)+=M.data[p].e*N.data[q].e;
		}

		for(j=0;j<N.nu;j++)
			if(*(totals+j)!=ZERO)
			{
				Q.data[tu].i=i,Q.data[tu].j=j,Q.data[tu++].e=*(totals+j);
				Q.rpos[i]++;
			}
	}

	Q.tu=tu;
	Q.rpos[Q.mu-1]=Q.tu-Q.rpos[Q.mu-1];
	for(i=Q.mu-2;i>=0;i--)
		Q.rpos[i]=Q.rpos[i+1]-Q.rpos[i];
	return OK;
}

Status TransposeSMatrix(RLSMatrix M,RLSMatrix &T)
{
	int i,j,tu;
		
	if(!M.mu || !M.nu)
		return ERROR;

	//算法一
	/*
	for(i=0;i<M.nu;i++)
		N.rpos[i]=0;
	T.mu=M.nu,T.nu=M.mu,T.tu=M.tu;
	for(tu=0,i=0;i<M.nu;i++)
		for(j=0;j<M.tu;j++)
			if(M.data[j].j==i)
			{
				T.data[tu].i=i,T.data[tu].j=M.data[i].i,T.data[tu++].e=M.data[i].e;
				T.rpos[i]++;
			}
	T.rpos[mu-1]=T.tu-T.rpos[T.mu-1];
	for(i=T.mu-2;i>=0;i--)
		T.rpos[i]=T.rpos[i+1]-T.rpos[i];
	*/
	
	//算法二
	/*
	int *rpos;
	int p;

	T.mu=M.nu,T.nu=M.mu,T.tu=M.tu;
	rpos=(int*)malloc(M.mu*sizeof(int));
	if(!rpos)
		return ERROR;

	for(i=0;i<M.mu;i++)
		*(rpos+i)=M.rpos[i];
	for(i=0;i<M.nu;i++)
		T.rpos[i]=0;
	for(tu=0,i=0;i<M.nu;i++)
	{
		for(j=0;j<M.mu;j++)
		{
			p=*(rpos+j);
			if(M.data[p].j==i)
			{
				T.data[tu].i=i,T.data[tu].j=M.data[p].i,T.data[tu++].e=M.data[p].e;
				T.rpos[i]++;
				*(rpos+j)++;
			}
		}
	}
	T.rpos[mu-1]=T.tu-T.rpos[T.mu-1];
	for(i=T.mu-2;i>=0;i--)
		T.rpos[i]=T.rpos[i+1]-T.rpos[i];
	free(rpos);

	*/


	//算法三
	int *colums;

	colums=(int*)malloc(M.nu*sizeof(int));

	T.mu=M.nu,T.nu=M.mu,T.tu=M.tu;
	for(i=0;i<M.nu;i++)
		*(colums+i)=0;
	for(i=0;i<M.tu;i++)
		(*(colums+M.data[i].j))++;
	T.rpos[T.mu-1]=*(colums+M.nu-1)=M.tu-*(colums+M.nu-1);
	for(i=M.nu-2;i>=0;i--)
	{
		*(colums+i)=*(colums+i+1)-*(colums+i);
		T.rpos[i]=*(colums+i);
	}

	for(i=0;i<M.tu;i++)
	{
		j=*(colums+M.data[i].j);
		T.data[j].i=M.data[i].j;
		T.data[j].j=M.data[i].i;
		T.data[j].e=M.data[i].e;
		(*(colums+M.data[i].j))++;
	}
	free(colums);

	return OK;
}
