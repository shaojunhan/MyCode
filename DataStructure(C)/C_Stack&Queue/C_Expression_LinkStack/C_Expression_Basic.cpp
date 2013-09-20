#include"C_Expression_Basic.h"
#include<string.h>
#include<stdlib.h>

char expression[128];
int i;

SElemType Taken()
{
	int len=strlen(expression);
	char c='#';

	if(i<len)
	{
		c=expression[i];
		i++;
	}
	else
	{
		c='#';
	}

	return c;
}

SElemType Operate(SElemType a,SElemType op,SElemType b)
{
	char c='#';
	a-='0';
	b-='0';

	switch(op)
	{
	case '-':
		c=a-b+'0';
		break;
	case '+':
		c=a+b+'0';
		break;
	case '/':
		if(b==0)
			exit(1);
		else
			c=a/b+'0';
		break;
	case '*':
		c=a*b+'0';
		break;
	}

	return c;
}

SElemType Precede(SElemType t1,SElemType t2)
{
	char c='<';

	switch(t1)
	{
	case '-':
	case '+':
		if(t2=='*' || t2=='/' || t2=='(')
			c='<';
		else
			c='>';
		break;
	case '*':
	case '/':
		if(t2=='(')
			c='<';
		else
			c='>';
		break;
	case '(':
		if(t2=='#')
			exit(1);
		else if(t2==')')
			c='=';
		else
			c='<';
		break;
	case ')':
		if(t2=='(')
			exit(1);
		else
			c='>';
		break;
	case '#':
		if(t2==')')
			exit(1);
		else if(t2=='#')
			c='=';
		else
			c='<';
		break;
	}
	
	return c;
}

SElemType EvaluateExpression()
{
	char c,x;
	char a,b;
	LinkStack OPND,OPTR;
	InitStack(OPND);
	InitStack(OPTR);
	
	Push(OPTR,'#');

	c=Taken();
	GetTop(OPTR,x);
	while(c!='#' || x!='#')
	{
		if('0'<=c && c<='9')
		{
			Push(OPND,c);
			c=Taken();
		}
		else
		{
			switch(Precede(x,c))
			{
			case '<':
				Push(OPTR,c);
				c=Taken();
				break;
			case '=':
				Pop(OPTR,c);
				c=Taken();
				break;
			case '>':
				Pop(OPTR,x);
				Pop(OPND,b),Pop(OPND,a);
				Push(OPND,Operate(a,x,b));
				break;
			}
		}

		GetTop(OPTR,x);
	}

	Pop(OPND,c);
	DestroyStack(OPND),DestroyStack(OPTR);
	return c;
}