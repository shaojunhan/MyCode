#ifndef C_SelectSort_Header_2013_2_26_15_13
#define C_SelectSort_Header_2013_2_26_15_13
//#pragma once
#define INFOSIZE 128
typedef int KeyType;
typedef char OtherType[INFOSIZE+1];
#include"E:\Document\Data Structures\Study\C_Sort\C_Sort_SqList.h"

void SimpleSelectSort(SqList &R,int flag);
//��ʼ����:˳���R����,0��λ��δռ��,flagΪ��¼������(0����,1����)
//�������:��ѡ������ʹR�м�¼����
void SimpleSelectSort(SqList &R);//����
//��ʼ����:˳���R����,0��λ��δռ��
//�������:��ѡ������ʹR�м�¼��������
void HeapSelectSort(SqList &R,int flag);
//��ʼ����:˳���R����,0��λ��δռ��,flagΪ��¼�������ͱ��(0����,1����)
//�������:������ʹR�м�¼���ؼ�������
void HeapSelectSort(SqList &R);//����
//��ʼ����:˳���R����,0��λ��Ϊռ��
//�������:������ʹR�м�¼���ؼ�����������
#endif