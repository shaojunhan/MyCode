#include"C_BiTree_Basic.h"
#include"C_BiTree_Stack.h"
#include"C_BiTree_Queue.h"

char Nil='#';

Status InitBiTree(BiTree &T)
{
	T=NULL;
	return OK;
}

Status DestroyBiTree(BiTree &T)
{
	BiTree p,q;//非递归算法中用到
#if TEST
	//算法一:递归
	if(!T)
		return OK;
	else
	{
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
		T=NULL;
	}

#elif TEST2
	//算法二:非递归
	Stack S;
	InitStack(S);
	
	p=T;
	do
	{
		while(p)
		{
			Push(S,p);
			p=p->lchild;
		}
		if(!StackEmpty(S))
		{
			Pop(S,p);
			q=p;
			p=p->rchild;
			free(q);
		}
	}while(!StackEmpty(S));
	T=NULL;
	DestroyStack(S);
	*/

#else
	//算法三:广度优先
	Queue Q;
	if(!T)
		return OK;
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
#endif
	return OK;
}

Status CreateBiTree(BiTree &T,TElemType *das,int &i)
{
#if TEST
	//算法一:先序递归
	if(*(das+i)==Nil)
		T=NULL;
	else
	{
		if(!(T=(BiTree)malloc(sizeof(struct BiTNode))))
			exit(OVERFLOW);
		T->e=*(das+i);
		CreateBiTree(T->lchild,das,++i);
		CreateBiTree(T->rchild,das,++i);
	}

#else
	//算法二:广搜
	
	Queue Q;
	int l,j;
	BiTree p;
	InitQueue(Q);
	if(*(das+i)!=Nil)
	{
		if(!(T=(BiTree)malloc(sizeof(struct BiTNode))))
			exit(OVERFLOW);
		T->e=*(das+i++);
		T->lchild=T->rchild=NULL;

		EnQueue(Q,T);
		while(!QueueEmpty(Q))
		{
			l=QueueLength(Q);
			for(j=0;j<l;j++)
			{
				DeQueue(Q,p);
				if(*(das+i)!=Nil)
				{
					if(!(p->lchild=(BiTree)malloc(sizeof(struct BiTNode))))
						exit(OVERFLOW);
					p->lchild->e=*(das+i);
					p->lchild->lchild=p->lchild->rchild=NULL;
					EnQueue(Q,p->lchild);
				}
				i++;
				if(*(das+i)!=Nil)
				{
					if(!(p->rchild=(BiTree)malloc(sizeof(struct BiTNode))))
						exit(OVERFLOW);
					p->rchild->e=*(das+i);
					p->rchild->lchild=p->rchild->rchild=NULL;
					EnQueue(Q,p->rchild);
				}
				i++;
			}		
		}
	}
	DestroyQueue(Q);
#endif
	return OK;
}

Status ClearBiTree(BiTree &T)
{
	return DestroyBiTree(T);
}

bool BiTreeEmpty(BiTree T)
{
	return T==NULL;
}

int BiTreeDepth(BiTree T)
{
	//递归
	int max,i;

	if(!T)
		return 0;
	else
	{
		max=i=0;
		i=BiTreeDepth(T->lchild);
		max=BiTreeDepth(T->rchild);
		if(i>max)
			max=i;
		return max+1;
	}
}

BiTree Root(BiTree T)
{
	return T==NULL?NULL:T;
}

bool Search(BiTree T,BiTNode e)
{
	if(!T)
		return 0;
	else
	{
		if(T->e==e.e && T->lchild==e.lchild && T->rchild==e.rchild)
			return 1;
		else
			return	Search(T->lchild,e)==0?Search(T->rchild,e):1;
	}
}

//T中结点e的值
TElemType Value(BiTree T,BiTNode e)
{
	if(Search(T,e))
		return e.e;
	else
		return Nil;
}

Status Assign(BiTree T,BiTNode &e,TElemType value)
{
	if(Search(T,e))
	{
		e.e=value;
		return OK;
	}
	else
		return FALSE;
}

BiTree Parent(BiTree T,BiTNode &e)
{
	BiTree p;

	if(!T || !T->lchild && !T->rchild)
		return NULL;
	else
	{
		if(T->lchild && T->lchild->e==e.e && T->lchild->lchild==e.lchild && T->rchild==e.rchild 
			|| T->rchild && T->rchild->e==e.e && T->rchild->lchild==e.lchild && T->rchild->rchild==e.rchild)
			return T;
		else
		{
			p=Parent(T->lchild,e);
			return p==NULL?Parent(T->rchild,e):p;
		}

	}
}

BiTree LeftChild(BiTree T,BiTNode e)
{
	if(Search(T,e))
		return e.lchild;
	else
		return NULL;
}

BiTree RightChild(BiTree T,BiTNode e)
{
	if(Search(T,e))
		return e.rchild;
	else
		return NULL;
}

BiTree LeftSibling(BiTree T,BiTNode e)
{
	BiTree p;
	p=Parent(T,e);
	if(p && p->rchild && p->rchild->e==e.e && p->rchild->lchild==e.lchild && p->rchild->rchild==e.rchild)
		if(p->lchild)
			return p->lchild;
		else
			return NULL;
	return NULL;
}

BiTree RightSibling(BiTree T,BiTNode e)
{
	BiTree p;
	p=Parent(T,e);
	if(p && p->lchild && p->lchild->e==e.e && p->lchild->lchild==e.lchild && p->lchild->rchild==e.rchild)
		if(p->rchild)
			return p->rchild;
		else
			return NULL;
	return NULL;
}

Status InsertChild(BiTree &T,position p,bool LR,BiTree C)
{
	Queue Q;
	int i,j;
	int l;
	BiTree q;

	//
	if(p.level<1 || p.order<1 || !T)
		return FALSE;

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

	l=QueueLength(Q);
	if(i<p.level || l<p.order)
	{
		DestroyQueue(Q);
		return FALSE;
	}

	for(j=0;j<p.order;j++)
		DeQueue(Q,q);

	if(LR)
	{
		C->rchild=q->rchild;
		q->rchild=C;
	}
	else
	{
		C->rchild=q->lchild;
		q->lchild=C;
	}
	DestroyQueue(Q);

	return OK;
}

Status DeleteChild(BiTree &T,position p,bool LR)
{
	Queue Q;
	int i,j,l;
	BiTree q;

	if(p.level<1 || p.order<1 || !T)
		return FALSE;
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

	l=QueueLength(Q);
	if(i<p.level || l<p.order)
	{
		DestroyQueue(Q);
		return FALSE;
	}
	
	for(j=0;j<p.order;j++)
		DeQueue(Q,q);
	if(LR)
		DestroyBiTree(q->rchild);
	else
		DestroyBiTree(q->lchild);
	DestroyQueue(Q);
	return OK;
}

Status PreOrderTraverse(BiTree T,void (*Visit)(TElemType))
{
#if TEST
	//算法一:递归
	if(T)
	{
		Visit(T->e);
		PreOrderTraverse(T->lchild,Visit);
		PreOrderTraverse(T->rchild,Visit);
		return OK;
	}
	else
		return FALSE;
	

#else
	//算法二:非递归

	Stack S;
	BiTree p;
	if(!T)
		return FALSE;
	InitStack(S);
	p=T;
	do
	{
		while(p)
		{
			Visit(p->e);
			Push(S,p);
			p=p->lchild;
		}
		if(!StackEmpty(S))
		{
			Pop(S,p);
			p=p->rchild;
		}
	}while(p || !StackEmpty(S));
	DestroyStack(S);
	return OK;
#endif
}

Status InOrderTraverse(BiTree T,void (*Visit)(TElemType))
{
#if TEST
	//算法一:递归
	if(T)
	{
		InOrderTraverse(T->lchild,Visit);
		Visit(T->e);
		InOrderTraverse(T->rchild,Visit);
		return OK;
	}
	else
		return FALSE;

#else
	//算法一:非递归
	Stack S;
	BiTree p;
	if(!T)
		return FALSE;
	InitStack(S);
	p=T;
	do
	{
		while(p)
		{
			Push(S,p);
			p=p->lchild;
		}
		if(!StackEmpty(S))
		{
			Pop(S,p);
			Visit(p->e);
			p=p->rchild;
		}
	}while(p || !StackEmpty(S));

	DestroyStack(S);
	return OK;
#endif
}

Status PostOrderTraverse(BiTree T,void (*Visit)(TElemType))
{
#if TEST
	//算法一:递归
	if(T)
	{
		PostOrderTraverse(T->lchild,Visit);
		PostOrderTraverse(T->rchild,Visit);
		Visit(T->e);
		return OK;
	}
	else
		return FALSE;

#else
	//算法二:非递归
	/*
	此算法有两种表示,一是修改栈结构,二是附加一个新栈
	此为第二种附加一个简单新栈
	*/
	Stack S;
	BiTree p;
	bool *flag;//用作标记的栈,最大深度不超过树的深度
	int n,i;
	if(!T)
		return FALSE;
	n=BiTreeDepth(T);//树深
	if(!(flag=(bool*)malloc((n+1)*sizeof(bool))))
		exit(OVERFLOW);
	for(i=0;i<=n;i++)
		*(flag+i)=0;
	
	i=0;
	InitStack(S);//初始栈
	p=T;
	do
	{
		while(p)//顺序入栈左子树
		{
			Push(S,p);
			i++;//i为栈顶
			p=p->lchild;
		}
	
		while(!StackEmpty(S))
		{
			Pop(S,p);
			if(*(flag+i)==0)//初次访问该节点
			{
				Push(S,p);
				p=p->rchild;
				*(flag+i)=1;//修改标记
				break;
			}
			else//第二次访问该节点,此时已经从右子树返回
			{
				*(flag+i)=0;
				i--;
				Visit(p->e);
			}
		}
	}while(!StackEmpty(S));
	DestroyStack(S);
	free(flag);
	return OK;
#endif
}

Status LevelOrderTraverse(BiTree T,void (*Visit)(TElemType))
{
	//广搜
	Queue Q;
	BiTree p;

	if(!T)
		return FALSE;
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
