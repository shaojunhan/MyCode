#ifndef C_PTree_Basic_2013_2_5_8_19
#define C_PTree_Basic_2013_2_5_8_19
//#pragma

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
#define MAX_SIZE 50
typedef int Status;
typedef char TElemType;
typedef struct
{
	TElemType data;
	int parent;
}PTNode;//结点类型
typedef struct
{
	PTNode nodes[MAX_SIZE];//数据域
	int n;//节点数
}PTree;

Status InitTree(PTree &T);//初始
void DestroyTree(PTree &T);//销毁
Status CreateTree(PTree &T);//创建
Status ClearTree(PTree &T);//清空
bool TreeEmpty(PTree T);//是否为空树
int TreeDepth(PTree T);//求树深
TElemType Root(PTree T);//求根
TElemType Value(PTree T,int i);//求值
Status Assign(PTree &T,TElemType cur_e,TElemType value);//赋值
int Parent(PTree T,TElemType cur_e);//求父节点
int LeftChild(PTree T,TElemType cur_e);//求左孩子
int RightSibling(PTree T,TElemType cur_e);//求右孩子
Status InsertChild(PTree &T,TElemType p,int i,PTree C);//插入子树
Status DeleteChild(PTree &T,TElemType p,int i);//删除子树
Status TraverseTree(PTree T,void (*Visit)(TElemType));//遍历

#endif