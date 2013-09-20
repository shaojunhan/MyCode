#ifndef C_OLGraph_Basic_2013_2_12_9_07
#define C_OLGraph_Basic_2013_2_12_9_07
//#pragma once
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
typedef int Status;
//����ͼ��ʮ�������ʾ
#define MAX_VERTEX_NUM 26
typedef int InfoType;
typedef char VertexType;
typedef struct ArcBox
{
	int tailvex,headvex;//�ֱ�ָʾ��β����ͷ�ڱ��е�λ��
	struct ArcBox *tlink,*hlink;//tlink��hlink�ֱ�ָʾ��β����ͷ��ͬ����һ����
	InfoType *info;
}ArcBox;//��������
typedef struct VexNode
{
	VertexType data;
	ArcBox *firstin,*firstout;//�Ըö���Ϊ��ͷ����β�ĵ�һ������
}VexNode;//��������
typedef struct
{
	VexNode xlist[MAX_VERTEX_NUM];//���㼯
	int vexnum,arcnum;//������������
//��Ϊ������ͼ������û����ͼ����������
}OLGraph;//����ͼ����

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