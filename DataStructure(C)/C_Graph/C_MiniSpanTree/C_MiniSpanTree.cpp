#include"C_MGraph.h"
#include"C_CTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Closedge
{
	int weight;
	int v;
};
struct Closedge closedge[MAX_VERTEX_NUM];
int count;

int CreateGraph(MGraph &G);
int MiniSpanTree_PRIM(MGraph G,CTree &T);
int LevelOrderTraverse(CTree T);
int DestroyTree(CTree &T);

int main(int argc,char *argv[])
{
	MGraph G;
	CTree T;
	CreateGraph(G);
	MiniSpanTree_PRIM(G,T);
	LevelOrderTraverse(T);
	DestroyTree(T);
	return 0;
}

int CreateGraph(MGraph &G)
{
	int i,j;
	char v1,v2;
	int row,line;
	int weight;

	for(i=0;i<MAX_VERTEX_NUM;i++)
		for(j=0;j<MAX_VERTEX_NUM;j++)
			G.arcs[i][j].adj=0;
loop1:
	printf("输入图的顶点数、弧数,其中顶点数(<=%d):",MAX_VERTEX_NUM);
	scanf("%d%d%*c",&G.vexnum,&G.arcnum);
	if(G.vexnum<1 || G.vexnum>MAX_VERTEX_NUM || G.arcnum<0)
		goto loop1;
	printf("输入%d个顶点:",G.vexnum);
	for(i=0;i<G.vexnum;i++)
		scanf("%c%*c",&G.vexs[i]);
	printf("输入%d条弧(顶点1顶点2权值):",G.arcnum);
	for(i=0;i<G.arcnum;i++)
	{
loop2:
		scanf("%c%c%d%*c",&v1,&v2,&weight);
		row=line=-1;
		for(j=0;j<G.vexnum;j++)
		{
			if(G.vexs[j]==v1)
				row=j;
			else if(G.vexs[j]==v2)
				line=j;
			if(row!=-1 && line!=-1)
				break;
		}
		if(j>=G.vexnum)
		{
			printf("输入错误,请重新输入:");
			goto loop2;
		}

		G.arcs[row][line].adj=1;G.arcs[row][line].info=weight;
		G.arcs[line][row].adj=1;G.arcs[line][row].info=weight;
	}
	return 0;
}

void minimum(int &cur,int &min)
{
	int i;
	int temp=INFINITY;
	for(i=0;i<count;i++)
	{
		if(closedge[i].weight!=0 && closedge[i].weight<temp)
		{
			temp=closedge[i].weight;
			cur=closedge[i].v;
			min=i;
		}
	}
}

int MiniSpanTree_PRIM(MGraph G,CTree &T)
{
	int i,cur,min;
	int flag;
	cur=0;//初始U集为u0;
	ChildPtr p,q;

	T.num=G.vexnum;
	for(i=0;i<G.vexnum;i++)
	{
		T.data[i].e=G.vexs[i];
		T.data[i].firstchild=NULL;
	}

	count=G.vexnum;
	cur=0;
	for(i=0;i<count;i++)
	{
		if(i==cur)
			closedge[i].weight=0;
		else if(G.arcs[cur][i].adj)
			closedge[i].weight=G.arcs[cur][i].info;
		else
			closedge[i].weight=INFINITY;
		closedge[i].v=cur;
	}

	flag=G.vexnum-1;
	while((flag--)>0)
	{
		minimum(cur,min);
		
		if(!(p=(ChildPtr)malloc(sizeof(CNode))))
			exit(1);
		p->child=min;
		p->next=NULL;
		if(T.data[cur].firstchild==NULL || T.data[cur].firstchild->child>min)
		{
			p->next=T.data[cur].firstchild;
			T.data[cur].firstchild=p;
		}
		else
		{
			for(q=T.data[cur].firstchild;q->next && q->next->child<=min;q=q->next);
			if(!q->next || q->next->child>min)
			{
				p->next=q->next;
				q->next=p;
			}
		}

		cur=min;
		for(i=0;i<count;i++)
		{
			if(i==cur)
				closedge[i].weight=0;
			else
			{
				if(closedge[i].weight!=0 && G.arcs[cur][i].adj && G.arcs[cur][i].info<closedge[i].weight)
				{
					closedge[i].weight=G.arcs[cur][i].info;
					closedge[i].v=cur;
				}
			}
		}
	}
	return 0;
}

int LevelOrderTraverse(CTree T)
{
	int queue[MAX_VERTEX_NUM];
	int front,rear;
	ChildPtr p;
	int cur;

	if(T.num<=0)
		return -1;
	front=rear=0;
	queue[(rear++)%MAX_VERTEX_NUM]=0;
	while(front!=rear)
	{
		cur=queue[(front++)%MAX_VERTEX_NUM];
		printf("%c ",T.data[cur].e);
		p=T.data[cur].firstchild;
		while(p)
		{
			queue[(rear++)%MAX_VERTEX_NUM]=p->child;
			p=p->next;
		}
	}
	return 0;
}

int DestroyTree(CTree &T)
{
	int i;
	ChildPtr p,q;
	for(i=0;i<T.num;i++)
	{
		p=T.data[i].firstchild;
		while(p)
		{
			q=p->next;
			free(p);
			p=q;
		}
		T.data[i].firstchild=NULL;
	}
	return 0;
}