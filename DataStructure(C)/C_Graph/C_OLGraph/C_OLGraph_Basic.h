#ifndef C_OLGraph_Basic_2013_2_12_9_07
#define C_OLGraph_Basic_2013_2_12_9_07
//#pragma once
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
typedef int Status;
//有向图的十字链表表示
#define MAX_VERTEX_NUM 26
typedef int InfoType;
typedef char VertexType;
typedef struct ArcBox
{
	int tailvex,headvex;//分别指示弧尾、弧头在表中的位置
	struct ArcBox *tlink,*hlink;//tlink、hlink分别指示弧尾、弧头相同的下一条弧
	InfoType *info;
}ArcBox;//弧的类型
typedef struct VexNode
{
	VertexType data;
	ArcBox *firstin,*firstout;//以该顶点为弧头、弧尾的第一个顶点
}VexNode;//顶点类型
typedef struct
{
	VexNode xlist[MAX_VERTEX_NUM];//顶点集
	int vexnum,arcnum;//顶点数、弧数
//因为是有向图，所以没有了图的种类属性
}OLGraph;//有向图类型

Status CreateGraph(OLGraph &G);
Status DestroyGraph(OLGraph &G);
int LocateVex(OLGraph G,VertexType u);
VertexType GetVex(OLGraph G,int v);
Status PutVex(OLGraph &G,VertexType v,VertexType value);
int FirstAdjVex(OLGraph G,VertexType v);
int NextAdjVex(OLGraph G,VertexType v,VertexType w);
Status InsertVex(OLGraph &G,VertexType v);
Status DeleteVex(OLGraph &G,VertexType v);
Status InsertArc(OLGraph &G,VertexType v,VertexType w);
Status DeleteArc(OLGraph &G,VertexType v,VertexType w);
Status DFSTraverse(OLGraph G,void (*Visit)(VertexType));
Status BFSTraverse(OLGraph G,void (*Visit)(VertexType));
#endif