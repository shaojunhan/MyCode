#include"C_CSTree_Basic.h"
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<string.h>

#define MAX 100
char Nil='#';
Status InitTree(CSTree &T)
{
	T=NULL;
	return OK;
}

Status DestroyTree(CSTree &T)
{
#if TEST
	//算法一:递归
	if(T)
	{
		if(T->firstchild)
			DestroyTree(T->firstchild);
		if(T->firstsibling)
			DestroyTree(T->rightsibling);
		free(T);
		T=NULL;
		return OK;
	}
#elif TEST2
	//算法二:广搜
	CSTree q[MAX];
	CSTree p;
	int front,rear;
	if(T)
	{
		front=rear=0;
		q[(rear++)%MAX]=T;
		while(front!=rear)
		{
			p=q[(front++)%MAX];
			if(p->firstchild)
				q[(rear++)%MAX]=p->firstchild;
			if(p->firstsibling)
				q[(rear++)%MAX]=p->rightsibling;
			free(p);
		}
		T=NULL;
		return OK;
	}
#else
	//算法三:后序深搜的非递归算法(利用栈)
	CSTree s[MAX];
	CSTree p;
	bool flag[MAX];
	int top,base;
	int i;
	for(i=0;i<MAX;i++)
		flag[i]=0;
	if(T)
	{
		top=base=0;
		p=T;
		do
		{
			while(p)
			{
				s[top++]=p;
				p=p->firstchild;
			}
			while(top!=base)
			{
				p=s[--top];
				if(flag[top]==0)
				{
					flag[top]=1;
					s[top++]=p;
					p=p->rightsibling;
					break;
				}
				else
				{
					flag[top]=0;
					free(p);
				}
			}
		}while(top!=base);
		T=NULL;
	}
	return OK;
#endif
}

Status CreateTree(CSTree &T,TElemType e)
{
	char buf[MAX];
	int l,i;

	CSTree p;
	printf("请输入%c的孩子节点:",e);
	scanf("%s%*c",buf);
	l=strlen(buf);
	if(l==1 && buf[0]==Nil)
	{
		T=NULL;
		return FALSE;
	}
	else
	{
		T=(CSTree)malloc(sizeof(struct CSTNode));
		if(!T)
			exit(OVERFLOW);
		T->e=buf[0];
		T->firstchild=T->rightsibling=NULL;
		p=T;
		for(i=1;i<l;i++)
		{
			p->rightsibling=(CSTree)malloc(sizeof(struct CSTNode));
			if(!p->rightsibling)
				exit(OVERFLOW);
			p=p->rightsibling;
			p->e=buf[i];
			p->firstchild=p->rightsibling=NULL;
		}
		p=T;
		while(p)
		{
			CreateTree(p->firstchild,p->e);
			p=p->rightsibling;
		}
		return OK;
	}
}

Status ClearTree(CSTree &T)
{
	return DestroyTree(T);
}

bool TreeEmpty(CSTree T)
{
	return T==NULL;
}

int TreeDepth(CSTree T)
{
	int max,l;
	if(T==NULL)
		return 0;
	else
	{
		max=0;
		max=TreeDepth(T->firstchild);
		l=TreeDepth(T->rightsibling);
		if(l>max)
			max=l;
		return max+1;
	}
}

TElemType Value(CSTree T,TElemType e)
{
	CSTree p;
	TElemType temp;
	if(T==NULL)
		return Nil;
	else
	{
		p=T;
		while(p)
		{
			if(p->e==e)
				return p->e;
			else
			{
				temp=Value(p->firstchild,e);
				if(temp==e)
					return temp;
			}
			p=p->rightsibling;
		}
		return Nil;
	}
}

Status Assign(CSTree &T,TElemType cur_e,TElemType value)
{
	int	isok;
	CSTree p;
	if(T==NULL)
		return FALSE;
	else
	{
		p=T;
		while(p)
		{
			if(p->e==cur_e)
			{
				p->e=value;
				return OK;
			}
			else
			{
				isok=Assign(p->firstchild,cur_e,value);
				if(isok)
					return isok;
			}

			p=p->rightsibling;
		}
		return FALSE;
	}
}

TElemType Root(CSTree T)
{
	return T==NULL?Nil:T->e;
}

CSTree Parent(CSTree T,TElemType cur_e)
{
	CSTree p;
	CSTree temp;
	if(T==NULL)
		return NULL;
	else
	{
		p=T;
		while(p)
		{
			if(p->firstchild)
				if(p->firstchild->e==cur_e)
					return p;
				else
				{
					temp=Parent(p->firstchild,cur_e);
					if(temp!=NULL)
						return temp;
				}
			p=p->rightsibling;
		}
		return NULL;
	}
}

CSTree LeftChild(CSTree T,TElemType cur_e)
{
	CSTree p;
	CSTree temp;
	if(T==NULL)
		return NULL;
	else
	{
		p=T;
		while(p)
		{
			if(p->e==cur_e)
				return p->firstchild==NULL?NULL:p->firstchild;
			else if(p->firstchild)
			{
				temp=LeftChild(p->firstchild,cur_e);
				if(temp!=NULL)
					return temp;
			}
			p=p->rightsibling;
		}
		return NULL;
	}
}

CSTree RightSibling(CSTree T,TElemType cur_e)
{
	CSTree p;
	CSTree temp;
	if(T==NULL)
		return NULL;
	else
	{
		p=T;
		while(p)
		{
			if(p->e==cur_e)
				return p->rightsibling==NULL?NULL:p->rightsibling;
			else if(p->firstchild)
			{
				temp=RightSibling(p->firstchild,cur_e);
				if(temp!=NULL)
					return temp;
			}
			p=p->rightsibling;
		}
		return NULL;
	}
}

Status InsertChild(CSTree &T,TElemType p,int i,CSTree &C)
{
	CSTree q;
	CSTree temp;
	int isok;
	if(T==NULL || p==Nil || i<1)
		return FALSE;
	else
	{
		q=T;
		temp=NULL;
		while(q)
		{
			if(q->e==p)
			{
				temp=q;
				break;
			}
			else if(q->firstchild)
			{
				isok=InsertChild(q->firstchild,p,i,C);
				if(isok)
					return isok;
			}
			q=q->rightsibling;
		}
		if(temp==NULL || temp->firstchild==NULL)
			return FALSE;
		else
		{
			q=C;
			while(q->rightsibling)
				q=q->rightsibling;
			if(i==1)
			{
				q->rightsibling=temp->firstchild;
				temp->firstchild=C;
				return OK;
			}
			else
			{
				temp=temp->firstchild;
				i--;
				while(--i && temp)
					temp=temp->rightsibling;
				if(temp)
				{
					q->rightsibling=temp->rightsibling;
					temp->rightsibling=C;
					return OK;
				}
			}
		}
		return FALSE;
	}
}

Status DeleteChild(CSTree &T,TElemType p,int i)
{
	CSTree q;
	CSTree temp;
	int isok;
	if(T==NULL || p==Nil || i<1)
		return FALSE;
	else
	{
		q=T;
		temp=NULL;
		while(q)
		{
			if(q->e==p)
			{
				temp=q;
				break;
			}
			else if(q->firstchild)
			{
				isok=DeleteChild(q->firstchild,p,i);
				if(isok)
					return isok;
			}
			q=q->rightsibling;
		}
		if(temp==NULL || temp->firstchild==NULL)
			return FALSE;
		else
		{
			q=NULL;
			if(i==1)
			{
				q=temp->firstchild;
				temp->firstchild=q->rightsibling;
				q->rightsibling=NULL;
			}
			else
			{
				temp=temp->firstchild;
				i--;
				while(--i && temp)
					temp=temp->rightsibling;
				if(temp)
				{
					q=temp->rightsibling;
					if(q)
					{
						temp->rightsibling=q->rightsibling;
						q->rightsibling=NULL;
					}
				}
				if(q)
				{
					DestroyTree(q);
					return OK;
				}
			}
		}
		return FALSE;
	}
}

Status PreOrderTraverse(CSTree T,void (*visit)(TElemType))
{
	CSTree p;
	if(T==NULL)
		return FALSE;
	else
	{
		p=T;
		while(p)
		{
			visit(p->e);
			PreOrderTraverse(p->firstchild,visit);
			p=p->rightsibling;
		}
		return OK;
	}
}

Status PostOrderTraverse(CSTree T,void (*visit)(TElemType))
{
	CSTree p;
	if(T==NULL)
		return FALSE;
	else
	{
		p=T;
		while(p)
		{
			PostOrderTraverse(p->firstchild,visit);
			visit(p->e);
			p=p->rightsibling;
		}
		return OK;
	}
}

Status LevelOrderTraverse(CSTree T,void (*visit)(TElemType))
{
	CSTree q[MAX];//队列queue
	int front,rear;
	CSTree p;
	if(T==NULL)
		return FALSE;
	else
	{
		front=rear=0;
		p=T;
		while(p)
		{
			q[(rear++)%MAX]=p;
			p=p->rightsibling;
		}
		while(front!=rear)
		{
			p=q[(front++)%MAX];
			visit(p->e);
			p=p->firstchild;
			while(p!=NULL)
			{
				q[(rear++)%MAX]=p;
				p=p->rightsibling;
			}
		}
		return OK;
	}
}
