#ifndef C_BiThrTree_Basic_2013_2_2_21_30
#define C_BiThrTree_Basic_2013_2_2_21_30
//#pragma once

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
#define CHAR 1

#if CHAR
typedef char TElemType;
#else
typedef int TElemType;
#endif

typedef int Status;
typedef enum {Link,Thread} PointerTag;
typedef struct BiThrNode
{
	TElemType e;
	struct BiThrNode *lchild,*rchild;
	PointerTag LTag,RTag;
}BiThrNode,*BiThrTree;

Status CreateBiThrTree(BiThrTree &Thr);
Status DestroyBiThrTree(BiThrTree &Thr);
Status InOrderThread(BiThrTree &Thr,BiThrTree T);
Status InOrderTraverse_Thr(BiThrTree Thr,void (*Visit)(TElemType));
#endif