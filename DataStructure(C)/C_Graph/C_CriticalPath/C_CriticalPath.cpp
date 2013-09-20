#include"C_Stack.h"
#include"C_ALGraph.h"
#include<stdio.h>
#include<stdlib.h>

int ve[MAX_VERTEX_NUM];
int CreateGraph(ALGraph &G);
int DestroyGraph(ALGraph &G);
int FindInDegree(ALGraph G,int degree[]);
int TopologySort(ALGraph G,Stack &S,int degree[]);
int CriticalPath(ALGraph G,Stack &S);

int main(int argc,char *argv[])
{
	ALGraph G;
	Stack S;
	int degree[MAX_VERTEX_NUM];

	CreateGraph(G);
	InitStack(S);
	TopologySort(G,S,degree);
	CriticalPath(G,S);

	DestroyGraph(G);
	DestroyStack(S);
	system("pause");
	return 0;
}

int CreateGraph(ALGraph &G)
{
	int i,j,weight;
	char v1,v2;
	int row,line;
	ArcNode *p,*q;

	for(i=0;i<MAX_VERTEX_NUM;i++)
		G.vertices[i].firstarc=NULL;
loop1:
	printf("输入有向网的顶点数(<=%d)、弧数:",MAX_VERTEX_NUM);
	scanf("%d%d%*c",&G.vexnum,&G.arcnum);
	if(G.vexnum<0 || G.vexnum>MAX_VERTEX_NUM || G.arcnum<0)
		goto loop1;

	printf("输入%d个顶点:",G.vexnum);
	for(i=0;i<G.vexnum;i++)
		scanf("%c%*c",&G.vertices[i].data);
	printf("输入%d条弧:",G.arcnum);
	for(i=0;i<G.arcnum;i++)
	{
loop2:
		row=line=-1;
		scanf("%c%c%d%*c",&v1,&v2,&weight);
		for(j=0;j<G.vexnum;j++)
		{
			if(G.vertices[j].data==v1)
				row=j;
			else if(G.vertices[j].data==v2)
				line=j;
			if(row!=-1 && line!=-1)
				break;
		}

		if(j>=G.vexnum)
		{
loop3:
			printf("<%c,%c,%d>输入有误,请重新输入:",v1,v2,weight);
			goto loop2;
		}

		p=(ArcNode*)malloc(sizeof(ArcNode));
		if(!p)
			exit(1);
		p->adjvex=line;
		p->info=weight;
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
	}//for
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
			free(p);
			p=q;
		}
		G.vertices[i].firstarc=NULL;
	}
	return 0;
}

int TopologySort(ALGraph G,Stack &S,int indegree[])
{
	Stack T;//零入度顶点栈
	int i,count,j;
	ArcNode *p;

	for(i=0;i<MAX_VERTEX_NUM;i++)
		ve[i]=0;
	count=0;
	FindInDegree(G,indegree);
	InitStack(T);
	for(i=0;i<G.vexnum;i++)
		if(indegree[i]==0)
		{
			Push(T,i);
			count++;
		}
	while(!StackEmpty(T))
	{
		Pop(T,j);
		Push(S,j);
		p=G.vertices[j].firstarc;
		while(p)
		{
			if(--indegree[p->adjvex]==0)
			{
				Push(T,p->adjvex);
				count++;
			}
			if((ve[j]+p->info)>ve[p->adjvex])
				ve[p->adjvex]=ve[j]+p->info;
			p=p->nextarc;
		}
	}

	if(count<G.vexnum)
		return 1;
	else
		return 0;
}

int CriticalPath(ALGraph G,Stack &S)
{
	int vl[MAX_VERTEX_NUM];
	int i,j,k;
	int ee,el;
	char tag;
	ArcNode *p;

	for(j=i=0;i<G.vexnum;i++)//找到汇点
		if(ve[i]>ve[j])
			j=i;

	for(i=0;i<MAX_VERTEX_NUM;i++)
		vl[i]=ve[j];

	while(!StackEmpty(S))
	{
		Pop(S,j);
		p=G.vertices[j].firstarc;
		while(p)
		{
			k=p->adjvex;
			if(vl[j]>(vl[k]-p->info))
				vl[j]=vl[k]-p->info;
			ee=ve[j];
			el=vl[k]-p->info;
			tag=(ee==el)?'*':' ';
			printf("%3d %3d %3d %3d %3d %c\n",j,k,p->info,ee,el,tag);
			p=p->nextarc;
		}
	}

	for(j=0;j<G.vexnum;j++)
	{
		p=G.vertices[j].firstarc;
		while(p)
		{
			k=p->adjvex;
			ee=ve[j];
			el=vl[k]-p->info;
			if(ee==el)
				printf("%c->%c ",G.vertices[j].data,G.vertices[k].data);
			p=p->nextarc;
		}
	}
	return 0;
}
