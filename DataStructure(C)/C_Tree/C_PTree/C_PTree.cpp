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

	printf("创建树:");
	CreateTree(T);
	CreateTree(C);
	printf("\n遍历树:");
	TraverseTree(T,Visit);
	printf("\n");
	TraverseTree(C,Visit);

	printf("\n树根:%c",Root(T));
	printf("\n输入i:");
	scanf("%d%*c",&i);
	printf("\n求值:%c",(tempe=Value(T,i)));
	printf("\n赋值:");
	scanf("%c%*c",&e);
	Assign(T,tempe,e);
	printf("\n父节点、左孩子、右兄弟，树深、树空:%c %c %c %d %d",
		
		Value(T,Parent(T,e)),
		Value(T,LeftChild(T,e)),Value(T,RightSibling(T,e)),
		TreeDepth(T),TreeEmpty(T));
	printf("\n插入后遍历:");
	InsertChild(T,e,1,C);
	TraverseTree(T,Visit);
	printf("\n删除后遍历:");
	DeleteChild(T,e,1);
	TraverseTree(T,Visit);

	DestroyTree(T);
	DestroyTree(C);
	return 0;
}
