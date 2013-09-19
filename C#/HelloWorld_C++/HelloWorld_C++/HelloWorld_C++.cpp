// HelloWorld_C++.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	printf("HelloWorld!\n");

	int i=0;
	for(i=0;i<1000;i++)
	{
		int j=0;
		for(j=0;j<i%10;j++)
			printf("%c",'*');
		printf("\n");
	}

	system("pause");

	//TODO:helloworld
	return 0;
}

