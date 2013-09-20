#ifndef C_BSTree_Basic_2013_2_22_9_49
#define C_BSTree_Basic_2013_2_22_9_49
//#pragma once
typedef struct BSTNode
{
	TElemType data;
	int bf;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
void InitDSTable(BSTree &BST);
//�������:��ƽ����������г�ʼ��
void DestroyDSTable(BSTree &BST);
//��ʼ����:ƽ�������BST����
//�������:����BST
BSTree SearchDSTable(BSTree BST,KeyType key);
//��ʼ����:ƽ�������BST����,key�Ǻ͹ؼ���������ͬ�ĸ���ֵ
//�������:����BST�йؼ�����key��ͬ�ļ�¼,���ҵ��򷵻���BST��λ��,���򷵻ؿ�
int InsertDSTable(BSTree &BST,TElemType data);
//��ʼ����:ƽ�������BST����,data����BST��������������ͬ��һ����ֵ
//�������:����BST��δ�ҵ��ؼ�����data.key��ͬ�ļ�¼,��ִ�в���,����ִ���κβ���

/*ɾ���㷨�д�����
int DeleteDSTable(BSTree &BST,KeyType key);
//��ʼ����:ƽ�������BST����,key�Ǻ͹ؼ���������ͬ��һ����ֵ
//�������:����BST���ҵ��ؼ�����key��ͬ�ļ�¼,��ִ��ɾ��,����ִ���κβ���
*/

void TraverseDSTable(BSTree BST,void (*Visit)(TElemType));
//��ʼ����:ƽ�������BST����,Visit�Ƕ�TElemType��������ִ�з��ʵĺ���
//�������:�����������BST�е�ÿ��������һ��

void L_Rotate(BSTree &BST);
void R_Rotate(BSTree &BST);
void LeftBalance(BSTree &BST);
void RightBalance(BSTree &BST);
#endif