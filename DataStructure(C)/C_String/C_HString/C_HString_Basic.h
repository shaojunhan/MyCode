#ifndef C_HString_Basic_2012_11_18_18_48
#define C_HString_Basic_2012_11_18_18_48

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;
struct HString
{
	char *ch;
	int length;
};

Status StrAssign(HString &T,char *chars);
Status DestroyString(HString &S);
Status ClearString(HString &S);
Status StrEmpty(HString S);
int StrLength(HString S);
Status StrCompare(HString S,HString T);
Status Concat(HString &T,HString S1,HString S2);
Status SubString(HString &Sub,HString S,int pos,int len);

Status StrCopy(HString &T,HString S);
int Index(HString S,HString T,int pos);
Status Replace(HString &S,HString T,HString V);
Status StrInsert(HString &S,int pos,HString T);
Status StrDelete(HString &S,int pos,int len);

Status InitString(HString &S);

#endif