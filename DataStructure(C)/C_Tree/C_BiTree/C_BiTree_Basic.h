#ifndef C_BiTree_Basic_2013_1_31_18_58
#define C_BiTree_Basic_2013_1_31_18_58

#include"C_BiTree_Header.h"

typedef char TElemType;
typedef struct BiTNode
{
	TElemType e;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef struct
{
	int level,order;
}position;

Status InitBiTree(BiTree &T);
Status DestroyBiTree(BiTree &T);
Status CreateBiTree(BiTree &T,TElemType *das,int &i);
Status ClearBiTree(BiTree &T);
bool BiTreeEmpty(BiTree T);
int BiTreeDepth(BiTree T);
BiTree Root(BiTree T);
TElemType Value(BiTree T,BiTNode e);
Status Assign(BiTree T,BiTNode &e,TElemType value);
BiTree Parent(BiTree T,BiTNode &e);
BiTree LeftChild(BiTree T,BiTNode e);
BiTree RightChild(BiTree T,BiTNode e);
BiTree LeftSibling(BiTree T,BiTNode e);
BiTree RightSibling(BiTree T,BiTNode e);
Status InsertChild(BiTree &T,position p,bool LR,BiTree C);
Status DeleteChild(BiTree &T,position p,bool LR);
Status PreOrderTraverse(BiTree T,void (*Visit)(TElemType));
Status InOrderTraverse(BiTree T,void (*Visit)(TElemType));
Status PostOrderTraverse(BiTree T,void (*Visit)(TElemType));
Status LevelOrderTraverse(BiTree T,void (*Visit)(TElemType));
#endif