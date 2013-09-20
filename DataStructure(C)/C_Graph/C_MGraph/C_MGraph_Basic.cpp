#include"C_MGraph_Basic.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

VertexType Nil='#';
void CreateDG(MGraph &G);
void CreateDN(MGraph &G);
void CreateUDG(MGraph &G);
void CreateUDN(MGraph &G);

Status CreateGraph(MGraph &G)
{
	int i,j;

	for(i=0;i<MAX_VERTEX_NUM;i++)//��ʼ����
	{
		for(j=0;j<i;j++)
		{
			G.arcs[i][j].adj=0;G.arcs[i][j].info=NULL;
			G.arcs[j][i].adj=0;G.arcs[j][i].info=NULL;
		}
		G.arcs[i][i].adj=0;G.arcs[i][j].info=NULL;
	}

loop1:
	printf("\n���붥����������(<=%d):",MAX_VERTEX_NUM);
	scanf("%d%d%*c",&G.vexnum,&G.arcnum);
	if(G.vexnum<1 || G.arcnum<1 || G.vexnum>MAX_VERTEX_NUM || G.arcnum>MAX_VERTEX_NUM)
		goto loop1;
	
	printf("���붥��:");
	for(i=0;i<G.vexnum;i++)
		scanf("%c%*c",&G.vexs[i]);
loop2:
	printf("1.����ͼ 2.������ 3.����ͼ 4.������"
		"\n���봴��ͼ������:");
	scanf("%d%*c",&i);
	switch(i)
	{
	case 1:
		CreateDG(G);
		break;
	case 2:
		CreateDN(G);
		break;
	case 3:
		CreateUDG(G);
		break;
	case 4:
		CreateUDN(G);
		break;
	default:
		goto loop2;
	}
	return OK;
}

void CreateUDG(MGraph &G)
{
	int i,j;
	int row,line;//�С���
	char v1,v2;

	G.kind=UDG;
	printf("���뻡(����1 ����2):");
	for(i=0;i<G.arcnum;i++)
	{
		row=line=-1;
		scanf("%c%c%*c",&v1,&v2);
		for(j=0;j<G.vexnum;j++)
		{
			if(v1==G.vexs[j])
				row=j;
			else if(v2==G.vexs[j])
				line=j;

			if(row!=-1 && line!=-1)
				break;
		}

		if(row!=-1 && line!=-1)
		{
			G.arcs[row][line].adj=1;
			G.arcs[line][row].adj=1;
		}
	}
}

void CreateDG(MGraph &G)
{
	int i,j;
	int row,line;//�С���
	char v1,v2;

	G.kind=DG;
	printf("���뻡(����1 ����2):");
	for(i=0;i<G.arcnum;i++)
	{
		row=line=-1;
		scanf("%c%c%*c",&v1,&v2);
		for(j=0;j<G.vexnum;j++)
		{
			if(v1==G.vexs[j])
				row=j;
			else if(v2==G.vexs[j])
				line=j;

			if(row!=-1 && line!=-1)
				break;
		}

		if(row!=-1 && line!=-1)
			G.arcs[row][line].adj=1;
	}
}

void CreateDN(MGraph &G)
{
	int i,weight,j;
	int row,line;//�С���
	char v1,v2;

	G.kind=DN;
	printf("���뻡(����1 ����2 Ȩֵ):");
	for(i=0;i<G.arcnum;i++)
	{
		row=line=-1;
		scanf("%c%c%d%*c",&v1,&v2,&weight);
		for(j=0;j<G.vexnum;j++)
		{
			if(v1==G.vexs[j])
				row=j;
			else if(v2==G.vexs[j])
				line=j;

			if(row!=-1 && line!=-1)
				break;
		}

		if(row!=-1 && line!=-1)
			G.arcs[row][line].adj=weight;
	}
}

void CreateUDN(MGraph &G)
{
	int i,weight,j;
	int row,line;//�С���
	char v1,v2;

	G.kind=UDN;
	printf("���뻡(����1 ����2 Ȩֵ):");
	for(i=0;i<G.arcnum;i++)
	{
		row=line=-1;
		scanf("%c%c%d%*c",&v1,&v2,&weight);
		for(j=0;j<G.vexnum;j++)
		{
			if(v1==G.vexs[j])
				row=j;
			else if(v2==G.vexs[j])
				line=j;

			if(row!=-1 && line!=-1)
				break;
		}

		if(row!=-1 && line!=-1)
		{
			G.arcs[row][line].adj=weight;
			G.arcs[line][row].adj=weight;
		}
	}
}

Status DestroyGraph(MGraph &G)
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			if(G.arcs[i][j].info!=NULL)
				free(G.arcs[i][j].info);
		}
	}
	G.arcnum=0;
	G.vexnum=0;
	return OK;
}

int LocateVex(MGraph G,VertexType u)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vexs[i]==u)
			return i;
	return -1;
}

VertexType GetVex(MGraph G,VertexType v)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vexs[i]==v)
			return v;
	return Nil;
}

Status PutVex(MGraph &G,VertexType v,VertexType value)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vexs[i]==v)
		{
			G.vexs[i]=value;
			return OK;
		}
	return FALSE;
}

int FirstAdjVex(MGraph G,VertexType v)
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
		if(G.vexs[i]==v)
		{
			for(j=0;j<G.vexnum;j++)
				if(G.arcs[i][j].adj!=0)
					return j;
			break;
		}
	return -1;
}

int NextAdjVex(MGraph G,VertexType v,VertexType w)
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
		if(G.vexs[i]==v)
			break;
	if(i>=G.vexnum)
		return -1;

	for(j=0;j<G.vexnum;j++)
		if(G.vexs[j]==w)
			break;
	if(j>=G.vexnum || G.arcs[i][j].adj==0)
		return -1;

	for(j=j+1;j<G.vexnum;j++)
		if(G.arcs[i][j].adj!=0)
			return j;
	return -1;
}

Status InsertVex(MGraph &G,VertexType v)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vexs[i]==v)
			break;
	if(i<G.vexnum)
		return FALSE;
	if(G.vexnum<MAX_VERTEX_NUM)
	{
		G.vexs[G.vexnum++]=v;
		return OK;
	}

	return FALSE;
}

Status DeleteVex(MGraph &G,VertexType v)
{
	int i,j;
	int cur;
	int count;

	for(cur=0;cur<G.vexnum;cur++)
		if(G.vexs[cur]==v)
			break;
	if(cur>=G.vexnum)
		return FALSE;
	
	for(count=0,j=0;j<G.vexnum;j++)//���ٶѷ��䡢����
	{
		if(G.arcs[cur][j].info!=NULL)
		{
			free(G.arcs[cur][j].info);
			G.arcs[cur][j].info=NULL;
		}
		if(G.arcs[j][cur].info!=NULL)
		{
			free(G.arcs[j][cur].info);
			G.arcs[j][cur].info=NULL;
		}

		if(G.arcs[cur][j].adj!=0)
			count++;
	}

	for(i=cur;i<G.vexnum-1;i++)//��ƽ��
	{
		G.vexs[i]=G.vexs[i+1];
		for(j=0;j<G.vexnum;j++)
		{
			G.arcs[i][j].adj=G.arcs[i+1][j].adj;
			G.arcs[i][j].info=G.arcs[i+1][j].info;
		}
	}
	for(i=cur;i<G.vexnum-1;i++)//������ƽ��
	{
		for(j=0;j<G.vexnum;j++)
		{
			G.arcs[j][i].adj=G.arcs[j][i+1].adj;
			G.arcs[j][i].info=G.arcs[j][i+1].info;
		}
	}

	for(j=0;j<G.vexnum;j++)//����ָ���ÿ�
	{
		if(G.arcs[i][j].info!=NULL)
			G.arcs[i][j].adj=NULL;
		if(G.arcs[j][i].info!=NULL)
			G.arcs[j][i].info=NULL;
	}

	G.arcnum-=count;
	G.vexnum--;
	return OK;
}

Status InertArc(MGraph &G,VertexType v,VertexType w,int weight)
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
		if(G.vexs[i]==v)
			break;
	for(j=0;j<G.vexnum;j++)
		if(G.vexs[j]==w)
			break;
	if(i>=G.vexnum || j>=G.vexnum || G.arcs[i][j].adj!=0)
		return FALSE;
	switch(G.kind)
	{
	case UDG:
		G.arcs[j][i].adj=1;
	case DG:
		G.arcs[i][j].adj=1;
		G.arcnum++;
		break;
	case UDN:
		G.arcs[j][i].adj=weight;
	case DN:
		G.arcs[i][j].adj=weight;
		G.arcnum++;
		break;
	default:
		return FALSE;
	}
	return OK;
}

Status DeleteArc(MGraph &G,VertexType v,VertexType w)
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
		if(G.vexs[i]==v)
			break;
	for(j=0;j<G.vexnum;j++)
		if(G.vexs[j]==w)
			break;
	if(i>=G.vexnum || j>=G.vexnum || G.arcs[i][j].adj==0)
		return FALSE;
	switch(G.kind)
	{
	case DG:
	case DN:
		G.arcs[i][j].adj=0;
		G.arcnum--;
		break;
	case UDG:
	case UDN:
		G.arcs[i][j].adj=0;
		G.arcs[j][i].adj=0;
		G.arcnum--;
		break;
	default:
		break;
	}
	return OK;
}

void DFS(MGraph G,int i,void (*Visit)(VertexType),bool visit[]);//�������
Status DFSTraverse(MGraph G,void (*Visit)(VertexType))
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

void DFS(MGraph G,int i,void (*Visit)(VertexType),bool visit[])
{
	int j;
	visit[i]=1;
	Visit(G.vexs[i]);
	for(j=0;j<i;j++)
		if(G.arcs[i][j].adj!=0 && 0==visit[j])
			DFS(G,j,Visit,visit);
}

Status BFSTraverse(MGraph G,void (*Visit)(VertexType))
{
	int i,j,p;//pΪ�α�
	bool visit[MAX_VERTEX_NUM];//���ʱ��
	int queue[MAX_VERTEX_NUM];//����
	int front,rear;

	for(i=0;i<MAX_VERTEX_NUM;i++)
		visit[i]=0;

	front=rear=0;
	for(i=0;i<G.vexnum;i++)
		if(0==visit[i])
		{
			queue[(rear++)%MAX_VERTEX_NUM]=i;
			visit[i]=1;
			while(front!=rear)
			{
				p=queue[(front++)%MAX_VERTEX_NUM];
				Visit(G.vexs[p]);
				for(j=0;j<G.vexnum;j++)
					if(G.arcs[p][j].adj!=0 && 0==visit[j])
					{
						queue[(rear++)%MAX_VERTEX_NUM]=j;
						visit[j]=1;
					}
			}
		}
	return OK;
}