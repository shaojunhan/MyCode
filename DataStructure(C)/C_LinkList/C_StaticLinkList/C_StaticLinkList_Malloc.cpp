#include"stdafx.h"
#include"C_StaticLinkList_Malloc.h"

int Malloc(SLinkList space)
{
	int k=space[0].cur;
	if(k)
	{
		space[0].cur=space[k].cur;
		space[k].cur=0;
	}
	return k;
}

void Free(SLinkList space,int k)
{
	int i=space[0].cur;
	space[0].cur=k;
	space[k].cur=i;
}

void DestroyList()
{

}