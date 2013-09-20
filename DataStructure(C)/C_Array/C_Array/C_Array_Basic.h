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
	ElemType *base;//数据
	int *bounds;//每一维的维数
	int *contants;//各维偏移量
	int dim;//维数
}Array;//数组

Status InitArray(Array &A,int dim,...);//初始
Status DestroyArray(Array &A);//销毁
Status Assign(Array &A,ElemType e,...);//赋值
Status Value(ElemType &e,Array A,...);//读取

#endif