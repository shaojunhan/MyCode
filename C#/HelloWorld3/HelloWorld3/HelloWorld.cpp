#include<stdio.h>
#include<stdlib.h>

int n=9;

int fun();

int main()
{
	printf("HelloWorld!\n");
	fun();
	system("pause");
	return 0;
}

int fun()

{
	if(n--<0)
		return 0;
	else
		main();
}