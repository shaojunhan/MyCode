#ifndef C_CString_Basic_2012_11_19_22_48
#define C_CString_Basic_2012_11_19_22_48

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

#define CHUNKSIZE 4
typedef int Status;

typedef struct LNode
{
	char ch[CHUNKSIZE];
	struct LNode *next;
}*Link;

typedef struct
{
	Link head,tail;
	int length;
}CString;

Status StrAssign(CString &T,char *chars);
Status Concat(CString &T,CString S1,CString S2);
Status StrCompare(CString T,CString S);
int StrLength(CString S);
Status SubString(CString &Sub,CString S,int pos,int len);

Status InitString(CString &T);//增加初始化函数
Status Zip(CString &S);//压缩数组，取出多余空格
Status DestroyString(CString &S);
Status ClearString(CString &S);
Status StrEmpty(CString S);
Status StrCopy(CString &T,CString S);
int Index(CString S,CString T,int pos);
Status Replace(CString &S,CString T,CString V);
Status StrInsert(CString &S,CString T,int pos);
Status StrDelete(CString &S,int pos,int len);

#endif