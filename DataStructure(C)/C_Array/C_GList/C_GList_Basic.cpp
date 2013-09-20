#include"C_GList_Basic.h"
#include<stdlib.h>
#include<math.h>
#include<string.h>

//
Status InitGList(GList &L)
{
	L=NULL;
	return OK;
}

//
Status CreateGList(GList &L,HString S)
{
	HString cmp,Sub,hsub;
	GList pt;

	InitHString(cmp),InitHString(Sub),InitHString(hsub);
	StrAssign(cmp,"()");//

	if(!(L=(GList)malloc(sizeof(struct GLNode))))
		exit(OVERFLOW);

	if(StrEmpty(S) || !StrCompare(S,cmp))//空表
	{
		L->tag=LIST;
		L->hp=L->tp=NULL;
	}
	else if(StrLength(S)==1)//原子元素
	{
		L->tag=ATOM;
		L->atom=*(S.base+0);
		L->tp=NULL;
	}
	else
	{
		L->tag=LIST;
		L->tp=NULL;
		SubString(Sub,S,2,StrLength(S)-2);
		server(Sub,hsub);
		CreateGList(L->hp,hsub);

		pt=L->hp;
		while(!StrEmpty(Sub))
		{
			server(Sub,hsub);
			CreateGList(pt->tp,hsub);
			pt=pt->tp;
		}
	}
	return OK;
}

Status DestroyGList(GList &L)
{
	GList ph,pt;
	if(L)
	{
		if(L->tag==ATOM)
			ph=NULL;
		else
			ph=L->hp;
		pt=L->tp;
		free(L),L=NULL;
		DestroyGList(ph);
		DestroyGList(pt);
	}
	return OK;
}

Status CopyGList(GList &T,GList L)
{
	DestroyGList(T);
	if(!L)
		T=NULL;
	else
	{
		if(!(T=(GList)malloc(sizeof(struct GLNode))))
			exit(OVERFLOW);
		T->tag=L->tag;
		T->tp=NULL;
		if(L->tag==ATOM)
			T->atom=L->atom;
		else
		{
			T->hp=NULL;
			CopyGList(T->hp,L->hp);
		}
		CopyGList(T->tp,L->tp);
	}
	return OK;
}

Status GListLength(GList L)
{
	GList pt;
	int len;
	
	if(!L || L->tag==LIST && !L->hp)
		return 0;
	if(L->tag==ATOM)
		return 1;
	else
	{
		pt=L->hp,len=0;
		do
		{
			len++;
			pt=pt->tp;
		}while(pt);
		return len;	
	}
}

int GListDepth(GList L)
{
	int max;
	int d;
	GList pt;

	if(L->tag==LIST && !L->hp)
		return 1;
	else if(!L || L->tag==ATOM)
		return 0;
	else
	{
		max=d=0;
		pt=L->hp;
		while(pt)
		{
			d=GListDepth(pt);
			if(d>max)
				max=d;
			pt=pt->tp;
		}
		return max+1;
	}
}

bool GListEmpty(GList L)
{
	return L==NULL || L->tag==LIST && !L->hp;
}

GList GetHead(GList L)
{
	GList p;
	
	if(!L || (L->tag==LIST && !L->hp))
		return NULL;

	InitGList(p);
	if(!(p=(GList)malloc(sizeof(struct GLNode))))
		exit(OVERFLOW);
	p->tp=NULL;

	p->tag=L->hp->tag;
	if(L->hp->tag==ATOM)
		p->atom=L->hp->atom;
	else
	{
		p->hp=NULL;
		CopyGList(p->hp,L->hp->hp);
	}
	return p;
}

GList GetTail(GList L)
{
	GList p;

	if(!L)
		return NULL;

	InitGList(p);
	if(!(p=(GList)malloc(sizeof(struct GLNode))))
		exit(OVERFLOW);

	p->tag=LIST;
	p->hp=p->tp=NULL;
	(L->tag==LIST && !L->hp)?CopyGList(p->hp,NULL):CopyGList(p->hp,L->hp->tp);
	return p;
}

Status InsertFirst_GL(GList &L,GList e)
{
	GList p;

	p=L->hp;
	L->hp=e;
	e->tp=p;
	return OK;
}

Status DeleteFirst_GL(GList &L,GList &e)
{
	if(!L || L->tag==LIST && !L->hp)
		e=NULL;
	else
	{
		if(e)
			DestroyGList(e);
		e=L->hp;
		L->hp=e->tp;
		e->tp=NULL;
	}
	return OK;
}

Status Traverse_GL(GList L, void (*visit)(AtomType))
{
	if(!L || L->tag==LIST && !L->hp)//空表
		return FALSE;
	else
	{
		if(L->tag==ATOM)
			visit(L->atom);
		else
			Traverse_GL(L->hp,visit);

		Traverse_GL(L->tp,visit);
		return OK;
	}
}

void server(HString &str,HString &hstr)
{
	int i,k;
	int n;
	HString C1,C2,C3,Ch;
	
	InitHString(C1),InitHString(C2),InitHString(C3),InitHString(Ch);//初始串
	StrAssign(C1,"("),StrAssign(C2,")"),StrAssign(C3,",");
	
	n=StrLength(str);
	i=1,k=0;
	do
	{
		SubString(Ch,str,i,1);
		if(!StrCompare(Ch,C1))
			++k;
		else if(!StrCompare(Ch,C2))
			--k;
		i++;
	}while(i<=n && StrCompare(Ch,C3) || k!=0);
	if(i<=n)
	{
		StrCopy(Ch,str);
		SubString(hstr,Ch,1,i-2);
		SubString(str,Ch,i,n-i+1);
	}
	else
	{
		StrCopy(hstr,str);
		ClearString(str);
	}
}