#include"C_Array_Basic.h"
#include<stdlib.h>
#include<stdarg.h>
#include<math.h>

Status InitArray(Array &A,int dim,...)//初始
{
	int i;
	int elemtotal;

	A.base=NULL,A.bounds=NULL,A.contants=NULL,A.dim=0;//初始置零
	if(dim<=0)
		return ERROR;
	else
	{
		A.dim=dim;
		A.bounds=(int*)malloc(dim*sizeof(int));
		if(!A.bounds)
			exit(OVERFLOW);
		va_list var;
		va_start(var,dim);
		for(elemtotal=1,i=0;i<dim;i++)
			if((*(A.bounds+i)=va_arg(var,int))<=0)
				return ERROR;
			else
				elemtotal*=*(A.bounds+i);
		va_end(var);
		
		A.base=(ElemType*)malloc(elemtotal*sizeof(ElemType));
		if(!A.base)
			exit(OVERFLOW);

		A.contants=(int*)malloc(dim*sizeof(int));
		if(!A.contants)
			exit(OVERFLOW);
		*(A.contants+dim-1)=1;
		for(i=dim-2;i>=0;i--)
			*(A.contants+i)=*(A.contants+i+1)**(A.bounds+i+1);

		return OK;
	}
}

Status DestroyArray(Array &A)//销毁
{
	if(!A.base)
		free(A.base);
	if(!A.bounds)
		free(A.bounds);
	if(!A.contants)
		free(A.contants);
	A.base=A.bounds=A.contants=NULL,A.dim=0;//
	return OK;
}

Status Assign(Array &A,ElemType e,...)//赋值
{
	int offset,i,k;

	va_list var;
	va_start(var,e);
	for(offset=0,i=0;i<A.dim;i++)
	{
		k=va_arg(var,int);
		if(k<0 || k>=*(A.bounds+i))
			return ERROR;
		offset+=*(A.contants+i)*k;
	}
	va_end(var);
	*(A.base+offset)=e;

	return OK;
}

Status Value(ElemType &e,Array A,...)//读取
{
	int offset,i,k;

	va_list var;
	k=0,va_start(var,A);
	for(offset=0,i=0;i<A.dim;i++)
	{
		k=va_arg(var,int);
		if(k<0 || k>=*(A.bounds+i))
			return ERROR;
		offset+=*(A.contants+i)*k;
	}
	va_end(var);
	e=*(A.base+offset);
	return OK;
}