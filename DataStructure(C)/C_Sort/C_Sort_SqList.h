#ifndef C_Sort_Header_2013_2_23_23_01
#define C_Sort_Header_2013_2_23_23_01
//#pragma once
#define MAXSIZE 20//记录最大20
typedef struct
{
	KeyType key;
	OtherType others;
}RedType;//记录类型
typedef struct
{
	RedType records[MAXSIZE+1];//0号元素不存储数据
	int n;//记录长度
}SqList;
#endif