#ifndef C_ALGraph_2013_2_15_16_20
#define C_ALGraph_2013_2_15_16_20
//#pragma once
//adjacent adj邻近的
//list n 列表

#define MAX_VERTEX_NUM 26
typedef enum{DG,DN,UDG,UDN}GraphKind;
typedef int InfoType;
typedef char VertexType;
typedef struct ArcNode
{
	int adjvex;
	InfoType info;
	struct ArcNode *next;
}ArcNode;
typedef struct
{
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct
{
	AdjList vertices;
	int vexnum,arcnum;
	GraphKind kind;
}ALGraph;
#endif