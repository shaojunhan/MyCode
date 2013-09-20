#ifndef C_GList_Basic_2013_1_18_18_59
#define C_GList_Basic_2013_1_18_18_59
//#pragma once

#include"C_GList_HString.h"

typedef int AtomType;
enum ElemTag {ATOM,LIST};
typedef struct GLNode//带头结点的广义表
{
	ElemTag tag;
	union
	{
		AtomType atom;
		struct GLNode *hp;
	};
	struct GLNode *tp;//相当于链表的next指针
}*GList;

Status InitGList(GList &L);
Status CreateGList(GList &L,HString S);
Status DestroyGList(GList &L);
Status CopyGList(GList &T,GList L);
Status GListLength(GList L);
int GListDepth(GList L);
bool GListEmpty(GList L);
GList GetHead(GList L);
GList GetTail(GList L);
Status InsertFirst_GL(GList &L,GList e);
Status DeleteFirst_GL(GList &L,GList &e);
Status Traverse_GL(GList L, void (*visit)(AtomType));

void server(HString &str,HString &hstr);
#endif