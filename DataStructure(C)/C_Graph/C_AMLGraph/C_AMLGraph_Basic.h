#ifndef C_AMLGraph_Basic_2013_2_14_12_03
#define C_AMLGraph_Basic_2013_2_14_12_03
//#pragma once
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
typedef int Status;
//无向图的邻接多重表表示
//简单无向图、无自回路
#define MAX_VERTEX_NUM 26
typedef int InfoType;
typedef char VertexType;
typedef struct EBox
{
	int mark;
	int ivex,jvex;
	struct EBox *ilink,*jlink;
	InfoType *info;
}EBox;
typedef struct VexBox
{
	VertexType data;
	EBox *firstedge;
}VexBox;
typedef struct
{
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vexnum,edgenum;
}AMLGraph;

Status CreateGraph(AMLGraph &G);
Status DestroyGraph(AMLGraph &G);
int LocateVex(AMLGraph G,VertexType v);
VertexType GetVex(AMLGraph G,int v);
Status PutVex(AMLGraph &G,VertexType v,VertexType value);
int FirstAdjVex(AMLGraph G,VertexType v);
int NextAdjVex(AMLGraph G,VertexType v,VertexType w);
Status InsertVex(AMLGraph &G,VertexType v);
Status DeleteVex(AMLGraph &G,VertexType v);
Status InsertArc(AMLGraph &G,VertexType v,VertexType w);
Status DeleteArc(AMLGraph &G,VertexType v,VertexType w);
Status DFSTraverse(AMLGraph G,void (*Visit)(VertexType));
Status BFSTraverse(AMLGraph G,void (*Visit)(VertexType));
#endif