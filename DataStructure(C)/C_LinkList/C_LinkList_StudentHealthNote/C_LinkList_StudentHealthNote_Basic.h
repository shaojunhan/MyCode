#ifndef C_LinkList_StudentHealthNote_Basic_2012_10_12_12_47
#define C_LinkList_StudentHealthNote_Basic_2012_10_12_12_47

#include"stdafx.h"
#include<stdio.h>

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;

enum Health{GOOD=1,GENERAL,BAD};
typedef struct Stu
{
	char name[20];
	char num[10];
	bool sex;
	int age;
	char stuclass[20];
	enum Health health;
}Student;

typedef struct StuNode
{
	Student data;
	struct StuNode *next;
}*LinkList,*Link;

Status InitList(LinkList &L);
Status InsertAscend(LinkList &L,Student e);
Status ReadIn(LinkList &L,FILE *in);
Status DeleteNum(LinkList &L,char num[],Student &e);
Status DeleteName(LinkList &L,char name[],Student &e);
Status ModifyNum(LinkList &L,char num[],Student e);
Status ModifyName(LinkList &L,char name[],Student e);
Status SearchNum(LinkList &L,char num[],Student &e);
Status SearchName(LinkList &L,char name[],Student &e);
Status DisplayAll(LinkList &L,void (*visit)(Student));
Status Save(LinkList &L,FILE *out);

#endif