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
	printf("��������������,��������(#��ʾ��):");
	CreateBiThrTree(Thr);
	printf("\n�����������������:");
	InOrderTraverse_Thr(Thr,visit);
	DestroyBiThrTree(Thr);
	return 0;
}