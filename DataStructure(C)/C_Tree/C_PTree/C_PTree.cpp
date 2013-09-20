#include"C_PTree_Basic.h"
#include<stdio.h>

void Visit(TElemType e)
{
	printf("%c",e);
}
int main(int argc,char *argv[])
{
	int i;
	TElemType e,tempe;
	PTree T,C;

	InitTree(T);
	InitTree(C);

	printf("������:");
	CreateTree(T);
	CreateTree(C);
	printf("\n������:");
	TraverseTree(T,Visit);
	printf("\n");
	TraverseTree(C,Visit);

	printf("\n����:%c",Root(T));
	printf("\n����i:");
	scanf("%d%*c",&i);
	printf("\n��ֵ:%c",(tempe=Value(T,i)));
	printf("\n��ֵ:");
	scanf("%c%*c",&e);
	Assign(T,tempe,e);
	printf("\n���ڵ㡢���ӡ����ֵܣ��������:%c %c %c %d %d",
		
		Value(T,Parent(T,e)),
		Value(T,LeftChild(T,e)),Value(T,RightSibling(T,e)),
		TreeDepth(T),TreeEmpty(T));
	printf("\n��������:");
	InsertChild(T,e,1,C);
	TraverseTree(T,Visit);
	printf("\nɾ�������:");
	DeleteChild(T,e,1);
	TraverseTree(T,Visit);

	DestroyTree(T);
	DestroyTree(C);
	return 0;
}
