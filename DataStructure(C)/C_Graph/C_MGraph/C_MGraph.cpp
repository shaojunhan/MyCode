#include"C_MGraph_Basic.h"
#include<stdio.h>

void visit(VertexType e);
int main(int argc,char *argv[])
{
	char vertex_test1,vertex_test2;
	int cur;
	MGraph G;
	printf("--------------����ͼ(�ڽӾ����ʾ)---------");
	CreateGraph(G);
	printf("\n����(��ȡ����):");
	DFSTraverse(G,visit);
	putchar('\n');
	BFSTraverse(G,visit);

	printf("\n���붥��:");
	scanf("%c%*c",&vertex_test1);
	printf("����%c����λ��:%d",vertex_test1,LocateVex(G,vertex_test1));
	printf("��ֵΪ%c:",GetVex(G,vertex_test1));
	printf("\n��㸳����ֵ,������ֵ:");
	scanf("%c%*c",&vertex_test2);
	PutVex(G,vertex_test1,vertex_test2);
	printf("\n����(��ȡ����):");
	DFSTraverse(G,visit);
	putchar('\n');
	BFSTraverse(G,visit);


	printf("\n%c�ĵ�һ���ڽӵ�λ��:%d",vertex_test2,(cur=FirstAdjVex(G,vertex_test2)));
	if(cur!=-1)
	{
		vertex_test1=G.vexs[cur];
		printf("\n��һ���ڽӵ�λ��:%d",NextAdjVex(G,vertex_test2,vertex_test1));
	}
	printf("\n�����µĽ��:");
	scanf("%c%*c",&vertex_test1);
	InsertVex(G,vertex_test1);
	printf("\n�����µ��ڽӱ�:");
	InertArc(G,vertex_test1,vertex_test2,1);
	printf("\n����(��ȡ����):");
	DFSTraverse(G,visit);
	putchar('\n');
	BFSTraverse(G,visit);

	printf("\nɾ���ڽӱ�!");
	DeleteArc(G,vertex_test1,vertex_test2);
	printf("\n����(��ȡ����):");
	DFSTraverse(G,visit);
	putchar('\n');
	BFSTraverse(G,visit);

	printf("\nɾ������!");
	DeleteVex(G,vertex_test1);
	printf("\n����(��ȡ����):");
	DFSTraverse(G,visit);
	putchar('\n');
	BFSTraverse(G,visit);

	DestroyGraph(G);
	return 0;
}

void visit(VertexType e)
{
	printf("%c",e);
}
