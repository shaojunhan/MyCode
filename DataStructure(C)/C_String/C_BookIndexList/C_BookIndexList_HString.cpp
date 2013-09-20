#include"C_BookIndexList_HString.h"

//
Status StrAssign(HString &T,char *chars)
{
	int i;
	int len;

	if(T.ch)
		free(T.ch);
	T.ch=NULL,T.len=0;

	len=strlen(chars);
	if(len)
	{
		T.ch=(char*)malloc(len*sizeof(char));//
		if(!T.ch)
			exit(OVERFLOW);

		for(i=0;i<len;i++)//
			*(T.ch+i)=*(chars+i);
		T.len=len;
		return OK;
	}
	else
		return ERROR;
}

//
Status StrCopy(HString &T,HString S)
{
	int i;

	if(T.ch)
		free(T.ch);
	T.ch=NULL,T.len=0;

	if(S.len)
	{
		T.ch=(char*)malloc(S.len*sizeof(char));
		if(!T.ch)
			exit(OVERFLOW);

		for(i=0;i<S.len;i++)
			*(T.ch+i)=*(S.ch+i);
		T.len=S.len;
		return OK;
	}
	else
		return ERROR;
}

//
bool StrEmpty(HString S)
{
	return S.len==0;
}

//
int StrCompare(HString S,HString T)
{
	int i;

	i=0;
	while(i<S.len && i<T.len)
	{
		if(*(S.ch+i)!=*(T.ch+i))
			return *(S.ch+i)-*(T.ch+i);
		i++;
	}

	return S.len-T.len;
}

//
int StrLength(HString S)
{
	return S.len;
}

//
Status ClearString(HString &S)
{
	if(S.ch)
		free(S.ch);
	S.ch=NULL,S.len=0;
	return OK;
}

//
Status Concat(HString &T,HString S1,HString S2)
{
	int i;

	if(T.ch)
		free(T.ch);
	T.ch=NULL,T.len=0;

	if(S1.len+S2.len)
	{
		T.ch=(char*)malloc((S1.len+S2.len)*sizeof(char));
		if(!T.ch)
			exit(OVERFLOW);

		for(i=0;i<S1.len;i++)
			*(T.ch+i)=*(S1.ch+i);
		for(i=0;i<S2.len;i++)
			*(T.ch+i+S1.len)=*(S2.ch+i);

		T.len=S1.len+S2.len;
		return OK;
	}
	else
		return ERROR;
}

//
Status SubString(HString &Sub,HString S,int pos,int len)
{
	int i;
	
	if(pos<1 || len<0 || len>S.len-len+1)
		return ERROR;
	
	if(Sub.ch)
		free(Sub.ch);
	Sub.ch=NULL,Sub.len=0;

	Sub.ch=(char*)malloc(len*sizeof(char));
	if(!Sub.ch)
		exit(OVERFLOW);

	for(i=0;i<len;i++)
		*(Sub.ch+i)=*(S.ch+pos-1+i);
	Sub.len=len;
	return OK;
}

//
Status Index(HString S,HString T,int pos)
{
	int i,j;
	int *nextval;
	
	nextval=(int*)malloc((T.len+1)*sizeof(int));
	if(!nextval)
		return ERROR;

	i=0,j=-1;
	nextval[0]=-1;
	while(i<T.len)
	{
		if(j==-1 || *(T.ch+i)==*(T.ch+j))
		{
			i++,j++;
			if(*(T.ch+i)==*(T.ch+j))
				nextval[i]=nextval[j];
			else
				nextval[i]=i;
		}
		else
			j=nextval[j];
	}

	i=pos-1,j=0;
	while(i<S.len && j<T.len)
	{
		if(j==-1 || *(S.ch+i)==*(T.ch+j))
			i++,j++;
		else
			j=nextval[j];
	}

	if(j>=T.len)
		return i-T.len+1;
	else
		return 0;
}

//
Status Replace(HString &S,HString T,HString V)
{
	int i=1;

	while(i)
	{
		i=Index(S,T,i);
		if(i)
		{
			StrDelete(S,i,T.len);
			StrInsert(S,i,V);
			i+=V.len;
		}
	}

	return OK;
}

Status StrInsert(HString &S,int pos,HString T)
{
	int i;

	if(pos<1 || pos>S.len+1)
		return ERROR;

	if(T.len)
	{
		S.ch=(char*)realloc(S.ch,(S.len+T.len)*sizeof(char));
		if(!S.ch)
			exit(OVERFLOW);

		for(i=S.len-1;i>=pos-1;i--)
			*(S.ch+i+T.len)=*(S.ch+i);
		for(i=0;i<T.len;i++)
			*(S.ch+pos-1+i)=*(T.ch+i);
		S.len+=T.len;
		return OK;
	}
	else
		return ERROR;
}

//
Status StrDelete(HString &S,int pos,int len)
{
	int i;

	if(pos<1 || len<0 || len>S.len-pos+1)
		return ERROR;

	for(i=pos-1+len;i<S.len;i++)
		*(S.ch+i-len)=*(S.ch+i);
	if(S.len-len)
	{
		S.ch=(char*)realloc(S.ch,(S.len-len)*sizeof(char));
		if(!S.ch)
			return ERROR;
		
		S.len-=len;
		return OK;
	}
	else
	{
		S.len-=len;
		return ERROR;
	}
}

//
Status DestroyString(HString &S)
{
	return 0;
}

//
Status InitString(HString &S)
{
	S.ch=NULL,S.len=0;
	return OK;
}