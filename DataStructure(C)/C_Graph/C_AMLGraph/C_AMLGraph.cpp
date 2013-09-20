#include"C_AMLGraph_Basic.h"
#include<stdio.h>
#include<stdlib.h>

void visit(VertexType e);
int main(int argc,char *argv[])
{
	char vertex_test1,vertex_test2;
	int cur;
	AMLGraph G;
	printf("--------------创建图(邻接矩阵表示)---------");
	CreateGraph(G);
	printf("\n遍历(深度、广度):");
	DFSTraverse(G,visit);
	putchar('\n');
	BFSTraverse(G,visit);

	printf("\n输入顶点:");
	scanf("%c%*c",&vertex_test1);
	printf("顶点%c所在位置:%d",vertex_test1,cur=LocateVex(G,vertex_test1));
	printf("其值为%c:",GetVex(G,cur));
	printf("\n结点赋予新值,输入新值:");
	scanf("%c%*c",&vertex_test2);
	PutVex(G,vertex_test1,vertex_test2);
	printf("\n遍历(深度、广度):");
	DFSTraverse(G,visit);
	putchar('\n');
	BFSTraverse(G,visit);


	printf("\n%c的第一个邻接点位置:%d",vertex_test2,(cur=FirstAdjVex(G,vertex_test2)));
	if(cur!=-1)
	{
		vertex_test1=G.adjmulist[cur].data;
		printf("\n下一个邻接点位置:%d",NextAdjVex(G,vertex_test2,vertex_test1));
	}
	printf("\n插入新的结点:");
	scanf("%c%*c",&vertex_test1);
	InsertVex(G,vertex_test1);
	printf("\n插入新的邻接边:");
	InsertArc(G,vertex_test2,vertex_test1);
	printf("\n遍历(深度、广度):");
	DFSTraverse(G,visit);
	putchar('\n');
	BFSTraverse(G,visit);

	printf("\n删除邻接边!");
	DeleteArc(G,vertex_test1,vertex_test2);
	printf("\n遍历(深度、广度):");
	DFSTraverse(G,visit);
	putchar('\n');
	BFSTraverse(G,visit);

	printf("\n删除顶点!");
	InsertArc(G,vertex_test1,vertex_test2);
	DeleteVex(G,vertex_test1);
	printf("\n遍历(深度、广度):");
	DFSTraverse(G,visit);
	putchar('\n');
	BFSTraverse(G,visit);

	DestroyGraph(G);
	system("pause");
	return 0;
}

void visit(VertexType e)
{
	printf("%c",e);
}
