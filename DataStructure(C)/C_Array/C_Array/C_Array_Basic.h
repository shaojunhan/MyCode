#ifndef C_Array_Basic_2013_1_8_14_51
#define C_Array_Basic_2013_1_8_14_51

#define ERROR 0
#define OK 1
#define FALSE 0
#define TURE 1

typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType *base;//����
	int *bounds;//ÿһά��ά��
	int *contants;//��άƫ����
	int dim;//ά��
}Array;//����

Status InitArray(Array &A,int dim,...);//��ʼ
Status DestroyArray(Array &A);//����
Status Assign(Array &A,ElemType e,...);//��ֵ
Status Value(ElemType &e,Array A,...);//��ȡ

#endif