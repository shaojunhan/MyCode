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
	BiTree p,q;//�ǵݹ��㷨���õ�
#if TEST
	//�㷨һ:�ݹ�
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
	//�㷨��:�ǵݹ�
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
	//�㷨��:�������
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
	//�㷨һ:����ݹ�
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
	//�㷨��:����
	
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
	//�ݹ�
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

//T�н��e��ֵ
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
	//�㷨һ:�ݹ�
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
	//�㷨��:�ǵݹ�

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
	//�㷨һ:�ݹ�
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
	//�㷨һ:�ǵݹ�
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
	//�㷨һ:�ݹ�
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
	//�㷨��:�ǵݹ�
	/*
	���㷨�����ֱ�ʾ,һ���޸�ջ�ṹ,���Ǹ���һ����ջ
	��Ϊ�ڶ��ָ���һ������ջ
	*/
	Stack S;
	BiTree p;
	bool *flag;//������ǵ�ջ,�����Ȳ������������
	int n,i;
	if(!T)
		return FALSE;
	n=BiTreeDepth(T);//����
	if(!(flag=(bool*)malloc((n+1)*sizeof(bool))))
		exit(OVERFLOW);
	for(i=0;i<=n;i++)
		*(flag+i)=0;
	
	i=0;
	InitStack(S);//��ʼջ
	p=T;
	do
	{
		while(p)//˳����ջ������
		{
			Push(S,p);
			i++;//iΪջ��
			p=p->lchild;
		}
	
		while(!StackEmpty(S))
		{
			Pop(S,p);
			if(*(flag+i)==0)//���η��ʸýڵ�
			{
				Push(S,p);
				p=p->rchild;
				*(flag+i)=1;//�޸ı��
				break;
			}
			else//�ڶ��η��ʸýڵ�,��ʱ�Ѿ�������������
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
	//����
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
