#ifndef C_ALGraph_2013_2_16_16_18
#define C_ALGraph_2013_2_16_16_18
//#pragma once
#define MAX_VERTEX_NUM 26
enum GraphKind{DG,DN,UDG,UDN};
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
	enum GraphKind kind;
}ALGraph;
#endif