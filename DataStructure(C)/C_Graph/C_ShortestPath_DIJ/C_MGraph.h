#ifndef C_MGraph_2013_2_19_12_50
#define C_MGraph_2013_2_19_12_50
//#pragma once
#define MAX_VERTEX_NUM 26
typedef enum{DG,DN,UDG,UDN}GraphKind;
typedef int VRType;
typedef int InfoType;
typedef char VertexType;
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
	GraphKind kind;
}MGraph;
#endif