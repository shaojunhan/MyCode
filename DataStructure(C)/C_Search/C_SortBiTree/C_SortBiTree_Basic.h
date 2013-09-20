//#ifndef C_SortBiTree_Basic_2013_2_20_22_26
//#define C_SortBiTree_Basic_2013_2_20_22_26
#pragma once
//����������
//BST-binary sorted tree
typedef struct BTNode
{
	TElemType data;
	struct BTNode *lchild,*rchild;
}BTNode,*BiTree;

int InitDSTable(BiTree &DT);
//�������:����һ���յĶ�̬���ұ�DT
int DestroyDSTable(BiTree &DT);
//��ʼ����:��̬���ұ�DT����
//�������:���ٶ�̬���ұ�DT
BiTree SearchDSTable(BiTree &DT,KeyType key);
//��ʼ����:��̬���ұ�DT����,keyΪ�͹ؼ���������ͬ�ĸ���ֵ
//�������:��DT�д��ڹؼ�����key��ͬ�ļ�¼,�򷵻ظ�Ԫ�ص�ֵ���ڱ��е�λ��,���򷵻ؿ�
int InsertDSTable(BiTree &DT,TElemType e);
//��ʼ����:��̬���ұ�DT����,eΪ����������Ԫ��
//�������:��DT�в����ڹؼ��ֵ���e.key�ļ�¼,�����e��DT
int DeleteDSTable(BiTree &DT,KeyType key);
//��ʼ����:��̬���ұ�DT����,keyΪ�͹ؼ���������ͬ�ĸ���ֵ
//�������:��DT�д��ڹؼ��ֵ���key�ļ�¼,��ɾ���ü�¼
void TraverseDSTable(BiTree DT,void (*Visit)(TElemType));
//��ʼ����:��̬���ұ�DT����,Visit�ǶԽ�������Ӧ�ú���
//�������:��ĳ�ִ����DT�е�ÿ��������Visitһ�������һ��.Visitʧ��,�����ʧ��.
//#endif