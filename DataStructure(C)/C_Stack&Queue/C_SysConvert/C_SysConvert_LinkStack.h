#ifndef C_SysConvert_LinkStack_2012_10_25_13_06
#define C_SysConvert_LinkStack_2012_10_25_13_06

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;
typedef char ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}*Link;

typedef struct 
{
	Link top,base;
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