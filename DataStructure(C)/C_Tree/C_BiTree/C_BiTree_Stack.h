#ifndef C_BiTree_Stack_2013_1_31_21_05
#define C_BiTree_Stack_2013_1_31_21_05
//#pragma once

#include"C_BiTree_Header.h"
#include"C_BiTree_Basic.h"
typedef BiTree SElemType;

typedef struct SLNode
{
	SElemType e;
	struct SLNode *next;
}*SLink;

typedef struct
{
	SLink top,base;
}Stack;

Status InitStack(Stack &S);
Status DestroyStack(Stack &S);
Status ClearStack(Stack &S);
bool StackEmpty(Stack S);
int StackLength(Stack S);
Status Push(Stack &S,SElemType e);
Status Pop(Stack &S,SElemType &e);
Status GetTop(Stack S,SElemType &e);
#endif