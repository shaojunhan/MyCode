#ifndef C_BankBusiness_Basic_2012_11_1_23_03
#define C_BankBusiness_Basic_2012_11_1_23_03

#include"C_BankBusiness_LinkList.h"
#include"C_BankBusiness_LinkQueue.h"

#define Qu 4

Status OpenForDay(LinkList &L);
int compare(SElemType e1,SElemType e2);
void Random(int &ArriveTime,int &Duration);
Status ListOrderInsert(LinkList &L,SElemType e,int (*compare)(SElemType,SElemType));
int Minmum(LinkQueue Q[]);
void CustomerDeparture(LinkList &L,LinkQueue Q[],SElemType e);
int CustomerArrived(LinkList &L,LinkQueue Q[],SElemType e);
void Bank_Simulation();

#endif
