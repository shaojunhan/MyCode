#include"C_CrossList_Basic.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

//访问
void Visit(ElemType e)
{
	printf("%5d",e);
}

Status InitSMatrix(CLSMatrix &M)//初始化
{
	M.rhead=M.chead=NULL;
	M.mu=M.nu=M.tu=0;
	return OK;
}

Status CreateSMatrix(CLSMatrix &M,int mu,int nu,ElemType *data[])//创建
{
	int i,j,tu;
	OLink pr,pc;
	OLink p;
	
	if(mu<1 || nu<1)
		return ERROR;
	
	//建立初始条件
	M.mu=mu,M.nu=nu;
	M.rhead=(OLink*)malloc(M.mu*sizeof(OLink));
	M.chead=(OLink*)malloc(M.nu*sizeof(OLink));
	if(!M.rhead || !M.chead)
		exit(OVERFLOW);
	for(i=0;i<M.mu;i++)
		*(M.rhead+i)=NULL;
	for(i=0;i<M.nu;i++)
		*(M.chead+i)=NULL;
	
	tu=0;
	for(i=0;i<mu;i++)
	{
		for(j=0;j<nu;j++)
		{
			if(*(data[i]+j)!=ZERO)
			{
				if(!(p=(OLink)malloc(sizeof(struct OLNode))))
					exit(OVERFLOW);
				p->i=i,p->j=j,p->e=*(data[i]+j);
				if(!*(M.rhead+i) || (*(M.rhead+i))->j>p->j)//
				{
					p->right=*(M.rhead+i);
					*(M.rhead+i)=p;
				}
				else
				{
					pr=*(M.rhead+i);
					while(pr->right && pr->right->j<p->j)
						pr=pr->right;
					p->right=pr->right;
					pr->right=p;
				}
				
				if(!*(M.chead+j) || (*(M.chead+j))->i>p->i)//
				{
					p->down=*(M.chead+j);
					*(M.chead+j)=p;
				}
				else
				{
					pc=*(M.chead+j);
					while(pc->down && pc->down->i<p->i)
						pc=pc->down;
					p->down=pc->down;
					pc->down=p;
				}
				tu++;
			}
		}
	}
	M.tu=tu;
	return OK;
}

Status DestroySMatrix(CLSMatrix &M)//销毁
{
	int i;
	OLink pr,qr;
	
	for(i=0;i<M.mu;i++)//
	{
		pr=*(M.rhead+i);
		while(pr)
		{
			qr=pr->right;
			free(pr);
			pr=qr;
		}
	}
	if(M.chead)//
		free(M.chead);
	if(M.rhead)
		free(M.rhead);
	M.chead=M.rhead=NULL;//
	M.mu=M.nu=M.tu=0;
	return OK;
}

Status PrintSMatrix(CLSMatrix M)//输出
{
	int i,j;
	bool flag;
	OLink pr;
	
	for(i=0;i<M.mu;i++)
	{
		for(j=0;j<M.nu;j++)
		{
			flag=0;
			pr=*(M.rhead+i);
			while(pr)
			{
				if(pr->j==j)
				{
					Visit(pr->e);
					flag=1;
					break;
				}
				pr=pr->right;
			}
			
			if(!flag)
				Visit(ZERO);
		}
		putchar('\n');
	}
	
	return OK;
}

Status CopySMatrix(CLSMatrix M,CLSMatrix &T)//拷贝
{
	int i,j;
	OLink pr,pc;
	OLink q;
	
	for(i=0;i<T.mu;i++)
	{
		pr=*(T.rhead+i);
		while(pr)
		{
			pc=pr->right;
			free(pr);
			pr=pc;
		}
	}
	if(T.chead)
		free(T.chead);
	if(T.rhead)
		free(T.rhead);
	
	T.mu=M.mu,T.nu=M.nu,T.tu=M.tu;
	T.rhead=(OLink*)malloc(T.mu*sizeof(OLink));
	T.chead=(OLink*)malloc(T.nu*sizeof(OLink));
	if(!T.rhead || !T.chead)
		exit(OVERFLOW);
	for(i=0;i<T.mu;i++)
		*(T.rhead+i)=NULL;
	for(i=0;i<T.nu;i++)
		*(T.chead+i)=NULL;
	
	for(i=0;i<M.mu;i++)
	{
		pr=*(M.rhead+i);
		while(pr)
		{
			if(!(q=(OLink)malloc(sizeof(struct OLNode))))
				exit(OVERFLOW);
			
			q->i=pr->i,q->j=pr->j,q->e=pr->e;
			if(!*(M.rhead+i) || (*(M.rhead+i))->j>q->j)
			{
				q->right=*(M.rhead+i);
				*(M.rhead+i)=q;
			}
			else
			{
				pc=*(M.rhead+i);
				while(pc->right && pc->right->j<q->j)
					pc=pc->right;
				q->right=pc->right;
				pc->right=q;
			}
			j=pr->j;
			if(!*(M.chead+j) || (*(M.chead+j))->i>q->i)
			{
				q->down=*(M.chead+j);
				*(M.chead+j)=q;
			}
			else
			{
				pc=*(M.chead+j);
				while(pc->down && pc->down->i<q->i)
					pc=pc->down;
				q->down=pc->down;
				pc->down=q;
			}
			pr=pr->right;
		}
	}
	return OK;
}

Status AddSMatrix(CLSMatrix M,CLSMatrix N,CLSMatrix &Q)//矩阵加
{
	int i,j,tu;
	OLink mpr,npr,qpr,qpc;
	OLink q;
	
	if(M.mu!=N.mu || M.nu!=N.nu)
		return ERROR;
	
	for(i=0;i<Q.mu;i++)
	{
		qpr=*(Q.rhead+i);
		while(qpr)
		{
			qpc=qpr->right;
			free(qpr);
			qpr=qpc;
		}
	}
	if(Q.chead)
		free(Q.chead);
	if(Q.rhead)
		free(Q.rhead);
	
	Q.mu=M.mu,Q.nu=M.nu;
	Q.rhead=(OLink*)malloc(Q.mu*sizeof(OLink));
	Q.chead=(OLink*)malloc(Q.nu*sizeof(OLink));
	if(!Q.rhead || !Q.chead)
		exit(OVERFLOW);
	for(i=0;i<Q.mu;i++)
		*(Q.rhead+i)=NULL;
	for(i=0;i<Q.nu;i++)
		*(Q.chead+i)=NULL;
	
	tu=0;
	for(i=0;i<M.mu;i++)
	{
		mpr=*(M.rhead+i);
		npr=*(N.rhead+i);
		
		while(mpr && npr)
		{
			if(mpr->j<npr->j)
			{
				if(!(q=(OLink)malloc(sizeof(struct OLNode))))
					exit(OVERFLOW);
				q->i=mpr->i,q->j=mpr->j,q->e=mpr->e;
				tu++;
				mpr=mpr->right;
				
				if(!*(Q.rhead+i) || (*(Q.rhead+i))->j>q->j)
				{
					q->right=*(Q.rhead+i);
					*(Q.rhead+i)=q;
				}
				else
				{
					qpr=*(Q.rhead+i);
					while(qpr->right && qpr->right->j<q->j)
						qpr=qpr->right;
					q->right=qpr->right;
					qpr->right=q;
				}
				
				if(!*(Q.chead+q->j) || (*(Q.chead+q->j))->i>q->i)
				{
					q->down=*(Q.chead+q->j);
					*(Q.chead+q->j)=q;
				}
				else
				{
					qpc=*(Q.chead+q->j);
					while(qpc->down && qpc->down->i<q->i)
						qpc=qpc->down;
					q->down=qpc->down;
					qpc->down=q;
				}
			}
			else if(mpr->j>npr->j)
			{
				if(!(q=(OLink)malloc(sizeof(struct OLNode))))
					exit(OVERFLOW);
				q->i=npr->i,q->j=npr->j,q->e=npr->e;
				tu++;
				npr=npr->right;
				
				if(!*(Q.rhead+i) || (*(Q.rhead+i))->j>q->j)
				{
					q->right=*(Q.rhead+i);
					*(Q.rhead+i)=q;
				}
				else
				{
					qpr=*(Q.rhead+i);
					while(qpr->right && qpr->right->j<q->j)
						qpr=qpr->right;
					q->right=qpr->right;
					qpr->right=q;
				}
				
				if(!*(Q.chead+q->j) || (*(Q.chead+q->j))->i>q->i)
				{
					q->down=*(Q.chead+q->j);
					*(Q.chead+q->j)=q;
				}
				else
				{
					qpc=*(Q.chead+q->j);
					while(qpc->down && qpc->down->i<q->i)
						qpc=qpc->down;
					q->down=qpc->down;
					qpc->down=q;
				}	
			}
			else if((mpr->e+npr->e)!=ZERO)
			{
				if(!(q=(OLink)malloc(sizeof(struct OLNode))))
					exit(OVERFLOW);
				q->i=mpr->i,q->j=mpr->j,q->e=mpr->e+npr->e;
				tu++;
				mpr=mpr->right,npr=npr->right;
				
				if(!*(Q.rhead+i) || (*(Q.rhead+i))->j>q->j)
				{
					q->right=*(Q.rhead+i);
					*(Q.rhead+i)=q;
				}
				else
				{
					qpr=*(Q.rhead+i);
					while(qpr->right && qpr->right->j<q->j)
						qpr=qpr->right;
					q->right=qpr->right;
					qpr->right=q;
				}
				
				if(!*(Q.chead+q->j) || (*(Q.chead+q->j))->i>q->i)
				{
					q->down=*(Q.chead+q->j);
					*(Q.chead+q->j)=q;
				}
				else
				{
					qpc=*(Q.chead+q->j);
					while(qpc->down && qpc->down->i<q->i)
						qpc=qpc->down;
					q->down=qpc->down;
					qpc->down=q;
				}
			}
			else
				mpr=mpr->right,npr=npr->right;
		}//while
		
		while(mpr)
		{
			if(!(q=(OLink)malloc(sizeof(struct OLNode))))
				exit(OVERFLOW);
			q->i=mpr->i,q->j=mpr->j,q->e=mpr->e;
			tu++;
			mpr=mpr->right;
			
			if(!*(Q.rhead+i) || (*(Q.rhead+i))->j>q->j)
			{
				q->right=*(Q.rhead+i);
				*(Q.rhead+i)=q;
			}
			else
			{
				qpr=*(Q.rhead+i);
				while(qpr->right && qpr->right->j<q->j)
					qpr=qpr->right;
				q->right=qpr->right;
				qpr->right=q;
			}
			
			if(!*(Q.chead+q->j) || (*(Q.chead+q->j))->i>q->i)
			{
				q->down=*(Q.chead+q->j);
				*(Q.chead+q->j)=q;
			}
			else
			{
				qpc=*(Q.chead+q->j);
				while(qpc->down && qpc->down->i<q->i)
					qpc=qpc->down;
				q->down=qpc->down;
				qpc->down=q;
			}
		}//while
		
		while(npr)
		{
			if(!(q=(OLink)malloc(sizeof(struct OLNode))))
				exit(OVERFLOW);
			q->i=npr->i,q->j=npr->j,q->e=npr->e;
			tu++;
			npr=npr->right;
			
			if(!*(Q.rhead+i) || (*(Q.rhead+i))->j>q->j)
			{
				q->right=*(Q.rhead+i);
				*(Q.rhead+i)=q;
			}
			else
			{
				qpr=*(Q.rhead+i);
				while(qpr->right && qpr->right->j<q->j)
					qpr=qpr->right;
				q->right=qpr->right;
				qpr->right=q;
			}
			
			if(!*(Q.chead+q->j) || (*(Q.chead+q->j))->i>q->i)
			{
				q->down=*(Q.chead+q->j);
				*(Q.chead+q->j)=q;
			}
			else
			{
				qpc=*(Q.chead+q->j);
				while(qpc->down && qpc->down->i<q->i)
					qpc=qpc->down;
				q->down=qpc->down;
				qpc->down=q;
			}
		}//while
	}//for
	Q.tu=tu;
	return OK;
}

Status SubSMatrix(CLSMatrix M,CLSMatrix N,CLSMatrix &Q)//矩阵减
{
	int i;
	OLink pr;

	for(i=0;i<N.mu;i++)
	{
		pr=*(N.rhead+i);
		while(pr)
			pr->e*=-1,pr=pr->right;
	}

	AddSMatrix(M,N,Q);
	return OK;
}

Status MultSMatrix(CLSMatrix M,CLSMatrix N,CLSMatrix &Q)//矩阵乘
{
	int i,j,tu;
	OLink pr,pc,q;
	ElemType e;

	if(M.nu!=N.mu || M.mu*N.nu==0)
		return ERROR;

	for(i=0;i<Q.mu;i++)
	{
		pr=*(Q.rhead+i);
		while(pr)
		{
			pc=pr->right;
			free(pr);
			pr=pc;
		}
	}
	if(Q.rhead)
		free(Q.rhead);
	if(Q.chead)
		free(Q.chead);

	Q.mu=M.mu,Q.nu=N.nu;
	Q.rhead=(OLink*)malloc(Q.mu*sizeof(OLink));
	Q.chead=(OLink*)malloc(Q.nu*sizeof(OLink));
	if(!Q.chead || !Q.rhead)
		exit(OVERFLOW);
	for(i=0;i<Q.mu;i++)
		*(Q.rhead+i)=NULL;
	for(i=0;i<Q.nu;i++)
		*(Q.chead+i)=NULL;

	tu=0;
	for(i=0;i<M.mu;i++)
	{
		for(j=0;j<N.nu;j++)
		{
			pr=*(M.rhead+i);
			pc=*(N.chead+j);
			
			e=ZERO;
			while(pr && pc)
			{
				if(pr->j==pc->i)
				{
					e+=pr->e*pc->e;
					pr=pr->right;
					pc=pc->down;
				}
				else if(pr->j>pc->i)
					pc=pc->down;
				else pr=pr->right;
			}

			if(e!=ZERO)
			{
				if(!(q=(OLink)malloc(sizeof(struct OLNode))))
					exit(OVERFLOW);
				tu++;
				q->i=i,q->j=j,q->e=e;

				if(!*(Q.rhead+i) || (*(Q.rhead+i))->j>q->j)
				{
					q->right=*(Q.rhead+i);
					*(Q.rhead+i)=q;
				}
				else
				{
					pr=*(Q.rhead+i);
					while(pr->right && pr->right->j<q->j)
						pr=pr->right;
					q->right=pr->right;
					pr->right=q;
				}

				if(!*(Q.chead+j) || (*(Q.chead+j))->i>q->i)
				{
					q->down=*(Q.chead+j);
					*(Q.chead+j)=q;
				}
				else
				{
					pc=*(Q.chead+j);
					while(pc->down && pc->down->i<q->i)
						pc=pc->down;
					q->down=pc->down;
					pc->down=q;
				}
			}
		}
	}
	Q.tu=tu;
	return OK;
}

Status TransposeSMatrix(CLSMatrix M,CLSMatrix &T)//矩阵转置
{
	int i,j;
	OLink pr,pc,q;

	for(i=0;i<T.mu;i++)
	{
		pr=*(T.rhead+i);
		while(pr)
		{
			pc=pr->right;
			free(pr);
			pr=pc;
		}
	}
	if(T.rhead)
		free(T.rhead);
	if(T.chead)
		free(T.chead);
	T.mu=M.nu,T.nu=M.mu,T.tu=M.tu;
	T.rhead=(OLink*)malloc(T.mu*sizeof(OLink));
	T.chead=(OLink*)malloc(T.nu*sizeof(OLink));
	if(!T.rhead || !T.chead)
		exit(OVERFLOW);
	for(i=0;i<T.mu;i++)
		*(T.rhead+i)=NULL;
	for(i=0;i<T.nu;i++)
		*(T.chead+i)=NULL;

	for(i=0;i<T.mu;i++)
	{
		pc=*(M.chead+i);
		while(pc)
		{
			if(!(q=(OLink)malloc(sizeof(struct OLNode))))
				exit(OVERFLOW);
			q->i=pc->i,q->j=pc->i,q->e=pc->e;
			pc=pc->down;

			if(!*(T.rhead+i) || (*(T.rhead+i))->j>q->j)
			{
				q->right=*(T.rhead+i);
				*(T.rhead+i)=q;
			}
			else
			{
				pr=*(T.rhead+i);
				while(pr->right && pr->right->j<q->j)
					pr=pr->right;
				q->right=pr->right;
				pr->right=q;
			}

			if(!*(T.chead+q->j) || (*(T.chead+q->j))->i>q->i)
			{
				q->down=*(T.chead+q->j);
				*(T.chead+q->j)=q;
			}
			else
			{
				pr=*(T.chead+q->j);
				while(pr->down && pr->down->i<q->i)
					pr=pr->down;
				q->down=pr->down;
				pr->down=q;
			}
		}
	}

	return OK;
}

