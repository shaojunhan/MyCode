#include"C_MGraph.h"
#include<stdio.h>

#define INFINITY 10000
typedef bool PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
bool final[MAX_VERTEX_NUM];
int CreateGraph(MGraph &G);
int ShortestPath_DIJ(MGraph G,PathMatrix &P,int D[],int v0);
int Disply(MGraph G,PathMatrix &P,int v0);

int main(int argc,char *argv[])
{
	MGraph G;
	PathMatrix P;
	int D[MAX_VERTEX_NUM];

	CreateGraph(G);
	ShortestPath_DIJ(G,P,D,0);
	Disply(G,P,0);
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

int ShortestPath_DIJ(MGraph G,PathMatrix &P,int D[],int v0)
{
	int w,v;
	int i,k;
	int min;

	for(v=0;v<MAX_VERTEX_NUM;v++)
	{
		final[v]=0;
		D[v]=G.arcs[v0][v].adj;
		for(w=0;w<MAX_VERTEX_NUM;w++)
			P[v][w]=0;
		if(D[v]<INFINITY)
		{
			P[v][v0]=1;
			P[v][v]=1;
		}
	}

	D[v0]=0;final[v0]=1;
	for(i=1;i<G.vexnum;i++)
	{
		min=INFINITY;
		for(w=0;w<G.vexnum;w++)
		{
			if(final[w]==0 && min>D[w])
			{
				v=w;
				min=D[w];
			}
		}

		final[v]=1;
		for(w=0;w<G.vexnum;w++)
		{
			if(final[w]==0 && (G.arcs[v][w].adj+min)<D[w])
			{
				D[w]=G.arcs[v][w].adj+min;
				for(k=0;k<G.vexnum;k++)
					P[w][k]=P[v][k];
				P[w][w]=1;
			}
		}
	}
	return 0;
}

int Disply(MGraph G,PathMatrix &P,int v0)
{
	int i,j;

	for(i=0;i<G.vexnum;i++)
	{
		printf("%c->%c:",G.vexs[v0],G.vexs[i]);
		for(j=0;j<G.vexnum;j++)
		{
			if(P[i][j]==1)
				printf("%c ",G.vexs[j]);
		}
		printf("\n");
	}
	return 0;
}