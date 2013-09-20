#ifndef C_MGraph_Basic_2013_2_9_19_28
#define C_MGraph_Basic_2013_2_9_19_28
//#pragma once
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
typedef int Status;
//无向图:UndiGraph
//有向图:DiGraph
//有向网:DiNetwork
//无向网:UndiNetwork
//边:Arc
//顶点:Vertex
#include<limits.h>
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 26
typedef char InfoType;
typedef int VRType;
typedef char VertexType;
typedef enum {DG,DN,UDG,UDN}GraphKind;//图的类型
typedef struct
{
	VRType adj;//顶点关系类型 
	InfoType *info;//弧信息
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//弧
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];//顶点类型
	AdjMatrix arcs;//邻接矩阵
	int arcnum,vexnum;//弧数、顶点数
	GraphKind kind;
}MGraph;//图(数组表示)

Status CreateGraph(MGraph &G);
Status DestroyGraph(MGraph &G);
int LocateVex(MGraph G,VertexType u);
VertexType GetVex(MGraph G,VertexType v);
Status PutVex(MGraph &G,VertexType v,VertexType value);
int FirstAdjVex(MGraph G,VertexType v);
int NextAdjVex(MGraph G,VertexType v,VertexType w);
Status InsertVex(MGraph &G,VertexType v);
Status DeleteVex(MGraph &G,VertexType v);
Status InertArc(MGraph &G,VertexType v,VertexType w,int weight);
Status DeleteArc(MGraph &G,VertexType v,VertexType w);
Status DFSTraverse(MGraph G,void (*Visit)(VertexType));
Status BFSTraverse(MGraph G,void (*Visit)(VertexType));

#endif