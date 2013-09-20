#ifndef C_PTree_Basic_2013_2_5_8_19
#define C_PTree_Basic_2013_2_5_8_19
//#pragma

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
#define MAX_SIZE 50
typedef int Status;
typedef char TElemType;
typedef struct
{
	TElemType data;
	int parent;
}PTNode;//�������
typedef struct
{
	PTNode nodes[MAX_SIZE];//������
	int n;//�ڵ���
}PTree;

Status InitTree(PTree &T);//��ʼ
void DestroyTree(PTree &T);//����
Status CreateTree(PTree &T);//����
Status ClearTree(PTree &T);//���
bool TreeEmpty(PTree T);//�Ƿ�Ϊ����
int TreeDepth(PTree T);//������
TElemType Root(PTree T);//���
TElemType Value(PTree T,int i);//��ֵ
Status Assign(PTree &T,TElemType cur_e,TElemType value);//��ֵ
int Parent(PTree T,TElemType cur_e);//�󸸽ڵ�
int LeftChild(PTree T,TElemType cur_e);//������
int RightSibling(PTree T,TElemType cur_e);//���Һ���
Status InsertChild(PTree &T,TElemType p,int i,PTree C);//��������
Status DeleteChild(PTree &T,TElemType p,int i);//ɾ������
Status TraverseTree(PTree T,void (*Visit)(TElemType));//����

#endif