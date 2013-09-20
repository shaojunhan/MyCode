#include"C_Hanoi_Basic.h"
#include<stdio.h>


void Move(int n,char c1,char c2)
{
	printf("%c----%d--->%c\n",c1,n,c2);
}

void Hanoi(int n,char x,char y,char z)
{
	if(n<=0)
		return;
	if(n==1)
		Move(n,x,z);
	else
	{
		Hanoi(n-1,x,z,y);
		Move(n,x,z);
		Hanoi(n-1,y,x,z);
	}
}