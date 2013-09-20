// C_AlgorithmTime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"C_AlgorithmTime_Header.h"
#include<stdlib.h>

int main(int argc, char* argv[])
{/*可以用x=1.23456789 n=30000进行测试,fun1大概100秒,fun2是瞬间完成*/
	printf("fun1 be called:\n");
	fun1();
	printf("\n");
	printf("fun2 be called:\n");
	fun2();
	
	system("pause");
	return 0;
}

