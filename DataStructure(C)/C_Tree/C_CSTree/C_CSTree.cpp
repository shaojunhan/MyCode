#define TEST 1
#include"C_CSTree_Basic.h"
#include<stdio.h>

extern char Nil;
void Visit(TElemType e)
{
	printf("%c",e);
}
int main(int argc,char *argv[])
{
	char c;
	TElemType e,tempe;
	CSTree T,C;
	CSTree p;

	InitTree(T);
	InitTree(C);

	printf("创建树:");
	CreateTree(T,Nil);
	CreateTree(C,Nil);
	printf("\n前、后、层遍历树:");
	PreOrderTraverse(T,Visit);
	printf("\n");
	PostOrderTraverse(T,Visit);
	printf("\n");
	LevelOrderTraverse(T,Visit);
	printf("\n前、后、层遍历树:");
	PreOrderTraverse(C,Visit);
	printf("\n");
	PostOrderTraverse(C,Visit);
	printf("\n");
	LevelOrderTraverse(C,Visit);

	printf("\n树根:%c",Root(T));
	printf("\n输入c:");
	scanf("%c%*c",&c);
	printf("\n求值:%c",(tempe=Value(T,c)));
	printf("\n赋值:");
	scanf("%c%*c",&e);
	Assign(T,tempe,e);
	printf("\n父节点、左孩子、右兄弟，树深、树空:");
	p=Parent(T,e);
	printf("%c ",p==NULL?Nil:p->e);
	p=LeftChild(T,e);
	printf("%c ",p==NULL?Nil:p->e);
	p=RightSibling(T,e);
	printf("%c ",p==NULL?Nil:p->e);
	printf("%d %d",TreeDepth(T),TreeEmpty(T));
	printf("\n插入后遍历:");
	InsertChild(T,e,1,C);
	printf("\n前、后、层遍历树:");
	PreOrderTraverse(T,Visit);
	printf("\n");
	PostOrderTraverse(T,Visit);
	printf("\n");
	LevelOrderTraverse(T,Visit);
	printf("\n删除后遍历:");
	DeleteChild(T,e,1);
	printf("\n前、后、层遍历树:");
	PreOrderTraverse(T,Visit);
	printf("\n");
	PostOrderTraverse(T,Visit);
	printf("\n");
	LevelOrderTraverse(T,Visit);

	DestroyTree(T);
	return 0;
}