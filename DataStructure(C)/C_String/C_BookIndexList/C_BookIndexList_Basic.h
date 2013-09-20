#ifndef C_BookIndexList_Basic_2012_1_1_21_12
#define C_BookIndexList_Basic_2012_1_1_21_12

#include"C_BookIndexList_Header.h"
#include"C_BookIndexList_HString.h"
#include"C_BookIndexList_LinkList.h"

#define MaxBookNum 1000//书的最大书目
#define MaxKeyNum 2500//索引表的最大容量
#define MaxLineLen 500//书目串的最大长度
#define MaxWordNum 10//词表最大容量
#define MaxNoNum 100//常用词表长度

typedef struct
{
	char *item[MaxWordNum];
	int last;
}WordListType;//词表

typedef struct
{
	HString key;
	LinkList bnolist;
}IdxTermType;//索引项

typedef struct
{
	IdxTermType item[MaxKeyNum+1];
	int last;
}IdxListType;//所以表

typedef struct
{
	HString bname;
	int bno;
}BookTermType;//书目项

typedef struct
{
	BookTermType item[MaxBookNum];
	int last;
}BookListType;//书目表

typedef struct
{
	char *item[MaxNoNum];
	int last;
}NoListType;//常用词表


Status InitIdxList(IdxListType &idxlist);//
void GetLine(FILE *f);//
void ExtractKeyWord(ElemType &bno);//
Status InsIdxList(IdxListType &idxlist,ElemType bno);//
void PutText(FILE *g,IdxListType idxlist);//

void GetWord(int i,HString &wb);//
int Locate(IdxListType idxlist,HString wd,bool &b);//
void InsertNewKey(IdxListType &idxlist,int i,HString wd);//
Status InsertBookNo(IdxListType &idxlist,int i,int bno);//

void Reserve();//增加的函数
void ListBuffer();
void NoBuffer();
int compare(ElemType e1,ElemType e2);
#endif