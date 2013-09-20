#ifndef C_HuffmanCode_Basic_2013_2_8
#define C_HuffmanCode_Basic_2013_2_8
//#pragma once
#define CHAR 1
#if CHAR
typedef char ElemType;
#elif INT
typedef int ElemType;
#endif

typedef struct
{
	ElemType e;
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;//�շ�����

typedef struct
{
	ElemType e;
	char *code;
}HCNode,*HuffmanCode;//�շ��������

int HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,ElemType *data,int n);//�����շ�����
int CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n);//�����շ��������
int TransCoding(HuffmanTree HT,char *code,ElemType &e,int n);//����
int GenerateCoding(HuffmanTree HT,char *code,ElemType e,int n);//ת��

#endif