#include"C_ALGraph.h"
#include"C_CSTree.h"
#include<stdio.h>
#include<stdlib.h>

int CreateGraph(ALGraph &G);
int DFSTree(ALGraph G,CSTree &T);
int DestroyGraph(ALGraph &G);
int DestroyTree(CSTree &T);
void DFS(ALGraph G,CSTree &T,int i);
void PreOrderTraverse(CSTree T);
void PostOrderTraverse(CSTree T);
void Visit(TElemType e);
bool visit[MAX_VERTEX_NUM];
int main(int argc,char *argv[])
{
	ALGraph G;
	CSTree T;
	CreateGraph(G);
	DFSTree(G,T);
	printf("\n前序、后序遍历森林:");
	PreOrderTraverse(T);
	printf("\n");
	PostOrderTraverse(T);
	DestroyGraph(G);
	DestroyTree(T);
	return 0;
}

int CreateGraph(ALGraph &G)
{
	int i,j,flag;
	int row,line;
	char v1,v2;
	ArcNode *p,*q;
	
	G.kind=UDG;
	for(i=0;i<MAX_VERTEX_NUM;i++)
		G.vertices[i].firstarc=NULL;
loop1:
	printf("请输入无向图的顶点数(<=%d)、弧数:",MAX_VERTEX_NUM);
	scanf("%d%d%*c",&G.vexnum,&G.arcnum);
	if(G.vexnum<1 || G.vexnum>MAX_VERTEX_NUM || G.arcnum<0)
		goto loop1;
	printf("输入%d个顶点:",G.vexnum);
	for(i=0;i<G.vexnum;i++)
		scanf("%c%*c",&G.vertices[i].data);
	printf("输入%d条弧(顶点1顶点2):",G.arcnum);
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
			printf("输入错误,重新输入:");
			goto loop2;
		}
	
		flag=2;
		while(flag--)
		{
			if(!(p=(ArcNode*)malloc(sizeof(ArcNode))))
				exit(0);
			p->adjvex=line;
			p->info=0;
			p->next=NULL;
			//按从小到大有序插入
			if(G.vertices[row].firstarc==NULL || G.vertices[row].firstarc->adjvex<line)
			{
				p->next=G.vertices[row].firstarc;
				G.vertices[row].firstarc=p;
			}
			else
			{
				for(q=G.vertices[row].firstarc;q->next && q->next->adjvex>=line;q=q->next);
				if(!q->next || q->next->adjvex<line)
				{
					p->next=q->next;
					q->next=p;
				}
				else//已经存在该弧
				{
					free(p);
					goto loop3;
				}
			}
			row+=line;
			line=row-line;
			row=row-line;
		}
	}
	return 0;
}

int DFSTree(ALGraph G,CSTree &T)
{
	int i;
	CSTree p;

	for(i=0;i<MAX_VERTEX_NUM;i++)
		visit[i]=0;
	if(G.vexnum==0)
	{
		T=NULL;
		return 1;
	}

	DFS(G,T,0);
	p=T;
	for(i=0;i<G.vexnum;i++)
		if(0==visit[i])
		{
			DFS(G,p->rightsibling,i);
			p=p->rightsibling;
		}
	return 0;
}

void DFS(ALGraph G,CSTree &T,int i)
{
	CSTree pt;
	ArcNode *pa;
	bool first;

	visit[i]=1;
	if(!(T=(CSTree)malloc(sizeof(CSNode))))
		exit(1);
	T->data=G.vertices[i].data;
	T->firstchild=T->rightsibling=NULL;

	first=0;
	pt=T;
	for(pa=G.vertices[i].firstarc;pa;pa=pa->next)
		if(0==visit[pa->adjvex])
		{
			if(first==0)
			{
				DFS(G,pt->firstchild,pa->adjvex);
				pt=pt->firstchild;
				first=1;
			}
			else
			{
				DFS(G,pt->rightsibling,pa->adjvex);
				pt=pt->rightsibling;
			}
		}
}

void PreOrderTraverse(CSTree T)
{
	if(T)
	{
		Visit(T->data);
		PreOrderTraverse(T->firstchild);
		PreOrderTraverse(T->rightsibling);
	}
}

void PostOrderTraverse(CSTree T)
{
	if(T)
	{
		PostOrderTraverse(T->firstchild);
		Visit(T->data);
		PostOrderTraverse(T->rightsibling);
	}
}

void Visit(TElemType e)
{
	printf("%c ",e);
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
			q=p->next;
			free(p);
			p=q;
		}
	}
	return 0;
}

int DestroyTree(CSTree &T)
{
	if(T)
	{
		DestroyTree(T->firstchild);
		DestroyTree(T->rightsibling);
		free(T);
		T=NULL;
		return 0;
	}
	return 1;
}