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
}HTNode,*HuffmanTree;//ºÕ·òÂüÊ÷

typedef struct
{
	ElemType e;
	char *code;
}HCNode,*HuffmanCode;//ºÕ·òÂü±àÂë±í

int HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,ElemType *data,int n);//´´½¨ºÕ·òÂüÊ÷
int CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n);//´´½¨ºÕ·òÂü±àÂë±í
int TransCoding(HuffmanTree HT,char *code,ElemType &e,int n);//·­Òë
int GenerateCoding(HuffmanTree HT,char *code,ElemType e,int n);//×ªÒë

#endif