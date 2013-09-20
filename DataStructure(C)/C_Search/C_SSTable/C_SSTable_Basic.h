#ifndef C_SSTable_Basic_2013_2_20_18_11
#define C_SSTable_Basic_2013_2_20_18_11
//#pragma once
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
typedef int Status;
//静态查找表
typedef struct
{
	SElemType *elem;
	int length;
}SSTable;

Status Create_IR(SSTable &ST);
//ST中的元素按关键字从小到大排序
Status Create_OR(SSTable &ST,SElemType R[],int n);
//R从0开始,ST的0位置不存储元素,n为R数组长度
 //根据R顺序建立ST
Status DestroyTable(SSTable &ST);
//销毁ST
int Search_IR(SSTable &ST,KeyType key);
//ST静态查找表,key关键字
//顺序查找,找到返回在ST中的位置(从1开始),否则返回负数
int Search_BIN(SSTable &ST,KeyType key);
//ST为关键字从小到大有序,key为待查关键字
//在ST中搜索key,找到返回所在ST中位置(从1开始),否则返回负数
void Traverse(SSTable &ST,void (*Visit)(SElemType));
//Visit参数为SElemType的函数指针
//顺序遍历ST
#endif