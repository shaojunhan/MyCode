#ifndef C_Expression_Basic_2012_10_22_13_39
#define C_Expression_Basic_2012_10_22_13_39

#include"C_Expression_SqStack_Basic.h"

typedef char SElemType;

SElemType Taken();//���ص�һ�����
SElemType Operate(SElemType a,SElemType op,SElemType b);
SElemType Precede(SElemType t1,SElemType t2);
SElemType EvaluateExpression();
Status IsDigit(char c);

#endif