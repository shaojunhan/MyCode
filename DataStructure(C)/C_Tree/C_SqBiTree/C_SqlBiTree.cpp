#include"C_SqBiTree_Basic.h"
#include<stdio.h>
#include<stdlib.h>
void Visit(TElemType e)
{
	printf("%c",e);
}
//SqBiTree�Ĳ��Գ���
int main(int argc,char *argv[])
{
	char buf[1024];
	char e,newe;
	bool k;
	position p;
	SqBiTree T,C;

	InitBiTree(T);
	InitBiTree(C);

	printf("�������ݴ���������(#��ʾ��),����С��%d:",MAX_SIZE);
	scanf("%s%*c",buf);
	CreateBiTree(T,buf);

	printf("\nǰ��,����,�������Ϊ:");
	PreOrderTraverse(T,Visit);
	printf("\n");
	InOrderTraverse(T,Visit);
	printf("\n");
	PostOrderTraverse(T,Visit);

	printf("\n��α���:");
	LevelOrderTraverse(T,Visit);

	printf("\n�������Ƿ�Ϊ��:%s",BiTreeEmpty(T)==1?"��":"�ǿ�");
	printf("\n�������:%d",BiTreeDepth(T));

	printf("\n˫�ס����Һ��ӡ������ֵܽڵ�");
	printf("\n����ڵ�:");
	scanf("%c%*c",&e);
	printf("\n%c %c %c %c %c%*c",Parent(T,e),LeftChild(T,e),RightChild(T,e),LeftSibling(T,e),RightSibling(T,e));
	
	printf("\n�ڵ����ֵ:");
	scanf("%c%*c",&newe);
	Assign(T,e,newe);
	printf("\n�滻�����:");
	PreOrderTraverse(T,Visit);

	printf("\n�������ݴ���������(#��ʾ��),����С��%d:",MAX_SIZE);
	scanf("%s%*c",buf);
	CreateBiTree(C,buf);
	printf("\n����Ҫ�������ݵĲ㡢��ź���������(0��1��):");
	scanf("%d%d%d%*c",&p.level,&p.order,&k);
	InsertChild(T,p,k,C);
	printf("\n����:");
	PreOrderTraverse(T,Visit);

	printf("\nɾ��%d��%d���ڵ�����������:",p.level,p.order);
	DeleteChild(T,p,1);
	PreOrderTraverse(T,Visit);
	printf("\n��α���:");
	LevelOrderTraverse(T,Visit);

	ClearBiTree(T);
	system("pause");
	return 0;
}
