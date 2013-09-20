#include"C_AMLGraph_Basic.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

VertexType Nil='#';

Status CreateGraph(AMLGraph &G)
{
	int i,j;
	int row,line;
	char v1,v2;
	EBox *p;

	for(i=0;i<MAX_VERTEX_NUM;i++)
		G.adjmulist[i].firstedge=NULL;

loop1:
	printf("\n请输入顶点数(<=%d)、弧数:",MAX_VERTEX_NUM);
	scanf("%d%d%*c",&G.vexnum,&G.edgenum);
	if(G.vexnum>=MAX_VERTEX_NUM || G.vexnum<1 || G.edgenum<0)
		goto loop1;
	
	printf("输入%d个顶点:",G.vexnum);
	for(i=0;i<G.vexnum;i++)
		scanf("%c%*c",&G.adjmulist[i].data);
	printf("输入%d条弧(顶点1顶点2):",G.edgenum);
	for(i=0;i<G.edgenum;i++)
	{
		scanf("%c%c%*c",&v1,&v2);
		row=line=-1;
		for(j=0;j<G.vexnum;j++)
		{
			if(G.adjmulist[j].data==v1)
				row=j;
			if(G.adjmulist[j].data==v2)
				line=j;
			if(row!=-1 && line!=-1)
				break;
		}

		if(j>=G.vexnum)
			continue;
		//头插法
		if(!(p=(EBox*)malloc(sizeof(EBox))))
			exit(OVERFLOW);
		p->info=NULL;
		p->ilink=p->jlink=NULL;
		p->ivex=row;
		p->jvex=line;
		p->ilink=G.adjmulist[row].firstedge;G.adjmulist[row].firstedge=p;
		p->jlink=G.adjmulist[line].firstedge;G.adjmulist[line].firstedge=p;
	}
	return OK;
}

Status DestroyGraph(AMLGraph &G)
{
	int i,j;
	EBox *p,*q,*temp;

	for(i=G.vexnum-1;i>=0;i--)
	{
		p=G.adjmulist[i].firstedge;
		while(p)
		{
			j=-1;
			if(p->ivex==i)
			{
				G.adjmulist[i].firstedge=p->ilink;
				j=p->jvex;
			}
			else
			{
				G.adjmulist[i].firstedge=p->jlink;
				j=p->ivex;
			}
			p=G.adjmulist[i].firstedge;
			
			if(j!=-1)
			{
				q=G.adjmulist[j].firstedge;
				if(q && q->ivex==i)
				{
					G.adjmulist[j].firstedge=q->jlink;
					if(q->info)
						free(q->info);
					free(q);
				}
				else if(q && q->jvex==i)
				{
					G.adjmulist[j].firstedge=q->ilink;
					if(q->info)
						free(q->info);
					free(q);				
				}
				else
				{
					while(q)
					{
						if(q->ivex==j && q->jvex!=i)
						{
							temp=q;
							q=q->ilink;
						}
						else if(q->jvex==j && q->ivex!=i)
						{
							temp=q;
							q=q->jlink;
						}
						else
							break;
					}
					if(!q)
						continue;
					if(q->ivex==j && q->jvex==i)
						if(temp->ivex==j)
							temp->ilink=q->ilink;
						else
							temp->jlink=q->ilink;
					if(q->ivex==i && q->jvex==j)
						if(temp->ivex==j)
							temp->ilink=q->jlink;
						else
							temp->jlink=q->jlink;
					if(q->info)
						free(q->info);
					free(q);
				}
			}
		}
	}
	G.vexnum=0;
	G.edgenum=0;
	return OK;
}

int LocateVex(AMLGraph G,VertexType v)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(v==G.adjmulist[i].data)
			return i;
	return -1;
}

VertexType GetVex(AMLGraph G,int v)
{
	if(v>=0 && v<G.vexnum)
		return G.adjmulist[v].data;
	return Nil;
}

Status PutVex(AMLGraph &G,VertexType v,VertexType value)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.adjmulist[i].data==v)
		{
			G.adjmulist[i].data=value;
			return OK;
		}
	return FALSE;
}

int FirstAdjVex(AMLGraph G,VertexType v)
{
	int i;

	for(i=0;i<G.vexnum;i++)
		if(G.adjmulist[i].data==v)
			break;
	if(i>=G.vexnum || G.adjmulist[i].firstedge==NULL)
		return -1;
	if(G.adjmulist[i].firstedge->ivex==i)
		return G.adjmulist[i].firstedge->jvex;
	else
		return G.adjmulist[i].firstedge->ivex;
}

int NextAdjVex(AMLGraph G,VertexType v,VertexType w)
{
	int i;
	int row,line;
	EBox *p;

	row=line=-1;
	for(i=0;i<G.vexnum;i++)
	{
		if(G.adjmulist[i].data==v)
			row=i;
		if(G.adjmulist[i].data==w)
			line=i;
		if(row!=-1 && line!=-1)
			break;
	}

	if(i>=G.vexnum && G.adjmulist[row].firstedge==NULL || G.adjmulist[line].firstedge==NULL)
		return -1;
	p=G.adjmulist[row].firstedge;
	while(p)
	{//搜索到该弧
		if((p->ivex==row && p->jvex==line) || (p->ivex==line && p->jvex==row))
			break;
		if(p->ivex==row)
			p=p->ilink;
		else if(p->jvex==row)
			p=p->jlink;
	}

	if(!p)
		return -1;
	if(p->ivex==row && p->ilink)//求下一个邻接顶点
	{
		if(p->ilink->ivex==row)
			return p->ilink->jvex;
		else if(p->ilink->jvex==row)
			return p->ilink->ivex;
	}
	if(p->jvex==row && p->jlink)
	{
		if(p->jlink->ivex==row)
			return p->jlink->jvex;
		else if(p->jlink->jvex==row)
			return p->jlink->ivex;
	}

	return -1;
}

Status InsertVex(AMLGraph &G,VertexType v)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.adjmulist[i].data==v)
			break;
	if(i<G.vexnum || G.vexnum>=MAX_VERTEX_NUM)
		return FALSE;
	G.adjmulist[G.vexnum].data=v;
	G.adjmulist[G.vexnum++].firstedge=NULL;
	return OK;
}

Status DeleteVex(AMLGraph &G,VertexType v)
{
	VertexType w;
	int i,j;
	EBox *p;

	for(i=0;i<G.vexnum;i++)
		if(G.adjmulist[i].data==v)
			break;
	if(i>=G.vexnum)
		return FALSE;
	//先删除邻接边，再删除顶点
	p=G.adjmulist[i].firstedge;
	while(p)
	{
		if(p->ivex==i)
		{
			w=G.adjmulist[p->jvex].data;
			p=p->ilink;
		}
		else
		{
			w=G.adjmulist[p->ivex].data;
			p=p->jlink;
		}
		DeleteArc(G,v,w);
	}

	for(j=i;j<G.vexnum-1;j++)//平移
		G.adjmulist[j]=G.adjmulist[j+1];
	G.vexnum--;
	for(j=i;j<G.vexnum;j++)
	{
		p=G.adjmulist[j].firstedge;
		while(p)
		{
			if(p->ivex==j+1)
			{
				p->ivex=j;
				p=p->ilink;
			}
			else if(p->jvex==j+1)
			{
				p->jvex=j;
				p=p->jlink;
			}
		}
	}

	return OK;
}

Status InsertArc(AMLGraph &G,VertexType v,VertexType w)
{
	int row,line;
	int i;
	EBox *p;

	row=line=-1;
	for(i=0;i<G.vexnum;i++)
	{
		if(G.adjmulist[i].data==v)
			row=i;
		if(G.adjmulist[i].data==w)
			line=i;
		if(row>=0 && line>=0)
			break;
	}

	if(i>=G.vexnum)
		return FALSE;
	if(!(p=(EBox*)malloc(sizeof(EBox))))
		exit(OVERFLOW);
	p->info=NULL;
	p->ilink=p->jlink=NULL;
	p->ivex=row;p->ilink=G.adjmulist[row].firstedge;G.adjmulist[row].firstedge=p;
	p->jvex=line;p->jlink=G.adjmulist[line].firstedge;G.adjmulist[line].firstedge=p;
	G.edgenum++;
	return OK;
}

Status DeleteArc(AMLGraph &G,VertexType v,VertexType w)
{
	int row,line;
	int i;
	EBox *p,*q;

	row=line=-1;
	for(i=0;i<G.vexnum;i++)
	{
		if(G.adjmulist[i].data==v)
			row=i;
		if(G.adjmulist[i].data==w)
			line=i;
		if(row>=0 && line>=0)
			break;
	}
	if(i>=G.vexnum)
		return FALSE;
	p=G.adjmulist[row].firstedge;
	if(p && p->ivex==line)
		G.adjmulist[row].firstedge=p->jlink;
	else if(p && p->jvex==line)
		G.adjmulist[row].firstedge=p->ilink;
	else
	{
		while(p)
		{
			if(p->ivex==row && p->jvex!=line)
			{
				q=p;
				p=p->ilink;
			}
			else if(p->jvex==row && p->ivex!=line)
			{
				q=p;
				p=p->jlink;
			}
			else
				break;
		}

		if(!p)
			return ERROR;
		if(p->ivex==row && p->jvex==line)
			if(q->ivex==row)
				q->ilink=p->ilink;
			else
				q->jlink=p->jlink;
		else if(p->jvex==row && p->ivex==line)
			if(q->ivex==row)
				q->ilink=p->jlink;
			else
				q->jlink=p->jlink;
	}

	p=G.adjmulist[line].firstedge;
	if(p && p->ivex==row)
	{
		G.adjmulist[line].firstedge=p->jlink;
		if(p->info)
			free(p->info);
		free(p);
	}
	else if(p && p->jvex==row)
	{
		G.adjmulist[line].firstedge=p->ilink;
		if(p->info)
			free(p->info);
		free(p);
	}
	else
	{
		while(p)
		{
			if(p->ivex==line && p->jvex!=row)
			{
				q=p;
				p=p->ilink;
			}
			else if(p->jvex==line && p->ivex!=row)
			{
				q=p;
				p=p->jlink;
			}
			else 
				break;
		}
		if(!p)
			return ERROR;
		if(p->ivex==row && p->jvex==line)
			if(q->ivex==row)
				q->ilink=p->ilink;
			else
				q->jlink=p->jlink;
		else if(p->jvex==row && p->ivex==line)
			if(q->ivex==row)
				q->ilink=p->jlink;
			else
				q->jlink=p->jlink;
		if(p->info)
			free(p->info);
		free(p);
	}
	p=NULL;
	G.edgenum--;
	return OK;
}

void DFS(AMLGraph G,int i,void (*Visit)(VertexType),bool visit[]);
Status DFSTraverse(AMLGraph G,void (*Visit)(VertexType))
{
	int i;
	bool visit[MAX_VERTEX_NUM];
	for(i=0;i<MAX_VERTEX_NUM;i++)
		visit[i]=0;
	for(i=0;i<G.vexnum;i++)
		if(0==visit[i])
			DFS(G,i,Visit,visit);
	return OK;
}
void DFS(AMLGraph G,int i,void (*Visit)(VertexType),bool visit[])
{
	EBox *p;

	visit[i]=1;
	Visit(G.adjmulist[i].data);
	p=G.adjmulist[i].firstedge;
	while(p)
	{
		if(p->ivex==i)
		{
			if(0==visit[p->jvex])
				DFS(G,p->jvex,Visit,visit);
			p=p->ilink;
		}
		else if(p->jvex==i)
		{
			if(0==visit[p->ivex])
				DFS(G,p->ivex,Visit,visit);
			p=p->jlink;
		}
	}
}

Status BFSTraverse(AMLGraph G,void (*Visit)(VertexType))
{
	int i,cur;
	int queue[MAX_VERTEX_NUM];//队列
	int front,rear;
	bool visit[MAX_VERTEX_NUM];
	EBox *p;

	for(i=0;i<MAX_VERTEX_NUM;i++)
		visit[i]=0;
	front=rear=0;
	for(i=0;i<G.vexnum;i++)
	{
		if(0==visit[i])
		{
			queue[(rear++)%MAX_VERTEX_NUM]=i;
			visit[i]=1;
		}

		while(front!=rear)
		{
			cur=queue[(front++)%MAX_VERTEX_NUM];
			Visit(G.adjmulist[cur].data);
			
			p=G.adjmulist[cur].firstedge;
			while(p)
			{
				if(p->ivex==cur)
				{
					if(visit[p->jvex]==0)
					{
						queue[(rear++)%MAX_VERTEX_NUM]=p->jvex;
						visit[p->jvex]=1;
					}
					p=p->ilink;
				}
				else if(p->jvex==cur)
				{
					if(visit[p->ivex]==0)
					{
						queue[(rear++)%MAX_VERTEX_NUM]=p->ivex;
						visit[p->ivex]=1;
					}
					p=p->jlink;
				}
			}
		}
	}
	return OK;
}