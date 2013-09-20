#ifndef C_LinkStack_Basic_2012_10_19_16_38
#define C_LinkStack_Basic_2012_10_19_16_38

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int ElemType;
typedef int Status;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}*Link;

typedef struct
{
	Link top;
	Link base;
}LinkStack;

Status InitStack(LinkStack &S);
Status DestroyStack(LinkStack &S);
Status ClearStack(LinkStack &S);
Status StackEmpty(LinkStack S);
int StackLength(LinkStack S);
Status Push(LinkStack &S,ElemType e);
Status Pop(LinkStack &S,ElemType &e);
Status GetTop(LinkStack S,ElemType &e);
Status StackTraverse(LinkStack S,void (*visit)(ElemType));

#endif