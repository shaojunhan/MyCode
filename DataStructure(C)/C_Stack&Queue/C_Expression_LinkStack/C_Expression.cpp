#include"C_Expression_Basic.h"
#include<stdlib.h>
#include<stdio.h>

extern char expression[128];

int main(int argc,char *argv[])
{
	printf("��������ʽ(9���±��ʽ���):");
	scanf("%s",expression);

	printf("���:%c",EvaluateExpression());
	system("pause");
	return 0;
}