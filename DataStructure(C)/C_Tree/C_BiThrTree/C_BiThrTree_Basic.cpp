#include"C_BiThrTree_Basic.h"
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

#if CHAR
TElemType Nil='#';
#else
TElemType Nil=0;
#endif

//前序遍历创建
BiThrTree pre=NULL;
Status Create(BiThrTree &T)
{
	TElemType e;

#if CHAR
	scanf("%c",&e);
#else
	scanf("%d",&e);
#endif

	if(e!=Nil)
	{
		if(!(T=(BiThrTree)malloc(sizeof(struct BiThrNode))))
			exit(OVERFLOW);
		T->LTag=T->RTag=Link;
		T->lchild=T->rchild=NULL;
		T->e=e;
		Create(T->lchild);
		Create(T->rchild);
	}
	else
		T=NULL;
	return OK;
}

Status CreateBiThrTree(BiThrTree &Thr)
{
	BiThrTree T;
	Thr=T=NULL;
	Create(T);
	return InOrderThread(Thr,T);
}

Status DestroyBiThrTree(BiThrTree &Thr)
{
	BiThrTree p,q;
	if(!Thr)
		return OK;
	else
	{
		p=Thr->lchild;
		while(p!=Thr)
		{
			while(p->LTag==Link)
				p=p->lchild;
			q=p;
			while(p->RTag==Thread && p->rchild!=Thr)
			{
				p=p->rchild;
				free(q);
				q=p;
			}
			p=p->rchild;
			free(q);
			q=p;
		}
		free(Thr);
		Thr=NULL;
		return OK;
	}
}

void InThreading(BiThrTree &p)
{
	if(p)
	{
		InThreading(p->lchild);
		if(!p->lchild)
		{
			p->LTag=Thread;
			p->lchild=pre;
		}
		if(!pre->rchild)
		{
			pre->RTag=Thread;
			pre->rchild=p;
		}
		pre=p;
		InThreading(p->rchild);
	}
}

Status InOrderThread(BiThrTree &Thr,BiThrTree T)
{	
	if(!(Thr=(BiThrTree)malloc(sizeof(struct BiThrNode))))
		exit(OVERFLOW);
	Thr->LTag=Link;
	Thr->RTag=Thread;
	if(!T)
		Thr->lchild=Thr->rchild=Thr;
	else
	{
		pre=Thr;
		Thr->lchild=T;
		InThreading(Thr->lchild);
		pre->LTag=Thread;
		pre->rchild=Thr;
		Thr->rchild=pre;
	}
	return OK;
}

Status InOrderTraverse_Thr(BiThrTree Thr,void (*Visit)(TElemType))
{
	BiThrTree p;
	if(!Thr)
		return OK;
	else
	{
		p=Thr->lchild;
		while(p!=Thr)
		{
			while(p->LTag==Link)
				p=p->lchild;
			Visit(p->e);
			while(p->RTag==Thread && p->rchild!=Thr)
			{
				p=p->rchild;
				Visit(p->e);
			}
			p=p->rchild;
		}
	}
}