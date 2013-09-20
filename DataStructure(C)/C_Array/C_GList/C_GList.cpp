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
	printf("���������,������:");
	scanf("%s%*c",buf);
	
	StrAssign(S,buf);
	CreateGList(L,S);
	printf("��������:");
	Traverse_GL(L,visit);
	printf("\n������Ƿ�Ϊ��(0-�� 1-�ǿ�):%d",!GListEmpty(L));
	printf("\n�������:%d\n",GListLength(L));
	printf("\n��������:%d\n",GListDepth(L));

	printf("\n-------------------");
	printf("\n���ƵĹ����:");
	CopyGList(T,L);
	Traverse_GL(T,visit);
	printf("\n��ñ�ͷ��β:");
	CopyGList(T,GetHead(L));
	Traverse_GL(T,visit);
	printf("\n");
	CopyGList(T,GetTail(L));
	Traverse_GL(T,visit);
	
	printf("\n-------------------");
	printf("\n����:");
	InsertFirst_GL(L,T);
	Traverse_GL(L,visit);
	printf("\nɾ��:");
	DeleteFirst_GL(L,G);
	Traverse_GL(L,visit);
	printf("\n");
	Traverse_GL(G,visit);

	DestroyGList(T),DestroyGList(L);
	DestroyString(S);
	system("pause");
	return 0;
}