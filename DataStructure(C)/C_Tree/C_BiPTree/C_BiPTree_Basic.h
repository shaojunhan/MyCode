#ifndef C_BiPTree_Basic_2013_2_2_23_51
#define C_BiPTree_Basic_2013_2_2_23_51
//#pragma once

#include"C_BiPTree_Header.h"

typedef struct BiPTNode
{
	TElemType e;
	struct BiPTNode *parent,*lchild,*rchild;
}BiPTNode,*BiPTree;
typedef struct
{
	int level,order;
}position;

Status InitBiTree(BiPTree &T);
Status CreateBiTree(BiPTree &T,TElemType *datas);
Status DestroyBiTree(BiPTree &T);
Status ClearBiTree(BiPTree &T);
bool BiTreeEmpty(BiPTree T);
int BiTreeDepth(BiPTree T);
BiPTree Root(BiPTree T);
TElemType Value(BiPTree T,BiPTree e);
Status Assign(BiPTree T,BiPTree e,TElemType value);
BiPTree Parent(BiPTree T,BiPTree e);
BiPTree LeftChild(BiPTree T,BiPTree e);
BiPTree RightChild(BiPTree T,BiPTree e);
BiPTree LeftSibling(BiPTree T,BiPTree e);
BiPTree RightSibling(BiPTree T,BiPTree e);
Status InsertChild(BiPTree T,position p,bool LR,BiPTree C);
Status DeleteChild(BiPTree T,position p,bool LR);
Status PreOrderTraverse(BiPTree T,void (*Visit)(TElemType));
Status InOrderTraverse(BiPTree T,void (*Visit)(TElemType));
Status PostOrderTraverse(BiPTree T,void (*Visit)(TElemType));
Status LevelOrderTraverse(BiPTree T,void (*Visit)(TElemType));

#endif