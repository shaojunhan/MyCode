#include"E:\Document\Data Structures\Study\C_Search\C_Search_Header.h"
#include<stdlib.h>

typedef int KeyType;
typedef struct
{
	KeyType key;
	char Sno[11];
	char Name[9];
	char Sex[3];
	unsigned int age;
	char major[31];
}HElemType;
#include"C_HashTable_Basic.h"

void InitDSTable(HashTable &HT)
{//操作结果:初始化哈希表
	int i;
	for(i=0;i<MAX;i++)
		HT[i]=NULL;
}

void DestroyDSTable(HashTable &HT)
{//初始条件:哈希表HT存在
//操作结果:销毁HT
	int i;
	HLink pt,pr;
	for(i=0;i<MAX;i++)
	{
		pt=HT[i];
		while(pt)
		{
			pr=pt->next;
			free(pt);
			pt=pr;
		}
	}
}

HLink SearchDSTable(HashTable HT,KeyType key)
{//初始条件:哈希表HT存在,key是与关键字类型相同的一给定值
//操作结果:搜索HT中关键字与key相同的记录,找到返回所在位置(指针),未找到返回空
	int index;
	HLink pt;

	index=key%MAX;
	pt=HT[index];
	while(pt)
	{
		if EQ(key,(pt->data).key)
			return pt;
		pt=pt->next;
	}

	return NULL;
}

int InsertDSTable(HashTable &HT,HElemType data)
{//初始条件:哈希表HT存在,data是与HT中记录类型相同的一给定值
//操作结果:搜索HT中关键字与data.key相同的记录,找到返回插入失败(1),未找到则执行插入返回插入成功(0)
	int index;
	HLink pt,p;

	index=data.key%MAX;

	if(HT[index]==NULL || LT(data.key,(HT[index]->data).key))
	{
		p=(HLink)malloc(sizeof(HNode));
		if(!p)
			exit(1);
		p->data=data;
		p->next=HT[index];
		HT[index]=p;
		return 0;
	}
	else
	{
		for(pt=HT[index];pt->next && LT((pt->next->data).key,data.key);pt=pt->next)
			if(!pt->next || LT(data.key,(pt->next->data).key))
			{
				p=(HLink)malloc(sizeof(HNode));
				if(!p)
					exit(1);
				p->data=data;
				p->next=pt->next;
				pt->next=p;
				return 0;
			}
	}
	return 1;
}

int DeleteDSTable(HashTable &HT,KeyType key)
{//初始条件:哈希表HT存在,key是与关键字类型相同的一给定值
//操作结果:在HT中搜索道关键字与key相同的记录,则执行删除返回删除成功(0),否则返回删除失败(1)
	HLink pt,pre;
	int index;

	index=key%MAX;
	
	pre=NULL;
	pt=HT[index];
	while(pt)
	{
		if EQ((pt->data).key,key)
			break;
		pre=pt;
		pt=pt->next;
	}
	if(pt)
	{
		if(pre==NULL)
		{
			HT[index]=pt->next;
			free(pt);
		}
		else
		{
			pre->next=pt->next;
			free(pt);
		}
		return 0;
	}
	return 1;
}

void TraverseDSTable(HashTable HT,void (*Visit)(HElemType))
{//初始条件:哈希表HT存在,Visit是对HElemType类型进行访问的函数
//操作结果:对HT中记录访问一次
	int i;
	HLink pt;

	for(i=0;i<MAX;i++)
	{
		pt=HT[i];
		while(pt)
		{
			Visit(pt->data);
			pt=pt->next;
		}
	}
}