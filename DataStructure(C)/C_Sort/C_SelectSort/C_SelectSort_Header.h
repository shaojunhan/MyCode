#ifndef C_SelectSort_Header_2013_2_26_15_13
#define C_SelectSort_Header_2013_2_26_15_13
//#pragma once
#define INFOSIZE 128
typedef int KeyType;
typedef char OtherType[INFOSIZE+1];
#include"E:\Document\Data Structures\Study\C_Sort\C_Sort_SqList.h"

void SimpleSelectSort(SqList &R,int flag);
//初始条件:顺序表R存在,0号位置未占用,flag为记录有序标记(0正序,1逆序)
//操作结果:简单选择排序使R中记录有序
void SimpleSelectSort(SqList &R);//重载
//初始条件:顺序表R存在,0号位置未占用
//操作结果:简单选择排序使R中记录正序有序
void HeapSelectSort(SqList &R,int flag);
//初始条件:顺序表R存在,0号位置未占用,flag为记录有序类型标记(0正序,1逆序)
//操作结果:堆排序使R中记录按关键字有序
void HeapSelectSort(SqList &R);//重载
//初始条件:顺序表R存在,0号位置为占用
//操作结果:堆排序使R中记录按关键字正序有序
#endif