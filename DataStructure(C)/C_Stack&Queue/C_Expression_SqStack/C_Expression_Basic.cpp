#include"C_Expression_SqStack_Basic.h"
#include"C_Expression_Basic.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char expression[128];
int i=0;

Status IsDigit(char c)
{
	return '0'<=c && c<='9';
}

SElemType Taken()//返回第一个结果
{
	SElemType c='\0';
	int len=strlen(expression);
	if(i<len)
	{
		c=expression[i];
		i++;
		return c;
	}
	else
		return '#';
}

SElemType Operate(SElemType a,SElemType op,SElemType b)
{
	int c='\0';
	
	switch(op)
	{
	case '+':
		c=a+b;
		break;
	case '-':
		c=a-b;
		break;
	case '*':
	case '/':
		if(b=='0')
			c='0';
		else
		{
			a-='0',b-='0';
			if(op=='*')
				c=a*b+'0';
			else
				c=a/b+'0';
		}
		break;
	default:
		c='0';
	}

	return c;
}

SElemType Precede(SElemType t1,SElemType t2)
{
	int c='\0';

	switch(t1)
	{
	case '+':
	case '-':
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
		if(t2==')')
			c='=';
		else if(t2=='#')
			exit(0);
		else
			c='<';
		break;
	case ')':
		if(t2=='(')
			exit(0);
		c='>';
		break;
	case '#':
		if(t2==')')
			exit(0);
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
	SqStack OPND,OPTR;
	SElemType op;
	SElemType t;
	SElemType a,b;

	InitStack(OPND);
	InitStack(OPTR);

	Push(OPTR,'#');
	op=Taken();

	GetTop(OPTR,t);
	while(op!='#' || t!='#')
	{
		if(IsDigit(op))
		{
			Push(OPND,op);
			op=Taken();
		}
		else
		{
			switch(Precede(t,op))
			{
			case '<':
				Push(OPTR,op);
				op=Taken();
				break;
			case '=':
				Pop(OPTR,t);
				op=Taken();
				break;
			case '>':
				Pop(OPTR,t);
				Pop(OPND,a),Pop(OPND,b);
				Push(OPND,Operate(b,t,a));
				break;
			}
		}

		GetTop(OPTR,t);
	}

	GetTop(OPND,a);
	DestroyStack(OPND);
	DestroyStack(OPTR);
	return a;
}