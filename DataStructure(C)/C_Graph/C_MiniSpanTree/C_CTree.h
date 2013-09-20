#ifndef C_CTree_2013_2_15_20_24
#define C_CTree_2013_2_15_20_24
//#pragma once
#define MAX_SIZE MAX_VERTEX_NUM
typedef char TElemType;
typedef struct CNode
{
	int child;
	struct CNode *next;
}CNode,*ChildPtr;
typedef struct
{
	TElemType e;
	ChildPtr firstchild;
}CTBox;
typedef struct
{
	CTBox data[MAX_SIZE];
	int num;
}CTree;
#endif