#ifndef C_Polynomial_Header_2012_10_14_20_38
#define C_Polynomial_Header_2012_10_14_20_38

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;

typedef struct
{
	float coef;
	int exp;
}term,ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}*Link,*Position;

typedef struct
{
	Link head,tail;
	int len;
}LinkList,Polynomial;

#endif