#define TEST 0 //ǰ������������ݹ�1;���Ѵ������ǵݹ�0
#define TEST2 1//
#include"C_BiTree_Basic.h"

extern char Nil;
void Visit(TElemType e)
{
	printf("%c",e);
}
//SqBiTree�Ĳ��Գ���
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

	printf("�������ݴ���������(#��ʾ��):");
	scanf("%s%*c",buf);
	temp=buf;
	CreateBiTree(T,temp,i);

	printf("\n����(ǰ���С��󡢲�):");
	PreOrderTraverse(T,Visit);
	printf("\n");
	InOrderTraverse(T,Visit);
	printf("\n");
	PostOrderTraverse(T,Visit);
	printf("\n");
	LevelOrderTraverse(T,Visit);

	printf("\n�������Ƿ�Ϊ��:%s",BiTreeEmpty(T)==1?"��":"�ǿ�");
	printf("\n�������:%d",BiTreeDepth(T));

	printf("\n���ڵ�����ӡ�˫�ס����Һ��ӡ������ֵܽڵ�");
	q=LeftChild(T,*T);
	printf("\n%c %c %c %c %c %c",q==NULL?Nil:q->e,(q2=Parent(T,*q))==NULL?Nil:q2->e,(q2=LeftChild(T,*q))==NULL?Nil:q2->e,
		(q2=RightChild(T,*q))==NULL?Nil:q2->e,(q2=LeftSibling(T,*q))==NULL?Nil:q2->e,
		(q2=RightSibling(T,*q))==NULL?Nil:q2->e);
	
	printf("\n�ڵ����ֵ:");
	scanf("%c%*c",&newe);
	Assign(T,*q,newe);

	printf("\n�滻�����(ǰ���С��󡢲�):");
	PreOrderTraverse(T,Visit);
	printf("\n");
	InOrderTraverse(T,Visit);
	printf("\n");
	PostOrderTraverse(T,Visit);
	printf("\n");
	LevelOrderTraverse(T,Visit);

	printf("\n�������ݴ���������(#��ʾ��):");
	scanf("%s%*c",buf);
	temp=buf;
	i=0;
	CreateBiTree(C,temp,i);
	printf("\n����Ҫ�������ݵĲ㡢��ź���������(0��1��):");
	scanf("%d%d%d%*c",&p.level,&p.order,&k);
	InsertChild(T,p,k,C);
	
	printf("\n����(ǰ���С��󡢲�):");
	PreOrderTraverse(T,Visit);
	printf("\n");
	InOrderTraverse(T,Visit);
	printf("\n");
	PostOrderTraverse(T,Visit);
	printf("\n");
	LevelOrderTraverse(T,Visit);

	printf("\nɾ��%d��%d���ڵ�������������:",p.level,p.order);
	DeleteChild(T,p,1);

	printf("\n����(ǰ���С��󡢲�):");
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
