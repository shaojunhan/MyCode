#include"C_GList_HString.h"
#include<stdlib.h>
#include<math.h>
#include<string.h>

Status InitHString(HString &T)
{
	T.base=NULL;
	T.len=0;
	return OK;
}

Status StrAssign(HString &T,char *chars)
{
	int len;
	int i;

	len=strlen(chars);
	if(len==0)
	{
		if(T.base)
			free(T.base);
		T.base=NULL,T.len=0;
		return FALSE;
	}

	if(!T.base || T.len!=len)
	{
		if(T.base)
			free(T.base);
		if(!(T.base=(char*)malloc(len*sizeof(char))))
			exit(OVERFLOW);
	}

	T.len=len;
	for(i=0;i<len;i++)
		*(T.base+i)=*(chars+i);
	return OK;
}

Status StrCopy(HString &T,HString S)
{
	int i;

	if(S.len==0)
	{
		if(T.base)
			free(T.base);
		T.base=NULL,T.len=0;
		return FALSE;
	}
	else
	{
		if(!T.base || T.len!=S.len)
		{
			if(T.base)
				free(T.base);
			if(!(T.base=(char*)malloc(S.len*sizeof(char))))
			exit(OVERFLOW);
		}

		T.len=S.len;
		for(i=0;i<S.len;i++)
			*(T.base+i)=*(S.base+i);
		return OK;
	}
}

bool StrEmpty(HString S)
{
	return S.len==0;
}

Status StrCompare(HString S,HString T)
{
	int i;

	i=0;
	while(i<S.len && i<T.len)
	{
		if(*(S.base+i)!=*(T.base+i))
			return *(S.base+i)-*(T.base+i);
		i++;
	}

	return S.len-T.len;
}

int StrLength(HString S)
{
	return S.len;
}

Status ClearString(HString &S)
{
	if(S.base)
		free(S.base);
	S.base=NULL,S.len=0;
	return OK;
}

Status Concat(HString &T,HString S1,HString S2)
{
	int i;

	if((S1.len+S2.len)==0)
	{
		if(T.base)
			free(T.base);
		T.base=NULL,T.len=0;
		return FALSE;
	}
	else
	{
		if(!T.base || T.len!=(S1.len+S2.len))
		{
			if(T.base)
				free(T.base);
			if(!(T.base=(char*)malloc((S1.len+S2.len)*sizeof(char))))
				exit(OVERFLOW);
		}

		T.len=S1.len+S2.len;
		for(i=0;i<S1.len;i++)
			*(T.base+i)=*(S1.base+i);
		for(i=S1.len;i<S1.len+S2.len;i++)
			*(T.base+i)=*(S2.base+i-S1.len);
		return OK;
	}
}

Status SubString(HString &Sub,HString S,int pos,int len)
{
	int i;

	if(pos<1 || len<1 || len>S.len-pos+1)
		return ERROR;

	if(!Sub.base || Sub.len!=len)
	{
		if(Sub.base)
			free(Sub.base);
		if(!(Sub.base=(char*)malloc(len*sizeof(char))))
			exit(OVERFLOW);
	}

	Sub.len=len;
	for(i=0;i<len;i++)
		*(Sub.base+i)=*(S.base+pos+i-1);
	return OK;
}

int Index(HString S,HString T,int pos)//
{
	int i,j;
	int *nextval;

	if(pos<1 || !T.len ||T.len>S.len-pos+1)
		return ERROR;
	
	if(!(nextval=(int*)malloc((T.len+1)*sizeof(int))))
		exit(OVERFLOW);

	i=1,j=0;
	*(nextval+1)=0;
	while(i<T.len)
	{
		if(j==0 || *(T.base+i-1)==*(T.base+j-1))
		{
			i++,j++;
			if(*(T.base+i-1)==*(T.base+j-1))
				*(nextval+i)=*(nextval+j);
			else
				*(nextval+i)=j;
		}
		else
			j=*(nextval+j);
	}

	i=pos,j=1;
	while(i<S.len && j<T.len)
	{
		if(j==0 || *(S.base+i-1)==*(T.base+j-1))
			i++,j++;
		else
			j=*(nextval+j);
	}

	if(j>=T.len)
		return i-T.len+1;
	else
		return 0;
}

Status Replace(HString &S,HString T,HString V)
{
	int i;

	i=1;
	do
	{
		i=Index(S,T,i);
		if(i)
		{
			StrDelete(S,i,T.len);
			StrInsert(S,i,V);
			i+=V.len;
		}
	}while(i);

	return OK;
}

Status StrInsert(HString &S,int pos,HString T)
{
	int i;
	
	if(T.len==0 || pos<1 || pos>S.len+1)
		return FALSE;
	if(!(S.base=(char*)realloc(S.base,(S.len+T.len)*sizeof(char))))
		exit(OVERFLOW);
	for(i=S.len-1;i>=pos-1;i--)
		*(S.base+T.len+i)=*(S.base+i);
	for(i=0;i<T.len;i++)
		*(S.base+pos+i-1)=*(T.base+i);
	S.len+=T.len;
	return OK;
}

Status StrDelete(HString &S,int pos,int len)
{
	int i;

	if(pos<1 || len<1 || len>S.len-pos+1)
		return FALSE;
	for(i=pos-1;i<S.len-len;i++)
		*(S.base+i)=*(S.base+i+len);
	S.len-=len;
	if(!(S.base=(char*)realloc(S.base,S.len*sizeof(char))))
		exit(OVERFLOW);
	return OK;
}

Status DestroyString(HString &S)
{
	if(S.base)
		free(S.base);
	S.base=NULL,S.len=0;
	return OK;
}
