#ifndef C_Expression_SqStack_Basic_2012_10_22_13_9
#define C_Expression_SqStack_Basic_2012_10_22_13_9

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

#define STACK_INIT_SIZE 5
#define STACKINCREMENT 2

typedef char ElemType;
typedef int Status;

typedef  struct
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &Q);
Status DestroyStack(SqStack &Q);
Status ClearStack(SqStack &Q);
Status StackEmpty(SqStack Q);
int StackLength(SqStack Q);
Status GetTop(SqStack Q,ElemType &e);
Status Push(SqStack &Q,ElemType e);
Status Pop(SqStack &Q,ElemType &e);
Status StackTraverse(SqStack Q,void (*visit)(ElemType));

#endif