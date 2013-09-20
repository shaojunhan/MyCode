#define TEST 0 //前序遍历创建、递归1;广搜创建、非递归0
#define TEST2 1//
#include"C_BiTree_Basic.h"

extern char Nil;
void Visit(TElemType e)
{
	printf("%c",e);
}
//SqBiTree的测试程序
int main(int argc,char *argv[])
{
	int i=0;
	char buf[1024];
	char e,newe;
	char *temp;
	bool k;
	position p;
	BiTree T,C;
	BiTree q,q2;

	InitBiTree(T);
	InitBiTree(C);

	printf("输入数据创建二叉树(#表示空):");
	scanf("%s%*c",buf);
	temp=buf;
	CreateBiTree(T,temp,i);

	printf("\n遍历(前、中、后、层):");
	PreOrderTraverse(T,Visit);
	printf("\n");
	InOrderTraverse(T,Visit);
	printf("\n");
	PostOrderTraverse(T,Visit);
	printf("\n");
	LevelOrderTraverse(T,Visit);

	printf("\n二叉树是否为空:%s",BiTreeEmpty(T)==1?"空":"非空");
	printf("\n树的深度:%d",BiTreeDepth(T));

	printf("\n根节点的左孩子、双亲、左右孩子、左右兄弟节点");
	q=LeftChild(T,*T);
	printf("\n%c %c %c %c %c %c",q==NULL?Nil:q->e,(q2=Parent(T,*q))==NULL?Nil:q2->e,(q2=LeftChild(T,*q))==NULL?Nil:q2->e,
		(q2=RightChild(T,*q))==NULL?Nil:q2->e,(q2=LeftSibling(T,*q))==NULL?Nil:q2->e,
		(q2=RightSibling(T,*q))==NULL?Nil:q2->e);
	
	printf("\n节点的新值:");
	scanf("%c%*c",&newe);
	Assign(T,*q,newe);

	printf("\n替换后遍历(前、中、后、层):");
	PreOrderTraverse(T,Visit);
	printf("\n");
	InOrderTraverse(T,Visit);
	printf("\n");
	PostOrderTraverse(T,Visit);
	printf("\n");
	LevelOrderTraverse(T,Visit);

	printf("\n输入数据创建二叉树(#表示空):");
	scanf("%s%*c",buf);
	temp=buf;
	i=0;
	CreateBiTree(C,temp,i);
	printf("\n输入要插入数据的层、序号和左右子树(0左1右):");
	scanf("%d%d%d%*c",&p.level,&p.order,&k);
	InsertChild(T,p,k,C);
	
	printf("\n遍历(前、中、后、层):");
	PreOrderTraverse(T,Visit);
	printf("\n");
	InOrderTraverse(T,Visit);
	printf("\n");
	PostOrderTraverse(T,Visit);
	printf("\n");
	LevelOrderTraverse(T,Visit);

	printf("\n删除%d层%d个节点的右子树后遍历:",p.level,p.order);
	DeleteChild(T,p,1);

	printf("\n遍历(前、中、后、层):");
	PreOrderTraverse(T,Visit);
	printf("\n");
	InOrderTraverse(T,Visit);
	printf("\n");
	PostOrderTraverse(T,Visit);
	printf("\n");
	LevelOrderTraverse(T,Visit);

	DestroyBiTree(T);
	system("pause");
	return 0;
}
