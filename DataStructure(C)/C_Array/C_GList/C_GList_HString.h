#ifndef C_GList_HString_2013_1_18_19_14
#define C_GList_HString_2013_1_18_19_14
//#pragma once

#include"C_GList_Header.h"

struct HString
{
	char *base;
	int len;
};//∂‘∑÷≈‰¥Æ

Status InitHString(HString &T);
Status StrAssign(HString &T,char *chars);
Status StrCopy(HString &T,HString S);
bool StrEmpty(HString S);
Status StrCompare(HString S,HString T);
int StrLength(HString S);
Status ClearString(HString &S);
Status Concat(HString &T,HString S1,HString S2);
Status SubString(HString &Sub,HString S,int pos,int len);
int Index(HString S,HString T,int pos);
Status Replace(HString &S,HString T,HString V);
Status StrInsert(HString &S,int pos,HString T);
Status StrDelete(HString &S,int pos,int len);
Status DestroyString(HString &S);

#endif