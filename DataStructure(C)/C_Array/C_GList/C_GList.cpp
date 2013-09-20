#include"C_GList_Basic.h"
#include"C_GList_HString.h"
#include<stdio.h>
#include<stdlib.h>

void visit(AtomType e)
{
	printf("%c",e);
}

int main(int argc,char *argv[])
{
	char buf[256];
	GList L,T,G;
	HString S;

	InitGList(L);
	InitGList(T);
	InitGList(G);
	InitHString(S);
	printf("创建广义表,请输入:");
	scanf("%s%*c",buf);
	
	StrAssign(S,buf);
	CreateGList(L,S);
	printf("输出广义表:");
	Traverse_GL(L,visit);
	printf("\n广义表是否为空(0-空 1-非空):%d",!GListEmpty(L));
	printf("\n广义表长度:%d\n",GListLength(L));
	printf("\n广义表深度:%d\n",GListDepth(L));

	printf("\n-------------------");
	printf("\n复制的广义表:");
	CopyGList(T,L);
	Traverse_GL(T,visit);
	printf("\n获得表头表尾:");
	CopyGList(T,GetHead(L));
	Traverse_GL(T,visit);
	printf("\n");
	CopyGList(T,GetTail(L));
	Traverse_GL(T,visit);
	
	printf("\n-------------------");
	printf("\n插入:");
	InsertFirst_GL(L,T);
	Traverse_GL(L,visit);
	printf("\n删除:");
	DeleteFirst_GL(L,G);
	Traverse_GL(L,visit);
	printf("\n");
	Traverse_GL(G,visit);

	DestroyGList(T),DestroyGList(L);
	DestroyString(S);
	system("pause");
	return 0;
}