#include"C_CString_Test.h"
#include<stdio.h>


extern char blank;

void test()
{
	char ch[2][255];
	int i=0,pos=1;
	CString S[2],T;

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

	printf("ɾ��%s��:",ch[0]);
	if(i)
		StrDelete(T,i,S[0].length);
	StrPrint(T);

	printf("����%s��:",ch[0]);
	if(i)
		StrInsert(T,S[0],i);
	StrPrint(T);

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

Status StrPrint(CString S)
{
	int i,pi;
	char c=' ';
	Link p;

	p=S.head;
	pi=0,i=0;
	while(i<S.length)
	{
		if(*(p->ch+pi)!=blank)
		{
			printf("%c%c",c,*(p->ch+pi));
			if(!i)
				c='-';
			i++;
		}
		pi++;
		if(pi>=CHUNKSIZE)
			pi=0,p=p->next;
	}

	printf("\n");

	return OK;
}