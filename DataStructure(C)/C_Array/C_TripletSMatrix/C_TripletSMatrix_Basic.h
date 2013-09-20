#ifndef C_TripletSMatrix_Basic_2013_1_8_17_21
#define C_TripletSMatrix_Basic_2013_1_8_17_21

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
#define MAXSIZE 40000
#define ZERO 0
#define MINUS -1

typedef int Status;
typedef int ElemType;
typedef struct
{
	int i,j;
	ElemType e;
}Triplet,TElemType;//三元组
typedef struct
{
	TElemType data[MAXSIZE];
	int mu,nu,tu;//行、列、非零元数
}TSSMatrix;

Status CreateSMatrix(TSSMatrix &M,int mu,int nu,ElemType **elem);//创建矩阵
Status DestroySMatrix(TSSMatrix &M);//销毁矩阵
Status CopySMatrix(TSSMatrix M,TSSMatrix &T);//拷贝矩阵
Status PrintSMatrix(TSSMatrix M);//输出矩阵
Status AddSMatrix(TSSMatrix M,TSSMatrix N,TSSMatrix &Q);//矩阵加
Status SubSMatrix(TSSMatrix M,TSSMatrix N,TSSMatrix &Q);//矩阵减
Status MultSMatrix(TSSMatrix M,TSSMatrix N,TSSMatrix &Q);//矩阵乘
Status TransposeSMatrix(TSSMatrix M,TSSMatrix &T);//转置

#endif