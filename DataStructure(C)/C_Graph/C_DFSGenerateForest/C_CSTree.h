#ifndef C_CSTree_2013_2_15_16_27
#define C_CSTree_2013_2_15_16_27
//#pragma once
typedef char TElemType;
typedef struct CSNode
{
	TElemType data;
	struct CSNode *firstchild,*rightsibling;
}CSNode,*CSTree;
#endif