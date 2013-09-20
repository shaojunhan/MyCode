#ifndef C_BookIndexList_HString_2013_1_1_13_15
#define C_BookIndexList_HString_2013_1_1_13_15

#include"C_BookIndexList_Header.h"

typedef struct
{
	char *ch;
	int len;
}HString;

Status StrAssign(HString &T,char *chars);
Status StrCopy(HString &T,HString S);
bool StrEmpty(HString S);
int StrCompare(HString S,HString T);
int StrLength(HString S);
Status ClearString(HString &S);
Status Concat(HString &T,HString S1,HString S2);
Status SubString(HString &Sub,HString S,int pos,int len);
Status Index(HString S,HString T,int pos);
Status Replace(HString &S,HString T,HString V);
Status StrInsert(HString &S,int pos,HString T);
Status StrDelete(HString &S,int pos,int len);
Status DestroyString(HString &S);

Status InitString(HString &S);

#endif