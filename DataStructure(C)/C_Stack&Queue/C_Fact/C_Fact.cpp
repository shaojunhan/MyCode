#include"C_Fact_Basic.h"
#include<stdio.h>

int main(int argc,char *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n>=0)
			printf("%d\n",Fact(n));
	}
	return 0;
}