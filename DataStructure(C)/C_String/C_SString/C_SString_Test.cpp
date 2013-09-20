#include"C_SString_Test.h"
#include<stdio.h>

void test()
{
	char ch[2][255];
	int i=0,pos=1;
	SString S[2],T;

	for(i=0;i<2;i++)
	{
		printf("输入字符串%d:",i+1);
		scanf("%s",ch[i]);
		StrAssign(S[i],ch[i]);
	}

	for(i=0;i<2;i++)
	{
		printf("输出字符串%d:",i+1);
		StrPrint(S[i]);
		printf("字符是否为空%d(1-非 0-空),字符串长度:%d\n",!StrEmpty(S[i]),StrLength(S[i]));
	}

	printf("---连接串--\n");
	Concat(T,S[0],S[1]);
	printf("连接后:");
	StrPrint(T);
	
	printf("---求子串---\n");
	printf("输入字串:");
	scanf("%s",ch[0]);
	printf("输入查找位置:");
	scanf("%d",&pos);
	StrAssign(S[0],ch[0]);
	i=Index(T,S[0],pos);
	printf("查找到的位置:%d\n",i);

	printf("---替代---\n");
	printf("输入替代的子串:");
	scanf("%s",ch[1]);
	printf("替换%s后:",ch[0]);
	StrAssign(S[1],ch[1]);
	Replace(T,S[0],S[1]);
	StrPrint(T);

	printf("比较字符串:S%d%cS%d\n",1,StrCompare(S[0],S[1])>0?'>':StrCompare(S[0],S[1])<0?'<':'=',2);
	StrCopy(S[0],S[1]);
	printf("---复制后---\n");
	for(i=0;i<2;i++)
	{
		printf("输出字符串%d:",i+1);
		StrPrint(S[i]);
		printf("字符是否为空%d(1-非 0-空),字符串长度:%d\n",!StrEmpty(S[i]),StrLength(S[i]));
	}
	printf("比较字符串:S%d%cS%d\n",1,StrCompare(S[0],S[1])>0?'>':StrCompare(S[0],S[1])<0?'<':'=',2);
}

/*
Status StrAssign(SString &T,char *chars);
Status StrCopy(SString &T,SString &S);
Status StrEmpty(SString T);
int StrCompare(SString S,SString T);
int StrLength(SString S);
Status ClearString(SString &S);
Status Concat(SString &T,SString S1,SString S2);
Status SubString(SString &Sub,SString S,int pos,int len);
int Index(SString S,SString T,int pos);
Status Replace(SString &S,SString T,SString V);
Status StrInsert(SString &S,int pos,SString T);
Status StrDelete(SString &S,int pos,int len);
Status DestroyString(SString &S);
*/

Status StrPrint(SString S)
{
	int i,j=0;
	const int N=2;
	char c[2]=" ";

	for(i=1;i<=S[0];i++)
	{
		printf("%s%c",c,S[i]);
		if(!j)
		{
			c[0]='-';
			c[N-1]='\0';
			j=1;
		}
	}

	printf("\n");
	return OK;
}
