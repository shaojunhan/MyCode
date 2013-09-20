#ifndef C_SOSTree_Basic_2013_2_20_19_29
#define C_SOSTree_Basic_2013_2_20_19_29
//#pragma once
//���Ŷ��������(��̬����)
typedef struct BTNode
{
	TElemType data;
	struct BTNode *lchild,*rchild;
}BTNode,*BiTree;

int SecondOptimal(BiTree &T,int sweight[],TElemType R[],int low,int high);
//TΪ����������,sweightΪȨֵ�͵ļ���,sweight[0]=0,RΪ��������,nΪ���鳤��
//����Ȩֵ�������Ų�����T,�ɹ�����0,���򷵻�1
void DestroyTree(BiTree &T);
//���ٴ�����T
void FindSW(int sweight[],TElemType R[],int n);
//sweightΪ����n+1����,RΪ����,nΪ���鳤��
//����Ȩֵ�ͷ���sweight��,sweight��0λ��ΪȨֵ��0
int Search(BiTree T,KeyType key,BiTree &p);
//���ݹؼ����ڴ�����������
//�ҵ�p�����������������0,����p=null����1
void Traverse(BiTree T,void (*Visit)(TElemType));
//������
void DestroyTree(BiTree &T);
//���ٴ�����T
#endif