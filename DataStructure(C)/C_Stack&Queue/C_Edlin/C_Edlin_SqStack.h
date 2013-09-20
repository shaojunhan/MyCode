#ifndef C_Edlin_SqStack_2012_10_27_9_17
#define C_Edlin_SqStack_2012_10_27_9_17

#include"C_Edlin_Header.h"

typedef struct
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;


Status InitStack(SqStack &S);
Status DestroyStack(SqStack &S);
Status ClearStack(SqStack &S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S,ElemType &e);
Status Push(SqStack &S,ElemType e);
Status Pop(SqStack &S,ElemType &e);
Status StackTraverse(SqStack S,void (*visit)(ElemType));

#endif