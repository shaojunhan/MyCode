#include"C_JumpTable_Basic.h"

double Add(double a,double b)
{
	return a+b;
}

double Sub(double a,double b)
{
	return a-b;
}

double Mult(double a,double b)
{
	return a*b;
}

double Div(double a,double b)
{
	if(b!=0)
		return a/b;
	else
		return 0;
}