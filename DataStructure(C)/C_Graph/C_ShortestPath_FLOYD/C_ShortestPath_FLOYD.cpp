#include"C_MGraph.h"
#include<stdio.h>
#include<stdlib.h>
#define INFINITY 1000
typedef bool PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef int Weight[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
int CreateGraph(MGraph &G);
int ShortestPath_FLOYD(MGraph G,
					   PathMatrix P[],
					   Weight &D);
int Disply(MGraph G,PathMatrix P[]);

int main(int argc,char *argv[])
{
	MGraph G;
	PathMatrix P[MAX_VERTEX_NUM];
	Weight D;

	CreateGraph(G);
	ShortestPath_FLOYD(G,P,D);
	Disply(G,P);
	system("pause");
	return 0;
}

int CreateGraph(MGraph &G)
{
	int i,j,weight;
	int row,line;
	char v,w;

	for(i=0;i<MAX_VERTEX_NUM;i++)
		for(j=0;j<MAX_VERTEX_NUM;j++)
		{
			G.arcs[i][j].adj=INFINITY;
			G.arcs[i][j].info=NULL;
		}
loop1:
	printf("请输入有向网的顶点数(<=%d)、弧数:",MAX_VERTEX_NUM);
	scanf("%d%d%*c",&G.vexnum,&G.arcnum);
	if(G.vexnum<0 || G.vexnum>MAX_VERTEX_NUM || G.arcnum<0)
		goto loop1;

	printf("输入%d个顶点:",G.vexnum);
	for(i=0;i<G.vexnum;i++)
		scanf("%c%*c",&G.vexs[i]);
	printf("输入%d条弧(顶点1顶点2权值):",G.arcnum);
	for(i=0;i<G.arcnum;i++)
	{
loop2:
		scanf("%c%c%d%*c",&v,&w,&weight);
		row=line=-1;
		for(j=0;j<G.vexnum;j++)
		{
			if(G.vexs[j]==v)
				row=j;
			else if(G.vexs[j]==w)
				line=j;
			if(row!=-1 && line!=-1)
				break;
		}

		if(j>=G.vexnum)
		{
			printf("%c%c输入有误,请重新输入:",v,w);
			goto loop2;
		}

		G.arcs[row][line].adj=weight;
	}

	G.kind=DN;
	return 0;
}

int ShortestPath_FLOYD(MGraph G,PathMatrix P[],Weight &D)
{
	int v,w,u;
	int k;

	for(v=0;v<G.vexnum;v++)
	{
		for(w=0;w<G.vexnum;w++)
		{
			D[v][w]=G.arcs[v][w].adj;
			for(k=0;k<G.vexnum;k++)
				P[v][w][k]=0;
			if(D[v][w]<INFINITY)
			{
				for(k=0;k<G.vexnum;k++)
					P[k][w][v]=1;
				P[v][w][v]=1;
				P[v][w][w]=1;
			}
		}
	}

	for(u=0;u<G.vexnum;u++)
	{
		for(v=0;v<G.vexnum;v++)
		{
			for(w=0;w<G.vexnum;w++)
			{
				if(D[v][u]+D[u][w]<D[v][w])
				{
					D[v][w]=D[v][u]+D[u][w];
					for(k=0;k<G.vexnum;k++)
						P[v][w][k]=P[v][u][k] || P[u][w][k];
				}
			}
		}
	}
	return 0;
}

int Disply(MGraph G,PathMatrix P[])
{
	int v,w,u;
	for(v=0;v<G.vexnum;v++)
	{
		for(w=0;w<G.vexnum;w++)
		{
			printf("%c->%c:",G.vexs[v],G.vexs[w]);
			for(u=0;u<G.vexnum;u++)
			{
				if(P[v][w][u]==1)
					printf("%c ",G.vexs[u]);
			}
			printf("\n");
		}
	}
	return 0;
}