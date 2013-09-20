#include"C_HString_Test.h"
#include<stdio.h>

void test()
{
	char ch[2][255];
	int i=0,pos=1;
	HString S[2],T;

	InitString(S[0]);
	InitString(S[1]);
	InitString(T);

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

	ClearString(S[0]);
	ClearString(S[1]);
	ClearString(T);
}

Status StrPrint(HString S)
{
	int i=0;
	char c[2]=" ";

	for(i=0;i<S.length;i++)
	{
		printf("%s%c",c,*(S.ch+i));
		if(!i)
			c[0]='-',c[1]='\0';
	}

	printf("\n");

	return OK;
}