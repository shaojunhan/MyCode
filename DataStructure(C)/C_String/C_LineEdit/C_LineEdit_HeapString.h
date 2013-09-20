#ifndef C_LineEdit_HeapString_2012_12_30_10_22
#define C_LineEdit_HeapString_2012_12_30_10_22


#define ERROR 0
#define OK 1
#define FALSE 0
#define TURE 1

typedef int Status;
typedef struct
{
	char *ch;
	int len;
}HString;

Status StrAssign(HString &T,char *ch);//��ֵ
Status StrCopy(HString &T,HString S);//����
Status StrEmpty(HString S);//�п�
int StrCompare(HString S,HString T);//�Ƚ�
Status StrLength(HString S);//�󳤶�
Status ClearString(HString &S);//���
Status Concat(HString &T,HString S1,HString S2);//����
Status SubString(HString &Sub,HString S,int pos,int len);//���Ӵ�
int Index(HString S,HString T,int pos);//ģʽƥ��
Status Replace(HString &S,HString T,HString V);//�滻
Status StrInsert(HString &S,int pos,HString T);//����
Status StrDelete(HString &S,int pos,int len);//ɾ��
Status DestroyString(HString &S);//����

Status InitString(HString &S);//���ӳ�ʼ������
Status StrPrint(HString S);//���ӵ��������
#endif