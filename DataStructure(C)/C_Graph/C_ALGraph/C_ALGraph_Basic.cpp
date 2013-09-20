#include"C_ALGraph_Basic.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

VertexType Nil='#';
void CreateDG(ALGraph &G);
void CreateDN(ALGraph &G);
void CreateUDG(ALGraph &G);
void CreateUDN(ALGraph &G);
Status CreateGraph(ALGraph &G)
{
	int i,kind;
	
	for(i=0;i<MAX_VERTEX_NUM;i++)
		G.vertices[i].firstarc=NULL;
loop1:
	printf("\n请输入顶点数(<=%d)、弧数:",MAX_VERTEX_NUM);
	scanf("%d%d%*c",&G.vexnum,&G.arcnum);
	if(G.vexnum<1 || G.arcnum<1 || G.vexnum>MAX_VERTEX_NUM)
		goto loop1;
	
	printf("输入%d个顶点:",G.vexnum);
	for(i=0;i<G.vexnum;i++)
		scanf("%c%*c",&G.vertices[i].data);
	
loop2:
	printf("\n1.有向图 2.有向网 3.无向图 4.无向网"
		"\n请输入要创建图的类型:");
	scanf("%d%*c",&kind);
	switch(kind)
	{
	case 1:
		CreateDG(G);
		G.kind=DG;
		break;
	case 2:
		CreateDN(G);
		G.kind=DN;
		break;
	case 3:
		CreateUDG(G);
		G.kind=UDG;
		break;
	case 4:
		CreateUDN(G);
		G.kind=UDN;
		break;
	default:
		goto loop2;
	}
	return OK;
}

void CreateDG(ALGraph &G)
{
	int i,j;
	int row,line;
	char v,w;
	ArcNode *p,*q;
	
	G.kind=DG;
	printf("\n输入%d条弧(顶点1顶点2):",G.arcnum);
	for(i=0;i<G.arcnum;i++)
	{
		scanf("%c%c%*c",&v,&w);
		row=line=-1;
		for(j=0;j<G.vexnum;j++)
		{
			if(G.vertices[j].data==v)
				row=j;
			if(G.vertices[j].data==w)
				line=j;
			if(row!=-1 && line!=-1)
				break;
		}
		if(j>=G.vexnum)
			continue;
		
		if(G.vertices[row].firstarc==NULL || G.vertices[row].firstarc->adjvex>line)
		{
			p=(ArcNode*)malloc(sizeof(ArcNode));
			if(!p)
				exit(OVERFLOW);
			p->adjvex=line;
			p->info=NULL;
			p->nextarc=G.vertices[row].firstarc;
			G.vertices[row].firstarc=p;
		}
		else
		{
			for(q=G.vertices[row].firstarc;q->nextarc && q->nextarc->adjvex<=line;q=q->nextarc);
			if(!q->nextarc || q->nextarc->adjvex>=line)//不存在该弧
			{
				p=(ArcNode*)malloc(sizeof(ArcNode));
				if(!p)
					exit(OVERFLOW);
				p->adjvex=line;
				p->info=NULL;
				p->nextarc=q->nextarc;
				q->nextarc=p;
			}
		}
	}
}

void CreateDN(ALGraph &G)
{
	int i,j,weight;
	int row,line;
	char v1,v2;
	ArcNode *p,*q;
	
	printf("\n输入%d条弧(顶点1顶点2 权值):");
	for(i=0;i<G.arcnum;i++)
	{
		scanf("%c%c%d%*c",&v1,&v2,&weight);
		row=line=-1;
		for(j=0;j<G.vexnum;j++)
		{
			if(G.vertices[j].data==v1)
				row=j;
			if(G.vertices[j].data==v2)
				line=j;
			
			if(row!=-1 && line!=-1)
				break;
		}
		
		if(j>=G.vexnum)
			continue;
		if(G.vertices[row].firstarc==NULL || G.vertices[row].firstarc->adjvex>line)
		{
			if(!(p=(ArcNode*)malloc(sizeof(ArcNode))))
				exit(OVERFLOW);
			if(!(p->info=(InfoType*)malloc(sizeof(InfoType))))
				exit(OVERFLOW);
			p->adjvex=line;
			*(p->info)=weight;
			p->nextarc=G.vertices[row].firstarc;
			G.vertices[row].firstarc=p;
		}
		else
		{
			for(q=G.vertices[row].firstarc;q->nextarc && q->nextarc->adjvex<=line;q=q->nextarc);
			if(!q->nextarc || q->nextarc->adjvex>line)
			{
				if(!(p=(ArcNode*)malloc(sizeof(ArcNode))))
					exit(OVERFLOW);
				if(!(p->info=(InfoType*)malloc(sizeof(ArcNode))))
					exit(OVERFLOW);
				p->adjvex=line;
				*(p->info)=weight;
				p->nextarc=q->nextarc;
				q->nextarc=p;
			}
		}
	}
}

void CreateUDG(ALGraph &G)
{
	int i,j,k;
	int row,line;
	char v1,v2;
	ArcNode *p,*q;
	
	printf("\n输入%d条弧(顶点1顶点2):",G.arcnum);
	for(i=0;i<G.arcnum;i++)
	{
		scanf("%c%c%*c",&v1,&v2);
		row=line=-1;
		for(j=0;j<G.vexnum;j++)
		{
			if(G.vertices[j].data==v1)
				row=j;
			if(G.vertices[j].data==v2)
				line=j;
			if(row!=-1 && line!=-1)
				break;
		}
		if(j>=G.vexnum)
			continue;
		k=2;
		while(k--)
		{
			if(G.vertices[row].firstarc==NULL || G.vertices[row].firstarc->adjvex>line)
			{
				p=(ArcNode*)malloc(sizeof(ArcNode));
				if(!q)
					exit(OVERFLOW);
				p->adjvex=line;
				p->info=NULL;
				p->nextarc=G.vertices[row].firstarc;
				G.vertices[row].firstarc=p;
			}
			else
			{
				for(q=G.vertices[row].firstarc;q->nextarc && q->nextarc->adjvex<=line;q=q->nextarc);
				if(!q->nextarc || q->nextarc->adjvex>line)
				{
					p=(ArcNode*)malloc(sizeof(ArcNode));
					if(!p)
						exit(OVERFLOW);
					p->adjvex=line;
					p->info=NULL;
					p->nextarc=q->nextarc;
					q->nextarc=p;
				}
			}
			//row和line的值交换
			row+=line;
			line=row-line;
			row=row-line;
		}
	}
}

void CreateUDN(ALGraph &G)
{
	int i,j,k,weight;
	int row,line;
	char v1,v2;
	ArcNode *p,*q;
	
	printf("\n请输入%d条弧(顶点1顶点2 权值):");
	for(i=0;i<G.arcnum;i++)
	{
		scanf("%c%c%d%*c",&v1,&v2,&weight);
		row=line=-1;
		for(j=0;j<G.vexnum;j++)
		{
			if(G.vertices[j].data==v1)
				row=j;
			if(G.vertices[j].data==v2)
				line=j;
			if(row!=-1 && line!=-1)
				break;
		}
		if(j>=G.vexnum)
			continue;
		k=2;
		while(k--)
		{
			if(G.vertices[row].firstarc==NULL || G.vertices[row].firstarc->adjvex>line)
			{
				if(!(p=(ArcNode*)malloc(sizeof(ArcNode))))
					exit(OVERFLOW);
				if(!(p->info=(InfoType*)malloc(sizeof(InfoType))))
					exit(OVERFLOW);
				p->adjvex=line;
				*(p->info)=weight;
				p->nextarc=G.vertices[row].firstarc;
				G.vertices[row].firstarc=p;
			}
			else
			{
				for(q=G.vertices[row].firstarc;q->nextarc && q->nextarc->adjvex<=line;q=q->nextarc);
				if(!q->nextarc || q->nextarc->adjvex>line)
				{
					if(!(p=(ArcNode*)malloc(sizeof(ArcNode))))
						exit(OVERFLOW);
					if(!(p->info=(InfoType*)malloc(sizeof(ArcNode))))
						exit(OVERFLOW);
					p->adjvex=line;
					*(p->info)=weight;
					p->nextarc=q->nextarc;
					q->nextarc=p;
				}
			}
			//row和line交换
			row+=line;
			line=row-line;
			row=row-line;
		}
	}
}

Status DestroyGraph(ALGraph &G)
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
	return OK;
}

int LocateVex(ALGraph G,VertexType u)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vertices[i].data==u)
			return i;
	return -1;
}

VertexType GetVex(ALGraph G,int v)
{
	if(v>=0 && v<G.vexnum)
		return G.vertices[v].data;
	return Nil;
}

Status PutVex(ALGraph &G,VertexType v,VertexType value)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(v==G.vertices[i].data)
		{
			G.vertices[i].data=value;
			return OK;
		}
	return FALSE;
}

int FirstAdjVex(ALGraph G,VertexType v)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(v==G.vertices[i].data)
		{
			if(G.vertices[i].firstarc)
				return G.vertices[i].firstarc->adjvex;
			break;
		}
	return -1;
}

int NextAdjVex(ALGraph G,VertexType v,VertexType w)
{
	int i;
	ArcNode *p;
	for(i=0;i<G.vexnum;i++)
		if(v==G.vertices[i].data)
			break;
	if(i>=G.vexnum)
		return -1;
	for(p=G.vertices[i].firstarc;p && G.vertices[p->adjvex].data!=w;p=p->nextarc);
	if(!p || !p->nextarc)
		return -1;
	else
		return p->nextarc->adjvex;
}

Status InsertVex(ALGraph &G,VertexType v)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(v==G.vertices[i].data)
			break;
	if(i<G.vexnum || G.vexnum>=MAX_VERTEX_NUM)
		return FALSE;
	G.vertices[G.vexnum].data=v;
	G.vertices[G.vexnum++].firstarc=NULL;
	return OK;
}

Status DeleteVex(ALGraph &G,VertexType v)
{
	int i,j;
	ArcNode *p,*q;//p为当前指针，q为前驱指针
	for(i=0;i<G.vexnum;i++)
		if(v==G.vertices[i].data)
			break;
	if(i>=G.vexnum)
		return FALSE;

	//删除顶点关联的弧		
	for(j=0;j<G.vexnum;j++)
	{
		while(G.vertices[j].firstarc && G.vertices[j].firstarc->adjvex==i)
		{
			p=G.vertices[j].firstarc;
			G.vertices[j].firstarc=p->nextarc;
			if(p->info)
				free(p->info);
			free(p);
		}
		
		q=G.vertices[j].firstarc;
		while(q && q->nextarc)
		{
			p=q->nextarc;
			if(p->adjvex==i)
			{
				q->nextarc=p->nextarc;
				if(p->info)
					free(p->info);
				free(p);
			}
			else
				q=q->nextarc;
		}
	}
		
	p=G.vertices[i].firstarc;
	while(p)
	{
		q=p->nextarc;
		if(p->info)
			free(p->info);
		free(p);
		p=q;
	}
		
	for(j;j<G.vexnum-1;j++)
	{
		G.vertices[j].data=G.vertices[j+1].data;
		G.vertices[j].firstarc=G.vertices[j+1].firstarc;
		
		for(p=G.vertices[j].firstarc;p;p=p->nextarc)
			if(p->adjvex>i)
				p->adjvex=p->adjvex-1;
	}
	
	G.vertices[i].firstarc=NULL;
	G.vexnum--;
	return OK;
}

Status InsertArc(ALGraph &G,VertexType v,VertexType w,int weight)
{
	int i,j;
	int count;
	bool flag;
	ArcNode *p,*q;
	
	switch(G.kind)
	{
	case DG:
		count=1;
		flag=0;
		break;
	case DN:
		count=1;
		flag=1;
		break;
	case UDG:
		count=2;
		flag=0;
		break;
	case UDN:
		count=2;
		flag=1;
		break;
	default:
		return FALSE;
	}
	
	for(i=0;i<G.vexnum;i++)
		if(v==G.vertices[i].data)
			break;
	for(j=0;j<G.vexnum;j++)
		if(w==G.vertices[j].data)
			break;
	if(i>=G.vexnum || j>=G.vexnum)
		return FALSE;
			
	while(count--)
	{
		if(G.vertices[i].firstarc==NULL || G.vertices[i].firstarc->adjvex>j)
		{
			if(!(p=(ArcNode*)malloc(sizeof(ArcNode))))
				exit(OVERFLOW);
			p->info=NULL;
			if(flag)
			{
				if(!(p->info=(InfoType*)malloc(sizeof(InfoType))))
					exit(OVERFLOW);
				*(p->info)=weight;
			}
			p->adjvex=j;
			p->nextarc=G.vertices[i].firstarc;
			G.vertices[i].firstarc=p;
		}
		else
		{
			for(q=G.vertices[i].firstarc;q->nextarc && q->nextarc->adjvex<=j;q=q->nextarc);
			if(!q->nextarc || q->nextarc->adjvex>j)
			{
				if(!(p=(ArcNode*)malloc(sizeof(ArcNode))))
					exit(OVERFLOW);
				p->info=NULL;
				if(flag)
				{
					if(!(p->info=(InfoType*)malloc(sizeof(InfoType))))
						exit(OVERFLOW);
					*(p->info)=weight;
				}
				p->adjvex=j;
				p->nextarc=q->nextarc;
				q->nextarc=p;
			}
		}
		//交换i,j的值
		i+=j;
		j=i-j;
		i=i-j;
	}
	return OK;
}

Status DeleteArc(ALGraph &G,VertexType v,VertexType w)
{
	int i,j;
	int count;
	ArcNode *p,*q;
	
	for(i=0;i<G.vexnum;i++)
		if(v==G.vertices[i].data)
			break;
	for(j=0;j<G.vexnum;j++)
		if(w==G.vertices[j].data)
			break;
	if(i>=G.vexnum || j>=G.vexnum)
		return FALSE;
			
	switch(G.kind)
	{
	case DG:
	case DN:
		count=1;
		break;
	case UDG:
	case UDN:
		count=2;
		break;
	default:
		count=0;
		break;
	}
	while(count--)
	{
		q=NULL;
		for(p=G.vertices[i].firstarc;p && p->adjvex!=j;p=p->nextarc)
			q=p;
		if(p)
		{
			if(!q)
				G.vertices[i].firstarc=p->nextarc;
			else
				q->nextarc=p->nextarc;
			if(p->info)
				free(p->info);
			free(p);
		}
		//值交换
		i+=j;
		j=i-j;
		i=i-j;
	}
	return OK;
}

void DFS(ALGraph G,int i,void (*Visit)(VertexType),bool visit[]);//深度遍历
Status DFSTraverse(ALGraph G,void (*Visit)(VertexType))
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
void DFS(ALGraph G,int i,void (*Visit)(VertexType),bool visit[])
{
	ArcNode *p;
	visit[i]=1;
	Visit(G.vertices[i].data);
	for(p=G.vertices[i].firstarc;p;p=p->nextarc)
		if(0==visit[p->adjvex])
			DFS(G,p->adjvex,Visit,visit);
}

Status BFSTraverse(ALGraph G,void (*Visit)(VertexType))
{
	int queue[MAX_VERTEX_NUM];//队列
	int front,rear;
	int i,q;//q为游标
	bool visit[MAX_VERTEX_NUM];
	ArcNode *p;
	
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
			q=queue[(front++)%MAX_VERTEX_NUM];
			Visit(G.vertices[q].data);
			for(p=G.vertices[q].firstarc;p;p=p->nextarc)
			{
				if(0==visit[p->adjvex])
				{
					queue[(rear++)%MAX_VERTEX_NUM]=p->adjvex;
					visit[p->adjvex]=1;
				}
			}
		}
	}
	return OK;
}