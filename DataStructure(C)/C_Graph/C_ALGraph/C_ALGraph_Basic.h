#ifndef C_ALGraph_Basic_2013_2_11_10_35
#define C_ALGraph_Basic_2013_2_11_10_35
//#pragma once
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
typedef int Status;
//图的邻接表表示
#define MAX_VERTEX_NUM 26
typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef int InfoType;
typedef char VertexType;
typedef struct ArcNode
{
	int adjvex;//弧指向的顶点位置
	InfoType *info;//弧的信息
	struct ArcNode *nextarc;//下一条弧
}ArcNode;//弧节点类型
typedef struct
{
	VertexType data;//顶点
	ArcNode *firstarc;//第一条邻接弧
}VexNode,AdjList[MAX_VERTEX_NUM];//头节点类型(即顶点类型)
typedef struct
{
	AdjList vertices;
	int vexnum,arcnum;//顶点数、弧数
	GraphKind kind;
}ALGraph;

Status CreateGraph(ALGraph &G);
Status DestroyGraph(ALGraph &G);
int LocateVex(ALGraph G,VertexType u);
VertexType GetVex(ALGraph G,int v);
Status PutVex(ALGraph &G,VertexType v,VertexType value);
int FirstAdjVex(ALGraph G,VertexType v);
int NextAdjVex(ALGraph G,VertexType v,VertexType w);
Status InsertVex(ALGraph &G,VertexType v);
Status DeleteVex(ALGraph &G,VertexType v);
Status InsertArc(ALGraph &G,VertexType v,VertexType w,int weight);
Status DeleteArc(ALGraph &G,VertexType v,VertexType w);
Status DFSTraverse(ALGraph G,void (*Visit)(VertexType));
Status BFSTraverse(ALGraph G,void (*Visit)(VertexType));

#endif