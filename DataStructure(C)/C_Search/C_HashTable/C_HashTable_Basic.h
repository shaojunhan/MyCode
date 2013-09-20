#ifndef C_HashTable_Basic_2013_2_22_22_08
#define C_HashTable_Basic_2013_2_22_22_08
//#pragma once
//��ʽ��ϣ��
#define MAX 100
typedef struct HNode
{
	HElemType data;
	struct HNode *next;
}HNode,*HLink;
typedef HLink HashTable[MAX];

void InitDSTable(HashTable &HT);
//�������:��ʼ����ϣ��
void DestroyDSTable(HashTable &HT);
//��ʼ����:��ϣ��HT����
//�������:����HT
HLink SearchDSTable(HashTable HT,KeyType key);
//��ʼ����:��ϣ��HT����,key����ؼ���������ͬ��һ����ֵ
//�������:����HT�йؼ�����key��ͬ�ļ�¼,�ҵ���������λ��(ָ��),δ�ҵ����ؿ�
int InsertDSTable(HashTable &HT,HElemType data);
//��ʼ����:��ϣ��HT����,data����HT�м�¼������ͬ��һ����ֵ
//�������:����HT�йؼ�����data.key��ͬ�ļ�¼,�ҵ����ز���ʧ��(1),δ�ҵ���ִ�в��뷵�ز���ɹ�(0)
int DeleteDSTable(HashTable &HT,KeyType key);
//��ʼ����:��ϣ��HT����,key����ؼ���������ͬ��һ����ֵ
//�������:��HT���������ؼ�����key��ͬ�ļ�¼,��ִ��ɾ������ɾ���ɹ�(0),���򷵻�ɾ��ʧ��(1)
void TraverseDSTable(HashTable HT,void (*Visit)(HElemType));
//��ʼ����:��ϣ��HT����,Visit�Ƕ�HElemType���ͽ��з��ʵĺ���
//�������:��HT�м�¼����һ��

#endif