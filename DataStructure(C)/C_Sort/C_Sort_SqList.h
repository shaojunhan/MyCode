#ifndef C_Sort_Header_2013_2_23_23_01
#define C_Sort_Header_2013_2_23_23_01
//#pragma once
#define MAXSIZE 20//��¼���20
typedef struct
{
	KeyType key;
	OtherType others;
}RedType;//��¼����
typedef struct
{
	RedType records[MAXSIZE+1];//0��Ԫ�ز��洢����
	int n;//��¼����
}SqList;
#endif