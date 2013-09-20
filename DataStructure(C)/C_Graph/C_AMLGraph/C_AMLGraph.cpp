#include"C_AMLGraph_Basic.h"
#include<stdio.h>
#include<stdlib.h>

void visit(VertexType e);
int main(int argc,char *argv[])
{
	char vertex_test1,vertex_test2;
	int cur;
	AMLGraph G;
	printf("--------------����ͼ(�ڽӾ����ʾ)---------");
	CreateGraph(G);
	printf("\n����(��ȡ����):");
	DFSTraverse(G,visit);
	putchar('\n');
	BFSTraverse(G,visit);

	printf("\n���붥��:");
	scanf("%c%*c",&vertex_test1);
	printf("����%c����λ��:%d",vertex_test1,cur=LocateVex(G,vertex_test1));
	printf("��ֵΪ%c:",GetVex(G,cur));
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
		vertex_test1=G.adjmulist[cur].data;
		printf("\n��һ���ڽӵ�λ��:%d",NextAdjVex(G,vertex_test2,vertex_test1));
	}
	printf("\n�����µĽ��:");
	scanf("%c%*c",&vertex_test1);
	InsertVex(G,vertex_test1);
	printf("\n�����µ��ڽӱ�:");
	InsertArc(G,vertex_test2,vertex_test1);
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
	InsertArc(G,vertex_test1,vertex_test2);
	DeleteVex(G,vertex_test1);
	printf("\n����(��ȡ����):");
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
