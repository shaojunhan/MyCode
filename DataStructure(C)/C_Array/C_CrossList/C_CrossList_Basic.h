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
	int i,j;//����
	ElemType e;//��ֵ
	struct OLNode *right,*down;//���¡�����
}*OLink;
struct CrossList
{
	OLink *rhead,*chead;//���еı�ͷ
	int mu,nu,tu;//���м�����Ԫ��
};
typedef struct CrossList CLSMatrix;

Status InitSMatrix(CLSMatrix &M);//��ʼ��
Status CreateSMatrix(CLSMatrix &M,int mu,int nu,ElemType *data[]);//����
Status DestroySMatrix(CLSMatrix &M);//����
Status PrintSMatrix(CLSMatrix M);//���
Status CopySMatrix(CLSMatrix M,CLSMatrix &T);//����
Status AddSMatrix(CLSMatrix M,CLSMatrix N,CLSMatrix &Q);//�����
Status SubSMatrix(CLSMatrix M,CLSMatrix N,CLSMatrix &Q);//�����
Status MultSMatrix(CLSMatrix M,CLSMatrix N,CLSMatrix &Q);//�����
Status TransposeSMatrix(CLSMatrix M,CLSMatrix &T);//����ת��
#endif