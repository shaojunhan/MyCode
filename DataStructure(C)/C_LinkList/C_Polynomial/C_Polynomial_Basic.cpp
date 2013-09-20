#include"stdafx.h"
#include"C_Polynomial_Basic.h"
#include"C_Polynomial_LinkList.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int compare(ElemType e1,ElemType e2)
{
	return e1.exp==e2.exp?0:e1.exp>e2.exp?1:-1;
}

void CreatePolyn(Polynomial &P,int m)
{
	Link ha;
	Link s;
	int i=0;
	ElemType e;
	float coef;
	int exp;

	InitList(P);
	ha=GetHead(P);

	printf("请输入%d组数据,格式为:(x,y)其中x为系数,y为指数:",m);
	while(i<m)
	{
loop1:
		scanf("(%f,%d)",&coef,&exp);
		e.coef=coef;
		e.exp=exp;
		fflush(stdin);

		if(LocateElem(P,e,compare))
		{
			printf("已经存在该系数,请重新输入:");
			goto loop1;
		}
		else
		{
			if(!MakeNode(s,e))
			{
				printf("内存分配失败!按任意键返回...");
				getch();
				return;
			}
			InsFirst(P,ha,s);
			i++;
		}
	}
}

void DestroyPolyn(Polynomial &P)
{
	DestroyList(P);
}

void PrintPolyn(Polynomial P)
{
	Link pa;
	Link ha=GetHead(P);
	pa=NextPos(P,ha);

	while(pa)
	{
		printf("(%.3f X %d)",pa->data.coef,pa->data.exp);
		if(pa->next)
			printf("+");
		pa=NextPos(P,pa);
	}
	printf("\n");
}

int PolynLength(Polynomial P)
{
	return P.len;
}

void AddPolyn(Polynomial &Pa,Polynomial &Pb)
{
	Link pb,hb=GetHead(Pb);
	Link s;
	ElemType e;
	Link pa,ha=GetHead(Pa),qa;

	pb=NextPos(Pb,hb);

	while(pb)
	{
		e=pb->data;
		if(!(pa=LocateElem(Pa,e,compare)))
		{
			if(!MakeNode(s,e))
			{
				printf("内存分配失败!按任意键返回...");
				getch();
				return;
			}

			InsFirst(Pa,ha,s);
		}
		else
		{
			pa->data.coef+=e.coef;
			if(pa->data.coef==0.0f)
			{
				qa=PriorPos(Pa,pa);
				if(!qa)
					qa=GetHead(Pa);
				DelFirst(Pa,qa,pa);
			}
		}

		pb=NextPos(Pb,pb);
	}
}

void SubPolyn(Polynomial &Pa,Polynomial &Pb)
{
	Link pb,hb=GetHead(Pb);

	pb=NextPos(Pb,hb);
	while(pb)
	{
		pb->data.coef*=-1;
		pb=NextPos(Pb,pb);
	}

	AddPolyn(Pa,Pb);
}

void MultiplyPolyn(Polynomial &Pa,Polynomial &Pb)
{
	Polynomial Pc;
	InitList(Pc);
	ElemType e;
	Link s;

	Link ha=GetHead(Pa),pa;
	Link hb=GetHead(Pb),pb;
	Link hc=GetHead(Pc),pc;

	DelFirst(Pb,hb,pb);
	while(pb)
	{
		pa=NextPos(Pa,ha);
		while(pa)
		{
			e.coef=pa->data.coef*pb->data.coef;
			e.exp=pa->data.exp+pb->data.exp;

			if(!(pc=LocateElem(Pc,e,compare)))
			{
				if(!MakeNode(s,e))
				{
					printf("内存分配失败!按任意键退出...");
					getch();
					return;
				}
				else
					InsFirst(Pc,hc,s);
			}
			else
			{
				pc->data.coef+=e.coef;
				if(pc->data.coef==0.0f)
				{
					pc=PriorPos(Pc,pc);
					if(!pc)
						pc=hc;
					DelFirst(Pc,hc,pc);
				}
			}

			pa=NextPos(Pa,pa);
		}
		DelFirst(Pb,hb,pb);
	}

	DestroyList(Pb);
	ClearList(Pa);
	if(hc->next)
	{
		Append(Pa,hc->next);
	}
}