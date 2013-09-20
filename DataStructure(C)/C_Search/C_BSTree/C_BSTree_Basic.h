#ifndef C_BSTree_Basic_2013_2_22_9_49
#define C_BSTree_Basic_2013_2_22_9_49
//#pragma once
typedef struct BSTNode
{
	TElemType data;
	int bf;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
void InitDSTable(BSTree &BST);
//操作结果:对平衡二叉树进行初始化
void DestroyDSTable(BSTree &BST);
//初始条件:平衡二叉树BST存在
//操作结果:销毁BST
BSTree SearchDSTable(BSTree BST,KeyType key);
//初始条件:平衡二叉树BST存在,key是和关键字类型相同的给定值
//操作结果:搜索BST中关键字与key相同的记录,若找到则返回在BST中位置,否则返回空
int InsertDSTable(BSTree &BST,TElemType data);
//初始条件:平衡二叉树BST存在,data是与BST中数据域类型相同的一给定值
//操作结果:若在BST中未找到关键字与data.key相同的记录,则执行插入,否则不执行任何操作

/*删除算法有待补充
int DeleteDSTable(BSTree &BST,KeyType key);
//初始条件:平衡二叉树BST存在,key是和关键字类型相同的一给定值
//操作结果:若在BST中找到关键字与key相同的记录,则执行删除,否则不执行任何操作
*/

void TraverseDSTable(BSTree BST,void (*Visit)(TElemType));
//初始条件:平衡二叉树BST存在,Visit是对TElemType数据类型执行访问的函数
//操作结果:以中序遍历对BST中的每个结点访问一次

void L_Rotate(BSTree &BST);
void R_Rotate(BSTree &BST);
void LeftBalance(BSTree &BST);
void RightBalance(BSTree &BST);
#endif