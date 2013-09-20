//#ifndef C_Sort_StaticList_2013_2_24_14_45
//#define C_Sort_StaticList_2013_2_24_14_45
#pragma once
#ifndef MAXSIZE
#define MAXSIZE 20
#endif
typedef struct
{
	ElemType data;
	int cur;
}component,StaticList[MAXSIZE+1];//链表是带头结点的链表

void InitList(StaticList &L);
//操作结果:初始化静态链表,表头为0的链存储可用结点
bool ListEmpty(StaticList L,int head);
//操作结果:判断链表是否为空
int ListLength(StaticList L,int head);
//操作结果:返回链表head的长度
int ClearList(StaticList &L,int head);
//操作结果:清空链表head,失败返回1,成功返回0
void GetElem(StaticList &L,int head,int i,ElemType &e,
			 int (*compare)(ElemType,ElemType));
//初始条件:静态链表L存在,head为链表表头,0<i<=ListLength(head)
//操作结果:用e返回链表head的第i个数据
int LocateElem(StaticList L,int head,ElemType e,
			   int (*compare)(ElemType,ElemType));
//初始条件:静态链表L存在,head为链表表头
//操作结果:返回元素e所在链表head中的位置
int PriorElem(StaticList L,int head,ElemType cur_e,ElemType &prior_e,
			  int (*compare)(ElemType,ElemType));
//初始条件:静态链表L存在,head为表头,cur_e为链表head中的一个元素
//操作结果:prior_e返回链表head中cur_e的前驱,成功返回0,失败返回0
int NextElem(StaticList L,int head,ElemType cur_e,ElemType &next_e,
			 int (*compare)(ElemType,ElemType));
//初始条件:L存在,head为表头,cur_e为链表head中的一元素
//操作结果:用next_e返回链表head中元素cur_e的后继
int ListInsert(StaticList &L,int head,int i,ElemType e);
//初始条件:L存在,head为表头,0<i<=ListLength(head)+1
//操作结果:链表head中第i个位置插入元素e
int ListDelete(StaticList &L,int head,int i,ElemType &e);
//初始条件:L存在,head为表头,0<i<=ListLenngth(head)
//操作结果:删除链表head中的第i个元素,用e返回删除元素的值
void TraverseList(StaticList L,int head,void (*Visit)(ElemType));
//操作结果:访问链表head中的每个元素一次 
int Malloc(StaticList &L);
//操作结果:返回一个可用存储单元
void Free(StaticList &L,int cur);
//操作结果:回收一个可用存储单元

//#endif