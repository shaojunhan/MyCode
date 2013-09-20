//#ifndef C_Sort_StaticList_2013_2_24_14_45
//#define C_Sort_StaticList_2013_2_24_14_45
#pragma once
#ifndef MAXSIZE
#define MAXSIZE 20
#endif
typedef struct
{
	ElemType data;
	int cur;
}component,StaticList[MAXSIZE+1];//�����Ǵ�ͷ��������

void InitList(StaticList &L);
//�������:��ʼ����̬����,��ͷΪ0�����洢���ý��
bool ListEmpty(StaticList L,int head);
//�������:�ж������Ƿ�Ϊ��
int ListLength(StaticList L,int head);
//�������:��������head�ĳ���
int ClearList(StaticList &L,int head);
//�������:�������head,ʧ�ܷ���1,�ɹ�����0
void GetElem(StaticList &L,int head,int i,ElemType &e,
			 int (*compare)(ElemType,ElemType));
//��ʼ����:��̬����L����,headΪ�����ͷ,0<i<=ListLength(head)
//�������:��e��������head�ĵ�i������
int LocateElem(StaticList L,int head,ElemType e,
			   int (*compare)(ElemType,ElemType));
//��ʼ����:��̬����L����,headΪ�����ͷ
//�������:����Ԫ��e��������head�е�λ��
int PriorElem(StaticList L,int head,ElemType cur_e,ElemType &prior_e,
			  int (*compare)(ElemType,ElemType));
//��ʼ����:��̬����L����,headΪ��ͷ,cur_eΪ����head�е�һ��Ԫ��
//�������:prior_e��������head��cur_e��ǰ��,�ɹ�����0,ʧ�ܷ���0
int NextElem(StaticList L,int head,ElemType cur_e,ElemType &next_e,
			 int (*compare)(ElemType,ElemType));
//��ʼ����:L����,headΪ��ͷ,cur_eΪ����head�е�һԪ��
//�������:��next_e��������head��Ԫ��cur_e�ĺ��
int ListInsert(StaticList &L,int head,int i,ElemType e);
//��ʼ����:L����,headΪ��ͷ,0<i<=ListLength(head)+1
//�������:����head�е�i��λ�ò���Ԫ��e
int ListDelete(StaticList &L,int head,int i,ElemType &e);
//��ʼ����:L����,headΪ��ͷ,0<i<=ListLenngth(head)
//�������:ɾ������head�еĵ�i��Ԫ��,��e����ɾ��Ԫ�ص�ֵ
void TraverseList(StaticList L,int head,void (*Visit)(ElemType));
//�������:��������head�е�ÿ��Ԫ��һ�� 
int Malloc(StaticList &L);
//�������:����һ�����ô洢��Ԫ
void Free(StaticList &L,int cur);
//�������:����һ�����ô洢��Ԫ

//#endif