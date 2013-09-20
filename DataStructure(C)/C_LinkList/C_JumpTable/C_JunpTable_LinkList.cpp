#include"C_JumpTable_LinkList.h"
#include<stdlib.h>
#include<math.h>

Status InitList(LinkList &S)
{
	S=(LinkList)malloc(sizeof(struct LNode));
	if(!S)
		exit(OVERFLOW);
	S->next=NULL;
	return OK;
}

//ͷ�巨
Status ListInsertAtHead(LinkList &S,ElemType e)
{
	Link s=(Link)malloc(sizeof(struct LNode));
	if(!s)
		return ERROR;
	s->data=e;
	s->next=S->next;
	S->next=s;
	return OK;
}

Status GetElem(LinkList S,int i,ElemType &e)
{
	int j=0;
	Link p=S->next;
	while(p)
	{
		j++;
		p=p->next;
	}

	if(i<1 || i>j)
		return ERROR;
	
	j=1;
	p=S->next;
	while(j<i)
	{
		p=p->next;
		j++;
	}
	
	e=p->data;
	return OK;

}

Status DestroyList(LinkList &S)
{
	Link p;
	while(S)
	{
		p=S->next;
		free(S);
		S=p;
	}

	S=NULL;
	return OK;
}