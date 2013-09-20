#include"C_Bracket_Basic.h"
#include<stdio.h>
#include<stdlib.h>

extern char expression[];

int main(int argc,char *argv[])
{
	printf("请输入一组字串,检验括号是否匹配:");
	scanf("%s",expression);

	printf("匹配结果(1-匹配成功 0-匹配失败):%d",BracketsMatch());
	system("pause");
	return 0;
}