#include"stdafx.h"
#include"C_LinkList_StudentHealthNote_Basic.h"
#include<string.h>
#include<stdlib.h>

Status InitList(LinkList &L)
{
	L=(LinkList)malloc(sizeof(struct StuNode));
	if(!L)
		return ERROR;
	L->next=NULL;
	return OK;
}

Status InsertAscend(LinkList &L,Student e)
{
	Link p=L->next;
	Link q=L;
	while(p && strcmp(p->data.num,e.num)<0)
	{
		q=p;
		p->next;
	}

	Link k=(Link)malloc(sizeof(struct StuNode));
	if(!k)
		return ERROR;
	k->data=e;//结构体的赋值规则
	k->next=q->next;
	q->next=k;
	return OK;
}

Status ReadIn(LinkList &L,FILE *in)
{
	Student e;
	while(true)
	{
		if(fread(&e,sizeof(Student),1,in)!=1)
		{
			if(feof(in))
			{
				fclose(in);
				break;
			}
		}

		InsertAscend(L,e);
	}

	return OK;
}

Status DeleteNum(LinkList &L,char num[],Student &e)
{
	Link p=L->next;
	Link q=L;

	while(p && strcmp(p->data.num,num))
	{
		q=p;
		p=p->next;
	}

	if(!p)
		return ERROR;
	e=p->data;
	q->next=p->next;
	free(p);
	return OK;
}

Status DeleteName(LinkList &L,char name[],Student &e)
{
	Link q=L,p=L->next;
	while(p && strcmp(p->data.name,name))
	{
		q=p;
		p=p->next;
	}

	if(!p)
		return ERROR;
	e=p->data;
	q->next=p->next;
	free(p);
	return OK;
}

Status ModifyNum(LinkList &L,char num[],Student e)
{
	Link p=L->next;
	while(p && strcmp(num,p->data.num))
		p=p->next;

	if(!p)
		return ERROR;
	p->data=e;
	return OK;
}

Status ModifyName(LinkList &L,char name[],Student e)
{
	Link p=L->next;
	while(p && strcmp(name,p->data.name))
		p=p->next;
	if(!p)
		return ERROR;
	p->data=e;
	return OK;
}

Status SearchNum(LinkList &L,char num[],Student &e)
{
	Link p=L->next;
	while(p && strcmp(p->data.num,num))
		p=p->next;
	if(!p)
		return ERROR;
	e=p->data;
	return OK;
}

Status SearchName(LinkList &L,char name[],Student &e)
{
	Link p=L->next;
	while(p && strcmp(p->data.name,name))
		p=p->next;
	if(!p)
		return ERROR;
	e=p->data;
	return OK;
}
Status DisplayAll(LinkList &L,void (*visit)(Student))
{
	Link p=L->next;
	while(p)
	{
		visit(p->data);
		p=p->next;
	}

	return OK;
}

Status Save(LinkList &L,FILE *out)
{
	Link p=L->next;
	while(p)
	{
		fwrite(&p->data,sizeof(Student),1,out);
		p=p->next;
	}

	return OK;
}