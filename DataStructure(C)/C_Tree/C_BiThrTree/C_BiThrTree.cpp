#include"C_BiThrTree_Basic.h"
#include<stdio.h>

void visit(TElemType e)
{
#if CHAR
	printf("%c",e);
#else
	printf("%d",e);
#endif
}

int main(int argc,char *argv[])
{
	BiThrTree Thr;
	printf("创建线索二叉树,输入数据(#表示空):");
	CreateBiThrTree(Thr);
	printf("\n中序遍历线索二叉树:");
	InOrderTraverse_Thr(Thr,visit);
	DestroyBiThrTree(Thr);
	return 0;
}