#ifndef C_MergeSort_Header_2013_2_26_16_19
#define C_MergeSort_Header_2013_2_26_16_19
//#pragma once
#define INFOSIZE 128
typedef int KeyType;
typedef char OtherType[INFOSIZE+1];
#include"E:\Document\Data Structures\Study\C_Sort\C_Sort_SqList.h"

void P2MergeSort(SqList &R,bool flag);
//��ʼ����:˳���R����,0��λ��δռ��,flagΪ��¼�������ͱ��(0����,1����)
//�������:2·�鲢����ʹR�м�¼���ؼ�������
void P2MergeSort(SqList &R);//����
//��ʼ����:˳���R����,0��λ��δռ��
//�������:2·�鲢����ʹR�м�¼���ؼ�����������

#endif