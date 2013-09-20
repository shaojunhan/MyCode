#include"C_Expression_Basic.h"
#include<stdlib.h>
#include<stdio.h>

extern char expression[128];

int main(int argc,char *argv[])
{
	printf("请输入表达式(9以下表达式求解):");
	scanf("%s",expression);

	printf("结果:%c",EvaluateExpression());
	system("pause");
	return 0;
}