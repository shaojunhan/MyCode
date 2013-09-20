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
}Triplet,TElemType;//��Ԫ��
typedef struct
{
	TElemType data[MAXSIZE];
	int mu,nu,tu;//�С��С�����Ԫ��
}TSSMatrix;

Status CreateSMatrix(TSSMatrix &M,int mu,int nu,ElemType **elem);//��������
Status DestroySMatrix(TSSMatrix &M);//���پ���
Status CopySMatrix(TSSMatrix M,TSSMatrix &T);//��������
Status PrintSMatrix(TSSMatrix M);//�������
Status AddSMatrix(TSSMatrix M,TSSMatrix N,TSSMatrix &Q);//�����
Status SubSMatrix(TSSMatrix M,TSSMatrix N,TSSMatrix &Q);//�����
Status MultSMatrix(TSSMatrix M,TSSMatrix N,TSSMatrix &Q);//�����
Status TransposeSMatrix(TSSMatrix M,TSSMatrix &T);//ת��

#endif