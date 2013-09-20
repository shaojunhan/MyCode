#ifndef C_RLSMatrix_Basic_2013_1_14_15_26
#define C_RLSMatrix_Basic_2013_1_14_15_26
//#pragma once

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
#define MAXSIZE 2500
#define MAXROW 50
#define ZERO 0

typedef int Status;
typedef int ElemType;
typedef struct
{
	int i,j;
	ElemType e;
}Triplet,TElemType;//��Ԫ��
typedef struct
{
	TElemType data[MAXSIZE];
	int rpos[MAXROW];
	int mu,nu,tu;
}RLSMatrix;//ϡ�����

Status CreateSMatrix(RLSMatrix &M,int mu,int nu,ElemType *data[]);//
Status DestroySMatrix(RLSMatrix &M);//
Status PrintSMatrix(RLSMatrix M);//�������
Status CopySMatrix(RLSMatrix M,RLSMatrix &T);//
Status AddSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q);//
Status SubSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q);//
Status MultSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q);//����˻�
Status TransposeSMatrix(RLSMatrix M,RLSMatrix &T);//

#endif