#include"C_Bracket_Basic.h"
#include<stdio.h>
#include<stdlib.h>

extern char expression[];

int main(int argc,char *argv[])
{
	printf("������һ���ִ�,���������Ƿ�ƥ��:");
	scanf("%s",expression);

	printf("ƥ����(1-ƥ��ɹ� 0-ƥ��ʧ��):%d",BracketsMatch());
	system("pause");
	return 0;
}