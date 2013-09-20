//#ifndef C_MGraph_2013_2_19_15_18
//#define C_MGraph_2013_2_19_15_18
#pragma once
#define MAX_VERTEX_NUM 26
typedef int VRType;
typedef int InfoType;
typedef char VertexType;
enum GraphKind{DG,DN,UDG,UDN};
typedef struct
{
	VRType adj;
	InfoType *info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum,arcnum;
	enum GraphKind kind;
}MGraph;
//#endif