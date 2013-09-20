#include"stdafx.h"

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;
typedef int ElemType;
typedef ElemType *Triplet;
typedef int Boolead;

Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3);
Status DestroyTriplet(Triplet &T);
Status Put(Triplet &T, int i, ElemType e);
Status Get(Triplet T, int i, ElemType &e);
Status IsAscending(Triplet T);
Status IsDescending(Triplet T);
Status Max(Triplet T, ElemType &e);
Status Min(Triplet T, ElemType &e);