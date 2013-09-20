#include"C_Fibonacci_Basic.h"
#include<stdio.h>

int main(int argc,char *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n>=0)
			printf("%d\n",Fib(n));
	}
}