#ifndef C_JumpTable_LinkList_2012_10_26_16_44
#define C_JumpTable_LinkList_2012_10_26_16_44

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;
typedef double SType;
typedef SType (*ElemType)(SType,SType);

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}*Link,*LinkList;

Status InitList(LinkList &S);
Status ListInsertAtHead(LinkList &S,ElemType e);//ͷ�巨
Status GetElem(LinkList S,int i,ElemType &e);
Status DestroyList(LinkList &S);

#endif