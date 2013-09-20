#include"C_Ackerman_Basic.h"
#include<stdlib.h>
#include<stdio.h>

int main(int argc,char *argv[])
{
	int m,n;
	while(scanf("%d%d",&m,&n))
	{
		if(m>=0 && n>=0)
			printf("%d",Ack(m,n));
	}
}