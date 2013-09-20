#ifndef C_SqBiTree_Basic_2013_1_29_21_20
#define C_SqBiTree_Basic_2013_1_29_21_20
//#pragma

#include"C_SqBiTree_Header.h"
typedef TElemType SqBiTree[MAX_SIZE];
typedef struct
{
	int level,order;
}position;

Status InitBiTree(SqBiTree T);
void DestroyBiTree(SqBiTree T);
Status CreateBiTree(SqBiTree T,char *chars);
Status ClearBiTree(SqBiTree T);
bool BiTreeEmpty(SqBiTree T);
int BiTreeDepth(SqBiTree T);
TElemType Root(SqBiTree T);
TElemType Value(SqBiTree T,TElemType e);
Status Assign(SqBiTree T,TElemType &e,TElemType value);
TElemType Parent(SqBiTree T,TElemType e);
TElemType LeftChild(SqBiTree T,TElemType e);
TElemType RightChild(SqBiTree T,TElemType e);
TElemType LeftSibling(SqBiTree T,TElemType e);
TElemType RightSibling(SqBiTree T,TElemType e);
Status InsertChild(SqBiTree T,position p,bool LR,SqBiTree C);
Status DeleteChild(SqBiTree T,position p,bool LR);
Status PreOrderTraverse(SqBiTree T,void (*Visit)(TElemType));
Status InOrderTraverse(SqBiTree T,void (*Visit)(TElemType));
Status PostOrderTraverse(SqBiTree T,void (*Visit)(TElemType));
Status LevelOrderTraverse(SqBiTree T,void (*Visit)(TElemType));

#endif