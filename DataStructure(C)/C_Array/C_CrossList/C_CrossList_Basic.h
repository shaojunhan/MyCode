#ifndef C_CrossList_Basic_2013_1_15_13_52
#define C_CrossList_Basic_2013_1_15_13_52
//#pragma once

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
#define ZERO 0

typedef int Status;
typedef int ElemType;
typedef struct OLNode
{
	int i,j;//坐标
	ElemType e;//数值
	struct OLNode *right,*down;//向下、向右
}*OLink;
struct CrossList
{
	OLink *rhead,*chead;//行列的表头
	int mu,nu,tu;//行列及非零元数
};
typedef struct CrossList CLSMatrix;

Status InitSMatrix(CLSMatrix &M);//初始化
Status CreateSMatrix(CLSMatrix &M,int mu,int nu,ElemType *data[]);//创建
Status DestroySMatrix(CLSMatrix &M);//销毁
Status PrintSMatrix(CLSMatrix M);//输出
Status CopySMatrix(CLSMatrix M,CLSMatrix &T);//拷贝
Status AddSMatrix(CLSMatrix M,CLSMatrix N,CLSMatrix &Q);//矩阵加
Status SubSMatrix(CLSMatrix M,CLSMatrix N,CLSMatrix &Q);//矩阵减
Status MultSMatrix(CLSMatrix M,CLSMatrix N,CLSMatrix &Q);//矩阵乘
Status TransposeSMatrix(CLSMatrix M,CLSMatrix &T);//矩阵转置
#endif