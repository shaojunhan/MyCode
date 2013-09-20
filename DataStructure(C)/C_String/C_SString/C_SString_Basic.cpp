#include"C_SString_Basic.h"
#include<stdlib.h>
#include<math.h>
#include<string.h>

Status StrAssign(SString &T,char *chars)
{
	int len=strlen(chars);
	int i=0;

	len=len>MAXSTRLEN?MAXSTRLEN:len;
	T[0]=len;
	for(i=1;i<=len;i++)
	{
		T[i]=chars[i-1];
	}

	return OK;
}

Status StrCopy(SString &T,SString &S)
{
	int i=0;
	for(i=0;i<=S[0];i++)
	{
		T[i]=S[i];
	}

	return OK;
}

Status StrEmpty(SString T)
{
	return T[0]==0?TRUE:FALSE;
}

int StrCompare(SString S,SString T)
{
	int i=1;
	
	while(i<=S[0] && i<=T[0])
	{
		if(S[i]!=T[i])
			return S[i]-T[i];
		i++;
	}

	return S[0]-T[0];
}

int StrLength(SString S)
{
	return S[0];
}

Status ClearString(SString &S)
{
	S[0]=0;
	return OK;
}

Status Concat(SString &T,SString S1,SString S2)
{
	int len=0;
	int i=0;

	len=S1[0]+S2[0];
	if(len>MAXSTRLEN)
		len=MAXSTRLEN;

	for(i=1;i<=S1[0];i++)
		T[i]=S1[i];
	for(i;i<=len;i++)
		T[i]=S2[i-S1[0]];
	T[0]=len;
	return OK;
}

Status SubString(SString &Sub,SString S,int pos,int len)
{
	int i=0;
	if(pos<0 || pos>S[0] || len<0 || len>S[0]-pos+1)
		return ERROR;
	
	for(i=1;i<=len;i++)
	{
		Sub[i]=S[pos+i-1];
	}
	Sub[0]=len;
	return OK;
}

int Index(SString S,SString T,int pos)
{
	int i=pos,j=1;
	if(pos<0 || pos>S[0])
		return ERROR;

	while(i<=S[0] && j<=T[0])
	{
		if(S[i]==T[j])
			i++,j++;
		else
			i=i-j+2,j=1;
	}

	if(j>T[0])
		return i-(int)T[0];
	else
		return 0;
}

Status Replace(SString &S,SString T,SString V)
{
	int i=1;
	
	if(!T[0])
		return ERROR;

	while(i<S[0])
	{
		i=Index(S,T,i);
		if(i)
		{
			StrDelete(S,i,T[0]);
			StrInsert(S,i,V);
			i+=V[0];
		}
		else
			break;
	}

	return OK;
}

Status StrInsert(SString &S,int pos,SString T)
{
	int i=0;
	int len=0;
	if(pos<0 || pos>S[0])
		return ERROR;

	if(T[0]+pos>MAXSTRLEN)
	{
		for(i=1;i<=MAXSTRLEN-pos+1;i++)
			S[i+pos-1]=T[i];
		S[0]=(char)MAXSTRLEN;
	}
	else
	{
		if((len=S[0]+T[0])>MAXSTRLEN)
			len=MAXSTRLEN;

		for(i=len-T[0];i>=pos;i--)
			S[i+T[0]]=S[i];
		for(i=1;i<=T[0];i++)
			S[i+pos-1]=T[i];
		S[0]=len;
	}

	return OK;
}

Status StrDelete(SString &S,int pos,int len)
{
	int i=0;
	if(pos<0 || pos>S[0] || len<0 || len>S[0]-pos+1)
		return ERROR;

	for(i=pos;i<=S[0]-len;i++)
		S[i]=S[i+len];

	S[0]=S[0]-len;
	return OK;
}
Status DestroyString(SString &S)
{
	S[0]=0;
	return OK;
}