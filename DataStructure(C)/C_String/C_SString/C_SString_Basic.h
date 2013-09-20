#ifndef C_SString_Basic_2012_11_17_22_07
#define C_SString_Basic_2012_11_17_22_07


#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

#define MAXSTRLEN 20
typedef int Status;
typedef char SString[MAXSTRLEN+1];


Status StrAssign(SString &T,char *chars);
Status StrCopy(SString &T,SString &S);
Status StrEmpty(SString T);
int StrCompare(SString S,SString T);
int StrLength(SString S);
Status ClearString(SString &S);
Status Concat(SString &T,SString S1,SString S2);
Status SubString(SString &Sub,SString S,int pos,int len);
int Index(SString S,SString T,int pos);
Status Replace(SString &S,SString T,SString V);
Status StrInsert(SString &S,int pos,SString T);
Status StrDelete(SString &S,int pos,int len);
Status DestroyString(SString &S);

#endif