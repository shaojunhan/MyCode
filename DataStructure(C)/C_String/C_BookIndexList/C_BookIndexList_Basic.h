#ifndef C_BookIndexList_Basic_2012_1_1_21_12
#define C_BookIndexList_Basic_2012_1_1_21_12

#include"C_BookIndexList_Header.h"
#include"C_BookIndexList_HString.h"
#include"C_BookIndexList_LinkList.h"

#define MaxBookNum 1000//��������Ŀ
#define MaxKeyNum 2500//��������������
#define MaxLineLen 500//��Ŀ������󳤶�
#define MaxWordNum 10//�ʱ��������
#define MaxNoNum 100//���ôʱ���

typedef struct
{
	char *item[MaxWordNum];
	int last;
}WordListType;//�ʱ�

typedef struct
{
	HString key;
	LinkList bnolist;
}IdxTermType;//������

typedef struct
{
	IdxTermType item[MaxKeyNum+1];
	int last;
}IdxListType;//���Ա�

typedef struct
{
	HString bname;
	int bno;
}BookTermType;//��Ŀ��

typedef struct
{
	BookTermType item[MaxBookNum];
	int last;
}BookListType;//��Ŀ��

typedef struct
{
	char *item[MaxNoNum];
	int last;
}NoListType;//���ôʱ�


Status InitIdxList(IdxListType &idxlist);//
void GetLine(FILE *f);//
void ExtractKeyWord(ElemType &bno);//
Status InsIdxList(IdxListType &idxlist,ElemType bno);//
void PutText(FILE *g,IdxListType idxlist);//

void GetWord(int i,HString &wb);//
int Locate(IdxListType idxlist,HString wd,bool &b);//
void InsertNewKey(IdxListType &idxlist,int i,HString wd);//
Status InsertBookNo(IdxListType &idxlist,int i,int bno);//

void Reserve();//���ӵĺ���
void ListBuffer();
void NoBuffer();
int compare(ElemType e1,ElemType e2);
#endif