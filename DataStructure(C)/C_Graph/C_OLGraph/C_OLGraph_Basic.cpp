#include"C_OLGraph_Basic.h"
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

VertexType Nil='#';
Status CreateGraph(OLGraph &G)
{
	int i,j;
	int mark;
	char v1,v2;
	int row,line;
	ArcBox *p,*q;

	//初始
	for(i=0;i<MAX_VERTEX_NUM;i++)
	{
		G.xlist[i].firstin=NULL;
		G.xlist[i].firstout=NULL;
	}

loop1:
	printf("\n请输入顶点数(<=%d)、弧数:",MAX_VERTEX_NUM);
	scanf("%d%d%*c",&G.vexnum,&G.arcnum);
	if(G.vexnum<1 || G.arcnum<0 || G.vexnum>MAX_VERTEX_NUM)
		goto loop1;
	
	printf("请输入%d个顶点:",G.vexnum);
	for(i=0;i<G.vexnum;i++)
		scanf("%c%*c",&G.xlist[i].data);
	printf("请输入%d条弧(顶点1顶点2):",G.arcnum);
	for(i=0;i<G.arcnum;i++)
	{
		scanf("%c%c%*c",&v1,&v2);
		row=line=-1;
		for(j=0;j<G.vexnum;j++)
		{
			if(v1==G.xlist[j].data)
				row=j;
			if(v2==G.xlist[j].data)
				line=j;
			if(row!=-1 && line!=-1)
				break;
		}

		if(j>=G.vexnum)
			continue;

		mark=0;
		if(!(p=(ArcBox*)malloc(sizeof(ArcBox))))
			exit(OVERFLOW);
		p->hlink=p->tlink=NULL;
		p->info=NULL;
		p->headvex=line;
		p->tailvex=row;
		
		if(G.xlist[row].firstout==NULL || G.xlist[row].firstout->headvex>line)
		{
			p->tlink=G.xlist[row].firstout;
			G.xlist[row].firstout=p;
			mark=1;
		}
		else
		{
			for(q=G.xlist[row].firstout;q->tlink && q->tlink->headvex<=line;q=q->tlink);
			if(!q->tlink || q->tlink->tailvex>line)
			{
				p->tlink=q->tlink;
				q->tlink=p;
				mark=1;
			}
		}

		if(G.xlist[line].firstin==NULL || G.xlist[line].firstin->tailvex>row)
		{
			p->hlink=G.xlist[line].firstin;
			G.xlist[line].firstin=p;
			mark=2;
		}
		else
		{
			for(q=G.xlist[line].firstin;q->hlink && q->hlink->tailvex<=row;q=q->hlink);
			if(!q->hlink || q->hlink->tailvex>row)
			{
				p->hlink=q->hlink;
				q->hlink=p;
				mark=2;
			}
		}

		if(mark==0)
			free(p);
		else if(mark!=2)
			exit(1);
	}

	return OK;
}

Status DestroyGraph(OLGraph &G)
{
	int i;
	ArcBox *p,*q;

	for(i=0;i<G.vexnum;i++)
	{//指向相同弧尾的指针脱离
		//十字链表变成单链表
		p=G.xlist[i].firstout;
		while(p)
		{
			q=p->tlink;
			p->tlink=NULL;
			p=q;
		}
		G.xlist[i].firstout=NULL;
	}

	for(i=0;i<G.vexnum;i++)
	{//删除结点
		p=G.xlist[i].firstin;
		while(p)
		{
			q=p->hlink;
			free(p);
			p=q;
		}
		G.xlist[i].firstin=NULL;
	}

	G.arcnum=0;
	G.vexnum=0;
	return OK;
}

int LocateVex(OLGraph G,VertexType u)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(u==G.xlist[i].data)
			return i;
	return -1;
}

VertexType GetVex(OLGraph G,int v)
{
	if(v>=0 && v<G.vexnum)
		return G.xlist[v].data;
	return Nil;
}

Status PutVex(OLGraph &G,VertexType v,VertexType value)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(v==G.xlist[i].data)
		{
			G.xlist[i].data=value;
			return OK;
		}
	return FALSE;
}

int FirstAdjVex(OLGraph G,VertexType v)
{
	int i;

	for(i=0;i<G.vexnum;i++)
		if(G.xlist[i].data==v && G.xlist[i].firstout)
			return G.xlist[i].firstout->headvex;
	return -1;
}

int NextAdjVex(OLGraph G,VertexType v,VertexType w)
{
	int i;
	ArcBox *p;
	for(i=0;i<G.vexnum;i++)
		if(G.xlist[i].data==v)
			break;
	if(i>=G.vexnum)
		return -1;
	p=G.xlist[i].firstout;
	while(p)
	{
		if(w==G.xlist[p->headvex].data && p->tlink)
			return p->tlink->headvex;
		p=p->tlink;
	}
	return -1;
}

Status InsertVex(OLGraph &G,VertexType v)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.xlist[i].data==v)
			break;
	if(i<G.vexnum || G.vexnum>=MAX_VERTEX_NUM)
		return FALSE;
	G.xlist[G.vexnum].data=v;
	G.xlist[G.vexnum].firstin=NULL;
	G.xlist[G.vexnum++].firstout=NULL;
	return OK;
}

Status DeleteVex(OLGraph &G,VertexType v)
{
	int i,j;
	ArcBox *p,*q;
	int count;

	for(i=0;i<G.vexnum;i++)
		if(v==G.xlist[i].data)
			break;
	if(i>=G.vexnum)
		return FALSE;
	for(j=0;j<G.vexnum;j++)
	{//与i关联的弧节点都脱离出来
		if(j==i)
			continue;
		if(G.xlist[j].firstout)
		{
			if(G.xlist[j].firstout->headvex==i)
				G.xlist[j].firstout=G.xlist[j].firstout->tlink;
			else
			{
				for(q=G.xlist[j].firstout;q->tlink && q->tlink->headvex!=i;q=q->tlink);
				if(q->tlink)
					q->tlink=q->tlink->tlink;
			}
		}

		if(G.xlist[j].firstin)
		{
			if(G.xlist[j].firstin->tailvex==i)
				G.xlist[j].firstin=G.xlist[j].firstin->hlink;
			else
			{
				for(q=G.xlist[j].firstin;q->hlink && q->hlink->tailvex!=i;q=q->hlink);
				if(q->hlink)
					q->hlink=q->hlink->hlink;
			}
		}
	}

	count=0;//记录删除的弧数
	p=G.xlist[i].firstout;
	while(p)
	{
		q=p->tlink;
		if(p->headvex!=p->tailvex)//不是自回路
		{
			free(p);
			count++;
		}
		p=q;
	}
	p=G.xlist[i].firstin;
	while(p)
	{
		q=p->hlink;
		free(p);
		count++;
		p=q;
	}
	
	for(i;i<G.vexnum-1;i++)
	{//i后的节点前移,修改弧信息
		G.xlist[i]=G.xlist[i+1];
		for(p=G.xlist[i].firstout;p;p=p->tlink)
			p->tailvex=i;
		for(p=G.xlist[i].firstin;p;p=p->hlink)
			p->headvex=i;
	}

	G.xlist[i].firstin=NULL;
	G.xlist[i].firstout=NULL;
	G.vexnum--;
	G.arcnum-=count;

	return OK;
}

Status InsertArc(OLGraph &G,VertexType v,VertexType w)
{
	int i,j;
	int mark;
	ArcBox *p,*q;

	for(i=0;i<G.vexnum;i++)
		if(v==G.xlist[i].data)
			break;
	for(j=0;j<G.vexnum;j++)
		if(w==G.xlist[j].data)
			break;
	if(i>=G.vexnum || j>=G.vexnum)
		return FALSE;

	mark=0;
	if(!(p=(ArcBox*)malloc(sizeof(ArcBox))))
		exit(OVERFLOW);
	p->info=NULL;
	p->hlink=p->tlink=NULL;
	p->headvex=j;
	p->tailvex=i;

	if(G.xlist[i].firstout==NULL || G.xlist[i].firstout->headvex>j)
	{
		p->tlink=G.xlist[i].firstout;
		G.xlist[i].firstout=p;
		mark=1;
	}
	else
	{
		for(q=G.xlist[i].firstout;q->tlink && q->tlink->headvex<=j;q=q->tlink);
		if(!q->tlink || q->tlink->headvex>j)
		{
			p->tlink=q->tlink;
			q->tlink=p;
			mark=1;
		}
	}

	if(G.xlist[j].firstin==NULL || G.xlist[j].firstin->tailvex>i)
	{
		p->hlink=G.xlist[j].firstin;
		G.xlist[j].firstin=p;
		mark=2;
	}
	else
	{
		for(q=G.xlist[j].firstin;q->hlink && q->hlink->tailvex<=i;q=q->hlink);
		if(!q->hlink || q->hlink->tailvex>i)
		{
			p->hlink=q->hlink;
			q->hlink=p;
			mark=2;
		}
	}
	if(mark==0)
		free(p);
	else if(mark!=2)
		exit(1);
	return OK;
}

Status DeleteArc(OLGraph &G,VertexType v,VertexType w)
{
	int i,j;
	ArcBox *p,*q;
	
	for(i=0;i<G.vexnum;i++)
		if(v==G.xlist[i].data)
			break;
	for(j=0;j<G.vexnum;j++)
		if(w==G.xlist[j].data)
			break;
	if(i>=G.vexnum || j>G.vexnum)
		return FALSE;

	p=NULL;
	if(G.xlist[i].firstout)
	{
		if(G.xlist[i].firstout->headvex==j)
		{
			p=G.xlist[i].firstout;
			G.xlist[i].firstout=G.xlist[i].firstout->tlink;
		}
		else
		{
			for(q=G.xlist[i].firstout;q->tlink && q->tlink->headvex!=j;q=q->tlink);
			if(q->tlink)
			{
				p=q->tlink;
				q->tlink=q->tlink->tlink;
			}
		}
	}

	if(G.xlist[j].firstin)
	{
		if(G.xlist[j].firstin->tailvex==i)
		{
			if(p!=G.xlist[j].firstin)
				return FALSE;
			G.xlist[j].firstin=G.xlist[j].firstin->hlink;
		}
		else
		{
			for(q=G.xlist[j].firstin;q->hlink && q->hlink->tailvex!=i;q=q->hlink);
			if(q->hlink)
			{
				if(p!=q->hlink)
					return FALSE;
				q->hlink=q->hlink->hlink;
			}
		}
	}

	if(p)
		free(p);
	G.arcnum--;
	return OK;
}

void DFS(OLGraph G,int i,void (*Visit)(VertexType),bool visit[]);
Status DFSTraverse(OLGraph G,void (*Visit)(VertexType))
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
void DFS(OLGraph G,int i,void (*Visit)(VertexType),bool visit[])
{
	ArcBox *p;
	visit[i]=1;
	Visit(G.xlist[i].data);
	for(p=G.xlist[i].firstout;p;p=p->tlink)
		if(0==visit[p->tailvex])
			DFS(G,p->tailvex,Visit,visit);
}

Status BFSTraverse(OLGraph G,void (*Visit)(VertexType))
{
	int queue[MAX_VERTEX_NUM];//队列
	int front,rear;
	int i,cur;
	bool visit[MAX_VERTEX_NUM];
	ArcBox *p;

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
			Visit(G.xlist[cur].data);
			for(p=G.xlist[cur].firstout;p;p=p->tlink)
			{
				if(0==visit[p->headvex])
				{
					queue[(rear++)%MAX_VERTEX_NUM]=p->headvex;
					visit[p->headvex]=1;
				}
			}
		}
	}
	return OK;
}
