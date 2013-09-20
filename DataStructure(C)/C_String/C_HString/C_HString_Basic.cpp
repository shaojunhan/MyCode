#include"C_HString_Basic.h"
#include<stdlib.h>
#include<math.h>
#include<string.h>

Status InitString(HString &S)
{
	S.ch=NULL;
	S.length=0;
	return OK;
}

Status StrAssign(HString &T,char *chars)
{
	int i=0,len=0;

	if(T.ch)
		free(T.ch);
	len=strlen(chars);

	if(!(T.ch=(char*)malloc(len*sizeof(char))))
	{
		T.ch=NULL,T.length=0;
		return ERROR;
	}
	else
		for(i=0;i<len;i++)
			*(T.ch+i)=chars[i];
	
	T.length=len;
	return OK;
}

Status DestroyString(HString &S)
{

	return OK;
}

Status ClearString(HString &S)
{
	if(S.ch)
		free(S.ch);
	
	S.ch=NULL;
	S.length=0;
	return OK;
}

Status StrEmpty(HString S)
{
	return S.length==0?TRUE:FALSE;
}

int StrLength(HString S)
{
	return S.length;
}

Status StrCompare(HString S,HString T)
{
	int i=0;
	while(i<S.length && i<T.length)
	{
		if(*(S.ch+i)!=*(T.ch+i))
			return *(S.ch+i)-*(T.ch+i);
		i++;
	}

	return S.length-T.length;
}

Status Concat(HString &T,HString S1,HString S2)
{
	int i=0,len=0;

	if(T.ch)
		free(T.ch);

	len=S1.length+S2.length;
	if(!(T.ch=(char*)malloc(len*sizeof(char))))
	{
		T.ch=NULL,T.length=0;
		return ERROR;
	}

	for(i=0;i<S1.length;i++)
		*(T.ch+i)=*(S1.ch+i);
	for(i=0;i<S2.length;i++)
		*(T.ch+S1.length+i)=*(S2.ch+i);

	T.length=len;
	return OK;
}

Status SubString(HString &Sub,HString S,int pos,int len)
{
	int i=0;
	
	if(pos<0 || len<0 || len>S.length-pos+1)
		return ERROR;

	if(Sub.ch)
		free(Sub.ch);
	if(!(Sub.ch=(char*)malloc(len*sizeof(char))))
		return ERROR;

	for(i=0;i<len;i++)
		*(Sub.ch+i)=*(S.ch+i+pos-1);
	Sub.length=len;
	return OK;
}

Status StrCopy(HString &T,HString S)
{
	int i=0;
	
	if(!T.ch)
		free(T.ch); 
	if(!(T.ch=(char*)malloc(S.length*sizeof(char))))
	{
		T.ch=NULL,T.length=0;
		return ERROR;
	}

	for(i=0;i<S.length;i++)
		*(T.ch+i)=*(S.ch+i);
	T.length=S.length;
	return OK;
}

int Index(HString S,HString T,int pos)
{
	int i=pos,j=1;

	if(pos<0 || T.length<=0 || T.length>S.length-pos+1)
		return 0;

	/*
	i=0,j=0;
	while(i<S.length && j<T.length)
	{
		if(*(S.ch+i)==*(T.ch+j))
			i++,j++;
		else
			i-=j-2,j=0;
	}

	if(j>T.length)
		return i-T.length+1;
	else
		return 0;
	*/

	int *next=(int*)malloc((T.length+1)*sizeof(int));
	if(!next)
		return 0;

	for(i=0;i<2;i++)
		*(next+i)=0;
	i=1,j=0;
	while(i<T.length)
	{
		if(j==0 || *(T.ch+i-1)==*(T.ch+j-1))
		{
			i++,j++;
			if(*(T.ch+i-1)==*(T.ch+j-1))
				*(next+i)=*(next+j);
			else
				*(next+i)=j;
		}
		else
			j=*(next+j);
	}


	i=pos,j=1;
	while(i<=S.length && j<=T.length)
	{
		if(j==0 || *(S.ch+i-1)==*(T.ch+j-1))
			i++,j++;
		else
			j=*(next+j);
	}

	free(next);

	if(j>T.length)
		return i-T.length;
	else
		return 0;
 }

Status Replace(HString &S,HString T,HString V)
{
	int i=1;

	while(i)
	{
		i=Index(S,T,i);
		if(i)
		{
			StrDelete(S,i,T.length);
			StrInsert(S,i,V);
			i+=V.length;
		}
	}

	return OK;
}

Status StrInsert(HString &S,int pos,HString T)
{
	int i=0;
	
	if(pos<0 || pos>S.length)
		return ERROR;

	if(!(S.ch=(char*)realloc(S.ch,(S.length+T.length)*sizeof(char))))
	{
		S.ch=NULL,S.length=0;
		return FALSE;
	}

	for(i=S.length-1;i>=pos-1;i--)
	{
		*(S.ch+i+T.length)=*(S.ch+i);
	}
	for(i=0;i<T.length;i++)
		*(S.ch+pos+i-1)=*(T.ch+i);

	S.length+=T.length;
	return OK;
}

Status StrDelete(HString &S,int pos,int len)
{
	int i=0;

	if(pos<0 || len<0 || len>S.length-pos+1)
		return ERROR;

	for(i=pos-1;i<S.length;i++)
		*(S.ch+i)=*(S.ch+i+len);

	S.length-=len;
	return OK;
}