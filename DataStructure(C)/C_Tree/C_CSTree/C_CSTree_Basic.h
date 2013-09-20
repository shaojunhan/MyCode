#ifndef C_CSTree_Basic_2013_2_6_18_54
#define C_CSTree_Basic_2013_2_6_18_54
//#pragma
//树的孩子兄弟表示

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;
typedef char TElemType;
typedef struct CSTNode
{
	TElemType e;
	struct CSTNode *firstchild,*rightsibling;
}*CSTree;

Status InitTree(CSTree &T);
Status DestroyTree(CSTree &T);
Status CreateTree(CSTree &T,TElemType e);
Status ClearTree(CSTree &T);
bool TreeEmpty(CSTree T);
int TreeDepth(CSTree T);
TElemType Value(CSTree T,TElemType e);
Status Assign(CSTree &T,TElemType cur_e,TElemType value);
TElemType Root(CSTree T);
CSTree Parent(CSTree T,TElemType cur_e);
CSTree LeftChild(CSTree T,TElemType cur_e);
CSTree RightSibling(CSTree T,TElemType cur_e);
Status InsertChild(CSTree &T,TElemType p,int i,CSTree &C);
Status DeleteChild(CSTree &T,TElemType p,int i);
Status PreOrderTraverse(CSTree T,void (*visit)(TElemType));
Status PostOrderTraverse(CSTree T,void (*visit)(TElemType));
Status LevelOrderTraverse(CSTree T,void (*visit)(TElemType));

#endif