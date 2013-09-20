//#ifndef C_SortBiTree_Basic_2013_2_20_22_26
//#define C_SortBiTree_Basic_2013_2_20_22_26
#pragma once
//二叉排序树
//BST-binary sorted tree
typedef struct BTNode
{
	TElemType data;
	struct BTNode *lchild,*rchild;
}BTNode,*BiTree;

int InitDSTable(BiTree &DT);
//操作结果:构造一个空的动态查找表DT
int DestroyDSTable(BiTree &DT);
//初始条件:动态查找表DT存在
//操作结果:销毁动态查找表DT
BiTree SearchDSTable(BiTree &DT,KeyType key);
//初始条件:动态查找表DT存在,key为和关键字类型相同的给定值
//操作结果:若DT中存在关键字与key相同的记录,则返回该元素的值或在表中的位置,否则返回空
int InsertDSTable(BiTree &DT,TElemType e);
//初始条件:动态查找表DT存在,e为待插入数据元素
//操作结果:若DT中不存在关键字等于e.key的记录,则插入e到DT
int DeleteDSTable(BiTree &DT,KeyType key);
//初始条件:动态查找表DT存在,key为和关键字类型相同的给定值
//操作结果:若DT中存在关键字等于key的记录,则删除该记录
void TraverseDSTable(BiTree DT,void (*Visit)(TElemType));
//初始条件:动态查找表DT存在,Visit是对结点操作的应用函数
//操作结果:以某种次序对DT中的每个结点调用Visit一次且最多一次.Visit失败,则访问失败.
//#endif