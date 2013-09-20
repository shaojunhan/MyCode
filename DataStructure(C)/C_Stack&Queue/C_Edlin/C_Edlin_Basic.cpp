#include"C_Edlin_Basic.h"
#include"C_Edlin_SqStack.h"
#include"C_Edlin_LinkStack.h"
#include<stdlib.h>
#include<stdio.h>

FILE *fp;

void visit(ElemType e)
{
	printf("%c",e);
}

void Flush(ElemType e)
{
	fwrite(&e,1,sizeof(ElemType),fp);
	fflush(fp);
}

void Edlin()
{
	SqStack QS;
	LinkStack LS;
	char c;

	fp=fopen("test.bin","wb+");
	if(!fp)
		exit(ERROR);

	InitStack(QS);
	InitStack(LS);

	while(~scanf("%c",&c) && c!='~')
	{
		while(c!='\n' && c!='~')
		{
			switch(c)
			{
			case '#':
				Pop(QS,c);
				Pop(LS,c);
				break;
			case '@':
				ClearStack(QS);
				ClearStack(LS);
				break;
			default:
				Push(QS,c);
				Push(LS,c);
			}
			c=getchar();

		}

		StackTraverse(QS,Flush);
		StackTraverse(LS,visit);

		ClearStack(QS);
		ClearStack(LS);
	}

	fclose(fp);
}
