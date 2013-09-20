#include"C_InsertSort_Header.h"

void TableInsertSort(StaticList &R,bool flag)
{//初始条件:静态链表R存在,0为链表头结点,flag表示记录有序类型(0正序,1逆序)
//操作结果:表插入排序使R有序
	int i,j,prior,next,count;
	i=R[0].cur;
	if(i==0)
		return;//空或者只有一个记录
	prior=i;
	i=R[i].cur;
	count=1;
	while(i!=0)
	{
		next=R[i].cur;
		j=0;
		while((R[(R[j].cur)].data).key<(R[i].data).key)
			j=R[j].cur;

		if(R[j].cur!=i)
		{
			R[prior].cur=R[i].cur;
			R[i].cur=R[j].cur;
			R[j].cur=i;
		}
		else
			prior=i;
		count++;
		i=next;
	}
	
	if(!flag)
	{
		i=R[0].cur;
		for(j=1;j<=count;j++)//元素暂存
		{
			while(i<j)
				i=R[i].cur;
			next=R[i].cur;
			if(i!=j)
			{
				R[0].data=R[i].data;
				R[i]=R[j];
				R[j].data=R[0].data;
				R[j].cur=i;
			}
			i=next;
		}
	}
	else
	{
		i=R[0].cur;
		for(j=count;j>=1;j--)
		{
			while(i>j)
				i=R[i].cur;
			next=R[i].cur;
			if(i!=j)
			{
				R[0].data=R[i].data;//i位置元素暂存
				R[i]=R[j];
				R[j].data=R[0].data;
				R[j].cur=i;
			}
			i=next;
		}
	}
	for(i=0;i<count;i++)//重新调整链表
		R[i].cur=i+1;
	R[i].cur=0;
}

void TableInsertSort(StaticList &R)//重载
{//初始条件:静态链表R存在,0为链表头结点
//操作结果:表插入排序使R正序有序
	int i,j,prior,next,count;
	i=R[0].cur;
	if(i==0)
		return;
	prior=i;
	i=R[i].cur;
	count=1;
	while(i!=0)
	{
		next=R[i].cur;
		j=0;
		while((R[R[j].cur].data).key<(R[i].data).key)
			j=R[j].cur;
		if(R[j].cur!=i)
		{
			R[prior].cur=R[i].cur;
			R[i].cur=R[j].cur;
			R[j].cur=i;
		}
		else
			prior=i;
		count++;
		i=next;
	}

	i=R[0].cur;
	for(j=1;j<=count;j++)
	{
		while(i<j)
			i=R[i].cur;
		next=R[i].cur;
		if(i!=j)
		{
			R[0].data=R[i].data;
			R[i]=R[j];
			R[j].data=R[0].data;
			R[j].cur=i;
		}
		i=next;
	}
	for(i=0;i<count;i++)//重新调整链表
		R[i].cur=i+1;
	R[i].cur=0;
}

void InitList(StaticList &L)
{//操作结果:初始化静态链表,表头为0的链存储可用结点
	int i;
	for(i=1;i<MAXSIZE;i++)
		L[i-1].cur=i;
	L[i].cur=0;//表尾
}

bool ListEmpty(StaticList L,int head)
{//操作结果:判断链表是否为空
	return L[head].cur==0;
}

int ListLength(StaticList L,int head)
{//操作结果:返回链表head的长度
	int count,i;
	count=0;
	i=head;
	while(i!=0)
	{
		i=L[i].cur;
		count++;
	}
	return count;
}

int ClearList(StaticList &L,int head)
{//操作结果:清空链表head,失败返回0,成功返回1
	int i;
	if(L[head].cur==0)
		return 0;
	i=L[head].cur;
	while(L[i].cur!=0)
		i=L[i].cur;
	L[i].cur=L[0].cur;
	L[0].cur=L[head].cur;
	return 1;
}

int GetElem(StaticList &L,int head,int i,ElemType &e)
{//初始条件:静态链表L存在,head为链表表头,0<i<=ListLength(head)
//操作结果:用e返回链表head的第i个数据
	int j,count;

	if(i<=0 || i>ListLength(L,head))
		return 0;
	j=L[head].cur;
	count=1;
	while(count<i)
	{
		j=L[j].cur;
		count++;
	}
	e=L[j].data;
	return 1;
}

int LocateElem(StaticList L,int head,ElemType e,int (*compare)(ElemType,ElemType))
{//初始条件:静态链表L存在,head为链表表头
//操作结果:返回元素e所在链表head中的位置
	int i,count;
	i=L[head].cur;
	count=1;
	while(i!=0)
	{
		if(!compare(L[i].data,e))
			return count;
		i=L[i].cur;
		count++;
	}
	return 0;
}

int PriorElem(StaticList L,int head,ElemType cur_e,ElemType &prior_e,
			  int (*compare)(ElemType,ElemType))
{//初始条件:静态链表L存在,head为表头,cur_e为链表head中的一个元素
//操作结果:prior_e返回链表head中cur_e的前驱,成功返回0,失败返回0
	int i,next;
	
	i=L[head].cur;
	if(i==0 || L[i].cur==0)
		return 0;
	while(L[i].cur)
	{
		next=L[i].cur;
		if(!compare(cur_e,L[next].data))
		{
			prior_e=L[i].data;
			return 1;
		}
		i=next;
	}
	return 0;
}

int NextElem(StaticList L,int head,ElemType cur_e,ElemType &next_e,
			 int (*compare)(ElemType,ElemType))
{//初始条件:L存在,head为表头,cur_e为链表head中的一元素
//操作结果:用next_e返回链表head中元素cur_e的后继
	int i;
	i=L[head].cur;
	while(i!=0)
	{
		if(!compare(L[i].data,cur_e))
			break;
		i=L[i].cur;
	}

	if(i==0 || L[i].cur==0)
		return 0;
	next_e=L[i].data;
	return 1;
}

int ListInsert(StaticList &L,int head,int i,ElemType e,int (*compare)(ElemType,ElemType))
{//初始条件:L存在,head为表头,0<i<=ListLength(head)+1
//操作结果:链表head中第i个位置插入元素e
	int j,count,n;
	if(i<=0 || i>ListLength(L,head)+1)
		return 0;
	j=head;
	count=0;
	while(count<i-1)
		j=L[j].cur;
	n=Malloc(L);
	if(n)
	{
		L[n].cur=L[j].cur;
		L[j].cur=n;
		return 1;
	}
	return 0;
}

int ListDelete(StaticList &L,int head,int i,ElemType &e)
{//初始条件:L存在,head为表头,0<i<=ListLenngth(head)
//操作结果:删除链表head中的第i个元素,用e返回删除元素的值
	int j,count,n;
	if(i<=0 || i>ListLength(L,head))
		return 0;
	j=head;
	count=0;
	while(count<i-1)
		j=L[j].cur;
	n=L[j].cur;
	L[j].cur=L[n].cur;
	Free(L,n);
	return 1;
}

void TraverseList(StaticList L,int head,void (*Visit)(ElemType))
{//操作结果:访问链表head中的每个元素一次
	int i;
	i=L[head].cur;
	while(i!=0)
	{
		Visit(L[i].data);
		i=L[i].cur;
	}
}

int Malloc(StaticList &L)
{//操作结果:返回一个可用存储单元
	int i;
	i=L[0].cur;
	if(i!=0)
	{
		L[0].cur=L[i].cur;
		L[i].cur=0;
	}
	return i;
}

void Free(StaticList &L,int n)
{//操作结果:回收一个可用存储单元
	if(n>0 && n<=MAXSIZE)
	{
		L[n].cur=L[0].cur;
		L[0].cur=n;
	}
}