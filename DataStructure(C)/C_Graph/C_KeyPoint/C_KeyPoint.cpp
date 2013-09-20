#include"C_ALGraph.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INFINITY INT_MAX

int childcount[MAX_VERTEX_NUM];
int stack[MAX_VERTEX_NUM];
int top,base;
int count;

int CreateGraph(ALGraph &G);
int DFSKeyPoint(ALGraph G);
void PrintKeyPoint(ALGraph G);
int DestroyGraph(ALGraph &G);

int main(int argc,char *argv[])
{
	ALGraph G;
	CreateGraph(G);
	DFSKeyPoint(G);
	PrintKeyPoint(G);
	DestroyGraph(G);
	return 0;
}

int CreateGraph(ALGraph &G)
{
	int i,j;
	int flag;
	int row,line;
	char v1,v2;
	ArcNode *p,*q;

	G.kind=UDG;
	for(i=0;i<MAX_VERTEX_NUM;i++)
	{
		G.vertices[i].firstarc=NULL;
		childcount[i]=0;
	}
loop1:
	printf("输入图的顶点数(<=%d),弧数:",MAX_VERTEX_NUM);
	scanf("%d%d%*c",&G.vexnum,&G.arcnum);
	if(G.vexnum<0 || G.vexnum>MAX_VERTEX_NUM || G.arcnum<0)
		goto loop1;

	printf("输入图的%d个顶点:",G.vexnum);
	for(i=0;i<G.vexnum;i++)
		scanf("%c%*c",&G.vertices[i].data);
	printf("输入图的%d条弧:",G.arcnum);
	for(i=0;i<G.arcnum;i++)
	{
loop2:
		scanf("%c%c%*c",&v1,&v2);
		row=line=-1;
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
			printf("%c%c输入错误，重新输入:",v1,v2);
			goto loop2;
		}
		flag=2;
		while(flag--)
		{
			if(!(p=(ArcNode*)malloc(sizeof(ArcNode))))
				exit(1);
			p->adjvex=line;
			p->info=NULL;
			p->nextarc=NULL;

			if(G.vertices[row].firstarc==NULL || G.vertices[row].firstarc->adjvex>line)
			{
				p->nextarc=G.vertices[row].firstarc;
				G.vertices[row].firstarc=p;
				childcount[row]++;
			}
			else
			{
				for(q=G.vertices[row].firstarc;q->nextarc && q->nextarc->adjvex<=line;q=q->nextarc);
				if(!q->nextarc || q->nextarc->adjvex>line)
				{
					p->nextarc=q->nextarc;
					q->nextarc=p;
					childcount[row]++;
				}
				else
				{
					if(flag)
					{
						free(p);
						goto loop3;
					}
					else
					{
						free(p);
						printf("ERROR!");
						exit(1);
					}
				}
			}//else
			row+=line;
			line=row-line;
			row=row-line;
		}//while
	}

	return 0;
}

void DFS(ALGraph G,int i,int visited[],int low[]);
int DFSKeyPoint(ALGraph G)
{
	int i;
	int visited[MAX_VERTEX_NUM];
	int low[MAX_VERTEX_NUM];
	for(i=0;i<MAX_VERTEX_NUM;i++)
		visited[i]=0;
	
	top=base=0;
	count=0;
	for(i=0;i<G.vexnum;i++)
	{
		if(0==visited[i])
			DFS(G,i,visited,low);
	}
	return 0;
}

void DFS(ALGraph G,int i,int visited[],int low[])
{
	int min;
	bool flag;
	ArcNode *p;

	flag=0;
	min=INFINITY;
	visited[i]=++count;
	low[i]=visited[i];
	for(p=G.vertices[i].firstarc;p;p=p->nextarc)
	{
		if(0==visited[p->adjvex])
		{
			DFS(G,p->adjvex,visited,low);
			if(low[p->adjvex]>=visited[i])
				flag=1;
			else if(min>low[p->adjvex])
				min=low[p->adjvex];
		}
		else if(visited[p->adjvex]<min)
			min=visited[p->adjvex];
	}
	low[i]=min;
	if(flag)
		stack[top++]=i;
}

void PrintKeyPoint(ALGraph G)
{
	while(top!=base)
		printf("%c ",G.vertices[stack[--top]].data);
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
		G.vertices[i].firstarc=NULL;
	}
	return 0;
}