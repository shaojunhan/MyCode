#include"C_SqBiTree_Basic.h"
#include<stdio.h>
#include<stdlib.h>
void Visit(TElemType e)
{
	printf("%c",e);
}
//SqBiTree的测试程序
int main(int argc,char *argv[])
{
	char buf[1024];
	char e,newe;
	bool k;
	position p;
	SqBiTree T,C;

	InitBiTree(T);
	InitBiTree(C);

	printf("输入数据创建二叉树(#表示空),长度小于%d:",MAX_SIZE);
	scanf("%s%*c",buf);
	CreateBiTree(T,buf);

	printf("\n前序,中序,后序遍历为:");
	PreOrderTraverse(T,Visit);
	printf("\n");
	InOrderTraverse(T,Visit);
	printf("\n");
	PostOrderTraverse(T,Visit);

	printf("\n层次遍历:");
	LevelOrderTraverse(T,Visit);

	printf("\n二叉树是否为空:%s",BiTreeEmpty(T)==1?"空":"非空");
	printf("\n树的深度:%d",BiTreeDepth(T));

	printf("\n双亲、左右孩子、左右兄弟节点");
	printf("\n输入节点:");
	scanf("%c%*c",&e);
	printf("\n%c %c %c %c %c%*c",Parent(T,e),LeftChild(T,e),RightChild(T,e),LeftSibling(T,e),RightSibling(T,e));
	
	printf("\n节点的新值:");
	scanf("%c%*c",&newe);
	Assign(T,e,newe);
	printf("\n替换后遍历:");
	PreOrderTraverse(T,Visit);

	printf("\n输入数据创建二叉树(#表示空),长度小于%d:",MAX_SIZE);
	scanf("%s%*c",buf);
	CreateBiTree(C,buf);
	printf("\n输入要插入数据的层、序号和左右子树(0左1右):");
	scanf("%d%d%d%*c",&p.level,&p.order,&k);
	InsertChild(T,p,k,C);
	printf("\n遍历:");
	PreOrderTraverse(T,Visit);

	printf("\n删除%d层%d个节点的子树后遍历:",p.level,p.order);
	DeleteChild(T,p,1);
	PreOrderTraverse(T,Visit);
	printf("\n层次遍历:");
	LevelOrderTraverse(T,Visit);

	ClearBiTree(T);
	system("pause");
	return 0;
}
