#ifndef C_Stack_2013_2_17_13_55
#define C_Stack_2013_2_17_13_55
//#pragma once
#define INIT_STACK_SIZE 5
#define INCR_STACK_SIZE 5
typedef int SElemType;
typedef struct
{
	SElemType *base,*top;
	int stacksize;
}Stack;
int InitStack(Stack &S);
int DestroyStack(Stack &S);
int ClearStack(Stack &S);
bool StackEmpty(Stack S);
int StackLength(Stack S);
int Push(Stack &S,SElemType e);
int Pop(Stack &S,SElemType &e);
int GetTop(Stack S,SElemType &e);

#endif