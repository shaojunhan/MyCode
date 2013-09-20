#include"C_Stack.h"
#include"C_ALGraph.h"
#include<stdio.h>
#include<stdlib.h>

int CreateGraph(ALGraph &G);
int FindInDegree(ALGraph G,int indegree[]);
int TopologySort(ALGraph G,Stack &S);
void Print(ALGraph G,Stack &S);
int DestroyGraph(ALGraph &G);

int main(int argc,char *argv[])
{
	ALGraph G;
	Stack S;
	InitStack(S);

	CreateGraph(G);
	TopologySort(G,S);
	Print(G,S);

	DestroyGraph(G);
	DestroyStack(S);
	system("pause");
	return 0;
}

int CreateGraph(ALGraph &G)
{
	int i,j;
	char v1,v2;
	int row,line;
	ArcNode *p,*q;

	for(i=0;i<MAX_VERTEX_NUM;i++)
		G.vertices[i].firstarc=NULL;
loop1:
	printf("输入有向图的顶点数(<=%d)、弧数:",MAX_VERTEX_NUM);
	scanf("%d%d%*c",&G.vexnum,&G.arcnum);
	if(G.vexnum<0 || G.vexnum>MAX_VERTEX_NUM || G.arcnum<0)
		goto loop1;
	
	printf("输入%d个顶点:",G.vexnum);
	for(i=0;i<G.vexnum;i++)
		scanf("%c%*c",&G.vertices[i].data);
	printf("输入%d条弧:",G.arcnum);
	for(i=0;i<G.arcnum;i++)
	{
		scanf("%c%c%*c",&v1,&v2);
		row=line=-1;
		for(j=0;j<G.vexnum;j++)
		{
loop2:		if(v1==G.vertices[j].data)
				row=j;
			else if(v2==G.vertices[j].data)
				line=j;
			if(row!=-1 && line!=-1)
				break;
		}
		if(j>=G.vexnum)
		{
loop3:		printf("弧<%c,%c>输入错误:",v1,v2);
			goto loop2;
		}

		if(!(p=(ArcNode*)malloc(sizeof(ArcNode))))
			exit(1);
		p->info=NULL;
		p->adjvex=line;
		p->nextarc=NULL;
		if(G.vertices[row].firstarc==NULL || G.vertices[row].firstarc->adjvex>line)
		{
			p->nextarc=G.vertices[row].firstarc;
			G.vertices[row].firstarc=p;
		}
		else
		{
			for(q=G.vertices[row].firstarc;q->nextarc && q->nextarc->adjvex<=line;q=q->nextarc);
			if(!q->nextarc || q->nextarc->adjvex>line)
			{
				p->nextarc=q->nextarc;
				q->nextarc=p;
			}
			else
			{
				free(p);
				goto loop3;
			}
		}
	}
	return 0;
}

int FindInDegree(ALGraph G,int indegree[])
{
	int i;
	ArcNode *p;

	for(i=0;i<MAX_VERTEX_NUM;i++)
		indegree[i]=0;
	for(i=0;i<G.vexnum;i++)
	{
		p=G.vertices[i].firstarc;
		while(p)
		{
			indegree[p->adjvex]++;
			p=p->nextarc;
		}
	}
	return 0;
}

int TopologySort(ALGraph G,Stack &S)
{
	int count;
	int cur,i;
	Stack T;
	ArcNode *p;
	int indegree[MAX_VERTEX_NUM];

	FindInDegree(G,indegree);
	ClearStack(S);
	InitStack(T);
	count=0;
	for(i=0;i<G.vexnum;i++)
		if(indegree[i]==0)
		{
			Push(T,i);
			count++;
		}
	
	while(!StackEmpty(T))
	{
		Pop(T,cur);
		Push(S,cur);
		p=G.vertices[cur].firstarc;
		while(p)
		{
			if(--indegree[p->adjvex]==0)
			{
				Push(T,p->adjvex);
				count++;
			}
			p=p->nextarc;
		}
	}
	if(count<G.vexnum)
		return 1;
	else
		return 0;
}

void Print(ALGraph G,Stack &S)
{
	int v;
	while(!StackEmpty(S))
	{
		Pop(S,v);
		printf("%c ",G.vertices[v].data);
	}
}

int DestroyGraph(ALGraph &G)
{
	int i;
	ArcNode *p,*q;

	for(i=0;i<G.vexnum;i++)
	{
		p=G.vertices[i].firstarc;
		while(p)
		{
			q=p->nextarc;
			if(p->info)
				free(p->info);
			free(p);
			p=q;
		}
	}
	return 0;
}
