#ifndef C_HashTable_Basic_2013_2_22_22_08
#define C_HashTable_Basic_2013_2_22_22_08
//#pragma once
//链式哈希表
#define MAX 100
typedef struct HNode
{
	HElemType data;
	struct HNode *next;
}HNode,*HLink;
typedef HLink HashTable[MAX];

void InitDSTable(HashTable &HT);
//操作结果:初始化哈希表
void DestroyDSTable(HashTable &HT);
//初始条件:哈希表HT存在
//操作结果:销毁HT
HLink SearchDSTable(HashTable HT,KeyType key);
//初始条件:哈希表HT存在,key是与关键字类型相同的一给定值
//操作结果:搜索HT中关键字与key相同的记录,找到返回所在位置(指针),未找到返回空
int InsertDSTable(HashTable &HT,HElemType data);
//初始条件:哈希表HT存在,data是与HT中记录类型相同的一给定值
//操作结果:搜索HT中关键字与data.key相同的记录,找到返回插入失败(1),未找到则执行插入返回插入成功(0)
int DeleteDSTable(HashTable &HT,KeyType key);
//初始条件:哈希表HT存在,key是与关键字类型相同的一给定值
//操作结果:在HT中搜索道关键字与key相同的记录,则执行删除返回删除成功(0),否则返回删除失败(1)
void TraverseDSTable(HashTable HT,void (*Visit)(HElemType));
//初始条件:哈希表HT存在,Visit是对HElemType类型进行访问的函数
//操作结果:对HT中记录访问一次

#endif