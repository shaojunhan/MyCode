#ifndef C_Expression_Basic_2012_10_25_13_43
#define C_Expression_Basic_2012_10_25_13_43

#include"C_Expression_LinkStack.h"

typedef char SElemType;

SElemType Taken();
SElemType Operate(SElemType a,SElemType op,SElemType b);
SElemType Precede(SElemType t1,SElemType t2);
SElemType EvaluateExpression();
#endif