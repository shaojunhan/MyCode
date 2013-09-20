#ifndef C_Polynomail_Basic_2012_10_13_21_21
#define C_Polynomail_Basic_2012_10_13_21_21

#include"stdafx.h"
#include"C_Polynomial_Header.h"

void CreatePolyn(Polynomial &P,int m);
void DestroyPolyn(Polynomial &P);
void PrintPolyn(Polynomial p);
int PolynLength(Polynomial P);
void AddPolyn(Polynomial &Pa,Polynomial &Pb);
void SubPolyn(Polynomial &Pa,Polynomial &Pb);
void MultiplyPolyn(Polynomial &Pa,Polynomial &Pb);

#endif