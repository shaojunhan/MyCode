//#ifndef C_SwapSort_Header_2013_2_25_21_50
//#define C_SwapSort_Header_2013_2_25_21_50
#pragma once
#define INFOSIZE 128
typedef int KeyType;
typedef char OtherType[INFOSIZE+1];
#include"E:\Document\Data Structures\Study\C_Sort\C_Sort_SqList.h"

void BubbleSort(SqList &R,bool flag);
//初始条件:顺序表R存在,0号位置未占用,flag为记录有序类型(0正序,1逆序)
//操作结果:冒泡排序使R有序
void BubbleSort(SqList &R);
//初始条件:顺序表R存在,0号位置未占用
//操作结果:冒泡排序使R正序有序

void QuikSort(SqList &R,bool flag);
//初始条件:顺序表R存在,0号元素未占用,flag为记录有序类型标记(0正序,1逆序)
//操作结果:快速排序使R有序
void QuikSort(SqList &R);
//初始条件:顺序表R存在,0号元素未占用
//操作结果:快速排序使R正序有序

//#endif