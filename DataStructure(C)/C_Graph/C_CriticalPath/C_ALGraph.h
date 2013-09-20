#ifndef C_ALGraph_2013_2_17_13_52
#define C_ALGraph_2013_2_17_13_52
//#pragma once
#define MAX_VERTEX_NUM 26
typedef enum{DG,DN,UDG,UDN}GraphKind; 
typedef int InfoType;
typedef char VertexType;
typedef struct ArcNode
{
	int adjvex;
	InfoType info;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct
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