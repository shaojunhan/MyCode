#ifndef C_Edlin_LinkStack_2012_10_27_9_12
#define C_Edlin_LinkStack_2012_10_27_9_12

#include"C_Edlin_Header.h"

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}*Link;

typedef struct
{
	Link base;
	Link top;
}LinkStack;

Status InitStack(LinkStack &S);
Status DestroyStack(LinkStack &S);
Status ClearStack(LinkStack &S);
Status StackEmpty(LinkStack S);
int StackLength(LinkStack S);
Status GetTop(LinkStack S,ElemType &e);
Status Push(LinkStack &S,ElemType e);
Status Pop(LinkStack &S,ElemType &e);
Status StackTraverse(LinkStack S,void (*visit)(ElemType));

#endif