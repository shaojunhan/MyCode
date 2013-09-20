#ifndef C_MGraph_Basic_2013_2_9_19_28
#define C_MGraph_Basic_2013_2_9_19_28
//#pragma once
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
typedef int Status;
//����ͼ:UndiGraph
//����ͼ:DiGraph
//������:DiNetwork
//������:UndiNetwork
//��:Arc
//����:Vertex
#include<limits.h>
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 26
typedef char InfoType;
typedef int VRType;
typedef char VertexType;
typedef enum {DG,DN,UDG,UDN}GraphKind;//ͼ������
typedef struct
{
	VRType adj;//�����ϵ���� 
	InfoType *info;//����Ϣ
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//��
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];//��������
	AdjMatrix arcs;//�ڽӾ���
	int arcnum,vexnum;//������������
	GraphKind kind;
}MGraph;//ͼ(�����ʾ)

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