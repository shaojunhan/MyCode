#include"C_SString_Test.h"
#include<stdio.h>

void test()
{
	char ch[2][255];
	int i=0,pos=1;
	SString S[2],T;

	for(i=0;i<2;i++)
	{
		printf("�����ַ���%d:",i+1);
		scanf("%s",ch[i]);
		StrAssign(S[i],ch[i]);
	}

	for(i=0;i<2;i++)
	{
		printf("����ַ���%d:",i+1);
		StrPrint(S[i]);
		printf("�ַ��Ƿ�Ϊ��%d(1-�� 0-��),�ַ�������:%d\n",!StrEmpty(S[i]),StrLength(S[i]));
	}

	printf("---���Ӵ�--\n");
	Concat(T,S[0],S[1]);
	printf("���Ӻ�:");
	StrPrint(T);
	
	printf("---���Ӵ�---\n");
	printf("�����ִ�:");
	scanf("%s",ch[0]);
	printf("�������λ��:");
	scanf("%d",&pos);
	StrAssign(S[0],ch[0]);
	i=Index(T,S[0],pos);
	printf("���ҵ���λ��:%d\n",i);

	printf("---���---\n");
	printf("����������Ӵ�:");
	scanf("%s",ch[1]);
	printf("�滻%s��:",ch[0]);
	StrAssign(S[1],ch[1]);
	Replace(T,S[0],S[1]);
	StrPrint(T);

	printf("�Ƚ��ַ���:S%d%cS%d\n",1,StrCompare(S[0],S[1])>0?'>':StrCompare(S[0],S[1])<0?'<':'=',2);
	StrCopy(S[0],S[1]);
	printf("---���ƺ�---\n");
	for(i=0;i<2;i++)
	{
		printf("����ַ���%d:",i+1);
		StrPrint(S[i]);
		printf("�ַ��Ƿ�Ϊ��%d(1-�� 0-��),�ַ�������:%d\n",!StrEmpty(S[i]),StrLength(S[i]));
	}
	printf("�Ƚ��ַ���:S%d%cS%d\n",1,StrCompare(S[0],S[1])>0?'>':StrCompare(S[0],S[1])<0?'<':'=',2);
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
