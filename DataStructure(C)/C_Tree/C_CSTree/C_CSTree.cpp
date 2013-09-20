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

	printf("������:");
	CreateTree(T,Nil);
	CreateTree(C,Nil);
	printf("\nǰ���󡢲������:");
	PreOrderTraverse(T,Visit);
	printf("\n");
	PostOrderTraverse(T,Visit);
	printf("\n");
	LevelOrderTraverse(T,Visit);
	printf("\nǰ���󡢲������:");
	PreOrderTraverse(C,Visit);
	printf("\n");
	PostOrderTraverse(C,Visit);
	printf("\n");
	LevelOrderTraverse(C,Visit);

	printf("\n����:%c",Root(T));
	printf("\n����c:");
	scanf("%c%*c",&c);
	printf("\n��ֵ:%c",(tempe=Value(T,c)));
	printf("\n��ֵ:");
	scanf("%c%*c",&e);
	Assign(T,tempe,e);
	printf("\n���ڵ㡢���ӡ����ֵܣ��������:");
	p=Parent(T,e);
	printf("%c ",p==NULL?Nil:p->e);
	p=LeftChild(T,e);
	printf("%c ",p==NULL?Nil:p->e);
	p=RightSibling(T,e);
	printf("%c ",p==NULL?Nil:p->e);
	printf("%d %d",TreeDepth(T),TreeEmpty(T));
	printf("\n��������:");
	InsertChild(T,e,1,C);
	printf("\nǰ���󡢲������:");
	PreOrderTraverse(T,Visit);
	printf("\n");
	PostOrderTraverse(T,Visit);
	printf("\n");
	LevelOrderTraverse(T,Visit);
	printf("\nɾ�������:");
	DeleteChild(T,e,1);
	printf("\nǰ���󡢲������:");
	PreOrderTraverse(T,Visit);
	printf("\n");
	PostOrderTraverse(T,Visit);
	printf("\n");
	LevelOrderTraverse(T,Visit);

	DestroyTree(T);
	return 0;
}