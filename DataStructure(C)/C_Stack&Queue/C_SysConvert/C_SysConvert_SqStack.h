#ifndef C_SysConvert_SqStack_2012_10_24_22_54
#define C_SysConvert_SqStack_2012_10_24_22_54

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

#define STACK_INIT_SIZE 5
#define STACKINCREMENT 2

typedef int Status;
typedef char ElemType;

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
Status Push(SqStack &S,ElemType e);
Status Pop(SqStack &S,ElemType &e);
Status GetTop(SqStack S,ElemType &e);
Status StackTraverse(SqStack S,void (*visit)(ElemType));

#endif