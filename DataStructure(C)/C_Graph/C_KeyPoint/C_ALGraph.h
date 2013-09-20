#ifndef C_ALGraph_2013_2_16_13_28
#define C_ALGraph_2013_2_16_13_28
//#pragma once
#define MAX_VERTEX_NUM 26
typedef enum{DG,DN,UDG,UDN}GraphKind;
typedef int InfoType;
typedef char VertexType;
typedef struct ArcNode
{
	int adjvex;
	InfoType *info;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct VBox
{
	VertexType data;
	ArcNode *firstarc;
}VBox;
typedef struct
{
	VBox vertices[MAX_VERTEX_NUM];
	int vexnum,arcnum;
	GraphKind kind;
}ALGraph;
#endif