#ifndef C_SOSTree_Basic_2013_2_20_19_29
#define C_SOSTree_Basic_2013_2_20_19_29
//#pragma once
//次优二叉查找树(静态树表)
typedef struct BTNode
{
	TElemType data;
	struct BTNode *lchild,*rchild;
}BTNode,*BiTree;

int SecondOptimal(BiTree &T,int sweight[],TElemType R[],int low,int high);
//T为待创建的树,sweight为权值和的集合,sweight[0]=0,R为数据数组,n为数组长度
//根据权值创建次优查找树T,成功返回0,否则返回1
void DestroyTree(BiTree &T);
//销毁次优树T
void FindSW(int sweight[],TElemType R[],int n);
//sweight为长度n+1数组,R为数据,n为数组长度
//计算权值和放入sweight中,sweight的0位置为权值和0
int Search(BiTree T,KeyType key,BiTree &p);
//根据关键字在次优树中搜索
//找到p返回搜索结果并返回0,否则p=null返回1
void Traverse(BiTree T,void (*Visit)(TElemType));
//遍历树
void DestroyTree(BiTree &T);
//销毁次优树T
#endif