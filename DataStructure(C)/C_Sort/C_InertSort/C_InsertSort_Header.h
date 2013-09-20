#ifndef C_InsertSort_Header_2013_2_23_23_08
#define C_InsertSort_Header_2013_2_23_23_08
//#pragma once
#define INFOSIZE 21
typedef int KeyType;
typedef char OtherType[INFOSIZE];
#include"E:\Document\Data Structures\Study\C_Sort\C_Sort_SqList.h"//顺序表类型定义
typedef RedType ElemType;
#include"E:\Document\Data Structures\Study\C_Sort\C_Sort_StaticList.h"

void SimpleInsertSort(SqList &R,bool flag);
//初始条件:顺序表R存在,flag指示有序类型(0正序、1逆序)
//操作结果:按flag指示的有序类型对R进行直接插入排序
void SimpleInsertSort(SqList &R);//重载
//初始条件:顺序表R存在,0号位置未占用
//操作结果:简单插入排序使R中记录按关键字从小到大排序

void BinInsertSort(SqList &R,bool flag);
//初始条件:顺序表R存在,0号位置为占用,flag表示有序类型(0正序,1逆序)
//操作结果:二分插入排序使R中记录按关键字有序
void BinInsertSort(SqList &R);//重载
//初始条件:顺序表R存在,0号位置为占用
//操作结果:二分插入排序使R中记录按关键字正序有序

void P2InsertSort(SqList &R,bool flag);
//初始条件:顺序表R存在,0号位置未占用,flag表示记录有序类型(0正序,1逆序)
//操作结果:2路插入排序使R中记录按关键字有序
void P2InsertSort(SqList &R);//重载
//初始条件:顺序表R存在,0号位置未占用
//操作结果:2路插入排序使R中记录按关键字正序有序

void TableInsertSort(StaticList &R,bool flag);
//初始条件:静态链表R存在,flag表示记录有序类型(0正序,1逆序)
//操作结果:表插入排序使R有序
void TableInsertSort(StaticList &R);//重载
//初始条件:静态链表R存在
//操作结果:表插入排序使R正序有序

void ShellInsertSort(SqList &R,int flag);
//初始条件:顺序表R存在,0号位置为占用,flag为记录有序类型标记(0为正序,1为逆序)
//操作结果:谢尔排序使R中记录有序
void ShellInsertSort(SqList &R);
//初始条件:顺序表R存在,0号位置为占用
//操作结果:谢尔排序使R中记录正序有序
#endif