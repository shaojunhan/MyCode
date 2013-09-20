#ifndef C_MergeSort_Header_2013_2_26_16_19
#define C_MergeSort_Header_2013_2_26_16_19
//#pragma once
#define INFOSIZE 128
typedef int KeyType;
typedef char OtherType[INFOSIZE+1];
#include"E:\Document\Data Structures\Study\C_Sort\C_Sort_SqList.h"

void P2MergeSort(SqList &R,bool flag);
//初始条件:顺序表R存在,0号位置未占用,flag为记录有序类型标记(0正序,1逆序)
//操作结果:2路归并排序使R中记录按关键字有序
void P2MergeSort(SqList &R);//重载
//初始条件:顺序表R存在,0号位置未占用
//操作结果:2路归并排序使R中记录按关键字正序有序

#endif