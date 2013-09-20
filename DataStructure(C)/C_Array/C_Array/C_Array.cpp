#include"C_Array_Basic.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	Array A;
	int i,j,value;

	printf("创建数组...\n");
	InitArray(A,2,3,3);
	printf("创建完成.\n");

	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			Assign(A,i+j,i,j);

	printf("输出为:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			Value(value,A,i,j),printf("%3d",value);
		printf("\n");
	}
	DestroyArray(A);

	system("pause");
	return 0;
}