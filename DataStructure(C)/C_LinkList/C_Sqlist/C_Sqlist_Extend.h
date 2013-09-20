#include"stdafx.h"
#include"C_Sqlist_Basic.h"

void InsertAscend(Sqlist &L,ElemType e);
void InsertDescend(Sqlist &L,ElemType e);
Status HeadInsert(Sqlist &L,ElemType e);
Status TailInsert(Sqlist &L,ElemType e);
Status DeleteFirst(Sqlist &L,ElemType &e);
Status DeleteTail(Sqlist &L, ElemType &e);
Status DeleteElem(Sqlist &L, ElemType e);
Status ReplaceElem(Sqlist &L, int i, ElemType e);
Status CreateAscend(Sqlist &L,int n);
Status CreateDescend(Sqlist &L, int n);