#ifndef C_MGraph_2013_2_15_20_17
#define C_MGraph_2013_2_15_20_17
//#pragma once
//图的矩阵(数组)表示
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 26
enum GraphKind{DG,DN,UDG,UDN};
typedef int InfoType;
typedef char VertexType;
typedef struct
{
	bool adj;
	InfoType info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum,arcnum;
	enum GraphKind kind;
}MGraph;
#endif