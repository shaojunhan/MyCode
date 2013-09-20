#ifndef C_BaseSort_2013_2_26_22_46
#define C_BaseSort_2013_2_26_22_46
//#pragma once
#define BASENUMBER 10
#define KEYSIZE 3
#define MAXSIZE 128
typedef int ElemType;
typedef struct
{
	ElemType data;
	int cur;
}component,StaticList[MAXSIZE+1];

void BaseSort(StaticList &L);
//初始条件:静态链表L存在,L中记录的关键字为三位的整数
//操作结果:基数排序使L中记录按关键字正序有序
#endif