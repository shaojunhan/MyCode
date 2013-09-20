#ifndef C_Maze_LinkStack_2012_10_28_16_26
#define C_Maze_LinkStack_2012_10_28_16_26

#include"C_Maze_Header.h"

typedef struct
{
	Link top;
	Link base;
}LinkStack;

Status InitStack(LinkStack &S);
Status DestroyStack(LinkStack &S);
Status ClearStack(LinkStack &S);
Status StackEmpty(LinkStack S);
int StackLenght(LinkStack S);
Status GetTop(LinkStack S,ElemType &e);
Status Push(LinkStack &S,ElemType e);
Status Pop(LinkStack &S,ElemType &e);
Status StackTraverse(LinkStack S,void (*visit)(ElemType));

#endif