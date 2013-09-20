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

Status StrAssign(HString &T,char *ch);//赋值
Status StrCopy(HString &T,HString S);//拷贝
Status StrEmpty(HString S);//判空
int StrCompare(HString S,HString T);//比较
Status StrLength(HString S);//求长度
Status ClearString(HString &S);//清空
Status Concat(HString &T,HString S1,HString S2);//连接
Status SubString(HString &Sub,HString S,int pos,int len);//求子串
int Index(HString S,HString T,int pos);//模式匹配
Status Replace(HString &S,HString T,HString V);//替换
Status StrInsert(HString &S,int pos,HString T);//插入
Status StrDelete(HString &S,int pos,int len);//删除
Status DestroyString(HString &S);//销毁

Status InitString(HString &S);//增加初始化函数
Status StrPrint(HString S);//增加的输出函数
#endif