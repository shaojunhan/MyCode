#ifndef C_InsertSort_Header_2013_2_23_23_08
#define C_InsertSort_Header_2013_2_23_23_08
//#pragma once
#define INFOSIZE 21
typedef int KeyType;
typedef char OtherType[INFOSIZE];
#include"E:\Document\Data Structures\Study\C_Sort\C_Sort_SqList.h"//˳������Ͷ���
typedef RedType ElemType;
#include"E:\Document\Data Structures\Study\C_Sort\C_Sort_StaticList.h"

void SimpleInsertSort(SqList &R,bool flag);
//��ʼ����:˳���R����,flagָʾ��������(0����1����)
//�������:��flagָʾ���������Ͷ�R����ֱ�Ӳ�������
void SimpleInsertSort(SqList &R);//����
//��ʼ����:˳���R����,0��λ��δռ��
//�������:�򵥲�������ʹR�м�¼���ؼ��ִ�С��������

void BinInsertSort(SqList &R,bool flag);
//��ʼ����:˳���R����,0��λ��Ϊռ��,flag��ʾ��������(0����,1����)
//�������:���ֲ�������ʹR�м�¼���ؼ�������
void BinInsertSort(SqList &R);//����
//��ʼ����:˳���R����,0��λ��Ϊռ��
//�������:���ֲ�������ʹR�м�¼���ؼ�����������

void P2InsertSort(SqList &R,bool flag);
//��ʼ����:˳���R����,0��λ��δռ��,flag��ʾ��¼��������(0����,1����)
//�������:2·��������ʹR�м�¼���ؼ�������
void P2InsertSort(SqList &R);//����
//��ʼ����:˳���R����,0��λ��δռ��
//�������:2·��������ʹR�м�¼���ؼ�����������

void TableInsertSort(StaticList &R,bool flag);
//��ʼ����:��̬����R����,flag��ʾ��¼��������(0����,1����)
//�������:���������ʹR����
void TableInsertSort(StaticList &R);//����
//��ʼ����:��̬����R����
//�������:���������ʹR��������

void ShellInsertSort(SqList &R,int flag);
//��ʼ����:˳���R����,0��λ��Ϊռ��,flagΪ��¼�������ͱ��(0Ϊ����,1Ϊ����)
//�������:л������ʹR�м�¼����
void ShellInsertSort(SqList &R);
//��ʼ����:˳���R����,0��λ��Ϊռ��
//�������:л������ʹR�м�¼��������
#endif