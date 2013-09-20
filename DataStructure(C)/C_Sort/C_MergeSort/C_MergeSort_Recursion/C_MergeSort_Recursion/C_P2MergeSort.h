//#ifndef C_P2MergeSort_2013_2_26_22_14
//#define C_P2MergeSort_2013_2_26_22_14
#pragma once
#define INFOSIZE 128
typedef int KeyType;
typedef char OtherType[INFOSIZE+1];
#include"E:\Document\Data Structures\Study\C_Sort\C_Sort_SqList.h"

void P2MergeSort(SqList &R);//重载
//初始条件:顺序表R存在,0号位置未占用
//操作结果:2路归并排序使R中的记录按关键字正序有序
//#endif