#ifndef C_SSTable_Basic_2013_2_20_18_11
#define C_SSTable_Basic_2013_2_20_18_11
//#pragma once
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
typedef int Status;
//��̬���ұ�
typedef struct
{
	SElemType *elem;
	int length;
}SSTable;

Status Create_IR(SSTable &ST);
//ST�е�Ԫ�ذ��ؼ��ִ�С��������
Status Create_OR(SSTable &ST,SElemType R[],int n);
//R��0��ʼ,ST��0λ�ò��洢Ԫ��,nΪR���鳤��
 //����R˳����ST
Status DestroyTable(SSTable &ST);
//����ST
int Search_IR(SSTable &ST,KeyType key);
//ST��̬���ұ�,key�ؼ���
//˳�����,�ҵ�������ST�е�λ��(��1��ʼ),���򷵻ظ���
int Search_BIN(SSTable &ST,KeyType key);
//STΪ�ؼ��ִ�С��������,keyΪ����ؼ���
//��ST������key,�ҵ���������ST��λ��(��1��ʼ),���򷵻ظ���
void Traverse(SSTable &ST,void (*Visit)(SElemType));
//Visit����ΪSElemType�ĺ���ָ��
//˳�����ST
#endif