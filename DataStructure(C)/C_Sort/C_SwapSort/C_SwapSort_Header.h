//#ifndef C_SwapSort_Header_2013_2_25_21_50
//#define C_SwapSort_Header_2013_2_25_21_50
#pragma once
#define INFOSIZE 128
typedef int KeyType;
typedef char OtherType[INFOSIZE+1];
#include"E:\Document\Data Structures\Study\C_Sort\C_Sort_SqList.h"

void BubbleSort(SqList &R,bool flag);
//��ʼ����:˳���R����,0��λ��δռ��,flagΪ��¼��������(0����,1����)
//�������:ð������ʹR����
void BubbleSort(SqList &R);
//��ʼ����:˳���R����,0��λ��δռ��
//�������:ð������ʹR��������

void QuikSort(SqList &R,bool flag);
//��ʼ����:˳���R����,0��Ԫ��δռ��,flagΪ��¼�������ͱ��(0����,1����)
//�������:��������ʹR����
void QuikSort(SqList &R);
//��ʼ����:˳���R����,0��Ԫ��δռ��
//�������:��������ʹR��������

//#endif