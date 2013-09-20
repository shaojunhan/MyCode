#include"C_Bracket_Basic.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char expression[128];

void visit(ElemType e)
{
	printf("%c",e);
}

Status BracketsMatch()
{
	int i=0;
	bool flag=1;
	int a;
	int b;
	int len;
	SqStack QS;
	LinkStack LS;
	
	InitStack(QS);
	InitStack(LS);

	len=strlen(expression);
	
	while(i<len && flag)
	{
		a=expression[i];
		i++;
		switch(a)
		{
		case '(':
		case '[':
		case '{':
			Push(QS,a);
			Push(LS,a);
			break;
		case ')':
			if(GetTop(QS,b) && b=='(')
			{
				Pop(QS,b);
				Push(LS,')');
			}
			else
				flag=0;
			break;
			
		case ']':
			if(GetTop(QS,b)&& b=='[')
			{
				Pop(QS,b);
				Push(LS,']');
			}
			else
				flag=0;
			break;
		case '}':
			if(GetTop(QS,b)&& b=='{')
			{
				Pop(QS,b);
				Push(LS,'}');
			}
			else
				flag=0;
			break;
		}
	}

	StackTraverse(LS,visit);
	printf("\n");

	if(flag && i>0 && StackEmpty(QS))
	{
		DestroyStack(QS);
		DestroyStack(LS);
		return TRUE;
	}
	else
		return FALSE;
}