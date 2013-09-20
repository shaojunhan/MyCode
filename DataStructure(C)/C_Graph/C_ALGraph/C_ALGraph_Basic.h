#ifndef C_ALGraph_Basic_2013_2_11_10_35
#define C_ALGraph_Basic_2013_2_11_10_35
//#pragma once
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
typedef int Status;
//ͼ���ڽӱ��ʾ
#define MAX_VERTEX_NUM 26
typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef int InfoType;
typedef char VertexType;
typedef struct ArcNode
{
	int adjvex;//��ָ��Ķ���λ��
	InfoType *info;//������Ϣ
	struct ArcNode *nextarc;//��һ����
}ArcNode;//���ڵ�����
typedef struct
{
	VertexType data;//����
	ArcNode *firstarc;//��һ���ڽӻ�
}VexNode,AdjList[MAX_VERTEX_NUM];//ͷ�ڵ�����(����������)
typedef struct
{
	AdjList vertices;
	int vexnum,arcnum;//������������
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