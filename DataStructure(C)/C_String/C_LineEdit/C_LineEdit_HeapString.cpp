#include"C_LineEdit_HeapString.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//
Status StrAssign(HString &T,char *ch)
{
	int i;
	int len;
	if(!ch)
		return ERROR;

	if(T.ch)//
		free(T.ch);

	len=(int)strlen(ch);
	T.ch=(char*)malloc(len*sizeof(char));//
	if(!T.ch)
		exit(OVERFLOW);

	for(i=0;i<(int)strlen(ch);i++)//
		*(T.ch+i)=*(ch+i);
	T.len=len;
	return OK;
}

//
Status StrCopy(HString &T,HString S)
{
	int i;

	if(T.ch)
		free(T.ch);
	
	T.ch=(char*)malloc(S.len*(sizeof(char)));
	if(!T.ch)
		exit(OVERFLOW);

	i=S.len;
	while(i--)
		*(T.ch+i)=*(S.ch+i);
	T.len=S.len;
	return OK;
}

//
Status StrEmpty(HString S)
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
		if(*(S.ch+i)!=*(T.ch+i))//
			return *(S.ch+i)-*(T.ch+i);
		else
			i++;
	}

	return S.len-T.len;//
}

//
Status StrLength(HString S)
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

	if(T.ch)//
		free(T.ch);

	T.ch=(char*)malloc((S1.len+S2.len)*sizeof(char));//
	if(!T.ch)
		return ERROR;

	i=0;
	while(i<S1.len)//
		*(T.ch+i)=*(S1.ch+i);
	for(i=0;i<S2.len;i++)//
		*(T.ch+i+S1.len)=*(S2.ch+i);
	T.len=S1.len+S2.len;
	return OK;
}

//
Status SubString(HString &Sub,HString S,int pos,int len)
{
	int i;

	if(pos<1 || len<0 || len>S.len-pos+1)
		return ERROR;

	if(Sub.ch)//
		free(Sub.ch);

	Sub.ch=(char*)malloc(len*sizeof(char));//
	if(!Sub.ch)
		exit(OVERFLOW);

	i=0;
	while(i<len)//
		*(Sub.ch+i)=*(S.ch+pos+i-1);
	Sub.len=len;
	return OK;
}

//
int Index(HString S,HString T,int pos)
{
	int i,j;
	int *nextval;

	if(pos<1 || pos>S.len)
		return 0;

	nextval=(int*)malloc((T.len+1)*sizeof(int));
	nextval[1]=0;//
	i=1,j=0;
	while(i<=T.len)//
	{
		if(j==0 || *(T.ch+i-1)==*(T.ch+j-1))
		{
			i++,j++;
			if(*(T.ch+i-1)==*(T.ch+j-1))
				nextval[i]=nextval[j];
			else
				nextval[i]=j;
		}
		else
			j=nextval[j];
	}

	i=pos,j=1;
	while(i<=S.len && j<=T.len)//
	{
		if(j==0 || *(S.ch+i-1)==*(T.ch+j-1))
			i++,j++;
		else
			j=nextval[j];
	}

	if(j>T.len)//
		return i-T.len;
	else
		return 0;
}

//
Status Replace(HString &S,HString T,HString V)
{
	int i=1;

	while(i)
	{
		i=Index(S,T,i);//
		if(i)
		{
			StrDelete(S,i,T.len);//
			StrInsert(S,i,V);
			i+=V.len;//
		}
	}

	return OK;
}

//
Status StrInsert(HString &S,int pos,HString T)
{
	int i;

	if(pos<1 || pos>S.len+1)//
		return ERROR;

	S.ch=(char*)realloc(S.ch,(S.len+T.len)*sizeof(char));//
	if(!S.ch)
		exit(OVERFLOW);

	for(i=S.len-1;i>=pos-1;i--)//
		*(S.ch+i+T.len)=*(S.ch+i);
	for(i=0;i<T.len;i++)//
		*(S.ch+i+pos-1)=*(T.ch+i);

	S.len+=T.len;
	
	return OK;
}

//
Status StrDelete(HString &S,int pos,int len)
{
	int i;

	if(pos<1 || len<0 || len>S.len-pos+1)
		return ERROR;

	for(i=pos-1;i<S.len-len;i++)//
		*(S.ch+i)=*(S.ch+i+len);

	S.ch=(char*)realloc(S.ch,(S.len-len)*sizeof(char));//
	if(!S.ch)
		return ERROR;
	S.len-=len;
	return OK;
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

//
Status StrPrint(HString S)
{
	int i;
	for(i=0;i<S.len;i++)
	{
		printf("%c",*(S.ch+i));
	}
	printf("\n");
	return OK;
}