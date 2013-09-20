#include"C_BiPTree_Basic.h"
#include"C_BiPTree_Queue.h"

#if CHAR
TElemType Nil='#';
#else
TElemType Nil=0;
#endif

Status InitBiTree(BiPTree &T)
{
	T=NULL;
	return OK;
}

Status Create(BiPTree parent,BiPTree &T,TElemType *datas,int &i)
{
	//算法:递归-前序遍历创建
	if(*(datas+i)==Nil)
	{
		T=NULL;
		return FALSE;
	}
	else
	{
		if(!(T=(BiPTree)malloc(sizeof(struct BiPTNode))))
			exit(OVERFLOW);
		T->lchild=T->rchild=NULL;
		T->parent=parent;
		T->e=*(datas+i);
		Create(T,T->lchild,datas,++i);
		Create(T,T->rchild,datas,++i);
		return OK;
	}
}

Status CreateBiTree(BiPTree &T,TElemType *datas)
{
#if TEST
	int i=0;
	//算法一:递归
	Create(NULL,T,datas,i);
	return OK;
#else
	//算法二:广搜创建
	Queue Q;
	InitQueue(Q);

	int i,j,l;
	BiPTree p;

	i=0;
	if(*(datas+i)==Nil)
		T=NULL;
	else
	{
		if(!(T=(BiPTree)malloc(sizeof(struct BiPTNode))))
			exit(OVERFLOW);
		T->parent=NULL;
		T->e=*(datas+i++);
		T->lchild=T->rchild=NULL;

		EnQueue(Q,T);
		while(!QueueEmpty(Q))
		{
			l=QueueLength(Q);
			for(j=0;j<l;j++)
			{
				DeQueue(Q,p);
				if(*(datas+i)!=Nil)
				{
					if(!(p->lchild=(BiPTree)malloc(sizeof(struct BiPTNode))))
						exit(OVERFLOW);
					p->lchild->parent=p;
					p->lchild->e=*(datas+i);
					EnQueue(Q,p->lchild);
				}
				else
					p->lchild=NULL;
				i++;
				if(*(datas+i)!=Nil)
				{
					if(!(p->rchild=(BiPTree)malloc(sizeof(struct BiPTNode))))
						exit(OVERFLOW);
					p->rchild->parent=p;
					p->rchild->e=*(datas+i);
					EnQueue(Q,p->rchild);
					
				}
				else
					p->rchild=NULL;
				i++;
			}//for
		}//while
	}//else
	return OK;
#endif
}

Status DestroyBiTree(BiPTree &T)
{
#if TEST
	//算法一:递归
	if(!T)
		return FALSE;
	else
	{
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
		T=NULL;
		return OK;
	}

#elif TEST2
	//算法二:非递归深搜
	int *flag;
	int i,n;
	BiPTree p;
	if(T)
	{
		n=BiTreeDepth(T);
		if(!(flag=(int*)malloc((n+1)*sizeof(int))))
			exit(OVERFLOW);
		for(i=0;i<=n;i++)
			*(flag+i)=0;
	}
#else
	//算法三:广搜
	Queue Q;
	BiPTree p;
	if(!T)
		return FALSE;
	else
	{
		InitQueue(Q);
		EnQueue(Q,T);
		while(!QueueEmpty(Q))
		{
			DeQueue(Q,p);
			if(p->lchild)
				EnQueue(Q,p->lchild);
			if(p->rchild)
				EnQueue(Q,p->rchild);
			free(p);
		}
		T=NULL;
		DestroyQueue(Q);
		return OK;
	}
#endif
}

Status ClearBiTree(BiPTree &T)
{
	DestroyBiTree(T);
	return OK;
}

bool BiTreeEmpty(BiPTree T)
{
	return T==NULL;
}

int BiTreeDepth(BiPTree T)
{
	int max,l;
	
	if(!T)
		return 0;
	else
	{
		max=BiTreeDepth(T->lchild);
		l=BiTreeDepth(T->rchild);
		if(max<l)
			max=l;
		return max+1;
	}
}

BiPTree Root(BiPTree T)
{
	return T==NULL?NULL:T;
}

//搜索e是否为T中的结点
bool Search(BiPTree T,BiPTree e)
{
	BiPTree p;

	if(!T || !e)
		return 0;
	else
	{
		p=e;
		while(p->parent)
			p=p->parent;
		return p==T;
	}	
}

TElemType Value(BiPTree T,BiPTree e)
{
	if(Search(T,e))
		return e->e;
	else
		return Nil;
}

Status Assign(BiPTree T,BiPTree e,TElemType value)
{
	if(Search(T,e))
	{
		e->e=value;
		return OK;
	}
	else
		return ERROR;
}

BiPTree Parent(BiPTree T,BiPTree e)
{
	if(Search(T,e))
		return e->parent;
	else
		return NULL;
}

BiPTree LeftChild(BiPTree T,BiPTree e)
{
	if(Search(T,e))
		return e->lchild;
	else
		return NULL;
}

BiPTree RightChild(BiPTree T,BiPTree e)
{
	if(Search(T,e))
		return e->rchild;
	else
		return NULL;
}

BiPTree LeftSibling(BiPTree T,BiPTree e)
{
	BiPTree p;
	p=Parent(T,e);
	if(p && p->rchild==e)
		return p->lchild;
	else
		return NULL;
}

BiPTree RightSibling(BiPTree T,BiPTree e)
{
	BiPTree p;
	p=Parent(T,e);
	if(p && p->lchild==e)
		return p->rchild;
	else
		return NULL;
}

Status InsertChild(BiPTree T,position p,bool LR,BiPTree C)
{
	//广搜
	Queue Q;
	BiPTree q;
	int i,j,l;

	if(!T || !C)
		return FALSE;
	else
	{
		InitQueue(Q);
		EnQueue(Q,T);
		i=1;
		while(i<p.level && !QueueEmpty(Q))
		{
			l=QueueLength(Q);
			for(j=0;j<l;j++)
			{
				DeQueue(Q,q);
				if(q->lchild)
					EnQueue(Q,q->lchild);
				if(q->rchild)
					EnQueue(Q,q->rchild);
			}
			i++;
		}

		if(i<p.level || p.order<1 || p.order>QueueLength(Q))
		{
			DestroyQueue(Q);
			return FALSE;
		}
		else
		{
			for(j=0;j<p.order;j++)
				DeQueue(Q,q);
			if(LR)
			{
				C->rchild=q->rchild;
				if(q->rchild)
					q->rchild->parent=C;
				q->rchild=C;
			}
			else
			{
				C->rchild=q->lchild;
				if(q->lchild)
					q->lchild->parent=C;
				q->lchild=C;
			}
			C->parent=q;
			DestroyQueue(Q);
			return OK;
		}		
	}
}

Status DeleteChild(BiPTree T,position p,bool LR)
{
	//广搜
	Queue Q;
	int i,j,l;
	BiPTree q;

	if(!T)
		return FALSE;
	else
	{
		InitQueue(Q);
		EnQueue(Q,T);
		i=1;
		while(i<p.level && !QueueEmpty(Q))
		{
			l=QueueLength(Q);
			for(j=0;j<l;j++)
			{
				DeQueue(Q,q);
				if(q->lchild)
					EnQueue(Q,q->lchild);
				if(q->rchild)
					EnQueue(Q,q->rchild);
			}
			i++;
		}

		if(i<p.level || p.order<1 || p.order>QueueLength(Q))
		{
			DestroyQueue(Q);
			return FALSE;
		}
		else
		{
			for(j=0;j<p.order;j++)
				DeQueue(Q,q);
			if(LR)
			{
				DestroyBiTree(q->rchild);
				q->rchild=NULL;
			}
			else
			{
				DestroyBiTree(q->lchild);
				q->rchild=NULL;
			}

			DestroyQueue(Q);
			return OK;
		}
	}
}

Status PreOrderTraverse(BiPTree T,void (*Visit)(TElemType))
{
#if TEST
	//算法一:递归
	if(!T)
		return FALSE;
	else
	{
		Visit(T->e);
		PreOrderTraverse(T->lchild,Visit);
		PreOrderTraverse(T->rchild,Visit);
		return OK;
	}

#else
	//算法二:非递归深搜

#endif
	return OK;
}

Status InOrderTraverse(BiPTree T,void (*Visit)(TElemType))
{
	//算法一:递归
	if(!T)
		return FALSE;
	else
	{
		InOrderTraverse(T->lchild,Visit);
		Visit(T->e);
		InOrderTraverse(T->rchild,Visit);
		return OK;
	}

	//算法二:非递归深搜
}

Status PostOrderTraverse(BiPTree T,void (*Visit)(TElemType))
{
	//算法一:递归
	if(!T)
		return FALSE;
	else
	{
		PostOrderTraverse(T->lchild,Visit);
		PostOrderTraverse(T->rchild,Visit);
		Visit(T->e);
	}

	//算法二:非递归深搜
}

Status LevelOrderTraverse(BiPTree T,void (*Visit)(TElemType))
{
	//广搜
	Queue Q;
	BiPTree p;
	if(!T)
		return FALSE;
	else
	{
		InitQueue(Q);
		EnQueue(Q,T);
		while(!QueueEmpty(Q))
		{
			DeQueue(Q,p);
			if(p->lchild)
				EnQueue(Q,p->lchild);
			if(p->rchild)
				EnQueue(Q,p->rchild);
			Visit(p->e);
		}

		DestroyQueue(Q);
		return OK;
	}
	return OK;
}