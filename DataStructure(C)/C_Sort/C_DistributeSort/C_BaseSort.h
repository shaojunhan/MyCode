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
//��ʼ����:��̬����L����,L�м�¼�Ĺؼ���Ϊ��λ������
//�������:��������ʹL�м�¼���ؼ�����������
#endif